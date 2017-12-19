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
CFLAGS=-c -std=c99

BIN=mev

SDIR=src
ODIR=obj
BDIR=build

IDIR=inc
CDIR=$(SDIR)/components


# src/
SSRC=$(patsubst %,$(SDIR)/%,edbg.c system.c kernel.c)
# src/inc/
SINC=$(SDIR)/$(IDIR)
SDEP=$(patsubst %,$(SINC)/%,edbg.h system.h hardware.h)


# src/components/
CSRC=$(patsubst %,$(CDIR)/%,cpu.c memory.c)
# src/components/inc/
CINC=$(CDIR)/$(IDIR)
CDEP=$(patsubst %,$(CINC)/%,cpu.h memory.h)


OBJS=edbg.o system.o kernel.o cpu.o memory.o
OBJ=$(patsubst %,$(ODIR)/%,$(OBJS))

# path
SRC=$(SSRC) $(CSRC)
DEP=$(SDEP) $(CDEP)



all: files $(BIN)

$(ODIR)/%.o: $(SRC) $(DEP)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	$(CC) -o $(BDIR)/$@ $^

files:
	mkdir -p $(ODIR)
	mkdir -p $(BDIR)

.PHONY: clean

clean:
	rm $(ODIR)/*.o
	clear
	@echo "Cleaned up exec resources."

cleanf:							# Temporary to solve mistakes :|
	rm src/*.o 
	rm src/components/*.o
	rm build/mev.exe

dbg_paths:
	@echo "Includes: "$(DEP)
	@echo "Objects:  "$(OBJ)
	@echo "Sources:  "$(SRC)