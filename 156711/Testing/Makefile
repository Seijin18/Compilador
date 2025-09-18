# Makefile para Compilador C-Minus 
# Projeto: Compilador e Assembler para Processador MIPS Customizado
# Data: 16 de Setembro de 2025

# Configurações do compilador
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99
LDFLAGS = 

# Diretórios
SRCDIR = .
TESTDIR = CMinusCodes/tests
UTILSDIR = ../../Utils

# Executáveis principais (seguindo padrão do Readme.txt)
COMPILER = testCompiler.exe
ASSEMBLER = testAssembler.exe
SIMULATOR = $(UTILSDIR)/mips_simulator.py

# Arquivos objeto necessários para o compilador (corrigido com dfa.c)
COMPILER_OBJS = bison.tab.o funcs.o intermediate.o dfa.o

# Arquivos fonte (corrigido com dfa.c)
COMPILER_SRCS = bison.tab.c funcs.c intermediate.c dfa.c
ASSEMBLER_SRCS = assembler.c

# Headers (conforme dependências do Readme.txt)
HEADERS = funcs.h intermediate.h bison.tab.h

# STATUS DOS CÓDIGOS CMINUS (Validado em Dezembro 2024)
# ✅ FUNCIONAIS: slt.c, teste_operacoes.c, mult.c, fibonacci.c, test_array_access.c
# ❌ COM PROBLEMAS: div.c (bug >=), gcd.c (loop infinito), fat.c (loop infinito)
# Taxa de sucesso real: ~71% (5/7 testados)

# Testes funcionais confirmados
FUNCTIONAL_TESTS = test_array_access test_array_param test_global_array test_loops_arrays

# Códigos CMinusCodes com problemas conhecidos  
BROKEN_CMINUS = div.c gcd.c fat.c
WORKING_CMINUS = slt.c mult.c fibonacci.c teste_operacoes.c

