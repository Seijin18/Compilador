# Relatório de Compilação - test_memory_pinpoint.c
## Data: 2025-10-04 00:55:59
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_memory_pinpoint.c
Tamanho: 213 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
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
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
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
DEBUG: get_register_for_variable('addr_reg_0', 'main')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 'addr_reg_0' -> R3
Address register: R3 (addr_reg_0)
Global array: GP=28, offset=0
Generating: ADDI R3, GP, 0 (base address)
ADD_INSTRUCTION[10]: ADDI (op=15) rs=R28 rt=R3 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R3, R28, 0'
Generating: ADD R3, R3, R2 (final address = base + index)
ADD_INSTRUCTION[11]: ADD (op=0) rs=R3 rt=R2 rd=R3 imm=0
  ADD PREVIEW: Will output 'ADD R3, R3, R2'
DEBUG: load_variable_to_register('t0', 'main')
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
STORE: Value register R1 (from 't0')
Generating: SW R1, 0(R3) (store value at address)
ADD_INSTRUCTION[12]: SW (op=26) rs=R3 rt=R1 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R1, 0(R3)'
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 't2' -> R4
ADD_INSTRUCTION[13]: LI (op=27) rs=R0 rt=R4 rd=R0 imm=200
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't3' -> R5
ADD_INSTRUCTION[14]: LI (op=27) rs=R0 rt=R5 rd=R0 imm=1

>>> PROCESSING QUAD: STORE t2 -> data[t3]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't3', Result: 't2', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R5 (reutilizando)
DEBUG: Variável 't3' -> R5 (símbolo NÃO encontrado!)
Index register: R5 (loaded from 't3')
DEBUG: get_register_for_variable('addr_reg_1', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 'addr_reg_1' -> R6
Address register: R6 (addr_reg_1)
Global array: GP=28, offset=0
Generating: ADDI R6, GP, 0 (base address)
ADD_INSTRUCTION[15]: ADDI (op=15) rs=R28 rt=R6 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R6, R28, 0'
Generating: ADD R6, R6, R5 (final address = base + index)
ADD_INSTRUCTION[16]: ADD (op=0) rs=R6 rt=R5 rd=R6 imm=0
  ADD PREVIEW: Will output 'ADD R6, R6, R5'
DEBUG: load_variable_to_register('t2', 'main')
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Variável 't2' já em R4 (reutilizando)
DEBUG: Variável 't2' -> R4 (símbolo NÃO encontrado!)
STORE: Value register R4 (from 't2')
Generating: SW R4, 0(R6) (store value at address)
ADD_INSTRUCTION[17]: SW (op=26) rs=R6 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R6)'
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't4' -> R7
ADD_INSTRUCTION[18]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=300
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't5' -> R8
ADD_INSTRUCTION[19]: LI (op=27) rs=R0 rt=R8 rd=R0 imm=2

>>> PROCESSING QUAD: STORE t4 -> data[t5]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't5', Result: 't4', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R8 (reutilizando)
DEBUG: Variável 't5' -> R8 (símbolo NÃO encontrado!)
Index register: R8 (loaded from 't5')
DEBUG: get_register_for_variable('addr_reg_2', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 'addr_reg_2' -> R9
Address register: R9 (addr_reg_2)
Global array: GP=28, offset=0
Generating: ADDI R9, GP, 0 (base address)
ADD_INSTRUCTION[20]: ADDI (op=15) rs=R28 rt=R9 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R9, R28, 0'
Generating: ADD R9, R9, R8 (final address = base + index)
ADD_INSTRUCTION[21]: ADD (op=0) rs=R9 rt=R8 rd=R9 imm=0
  ADD PREVIEW: Will output 'ADD R9, R9, R8'
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R7 (reutilizando)
DEBUG: Variável 't4' -> R7 (símbolo NÃO encontrado!)
STORE: Value register R7 (from 't4')
Generating: SW R7, 0(R9) (store value at address)
ADD_INSTRUCTION[22]: SW (op=26) rs=R9 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R9)'
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't6' -> R10
ADD_INSTRUCTION[23]: LI (op=27) rs=R0 rt=R10 rd=R0 imm=400
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't7' -> R11
ADD_INSTRUCTION[24]: LI (op=27) rs=R0 rt=R11 rd=R0 imm=3

