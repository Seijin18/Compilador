# Relatório de Compilação - test_array_param.c
## Data: 2025-10-04 00:55:58
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_array_param.c
Tamanho: 391 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function sumarray children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
(goto,main, , )
(alloc,testarray,3, )
(fun,sumarray, , )
(alloc,arr,10, )
(alloc,size,1, )
(alloc,i,1, )
(alloc,sum,1, )
(immed,0, ,t0)
(asn,t0, ,sum)
(immed,0, ,t1)
(asn,t1, ,i)
(label,L0, , )
(<,i,size,t2)
(if_f,t2,L1, )
(load,arr,i,t3)
(+,sum,t3,t4)
(asn,t4, ,sum)
(immed,1, ,t5)
(+,i,t5,t6)
(asn,t6, ,i)
(goto,L0, , )
(label,L1, , )
(ret,sum, , )
(endfun, , , )
(fun,main, , )
(alloc,result,1, )
(immed,5, ,t7)
(immed,0, ,t8)
(store,testarray,t8,t7)
(immed,10, ,t9)
(immed,1, ,t10)
(store,testarray,t10,t9)
(immed,15, ,t11)
(immed,2, ,t12)
(store,testarray,t12,t11)
(immed,3, ,t13)
(param,testarray, , )
(param,t13, , )
(call,sumarray,testarray,t14)
(asn,t14, ,result)
(output,result,0, )
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
Quadruplas lidas: 42
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'sumarray' detectada com 4 parâmetros totais
DEBUG_RA: === INICIO PROLOGO FUNCAO ===
DEBUG_RA: Decrementando SP em 8 posicoes
ADD_INSTRUCTION[4]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=8
DEBUG_RA: Salvando RA no stack em posição relativa (SP+7)
ADD_INSTRUCTION[5]: SW (op=26) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'SW R31, 7(R29)'
DEBUG_RA: Salvando FP no stack em posição relativa (SP+6)
ADD_INSTRUCTION[6]: SW (op=26) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'SW R30, 6(R29)'
DEBUG_RA: Estabelecendo novo FP (SP+0)
ADD_INSTRUCTION[7]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[7]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG_RA: === FIM PROLOGO FUNCAO ===
DEBUG: Configurando função 'sumarray' - salvando 4 parâmetros de registrador
DEBUG: Salvando 4 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[8]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[9]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Salvando R6->offset 2
ADD_INSTRUCTION[10]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: Salvando R7->offset 3
ADD_INSTRUCTION[11]: SW (op=26) rs=R30 rt=R7 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R7, 3(R30)'
DEBUG: Local offset configurado para 4 (baseado em 4 parâmetros)
DEBUG: Detectado parâmetro arr na função sumarray (param #1 de 4)
DEBUG: Parâmetro arr registrado com offset 0 na função sumarray
DEBUG: Detectado parâmetro size na função sumarray (param #2 de 4)
DEBUG: Parâmetro size registrado com offset 1 na função sumarray
DEBUG: Detectado parâmetro i na função sumarray (param #3 de 4)
DEBUG: Parâmetro i registrado com offset 2 na função sumarray
DEBUG: Detectado parâmetro sum na função sumarray (param #4 de 4)
DEBUG: Parâmetro sum registrado com offset 3 na função sumarray
DEBUG: get_register_for_variable('t0', 'sumarray')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[12]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=0
DEBUG: load_variable_to_register('t0', 'sumarray')
DEBUG: get_register_for_variable('t0', 'sumarray')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('sum', 'sumarray')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'sum' -> R2
DEBUG: add_move_if_different(R1 -> R2)
DEBUG: Gerando MOVE R2, R1
ADD_INSTRUCTION[13]: MOVE (op=11) rs=R1 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[13]: rs=1, rt=0, rd=2 (Armazenado: rs=1, rd=2)
ADD_INSTRUCTION[14]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R2, 3(R30)'
DEBUG: get_register_for_variable('t1', 'sumarray')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[15]: LI (op=27) rs=R0 rt=R3 rd=R0 imm=0
DEBUG: load_variable_to_register('t1', 'sumarray')
DEBUG: get_register_for_variable('t1', 'sumarray')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'sumarray')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 'i' -> R4
DEBUG: add_move_if_different(R3 -> R4)
DEBUG: Gerando MOVE R4, R3
ADD_INSTRUCTION[16]: MOVE (op=11) rs=R3 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[16]: rs=3, rt=0, rd=4 (Armazenado: rs=3, rd=4)
ADD_INSTRUCTION[17]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R4, 2(R30)'
DEBUG: load_variable_to_register('i', 'sumarray')
DEBUG: get_register_for_variable('i', 'sumarray')
DEBUG: Variável 'i' já em R4 (reutilizando)
DEBUG: Variável 'i' -> R4 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[19]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R4, 2(R30)'

DEBUG: load_variable_to_register('size', 'sumarray')
DEBUG: get_register_for_variable('size', 'sumarray')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 'size' -> R5
DEBUG: Variável 'size' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[20]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: get_register_for_variable('t2', 'sumarray')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't2' -> R6
ADD_INSTRUCTION[21]: SLT (op=8) rs=R4 rt=R5 rd=R6 imm=0
DEBUG: load_variable_to_register('t2', 'sumarray')
DEBUG: get_register_for_variable('t2', 'sumarray')
DEBUG: Variável 't2' já em R6 (reutilizando)
DEBUG: Variável 't2' -> R6 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD arr[i] -> t3

=== DEBUG ARRAY ACCESS ===
Array: 'arr', Index: 'i', Result: 't3', LOAD
Symbol found: name='arr', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'sumarray')
DEBUG: get_register_for_variable('i', 'sumarray')
DEBUG: Variável 'i' já em R4 (reutilizando)
DEBUG: Variável 'i' -> R4 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[23]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R4, 2(R30)'

Index register: R4 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_0', 'sumarray')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 'addr_reg_0' -> R7
Address register: R7 (addr_reg_0)
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R7, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[24]: LW (op=25) rs=R30 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R30)'
Generating: ADD R7, R7, R4 (final address = base + index)
ADD_INSTRUCTION[25]: ADD (op=0) rs=R7 rt=R4 rd=R7 imm=0
  ADD PREVIEW: Will output 'ADD R7, R7, R4'
DEBUG: get_register_for_variable('t3', 'sumarray')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't3' -> R8
LOAD: Dest register R8 (to 't3')
Generating: LW R8, 0(R7) (load value from address)
ADD_INSTRUCTION[26]: LW (op=25) rs=R7 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R7)'
DEBUG: load_variable_to_register('sum', 'sumarray')
DEBUG: get_register_for_variable('sum', 'sumarray')
DEBUG: Variável 'sum' já em R2 (reutilizando)
DEBUG: Variável 'sum' -> R2 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[27]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R2, 3(R30)'

