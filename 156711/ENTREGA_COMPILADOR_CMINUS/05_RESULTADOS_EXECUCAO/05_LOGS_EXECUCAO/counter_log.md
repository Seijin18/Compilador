# Relatório de Compilação - counter.c
## Data: 2025-10-04 00:55:57
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\counter.c
Tamanho: 199 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
(goto,main, , )
(fun,main, , )
(alloc,count,1, )
(alloc,i,1, )
(immed,0, ,t0)
(asn,t0, ,count)
(immed,0, ,t1)
(asn,t1, ,i)
(label,L0, , )
(immed,10, ,t2)
(<,i,t2,t3)
(if_f,t3,L1, )
(immed,1, ,t4)
(+,count,t4,t5)
(asn,t5, ,count)
(output,count,0, )
(immed,1, ,t6)
(+,i,t6,t7)
(asn,t7, ,i)
(goto,L0, , )
(label,L1, , )
(output,count,0, )
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
Quadruplas lidas: 23
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
DEBUG: Detectado parâmetro count na função main (param #1 de 2)
DEBUG: Parâmetro count registrado com offset 0 na função main
DEBUG: Detectado parâmetro i na função main (param #2 de 2)
DEBUG: Parâmetro i registrado com offset 1 na função main
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[8]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=0
DEBUG: load_variable_to_register('t0', 'main')
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('count', 'main')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'count' -> R2
DEBUG: add_move_if_different(R1 -> R2)
DEBUG: Gerando MOVE R2, R1
ADD_INSTRUCTION[9]: MOVE (op=11) rs=R1 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[9]: rs=1, rt=0, rd=2 (Armazenado: rs=1, rd=2)
ADD_INSTRUCTION[10]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[11]: LI (op=27) rs=R0 rt=R3 rd=R0 imm=0
DEBUG: load_variable_to_register('t1', 'main')
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 'i' -> R4
DEBUG: add_move_if_different(R3 -> R4)
DEBUG: Gerando MOVE R4, R3
ADD_INSTRUCTION[12]: MOVE (op=11) rs=R3 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[12]: rs=3, rt=0, rd=4 (Armazenado: rs=3, rd=4)
ADD_INSTRUCTION[13]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R4, 1(R30)'
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't2' -> R5
ADD_INSTRUCTION[15]: LI (op=27) rs=R0 rt=R5 rd=R0 imm=10
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R4 (reutilizando)
DEBUG: Variável 'i' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[16]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: load_variable_to_register('t2', 'main')
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Variável 't2' já em R5 (reutilizando)
DEBUG: Variável 't2' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't3' -> R6
ADD_INSTRUCTION[17]: SLT (op=8) rs=R4 rt=R5 rd=R6 imm=0
DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R6 (reutilizando)
DEBUG: Variável 't3' -> R6 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't4' -> R7
ADD_INSTRUCTION[19]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=1
DEBUG: load_variable_to_register('count', 'main')
DEBUG: get_register_for_variable('count', 'main')
DEBUG: Variável 'count' já em R2 (reutilizando)
DEBUG: Variável 'count' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[20]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R7 (reutilizando)
DEBUG: Variável 't4' -> R7 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't5' -> R8
ADD_INSTRUCTION[21]: ADD (op=0) rs=R2 rt=R7 rd=R8 imm=0
  ADD PREVIEW: Will output 'ADD R8, R2, R7'
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R8 (reutilizando)
DEBUG: Variável 't5' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('count', 'main')
DEBUG: Variável 'count' já em R2 (reutilizando)
DEBUG: add_move_if_different(R8 -> R2)
DEBUG: Gerando MOVE R2, R8
ADD_INSTRUCTION[22]: MOVE (op=11) rs=R8 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[22]: rs=8, rt=0, rd=2 (Armazenado: rs=8, rd=2)
ADD_INSTRUCTION[23]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: load_variable_to_register('count', 'main')
DEBUG: get_register_for_variable('count', 'main')
DEBUG: Variável 'count' já em R2 (reutilizando)
DEBUG: Variável 'count' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[24]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

ADD_INSTRUCTION[25]: OUTPUTREG (op=32) rs=R2 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't6' -> R9
ADD_INSTRUCTION[26]: LI (op=27) rs=R0 rt=R9 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R4 (reutilizando)
DEBUG: Variável 'i' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[27]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R9 (reutilizando)
DEBUG: Variável 't6' -> R9 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't7' -> R10
ADD_INSTRUCTION[28]: ADD (op=0) rs=R4 rt=R9 rd=R10 imm=0
  ADD PREVIEW: Will output 'ADD R10, R4, R9'
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R10 (reutilizando)
DEBUG: Variável 't7' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R4 (reutilizando)
DEBUG: add_move_if_different(R10 -> R4)
DEBUG: Gerando MOVE R4, R10
ADD_INSTRUCTION[29]: MOVE (op=11) rs=R10 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[29]: rs=10, rt=0, rd=4 (Armazenado: rs=10, rd=4)
ADD_INSTRUCTION[30]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R4, 1(R30)'
DEBUG: load_variable_to_register('count', 'main')
DEBUG: get_register_for_variable('count', 'main')
DEBUG: Variável 'count' já em R2 (reutilizando)
DEBUG: Variável 'count' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[33]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

ADD_INSTRUCTION[34]: OUTPUTREG (op=32) rs=R2 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[35]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 23
Instruções geradas: 36
Labels: 3
Símbolos: 2
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
count           main            0       Não    Sim     Não    1      
i               main            1       Não    Sim     Não    1      
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
