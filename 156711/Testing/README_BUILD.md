# Guia de Build e Testes - Compilador C-Minus

## Visão Geral

Este projeto implementa um compilador completo para a linguagem C-Minus que gera código assembly MIPS. O projeto inclui:

- **Compilador C-Minus** (`testCompilerFixed.exe`) - Converte código C-Minus para código intermediário
- **Assembler MIPS** (`assembler.exe`) - Converte código intermediário para assembly MIPS  
- **Simulador MIPS** (`mips_simulator.py`) - Executa o código assembly gerado

## Pré-requisitos

- **GNU Make** (instalado via `winget install GnuWin32.Make`)
- **GCC Compiler** (MinGW/MSYS2)
- **Python 3.x** (para o simulador MIPS)
- **Windows PowerShell** (para execução dos comandos)

## Estrutura do Projeto

```
Testing/
├── Makefile                    # Build script principal
├── testCompilerFixed.exe      # Compilador C-Minus (gerado)
├── assembler.exe              # Assembler MIPS (gerado)
├── assembler.c                # Código fonte do assembler
├── bison.tab.c/h              # Parser gerado pelo Bison
├── funcs.c/h                  # Funções auxiliares do compilador
├── dfa.c                      # Analisador léxico
├── intermediate.c/h           # Geração de código intermediário
└── CMinusCodes/tests/         # Códigos de teste
    ├── test_array_access.c    # ✅ Teste de arrays funcionando
    ├── test_array_param.c     # ✅ Arrays como parâmetros funcionando
    ├── test_global_array.c    # ✅ Arrays globais funcionando
    ├── test_loops_arrays.c    # ✅ Loops com arrays funcionando
    ├── test_multiple_functions.c  # ❌ Funções múltiplas com problemas
    └── test_variable_scope.c      # ❌ Escopo de variáveis com problemas
```

## Comandos Disponíveis

### Build Commands

```bash
# Compilar todos os executáveis
make all

# Limpar arquivos gerados
make clean

# Recompilar tudo do zero
make rebuild

# Validar apenas a compilação (sem executar testes)
make validate-build
```

### Test Commands

```bash
# Executar todos os testes funcionais (recomendado)
make test-functional

# Executar testes que têm problemas conhecidos
make test-broken

# Executar TODOS os testes (funcionais + com problemas)
make test-all

# Executar um teste específico
make test_array_access
make test_array_param
make test_global_array
make test_loops_arrays
make test_multiple_functions
make test_variable_scope

# Testar um arquivo personalizado
make test-file FILE=CMinusCodes/tests/meu_teste.c
```

### Informações e Ajuda

```bash
# Mostrar informações detalhadas do projeto
make info

# Mostrar ajuda com todos os comandos
make help
```

## Fluxo de Compilação Detalhado

O processo de compilação e execução segue estas etapas:

### 1. Compilação C-Minus → Código Intermediário
```bash
./testCompilerFixed.exe arquivo.c
```
- **Entrada**: Arquivo `.c` em linguagem C-Minus
- **Saída**: `intermediate.txt` com código intermediário em quadruplas
- **Arquivos auxiliares**: `tree.txt`, `symbol_table.txt`

### 2. Assembly MIPS Generation
```bash
./assembler.exe intermediate.txt
```
- **Entrada**: `intermediate.txt` (código intermediário)
- **Saída**: `assembly_output_corrected.asm` (assembly MIPS)
- **Arquivos auxiliares**: `binary_output_corrected.txt`

### 3. Execução no Simulador MIPS
```bash
python ../../Utils/mips_simulator.py assembly_output_corrected.asm
```
- **Entrada**: `assembly_output_corrected.asm`
- **Saída**: Resultados da execução + log detalhado
- **Arquivos auxiliares**: `execution_debug.txt`

## Status dos Testes Funcionais

Conforme documentado no relatório de problemas:

### ✅ Testes Funcionais (4/6 - 67% de sucesso)

1. **test_array_access.c** - Arrays locais com acesso por índice
   - **Resultado esperado**: `[200, 400, 300, 400]`
   - **Status**: ✅ Funcionando (com pequena regressão detectada)

