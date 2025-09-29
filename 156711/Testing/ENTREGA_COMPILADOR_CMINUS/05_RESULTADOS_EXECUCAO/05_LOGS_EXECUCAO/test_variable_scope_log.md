# Relatório de Compilação - test_variable_scope.c
## Data: 2025-09-23 12:21:39
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_variable_scope.c
Tamanho: 374 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function testscope children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=localvar
DEBUG: Child - node=0, stmt=2, exp=-1, name=globalvar
DEBUG: Child - node=0, stmt=3, exp=-1, name=int
DEBUG: Processing function main children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=globalvar
DEBUG: Child - node=0, stmt=2, exp=-1, name=localmain
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=2, exp=-1, name=globalvar
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
(goto,main, , )
(alloc,globalvar,1, )
(fun,testscope, , )
(alloc,param,1, )
(alloc,localvar,1, )
(immed,5, ,t0)
(+,param,t0,t1)
(asn,t1, ,localvar)
(immed,2, ,t2)
(*,localvar,t2,t3)
(asn,t3, ,globalvar)
(ret,localvar, , )
(endfun, , , )
(fun,main, , )
(alloc,localmain,1, )
(immed,100, ,t4)
(asn,t4, ,globalvar)
(immed,10, ,t5)
(param,t5, , )
(call,testscope,t5,t6)
(asn,t6, ,localmain)
(output,localmain,0, )
(output,globalvar,0, )
(+,globalvar,localmain,t7)
(asn,t7, ,globalvar)
(output,globalvar,0, )
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
Quadruplas lidas: 27
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=144
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'testscope' detectada com 2 parâmetros totais
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
DEBUG: Configurando função 'testscope' - salvando 2 parâmetros de registrador
DEBUG: Salvando 2 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[8]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[9]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Local offset configurado para 2 (baseado em 2 parâmetros)
DEBUG: Detectado parâmetro param na função testscope (param #1 de 2)
DEBUG: Parâmetro param registrado com offset 0 na função testscope
DEBUG: Detectado parâmetro localvar na função testscope (param #2 de 2)
DEBUG: Parâmetro localvar registrado com offset 1 na função testscope
DEBUG: get_register_for_variable('t0', 'testscope')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[10]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=5
DEBUG: load_variable_to_register('param', 'testscope')
DEBUG: get_register_for_variable('param', 'testscope')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'param' -> R2
DEBUG: Variável 'param' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[11]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t0', 'testscope')
DEBUG: get_register_for_variable('t0', 'testscope')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t1', 'testscope')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[12]: ADD (op=0) rs=R2 rt=R1 rd=R3 imm=0
  ADD PREVIEW: Will output 'ADD R3, R2, R1'
DEBUG: load_variable_to_register('t1', 'testscope')
DEBUG: get_register_for_variable('t1', 'testscope')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('localvar', 'testscope')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 'localvar' -> R4
DEBUG: add_move_if_different(R3 -> R4)
DEBUG: Gerando MOVE R4, R3
ADD_INSTRUCTION[13]: MOVE (op=11) rs=R3 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[13]: rs=3, rt=0, rd=4 (Armazenado: rs=3, rd=4)
ADD_INSTRUCTION[14]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R4, 1(R30)'
DEBUG: get_register_for_variable('t2', 'testscope')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't2' -> R5
ADD_INSTRUCTION[15]: LI (op=27) rs=R0 rt=R5 rd=R0 imm=2
DEBUG: load_variable_to_register('localvar', 'testscope')
DEBUG: get_register_for_variable('localvar', 'testscope')
DEBUG: Variável 'localvar' já em R4 (reutilizando)
DEBUG: Variável 'localvar' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[16]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: load_variable_to_register('t2', 'testscope')
DEBUG: get_register_for_variable('t2', 'testscope')
DEBUG: Variável 't2' já em R5 (reutilizando)
DEBUG: Variável 't2' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t3', 'testscope')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't3' -> R6
ADD_INSTRUCTION[17]: MULT (op=2) rs=R4 rt=R5 rd=R6 imm=0
DEBUG: load_variable_to_register('t3', 'testscope')
DEBUG: get_register_for_variable('t3', 'testscope')
DEBUG: Variável 't3' já em R6 (reutilizando)
DEBUG: Variável 't3' -> R6 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('globalvar', 'testscope')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 'globalvar' -> R7
DEBUG: add_move_if_different(R6 -> R7)
DEBUG: Gerando MOVE R7, R6
ADD_INSTRUCTION[18]: MOVE (op=11) rs=R6 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[18]: rs=6, rt=0, rd=7 (Armazenado: rs=6, rd=7)
ADD_INSTRUCTION[19]: SW (op=26) rs=R28 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R28)'
DEBUG: load_variable_to_register('localvar', 'testscope')
DEBUG: get_register_for_variable('localvar', 'testscope')
DEBUG: Variável 'localvar' já em R4 (reutilizando)
DEBUG: Variável 'localvar' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[20]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: add_move_if_different(R4 -> R1)
DEBUG: Gerando MOVE R1, R4
ADD_INSTRUCTION[21]: MOVE (op=11) rs=R4 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[21]: rs=4, rt=0, rd=1 (Armazenado: rs=4, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[24]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[25]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[26]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[27]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 1 parâmetros totais
ADD_INSTRUCTION[29]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[30]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[31]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[32]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[32]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro localmain na função main (param #1 de 1)
DEBUG: Parâmetro localmain registrado com offset 0 na função main
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't4' -> R8
ADD_INSTRUCTION[33]: LI (op=27) rs=R0 rt=R8 rd=R0 imm=100
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R8 (reutilizando)
DEBUG: Variável 't4' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('globalvar', 'main')
DEBUG: Variável 'globalvar' já em R7 (reutilizando)
DEBUG: add_move_if_different(R8 -> R7)
DEBUG: Gerando MOVE R7, R8
ADD_INSTRUCTION[34]: MOVE (op=11) rs=R8 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[34]: rs=8, rt=0, rd=7 (Armazenado: rs=8, rd=7)
ADD_INSTRUCTION[35]: SW (op=26) rs=R28 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R28)'
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't5' -> R9
ADD_INSTRUCTION[36]: LI (op=27) rs=R0 rt=R9 rd=R0 imm=10
DEBUG: Passando parâmetro 0: 't5'
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R9 (reutilizando)
DEBUG: Variável 't5' -> R9 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 0: 't5' de R9 para R4 (forçado)
ADD_INSTRUCTION[37]: MOVE (op=11) rs=R9 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[37]: rs=9, rt=0, rd=4 (Armazenado: rs=9, rd=4)
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't6' -> R10
DEBUG: add_move_if_different(R1 -> R10)
DEBUG: Gerando MOVE R10, R1
ADD_INSTRUCTION[39]: MOVE (op=11) rs=R1 rt=R0 rd=R10 imm=0
DEBUG: add_instruction MOVE[39]: rs=1, rt=0, rd=10 (Armazenado: rs=1, rd=10)
ADD_INSTRUCTION[40]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[40]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R10 (reutilizando)
DEBUG: Variável 't6' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('localmain', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 'localmain' -> R11
DEBUG: add_move_if_different(R10 -> R11)
DEBUG: Gerando MOVE R11, R10
ADD_INSTRUCTION[41]: MOVE (op=11) rs=R10 rt=R0 rd=R11 imm=0
DEBUG: add_instruction MOVE[41]: rs=10, rt=0, rd=11 (Armazenado: rs=10, rd=11)
ADD_INSTRUCTION[42]: SW (op=26) rs=R30 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R11, 0(R30)'
DEBUG: load_variable_to_register('localmain', 'main')
DEBUG: get_register_for_variable('localmain', 'main')
DEBUG: Variável 'localmain' já em R11 (reutilizando)
DEBUG: Variável 'localmain' -> R11 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[43]: LW (op=25) rs=R30 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R11, 0(R30)'

ADD_INSTRUCTION[44]: OUTPUTREG (op=32) rs=R11 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('globalvar', 'main')
DEBUG: get_register_for_variable('globalvar', 'main')
DEBUG: Variável 'globalvar' já em R7 (reutilizando)
DEBUG: Variável 'globalvar' -> R7 (símbolo encontrado: offset=0, global=1)ADD_INSTRUCTION[45]: LW (op=25) rs=R28 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R28)'

ADD_INSTRUCTION[46]: OUTPUTREG (op=32) rs=R7 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('globalvar', 'main')
DEBUG: get_register_for_variable('globalvar', 'main')
DEBUG: Variável 'globalvar' já em R7 (reutilizando)
DEBUG: Variável 'globalvar' -> R7 (símbolo encontrado: offset=0, global=1)ADD_INSTRUCTION[47]: LW (op=25) rs=R28 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R28)'

DEBUG: load_variable_to_register('localmain', 'main')
DEBUG: get_register_for_variable('localmain', 'main')
DEBUG: Variável 'localmain' já em R11 (reutilizando)
DEBUG: Variável 'localmain' -> R11 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[48]: LW (op=25) rs=R30 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R11, 0(R30)'

DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't7' -> R12
ADD_INSTRUCTION[49]: ADD (op=0) rs=R7 rt=R11 rd=R12 imm=0
  ADD PREVIEW: Will output 'ADD R12, R7, R11'
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R12 (reutilizando)
DEBUG: Variável 't7' -> R12 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('globalvar', 'main')
DEBUG: Variável 'globalvar' já em R7 (reutilizando)
DEBUG: add_move_if_different(R12 -> R7)
DEBUG: Gerando MOVE R7, R12
ADD_INSTRUCTION[50]: MOVE (op=11) rs=R12 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[50]: rs=12, rt=0, rd=7 (Armazenado: rs=12, rd=7)
ADD_INSTRUCTION[51]: SW (op=26) rs=R28 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R28)'
DEBUG: load_variable_to_register('globalvar', 'main')
DEBUG: get_register_for_variable('globalvar', 'main')
DEBUG: Variável 'globalvar' já em R7 (reutilizando)
DEBUG: Variável 'globalvar' -> R7 (símbolo encontrado: offset=0, global=1)ADD_INSTRUCTION[52]: LW (op=25) rs=R28 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R28)'

ADD_INSTRUCTION[53]: OUTPUTREG (op=32) rs=R7 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[54]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 27
Instruções geradas: 55
Labels: 3
Símbolos: 4
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
globalvar                       0       Sim     Não    Não    1      
param           testscope       0       Não    Sim     Não    1      
localvar        testscope       1       Não    Sim     Não    1      
localmain       main            0       Não    Sim     Não    1      
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
