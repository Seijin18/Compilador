# ESPECIFICAÇÕES COMPLETAS DO SISTEMA COMPILADOR-PROCESSADOR MIPS

## ÍNDICE
1. [Visão Geral do Sistema](#visão-geral-do-sistema)
2. [Especificações do Compilador](#especificações-do-compilador)
3. [Especificações do Processador MIPS](#especificações-do-processador-mips)
4. [Análise de Compatibilidade](#análise-de-compatibilidade)
5. [Correções e Melhorias Críticas](#correções-e-melhorias-críticas)
6. [Implementação de Operações Lógicas](#implementação-de-operações-lógicas)
7. [Implementação de Operações Aritméticas](#implementação-de-operações-aritméticas)
8. [Guia de Implementação](#guia-de-implementação)

---

## VISÃO GERAL DO SISTEMA

### Arquitetura do Sistema

O sistema é composto por uma toolchain completa que inclui:

1. **Frontend**: Compilador C- (subset de C) usando Bison/Yacc
2. **Middleend**: Geração de código intermediário em três endereços
3. **Backend**: Assembler que gera código binário para o processador MIPS customizado
4. **Hardware**: Processador MIPS implementado em Verilog para Quartus

### Fluxo de Compilação

```
Código C- → Análise Sintática → Código Intermediário → Assembly → Binário → Processador MIPS
    ↓             ↓                    ↓               ↓         ↓           ↓
  bison.y     funcs.c           intermediate.c    assembler.c  .txt      CPU.v
```

---

## ESPECIFICAÇÕES DO COMPILADOR

### 2.1 Gramática da Linguagem C-

#### Tokens Suportados
```bison
%token NUM ID IF ELSE WHILE INT RETURN VOID 
%token COMP DIF GT LT GE LE SOMA SUB MULT DIV ATR
%token PTV VIR APAR FPAR ACOL FCOL ACHV FCHV
%token CMT INPUT OUTPUT
```

#### Estruturas Sintáticas Suportadas

1. **Declarações de Variáveis**
   ```c
   int x;              // variável simples
   int vet[10];        // vetor
   ```

2. **Declarações de Funções**
   ```c
   int funcao(int param1, int param2) { ... }
   void main(void) { ... }
   ```

3. **Estruturas de Controle**
   ```c
   if (condicao) { ... } else { ... }
   while (condicao) { ... }
   ```

4. **Operações Aritméticas**
   ```c
   +, -, *, /
   ```

5. **Operações Lógicas e Relacionais**
   ```c
   ==, !=, <, <=, >, >=
   ```

6. **I/O**
   ```c
   input()     // leitura de entrada
   output(x)   // saída de valor
   ```

### 2.2 Geração de Código Intermediário

#### Formato das Quadruplas
```
(operador, arg1, arg2, resultado)
```

#### Tipos de Operações Intermediárias

1. **Operações Aritméticas**
   ```
   (+, x, y, t1)
   (-, x, y, t2)
   (*, x, y, t3)
   (/, x, y, t4)
   ```

2. **Atribuições**
   ```
   (asn, t1, , x)
   ```

3. **Saltos Condicionais**
   ```
   (if_t, x, , L1)    // pula se verdadeiro
   (if_f, x, , L2)    // pula se falso
   ```

4. **Saltos Incondicionais**
   ```
   (goto, L1, , )
   ```

5. **Funções**
   ```
   (fun, nome, , )
   (arg, param, , )
   (call, nome, nargs, resultado)
   (return, valor, , )
   (endfun, , , )
   ```

6. **I/O**
   ```
   (input, , , resultado)
   (output, valor, , )
   ```

### 2.3 Assembler

#### Características do Assembler

1. **Gerenciamento de Pilha**
   - Stack Pointer ($sp) e Frame Pointer ($fp)
   - Alocação dinâmica de espaço para variáveis locais
   - Suporte a chamadas recursivas

2. **Tabela de Símbolos**
   ```c
   typedef struct {
       char name[32];
       char scope[32];
       int offset;
       int size;
       int is_array;
       int is_global;
       int is_arg;
   } Symbol;
   ```

3. **Mapeamento de Registradores**
   - R0: zero constante
   - R1-R10: temporários
   - R29: stack pointer ($sp)
   - R30: frame pointer ($fp)
   - R31: return address ($ra)

---

## ESPECIFICAÇÕES DO PROCESSADOR MIPS

### 3.1 Formato das Instruções

**Formato Geral (32 bits):**
```
[31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMEDIATO/ENDEREÇO
```

**Campos:**
- **OPCODE [31:26]**: Código da operação (6 bits)
- **RS [25:20]**: Registrador fonte 1 (6 bits)
- **RT [19:14]**: Registrador fonte 2 (6 bits)
- **RD [13:8]**: Registrador destino (6 bits)
- **IMEDIATO [13:0]**: Valor imediato (14 bits)
- **ENDEREÇO [7:0]**: Endereço de salto (8 bits)

### 3.2 Conjunto de Instruções

#### Operações Aritméticas
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| ADD | 000000 | ADD RD, RS, RT | RD = RS + RT |
| SUB | 000001 | SUB RD, RS, RT | RD = RS - RT |
| MULT | 000010 | MULT RS, RT | HI:LO = RS * RT |
| DIV | 000011 | DIV RS, RT | HI = RS / RT, LO = RS % RT |

#### Operações Lógicas
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| AND | 000100 | AND RD, RS, RT | RD = RS & RT |
| OR | 000101 | OR RD, RS, RT | RD = RS \| RT |
| SLL | 000110 | SLL RD, RS, SHAMT | RD = RS << SHAMT |
| SRL | 000111 | SRL RD, RS, SHAMT | RD = RS >> SHAMT |

#### Operações de Comparação
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| SLT | 001000 | SLT RD, RS, RT | RD = (RS < RT) ? 1 : 0 |

#### Instruções de Branch
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| BEQ | 010011 | BEQ RS, RT, ADDR | if (RS == RT) PC = ADDR |
| BNE | 010100 | BNE RS, RT, ADDR | if (RS != RT) PC = ADDR |
| BGT | 010101 | BGT RS, RT, ADDR | if (RS > RT) PC = ADDR |
| BGTE | 010110 | BGTE RS, RT, ADDR | if (RS >= RT) PC = ADDR |
| BLT | 010111 | BLT RS, RT, ADDR | if (RS < RT) PC = ADDR |
| BLTE | 011000 | BLTE RS, RT, ADDR | if (RS <= RT) PC = ADDR |

#### Instruções de Salto
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| J | 011100 | J ADDR | PC = ADDR |
| JAL | 011101 | JAL ADDR | R31 = PC+1; PC = ADDR |
| JR | 001100 | JR RS | PC = RS |
| JALR | 001101 | JALR RS | R31 = PC+1; PC = RS |

#### Instruções de Memória
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| LW | 011001 | LW RT, OFFSET(RS) | RT = MEM[RS + OFFSET] |
| SW | 011010 | SW RT, OFFSET(RS) | MEM[RS + OFFSET] = RT |

#### Instruções Imediatas
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| ADDI | 001111 | ADDI RT, RS, IMM | RT = RS + IMM |
| SUBI | 010000 | SUBI RT, RS, IMM | RT = RS - IMM |
| LI | 011011 | LI RT, IMM | RT = IMM |

#### Instruções de I/O
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| INPUT | 100010 | INPUT RD | RD = switches |
| OUTPUTREG | 100000 | OUTPUTREG RS | Display = RS |
| OUTPUTMEM | 011111 | OUTPUTMEM RS, ADDR | Display = MEM[RS] |

#### Instruções de Controle
| Instrução | OPCODE | Formato | Operação |
|-----------|--------|---------|----------|
| HALT | 011110 | HALT | Para execução |

### 3.3 Arquitetura do Processador

#### Componentes Principais

1. **Unidade de Controle (Controle.v)**
   - Decodifica instruções
   - Gera sinais de controle
   - Coordena operação dos componentes

2. **ULA (ULA.v)**
   - Operações aritméticas e lógicas
   - Comparações
   - Saídas de 32 e 64 bits

3. **Banco de Registradores (Registradores.v)**
   - 32 registradores de 32 bits
   - Registradores especiais HI e LO

4. **Memória de Programa (ROMSinglePort.v)**
   - Armazena instruções
   - Endereçamento de 8 bits (256 instruções)

5. **Memória de Dados (RAMDualPortDualClock.v)**
   - Dual-port para leitura/escrita simultânea
   - Suporte a endereçamento indireto

6. **Program Counter (ProgramCounter.v)**
   - Controle de fluxo de execução
   - Suporte a branches e jumps

---

## ANÁLISE DE COMPATIBILIDADE

### 4.1 Pontos de Compatibilidade

#### ✅ Funcionalidades Compatíveis

1. **Operações Aritméticas Básicas**
   - Adição, subtração: totalmente compatíveis
   - Multiplicação: simplificada (32 bits)
   - Divisão: simplificada (32 bits)

2. **Operações Lógicas**
   - AND, OR: totalmente compatíveis
   - Comparações: suporte completo

3. **Estruturas de Controle**
   - Branches condicionais: suporte completo
   - Loops while: funcionais
   - Condicionais if-else: funcionais

4. **I/O Básico**
   - Input/Output: implementados

### 4.2 Limitações Identificadas

#### ⚠️ Limitações Críticas

1. **Multiplicação e Divisão Simplificadas**
   ```verilog
   // ULA.v - MULT simplificado
   4'b0010: result_32 = in1 * in2;  // Deveria usar HI:LO
   
   // ULA.v - DIV simplificado  
   4'b0011: result_32 = in1 / in2;  // Deveria: HI=quociente, LO=resto
   ```

2. **Endereçamento de Branches Limitado**
   - Apenas 8 bits para endereço (0-255)
   - Sem offset relativo ao PC
   - Limitação para programas grandes

3. **Gerenciamento de Pilha Básico**
   - Stack pointer implementado
   - Frame pointer presente mas subutilizado

---

## CORREÇÕES E MELHORIAS CRÍTICAS

### 5.1 Correções no Processador (ULA.v)

#### Multiplicação Corrigida
```verilog
// Correção necessária na ULA.v
4'b0010:
    begin
    result_64 = in1 * in2;          // Resultado completo 64-bit
    result_32 = result_64[31:0];    // Parte baixa (LO)
    out1 = 1'b0;
    sign_hilo = 1'b1;               // Indica operação HI:LO válida
    end
```

#### Divisão Corrigida
```verilog
// Correção necessária na ULA.v
4'b0011:
    begin
    if (in2 != 0) begin
        result_64[63:32] = in1 / in2;   // HI = quociente
        result_64[31:0] = in1 % in2;    // LO = resto
        sign_hilo = 1'b1;               // Indica operação HI:LO válida
    end else begin
        result_64 = 64'b0;              // Divisão por zero
        sign_hilo = 1'b0;
    end
    result_32 = result_64[63:32];       // Retorna quociente por padrão
    out1 = 1'b0;
    end
```

### 5.2 Melhorias no Assembler

#### Suporte Melhorado para Operações Complexas
```c
// Adição no assembler.c para multiplicação 64-bit
void generate_mult_64bit(const char* rs, const char* rt, const char* hi_reg, const char* lo_reg) {
    fprintf(output, "mult %s, %s\n", rs, rt);
    fprintf(output, "mfhi %s\n", hi_reg);
    fprintf(output, "mflo %s\n", lo_reg);
}

// Adição para divisão com resto
void generate_div_with_remainder(const char* rs, const char* rt, const char* quot_reg, const char* rem_reg) {
    fprintf(output, "div %s, %s\n", rs, rt);
    fprintf(output, "mfhi %s\n", quot_reg);  // HI = quociente
    fprintf(output, "mflo %s\n", rem_reg);   // LO = resto
}
```

### 5.3 Extensões do Compilador

#### Suporte a Expressões Complexas
```c
// Em intermediate.c - geração de código para operações complexas
static char* genComplexOperation(AASNode* node, FILE* out) {
    switch (node->token) {
        case MULT: {
            char* left = genNode(node->children, out);
            char* right = genNode(node->children->sibling, out);
            char* temp_hi = newTemp();
            char* temp_lo = newTemp();
            
            emitQuad("mult", left, right, temp_lo);
            emitQuad("mfhi", " ", " ", temp_hi);
            emitQuad("mflo", " ", " ", temp_lo);
            
            return temp_lo;  // Retorna parte baixa por padrão
        }
        case DIV: {
            char* left = genNode(node->children, out);
            char* right = genNode(node->children->sibling, out);
            char* temp_quot = newTemp();
            char* temp_rem = newTemp();
            
            emitQuad("div", left, right, temp_quot);
            emitQuad("mfhi", " ", " ", temp_quot);
            emitQuad("mflo", " ", " ", temp_rem);
            
            return temp_quot;  // Retorna quociente
        }
    }
}
```

---

## IMPLEMENTAÇÃO DE OPERAÇÕES LÓGICAS

### 6.1 Estruturas Condicionais

#### Implementação de if (x == 0)

**Código C-:**
```c
if (x == 0) {
    // bloco then
} else {
    // bloco else
}
```

**Código Intermediário Gerado:**
```
(==, x, 0, t1)
(if_f, t1, , L_else)
; bloco then
(goto, L_end, , )
(label, L_else, , )
; bloco else
(label, L_end, , )
```

**Assembly Gerado:**
```assembly
li $t0, 0
beq $x, $t0, L_then
j L_else
L_then:
    ; bloco then
    j L_end
L_else:
    ; bloco else
L_end:
```

**Binário Processador:**
```
01101100000000001000000000000000  ; LI $t0, 0
01001100000010000100000000000100  ; BEQ $x, $t0, 4 (L_then)
01110000000000000000000000001000  ; J 8 (L_else)
; ... código do bloco then ...
01110000000000000000000000001100  ; J 12 (L_end)
; ... código do bloco else ...
```

### 6.2 Adaptações para Diferentes Comparações

#### Mapeamento de Operadores Lógicos

| Operador C- | Instrução MIPS | OPCODE | Descrição |
|-------------|----------------|--------|-----------|
| == | BEQ | 010011 | Branch if Equal |
| != | BNE | 010100 | Branch if Not Equal |
| > | BGT | 010101 | Branch if Greater Than |
| >= | BGTE | 010110 | Branch if Greater or Equal |
| < | BLT | 010111 | Branch if Less Than |
| <= | BLTE | 011000 | Branch if Less or Equal |

#### Exemplo: if (x > y)
```c
// Código C-
if (x > y) {
    statement;
}
```

```assembly
; Assembly gerado
bgt $x, $y, L_then
j L_end
L_then:
    ; statement
L_end:
```

### 6.3 Implementação de Loops

#### While Loop
```c
while (i < 10) {
    i = i + 1;
}
```

**Código Intermediário:**
```
(label, L_loop, , )
(<, i, 10, t1)
(if_f, t1, , L_end)
(+, i, 1, t2)
(asn, t2, , i)
(goto, L_loop, , )
(label, L_end, , )
```

**Assembly:**
```assembly
L_loop:
    li $t0, 10
    blt $i, $t0, L_body
    j L_end
L_body:
    addi $i, $i, 1
    j L_loop
L_end:
```

---

## IMPLEMENTAÇÃO DE OPERAÇÕES ARITMÉTICAS

### 7.1 Operações Básicas como Blocos de Construção

#### Adição e Subtração
```c
int result = a + b - c;
```

**Código Intermediário:**
```
(+, a, b, t1)
(-, t1, c, t2)
(asn, t2, , result)
```

**Assembly:**
```assembly
add $t1, $a, $b      ; t1 = a + b
sub $t2, $t1, $c     ; t2 = t1 - c
move $result, $t2    ; result = t2
```

### 7.2 Implementação de Multiplicação Complexa

#### Multiplicação usando Soma Repetida
```c
// Função de multiplicação por soma (para números pequenos)
int mult_by_add(int a, int b) {
    int result = 0;
    int i = 0;
    while (i < b) {
        result = result + a;
        i = i + 1;
    }
    return result;
}
```

#### Multiplicação Eficiente (usando MULT)
```c
// Usando instrução MULT do processador
int efficient_mult(int a, int b) {
    return a * b;  // Compilador gera instrução MULT
}
```

### 7.3 Implementação de Divisão

#### Divisão por Subtração Sucessiva
```c
int div_by_sub(int dividend, int divisor) {
    int quotient = 0;
    while (dividend >= divisor) {
        dividend = dividend - divisor;
        quotient = quotient + 1;
    }
    return quotient;
}
```

#### Divisão com Resto
```c
struct div_result {
    int quotient;
    int remainder;
};

struct div_result divide(int a, int b) {
    struct div_result result;
    result.quotient = a / b;     // Usa DIV instruction
    result.remainder = a % b;    // Implementado como a - (a/b)*b
    return result;
}
```

### 7.4 Operações Complexas Derivadas

#### Potenciação
```c
int power(int base, int exp) {
    int result = 1;
    int i = 0;
    while (i < exp) {
        result = result * base;
        i = i + 1;
    }
    return result;
}
```

#### Fatorial (já implementado)
```c
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
```

#### Maior Divisor Comum (já implementado)
```c
int gcd(int u, int v) {
    if (v == 0) return u;
    else return gcd(v, u - u/v*v);  // u mod v
}
```

---

## GUIA DE IMPLEMENTAÇÃO

### 8.1 Configuração do Ambiente

#### Requisitos
1. **Compilador Bison/Yacc**
2. **GCC para compilação**
3. **Quartus para síntese do processador**
4. **Arquivos do projeto organizados**

#### Estrutura de Diretórios Recomendada
```
Projeto/
├── Compilador/
│   ├── src/           # Código fonte do compilador
│   ├── tests/         # Programas de teste
│   ├── intermediate/  # Código intermediário gerado
│   └── assembly/      # Assembly gerado
├── Processador/
│   ├── verilog/       # Módulos Verilog
│   ├── testbench/     # Testes do processador
│   └── synthesis/     # Arquivos de síntese
└── Utils/
    └── docs/          # Documentação
```

### 8.2 Processo de Compilação

#### Passo a Passo
```bash
# 1. Compilar o parser
bison -d bison.y
gcc -o compiler bison.tab.c funcs.c intermediate.c

# 2. Compilar o assembler
gcc -o assembler assembler.c

# 3. Compilar programa C-
./compiler programa.c

# 4. Gerar assembly
./assembler intermediate.txt

# 5. Carregar no processador
# Copiar binary_output.txt para ROM do Quartus
```

### 8.3 Testes Recomendados

#### Suite de Testes Básica

1. **Teste Aritmético**
```c
void main(void) {
    int a, b, sum, diff, prod, quot;
    a = input();
    b = input();
    sum = a + b;
    diff = a - b;
    prod = a * b;
    quot = a / b;
    output(sum);
    output(diff);
    output(prod);
    output(quot);
}
```

2. **Teste Lógico**
```c
void main(void) {
    int x, y;
    x = input();
    y = input();
    
    if (x == y) {
        output(1);
    } else if (x > y) {
        output(2);
    } else {
        output(3);
    }
}
```

3. **Teste de Loop**
```c
void main(void) {
    int i, sum;
    sum = 0;
    i = 1;
    while (i <= 10) {
        sum = sum + i;
        i = i + 1;
    }
    output(sum);  // Deve imprimir 55
}
```

4. **Teste de Função Recursiva**
```c
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void main(void) {
    int n, result;
    n = input();
    result = fibonacci(n);
    output(result);
}
```

### 8.4 Debugging e Validação

#### Pontos de Verificação

1. **Código Intermediário**
   - Verificar geração correta de quadruplas
   - Validar labels e saltos
   - Confirmar passagem de parâmetros

2. **Assembly**
   - Validar mapeamento de registradores
   - Verificar gestão da pilha
   - Confirmar instruções geradas

3. **Binário**
   - Verificar encoding das instruções
   - Validar endereços de branch
   - Confirmar opcodes

4. **Simulação no Processador**
   - Testar execução passo a passo
   - Verificar estado dos registradores
   - Validar operações da ULA

### 8.5 Otimizações Futuras

#### Melhorias Sugeridas

1. **Compilador**
   - Otimização de registradores
   - Eliminação de código morto
   - Propagação de constantes

2. **Processador**
   - Pipeline básico
   - Cache de instruções
   - Predição de branches

3. **Conjunto de Instruções**
   - Instruções de shift mais eficientes
   - Operações bit-a-bit
   - Multiplicação/divisão por constantes

---

## CONCLUSÃO

Este sistema compilador-processador fornece uma base sólida para execução de programas com operações lógicas e aritméticas básicas. As correções e melhorias sugeridas garantem maior robustez e compatibilidade entre os componentes.

### Características Principais
- ✅ Operações aritméticas básicas funcionais
- ✅ Estruturas de controle completas  
- ✅ Suporte a funções e recursão
- ✅ I/O básico implementado
- ⚠️ Multiplicação/divisão precisam de correção
- ⚠️ Endereçamento de branches limitado

### Próximos Passos
1. Implementar correções na ULA
2. Expandir suite de testes
3. Otimizar geração de código
4. Adicionar mais instruções MIPS

**Data de Criação:** Setembro 2025  
**Versão:** 1.0  
**Autor:** Documentação Técnica Automatizada
