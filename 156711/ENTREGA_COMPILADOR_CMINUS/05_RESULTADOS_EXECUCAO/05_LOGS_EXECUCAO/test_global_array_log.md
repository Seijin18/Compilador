# Relatório de Compilação - test_global_array.c
## Data: 2025-10-04 00:55:58
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_global_array.c
Tamanho: 241 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
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
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
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
DEBUG: get_register_for_variable('addr_reg_0', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 'addr_reg_0' -> R5
Address register: R5 (addr_reg_0)
Global array: GP=28, offset=0
Generating: ADDI R5, GP, 0 (base address)
ADD_INSTRUCTION[13]: ADDI (op=15) rs=R28 rt=R5 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R5, R28, 0'
Generating: ADD R5, R5, R4 (final address = base + index)
ADD_INSTRUCTION[14]: ADD (op=0) rs=R5 rt=R4 rd=R5 imm=0
  ADD PREVIEW: Will output 'ADD R5, R5, R4'
DEBUG: load_variable_to_register('t1', 'main')
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
STORE: Value register R3 (from 't1')
Generating: SW R3, 0(R5) (store value at address)
ADD_INSTRUCTION[15]: SW (op=26) rs=R5 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R5)'
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't3' -> R6
ADD_INSTRUCTION[16]: LI (op=27) rs=R0 rt=R6 rd=R0 imm=20
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't4' -> R7
ADD_INSTRUCTION[17]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=1

>>> PROCESSING QUAD: STORE t3 -> globalarray[t4]

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't4', Result: 't3', STORE
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R7 (reutilizando)
DEBUG: Variável 't4' -> R7 (símbolo NÃO encontrado!)
Index register: R7 (loaded from 't4')
DEBUG: get_register_for_variable('addr_reg_1', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 'addr_reg_1' -> R8
Address register: R8 (addr_reg_1)
Global array: GP=28, offset=0
Generating: ADDI R8, GP, 0 (base address)
ADD_INSTRUCTION[18]: ADDI (op=15) rs=R28 rt=R8 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R8, R28, 0'
Generating: ADD R8, R8, R7 (final address = base + index)
ADD_INSTRUCTION[19]: ADD (op=0) rs=R8 rt=R7 rd=R8 imm=0
  ADD PREVIEW: Will output 'ADD R8, R8, R7'
DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R6 (reutilizando)
DEBUG: Variável 't3' -> R6 (símbolo NÃO encontrado!)
STORE: Value register R6 (from 't3')
Generating: SW R6, 0(R8) (store value at address)
ADD_INSTRUCTION[20]: SW (op=26) rs=R8 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R8)'
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't5' -> R9
ADD_INSTRUCTION[21]: LI (op=27) rs=R0 rt=R9 rd=R0 imm=30
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't6' -> R10
ADD_INSTRUCTION[22]: LI (op=27) rs=R0 rt=R10 rd=R0 imm=2

>>> PROCESSING QUAD: STORE t5 -> globalarray[t6]

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't6', Result: 't5', STORE
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R10 (reutilizando)
DEBUG: Variável 't6' -> R10 (símbolo NÃO encontrado!)
Index register: R10 (loaded from 't6')
DEBUG: get_register_for_variable('addr_reg_2', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 'addr_reg_2' -> R11
Address register: R11 (addr_reg_2)
Global array: GP=28, offset=0
Generating: ADDI R11, GP, 0 (base address)
ADD_INSTRUCTION[23]: ADDI (op=15) rs=R28 rt=R11 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R11, R28, 0'
Generating: ADD R11, R11, R10 (final address = base + index)
ADD_INSTRUCTION[24]: ADD (op=0) rs=R11 rt=R10 rd=R11 imm=0
  ADD PREVIEW: Will output 'ADD R11, R11, R10'
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R9 (reutilizando)
DEBUG: Variável 't5' -> R9 (símbolo NÃO encontrado!)
STORE: Value register R9 (from 't5')
Generating: SW R9, 0(R11) (store value at address)
ADD_INSTRUCTION[25]: SW (op=26) rs=R11 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R11)'
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't7' -> R12
ADD_INSTRUCTION[26]: LI (op=27) rs=R0 rt=R12 rd=R0 imm=0

