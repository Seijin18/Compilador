# Relatório de Compilação - fat.c
## Data: 2025-10-04 00:55:57
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\fat.c
Tamanho: 189 bytes

### 🔧 Compilação C-Minus
```
ERRO LEXICO: '' INVALIDO [linha: 17, coluna: 0]
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function fat children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
(goto,main, , )
(fun,fat, , )
(alloc,x,1, )
(immed,0, ,t0)
(bne,x,t0,L0)
(immed,10, ,t1)
(output,t1,0, )
(immed,1, ,t2)
(ret,t2, , )
(goto,L1, , )
(label,L0, , )
(output,x,0, )
(immed,1, ,t3)
(-,x,t3,t4)
(param,t4, , )
(call,fat,t4,t5)
(*,x,t5,t6)
(ret,t6, , )
(label,L1, , )
(endfun, , , )
(fun,main, , )
(alloc,x,1, )
(input, , ,t7)
(asn,t7, ,x)
(param,x, , )
(call,fat,x,t8)
(output,t8,0, )
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
Quadruplas lidas: 28
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'fat' detectada com 1 parâmetros totais
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
DEBUG: Configurando função 'fat' - salvando 1 parâmetros de registrador
DEBUG: Salvando 1 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[8]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Local offset configurado para 1 (baseado em 1 parâmetros)
DEBUG: Detectado parâmetro x na função fat (param #1 de 1)
DEBUG: Parâmetro x registrado com offset 0 na função fat
DEBUG: get_register_for_variable('t0', 'fat')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[9]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=0
DEBUG: load_variable_to_register('x', 'fat')
DEBUG: get_register_for_variable('x', 'fat')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'x' -> R2
DEBUG: Variável 'x' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[10]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t0', 'fat')
DEBUG: get_register_for_variable('t0', 'fat')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t1', 'fat')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[12]: LI (op=27) rs=R0 rt=R3 rd=R0 imm=10
DEBUG: load_variable_to_register('t1', 'fat')
DEBUG: get_register_for_variable('t1', 'fat')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[13]: OUTPUTREG (op=32) rs=R3 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t2', 'fat')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 't2' -> R4
ADD_INSTRUCTION[14]: LI (op=27) rs=R0 rt=R4 rd=R0 imm=1
DEBUG: load_variable_to_register('t2', 'fat')
DEBUG: get_register_for_variable('t2', 'fat')
DEBUG: Variável 't2' já em R4 (reutilizando)
DEBUG: Variável 't2' -> R4 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R4 -> R1)
DEBUG: Gerando MOVE R1, R4
ADD_INSTRUCTION[15]: MOVE (op=11) rs=R4 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[15]: rs=4, rt=0, rd=1 (Armazenado: rs=4, rd=1)
DEBUG: load_variable_to_register('x', 'fat')
DEBUG: get_register_for_variable('x', 'fat')
DEBUG: Variável 'x' já em R2 (reutilizando)
DEBUG: Variável 'x' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[19]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

ADD_INSTRUCTION[20]: OUTPUTREG (op=32) rs=R2 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t3', 'fat')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't3' -> R5
ADD_INSTRUCTION[21]: LI (op=27) rs=R0 rt=R5 rd=R0 imm=1
DEBUG: load_variable_to_register('x', 'fat')
DEBUG: get_register_for_variable('x', 'fat')
DEBUG: Variável 'x' já em R2 (reutilizando)
DEBUG: Variável 'x' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[22]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t3', 'fat')
DEBUG: get_register_for_variable('t3', 'fat')
DEBUG: Variável 't3' já em R5 (reutilizando)
DEBUG: Variável 't3' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t4', 'fat')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't4' -> R6
ADD_INSTRUCTION[23]: SUB (op=1) rs=R2 rt=R5 rd=R6 imm=0
DEBUG: Passando parâmetro 0: 't4'
DEBUG: load_variable_to_register('t4', 'fat')
DEBUG: get_register_for_variable('t4', 'fat')
DEBUG: Variável 't4' já em R6 (reutilizando)
DEBUG: Variável 't4' -> R6 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 0: 't4' de R6 para R4 (forçado)
ADD_INSTRUCTION[24]: MOVE (op=11) rs=R6 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[24]: rs=6, rt=0, rd=4 (Armazenado: rs=6, rd=4)
DEBUG: Salvando R2 (contém 'x') antes da chamada
ADD_INSTRUCTION[25]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[26]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 't1') antes da chamada
ADD_INSTRUCTION[27]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[28]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
DEBUG: Salvando R5 (contém 't3') antes da chamada
ADD_INSTRUCTION[29]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[30]: SW (op=26) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R2)'
DEBUG: Salvando R6 (contém 't4') antes da chamada
ADD_INSTRUCTION[31]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[32]: SW (op=26) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R2)'
ADD_INSTRUCTION[33]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=4
ADD_INSTRUCTION[35]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=4
  ADDI PREVIEW: Will output 'ADDI R29, R29, 4'
DEBUG: Restaurando R6 (contém 't4') após a chamada
ADD_INSTRUCTION[36]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[37]: LW (op=25) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R6, 0(R2)'
DEBUG: Restaurando R5 (contém 't3') após a chamada
ADD_INSTRUCTION[38]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[39]: LW (op=25) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R2)'
DEBUG: Restaurando R3 (contém 't1') após a chamada
ADD_INSTRUCTION[40]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[41]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'x') após a chamada
ADD_INSTRUCTION[42]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[43]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t5', 'fat')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't5' -> R7
DEBUG: add_move_if_different(R1 -> R7)
DEBUG: Gerando MOVE R7, R1
ADD_INSTRUCTION[44]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[44]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('x', 'fat')
DEBUG: get_register_for_variable('x', 'fat')
DEBUG: Variável 'x' já em R2 (reutilizando)
DEBUG: Variável 'x' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[45]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t5', 'fat')
DEBUG: get_register_for_variable('t5', 'fat')
DEBUG: Variável 't5' já em R7 (reutilizando)
DEBUG: Variável 't5' -> R7 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t6', 'fat')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't6' -> R8
ADD_INSTRUCTION[46]: MULT (op=2) rs=R2 rt=R7 rd=R8 imm=0
DEBUG: load_variable_to_register('t6', 'fat')
DEBUG: get_register_for_variable('t6', 'fat')
DEBUG: Variável 't6' já em R8 (reutilizando)
DEBUG: Variável 't6' -> R8 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R8 -> R1)
DEBUG: Gerando MOVE R1, R8
ADD_INSTRUCTION[47]: MOVE (op=11) rs=R8 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[47]: rs=8, rt=0, rd=1 (Armazenado: rs=8, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[51]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[52]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[53]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[54]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 1 parâmetros totais
ADD_INSTRUCTION[56]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[57]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[58]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[59]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[59]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro x na função main (param #1 de 1)
DEBUG: Parâmetro x registrado com offset 0 na função main
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't7' -> R9
ADD_INSTRUCTION[60]: INPUT (op=34) rs=R0 rt=R0 rd=R9 imm=0
ADD_INSTRUCTION[61]: OUTPUTREG (op=32) rs=R9 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R9 (reutilizando)
DEBUG: Variável 't7' -> R9 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('x', 'main')
DEBUG: Variável 'x' já em R2 (reutilizando)
DEBUG: add_move_if_different(R9 -> R2)
DEBUG: Gerando MOVE R2, R9
ADD_INSTRUCTION[62]: MOVE (op=11) rs=R9 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[62]: rs=9, rt=0, rd=2 (Armazenado: rs=9, rd=2)
ADD_INSTRUCTION[63]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: Passando parâmetro 0: 'x'
DEBUG: load_variable_to_register('x', 'main')
DEBUG: get_register_for_variable('x', 'main')
DEBUG: Variável 'x' já em R2 (reutilizando)
DEBUG: Variável 'x' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[64]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: Parâmetro 0: 'x' de R2 para R4 (forçado)
ADD_INSTRUCTION[65]: MOVE (op=11) rs=R2 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[65]: rs=2, rt=0, rd=4 (Armazenado: rs=2, rd=4)
DEBUG: Salvando R2 (contém 'x') antes da chamada
ADD_INSTRUCTION[66]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[67]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 't1') antes da chamada
ADD_INSTRUCTION[68]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[69]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
DEBUG: Salvando R5 (contém 't3') antes da chamada
ADD_INSTRUCTION[70]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[71]: SW (op=26) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R2)'
DEBUG: Salvando R6 (contém 't4') antes da chamada
ADD_INSTRUCTION[72]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[73]: SW (op=26) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R2)'
DEBUG: Salvando R7 (contém 't5') antes da chamada
ADD_INSTRUCTION[74]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[75]: SW (op=26) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R2)'
DEBUG: Salvando R8 (contém 't6') antes da chamada
ADD_INSTRUCTION[76]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[77]: SW (op=26) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R2)'
DEBUG: Salvando R9 (contém 't7') antes da chamada
ADD_INSTRUCTION[78]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[79]: SW (op=26) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R2)'
ADD_INSTRUCTION[80]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=7
ADD_INSTRUCTION[82]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=7
  ADDI PREVIEW: Will output 'ADDI R29, R29, 7'
DEBUG: Restaurando R9 (contém 't7') após a chamada
ADD_INSTRUCTION[83]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[84]: LW (op=25) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R2)'
DEBUG: Restaurando R8 (contém 't6') após a chamada
ADD_INSTRUCTION[85]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[86]: LW (op=25) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R2)'
DEBUG: Restaurando R7 (contém 't5') após a chamada
ADD_INSTRUCTION[87]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[88]: LW (op=25) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R2)'
DEBUG: Restaurando R6 (contém 't4') após a chamada
ADD_INSTRUCTION[89]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[90]: LW (op=25) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R6, 0(R2)'
DEBUG: Restaurando R5 (contém 't3') após a chamada
ADD_INSTRUCTION[91]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[92]: LW (op=25) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R2)'
DEBUG: Restaurando R3 (contém 't1') após a chamada
ADD_INSTRUCTION[93]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[94]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'x') após a chamada
ADD_INSTRUCTION[95]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[96]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't8' -> R10
DEBUG: add_move_if_different(R1 -> R10)
DEBUG: Gerando MOVE R10, R1
ADD_INSTRUCTION[97]: MOVE (op=11) rs=R1 rt=R0 rd=R10 imm=0
DEBUG: add_instruction MOVE[97]: rs=1, rt=0, rd=10 (Armazenado: rs=1, rd=10)
ADD_INSTRUCTION[98]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[98]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R10 (reutilizando)
DEBUG: Variável 't8' -> R10 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[99]: OUTPUTREG (op=32) rs=R10 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[100]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 28
Instruções geradas: 101
Labels: 5
Símbolos: 2
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
x               fat             0       Não    Sim     Não    1      
x               main            0       Não    Sim     Não    1      
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
Entradas: [5]
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
