# Relatório de Compilação - test_loops_arrays.c
## Data: 2025-10-04 00:55:58
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_loops_arrays.c
Tamanho: 468 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
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
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
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
DEBUG: get_register_for_variable('addr_reg_0', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 'addr_reg_0' -> R9
Address register: R9 (addr_reg_0)
Global array: GP=28, offset=0
Generating: ADDI R9, GP, 0 (base address)
ADD_INSTRUCTION[22]: ADDI (op=15) rs=R28 rt=R9 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R9, R28, 0'
Generating: ADD R9, R9, R2 (final address = base + index)
ADD_INSTRUCTION[23]: ADD (op=0) rs=R9 rt=R2 rd=R9 imm=0
  ADD PREVIEW: Will output 'ADD R9, R9, R2'
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R8 (reutilizando)
DEBUG: Variável 't6' -> R8 (símbolo NÃO encontrado!)
STORE: Value register R8 (from 't6')
Generating: SW R8, 0(R9) (store value at address)
ADD_INSTRUCTION[24]: SW (op=26) rs=R9 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R9)'
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't7' -> R10
ADD_INSTRUCTION[25]: LI (op=27) rs=R0 rt=R10 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[26]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R10 (reutilizando)
DEBUG: Variável 't7' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't8' -> R11
ADD_INSTRUCTION[27]: ADD (op=0) rs=R2 rt=R10 rd=R11 imm=0
  ADD PREVIEW: Will output 'ADD R11, R2, R10'
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R11 (reutilizando)
DEBUG: Variável 't8' -> R11 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R11 -> R2)
DEBUG: Gerando MOVE R2, R11
ADD_INSTRUCTION[28]: MOVE (op=11) rs=R11 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[28]: rs=11, rt=0, rd=2 (Armazenado: rs=11, rd=2)
ADD_INSTRUCTION[29]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't9' -> R12
ADD_INSTRUCTION[32]: LI (op=27) rs=R0 rt=R12 rd=R0 imm=0
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R12 (reutilizando)
DEBUG: Variável 't9' -> R12 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R12 -> R2)
DEBUG: Gerando MOVE R2, R12
ADD_INSTRUCTION[33]: MOVE (op=11) rs=R12 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[33]: rs=12, rt=0, rd=2 (Armazenado: rs=12, rd=2)
ADD_INSTRUCTION[34]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 't10' -> R13
ADD_INSTRUCTION[35]: LI (op=27) rs=R0 rt=R13 rd=R0 imm=0
DEBUG: load_variable_to_register('t10', 'main')
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Variável 't10' já em R13 (reutilizando)
DEBUG: Variável 't10' -> R13 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('sum', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 'sum' -> R14
DEBUG: add_move_if_different(R13 -> R14)
DEBUG: Gerando MOVE R14, R13
ADD_INSTRUCTION[36]: MOVE (op=11) rs=R13 rt=R0 rd=R14 imm=0
DEBUG: add_instruction MOVE[36]: rs=13, rt=0, rd=14 (Armazenado: rs=13, rd=14)
ADD_INSTRUCTION[37]: SW (op=26) rs=R30 rt=R14 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R14, 1(R30)'
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't11' -> R15
ADD_INSTRUCTION[39]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[40]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t11', 'main')
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Variável 't11' já em R15 (reutilizando)
DEBUG: Variável 't11' -> R15 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 't12' -> R16
ADD_INSTRUCTION[41]: SLT (op=8) rs=R2 rt=R15 rd=R16 imm=0
DEBUG: load_variable_to_register('t12', 'main')
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Variável 't12' já em R16 (reutilizando)
DEBUG: Variável 't12' -> R16 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD numbers[i] -> t13

=== DEBUG ARRAY ACCESS ===
Array: 'numbers', Index: 'i', Result: 't13', LOAD
Symbol found: name='numbers', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[43]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

Index register: R2 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_1', 'main')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 'addr_reg_1' -> R17
Address register: R17 (addr_reg_1)
Global array: GP=28, offset=0
Generating: ADDI R17, GP, 0 (base address)
ADD_INSTRUCTION[44]: ADDI (op=15) rs=R28 rt=R17 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R17, R28, 0'
Generating: ADD R17, R17, R2 (final address = base + index)
ADD_INSTRUCTION[45]: ADD (op=0) rs=R17 rt=R2 rd=R17 imm=0
  ADD PREVIEW: Will output 'ADD R17, R17, R2'
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 't13' -> R18
LOAD: Dest register R18 (to 't13')
Generating: LW R18, 0(R17) (load value from address)
ADD_INSTRUCTION[46]: LW (op=25) rs=R17 rt=R18 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R18, 0(R17)'
DEBUG: load_variable_to_register('sum', 'main')
DEBUG: get_register_for_variable('sum', 'main')
DEBUG: Variável 'sum' já em R14 (reutilizando)
DEBUG: Variável 'sum' -> R14 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[47]: LW (op=25) rs=R30 rt=R14 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R14, 1(R30)'

DEBUG: load_variable_to_register('t13', 'main')
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Variável 't13' já em R18 (reutilizando)
DEBUG: Variável 't13' -> R18 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 't14' -> R19
ADD_INSTRUCTION[48]: ADD (op=0) rs=R14 rt=R18 rd=R19 imm=0
  ADD PREVIEW: Will output 'ADD R19, R14, R18'
DEBUG: load_variable_to_register('t14', 'main')
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Variável 't14' já em R19 (reutilizando)
DEBUG: Variável 't14' -> R19 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('sum', 'main')
DEBUG: Variável 'sum' já em R14 (reutilizando)
DEBUG: add_move_if_different(R19 -> R14)
DEBUG: Gerando MOVE R14, R19
ADD_INSTRUCTION[49]: MOVE (op=11) rs=R19 rt=R0 rd=R14 imm=0
DEBUG: add_instruction MOVE[49]: rs=19, rt=0, rd=14 (Armazenado: rs=19, rd=14)
ADD_INSTRUCTION[50]: SW (op=26) rs=R30 rt=R14 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R14, 1(R30)'
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 't15' -> R20
ADD_INSTRUCTION[51]: LI (op=27) rs=R0 rt=R20 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[52]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t15', 'main')
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Variável 't15' já em R20 (reutilizando)
DEBUG: Variável 't15' -> R20 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 't16' -> R21
ADD_INSTRUCTION[53]: ADD (op=0) rs=R2 rt=R20 rd=R21 imm=0
  ADD PREVIEW: Will output 'ADD R21, R2, R20'
DEBUG: load_variable_to_register('t16', 'main')
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Variável 't16' já em R21 (reutilizando)
DEBUG: Variável 't16' -> R21 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R21 -> R2)
DEBUG: Gerando MOVE R2, R21
ADD_INSTRUCTION[54]: MOVE (op=11) rs=R21 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[54]: rs=21, rt=0, rd=2 (Armazenado: rs=21, rd=2)
ADD_INSTRUCTION[55]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: load_variable_to_register('sum', 'main')
DEBUG: get_register_for_variable('sum', 'main')
DEBUG: Variável 'sum' já em R14 (reutilizando)
DEBUG: Variável 'sum' -> R14 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[58]: LW (op=25) rs=R30 rt=R14 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R14, 1(R30)'

