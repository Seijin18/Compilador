# Set de Instruções - Simulador MIPS

## 📋 Visão Geral

O simulador implementa **43 instruções MIPS** customizadas, organizadas em categorias funcionais. Cada instrução segue o formato de 32 bits com campos específicos para opcode, registradores e imediatos.

## 🏗️ Formato das Instruções

### Formato Geral (32 bits)
```
[31:26] OPCODE | [25:20] RS | [19:14] RT | [13:8] RD | [7:0] IMMEDIATE
```

### Convenções
- **RS**: Registrador fonte
- **RT**: Registrador fonte/destino secundário
- **RD**: Registrador destino
- **IMMEDIATE**: Valor imediato (8 bits, -128 a 127)

## 📊 Tabela de Instruções

| Opcode | Mnemônico | Tipo | Descrição | Formato |
|--------|-----------|------|-----------|---------|
| 0x00 | ADD | R | Adição | ADD RD, RS, RT |
| 0x01 | SUB | R | Subtração | SUB RD, RS, RT |
| 0x02 | MULT | R | Multiplicação | MULT RS, RT |
| 0x03 | DIV | R | Divisão | DIV RS, RT |
| 0x04 | AND | R | E lógico | AND RD, RS, RT |
| 0x05 | OR | R | OU lógico | OR RD, RS, RT |
| 0x06 | XOR | R | OU exclusivo | XOR RD, RS, RT |
| 0x07 | NOR | R | NOR lógico | NOR RD, RS, RT |
| 0x08 | SLT | R | Set Less Than | SLT RD, RS, RT |
| 0x09 | SGT | R | Set Greater Than | SGT RD, RS, RT |
| 0x0A | SLE | R | Set Less Equal | SLE RD, RS, RT |
| 0x0B | SGE | R | Set Greater Equal | SGE RD, RS, RT |
| 0x0C | SLL | R | Shift Left Logical | SLL RD, RS, IMM |
| 0x0D | SRL | R | Shift Right Logical | SRL RD, RS, IMM |
| 0x0E | SRA | R | Shift Right Arithmetic | SRA RD, RS, IMM |
| 0x0F | ADDI | I | Add Immediate | ADDI RT, RS, IMM |
| 0x10 | SUBI | I | Sub Immediate | SUBI RT, RS, IMM |
| 0x11 | ANDI | I | And Immediate | ANDI RT, RS, IMM |
| 0x12 | ORI | I | Or Immediate | ORI RT, RS, IMM |
| 0x13 | XORI | I | Xor Immediate | XORI RT, RS, IMM |
| 0x14 | SLTI | I | Set Less Than Immediate | SLTI RT, RS, IMM |
| 0x15 | LW | I | Load Word | LW RT, IMM(RS) |
| 0x16 | SW | I | Store Word | SW RT, IMM(RS) |
| 0x17 | LI | I | Load Immediate | LI RT, IMM |
| 0x18 | BEQ | I | Branch Equal | BEQ RS, RT, IMM |
| 0x19 | BNE | I | Branch Not Equal | BNE RS, RT, IMM |
| 0x1A | BGT | I | Branch Greater Than | BGT RS, RT, IMM |
| 0x1B | BLT | I | Branch Less Than | BLT RS, RT, IMM |
| 0x1C | BGTE | I | Branch Greater Equal | BGTE RS, RT, IMM |
| 0x1D | BLTE | I | Branch Less Equal | BLTE RS, RT, IMM |
| 0x1E | J | J | Jump | J TARGET |
| 0x1F | JAL | J | Jump And Link | JAL TARGET |
| 0x20 | JR | R | Jump Register | JR RS |
| 0x21 | MFHI | R | Move From HI | MFHI RD |
| 0x22 | MFLO | R | Move From LO | MFLO RD |
| 0x23 | MOVE | R | Move Register | MOVE RD, RS |
| 0x24 | NOP | - | No Operation | NOP |
| 0x25 | HALT | - | Halt Execution | HALT |
| 0x26 | INPUT | I | Input to Register | INPUT RD |
| 0x27 | OUTPUT | I | Output from Memory | OUTPUT IMM |
| 0x28 | OUTPUTREG | R | Output from Register | OUTPUTREG RS |