DEBUG: load_variable_to_register('t3', 'sumarray')
DEBUG: get_register_for_variable('t3', 'sumarray')
DEBUG: Variável 't3' já em R8 (reutilizando)
DEBUG: Variável 't3' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t4', 'sumarray')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't4' -> R9
ADD_INSTRUCTION[28]: ADD (op=0) rs=R2 rt=R8 rd=R9 imm=0
  ADD PREVIEW: Will output 'ADD R9, R2, R8'
DEBUG: load_variable_to_register('t4', 'sumarray')
DEBUG: get_register_for_variable('t4', 'sumarray')
DEBUG: Variável 't4' já em R9 (reutilizando)
DEBUG: Variável 't4' -> R9 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('sum', 'sumarray')
DEBUG: Variável 'sum' já em R2 (reutilizando)
DEBUG: add_move_if_different(R9 -> R2)
DEBUG: Gerando MOVE R2, R9
ADD_INSTRUCTION[29]: MOVE (op=11) rs=R9 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[29]: rs=9, rt=0, rd=2 (Armazenado: rs=9, rd=2)
ADD_INSTRUCTION[30]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R2, 3(R30)'
DEBUG: get_register_for_variable('t5', 'sumarray')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't5' -> R10
ADD_INSTRUCTION[31]: LI (op=27) rs=R0 rt=R10 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'sumarray')
DEBUG: get_register_for_variable('i', 'sumarray')
DEBUG: Variável 'i' já em R4 (reutilizando)
DEBUG: Variável 'i' -> R4 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[32]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R4, 2(R30)'