# Cores para output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
NC = \033[0m # No Color

.PHONY: all clean rebuild test-functional test-all help info

# Target padrão
all: $(COMPILER) $(ASSEMBLER)
	@echo "$(GREEN)✓ Build completo realizado com sucesso!$(NC)"
	@echo "$(YELLOW)Executáveis:$(NC)"
	@echo "  - $(COMPILER) (Compilador C-Minus)"
	@echo "  - $(ASSEMBLER) (Assembler MIPS)"
	@echo "$(YELLOW)Para testar:$(NC) make test-functional"
	@echo "$(YELLOW)Padrão do Readme.txt:$(NC)"
	@echo "  1. $(COMPILER) <arquivo.c>"
	@echo "  2. $(ASSEMBLER) intermediate.txt"

# Compilar o compilador principal (testCompiler.exe - conforme Readme.txt)
$(COMPILER): $(COMPILER_OBJS)
	@echo "$(YELLOW)🔗 Linkando compilador principal...$(NC)"
	$(CC) -o $@ $^
	@echo "$(GREEN)✓ $(COMPILER) compilado com sucesso!$(NC)"

# Compilar o assembler (testAssembler.exe - conforme Readme.txt)
$(ASSEMBLER): $(ASSEMBLER_SRCS)
	@echo "$(YELLOW)🔗 Compilando assembler...$(NC)"
	$(CC) $(CFLAGS) -o $@ $<
	@echo "$(GREEN)✓ $(ASSEMBLER) compilado com sucesso!$(NC)"

# Regras para arquivos objeto
%.o: %.c $(HEADERS)
	@echo "$(YELLOW)🔨 Compilando $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

# Bison - gerar parser se necessário (conforme Readme.txt)
bison.tab.c bison.tab.h: bison.y
	@echo "$(YELLOW)📝 Gerando parser com Bison...$(NC)"
	bison -d bison.y

# Target para recompilar tudo do zero
rebuild: clean all

# Limpeza de arquivos gerados
clean:
	@echo "$(YELLOW)🧹 Limpando arquivos gerados...$(NC)"
	-del *.o *.exe 2>nul
	-del intermediate.txt symbol_table.txt tree.txt 2>nul
	-del assembly_output*.asm binary_output*.txt 2>nul
	-del execution_debug*.txt assembly_log*.txt 2>nul
	-rmdir /s /q __pycache__ 2>nul
	@echo "$(GREEN)✓ Limpeza concluída!$(NC)"

# ============================================================================
# TESTES FUNCIONAIS
# ============================================================================

# Executar todos os testes funcionais
test-functional: $(COMPILER) $(ASSEMBLER)
	@echo "$(GREEN)🧪 EXECUTANDO TESTES FUNCIONAIS$(NC)"
	@echo "$(YELLOW)Conforme relatório: 4 testes devem funcionar corretamente$(NC)"
	@echo ""
	@$(MAKE) $(FUNCTIONAL_TESTS)
	@echo ""
	@echo "$(GREEN)✓ Todos os testes funcionais executados!$(NC)"

# Template para executar um teste específico
define run_test
	@echo "$(YELLOW)🔍 Testando: $(1).c$(NC)"
	@if not exist "$(TESTDIR)\$(1).c" ( \
		echo "$(RED)❌ Arquivo não encontrado: $(TESTDIR)\$(1).c$(NC)" & \
		exit 1 \
	)
	@echo "  Compilando C-Minus → Código Intermediário..."
	@.\$(COMPILER) $(TESTDIR)\$(1).c && echo "Código intermediário gerado com sucesso"
	@echo "  Gerando Assembly MIPS..."
	@.\$(ASSEMBLER) intermediate.txt && echo "Assembly gerado com sucesso"
	@echo "  Executando no simulador MIPS..."
	@python $(SIMULATOR) assembly_output_corrected.asm
	@echo "$(GREEN)✓ $(1).c executado com sucesso!$(NC)"
	@echo ""
endef

# Testes individuais funcionais
test_array_access: $(COMPILER) $(ASSEMBLER)
	$(call run_test,test_array_access)

test_array_param: $(COMPILER) $(ASSEMBLER)
	$(call run_test,test_array_param)

test_global_array: $(COMPILER) $(ASSEMBLER)
	$(call run_test,test_global_array)

test_loops_arrays: $(COMPILER) $(ASSEMBLER)
	$(call run_test,test_loops_arrays)

# ============================================================================
# TESTES COM PROBLEMAS CONHECIDOS
# ============================================================================

# Executar testes que têm problemas conhecidos (para debug)
test-broken: $(COMPILER) $(ASSEMBLER)
	@echo "$(RED)⚠️  EXECUTANDO TESTES COM PROBLEMAS CONHECIDOS$(NC)"
	@echo "$(YELLOW)Estes testes podem falhar conforme documentado no relatório$(NC)"
	@echo ""
	@-$(MAKE) $(BROKEN_TESTS)
	@echo ""
	@echo "$(YELLOW)⚠️  Testes com problemas executados (falhas esperadas)$(NC)"

test_multiple_functions: $(COMPILER) $(ASSEMBLER)
	$(call run_test,test_multiple_functions)

test_variable_scope: $(COMPILER) $(ASSEMBLER)
	$(call run_test,test_variable_scope)

# ============================================================================
# TESTES ESPECIAIS
# ============================================================================

# Teste de área do triângulo (requer inputs)
test_triangle_area: $(COMPILER) $(ASSEMBLER)
	@echo "$(YELLOW)🔍 Testando: test_triangle_area.c (com inputs)$(NC)"
	@echo "  Compilando C-Minus → Código Intermediário..."
	@.\$(COMPILER) $(TESTDIR)\test_triangle_area.c && echo "Código intermediário gerado com sucesso"
	@echo "  Gerando Assembly MIPS..."
	@.\$(ASSEMBLER) intermediate.txt && echo "Assembly gerado com sucesso"
	@echo "  Executando no simulador MIPS com inputs 6 e 8..."
	@python $(SIMULATOR) assembly_output_corrected.asm "6,8"
	@echo "$(GREEN)✓ test_triangle_area.c executado com sucesso!$(NC)"
	@echo "$(YELLOW)📊 Resultado esperado: (6 * 8) / 2 = 24$(NC)"
	@echo ""

# ============================================================================
# TESTES COMPLETOS
# ============================================================================

# Executar TODOS os testes (funcionais + com problemas)
test-all: test-functional test-broken

# ============================================================================
# VALIDAÇÃO ESPECÍFICA
# ============================================================================

# Validar apenas que a compilação funciona sem executar
validate-build: $(COMPILER) $(ASSEMBLER)
	@echo "$(GREEN)✓ Build validado com sucesso!$(NC)"
	@echo "Arquivos gerados:"
	@dir *.exe 2>nul || echo "Executáveis não encontrados"

# Testar um arquivo específico fornecido pelo usuário
test-file:
	@if "$(FILE)"=="" ( \
		echo "$(RED)❌ Uso: make test-file FILE=nome_do_arquivo.c [INPUTS=valor1,valor2,...]$(NC)" & \
		echo "$(YELLOW)Exemplo: make test-file FILE=test_triangle_area.c INPUTS=6,8$(NC)" & \
		exit 1 \
	)
	@if not exist "$(FILE)" ( \
		echo "$(RED)❌ Arquivo não encontrado: $(FILE)$(NC)" & \
		exit 1 \
	)
	@echo "$(YELLOW)🔍 Testando arquivo personalizado: $(FILE)$(NC)"
	@if not "$(INPUTS)"=="" echo "$(YELLOW)📝 Entradas: $(INPUTS)$(NC)"
	@echo "  Compilando C-Minus → Código Intermediário..."
	@.\$(COMPILER) $(FILE) && echo "Código intermediário gerado com sucesso"
	@echo "  Gerando Assembly MIPS..."
	@.\$(ASSEMBLER) intermediate.txt && echo "Assembly gerado com sucesso"
	@echo "  Executando no simulador MIPS..."
	@if "$(INPUTS)"=="" ( \
		python $(SIMULATOR) assembly_output_corrected.asm \
	) else ( \
		python $(SIMULATOR) assembly_output_corrected.asm "$(INPUTS)" \
	)
	@echo "$(GREEN)✓ $(FILE) executado com sucesso!$(NC)"

# ============================================================================
# INFORMAÇÕES E AJUDA
# ============================================================================

# Mostrar informações do projeto
info:
	@echo "$(GREEN)COMPILADOR C-MINUS - INFORMAÇÕES DO PROJETO$(NC)"
	@echo "============================================="
	@echo "$(YELLOW)Executáveis:$(NC)"
	@echo "  • $(COMPILER) - Compilador C-Minus para código intermediário"
	@echo "  • $(ASSEMBLER) - Assembler que converte código intermediário para MIPS"
	@echo "  • $(SIMULATOR) - Simulador MIPS em Python"
	@echo ""
	@echo "$(YELLOW)Fluxo de Compilação:$(NC)"
	@echo "  1. Código C-Minus (.c) → $(COMPILER) → Código Intermediário (.txt)"
	@echo "  2. Código Intermediário (.txt) → $(ASSEMBLER) → Assembly MIPS (.asm)"  
	@echo "  3. Assembly MIPS (.asm) → $(SIMULATOR) → Execução"
	@echo ""
	@echo "$(YELLOW)Status dos Testes (conforme relatório):$(NC)"
	@echo "  ✅ test_array_access.c - Arrays locais funcionando"
	@echo "  ✅ test_array_param.c - Arrays como parâmetros funcionando"
	@echo "  ✅ test_global_array.c - Arrays globais funcionando"
	@echo "  ✅ test_loops_arrays.c - Loops com arrays funcionando"
	@echo "  ❌ test_multiple_functions.c - Chamadas de função aninhadas com problemas"
	@echo "  ❌ test_variable_scope.c - Passagem de parâmetros com problemas"
	@echo ""
	@echo "$(YELLOW)Taxa de Sucesso:$(NC) 4/6 testes (67%)"

# Mostrar ajuda de uso
help:
	@echo "$(GREEN)MAKEFILE - COMPILADOR C-MINUS$(NC)"
	@echo "============================"
	@echo ""
	@echo "$(YELLOW)Targets Principais:$(NC)"
	@echo "  all                 - Compila todos os executáveis"
	@echo "  clean               - Remove arquivos gerados"
	@echo "  rebuild             - Limpeza + compilação completa"
	@echo ""
	@echo "$(YELLOW)Testes:$(NC)"
	@echo "  test-functional     - Executa os 4 testes funcionais"
	@echo "  test-broken         - Executa testes com problemas conhecidos"
	@echo "  test-all            - Executa todos os testes"
	@echo "  test-file FILE=x.c  - Testa um arquivo específico"
	@echo ""
	@echo "$(YELLOW)Testes Individuais:$(NC)"
	@echo "  test_array_access   - Teste de acesso a arrays"
	@echo "  test_array_param    - Teste de arrays como parâmetros"
	@echo "  test_global_array   - Teste de arrays globais"
	@echo "  test_loops_arrays   - Teste de loops com arrays"
	@echo "  test_multiple_functions - Teste de funções múltiplas (com problemas)"
	@echo "  test_variable_scope - Teste de escopo de variáveis (com problemas)"
	@echo "  test_triangle_area  - Teste de área do triângulo (com inputs)"
	@echo ""
	@echo "$(YELLOW)Informações:$(NC)"
	@echo "  info                - Mostra informações do projeto"
	@echo "  help                - Mostra esta ajuda"
	@echo "  validate-build      - Valida apenas a compilação"
	@echo ""
	@echo "$(YELLOW)Exemplos de Uso:$(NC)"
	@echo "  make                           # Compila tudo"
	@echo "  make test-functional           # Executa testes funcionais"
	@echo "  make test_array_access         # Testa apenas arrays"
	@echo "  make test_triangle_area        # Testa área do triângulo"
	@echo "  make test-file FILE=meu_teste.c # Testa arquivo específico"
	@echo "  make test-file FILE=teste.c INPUTS=10,20 # Com inputs"
	@echo "  make clean rebuild             # Recompila do zero"

# Target padrão se nenhum for especificado
.DEFAULT_GOAL := all