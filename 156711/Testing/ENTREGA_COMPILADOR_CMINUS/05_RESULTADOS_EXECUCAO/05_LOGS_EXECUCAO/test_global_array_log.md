# Relatório de Compilação - test_global_array.c
## Data: 2025-09-23 12:21:38
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_global_array.c
Tamanho: 241 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=i
DEBUG: Child - node=0, stmt=2, exp=-1, name=globalarray
DEBUG: Child - node=0, stmt=2, exp=-1, name=globalarray
DEBUG: Child - node=0, stmt=2, exp=-1, name=globalarray
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
(goto,main, , )
(alloc,globalarray,5, )
(fun,main, , )
(alloc,i,1, )
(immed,0, ,t0)
(asn,t0, ,i)
(immed,10, ,t1)
(immed,0, ,t2)
(store,globalarray,t2,t1)
(immed,20, ,t3)
(immed,1, ,t4)
(store,globalarray,t4,t3)
(immed,30, ,t5)
(immed,2, ,t6)
(store,globalarray,t6,t5)
(immed,0, ,t7)
(load,globalarray,t7,t8)
(output,t8,0, )
(immed,1, ,t9)
(load,globalarray,t9,t10)
(output,t10,0, )
(immed,2, ,t11)
(load,globalarray,t11,t12)
(output,t12,0, )
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
Quadruplas lidas: 25
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=152
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'main' detectada com 1 parâmetros totais
ADD_INSTRUCTION[4]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[5]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[6]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[7]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[7]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro i na função main (param #1 de 1)
DEBUG: Parâmetro i registrado com offset 0 na função main
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
ADD_INSTRUCTION[11]: LI (op=27) rs=R0 rt=R3 rd=R0 imm=10
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 't2' -> R4
ADD_INSTRUCTION[12]: LI (op=27) rs=R0 rt=R4 rd=R0 imm=0

>>> PROCESSING QUAD: STORE t1 -> globalarray[t2]

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't2', Result: 't1', STORE
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t2', 'main')
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Variável 't2' já em R4 (reutilizando)
DEBUG: Variável 't2' -> R4 (símbolo NÃO encontrado!)
Index register: R4 (loaded from 't2')
DEBUG: get_register_for_variable('temp_reg_0', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 'temp_reg_0' -> R5
DEBUG: get_register_for_variable('addr_reg_0', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 'addr_reg_0' -> R6
Temp register: R5 (temp_reg_0), Address register: R6 (addr_reg_0)
Generating: SLL R5, R4, 2 (index * 4)
ADD_INSTRUCTION[13]: SLL (op=6) rs=R4 rt=R0 rd=R5 imm=2
Global array: GP=28, offset=0
Generating: ADDI R6, GP, 0 (base address)
ADD_INSTRUCTION[14]: ADDI (op=15) rs=R28 rt=R6 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R6, R28, 0'
Generating: ADD R6, R6, R5 (final address)
ADD_INSTRUCTION[15]: ADD (op=0) rs=R6 rt=R5 rd=R6 imm=0
  ADD PREVIEW: Will output 'ADD R6, R6, R5'
DEBUG: load_variable_to_register('t1', 'main')
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
STORE: Value register R3 (from 't1')
Generating: SW R3, 0(R6) (store value at address)
ADD_INSTRUCTION[16]: SW (op=26) rs=R6 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R6)'
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't3' -> R7
ADD_INSTRUCTION[17]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=20
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't4' -> R8
ADD_INSTRUCTION[18]: LI (op=27) rs=R0 rt=R8 rd=R0 imm=1

>>> PROCESSING QUAD: STORE t3 -> globalarray[t4]

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't4', Result: 't3', STORE
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R8 (reutilizando)
DEBUG: Variável 't4' -> R8 (símbolo NÃO encontrado!)
Index register: R8 (loaded from 't4')
DEBUG: get_register_for_variable('temp_reg_1', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 'temp_reg_1' -> R9
DEBUG: get_register_for_variable('addr_reg_1', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 'addr_reg_1' -> R10
Temp register: R9 (temp_reg_1), Address register: R10 (addr_reg_1)
Generating: SLL R9, R8, 2 (index * 4)
ADD_INSTRUCTION[19]: SLL (op=6) rs=R8 rt=R0 rd=R9 imm=2
Global array: GP=28, offset=0
Generating: ADDI R10, GP, 0 (base address)
ADD_INSTRUCTION[20]: ADDI (op=15) rs=R28 rt=R10 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R10, R28, 0'
Generating: ADD R10, R10, R9 (final address)
ADD_INSTRUCTION[21]: ADD (op=0) rs=R10 rt=R9 rd=R10 imm=0
  ADD PREVIEW: Will output 'ADD R10, R10, R9'
DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R7 (reutilizando)
DEBUG: Variável 't3' -> R7 (símbolo NÃO encontrado!)
STORE: Value register R7 (from 't3')
Generating: SW R7, 0(R10) (store value at address)
ADD_INSTRUCTION[22]: SW (op=26) rs=R10 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R10)'
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't5' -> R11
ADD_INSTRUCTION[23]: LI (op=27) rs=R0 rt=R11 rd=R0 imm=30
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't6' -> R12
ADD_INSTRUCTION[24]: LI (op=27) rs=R0 rt=R12 rd=R0 imm=2

>>> PROCESSING QUAD: STORE t5 -> globalarray[t6]

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't6', Result: 't5', STORE
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R12 (reutilizando)
DEBUG: Variável 't6' -> R12 (símbolo NÃO encontrado!)
Index register: R12 (loaded from 't6')
DEBUG: get_register_for_variable('temp_reg_2', 'main')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 'temp_reg_2' -> R13
DEBUG: get_register_for_variable('addr_reg_2', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 'addr_reg_2' -> R14
Temp register: R13 (temp_reg_2), Address register: R14 (addr_reg_2)
Generating: SLL R13, R12, 2 (index * 4)
ADD_INSTRUCTION[25]: SLL (op=6) rs=R12 rt=R0 rd=R13 imm=2
Global array: GP=28, offset=0
Generating: ADDI R14, GP, 0 (base address)
ADD_INSTRUCTION[26]: ADDI (op=15) rs=R28 rt=R14 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R14, R28, 0'
Generating: ADD R14, R14, R13 (final address)
ADD_INSTRUCTION[27]: ADD (op=0) rs=R14 rt=R13 rd=R14 imm=0
  ADD PREVIEW: Will output 'ADD R14, R14, R13'
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R11 (reutilizando)
DEBUG: Variável 't5' -> R11 (símbolo NÃO encontrado!)
STORE: Value register R11 (from 't5')
Generating: SW R11, 0(R14) (store value at address)
ADD_INSTRUCTION[28]: SW (op=26) rs=R14 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R11, 0(R14)'
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't7' -> R15
ADD_INSTRUCTION[29]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=0

>>> PROCESSING QUAD: LOAD globalarray[t7] -> t8

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't7', Result: 't8', LOAD
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R15 (reutilizando)
DEBUG: Variável 't7' -> R15 (símbolo NÃO encontrado!)
Index register: R15 (loaded from 't7')
DEBUG: get_register_for_variable('temp_reg_3', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 'temp_reg_3' -> R16
DEBUG: get_register_for_variable('addr_reg_3', 'main')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 'addr_reg_3' -> R17
Temp register: R16 (temp_reg_3), Address register: R17 (addr_reg_3)
Generating: SLL R16, R15, 2 (index * 4)
ADD_INSTRUCTION[30]: SLL (op=6) rs=R15 rt=R0 rd=R16 imm=2
Global array: GP=28, offset=0
Generating: ADDI R17, GP, 0 (base address)
ADD_INSTRUCTION[31]: ADDI (op=15) rs=R28 rt=R17 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R17, R28, 0'
Generating: ADD R17, R17, R16 (final address)
ADD_INSTRUCTION[32]: ADD (op=0) rs=R17 rt=R16 rd=R17 imm=0
  ADD PREVIEW: Will output 'ADD R17, R17, R16'
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 't8' -> R18
LOAD: Dest register R18 (to 't8')
Generating: LW R18, 0(R17) (load value from address)
ADD_INSTRUCTION[33]: LW (op=25) rs=R17 rt=R18 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R18, 0(R17)'
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R18 (reutilizando)
DEBUG: Variável 't8' -> R18 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[34]: OUTPUTREG (op=32) rs=R18 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 't9' -> R19
ADD_INSTRUCTION[35]: LI (op=27) rs=R0 rt=R19 rd=R0 imm=1

>>> PROCESSING QUAD: LOAD globalarray[t9] -> t10

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't9', Result: 't10', LOAD
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R19 (reutilizando)
DEBUG: Variável 't9' -> R19 (símbolo NÃO encontrado!)
Index register: R19 (loaded from 't9')
DEBUG: get_register_for_variable('temp_reg_4', 'main')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 'temp_reg_4' -> R20
DEBUG: get_register_for_variable('addr_reg_4', 'main')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 'addr_reg_4' -> R21
Temp register: R20 (temp_reg_4), Address register: R21 (addr_reg_4)
Generating: SLL R20, R19, 2 (index * 4)
ADD_INSTRUCTION[36]: SLL (op=6) rs=R19 rt=R0 rd=R20 imm=2
Global array: GP=28, offset=0
Generating: ADDI R21, GP, 0 (base address)
ADD_INSTRUCTION[37]: ADDI (op=15) rs=R28 rt=R21 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R21, R28, 0'
Generating: ADD R21, R21, R20 (final address)
ADD_INSTRUCTION[38]: ADD (op=0) rs=R21 rt=R20 rd=R21 imm=0
  ADD PREVIEW: Will output 'ADD R21, R21, R20'
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 't10' -> R22
LOAD: Dest register R22 (to 't10')
Generating: LW R22, 0(R21) (load value from address)
ADD_INSTRUCTION[39]: LW (op=25) rs=R21 rt=R22 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R22, 0(R21)'
DEBUG: load_variable_to_register('t10', 'main')
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Variável 't10' já em R22 (reutilizando)
DEBUG: Variável 't10' -> R22 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[40]: OUTPUTREG (op=32) rs=R22 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Registrador livre encontrado: R23
DEBUG: Alocando 't11' -> R23
ADD_INSTRUCTION[41]: LI (op=27) rs=R0 rt=R23 rd=R0 imm=2

>>> PROCESSING QUAD: LOAD globalarray[t11] -> t12

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't11', Result: 't12', LOAD
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t11', 'main')
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Variável 't11' já em R23 (reutilizando)
DEBUG: Variável 't11' -> R23 (símbolo NÃO encontrado!)
Index register: R23 (loaded from 't11')
DEBUG: get_register_for_variable('temp_reg_5', 'main')
DEBUG: Registrador livre encontrado: R24
DEBUG: Alocando 'temp_reg_5' -> R24
DEBUG: get_register_for_variable('addr_reg_5', 'main')
DEBUG: Registrador livre encontrado: R25
DEBUG: Alocando 'addr_reg_5' -> R25
Temp register: R24 (temp_reg_5), Address register: R25 (addr_reg_5)
Generating: SLL R24, R23, 2 (index * 4)
ADD_INSTRUCTION[42]: SLL (op=6) rs=R23 rt=R0 rd=R24 imm=2
Global array: GP=28, offset=0
Generating: ADDI R25, GP, 0 (base address)
ADD_INSTRUCTION[43]: ADDI (op=15) rs=R28 rt=R25 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R25, R28, 0'
Generating: ADD R25, R25, R24 (final address)
ADD_INSTRUCTION[44]: ADD (op=0) rs=R25 rt=R24 rd=R25 imm=0
  ADD PREVIEW: Will output 'ADD R25, R25, R24'
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Registrador livre encontrado: R26
DEBUG: Alocando 't12' -> R26
LOAD: Dest register R26 (to 't12')
Generating: LW R26, 0(R25) (load value from address)
ADD_INSTRUCTION[45]: LW (op=25) rs=R25 rt=R26 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R26, 0(R25)'
DEBUG: load_variable_to_register('t12', 'main')
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Variável 't12' já em R26 (reutilizando)
DEBUG: Variável 't12' -> R26 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[46]: OUTPUTREG (op=32) rs=R26 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[47]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 25
Instruções geradas: 48
Labels: 1
Símbolos: 2
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
globalarray                     0       Sim     Não    Sim     5      
i               main            0       Não    Sim     Não    1      
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