ADD_INSTRUCTION[59]: OUTPUTREG (op=32) rs=R14 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 't17' -> R22
ADD_INSTRUCTION[60]: LI (op=27) rs=R0 rt=R22 rd=R0 imm=0
DEBUG: load_variable_to_register('t17', 'main')
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Variável 't17' já em R22 (reutilizando)
DEBUG: Variável 't17' -> R22 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R22 -> R2)
DEBUG: Gerando MOVE R2, R22
ADD_INSTRUCTION[61]: MOVE (op=11) rs=R22 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[61]: rs=22, rt=0, rd=2 (Armazenado: rs=22, rd=2)
ADD_INSTRUCTION[62]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t18', 'main')
DEBUG: Registrador livre encontrado: R23
DEBUG: Alocando 't18' -> R23
ADD_INSTRUCTION[64]: LI (op=27) rs=R0 rt=R23 rd=R0 imm=3
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[65]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t18', 'main')
DEBUG: get_register_for_variable('t18', 'main')
DEBUG: Variável 't18' já em R23 (reutilizando)
DEBUG: Variável 't18' -> R23 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t19', 'main')
DEBUG: Registrador livre encontrado: R24
DEBUG: Alocando 't19' -> R24
ADD_INSTRUCTION[66]: SLT (op=8) rs=R2 rt=R23 rd=R24 imm=0
DEBUG: load_variable_to_register('t19', 'main')
DEBUG: get_register_for_variable('t19', 'main')
DEBUG: Variável 't19' já em R24 (reutilizando)
DEBUG: Variável 't19' -> R24 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD numbers[i] -> t20

