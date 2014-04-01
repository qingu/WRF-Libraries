#------------------------------------------------------------------------------
#          Harvard University Atmospheric Chemistry Modeling Group            !
#------------------------------------------------------------------------------
#BOP
#
# !MODULE: GNUMakefile (in doc subdirectory)
#
# !DESCRIPTION: Makefile for building the documentation (in PDF and 
#  PostScript formats) for the GEOS-Chem-Libraries package.
#\\
#\\
# !REMARKS:
# To build the documentation, call "make" with the following syntax:
#
#   make all
#
# You must have the LaTeX utilities (latex, dvips, dvipdf) installed
# on your system in order to build the documentation.
#
# !REVISION HISTORY: 
#  26 Apr 2012 - R. Yantosca - Initial version
#EOP
#------------------------------------------------------------------------------
#BOC

#==============================================================================
# Initialization
#==============================================================================

# Define variables
ROOTDIR := ..
DOC     := $(ROOTDIR)/doc
HELP    := $(ROOTDIR)/help

# List of source code files (order is important)
SRC :=                 \
./intro.make           \
$(ROOTDIR)/GNUmakefile \
$(DOC)/GNUmakefile     \
$(HELP)/GNUmakefile

# Output file names
TEX := GEOS-Chem-Libraries.tex
DVI := GEOS-Chem-Libraries.dvi
PDF := GEOS-Chem-Libraries.pdf
PS  := GEOS-Chem-Libraries.ps

# Make command
all: 
	rm -f $(TEX)
	protex -fS $(SRC) > $(TEX)
	latex $(TEX)
	latex $(TEX)
	latex $(TEX)
	dvipdf $(DVI) $(PDF)
	dvips $(DVI) -o $(PS)
	rm -f *.aux *.dvi *.log *.toc

clean:
	rm -f *.tex *.ps *.pdf

#EOC

