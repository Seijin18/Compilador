# Relatório de Compilação - test_loops_arrays.c
## Data: 2025-09-16 20:28:08
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_loops_arrays.c
Tamanho: 468 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=i
DEBUG: Child - node=0, stmt=1, exp=-1, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=i
DEBUG: Child - node=0, stmt=2, exp=-1, name=sum
DEBUG: Child - node=0, stmt=1, exp=-1, name=NULL
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=2, exp=-1, name=i
DEBUG: Child - node=0, stmt=1, exp=-1, name=NULL
(goto,main, , )
(alloc,numbers,5, )
(fun,main, , )
(alloc,i,1, )
(alloc,sum,1, )
(immed,0, ,t0)
(asn,t0, ,i)
(label,L0, , )
(immed,5, ,t1)
(<,i,t1,t2)
(if_f,t2,L1, )
(immed,1, ,t3)
(+,i,t3,t4)
(immed,10, ,t5)
(*,t4,t5,t6)
(store,numbers,i,t6)
(immed,1, ,t7)
(+,i,t7,t8)
(asn,t8, ,i)
(goto,L0, , )
(label,L1, , )
(immed,0, ,t9)
(asn,t9, ,i)
(immed,0, ,t10)
(asn,t10, ,sum)
(label,L2, , )
(immed,5, ,t11)
(<,i,t11,t12)
(if_f,t12,L3, )
(load,numbers,i,t13)
(+,sum,t13,t14)
(asn,t14, ,sum)
(immed,1, ,t15)
(+,i,t15,t16)
(asn,t16, ,i)
(goto,L2, , )
(label,L3, , )
(output,sum,0, )
(immed,0, ,t17)
(asn,t17, ,i)
(label,L4, , )
(immed,3, ,t18)
(<,i,t18,t19)
(if_f,t19,L5, )
(load,numbers,i,t20)
(output,t20,0, )
(immed,1, ,t21)
(+,i,t21,t22)
(asn,t22, ,i)
(goto,L4, , )
(label,L5, , )
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
Quadruplas lidas: 52
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=156
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'main' detectada com 2 parâmetros totais
ADD_INSTRUCTION[4]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[5]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[6]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[7]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[7]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro i na função main (param #1 de 2)
DEBUG: Parâmetro i registrado com offset 0 na função main
DEBUG: Detectado parâmetro sum na função main (param #2 de 2)
DEBUG: Parâmetro sum registrado com offset 1 na função main
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[8]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=0
DEBUG: load_variable_to_register('t0', 'main')
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'i' -> R2
DEBUG: add_move_if_different(R1 -> R2)
DEBUG: Gerando MOVE R2, R1
ADD_INSTRUCTION[9]: MOVE (op=11) rs=R1 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[9]: rs=1, rt=0, rd=2 (Armazenado: rs=1, rd=2)
ADD_INSTRUCTION[10]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[12]: LI (op=27) rs=R0 rt=R3 rd=R0 imm=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[13]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t1', 'main')
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 't2' -> R4
ADD_INSTRUCTION[14]: SLT (op=8) rs=R2 rt=R3 rd=R4 imm=0
DEBUG: load_variable_to_register('t2', 'main')
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Variável 't2' já em R4 (reutilizando)
DEBUG: Variável 't2' -> R4 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't3' -> R5
ADD_INSTRUCTION[16]: LI (op=27) rs=R0 rt=R5 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[17]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R5 (reutilizando)
DEBUG: Variável 't3' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't4' -> R6
ADD_INSTRUCTION[18]: ADD (op=0) rs=R2 rt=R5 rd=R6 imm=0
  ADD PREVIEW: Will output 'ADD R6, R2, R5'
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't5' -> R7
ADD_INSTRUCTION[19]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=10
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R6 (reutilizando)
DEBUG: Variável 't4' -> R6 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R7 (reutilizando)
DEBUG: Variável 't5' -> R7 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't6' -> R8
ADD_INSTRUCTION[20]: MULT (op=2) rs=R6 rt=R7 rd=R8 imm=0

>>> PROCESSING QUAD: STORE t6 -> numbers[i]

=== DEBUG ARRAY ACCESS ===
Array: 'numbers', Index: 'i', Result: 't6', STORE
Symbol found: name='numbers', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[21]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

Index register: R2 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_0', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 'temp_reg_0' -> R9
DEBUG: get_register_for_variable('addr_reg_0', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 'addr_reg_0' -> R10
Temp register: R9 (temp_reg_0), Address register: R10 (addr_reg_0)
Generating: SLL R9, R2, 2 (index * 4)
ADD_INSTRUCTION[22]: SLL (op=6) rs=R2 rt=R0 rd=R9 imm=2
Global array: GP=28, offset=0
Generating: ADDI R10, GP, 0 (base address)
ADD_INSTRUCTION[23]: ADDI (op=15) rs=R28 rt=R10 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R10, R28, 0'
Generating: ADD R10, R10, R9 (final address)
ADD_INSTRUCTION[24]: ADD (op=0) rs=R10 rt=R9 rd=R10 imm=0
  ADD PREVIEW: Will output 'ADD R10, R10, R9'
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R8 (reutilizando)
DEBUG: Variável 't6' -> R8 (símbolo NÃO encontrado!)
STORE: Value register R8 (from 't6')
Generating: SW R8, 0(R10) (store value at address)
ADD_INSTRUCTION[25]: SW (op=26) rs=R10 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R10)'
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't7' -> R11
ADD_INSTRUCTION[26]: LI (op=27) rs=R0 rt=R11 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[27]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R11 (reutilizando)
DEBUG: Variável 't7' -> R11 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't8' -> R12
ADD_INSTRUCTION[28]: ADD (op=0) rs=R2 rt=R11 rd=R12 imm=0
  ADD PREVIEW: Will output 'ADD R12, R2, R11'
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R12 (reutilizando)
DEBUG: Variável 't8' -> R12 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R12 -> R2)
DEBUG: Gerando MOVE R2, R12
ADD_INSTRUCTION[29]: MOVE (op=11) rs=R12 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[29]: rs=12, rt=0, rd=2 (Armazenado: rs=12, rd=2)
ADD_INSTRUCTION[30]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 't9' -> R13
ADD_INSTRUCTION[33]: LI (op=27) rs=R0 rt=R13 rd=R0 imm=0
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R13 (reutilizando)
DEBUG: Variável 't9' -> R13 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R13 -> R2)
DEBUG: Gerando MOVE R2, R13
ADD_INSTRUCTION[34]: MOVE (op=11) rs=R13 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[34]: rs=13, rt=0, rd=2 (Armazenado: rs=13, rd=2)
ADD_INSTRUCTION[35]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 't10' -> R14
ADD_INSTRUCTION[36]: LI (op=27) rs=R0 rt=R14 rd=R0 imm=0
DEBUG: load_variable_to_register('t10', 'main')
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Variável 't10' já em R14 (reutilizando)
DEBUG: Variável 't10' -> R14 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('sum', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 'sum' -> R15
DEBUG: add_move_if_different(R14 -> R15)
DEBUG: Gerando MOVE R15, R14
ADD_INSTRUCTION[37]: MOVE (op=11) rs=R14 rt=R0 rd=R15 imm=0
DEBUG: add_instruction MOVE[37]: rs=14, rt=0, rd=15 (Armazenado: rs=14, rd=15)
ADD_INSTRUCTION[38]: SW (op=26) rs=R30 rt=R15 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R15, 1(R30)'
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 't11' -> R16
ADD_INSTRUCTION[40]: LI (op=27) rs=R0 rt=R16 rd=R0 imm=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[41]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t11', 'main')
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Variável 't11' já em R16 (reutilizando)
DEBUG: Variável 't11' -> R16 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 't12' -> R17
ADD_INSTRUCTION[42]: SLT (op=8) rs=R2 rt=R16 rd=R17 imm=0
DEBUG: load_variable_to_register('t12', 'main')
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Variável 't12' já em R17 (reutilizando)
DEBUG: Variável 't12' -> R17 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD numbers[i] -> t13

=== DEBUG ARRAY ACCESS ===
Array: 'numbers', Index: 'i', Result: 't13', LOAD
Symbol found: name='numbers', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[44]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

Index register: R2 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_1', 'main')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 'temp_reg_1' -> R18
DEBUG: get_register_for_variable('addr_reg_1', 'main')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 'addr_reg_1' -> R19
Temp register: R18 (temp_reg_1), Address register: R19 (addr_reg_1)
Generating: SLL R18, R2, 2 (index * 4)
ADD_INSTRUCTION[45]: SLL (op=6) rs=R2 rt=R0 rd=R18 imm=2
Global array: GP=28, offset=0
Generating: ADDI R19, GP, 0 (base address)
ADD_INSTRUCTION[46]: ADDI (op=15) rs=R28 rt=R19 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R19, R28, 0'
Generating: ADD R19, R19, R18 (final address)
ADD_INSTRUCTION[47]: ADD (op=0) rs=R19 rt=R18 rd=R19 imm=0
  ADD PREVIEW: Will output 'ADD R19, R19, R18'
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 't13' -> R20
LOAD: Dest register R20 (to 't13')
Generating: LW R20, 0(R19) (load value from address)
ADD_INSTRUCTION[48]: LW (op=25) rs=R19 rt=R20 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R20, 0(R19)'
DEBUG: load_variable_to_register('sum', 'main')
DEBUG: get_register_for_variable('sum', 'main')
DEBUG: Variável 'sum' já em R15 (reutilizando)
DEBUG: Variável 'sum' -> R15 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[49]: LW (op=25) rs=R30 rt=R15 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R15, 1(R30)'

DEBUG: load_variable_to_register('t13', 'main')
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Variável 't13' já em R20 (reutilizando)
DEBUG: Variável 't13' -> R20 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 't14' -> R21
ADD_INSTRUCTION[50]: ADD (op=0) rs=R15 rt=R20 rd=R21 imm=0
  ADD PREVIEW: Will output 'ADD R21, R15, R20'
DEBUG: load_variable_to_register('t14', 'main')
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Variável 't14' já em R21 (reutilizando)
DEBUG: Variável 't14' -> R21 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('sum', 'main')
DEBUG: Variável 'sum' já em R15 (reutilizando)
DEBUG: add_move_if_different(R21 -> R15)
DEBUG: Gerando MOVE R15, R21
ADD_INSTRUCTION[51]: MOVE (op=11) rs=R21 rt=R0 rd=R15 imm=0
DEBUG: add_instruction MOVE[51]: rs=21, rt=0, rd=15 (Armazenado: rs=21, rd=15)
ADD_INSTRUCTION[52]: SW (op=26) rs=R30 rt=R15 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R15, 1(R30)'
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 't15' -> R22
ADD_INSTRUCTION[53]: LI (op=27) rs=R0 rt=R22 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[54]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t15', 'main')
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Variável 't15' já em R22 (reutilizando)
DEBUG: Variável 't15' -> R22 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Registrador livre encontrado: R23
DEBUG: Alocando 't16' -> R23
ADD_INSTRUCTION[55]: ADD (op=0) rs=R2 rt=R22 rd=R23 imm=0
  ADD PREVIEW: Will output 'ADD R23, R2, R22'
DEBUG: load_variable_to_register('t16', 'main')
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Variável 't16' já em R23 (reutilizando)
DEBUG: Variável 't16' -> R23 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R23 -> R2)
DEBUG: Gerando MOVE R2, R23
ADD_INSTRUCTION[56]: MOVE (op=11) rs=R23 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[56]: rs=23, rt=0, rd=2 (Armazenado: rs=23, rd=2)
ADD_INSTRUCTION[57]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: load_variable_to_register('sum', 'main')
DEBUG: get_register_for_variable('sum', 'main')
DEBUG: Variável 'sum' já em R15 (reutilizando)
DEBUG: Variável 'sum' -> R15 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[60]: LW (op=25) rs=R30 rt=R15 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R15, 1(R30)'

