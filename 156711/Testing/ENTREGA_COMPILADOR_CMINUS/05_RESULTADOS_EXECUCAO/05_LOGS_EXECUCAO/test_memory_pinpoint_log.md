# Relatório de Compilação - test_memory_pinpoint.c
## Data: 2025-09-23 12:21:39
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_memory_pinpoint.c
Tamanho: 213 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=2, exp=-1, name=data
DEBUG: Child - node=0, stmt=2, exp=-1, name=data
DEBUG: Child - node=0, stmt=2, exp=-1, name=data
DEBUG: Child - node=0, stmt=2, exp=-1, name=data
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=2, exp=-1, name=data
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
(goto,main, , )
(alloc,data,4, )
(fun,main, , )
(immed,100, ,t0)
(immed,0, ,t1)
(store,data,t1,t0)
(immed,200, ,t2)
(immed,1, ,t3)
(store,data,t3,t2)
(immed,300, ,t4)
(immed,2, ,t5)
(store,data,t5,t4)
(immed,400, ,t6)
(immed,3, ,t7)
(store,data,t7,t6)
(immed,2, ,t8)
(load,data,t8,t9)
(output,t9,0, )
(immed,0, ,t10)
(load,data,t10,t11)
(immed,2, ,t12)
(load,data,t12,t13)
(+,t11,t13,t14)
(immed,1, ,t15)
(store,data,t15,t14)
(immed,2, ,t16)
(load,data,t16,t17)
(output,t17,0, )
(endfun, , , )
Intermediate code written to intermediate.txt

```

### ⚙️ Assembly MIPS
```
Assembler Corrigido para Processador MIPS Customizado
Implementa todas as correções identificadas nos problemas:
- Gerenciamento de pilha com Frame Pointer
- Suporte a arrays com cálculo de endereços
- Inicialização de variáveis globais
- Passagem robusta de parâmetros
=====================================================
Lendo arquivo: intermediate.txt
Quadruplas lidas: 29
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=144
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'main' detectada com 0 parâmetros totais
ADD_INSTRUCTION[4]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[5]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[6]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[7]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[7]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[8]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=100
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 't1' -> R2
ADD_INSTRUCTION[9]: LI (op=27) rs=R0 rt=R2 rd=R0 imm=0

>>> PROCESSING QUAD: STORE t0 -> data[t1]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't1', Result: 't0', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t1', 'main')
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Variável 't1' já em R2 (reutilizando)
DEBUG: Variável 't1' -> R2 (símbolo NÃO encontrado!)
Index register: R2 (loaded from 't1')
DEBUG: get_register_for_variable('temp_reg_0', 'main')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 'temp_reg_0' -> R3
DEBUG: get_register_for_variable('addr_reg_0', 'main')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 'addr_reg_0' -> R4
Temp register: R3 (temp_reg_0), Address register: R4 (addr_reg_0)
Generating: SLL R3, R2, 2 (index * 4)
ADD_INSTRUCTION[10]: SLL (op=6) rs=R2 rt=R0 rd=R3 imm=2
Global array: GP=28, offset=0
Generating: ADDI R4, GP, 0 (base address)
ADD_INSTRUCTION[11]: ADDI (op=15) rs=R28 rt=R4 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R4, R28, 0'
Generating: ADD R4, R4, R3 (final address)
ADD_INSTRUCTION[12]: ADD (op=0) rs=R4 rt=R3 rd=R4 imm=0
  ADD PREVIEW: Will output 'ADD R4, R4, R3'
DEBUG: load_variable_to_register('t0', 'main')
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
STORE: Value register R1 (from 't0')
Generating: SW R1, 0(R4) (store value at address)
ADD_INSTRUCTION[13]: SW (op=26) rs=R4 rt=R1 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R1, 0(R4)'
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't2' -> R5
ADD_INSTRUCTION[14]: LI (op=27) rs=R0 rt=R5 rd=R0 imm=200
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't3' -> R6
ADD_INSTRUCTION[15]: LI (op=27) rs=R0 rt=R6 rd=R0 imm=1