>>> PROCESSING QUAD: STORE t6 -> data[t7]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't7', Result: 't6', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R11 (reutilizando)
DEBUG: Variável 't7' -> R11 (símbolo NÃO encontrado!)
Index register: R11 (loaded from 't7')
DEBUG: get_register_for_variable('addr_reg_3', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 'addr_reg_3' -> R12
Address register: R12 (addr_reg_3)
Global array: GP=28, offset=0
Generating: ADDI R12, GP, 0 (base address)
ADD_INSTRUCTION[25]: ADDI (op=15) rs=R28 rt=R12 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R12, R28, 0'
Generating: ADD R12, R12, R11 (final address = base + index)
ADD_INSTRUCTION[26]: ADD (op=0) rs=R12 rt=R11 rd=R12 imm=0
  ADD PREVIEW: Will output 'ADD R12, R12, R11'
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R10 (reutilizando)
DEBUG: Variável 't6' -> R10 (símbolo NÃO encontrado!)
STORE: Value register R10 (from 't6')
Generating: SW R10, 0(R12) (store value at address)
ADD_INSTRUCTION[27]: SW (op=26) rs=R12 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R10, 0(R12)'
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 't8' -> R13
ADD_INSTRUCTION[28]: LI (op=27) rs=R0 rt=R13 rd=R0 imm=2

>>> PROCESSING QUAD: LOAD data[t8] -> t9

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't8', Result: 't9', LOAD
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R13 (reutilizando)
DEBUG: Variável 't8' -> R13 (símbolo NÃO encontrado!)
Index register: R13 (loaded from 't8')
DEBUG: get_register_for_variable('addr_reg_4', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 'addr_reg_4' -> R14
Address register: R14 (addr_reg_4)
Global array: GP=28, offset=0
Generating: ADDI R14, GP, 0 (base address)
ADD_INSTRUCTION[29]: ADDI (op=15) rs=R28 rt=R14 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R14, R28, 0'
Generating: ADD R14, R14, R13 (final address = base + index)
ADD_INSTRUCTION[30]: ADD (op=0) rs=R14 rt=R13 rd=R14 imm=0
  ADD PREVIEW: Will output 'ADD R14, R14, R13'
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't9' -> R15
LOAD: Dest register R15 (to 't9')
Generating: LW R15, 0(R14) (load value from address)
ADD_INSTRUCTION[31]: LW (op=25) rs=R14 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R15, 0(R14)'
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R15 (reutilizando)
DEBUG: Variável 't9' -> R15 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[32]: OUTPUTREG (op=32) rs=R15 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 't10' -> R16
ADD_INSTRUCTION[33]: LI (op=27) rs=R0 rt=R16 rd=R0 imm=0

>>> PROCESSING QUAD: LOAD data[t10] -> t11

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't10', Result: 't11', LOAD
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t10', 'main')
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Variável 't10' já em R16 (reutilizando)
DEBUG: Variável 't10' -> R16 (símbolo NÃO encontrado!)
Index register: R16 (loaded from 't10')
DEBUG: get_register_for_variable('addr_reg_5', 'main')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 'addr_reg_5' -> R17
Address register: R17 (addr_reg_5)
Global array: GP=28, offset=0
Generating: ADDI R17, GP, 0 (base address)
ADD_INSTRUCTION[34]: ADDI (op=15) rs=R28 rt=R17 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R17, R28, 0'
Generating: ADD R17, R17, R16 (final address = base + index)
ADD_INSTRUCTION[35]: ADD (op=0) rs=R17 rt=R16 rd=R17 imm=0
  ADD PREVIEW: Will output 'ADD R17, R17, R16'
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 't11' -> R18
LOAD: Dest register R18 (to 't11')
Generating: LW R18, 0(R17) (load value from address)
ADD_INSTRUCTION[36]: LW (op=25) rs=R17 rt=R18 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R18, 0(R17)'
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 't12' -> R19
ADD_INSTRUCTION[37]: LI (op=27) rs=R0 rt=R19 rd=R0 imm=2

>>> PROCESSING QUAD: LOAD data[t12] -> t13

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't12', Result: 't13', LOAD
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t12', 'main')
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Variável 't12' já em R19 (reutilizando)
DEBUG: Variável 't12' -> R19 (símbolo NÃO encontrado!)
Index register: R19 (loaded from 't12')
DEBUG: get_register_for_variable('addr_reg_6', 'main')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 'addr_reg_6' -> R20
Address register: R20 (addr_reg_6)
Global array: GP=28, offset=0
Generating: ADDI R20, GP, 0 (base address)
ADD_INSTRUCTION[38]: ADDI (op=15) rs=R28 rt=R20 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R20, R28, 0'
Generating: ADD R20, R20, R19 (final address = base + index)
ADD_INSTRUCTION[39]: ADD (op=0) rs=R20 rt=R19 rd=R20 imm=0
  ADD PREVIEW: Will output 'ADD R20, R20, R19'
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 't13' -> R21
LOAD: Dest register R21 (to 't13')
Generating: LW R21, 0(R20) (load value from address)
ADD_INSTRUCTION[40]: LW (op=25) rs=R20 rt=R21 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R21, 0(R20)'
DEBUG: load_variable_to_register('t11', 'main')
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Variável 't11' já em R18 (reutilizando)
DEBUG: Variável 't11' -> R18 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('t13', 'main')
DEBUG: get_register_for_variable('t13', 'main')
DEBUG: Variável 't13' já em R21 (reutilizando)
DEBUG: Variável 't13' -> R21 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 't14' -> R22
ADD_INSTRUCTION[41]: ADD (op=0) rs=R18 rt=R21 rd=R22 imm=0
  ADD PREVIEW: Will output 'ADD R22, R18, R21'
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Registrador livre encontrado: R23
DEBUG: Alocando 't15' -> R23
ADD_INSTRUCTION[42]: LI (op=27) rs=R0 rt=R23 rd=R0 imm=1

>>> PROCESSING QUAD: STORE t14 -> data[t15]

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't15', Result: 't14', STORE
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t15', 'main')
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Variável 't15' já em R23 (reutilizando)
DEBUG: Variável 't15' -> R23 (símbolo NÃO encontrado!)
Index register: R23 (loaded from 't15')
DEBUG: get_register_for_variable('addr_reg_7', 'main')
DEBUG: Registrador livre encontrado: R24
DEBUG: Alocando 'addr_reg_7' -> R24
Address register: R24 (addr_reg_7)
Global array: GP=28, offset=0
Generating: ADDI R24, GP, 0 (base address)
ADD_INSTRUCTION[43]: ADDI (op=15) rs=R28 rt=R24 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R24, R28, 0'
Generating: ADD R24, R24, R23 (final address = base + index)
ADD_INSTRUCTION[44]: ADD (op=0) rs=R24 rt=R23 rd=R24 imm=0
  ADD PREVIEW: Will output 'ADD R24, R24, R23'
DEBUG: load_variable_to_register('t14', 'main')
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Variável 't14' já em R22 (reutilizando)
DEBUG: Variável 't14' -> R22 (símbolo NÃO encontrado!)
STORE: Value register R22 (from 't14')
Generating: SW R22, 0(R24) (store value at address)
ADD_INSTRUCTION[45]: SW (op=26) rs=R24 rt=R22 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R22, 0(R24)'
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Registrador livre encontrado: R25
DEBUG: Alocando 't16' -> R25
ADD_INSTRUCTION[46]: LI (op=27) rs=R0 rt=R25 rd=R0 imm=2

>>> PROCESSING QUAD: LOAD data[t16] -> t17

=== DEBUG ARRAY ACCESS ===
Array: 'data', Index: 't16', Result: 't17', LOAD
Symbol found: name='data', offset=0, global=YES, is_array=YES, size=4
DEBUG: load_variable_to_register('t16', 'main')
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Variável 't16' já em R25 (reutilizando)
DEBUG: Variável 't16' -> R25 (símbolo NÃO encontrado!)
Index register: R25 (loaded from 't16')
DEBUG: get_register_for_variable('addr_reg_8', 'main')
DEBUG: Registrador livre encontrado: R26
DEBUG: Alocando 'addr_reg_8' -> R26
Address register: R26 (addr_reg_8)
Global array: GP=28, offset=0
Generating: ADDI R26, GP, 0 (base address)
ADD_INSTRUCTION[47]: ADDI (op=15) rs=R28 rt=R26 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R26, R28, 0'
Generating: ADD R26, R26, R25 (final address = base + index)
ADD_INSTRUCTION[48]: ADD (op=0) rs=R26 rt=R25 rd=R26 imm=0
  ADD PREVIEW: Will output 'ADD R26, R26, R25'
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Registrador livre encontrado: R27
DEBUG: Alocando 't17' -> R27
LOAD: Dest register R27 (to 't17')
Generating: LW R27, 0(R26) (load value from address)
ADD_INSTRUCTION[49]: LW (op=25) rs=R26 rt=R27 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R27, 0(R26)'
DEBUG: load_variable_to_register('t17', 'main')
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Variável 't17' já em R27 (reutilizando)
DEBUG: Variável 't17' -> R27 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[50]: OUTPUTREG (op=32) rs=R27 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[51]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 29
Instruções geradas: 52
Labels: 1
Símbolos: 1
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
data                            0       Sim     Não    Sim     4      
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