DEBUG: load_variable_to_register('t5', 'sumarray')
DEBUG: get_register_for_variable('t5', 'sumarray')
DEBUG: Variável 't5' já em R10 (reutilizando)
DEBUG: Variável 't5' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t6', 'sumarray')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't6' -> R11
ADD_INSTRUCTION[33]: ADD (op=0) rs=R4 rt=R10 rd=R11 imm=0
  ADD PREVIEW: Will output 'ADD R11, R4, R10'
DEBUG: load_variable_to_register('t6', 'sumarray')
DEBUG: get_register_for_variable('t6', 'sumarray')
DEBUG: Variável 't6' já em R11 (reutilizando)
DEBUG: Variável 't6' -> R11 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'sumarray')
DEBUG: Variável 'i' já em R4 (reutilizando)
DEBUG: add_move_if_different(R11 -> R4)
DEBUG: Gerando MOVE R4, R11
ADD_INSTRUCTION[34]: MOVE (op=11) rs=R11 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[34]: rs=11, rt=0, rd=4 (Armazenado: rs=11, rd=4)
ADD_INSTRUCTION[35]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R4, 2(R30)'
DEBUG: load_variable_to_register('sum', 'sumarray')
DEBUG: get_register_for_variable('sum', 'sumarray')
DEBUG: Variável 'sum' já em R2 (reutilizando)
DEBUG: Variável 'sum' -> R2 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[38]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R2, 3(R30)'

