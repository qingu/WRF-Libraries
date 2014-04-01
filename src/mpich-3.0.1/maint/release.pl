#!/usr/bin/env perl
#
# (C) 2008 by Argonne National Laboratory.
#     See COPYRIGHT in top-level directory.
#
#
# Known limitations:
#
#    1. This script assumes that it is the only client accessing the
#    svn server. Version number verifications, diffs for ABI
#    mismatches and other checks are run assuming atomicity.
#
#    2. ABI mismatch checks are run using an svn diff in mpi.h.in and
#    the binding directory. This can come up with false positives, and
#    is only meant to be a worst-case guess.
#

use strict;
use warnings;

use Cwd qw( getcwd realpath );
use Getopt::Long;

my $arg = 0;
my $source = "";
my $psource = "";
my $version = "";
my $append_svnrev;
my $root = $ENV{PWD};
my $with_autoconf = "";
my $with_automake = "";

# Default to MPICH
my $pack = "mpich";

my $logfile = "release.log";

sub usage
{
    print "Usage: $0 [OPTIONS]\n\n";
    print "OPTIONS:\n";

    # Source svn repository from where the package needs to be downloaded from
    print "\t--source          source svn repository (required)\n";

    # svn repository for the previous source in this series to ensure ABI compliance
    print "\t--psource         source repo for the previous version for ABI compliance (required)\n";

    # what package we are creating
    print "\t--package         package to create (optional)\n";

    # version string associated with the tarball
    print "\t--version         tarball version (required)\n";

    # append svn revision
    print "\t--append-svnrev   append svn revision number (optional)\n";

    print "\n";

    exit;
}

sub check_package
{
    my $pack = shift;

    print "===> Checking for package $pack... ";
    if ($with_autoconf and ($pack eq "autoconf")) {
        # the user specified a dir where autoconf can be found
        if (not -x "$with_autoconf/$pack") {
            print "not found\n";
            exit;
        }
    }
    if ($with_automake and ($pack eq "automake")) {
        # the user specified a dir where automake can be found
        if (not -x "$with_automake/$pack") {
            print "not found\n";
            exit;
        }
    }
    else {
        if (`which $pack` eq "") {
            print "not found\n";
            exit;
        }
    }
    print "done\n";
}

sub check_autotools_version
{
    my $tool = shift;
    my $req_ver = shift;
    my $curr_ver;

    $curr_ver = `$tool --version | head -1 | cut -f4 -d' ' | xargs echo -n`;
    if ("$curr_ver" ne "$req_ver") {
	print("\tWARNING: $tool version mismatch ($req_ver) required\n\n");
    }
}

sub run_cmd
{
    my $cmd = shift;

    #print("===> running cmd=|$cmd| from ".getcwd()."\n");
    system("$cmd >> $root/$logfile 2>&1");
    if ($?) {
        die "unable to execute ($cmd), \$?=$?.  Stopped";
    }
}

GetOptions(
    "source=s" => \$source,
    "psource=s" => \$psource,
    "package:s"  => \$pack,
    "version=s" => \$version,
    "append-svnrev!" => \$append_svnrev,
    "with-autoconf" => \$with_autoconf,
    "with-automake" => \$with_automake,
    "help"     => \&usage,
) or die "unable to parse options, stopped";

if (scalar(@ARGV) != 0) {
    usage();
}

if (!$source || !$version || !$psource) {
    usage();
}

check_package("doctext");
check_package("txt2man");
check_package("svn");
check_package("latex");
check_package("autoconf");
check_package("automake");
print("\n");

## IMPORTANT: Changing the autotools versions can result in ABI
## breakage. So make sure the ABI string in the release tarball is
## updated when you do that.
check_autotools_version("autoconf", "2.69");
check_autotools_version("automake", "1.12.4");
check_autotools_version("libtool", "2.4.2");
print("\n");

my $current_ver = `svn cat ${source}/maint/version.m4 | grep MPICH_VERSION_m4 | \
                   sed -e 's/^.*\\[MPICH_VERSION_m4\\],\\[\\(.*\\)\\].*/\\1/g'`;
if ("$current_ver" ne "$version\n") {
    print("\tWARNING: Version mismatch\n\n");
}

if ($psource) {
    # Check diff
    my $d = `svn diff ${psource}/src/include/mpi.h.in ${source}/src/include/mpi.h.in`;
    $d .= `svn diff ${psource}/src/binding ${source}/src/binding`;
    if ("$d" ne "") {
	print("\tWARNING: ABI mismatch\n\n");
    }
}

if ($append_svnrev) {
    $version .= "-r";
    $version .= `svn info ${source} | grep ^Revision: | cut -f2 -d' ' | xargs echo -n`;
}

# Clean up the log file
system("rm -f ${root}/$logfile");