## 🔧 Descrição Detalhada

### Instruções Aritméticas

#### ADD - Adição
```assembly
ADD R1, R2, R3    # R1 = R2 + R3
```
- **Função**: Soma dois registradores
- **Overflow**: Não verificado
- **Flags**: Nenhuma

#### SUB - Subtração
```assembly
SUB R1, R2, R3    # R1 = R2 - R3
```
- **Função**: Subtrai RT de RS
- **Resultado**: Pode ser negativo
- **Flags**: Nenhuma

#### MULT - Multiplicação
```assembly
MULT R2, R3       # HI:LO = R2 * R3
```
- **Função**: Multiplica dois registradores
- **Resultado**: 64 bits em HI:LO
- **Acesso**: Use MFHI/MFLO

#### DIV - Divisão
```assembly
DIV R2, R3        # LO = R2 / R3, HI = R2 % R3
```
- **Função**: Divide RS por RT
- **Quociente**: LO
- **Resto**: HI
- **Divisão por zero**: Resultado indefinido

### Instruções Lógicas

#### AND - E Lógico
```assembly
AND R1, R2, R3    # R1 = R2 & R3
```
- **Função**: AND bit a bit
- **Resultado**: 1 onde ambos bits são 1

#### OR - OU Lógico
```assembly
OR R1, R2, R3     # R1 = R2 | R3
```
- **Função**: OR bit a bit
- **Resultado**: 1 onde pelo menos um bit é 1

#### XOR - OU Exclusivo
```assembly
XOR R1, R2, R3    # R1 = R2 ^ R3
```
- **Função**: XOR bit a bit
- **Resultado**: 1 onde bits são diferentes

#### NOR - NOR Lógico
```assembly
NOR R1, R2, R3    # R1 = ~(R2 | R3)
```
- **Função**: NOT OR bit a bit
- **Resultado**: Inversão de OR

### Instruções de Comparação

#### SLT - Set Less Than
```assembly
SLT R1, R2, R3    # R1 = (R2 < R3) ? 1 : 0
```
- **Função**: Compara com sinal
- **Resultado**: 1 se verdadeiro, 0 se falso

#### SGT - Set Greater Than
```assembly
SGT R1, R2, R3    # R1 = (R2 > R3) ? 1 : 0
```
- **Função**: Maior que com sinal
- **Uso**: Implementação de loops

### Instruções de Shift

#### SLL - Shift Left Logical
```assembly
SLL R1, R2, 4     # R1 = R2 << 4
```
- **Função**: Desloca bits para esquerda
- **Preenchimento**: Zeros à direita
- **Máximo**: 31 posições

#### SRL - Shift Right Logical
```assembly
SRL R1, R2, 4     # R1 = R2 >> 4 (lógico)
```
- **Função**: Desloca bits para direita
- **Preenchimento**: Zeros à esquerda

#### SRA - Shift Right Arithmetic
```assembly
SRA R1, R2, 4     # R1 = R2 >> 4 (aritmético)
```
- **Função**: Desloca preservando sinal
- **Preenchimento**: Bit de sinal

### Instruções Imediatas

#### ADDI - Add Immediate
```assembly
ADDI R1, R2, 10   # R1 = R2 + 10
```
- **Função**: Soma constante
- **Immediate**: -128 a 127
- **Extensão**: Com sinal

#### LI - Load Immediate
```assembly
LI R1, 42         # R1 = 42
```
- **Função**: Carrega constante
- **Uso**: Inicialização
- **Extensão**: Com sinal

### Instruções de Memória

#### LW - Load Word
```assembly
LW R1, 4(R29)     # R1 = MEM[R29 + 4]
```
- **Função**: Carrega da memória
- **Endereço**: Base + offset
- **Tamanho**: 32 bits

#### SW - Store Word
```assembly
SW R1, 4(R29)     # MEM[R29 + 4] = R1
```
- **Função**: Armazena na memória
- **Endereço**: Base + offset
- **Tamanho**: 32 bits