DEBUG: add_move_if_different(R2 -> R1)
DEBUG: Gerando MOVE R1, R2
ADD_INSTRUCTION[39]: MOVE (op=11) rs=R2 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[39]: rs=2, rt=0, rd=1 (Armazenado: rs=2, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[42]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[43]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[44]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[45]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 1 parâmetros totais
ADD_INSTRUCTION[47]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[48]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[49]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[50]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[50]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro result na função main (param #1 de 1)
DEBUG: Parâmetro result registrado com offset 0 na função main
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't7' -> R12
ADD_INSTRUCTION[51]: LI (op=27) rs=R0 rt=R12 rd=R0 imm=5
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 't8' -> R13
ADD_INSTRUCTION[52]: LI (op=27) rs=R0 rt=R13 rd=R0 imm=0

>>> PROCESSING QUAD: STORE t7 -> testarray[t8]

=== DEBUG ARRAY ACCESS ===
Array: 'testarray', Index: 't8', Result: 't7', STORE
Symbol found: name='testarray', offset=0, global=YES, is_array=YES, size=3
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R13 (reutilizando)
DEBUG: Variável 't8' -> R13 (símbolo NÃO encontrado!)
Index register: R13 (loaded from 't8')
DEBUG: get_register_for_variable('addr_reg_1', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 'addr_reg_1' -> R14
Address register: R14 (addr_reg_1)
Global array: GP=28, offset=0
Generating: ADDI R14, GP, 0 (base address)
ADD_INSTRUCTION[53]: ADDI (op=15) rs=R28 rt=R14 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R14, R28, 0'
Generating: ADD R14, R14, R13 (final address = base + index)
ADD_INSTRUCTION[54]: ADD (op=0) rs=R14 rt=R13 rd=R14 imm=0
  ADD PREVIEW: Will output 'ADD R14, R14, R13'
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R12 (reutilizando)
DEBUG: Variável 't7' -> R12 (símbolo NÃO encontrado!)
STORE: Value register R12 (from 't7')
Generating: SW R12, 0(R14) (store value at address)
ADD_INSTRUCTION[55]: SW (op=26) rs=R14 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R12, 0(R14)'
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't9' -> R15
ADD_INSTRUCTION[56]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=10
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 't10' -> R16
ADD_INSTRUCTION[57]: LI (op=27) rs=R0 rt=R16 rd=R0 imm=1

>>> PROCESSING QUAD: STORE t9 -> testarray[t10]

=== DEBUG ARRAY ACCESS ===
Array: 'testarray', Index: 't10', Result: 't9', STORE
Symbol found: name='testarray', offset=0, global=YES, is_array=YES, size=3
DEBUG: load_variable_to_register('t10', 'main')
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Variável 't10' já em R16 (reutilizando)
DEBUG: Variável 't10' -> R16 (símbolo NÃO encontrado!)
Index register: R16 (loaded from 't10')
DEBUG: get_register_for_variable('addr_reg_2', 'main')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 'addr_reg_2' -> R17
Address register: R17 (addr_reg_2)
Global array: GP=28, offset=0
Generating: ADDI R17, GP, 0 (base address)
ADD_INSTRUCTION[58]: ADDI (op=15) rs=R28 rt=R17 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R17, R28, 0'
Generating: ADD R17, R17, R16 (final address = base + index)
ADD_INSTRUCTION[59]: ADD (op=0) rs=R17 rt=R16 rd=R17 imm=0
  ADD PREVIEW: Will output 'ADD R17, R17, R16'
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R15 (reutilizando)
DEBUG: Variável 't9' -> R15 (símbolo NÃO encontrado!)
STORE: Value register R15 (from 't9')
Generating: SW R15, 0(R17) (store value at address)
ADD_INSTRUCTION[60]: SW (op=26) rs=R17 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R15, 0(R17)'
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 't11' -> R18
ADD_INSTRUCTION[61]: LI (op=27) rs=R0 rt=R18 rd=R0 imm=15
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 't12' -> R19
ADD_INSTRUCTION[62]: LI (op=27) rs=R0 rt=R19 rd=R0 imm=2

>>> PROCESSING QUAD: STORE t11 -> testarray[t12]

=== DEBUG ARRAY ACCESS ===
Array: 'testarray', Index: 't12', Result: 't11', STORE
Symbol found: name='testarray', offset=0, global=YES, is_array=YES, size=3
DEBUG: load_variable_to_register('t12', 'main')
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Variável 't12' já em R19 (reutilizando)
DEBUG: Variável 't12' -> R19 (símbolo NÃO encontrado!)
Index register: R19 (loaded from 't12')
DEBUG: get_register_for_variable('addr_reg_3', 'main')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 'addr_reg_3' -> R20
Address register: R20 (addr_reg_3)
Global array: GP=28, offset=0
Generating: ADDI R20, GP, 0 (base address)
ADD_INSTRUCTION[63]: ADDI (op=15) rs=R28 rt=R20 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R20, R28, 0'
Generating: ADD R20, R20, R19 (final address = base + index)
ADD_INSTRUCTION[64]: ADD (op=0) rs=R20 rt=R19 rd=R20 imm=0
  ADD PREVIEW: Will output 'ADD R20, R20, R19'
DEBUG: load_variable_to_register('t11', 'main')
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Variável 't11' já em R18 (reutilizando)
DEBUG: Variável 't11' -> R18 (símbolo NÃO encontrado!)
STORE: Value register R18 (from 't11')
Generating: SW R18, 0(R20) (store value at address)
ADD_INSTRUCTION[65]: SW (op=26) rs=R20 rt=R18 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R18, 0(R20)'
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 't13' -> R21
ADD_INSTRUCTION[66]: LI (op=27) rs=R0 rt=R21 rd=R0 imm=3
DEBUG: Passando parâmetro 0: 'testarray'
DEBUG: Parâmetro 0 é array, carregando endereço
DEBUG: load_array_address_to_register('testarray', 'main')
DEBUG: get_register_for_variable('testarray', 'main')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 'testarray' -> R22
DEBUG: Array 'testarray' -> R22 (símbolo encontrado: offset=0, global=1, is_arg=0, is_array=1)ADD_INSTRUCTION[67]: ADDI (op=15) rs=R28 rt=R22 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R22, R28, 0'

DEBUG: Parâmetro 0: 'testarray' de R22 para R4 (forçado)
ADD_INSTRUCTION[68]: MOVE (op=11) rs=R22 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[68]: rs=22, rt=0, rd=4 (Armazenado: rs=22, rd=4)
DEBUG: Passando parâmetro 1: 't13'
DEBUG: load_variable_to_register('t13', 'main')
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Variável 't13' já em R21 (reutilizando)
DEBUG: Variável 't13' -> R21 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 1: 't13' de R21 para R5 (forçado)
ADD_INSTRUCTION[69]: MOVE (op=11) rs=R21 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[69]: rs=21, rt=0, rd=5 (Armazenado: rs=21, rd=5)
DEBUG: Salvando R2 (contém 'sum') antes da chamada
ADD_INSTRUCTION[70]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[71]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 't1') antes da chamada
ADD_INSTRUCTION[72]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[73]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
DEBUG: Salvando R5 (contém 'size') antes da chamada
ADD_INSTRUCTION[74]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[75]: SW (op=26) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R2)'
DEBUG: Salvando R6 (contém 't2') antes da chamada
ADD_INSTRUCTION[76]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[77]: SW (op=26) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R2)'
DEBUG: Salvando R7 (contém 'addr_reg_0') antes da chamada
ADD_INSTRUCTION[78]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[79]: SW (op=26) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R2)'
DEBUG: Salvando R8 (contém 't3') antes da chamada
ADD_INSTRUCTION[80]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[81]: SW (op=26) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R2)'
DEBUG: Salvando R9 (contém 't4') antes da chamada
ADD_INSTRUCTION[82]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[83]: SW (op=26) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R2)'
DEBUG: Salvando R10 (contém 't5') antes da chamada
ADD_INSTRUCTION[84]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[85]: SW (op=26) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R10, 0(R2)'
DEBUG: Salvando R11 (contém 't6') antes da chamada
ADD_INSTRUCTION[86]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=9
ADD_INSTRUCTION[87]: SW (op=26) rs=R2 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R11, 0(R2)'
DEBUG: Salvando R12 (contém 't7') antes da chamada
ADD_INSTRUCTION[88]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=10
ADD_INSTRUCTION[89]: SW (op=26) rs=R2 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R12, 0(R2)'
DEBUG: Salvando R13 (contém 't8') antes da chamada
ADD_INSTRUCTION[90]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=11
ADD_INSTRUCTION[91]: SW (op=26) rs=R2 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R13, 0(R2)'
DEBUG: Salvando R14 (contém 'addr_reg_1') antes da chamada
ADD_INSTRUCTION[92]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=12
ADD_INSTRUCTION[93]: SW (op=26) rs=R2 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R14, 0(R2)'
DEBUG: Salvando R15 (contém 't9') antes da chamada
ADD_INSTRUCTION[94]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=13
ADD_INSTRUCTION[95]: SW (op=26) rs=R2 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R15, 0(R2)'
ADD_INSTRUCTION[96]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=13
ADD_INSTRUCTION[98]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=13
  ADDI PREVIEW: Will output 'ADDI R29, R29, 13'
