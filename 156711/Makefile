CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
BISON=bison
FLEX=flex

# Arquivos fonte
SOURCES=bison.tab.c funcs.c intermediate.c assembler.c
OBJECTS=$(SOURCES:.c=.o)
TARGET=compilador

# Arquivos de entrada para testes
TEST_FILES=entrada.txt gcd.c sort.c

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

bison.tab.c bison.tab.h: bison.y
	$(BISON) -d -v bison.y

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependências
funcs.o: funcs.c funcs.h
intermediate.o: intermediate.c intermediate.h funcs.h
assembler.o: assembler.c assembler.h intermediate.h funcs.h
bison.tab.o: bison.tab.c funcs.h intermediate.h assembler.h

clean:
	rm -f $(OBJECTS) $(TARGET) bison.tab.c bison.tab.h bison.output
	rm -f tree.txt symbol_table.txt intermediate.txt assembly.txt binary.txt
	rm -f *.exe *.out

test: $(TARGET)
	@echo "Testing with entrada.txt..."
	./$(TARGET) entrada.txt 3
	@echo "\nGenerated files:"
	@ls -la *.txt

# Teste individual com diferentes opções
test-lex: $(TARGET)
	./$(TARGET) entrada.txt 0

test-syntax: $(TARGET)
	./$(TARGET) entrada.txt 1

test-semantic: $(TARGET)
	./$(TARGET) entrada.txt 2

test-full: $(TARGET)
	./$(TARGET) entrada.txt 3

# Compile for Windows (if cross-compiling)
windows: $(SOURCES)
	i686-w64-mingw32-gcc $(CFLAGS) -o compilador.exe $(SOURCES)

help:
	@echo "Available targets:"
	@echo "  all        - Build the compiler"
	@echo "  clean      - Remove generated files"
	@echo "  test       - Run full test with entrada.txt"
	@echo "  test-lex   - Run lexical analysis only"
	@echo "  test-syntax- Run syntax analysis only"
	@echo "  test-semantic - Run semantic analysis only"
	@echo "  test-full  - Run complete compilation"
	@echo "  windows    - Cross-compile for Windows"
	@echo "  help       - Show this help"