>>> PROCESSING QUAD: STORE t2 -> data[t3]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't3', Result: 't2', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R6 (reutilizando)
DEBUG: Variável 't3' -> R6 (símbolo NÃO encontrado!)
Index register: R6 (loaded from 't3')
DEBUG: get_register_for_variable('temp_reg_1', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 'temp_reg_1' -> R7
DEBUG: get_register_for_variable('addr_reg_1', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 'addr_reg_1' -> R8
Temp register: R7 (temp_reg_1), Address register: R8 (addr_reg_1)
Generating: SLL R7, R6, 2 (index * 4)
ADD_INSTRUCTION[16]: SLL (op=6) rs=R6 rt=R0 rd=R7 imm=2
Global array: GP=28, offset=0
Generating: ADDI R8, GP, 0 (base address)
ADD_INSTRUCTION[17]: ADDI (op=15) rs=R28 rt=R8 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R8, R28, 0'
Generating: ADD R8, R8, R7 (final address)
ADD_INSTRUCTION[18]: ADD (op=0) rs=R8 rt=R7 rd=R8 imm=0
  ADD PREVIEW: Will output 'ADD R8, R8, R7'
DEBUG: load_variable_to_register('t2', 'main')
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Variável 't2' já em R5 (reutilizando)
DEBUG: Variável 't2' -> R5 (símbolo NÃO encontrado!)
STORE: Value register R5 (from 't2')
Generating: SW R5, 0(R8) (store value at address)
ADD_INSTRUCTION[19]: SW (op=26) rs=R8 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R8)'
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't4' -> R9
ADD_INSTRUCTION[20]: LI (op=27) rs=R0 rt=R9 rd=R0 imm=300
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't5' -> R10
ADD_INSTRUCTION[21]: LI (op=27) rs=R0 rt=R10 rd=R0 imm=2

>>> PROCESSING QUAD: STORE t4 -> data[t5]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't5', Result: 't4', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R10 (reutilizando)
DEBUG: Variável 't5' -> R10 (símbolo NÃO encontrado!)
Index register: R10 (loaded from 't5')
DEBUG: get_register_for_variable('temp_reg_2', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 'temp_reg_2' -> R11
DEBUG: get_register_for_variable('addr_reg_2', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 'addr_reg_2' -> R12
Temp register: R11 (temp_reg_2), Address register: R12 (addr_reg_2)
Generating: SLL R11, R10, 2 (index * 4)
ADD_INSTRUCTION[22]: SLL (op=6) rs=R10 rt=R0 rd=R11 imm=2
Global array: GP=28, offset=0
Generating: ADDI R12, GP, 0 (base address)
ADD_INSTRUCTION[23]: ADDI (op=15) rs=R28 rt=R12 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R12, R28, 0'
Generating: ADD R12, R12, R11 (final address)
ADD_INSTRUCTION[24]: ADD (op=0) rs=R12 rt=R11 rd=R12 imm=0
  ADD PREVIEW: Will output 'ADD R12, R12, R11'
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R9 (reutilizando)
DEBUG: Variável 't4' -> R9 (símbolo NÃO encontrado!)
STORE: Value register R9 (from 't4')
Generating: SW R9, 0(R12) (store value at address)
ADD_INSTRUCTION[25]: SW (op=26) rs=R12 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R12)'
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 't6' -> R13
ADD_INSTRUCTION[26]: LI (op=27) rs=R0 rt=R13 rd=R0 imm=400
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 't7' -> R14
ADD_INSTRUCTION[27]: LI (op=27) rs=R0 rt=R14 rd=R0 imm=3

>>> PROCESSING QUAD: STORE t6 -> data[t7]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't7', Result: 't6', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R14 (reutilizando)
DEBUG: Variável 't7' -> R14 (símbolo NÃO encontrado!)
Index register: R14 (loaded from 't7')
DEBUG: get_register_for_variable('temp_reg_3', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 'temp_reg_3' -> R15
DEBUG: get_register_for_variable('addr_reg_3', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 'addr_reg_3' -> R16
Temp register: R15 (temp_reg_3), Address register: R16 (addr_reg_3)
Generating: SLL R15, R14, 2 (index * 4)
ADD_INSTRUCTION[28]: SLL (op=6) rs=R14 rt=R0 rd=R15 imm=2
Global array: GP=28, offset=0
Generating: ADDI R16, GP, 0 (base address)
ADD_INSTRUCTION[29]: ADDI (op=15) rs=R28 rt=R16 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R16, R28, 0'
Generating: ADD R16, R16, R15 (final address)
ADD_INSTRUCTION[30]: ADD (op=0) rs=R16 rt=R15 rd=R16 imm=0
  ADD PREVIEW: Will output 'ADD R16, R16, R15'
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R13 (reutilizando)
DEBUG: Variável 't6' -> R13 (símbolo NÃO encontrado!)
STORE: Value register R13 (from 't6')
Generating: SW R13, 0(R16) (store value at address)
ADD_INSTRUCTION[31]: SW (op=26) rs=R16 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R13, 0(R16)'
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 't8' -> R17
ADD_INSTRUCTION[32]: LI (op=27) rs=R0 rt=R17 rd=R0 imm=2

>>> PROCESSING QUAD: LOAD data[t8] -> t9

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't8', Result: 't9', LOAD
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R17 (reutilizando)
DEBUG: Variável 't8' -> R17 (símbolo NÃO encontrado!)
Index register: R17 (loaded from 't8')
DEBUG: get_register_for_variable('temp_reg_4', 'main')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 'temp_reg_4' -> R18
DEBUG: get_register_for_variable('addr_reg_4', 'main')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 'addr_reg_4' -> R19
Temp register: R18 (temp_reg_4), Address register: R19 (addr_reg_4)
Generating: SLL R18, R17, 2 (index * 4)
ADD_INSTRUCTION[33]: SLL (op=6) rs=R17 rt=R0 rd=R18 imm=2
Global array: GP=28, offset=0
Generating: ADDI R19, GP, 0 (base address)
ADD_INSTRUCTION[34]: ADDI (op=15) rs=R28 rt=R19 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R19, R28, 0'
Generating: ADD R19, R19, R18 (final address)
ADD_INSTRUCTION[35]: ADD (op=0) rs=R19 rt=R18 rd=R19 imm=0
  ADD PREVIEW: Will output 'ADD R19, R19, R18'
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 't9' -> R20
LOAD: Dest register R20 (to 't9')
Generating: LW R20, 0(R19) (load value from address)
ADD_INSTRUCTION[36]: LW (op=25) rs=R19 rt=R20 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R20, 0(R19)'
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R20 (reutilizando)
DEBUG: Variável 't9' -> R20 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[37]: OUTPUTREG (op=32) rs=R20 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 't10' -> R21
ADD_INSTRUCTION[38]: LI (op=27) rs=R0 rt=R21 rd=R0 imm=0

>>> PROCESSING QUAD: LOAD data[t10] -> t11

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't10', Result: 't11', LOAD
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t10', 'main')
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Variável 't10' já em R21 (reutilizando)
DEBUG: Variável 't10' -> R21 (símbolo NÃO encontrado!)
Index register: R21 (loaded from 't10')
DEBUG: get_register_for_variable('temp_reg_5', 'main')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 'temp_reg_5' -> R22
DEBUG: get_register_for_variable('addr_reg_5', 'main')
DEBUG: Registrador livre encontrado: R23
DEBUG: Alocando 'addr_reg_5' -> R23
Temp register: R22 (temp_reg_5), Address register: R23 (addr_reg_5)
Generating: SLL R22, R21, 2 (index * 4)
ADD_INSTRUCTION[39]: SLL (op=6) rs=R21 rt=R0 rd=R22 imm=2
Global array: GP=28, offset=0
Generating: ADDI R23, GP, 0 (base address)
ADD_INSTRUCTION[40]: ADDI (op=15) rs=R28 rt=R23 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R23, R28, 0'
Generating: ADD R23, R23, R22 (final address)
ADD_INSTRUCTION[41]: ADD (op=0) rs=R23 rt=R22 rd=R23 imm=0
  ADD PREVIEW: Will output 'ADD R23, R23, R22'
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Registrador livre encontrado: R24
DEBUG: Alocando 't11' -> R24
LOAD: Dest register R24 (to 't11')
Generating: LW R24, 0(R23) (load value from address)
ADD_INSTRUCTION[42]: LW (op=25) rs=R23 rt=R24 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R24, 0(R23)'
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Registrador livre encontrado: R25
DEBUG: Alocando 't12' -> R25
ADD_INSTRUCTION[43]: LI (op=27) rs=R0 rt=R25 rd=R0 imm=2

>>> PROCESSING QUAD: LOAD data[t12] -> t13

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't12', Result: 't13', LOAD
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t12', 'main')
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Variável 't12' já em R25 (reutilizando)
DEBUG: Variável 't12' -> R25 (símbolo NÃO encontrado!)
Index register: R25 (loaded from 't12')
DEBUG: get_register_for_variable('temp_reg_6', 'main')
DEBUG: Registrador livre encontrado: R26
DEBUG: Alocando 'temp_reg_6' -> R26
DEBUG: get_register_for_variable('addr_reg_6', 'main')
DEBUG: Registrador livre encontrado: R27
DEBUG: Alocando 'addr_reg_6' -> R27
Temp register: R26 (temp_reg_6), Address register: R27 (addr_reg_6)
Generating: SLL R26, R25, 2 (index * 4)
ADD_INSTRUCTION[44]: SLL (op=6) rs=R25 rt=R0 rd=R26 imm=2
Global array: GP=28, offset=0
Generating: ADDI R27, GP, 0 (base address)
ADD_INSTRUCTION[45]: ADDI (op=15) rs=R28 rt=R27 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R27, R28, 0'
Generating: ADD R27, R27, R26 (final address)
ADD_INSTRUCTION[46]: ADD (op=0) rs=R27 rt=R26 rd=R27 imm=0
  ADD PREVIEW: Will output 'ADD R27, R27, R26'
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Liberando R2 (era t1)
DEBUG: Alocando 't13' -> R2
LOAD: Dest register R2 (to 't13')
Generating: LW R2, 0(R27) (load value from address)
ADD_INSTRUCTION[47]: LW (op=25) rs=R27 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R27)'
DEBUG: load_variable_to_register('t11', 'main')
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Variável 't11' já em R24 (reutilizando)
DEBUG: Variável 't11' -> R24 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('t13', 'main')
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Variável 't13' já em R2 (reutilizando)
DEBUG: Variável 't13' -> R2 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Liberando R3 (era temp_reg_0)
DEBUG: Alocando 't14' -> R3
ADD_INSTRUCTION[48]: ADD (op=0) rs=R24 rt=R2 rd=R3 imm=0
  ADD PREVIEW: Will output 'ADD R3, R24, R2'
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Liberando R4 (era addr_reg_0)
DEBUG: Alocando 't15' -> R4
ADD_INSTRUCTION[49]: LI (op=27) rs=R0 rt=R4 rd=R0 imm=1

>>> PROCESSING QUAD: STORE t14 -> data[t15]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't15', Result: 't14', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t15', 'main')
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Variável 't15' já em R4 (reutilizando)
DEBUG: Variável 't15' -> R4 (símbolo NÃO encontrado!)
Index register: R4 (loaded from 't15')
DEBUG: get_register_for_variable('temp_reg_7', 'main')
DEBUG: Liberando R1 (era t0)
DEBUG: Alocando 'temp_reg_7' -> R1
DEBUG: get_register_for_variable('addr_reg_7', 'main')
DEBUG: Liberando R6 (era t3)
DEBUG: Alocando 'addr_reg_7' -> R6
Temp register: R1 (temp_reg_7), Address register: R6 (addr_reg_7)
Generating: SLL R1, R4, 2 (index * 4)
ADD_INSTRUCTION[50]: SLL (op=6) rs=R4 rt=R0 rd=R1 imm=2
Global array: GP=28, offset=0
Generating: ADDI R6, GP, 0 (base address)
ADD_INSTRUCTION[51]: ADDI (op=15) rs=R28 rt=R6 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R6, R28, 0'
Generating: ADD R6, R6, R1 (final address)
ADD_INSTRUCTION[52]: ADD (op=0) rs=R6 rt=R1 rd=R6 imm=0
  ADD PREVIEW: Will output 'ADD R6, R6, R1'
DEBUG: load_variable_to_register('t14', 'main')
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Variável 't14' já em R3 (reutilizando)
DEBUG: Variável 't14' -> R3 (símbolo NÃO encontrado!)
STORE: Value register R3 (from 't14')
Generating: SW R3, 0(R6) (store value at address)
ADD_INSTRUCTION[53]: SW (op=26) rs=R6 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R6)'
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Liberando R7 (era temp_reg_1)
DEBUG: Alocando 't16' -> R7
ADD_INSTRUCTION[54]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=2

>>> PROCESSING QUAD: LOAD data[t16] -> t17

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't16', Result: 't17', LOAD
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t16', 'main')
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Variável 't16' já em R7 (reutilizando)
DEBUG: Variável 't16' -> R7 (símbolo NÃO encontrado!)
Index register: R7 (loaded from 't16')
DEBUG: get_register_for_variable('temp_reg_8', 'main')
DEBUG: Liberando R8 (era addr_reg_1)
DEBUG: Alocando 'temp_reg_8' -> R8
DEBUG: get_register_for_variable('addr_reg_8', 'main')
DEBUG: Liberando R5 (era t2)
DEBUG: Alocando 'addr_reg_8' -> R5
Temp register: R8 (temp_reg_8), Address register: R5 (addr_reg_8)
Generating: SLL R8, R7, 2 (index * 4)
ADD_INSTRUCTION[55]: SLL (op=6) rs=R7 rt=R0 rd=R8 imm=2
Global array: GP=28, offset=0
Generating: ADDI R5, GP, 0 (base address)
ADD_INSTRUCTION[56]: ADDI (op=15) rs=R28 rt=R5 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R5, R28, 0'
Generating: ADD R5, R5, R8 (final address)
ADD_INSTRUCTION[57]: ADD (op=0) rs=R5 rt=R8 rd=R5 imm=0
  ADD PREVIEW: Will output 'ADD R5, R5, R8'
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Liberando R10 (era t5)
DEBUG: Alocando 't17' -> R10
LOAD: Dest register R10 (to 't17')
Generating: LW R10, 0(R5) (load value from address)
ADD_INSTRUCTION[58]: LW (op=25) rs=R5 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R10, 0(R5)'
DEBUG: load_variable_to_register('t17', 'main')
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Variável 't17' já em R10 (reutilizando)
DEBUG: Variável 't17' -> R10 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[59]: OUTPUTREG (op=32) rs=R10 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[60]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 29
Instruções geradas: 61
Labels: 1
Símbolos: 1
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
data                            0       Sim     Não    Sim     4      
====================================

Arquivos gerados:
- assembly_output_corrected.asm
- binary_output_corrected.txt

Assembler corrigido executado com sucesso!

```

### 🚀 Simulação MIPS
```
Simulador MIPS Customizado - Vers�o Gen�rica
============================================================

Configura��o:
Arquivo: d:\Projetinhos\Compilador\156711\Testing\assembly_output_corrected.asm
Entradas: []
Resultado esperado: None
Traceback (most recent call last):
  File "d:\Projetinhos\Compilador\Utils\mips_simulator.py", line 872, in <module>
    main()
  File "d:\Projetinhos\Compilador\Utils\mips_simulator.py", line 785, in main
    simulator = MIPSSimulator(input_values=input_values)
                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "d:\Projetinhos\Compilador\Utils\mips_simulator.py", line 58, in __init__
    print(f"\U0001f527 Simulador MIPS inicializado")
  File "C:\msys64\ucrt64\lib\python3.12\encodings\cp1252.py", line 19, in encode
    return codecs.charmap_encode(input,self.errors,encoding_table)[0]
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
UnicodeEncodeError: 'charmap' codec can't encode character '\U0001f527' in position 0: character maps to <undefined>

```

### 📤 Resultados da Execução
Saídas geradas: []
Número de outputs: 0

### 📊 Resumo
- Compilação: ✅ OK
- Assembly: ✅ OK
- Simulação: ❌ ERRO