DEBUG: Restaurando R15 (contém 't9') após a chamada
ADD_INSTRUCTION[99]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=13
ADD_INSTRUCTION[100]: LW (op=25) rs=R2 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R15, 0(R2)'
DEBUG: Restaurando R14 (contém 'addr_reg_1') após a chamada
ADD_INSTRUCTION[101]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=12
ADD_INSTRUCTION[102]: LW (op=25) rs=R2 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R14, 0(R2)'
DEBUG: Restaurando R13 (contém 't8') após a chamada
ADD_INSTRUCTION[103]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=11
ADD_INSTRUCTION[104]: LW (op=25) rs=R2 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R13, 0(R2)'
DEBUG: Restaurando R12 (contém 't7') após a chamada
ADD_INSTRUCTION[105]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=10
ADD_INSTRUCTION[106]: LW (op=25) rs=R2 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R12, 0(R2)'
DEBUG: Restaurando R11 (contém 't6') após a chamada
ADD_INSTRUCTION[107]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=9
ADD_INSTRUCTION[108]: LW (op=25) rs=R2 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R11, 0(R2)'
DEBUG: Restaurando R10 (contém 't5') após a chamada
ADD_INSTRUCTION[109]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[110]: LW (op=25) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R10, 0(R2)'
DEBUG: Restaurando R9 (contém 't4') após a chamada
ADD_INSTRUCTION[111]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[112]: LW (op=25) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R2)'
DEBUG: Restaurando R8 (contém 't3') após a chamada
ADD_INSTRUCTION[113]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[114]: LW (op=25) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R2)'
DEBUG: Restaurando R7 (contém 'addr_reg_0') após a chamada
ADD_INSTRUCTION[115]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[116]: LW (op=25) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R2)'
DEBUG: Restaurando R6 (contém 't2') após a chamada
ADD_INSTRUCTION[117]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[118]: LW (op=25) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R6, 0(R2)'
DEBUG: Restaurando R5 (contém 'size') após a chamada
ADD_INSTRUCTION[119]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[120]: LW (op=25) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R2)'
DEBUG: Restaurando R3 (contém 't1') após a chamada
ADD_INSTRUCTION[121]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[122]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'sum') após a chamada
ADD_INSTRUCTION[123]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[124]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Registrador livre encontrado: R23
DEBUG: Alocando 't14' -> R23
DEBUG: add_move_if_different(R1 -> R23)
DEBUG: Gerando MOVE R23, R1
ADD_INSTRUCTION[125]: MOVE (op=11) rs=R1 rt=R0 rd=R23 imm=0
DEBUG: add_instruction MOVE[125]: rs=1, rt=0, rd=23 (Armazenado: rs=1, rd=23)
ADD_INSTRUCTION[126]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[126]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('t14', 'main')
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Variável 't14' já em R23 (reutilizando)
DEBUG: Variável 't14' -> R23 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('result', 'main')
DEBUG: Registrador livre encontrado: R24
DEBUG: Alocando 'result' -> R24
DEBUG: add_move_if_different(R23 -> R24)
DEBUG: Gerando MOVE R24, R23
ADD_INSTRUCTION[127]: MOVE (op=11) rs=R23 rt=R0 rd=R24 imm=0
DEBUG: add_instruction MOVE[127]: rs=23, rt=0, rd=24 (Armazenado: rs=23, rd=24)
ADD_INSTRUCTION[128]: SW (op=26) rs=R30 rt=R24 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R24, 0(R30)'
DEBUG: load_variable_to_register('result', 'main')
DEBUG: get_register_for_variable('result', 'main')
DEBUG: Variável 'result' já em R24 (reutilizando)
DEBUG: Variável 'result' -> R24 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[129]: LW (op=25) rs=R30 rt=R24 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R24, 0(R30)'

ADD_INSTRUCTION[130]: OUTPUTREG (op=32) rs=R24 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[131]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 42
Instruções geradas: 132
Labels: 5
Símbolos: 6
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
testarray                       0       Sim     Não    Sim     3      
arr             sumarray        0       Não    Sim     Sim     1      
size            sumarray        1       Não    Sim     Não    1      
i               sumarray        2       Não    Sim     Não    1      
sum             sumarray        3       Não    Sim     Não    1      
result          main            0       Não    Sim     Não    1      
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
