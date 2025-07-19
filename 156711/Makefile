# Makefile para o Assembler MIPS Customizado

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET_BASIC = assembler
TARGET_ADVANCED = assembler_advanced
TARGET_FIXED = assembler_fixed
TARGET_FINAL = assembler_final
SOURCE_BASIC = assembler.c
SOURCE_ADVANCED = assembler_advanced.c
SOURCE_FIXED = assembler_fixed.c
SOURCE_FINAL = assembler_final.c

# Arquivo de entrada padrão
INPUT_FILE = intermediate.txt
INPUT_COMPLEX = test_gcd.txt

# Target padrão - compila versão final
all: $(TARGET_FINAL)

# Compilação das diferentes versões
basic: $(TARGET_BASIC)
advanced: $(TARGET_ADVANCED)
fixed: $(TARGET_FIXED)
final: $(TARGET_FINAL)

$(TARGET_BASIC): $(SOURCE_BASIC)
	$(CC) $(CFLAGS) -o $(TARGET_BASIC) $(SOURCE_BASIC)

$(TARGET_ADVANCED): $(SOURCE_ADVANCED)
	$(CC) $(CFLAGS) -o $(TARGET_ADVANCED) $(SOURCE_ADVANCED)

$(TARGET_FIXED): $(SOURCE_FIXED)
	$(CC) $(CFLAGS) -o $(TARGET_FIXED) $(SOURCE_FIXED)

$(TARGET_FINAL): $(SOURCE_FINAL)
	$(CC) $(CFLAGS) -o $(TARGET_FINAL) $(SOURCE_FINAL)

# Regras de execução
run: $(TARGET_FINAL)
	./$(TARGET_FINAL) $(INPUT_FILE)

run-complex: $(TARGET_FINAL)
	./$(TARGET_FINAL) $(INPUT_COMPLEX)

run-basic: $(TARGET_BASIC)
	./$(TARGET_BASIC) $(INPUT_FILE)

run-advanced: $(TARGET_ADVANCED)
	./$(TARGET_ADVANCED) $(INPUT_FILE)

run-fixed: $(TARGET_FIXED)
	./$(TARGET_FIXED) $(INPUT_FILE)

# Limpeza dos arquivos gerados
clean:
	rm -f $(TARGET_BASIC) $(TARGET_BASIC).exe 
	rm -f $(TARGET_ADVANCED) $(TARGET_ADVANCED).exe
	rm -f $(TARGET_FIXED) $(TARGET_FIXED).exe
	rm -f $(TARGET_FINAL) $(TARGET_FINAL).exe
	rm -f assembly_output.asm binary_output.txt

# Regras de teste
test: $(TARGET_FINAL)
	@echo "=== Testando com arquivo básico: $(INPUT_FILE) ==="
	./$(TARGET_FINAL) $(INPUT_FILE)
	@echo ""
	@echo "=== Primeiras 20 linhas do Assembly Gerado ==="
	@head -20 assembly_output.asm
	@echo ""
	@echo "=== Primeiras 10 linhas do Código Binário ==="
	@head -10 binary_output.txt
	@echo ""

test-complex: $(TARGET_FINAL)
	@echo "=== Testando com arquivo complexo: $(INPUT_COMPLEX) ==="
	./$(TARGET_FINAL) $(INPUT_COMPLEX)
	@echo ""
	@echo "=== Assembly Gerado (GCD) ==="
	@head -30 assembly_output.asm
	@echo ""

