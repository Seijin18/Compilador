# Makefile for compiler, assembler, and simulator (Windows cmd compatible)
#
# After "make clean", regenerate the parser with "make parser" (requires bison)
# before "make all", or restore bison.tab.c / bison.tab.h from git.

# Compilers and flags
CC = gcc
BISON = bison
BISONFLAGS = -d
PYTHON = python
SIM = ..\..\Utils\mips_simulator.py

# Targets
all: testCompiler.exe testAssembler.exe

# Regenerate parser from bison.y (requires bison in PATH)
parser: bison.y
	$(BISON) $(BISONFLAGS) bison.y

# Build compiler (uses pre-generated bison.tab.c — no bison required)
testCompiler.exe: bison.tab.c bison.tab.h funcs.c intermediate.c dfa.c
	$(CC) -o testCompiler.exe bison.tab.c funcs.c intermediate.c dfa.c

# Build assembler
testAssembler.exe: assembler.c
	$(CC) -o testAssembler.exe assembler.c

# Run compiler + assembler
# Usage: make run ardoomino_controller.c
run: testCompiler.exe testAssembler.exe
	testCompiler $(word 2, $(MAKECMDGOALS))
	testAssembler intermediate.txt

# Run simulator only with first argument as input
# Usage: make simulate 5
simulate:
	$(PYTHON) $(SIM) .\assembly_output.asm $(word 2, $(MAKECMDGOALS))

# Trick to allow passing arguments after run/simulate
%:
	@:

# Remove all generated build and compiler output files
clean:
	del /Q testCompiler.exe testAssembler.exe 2>nul || exit 0
	del /Q bison.tab.c bison.tab.h 2>nul || exit 0
	del /Q intermediate.txt assembly_output.asm binary_output.txt 2>nul || exit 0
	del /Q tree.txt symbol_table.txt 2>nul || exit 0
	del /Q *.o 2>nul || exit 0