2. **test_array_param.c** - Arrays passados como parâmetros
   - **Resultado esperado**: `30`
   - **Status**: ✅ Funcionando completamente

3. **test_global_array.c** - Arrays globais
   - **Resultado esperado**: `[10, 20, 30]`
   - **Status**: ✅ Funcionando completamente

4. **test_loops_arrays.c** - Loops com operações em arrays
   - **Resultado esperado**: `[150, 10, 20, 30]`
   - **Status**: ✅ Funcionando completamente

### ❌ Testes com Problemas Conhecidos (2/6)

5. **test_multiple_functions.c** - Chamadas de função aninhadas
   - **Status**: ❌ Loop infinito por corrupção do Return Address

6. **test_variable_scope.c** - Escopo de variáveis e parâmetros
   - **Status**: ❌ Passagem de parâmetros parcialmente quebrada

## Exemplos de Uso

### Exemplo 1: Build Completo e Teste Básico
```bash
# Compilar tudo
make all

# Testar funcionalidades básicas
make test-functional

# Ver informações do projeto
make info
```

### Exemplo 2: Desenvolvimento e Debug
```bash
# Limpar e recompilar
make clean rebuild

# Testar um arquivo específico
make test_array_access

# Verificar logs detalhados
cat execution_debug.txt
```

### Exemplo 3: Teste de Arquivo Personalizado
```bash
# Criar seu próprio teste
echo 'void main(void) { output(42); }' > meu_teste.c

# Compilar e executar
make test-file FILE=meu_teste.c
```

## Troubleshooting

### Erro: "make: command not found"
```bash
# Instalar GNU Make
winget install GnuWin32.Make
```

### Erro: "gcc: command not found"
```bash
# Instalar GCC via MSYS2 ou MinGW
# Ou adicionar ao PATH
```

### Erro: Assembly vazio ou incorreto
```bash
# Verificar se o código intermediário foi gerado
cat intermediate.txt

# Verificar logs do assembler
./assembler.exe intermediate.txt
```

### Erro: Python ou simulador não encontrado
```bash
# Verificar caminho do simulador
ls ../../Utils/mips_simulator.py

# Testar diretamente
python ../../Utils/mips_simulator.py assembly_output_corrected.asm
```

## Arquivos Gerados

Durante o processo de build e testes, os seguintes arquivos são criados:

### Arquivos de Build
- `*.o` - Arquivos objeto compilados
- `testCompilerFixed.exe` - Compilador principal
- `assembler.exe` - Assembler MIPS

### Arquivos de Execução
- `intermediate.txt` - Código intermediário em quadruplas
- `tree.txt` - Árvore sintática do parser
- `symbol_table.txt` - Tabela de símbolos
- `assembly_output_corrected.asm` - Assembly MIPS gerado
- `binary_output_corrected.txt` - Representação binária
- `execution_debug.txt` - Log detalhado da execução

### Limpeza
```bash
# Remover todos os arquivos gerados
make clean
```

## Contribuição e Desenvolvimento

### Estrutura do Makefile

O Makefile está organizado em seções:
- **Configurações**: Variáveis de compilação e paths
- **Build Rules**: Regras para compilar executáveis
- **Test Templates**: Templates para execução de testes
- **Informational**: Comandos de ajuda e informações

### Adicionando Novos Testes

1. Criar arquivo `.c` em `CMinusCodes/tests/`
2. Adicionar regra no Makefile (opcional)
3. Executar com `make test-file FILE=novo_teste.c`

### Modificando o Build Process

As principais variáveis no Makefile:
- `CC`: Compilador (padrão: gcc)
- `CFLAGS`: Flags de compilação
- `UTILSDIR`: Diretório do simulador
- `TESTDIR`: Diretório dos testes

## Contato e Suporte

Para problemas ou dúvidas:
1. Verificar logs de debug gerados
2. Consultar o relatório de problemas (`relatorio_problemas_testes.txt`)
3. Usar `make help` para comandos disponíveis
4. Usar `make info` para status do projeto