test-all: $(TARGET_BASIC) $(TARGET_ADVANCED) $(TARGET_FIXED) $(TARGET_FINAL)
	@echo "=== Testando Todas as Versões ==="
	@echo ""
	@echo "--- Versão Básica ---"
	./$(TARGET_BASIC) $(INPUT_FILE) | grep "Instruções"
	@mv assembly_output.asm assembly_basic.asm
	@mv binary_output.txt binary_basic.txt
	@echo ""
	@echo "--- Versão Avançada ---"
	./$(TARGET_ADVANCED) $(INPUT_FILE) | grep "Instruções"
	@mv assembly_output.asm assembly_advanced.asm
	@mv binary_output.txt binary_advanced.txt
	@echo ""
	@echo "--- Versão Corrigida ---"
	./$(TARGET_FIXED) $(INPUT_FILE) | grep "Instruções"
	@mv assembly_output.asm assembly_fixed.asm
	@mv binary_output.txt binary_fixed.txt
	@echo ""
	@echo "--- Versão Final ---"
	./$(TARGET_FINAL) $(INPUT_FILE) | grep "Instruções"
	@mv assembly_output.asm assembly_final.asm
	@mv binary_output.txt binary_final.txt
	@echo ""
	@echo "Arquivos gerados:"
	@echo "- assembly_basic.asm / binary_basic.txt"
	@echo "- assembly_advanced.asm / binary_advanced.txt"
	@echo "- assembly_fixed.asm / binary_fixed.txt"
	@echo "- assembly_final.asm / binary_final.txt"

# Instalação
install: $(TARGET_FINAL)
	@mkdir -p ./bin
	cp $(TARGET_FINAL) ./bin/
	@echo "Assembler final instalado em ./bin/"

# Demonstração completa
demo: $(TARGET_FINAL)
	@echo "=========================================="
	@echo "DEMONSTRAÇÃO DO ASSEMBLER MIPS CUSTOMIZADO"
	@echo "=========================================="
	@echo ""
	@echo "1. Exemplo Básico (if-then-else):"
	@echo "----------------------------------"
	./$(TARGET_FINAL) $(INPUT_FILE)
	@echo ""
	@echo "Assembly gerado:"
	@cat assembly_output.asm
	@echo ""
	@echo "2. Exemplo Complexo (Função GCD):"
	@echo "--------------------------------"
	./$(TARGET_FINAL) $(INPUT_COMPLEX)
	@echo ""
	@echo "Assembly gerado (primeiras 25 linhas):"
	@head -25 assembly_output.asm
	@echo ""
	@echo "=========================================="

# Regra para exibir ajuda
help:
	@echo "Makefile para Assembler MIPS Customizado"
	@echo "========================================"
	@echo ""
	@echo "Versões disponíveis:"
	@echo "  basic       - $(SOURCE_BASIC) -> $(TARGET_BASIC)"
	@echo "  advanced    - $(SOURCE_ADVANCED) -> $(TARGET_ADVANCED)"
	@echo "  fixed       - $(SOURCE_FIXED) -> $(TARGET_FIXED)"
	@echo "  final       - $(SOURCE_FINAL) -> $(TARGET_FINAL) ⭐"
	@echo ""
	@echo "Targets de compilação:"
	@echo "  all         - Compila versão final (padrão)"
	@echo "  basic       - Compila versão básica"
	@echo "  advanced    - Compila versão avançada"
	@echo "  fixed       - Compila versão corrigida"
	@echo "  final       - Compila versão final"
	@echo ""
	@echo "Targets de execução:"
	@echo "  run         - Executa versão final com $(INPUT_FILE)"
	@echo "  run-complex - Executa versão final com $(INPUT_COMPLEX)"
	@echo "  run-basic   - Executa versão básica"
	@echo "  run-advanced- Executa versão avançada"
	@echo "  run-fixed   - Executa versão corrigida"
	@echo ""
	@echo "Targets de teste:"
	@echo "  test        - Testa versão final e mostra resultados"
	@echo "  test-complex- Testa com exemplo GCD"
	@echo "  test-all    - Testa todas as versões"
	@echo "  demo        - Demonstração completa do sistema"
	@echo ""
	@echo "Utilitários:"
	@echo "  install     - Instala assembler final em ./bin/"
	@echo "  clean       - Remove arquivos gerados"
	@echo "  help        - Mostra esta ajuda"
	@echo ""
	@echo "Uso típico:"
	@echo "  make && make test    # Compila e testa"
	@echo "  make demo           # Demonstração completa"
	@echo "  make run-complex    # Testa exemplo GCD"

.PHONY: all basic advanced fixed final run run-complex run-basic run-advanced run-fixed clean test test-complex test-all install demo help