>>> PROCESSING QUAD: LOAD globalarray[t7] -> t8

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't7', Result: 't8', LOAD
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R12 (reutilizando)
DEBUG: Variável 't7' -> R12 (símbolo NÃO encontrado!)
Index register: R12 (loaded from 't7')
DEBUG: get_register_for_variable('addr_reg_3', 'main')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 'addr_reg_3' -> R13
Address register: R13 (addr_reg_3)
Global array: GP=28, offset=0
Generating: ADDI R13, GP, 0 (base address)
ADD_INSTRUCTION[27]: ADDI (op=15) rs=R28 rt=R13 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R13, R28, 0'
Generating: ADD R13, R13, R12 (final address = base + index)
ADD_INSTRUCTION[28]: ADD (op=0) rs=R13 rt=R12 rd=R13 imm=0
  ADD PREVIEW: Will output 'ADD R13, R13, R12'
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 't8' -> R14
LOAD: Dest register R14 (to 't8')
Generating: LW R14, 0(R13) (load value from address)
ADD_INSTRUCTION[29]: LW (op=25) rs=R13 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R14, 0(R13)'
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R14 (reutilizando)
DEBUG: Variável 't8' -> R14 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[30]: OUTPUTREG (op=32) rs=R14 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't9' -> R15
ADD_INSTRUCTION[31]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=1

>>> PROCESSING QUAD: LOAD globalarray[t9] -> t10

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't9', Result: 't10', LOAD
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R15 (reutilizando)
DEBUG: Variável 't9' -> R15 (símbolo NÃO encontrado!)
Index register: R15 (loaded from 't9')
DEBUG: get_register_for_variable('addr_reg_4', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 'addr_reg_4' -> R16
Address register: R16 (addr_reg_4)
Global array: GP=28, offset=0
Generating: ADDI R16, GP, 0 (base address)
ADD_INSTRUCTION[32]: ADDI (op=15) rs=R28 rt=R16 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R16, R28, 0'
Generating: ADD R16, R16, R15 (final address = base + index)
ADD_INSTRUCTION[33]: ADD (op=0) rs=R16 rt=R15 rd=R16 imm=0
  ADD PREVIEW: Will output 'ADD R16, R16, R15'
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 't10' -> R17
LOAD: Dest register R17 (to 't10')
Generating: LW R17, 0(R16) (load value from address)
ADD_INSTRUCTION[34]: LW (op=25) rs=R16 rt=R17 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R17, 0(R16)'
DEBUG: load_variable_to_register('t10', 'main')
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Variável 't10' já em R17 (reutilizando)
DEBUG: Variável 't10' -> R17 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[35]: OUTPUTREG (op=32) rs=R17 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 't11' -> R18
ADD_INSTRUCTION[36]: LI (op=27) rs=R0 rt=R18 rd=R0 imm=2

>>> PROCESSING QUAD: LOAD globalarray[t11] -> t12

=== DEBUG ARRAY ACCESS ===
Array: 'globalarray', Index: 't11', Result: 't12', LOAD
Symbol found: name='globalarray', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('t11', 'main')
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Variável 't11' já em R18 (reutilizando)
DEBUG: Variável 't11' -> R18 (símbolo NÃO encontrado!)
Index register: R18 (loaded from 't11')
DEBUG: get_register_for_variable('addr_reg_5', 'main')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 'addr_reg_5' -> R19
Address register: R19 (addr_reg_5)
Global array: GP=28, offset=0
Generating: ADDI R19, GP, 0 (base address)
ADD_INSTRUCTION[37]: ADDI (op=15) rs=R28 rt=R19 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R19, R28, 0'
Generating: ADD R19, R19, R18 (final address = base + index)
ADD_INSTRUCTION[38]: ADD (op=0) rs=R19 rt=R18 rd=R19 imm=0
  ADD PREVIEW: Will output 'ADD R19, R19, R18'
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 't12' -> R20
LOAD: Dest register R20 (to 't12')
Generating: LW R20, 0(R19) (load value from address)
ADD_INSTRUCTION[39]: LW (op=25) rs=R19 rt=R20 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R20, 0(R19)'
DEBUG: load_variable_to_register('t12', 'main')
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Variável 't12' já em R20 (reutilizando)
DEBUG: Variável 't12' -> R20 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[40]: OUTPUTREG (op=32) rs=R20 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[41]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 25
Instruções geradas: 42
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