=== DEBUG ARRAY ACCESS ===
Array: 'numbers', Index: 'i', Result: 't20', LOAD
Symbol found: name='numbers', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[68]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

Index register: R2 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_2', 'main')
DEBUG: Registrador livre encontrado: R25
DEBUG: Alocando 'addr_reg_2' -> R25
Address register: R25 (addr_reg_2)
Global array: GP=28, offset=0
Generating: ADDI R25, GP, 0 (base address)
ADD_INSTRUCTION[69]: ADDI (op=15) rs=R28 rt=R25 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R25, R28, 0'
Generating: ADD R25, R25, R2 (final address = base + index)
ADD_INSTRUCTION[70]: ADD (op=0) rs=R25 rt=R2 rd=R25 imm=0
  ADD PREVIEW: Will output 'ADD R25, R25, R2'
DEBUG: get_register_for_variable('t20', 'main')
DEBUG: Registrador livre encontrado: R26
DEBUG: Alocando 't20' -> R26
LOAD: Dest register R26 (to 't20')
Generating: LW R26, 0(R25) (load value from address)
ADD_INSTRUCTION[71]: LW (op=25) rs=R25 rt=R26 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R26, 0(R25)'
DEBUG: load_variable_to_register('t20', 'main')
DEBUG: get_register_for_variable('t20', 'main')
DEBUG: Variável 't20' já em R26 (reutilizando)
DEBUG: Variável 't20' -> R26 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[72]: OUTPUTREG (op=32) rs=R26 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t21', 'main')
DEBUG: Registrador livre encontrado: R27
DEBUG: Alocando 't21' -> R27
ADD_INSTRUCTION[73]: LI (op=27) rs=R0 rt=R27 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: Variável 'i' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[74]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t21', 'main')
DEBUG: get_register_for_variable('t21', 'main')
DEBUG: Variável 't21' já em R27 (reutilizando)
DEBUG: Variável 't21' -> R27 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t22', 'main')
DEBUG: Liberando R1 (era t0)
DEBUG: Alocando 't22' -> R1
ADD_INSTRUCTION[75]: ADD (op=0) rs=R2 rt=R27 rd=R1 imm=0
  ADD PREVIEW: Will output 'ADD R1, R2, R27'
DEBUG: load_variable_to_register('t22', 'main')
DEBUG: get_register_for_variable('t22', 'main')
DEBUG: Variável 't22' já em R1 (reutilizando)
DEBUG: Variável 't22' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R2 (reutilizando)
DEBUG: add_move_if_different(R1 -> R2)
DEBUG: Gerando MOVE R2, R1
ADD_INSTRUCTION[76]: MOVE (op=11) rs=R1 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[76]: rs=1, rt=0, rd=2 (Armazenado: rs=1, rd=2)
ADD_INSTRUCTION[77]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
ADD_INSTRUCTION[80]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 52
Instruções geradas: 81
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
- assembly_output.asm
- binary_output.txt

Assembler corrigido executado com sucesso!

```

### 🚀 Simulação MIPS
```
Simulador MIPS Customizado - Vers�o Gen�rica
============================================================

Configura��o:
Arquivo: d:\Projetinhos\Compilador\156711\Testing\assembly_output.asm
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
