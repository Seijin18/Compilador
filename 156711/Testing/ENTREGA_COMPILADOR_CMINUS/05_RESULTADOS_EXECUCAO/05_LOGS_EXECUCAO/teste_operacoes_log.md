# Relatório de Compilação - teste_operacoes.c
## Data: 2025-09-23 12:21:38
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\teste_operacoes.c
Tamanho: 651 bytes

### 🔧 Compilação C-Minus
```
ERRO LEXICO: '' INVALIDO [linha: 43, coluna: 0]
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=a
DEBUG: Child - node=0, stmt=2, exp=-1, name=b
DEBUG: Child - node=0, stmt=2, exp=-1, name=resultado
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=2, exp=-1, name=resultado
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=2, exp=-1, name=resultado
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
DEBUG: Child - node=0, stmt=0, exp=-1, name=NULL
DEBUG: Child - node=0, stmt=0, exp=-1, name=NULL
DEBUG: Child - node=0, stmt=0, exp=-1, name=NULL
DEBUG: Child - node=0, stmt=0, exp=-1, name=NULL
(goto,main, , )
(fun,main, , )
(alloc,a,1, )
(alloc,b,1, )
(alloc,resultado,1, )
(input, , ,t0)
(asn,t0, ,a)
(input, , ,t1)
(asn,t1, ,b)
(+,a,b,t2)
(asn,t2, ,resultado)
(output,resultado,0, )
(-,a,b,t3)
(asn,t3, ,resultado)
(output,resultado,0, )
(*,a,b,t4)
(asn,t4, ,resultado)
(output,resultado,0, )
(bge,a,b,L0)
(immed,1, ,t5)
(output,t5,0, )
(goto,L1, , )
(label,L0, , )
(immed,0, ,t6)
(output,t6,0, )
(label,L1, , )
(ble,a,b,L2)
(immed,1, ,t7)
(output,t7,0, )
(goto,L3, , )
(label,L2, , )
(immed,0, ,t8)
(output,t8,0, )
(label,L3, , )
(bne,a,b,L4)
(immed,1, ,t9)
(output,t9,0, )
(goto,L5, , )
(label,L4, , )
(immed,0, ,t10)
(output,t10,0, )
(label,L5, , )
(beq,a,b,L6)
(immed,1, ,t11)
(output,t11,0, )
(goto,L7, , )
(label,L6, , )
(immed,0, ,t12)
(output,t12,0, )
(label,L7, , )
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
Quadruplas lidas: 51
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=140
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'main' detectada com 3 parâmetros totais
ADD_INSTRUCTION[4]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[5]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[6]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[7]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[7]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro a na função main (param #1 de 3)
DEBUG: Parâmetro a registrado com offset 0 na função main
DEBUG: Detectado parâmetro b na função main (param #2 de 3)
DEBUG: Parâmetro b registrado com offset 1 na função main
DEBUG: Detectado parâmetro resultado na função main (param #3 de 3)
DEBUG: Parâmetro resultado registrado com offset 2 na função main
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[8]: INPUT (op=34) rs=R0 rt=R0 rd=R1 imm=0
ADD_INSTRUCTION[9]: OUTPUTREG (op=32) rs=R1 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t0', 'main')
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'a' -> R2
DEBUG: add_move_if_different(R1 -> R2)
DEBUG: Gerando MOVE R2, R1
ADD_INSTRUCTION[10]: MOVE (op=11) rs=R1 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[10]: rs=1, rt=0, rd=2 (Armazenado: rs=1, rd=2)
ADD_INSTRUCTION[11]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[12]: INPUT (op=34) rs=R0 rt=R0 rd=R3 imm=0
ADD_INSTRUCTION[13]: OUTPUTREG (op=32) rs=R3 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t1', 'main')
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 'b' -> R4
DEBUG: add_move_if_different(R3 -> R4)
DEBUG: Gerando MOVE R4, R3
ADD_INSTRUCTION[14]: MOVE (op=11) rs=R3 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[14]: rs=3, rt=0, rd=4 (Armazenado: rs=3, rd=4)
ADD_INSTRUCTION[15]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R4, 1(R30)'
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[16]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('b', 'main')
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Variável 'b' já em R4 (reutilizando)
DEBUG: Variável 'b' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[17]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't2' -> R5
ADD_INSTRUCTION[18]: ADD (op=0) rs=R2 rt=R4 rd=R5 imm=0
  ADD PREVIEW: Will output 'ADD R5, R2, R4'
DEBUG: load_variable_to_register('t2', 'main')
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Variável 't2' já em R5 (reutilizando)
DEBUG: Variável 't2' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('resultado', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 'resultado' -> R6
DEBUG: add_move_if_different(R5 -> R6)
DEBUG: Gerando MOVE R6, R5
ADD_INSTRUCTION[19]: MOVE (op=11) rs=R5 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[19]: rs=5, rt=0, rd=6 (Armazenado: rs=5, rd=6)
ADD_INSTRUCTION[20]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: load_variable_to_register('resultado', 'main')
DEBUG: get_register_for_variable('resultado', 'main')
DEBUG: Variável 'resultado' já em R6 (reutilizando)
DEBUG: Variável 'resultado' -> R6 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[21]: LW (op=25) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R6, 2(R30)'

ADD_INSTRUCTION[22]: OUTPUTREG (op=32) rs=R6 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[23]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('b', 'main')
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Variável 'b' já em R4 (reutilizando)
DEBUG: Variável 'b' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[24]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't3' -> R7
ADD_INSTRUCTION[25]: SUB (op=1) rs=R2 rt=R4 rd=R7 imm=0
DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R7 (reutilizando)
DEBUG: Variável 't3' -> R7 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('resultado', 'main')
DEBUG: Variável 'resultado' já em R6 (reutilizando)
DEBUG: add_move_if_different(R7 -> R6)
DEBUG: Gerando MOVE R6, R7
ADD_INSTRUCTION[26]: MOVE (op=11) rs=R7 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[26]: rs=7, rt=0, rd=6 (Armazenado: rs=7, rd=6)
ADD_INSTRUCTION[27]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: load_variable_to_register('resultado', 'main')
DEBUG: get_register_for_variable('resultado', 'main')
DEBUG: Variável 'resultado' já em R6 (reutilizando)
DEBUG: Variável 'resultado' -> R6 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[28]: LW (op=25) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R6, 2(R30)'

ADD_INSTRUCTION[29]: OUTPUTREG (op=32) rs=R6 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[30]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('b', 'main')
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Variável 'b' já em R4 (reutilizando)
DEBUG: Variável 'b' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[31]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't4' -> R8
ADD_INSTRUCTION[32]: MULT (op=2) rs=R2 rt=R4 rd=R8 imm=0
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R8 (reutilizando)
DEBUG: Variável 't4' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('resultado', 'main')
DEBUG: Variável 'resultado' já em R6 (reutilizando)
DEBUG: add_move_if_different(R8 -> R6)
DEBUG: Gerando MOVE R6, R8
ADD_INSTRUCTION[33]: MOVE (op=11) rs=R8 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[33]: rs=8, rt=0, rd=6 (Armazenado: rs=8, rd=6)
ADD_INSTRUCTION[34]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: load_variable_to_register('resultado', 'main')
DEBUG: get_register_for_variable('resultado', 'main')
DEBUG: Variável 'resultado' já em R6 (reutilizando)
DEBUG: Variável 'resultado' -> R6 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[35]: LW (op=25) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R6, 2(R30)'

ADD_INSTRUCTION[36]: OUTPUTREG (op=32) rs=R6 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[37]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('b', 'main')
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Variável 'b' já em R4 (reutilizando)
DEBUG: Variável 'b' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[38]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't5' -> R9
ADD_INSTRUCTION[40]: LI (op=27) rs=R0 rt=R9 rd=R0 imm=1
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R9 (reutilizando)
DEBUG: Variável 't5' -> R9 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[41]: OUTPUTREG (op=32) rs=R9 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't6' -> R10
ADD_INSTRUCTION[44]: LI (op=27) rs=R0 rt=R10 rd=R0 imm=0
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R10 (reutilizando)
DEBUG: Variável 't6' -> R10 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[45]: OUTPUTREG (op=32) rs=R10 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[47]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('b', 'main')
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Variável 'b' já em R4 (reutilizando)
DEBUG: Variável 'b' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[48]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't7' -> R11
ADD_INSTRUCTION[50]: LI (op=27) rs=R0 rt=R11 rd=R0 imm=1
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R11 (reutilizando)
DEBUG: Variável 't7' -> R11 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[51]: OUTPUTREG (op=32) rs=R11 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't8' -> R12
ADD_INSTRUCTION[54]: LI (op=27) rs=R0 rt=R12 rd=R0 imm=0
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R12 (reutilizando)
DEBUG: Variável 't8' -> R12 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[55]: OUTPUTREG (op=32) rs=R12 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[57]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('b', 'main')
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Variável 'b' já em R4 (reutilizando)
DEBUG: Variável 'b' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[58]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 't9' -> R13
ADD_INSTRUCTION[60]: LI (op=27) rs=R0 rt=R13 rd=R0 imm=1
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R13 (reutilizando)
DEBUG: Variável 't9' -> R13 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[61]: OUTPUTREG (op=32) rs=R13 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 't10' -> R14
ADD_INSTRUCTION[64]: LI (op=27) rs=R0 rt=R14 rd=R0 imm=0
DEBUG: load_variable_to_register('t10', 'main')
DEBUG: get_register_for_variable('t10', 'main')
DEBUG: Variável 't10' já em R14 (reutilizando)
DEBUG: Variável 't10' -> R14 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[65]: OUTPUTREG (op=32) rs=R14 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[67]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('b', 'main')
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Variável 'b' já em R4 (reutilizando)
DEBUG: Variável 'b' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[68]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't11' -> R15
ADD_INSTRUCTION[70]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=1
DEBUG: load_variable_to_register('t11', 'main')
DEBUG: get_register_for_variable('t11', 'main')
DEBUG: Variável 't11' já em R15 (reutilizando)
DEBUG: Variável 't11' -> R15 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[71]: OUTPUTREG (op=32) rs=R15 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 't12' -> R16
ADD_INSTRUCTION[74]: LI (op=27) rs=R0 rt=R16 rd=R0 imm=0
DEBUG: load_variable_to_register('t12', 'main')
DEBUG: get_register_for_variable('t12', 'main')
DEBUG: Variável 't12' já em R16 (reutilizando)
DEBUG: Variável 't12' -> R16 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[75]: OUTPUTREG (op=32) rs=R16 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[77]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 51
Instruções geradas: 78
Labels: 9
Símbolos: 3
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
a               main            0       Não    Sim     Não    1      
b               main            1       Não    Sim     Não    1      
resultado       main            2       Não    Sim     Não    1      
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
Entradas: [10, 5]
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
