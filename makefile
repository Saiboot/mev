# Project directory hierarchy
#	src/
#	|	edbg.c system.c kernel.c
#	|	inc/
#	|	|	edbg.h system.h hardware.h 
#	|	components/
#	|	|	cpu.c memory.c
#	|	|	inc/
#	|	|	|	cpu.h memory.h	
#	makefile
#	build/
#	obj/
#

CC=gcc
CFLAGS=-std=c99

# src dirs
SDIR=src
CDIR=$(SDIR)/components

# include dirs
SINC=$(SDIR)/inc
CINC=$(CDIR)/inc

# build dirs
ODIR=obj
BDIR=build

# src depends
_SDEP=edbg.h system.h hardware_def.h
SDEP=$(patsubst %,$(SINC)/%,$(_SDEP))

# component depends
_CDEP=cpu.h memory.h
CDEP=$(patsubst %,$(CINC)/%,$(_CDEP))

# all objs
_OBJ=edbg.o system.o kernel.o cpu.o memory.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

all: files mev

# compile all sdir/ to .o
$(ODIR)/%.o: $(SDIR)/%.c $(SDEP)
	$(CC) -c -o $@ $< $(CFLAGS)

# compile all cdir/ to .o
$(ODIR)/%.o: $(CDIR)/%.c $(CDEP)
	$(CC) -c -o $@ $< $(CFLAGS)
	
# link all obj to binary
mev: $(OBJ)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS)

files:
	mkdir -p $(ODIR)
	mkdir -p $(BDIR)

.PHONY: clean

clean:
	rm $(ODIR)/*.o
	clear
	@echo "Cleaned up exec resources."

dbg_paths:
	@echo "Includes: "$(DEP)
	@echo "Objects:  "$(OBJ)
	@echo "Sources:  "$(SRC)