# Check out the appropriate source
print("===> Checking out $pack SVN source... ");
run_cmd("rm -rf ${pack}-${version}");
run_cmd("svn export -q ${source} ${pack}-${version}");
run_cmd("find ${pack}-${version} -name .gitignore | xargs rm -f");
print("done\n");

print("===> Create release date and version information... ");
chdir("${root}/${pack}-${version}");

my $date = `date`;
chomp $date;
system(qq(perl -p -i -e 's/\\[MPICH_RELEASE_DATE_m4\\],\\[unreleased development copy\\]/[MPICH_RELEASE_DATE_m4],[$date]/g' ./maint/version.m4));
system(qq(perl -p -i -e 's/\\[MPICH_RELEASE_DATE_m4\\],\\[unreleased development copy\\]/[MPICH_RELEASE_DATE_m4],[$date]/g' ./src/pm/hydra/version.m4));
print("done\n");

# Remove packages that are not being released
print("===> Removing packages that are not being released... ");
chdir("${root}/${pack}-${version}");
run_cmd("rm -rf doc/notes src/pm/mpd/Zeroconf.py");

chdir("${root}/${pack}-${version}/src/mpid/ch3/channels/nemesis/nemesis/netmod");
my @nem_modules = qw(elan);
run_cmd("rm -rf ".join(' ', @nem_modules));
for my $module (@nem_modules) {
    run_cmd("rm -rf $module");
    run_cmd(q{perl -p -i -e '$_="" if m|^\s*include \$.*netmod/}.${module}.q{/Makefile.mk|' Makefile.mk});
}
print("done\n");

# Create configure
print("===> Creating configure in the main package... ");
chdir("${root}/${pack}-${version}");
{
    my $cmd = "./autogen.sh";
    $cmd .= " --with-autoconf=$with_autoconf" if $with_autoconf;
    $cmd .= " --with-automake=$with_automake" if $with_automake;
    run_cmd($cmd);
}
print("done\n");

# Disable unnecessary tests in the release tarball
print("===> Disabling unnecessary tests in the main package... ");
chdir("${root}/${pack}-${version}");
run_cmd("perl -p -i -e 's/^perf\$/#perf/' test/mpi/testlist.in");
run_cmd("perl -p -i -e 's/^large_message /#large_message /' test/mpi/pt2pt/testlist");
run_cmd("perl -p -i -e 's/^large-count /#large-count /' test/mpi/datatype/testlist");
print("done\n");

# Remove unnecessary files
print("===> Removing unnecessary files in the main package... ");
chdir("${root}/${pack}-${version}");
run_cmd("rm -rf README.vin maint/config.log maint/config.status unusederr.txt");
run_cmd("find . -name autom4te.cache | xargs rm -rf");
print("done\n");

# Get docs
print("===> Creating secondary package for the docs... ");
chdir("${root}");
run_cmd("cp -a ${pack}-${version} ${pack}-${version}-tmp");
print("done\n");

print("===> Configuring and making the secondary package... ");
chdir("${root}/${pack}-${version}-tmp");
{
    my $cmd = "./autogen.sh";
    $cmd .= " --with-autoconf=$with_autoconf" if $with_autoconf;
    $cmd .= " --with-automake=$with_automake" if $with_automake;
    run_cmd($cmd);
}
run_cmd("./configure --disable-fc --disable-f77 --disable-cxx");
run_cmd("(make mandoc && make htmldoc && make latexdoc)");
print("done\n");

print("===> Copying docs over... ");
chdir("${root}/${pack}-${version}-tmp");
run_cmd("cp -a man ${root}/${pack}-${version}");
run_cmd("cp -a www ${root}/${pack}-${version}");
run_cmd("cp -a doc/userguide/user.pdf ${root}/${pack}-${version}/doc/userguide");
run_cmd("cp -a doc/installguide/install.pdf ${root}/${pack}-${version}/doc/installguide");
run_cmd("cp -a doc/smpd/smpd_pmi.pdf ${root}/${pack}-${version}/doc/smpd");
run_cmd("cp -a doc/logging/logging.pdf ${root}/${pack}-${version}/doc/logging");
run_cmd("cp -a doc/windev/windev.pdf ${root}/${pack}-${version}/doc/windev");
chdir("${root}");
run_cmd("rm -rf ${pack}-${version}-tmp");
print("done\n");

print("===> Creating ROMIO docs... ");
chdir("${root}/${pack}-${version}/src/mpi");
chdir("romio/doc");
run_cmd("make");
run_cmd("rm -f users-guide.blg users-guide.toc users-guide.aux users-guide.bbl users-guide.log users-guide.dvi");
print("done\n");

# Create the tarball
print("===> Creating the final ${pack} tarball... ");
chdir("${root}");
run_cmd("tar -czvf ${pack}-${version}.tar.gz ${pack}-${version}");
run_cmd("rm -rf ${pack}-${version}");
print("done\n\n");