ADD_INSTRUCTION[61]: OUTPUTREG (op=32) rs=R15 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Registrador livre encontrado: R24
DEBUG: Alocando 't17' -> R24
ADD_INSTRUCTION[62]: LI (op=27) rs=R0 rt=R24 rd=R0 imm=0
DEBUG: load_variable_to_register('t17', 'main')
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Variável 't17' já em R24 (reutilizando)
DEBUG: Variável 't17' -> R24 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R24 -> R2)
DEBUG: Gerando MOVE R2, R24
ADD_INSTRUCTION[63]: MOVE (op=11) rs=R24 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[63]: rs=24, rt=0, rd=2 (Armazenado: rs=24, rd=2)
ADD_INSTRUCTION[64]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t18', 'main')
DEBUG: Registrador livre encontrado: R25
DEBUG: Alocando 't18' -> R25
ADD_INSTRUCTION[66]: LI (op=27) rs=R0 rt=R25 rd=R0 imm=3
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[67]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t18', 'main')
DEBUG: get_register_for_variable('t18', 'main')
DEBUG: Variável 't18' já em R25 (reutilizando)
DEBUG: Variável 't18' -> R25 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t19', 'main')
DEBUG: Registrador livre encontrado: R26
DEBUG: Alocando 't19' -> R26
ADD_INSTRUCTION[68]: SLT (op=8) rs=R2 rt=R25 rd=R26 imm=0
DEBUG: load_variable_to_register('t19', 'main')
DEBUG: get_register_for_variable('t19', 'main')
DEBUG: Variável 't19' já em R26 (reutilizando)
DEBUG: Variável 't19' -> R26 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD numbers[i] -> t20

