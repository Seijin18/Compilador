# Compilador C Menos - Build e Execução

## Compilação com Make

O projeto utiliza um `Makefile` para automatizar a compilação. As seguintes opções estão disponíveis:

### Compilar tudo
```bash
make all
```
Compila o compilador (`testCompiler.exe`) e o Assembler (`testAssembler.exe`).

### Executar compilador e Assembler
```bash
make run .\CMinusCodes\fibonacci.c
```
Compila o arquivo C Menos e gera o código de máquina intermediário.

### Executar simulador
```bash
make simulate 5
```
Executa o simulador MIPS com a entrada especificada (exemplo: `5` como argumento).
Obs: O simulador espera o arquivo 'assembly_output.asm' gerado pelo assembler.

### Limpar arquivos de build
```bash
make clean
```
Remove os executáveis e arquivos gerados pelo Bison.

## Compilação Manual

Caso deseje compilar manualmente sem o Makefile:

```bash
# Gerar parser com Bison
bison -d bison.y

# Compilar o compilador
gcc -o testCompiler.exe bison.tab.c funcs.c intermediate.c dfa.c

# Compilar o Assembler
gcc -o testAssembler.exe assembler.c

# Executar compilador
testCompiler.exe <arquivo_entrada>

# Executar Assembler
testAssembler.exe intermediate.txt
```

## Estrutura do Build

O processo de compilação segue as seguintes etapas:

1. **Parser (Bison)**: Gera `bison.tab.c` e `bison.tab.h` a partir de `bison.y`
2. **Compilador**: Compila o código C Menos para código intermediário
3. **Assembler**: Converte o código intermediário para MIPS assembly
4. **Simulador**: Executa o código MIPS gerado
