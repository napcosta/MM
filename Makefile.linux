###############################################################################
#
# Makefile
#
# Created: March 2011 by Miguel Wahnon Monteiro, IST
# Adapted: March 2011 by J M Brisson Lopes, IST
#
###############################################################################

LIBINCDIR   = cglib/include
LIBINCDIRCG = $(LIBINCDIR)/cg
LIBSRCDIR   = cglib/src
LIBDIR      = cglib/lib

LIBSOURCES = $(wildcard $(LIBSRCDIR)/*.cpp)
LIBOBJS    = $(LIBSOURCES:$(LIBSRCDIR)%.cpp=$(LIBDIR)%.o)
LIBNAME    = cglib.a
LIB        = $(LIBDIR)/$(LIBNAME)

PROGRAM    = test
PRGSRCDIR  = template
PRGSRC     = $(wildcard $(PRGSRCDIR)/*.cpp)
PRGOBJDIR  = $(PRGSRCDIR)/obj
PRGOBJS    = $(PRGSRC:$(PRGSRCDIR)%.cpp=$(PRGOBJDIR)%.o)
PRGINCDIR  = template

###############################################################################

ifdef DEBUG
OPTFLAGS = -g
else
OPTFLAGS = -O3
endif

CC      = g++
#CFLAGS  = -Wall $(OPTFLAGS)
CFLAGS  = $(OPTFLAGS)
#LDFLAGS =  -L$(LIBDIR) -l$(LIBNAME) -lGL -lglut -lm -lX11 -lGLU
LDFLAGS =  -L$(LIBDIR) $(LIBDIR)/$(LIBNAME) -lGL -lglut -lm -lX11 -lGLU
INCFLAGS = -I$(LIBINCDIR) -I$(LIBINCDIRCG)

###############################################################################

all: $(PRGOBJDIR) $(PROGRAM)

lib: $(LIBDIR) $(LIBSOURCES) $(LIBINCDIRCG)/*.h $(LIBOBJS)
	rm -f $(LIB)
	ar -cq $(LIB) $(LIBOBJS)
	ranlib $(LIB)

$(PROGRAM): $(PRGSRC) $(PRGOBJS) $(PRGOBJDIR) $(LIB)
	$(CC) $(CFLAGS) $(PRGOBJS) -I$(PRGINCDIR) $(INCFLAGS) $(LDFLAGS) -o $(PROGRAM)

$(LIB): $(LIBDIR) $(LIBSOURCES) $(LIBINCDIRCG)/*.h $(LIBOBJS)
	rm -f $(LIB)
	ar -cq $(LIB) $(LIBOBJS)
	ranlib $(LIB)

$(LIBDIR) $(PRGOBJDIR):
	@ test -d $@ || mkdir -p $@
	
clean:
	rm -f $(PROGRAM)
	rm -rf $(PRGOBJDIR)
	rm -rf $(LIBDIR)
	rm -f log.txt

.PHONY: all clean

###############################################################################

$(LIBDIR)/%.o: $(LIBSRCDIR)/%.cpp
	$(CC) -c $(CFLAGS) $^ -o $@ $(INCFLAGS)

$(PRGOBJDIR)/%.o: $(PRGSRCDIR)/%.cpp
	$(CC) -c $(CFLAGS) $^ -o $@ $(INCFLAGS)

###############################################################################
