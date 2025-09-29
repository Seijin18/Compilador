# Makefile for compiler, assembler, and simulator (Windows cmd compatible)

# Compilers and flags
CC = gcc
BISON = bison
BISONFLAGS = -d
PYTHON = python
SIM = ..\..\Utils\mips_simulator.py

# Targets
all: testCompiler.exe testAssembler.exe

# Build parser with Bison
bison.tab.c bison.tab.h: bison.y
	$(BISON) $(BISONFLAGS) bison.y

# Build compiler (depends on Bison output)
testCompiler.exe: bison.tab.c bison.tab.h funcs.c intermediate.c dfa.c
	$(CC) -o testCompiler.exe bison.tab.c funcs.c intermediate.c dfa.c

# Build assembler
testAssembler.exe: assembler.c
	$(CC) -o testAssembler.exe assembler.c

# Run compiler + assembler
# Usage: make run .\CMinusCodes\fibonacci.c
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

# Clean build artifacts
clean:
	del /Q testCompiler.exe testAssembler.exe bison.tab.c bison.tab.h 2>nul || exit 0