### Instruções de Controle

#### BEQ - Branch Equal
```assembly
BEQ R1, R2, label # if (R1 == R2) PC = label
```
- **Função**: Desvio condicional
- **Condição**: Igualdade
- **Offset**: Relativo ao PC

#### BNE - Branch Not Equal
```assembly
BNE R1, R2, label # if (R1 != R2) PC = label
```
- **Função**: Desvio condicional
- **Condição**: Desigualdade

#### J - Jump
```assembly
J main            # PC = main
```
- **Função**: Salto incondicional
- **Endereço**: Absoluto
- **Uso**: Loops e funções

#### JAL - Jump And Link
```assembly
JAL function      # R31 = PC + 1; PC = function
```
- **Função**: Chamada de função
- **Return Address**: Salvo em R31
- **Uso**: Implementação de funções

#### JR - Jump Register
```assembly
JR R31            # PC = R31
```
- **Função**: Retorno de função
- **Endereço**: Do registrador
- **Uso**: Return statements

### Instruções de Sistema

#### INPUT - Input
```assembly
INPUT R8          # R8 = próximo_input()
```
- **Função**: Leitura de entrada
- **Fonte**: input_values array
- **Formato**: Inteiro de 32 bits

#### OUTPUT - Output Memory
```assembly
OUTPUT 10         # display = MEM[10]
```
- **Função**: Saída da memória
- **Destino**: Display register
- **Uso**: Resultados de programas

#### OUTPUTREG - Output Register
```assembly
OUTPUTREG R12     # display = R12
```
- **Função**: Saída de registrador
- **Destino**: Display register
- **Uso**: Resultados diretos

#### HALT - Halt
```assembly
HALT              # Parar execução
```
- **Função**: Termina programa
- **Estado**: halted = True
- **Uso**: Final de programas

### Instruções Especiais

#### MOVE - Move Register
```assembly
MOVE R1, R2       # R1 = R2
```
- **Função**: Copia registrador
- **Implementação**: ADD R1, R2, R0
- **Uso**: Pseudoinstrução

#### MFHI - Move From HI
```assembly
MFHI R1           # R1 = HI
```
- **Função**: Acessa parte alta do resultado
- **Uso**: Após MULT/DIV
- **Tamanho**: 32 bits

#### MFLO - Move From LO
```assembly
MFLO R1           # R1 = LO
```
- **Função**: Acessa parte baixa do resultado
- **Uso**: Após MULT/DIV
- **Tamanho**: 32 bits

#### NOP - No Operation
```assembly
NOP               # Não faz nada
```
- **Função**: Ciclo vazio
- **Uso**: Alinhamento, delays
- **Implementação**: ADD R0, R0, R0

## 🎯 Registradores Especiais

| Registrador | Nome | Função |
|-------------|------|---------|
| R0 | ZERO | Sempre zero |
| R29 | SP | Stack Pointer |
| R31 | RA | Return Address |
| HI | HI | Resultado alto MULT/DIV |
| LO | LO | Resultado baixo MULT/DIV |

## 📝 Convenções de Uso

### Convenção de Chamada
```assembly
# Preparar parâmetros
SW R_param1, 0(R29)
SW R_param2, 1(R29)
SW R31, 2(R29)

# Chamar função
JAL function

# Restaurar RA
LW R31, 2(R29)

# Usar resultado (em R1)
MOVE R_result, R1
```

### Uso de Pilha
- **SP (R29)**: Aponta para próxima posição livre
- **Crescimento**: Para baixo (endereços menores)
- **Frame**: Parâmetros + RA + variáveis locais

### Padrões Comuns
```assembly
# Loop
loop:
    # corpo do loop
    SUBI R1, R1, 1
    BNE R1, R0, loop

# Condicionais
    BEQ R1, R2, else
    # código if
    J endif
else:
    # código else
endif:
```

Este conjunto de instruções fornece funcionalidade completa para implementação de algoritmos e programas em assembly MIPS customizado.
