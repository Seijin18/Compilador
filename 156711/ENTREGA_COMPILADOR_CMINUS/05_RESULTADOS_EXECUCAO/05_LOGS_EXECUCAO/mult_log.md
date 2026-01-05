# Relatório de Compilação - mult.c
## Data: 2025-10-04 00:55:57
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\mult.c
Tamanho: 245 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
(goto,main, , )
(fun,main, , )
(alloc,a,1, )
(alloc,b,1, )
(alloc,i,1, )
(alloc,original,1, )
(input, , ,t0)
(asn,t0, ,a)
(input, , ,t1)
(asn,t1, ,b)
(asn,a, ,original)
(immed,0, ,t2)
(asn,t2, ,a)
(immed,0, ,t3)
(asn,t3, ,i)
(label,L0, , )
(<,i,b,t4)
(if_f,t4,L1, )
(+,a,original,t5)
(asn,t5, ,a)
(immed,1, ,t6)
(+,i,t6,t7)
(asn,t7, ,i)
(goto,L0, , )
(label,L1, , )
(output,a,0, )
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
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'main' detectada com 4 parâmetros totais
ADD_INSTRUCTION[4]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[5]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[6]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[7]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[7]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro a na função main (param #1 de 4)
DEBUG: Parâmetro a registrado com offset 0 na função main
DEBUG: Detectado parâmetro b na função main (param #2 de 4)
DEBUG: Parâmetro b registrado com offset 1 na função main
DEBUG: Detectado parâmetro i na função main (param #3 de 4)
DEBUG: Parâmetro i registrado com offset 2 na função main
DEBUG: Detectado parâmetro original na função main (param #4 de 4)
DEBUG: Parâmetro original registrado com offset 3 na função main
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

DEBUG: get_register_for_variable('original', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 'original' -> R5
DEBUG: add_move_if_different(R2 -> R5)
DEBUG: Gerando MOVE R5, R2
ADD_INSTRUCTION[17]: MOVE (op=11) rs=R2 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[17]: rs=2, rt=0, rd=5 (Armazenado: rs=2, rd=5)
ADD_INSTRUCTION[18]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R5, 3(R30)'
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't2' -> R6
ADD_INSTRUCTION[19]: LI (op=27) rs=R0 rt=R6 rd=R0 imm=0
DEBUG: load_variable_to_register('t2', 'main')
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Variável 't2' já em R6 (reutilizando)
DEBUG: Variável 't2' -> R6 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: add_move_if_different(R6 -> R2)
DEBUG: Gerando MOVE R2, R6
ADD_INSTRUCTION[20]: MOVE (op=11) rs=R6 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[20]: rs=6, rt=0, rd=2 (Armazenado: rs=6, rd=2)
ADD_INSTRUCTION[21]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't3' -> R7
ADD_INSTRUCTION[22]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=0
DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R7 (reutilizando)
DEBUG: Variável 't3' -> R7 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 'i' -> R8
DEBUG: add_move_if_different(R7 -> R8)
DEBUG: Gerando MOVE R8, R7
ADD_INSTRUCTION[23]: MOVE (op=11) rs=R7 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[23]: rs=7, rt=0, rd=8 (Armazenado: rs=7, rd=8)
ADD_INSTRUCTION[24]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R8, 2(R30)'
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[26]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R8, 2(R30)'

DEBUG: load_variable_to_register('b', 'main')
DEBUG: get_register_for_variable('b', 'main')
DEBUG: Variável 'b' já em R4 (reutilizando)
DEBUG: Variável 'b' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[27]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't4' -> R9
ADD_INSTRUCTION[28]: SLT (op=8) rs=R8 rt=R4 rd=R9 imm=0
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R9 (reutilizando)
DEBUG: Variável 't4' -> R9 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[30]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('original', 'main')
DEBUG: get_register_for_variable('original', 'main')
DEBUG: Variável 'original' já em R5 (reutilizando)
DEBUG: Variável 'original' -> R5 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[31]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R5, 3(R30)'

DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't5' -> R10
ADD_INSTRUCTION[32]: ADD (op=0) rs=R2 rt=R5 rd=R10 imm=0
  ADD PREVIEW: Will output 'ADD R10, R2, R5'
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R10 (reutilizando)
DEBUG: Variável 't5' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: add_move_if_different(R10 -> R2)
DEBUG: Gerando MOVE R2, R10
ADD_INSTRUCTION[33]: MOVE (op=11) rs=R10 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[33]: rs=10, rt=0, rd=2 (Armazenado: rs=10, rd=2)
ADD_INSTRUCTION[34]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't6' -> R11
ADD_INSTRUCTION[35]: LI (op=27) rs=R0 rt=R11 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[36]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R8, 2(R30)'

DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R11 (reutilizando)
DEBUG: Variável 't6' -> R11 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't7' -> R12
ADD_INSTRUCTION[37]: ADD (op=0) rs=R8 rt=R11 rd=R12 imm=0
  ADD PREVIEW: Will output 'ADD R12, R8, R11'
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R12 (reutilizando)
DEBUG: Variável 't7' -> R12 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: add_move_if_different(R12 -> R8)
DEBUG: Gerando MOVE R8, R12
ADD_INSTRUCTION[38]: MOVE (op=11) rs=R12 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[38]: rs=12, rt=0, rd=8 (Armazenado: rs=12, rd=8)
ADD_INSTRUCTION[39]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R8, 2(R30)'
DEBUG: load_variable_to_register('a', 'main')
DEBUG: get_register_for_variable('a', 'main')
DEBUG: Variável 'a' já em R2 (reutilizando)
DEBUG: Variável 'a' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[42]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

ADD_INSTRUCTION[43]: OUTPUTREG (op=32) rs=R2 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[44]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 27
Instruções geradas: 45
Labels: 3
Símbolos: 4
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
a               main            0       Não    Sim     Não    1      
b               main            1       Não    Sim     Não    1      
i               main            2       Não    Sim     Não    1      
original        main            3       Não    Sim     Não    1      
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
Entradas: [6, 7]
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
