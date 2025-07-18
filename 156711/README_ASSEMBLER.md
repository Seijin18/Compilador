# Compilador C- com Gerador de Assembly

Este compilador implementa todas as fases de compilação para a linguagem C-, incluindo análise léxica, sintática, semântica e geração de código assembly/binário para um processador MIPS customizado.

## Estrutura do Projeto

```
156711/
├── assembler.h          # Header do gerador de assembly
├── assembler.c          # Implementação do gerador de assembly
├── intermediate.h       # Header do gerador de código intermediário
├── intermediate.c       # Implementação do código intermediário (quadruplas)
├── funcs.h             # Funções auxiliares e estruturas principais
├── funcs.c             # Implementação das funções auxiliares
├── bison.y             # Gramática e parser Bison
├── bison.tab.c/h       # Arquivos gerados pelo Bison
├── Makefile            # Script de compilação
├── compilador.exe      # Executável do compilador
└── entrada.txt         # Arquivo de exemplo
```

## Como Compilar

```bash
# Gerar arquivos do parser
bison -d -v bison.y

# Compilar todos os módulos
gcc -Wall -Wextra -std=c99 -g -c funcs.c -o funcs.o
gcc -Wall -Wextra -std=c99 -g -c intermediate.c -o intermediate.o
gcc -Wall -Wextra -std=c99 -g -c assembler.c -o assembler.o
gcc -Wall -Wextra -std=c99 -g -c bison.tab.c -o bison.tab.o

# Linkar o executável
gcc -Wall -Wextra -std=c99 -g -o compilador bison.tab.o funcs.o intermediate.o assembler.o

# Ou usar o Makefile
make all
```

## Como Usar

```bash
./compilador <arquivo_fonte> <opcao>
```

### Opções disponíveis:

- **0**: Análise léxica apenas
- **1**: Análise sintática (gera árvore sintática)
- **2**: Análise semântica (gera tabela de símbolos)
- **3**: Compilação completa (gera assembly e código binário)

### Exemplo de uso:

```bash
# Análise léxica
./compilador entrada.txt 0

# Compilação completa
./compilador entrada.txt 3
```

## Arquivos de Saída

Dependendo da opção escolhida, o compilador gera:

- **tree.txt**: Árvore sintática abstrata
- **symbol_table.txt**: Tabela de símbolos
- **intermediate.txt**: Código intermediário (quadruplas)
- **assembly.txt**: Código assembly MIPS
- **binary.txt**: Código binário (32 bits por instrução)

## Arquitetura do Processador

O gerador de assembly produz código para um processador MIPS customizado com as seguintes características:

### Instruções Suportadas:

#### Aritméticas
- ADD, SUB, MULT, DIV
- AND, OR, SLL, SRL, SLT

#### Movimentação
- MOVE, MFHI, MFLO

#### Imediatas
- ADDI, SUBI, ANDI, ORI, LI, LA

#### Controle de Fluxo
- J, JAL, JR, JALR
- BEQ, BNE, BGT, BGTE, BLT, BLTE

#### Memória
- LW, SW

#### I/O
- INPUT, OUTPUTREG, OUTPUT_RESET

#### Controle
- HALT

### Registradores:

- **R0-R31**: Registradores gerais
- **FP (R28)**: Frame Pointer
- **SP (R29)**: Stack Pointer
- **RA (R30)**: Return Address
- **RF (R31)**: Valor de retorno

## Exemplo de Programa C-

```c
int fat(int x){
    if(x == 0){
        return 1;
    } else {
        return x * fat(x-1);
    }
}

void main(void){
    int x;
    x = input();
    output(fat(x));
}
```

## Código Intermediário Gerado

```
(goto,main, , )
(fun,fat, , )
(alloc,x,1, )
(immed,0, ,t0)
(==,x,t0,t1)
(if_f,t1,L0, )
(immed,1, ,t2)
(ret,t2, , )
(goto,L1, , )
(label,L0, , )
(immed,1, ,t3)
(-,x,t3,t4)
(param,t4, , )
(call,fat,t4,t5)
(*,x,t5,t6)
(ret,t6, , )
(label,L1, , )
(endfun, , , )
(fun,main, , )
(alloc,x,1, )
(input, , ,t7)
(asn,t7, ,x)
(param,x, , )
(call,fat,x,t8)
(output,t8,0, )
(endfun, , , )
```

## Assembly Gerado

```assembly
main:
    J 0

fat:
    SW SP, 0(FP)
    ADDI SP, SP, 1
    SW SP, 0(RA)
    ADDI SP, SP, 1
    MOVE FP
    LI R1, 0
    SUB R2, R3, R4
    BEQ R5, R0, 0
    LI R6, 1
    J 1
L0:
    LI R7, 1
    SUB R8, R9, R10
    MULT R12, R13
    MFLO R11
L1:
    MOVE SP
    SUBI SP, SP, 1
    LW SP, 0(RA)
    SUBI SP, SP, 1
    LW SP, 0(FP)
    JR RA

main:
    INPUT R14
    MOVE R16
    OUTPUTREG R17
    HALT
```

## Código Binário

O código binário é gerado no formato de 32 bits por instrução, seguindo o formato:

```
[31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMEDIATO
```

Exemplo:
```
01110000000000000000000000000000  ; J main
01101001110001110100000000000000  ; SW FP, 0(SP)
00111101110101110100000000000001  ; ADDI SP, SP, 1
...
```

## Funcionalidades Implementadas

### ✅ Geração de Código Assembly
- Tradução de quadruplas para instruções assembly
- Gerenciamento de registradores temporários
- Alocação de variáveis em escopos
- Suporte a funções e recursão

### ✅ Geração de Código Binário
- Conversão de instruções assembly para binário de 32 bits
- Codificação correta dos opcodes conforme especificação

### ✅ Gerenciamento de Memória
- Pilha para chamadas de função
- Frame pointer para acesso a variáveis locais
- Salvamento/restauração de contexto

### ✅ Estruturas de Controle
- Condicionais (if/else)
- Loops (while)
- Chamadas de função
- Retorno de valores

## Limitações Conhecidas

1. Gerenciamento de registradores simples (sem otimizações)
2. Não implementa otimizações de código
3. Suporte limitado a arrays
4. Não verifica overflow de registradores

## Melhorias Futuras

1. Implementar otimizações de código
2. Melhorar gerenciamento de registradores
3. Adicionar suporte completo a arrays
4. Implementar mais tipos de dados
5. Adicionar verificações de runtime

## Autores

Desenvolvido como parte do projeto de Compiladores.