=== DEBUG ARRAY ACCESS ===
Array: 'numbers', Index: 'i', Result: 't20', LOAD
Symbol found: name='numbers', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[70]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

Index register: R2 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_2', 'main')
DEBUG: Registrador livre encontrado: R27
DEBUG: Alocando 'temp_reg_2' -> R27
DEBUG: get_register_for_variable('addr_reg_2', 'main')
DEBUG: Liberando R1 (era t0)
DEBUG: Alocando 'addr_reg_2' -> R1
Temp register: R27 (temp_reg_2), Address register: R1 (addr_reg_2)
Generating: SLL R27, R2, 2 (index * 4)
ADD_INSTRUCTION[71]: SLL (op=6) rs=R2 rt=R0 rd=R27 imm=2
Global array: GP=28, offset=0
Generating: ADDI R1, GP, 0 (base address)
ADD_INSTRUCTION[72]: ADDI (op=15) rs=R28 rt=R1 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R1, R28, 0'
Generating: ADD R1, R1, R27 (final address)
ADD_INSTRUCTION[73]: ADD (op=0) rs=R1 rt=R27 rd=R1 imm=0
  ADD PREVIEW: Will output 'ADD R1, R1, R27'
DEBUG: get_register_for_variable('t20', 'main')
DEBUG: Liberando R3 (era t1)
DEBUG: Alocando 't20' -> R3
LOAD: Dest register R3 (to 't20')
Generating: LW R3, 0(R1) (load value from address)
ADD_INSTRUCTION[74]: LW (op=25) rs=R1 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R1)'
DEBUG: load_variable_to_register('t20', 'main')
DEBUG: get_register_for_variable('t20', 'main')
DEBUG: Variável 't20' já em R3 (reutilizando)
DEBUG: Variável 't20' -> R3 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[75]: OUTPUTREG (op=32) rs=R3 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t21', 'main')
DEBUG: Liberando R4 (era t2)
DEBUG: Alocando 't21' -> R4
ADD_INSTRUCTION[76]: LI (op=27) rs=R0 rt=R4 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[77]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t21', 'main')
DEBUG: get_register_for_variable('t21', 'main')
DEBUG: Variável 't21' já em R4 (reutilizando)
DEBUG: Variável 't21' -> R4 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t22', 'main')
DEBUG: Liberando R5 (era t3)
DEBUG: Alocando 't22' -> R5
ADD_INSTRUCTION[78]: ADD (op=0) rs=R2 rt=R4 rd=R5 imm=0
  ADD PREVIEW: Will output 'ADD R5, R2, R4'
DEBUG: load_variable_to_register('t22', 'main')
DEBUG: get_register_for_variable('t22', 'main')
DEBUG: Variável 't22' já em R5 (reutilizando)
DEBUG: Variável 't22' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R5 -> R2)
DEBUG: Gerando MOVE R2, R5
ADD_INSTRUCTION[79]: MOVE (op=11) rs=R5 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[79]: rs=5, rt=0, rd=2 (Armazenado: rs=5, rd=2)
ADD_INSTRUCTION[80]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
ADD_INSTRUCTION[83]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 52
Instruções geradas: 84
Labels: 7
Símbolos: 3
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
numbers                         0       Sim     Não    Sim     5      
i               main            0       Não    Sim     Não    1      
sum             main            1       Não    Sim     Não    1      
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
  File "d:\Projetinhos\Compilador\Utils\mips_simulator.py", line 870, in <module>
    main()
  File "d:\Projetinhos\Compilador\Utils\mips_simulator.py", line 783, in main
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
