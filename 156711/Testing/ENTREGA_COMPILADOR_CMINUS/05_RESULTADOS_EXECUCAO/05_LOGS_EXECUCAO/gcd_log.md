# Relatório de Compilação - gcd.c
## Data: 2025-09-16 20:28:06
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\gcd.c
Tamanho: 282 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function gcd children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=0, exp=-1, name=NULL
DEBUG: Processing function main children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=x
DEBUG: Child - node=0, stmt=2, exp=-1, name=y
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
(goto,main, , )
(fun,gcd, , )
(alloc,u,1, )
(alloc,v,1, )
(immed,0, ,t0)
(bne,v,t0,L0)
(ret,u, , )
(label,L0, , )
(/,u,v,t1)
(*,t1,v,t2)
(-,u,t2,t3)
(param,v, , )
(param,t3, , )
(call,gcd,v,t4)
(ret,t4, , )
(label,L1, , )
(endfun, , , )
(fun,main, , )
(alloc,x,1, )
(alloc,y,1, )
(input, , ,t5)
(asn,t5, ,x)
(input, , ,t6)
(asn,t6, ,y)
(param,x, , )
(param,y, , )
(call,gcd,x,t7)
(output,t7,0, )
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
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=144
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'gcd' detectada com 2 parâmetros totais
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
DEBUG: Configurando função 'gcd' - salvando 2 parâmetros de registrador
DEBUG: Salvando 2 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[8]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[9]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Local offset configurado para 2 (baseado em 2 parâmetros)
DEBUG: Detectado parâmetro u na função gcd (param #1 de 2)
DEBUG: Parâmetro u registrado com offset 0 na função gcd
DEBUG: Detectado parâmetro v na função gcd (param #2 de 2)
DEBUG: Parâmetro v registrado com offset 1 na função gcd
DEBUG: get_register_for_variable('t0', 'gcd')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[10]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=0
DEBUG: load_variable_to_register('v', 'gcd')
DEBUG: get_register_for_variable('v', 'gcd')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'v' -> R2
DEBUG: Variável 'v' -> R2 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[11]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R2, 1(R30)'

DEBUG: load_variable_to_register('t0', 'gcd')
DEBUG: get_register_for_variable('t0', 'gcd')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('u', 'gcd')
DEBUG: get_register_for_variable('u', 'gcd')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 'u' -> R3
DEBUG: Variável 'u' -> R3 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[13]: LW (op=25) rs=R30 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R30)'

DEBUG: add_move_if_different(R3 -> R1)
DEBUG: Gerando MOVE R1, R3
ADD_INSTRUCTION[14]: MOVE (op=11) rs=R3 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[14]: rs=3, rt=0, rd=1 (Armazenado: rs=3, rd=1)
DEBUG: load_variable_to_register('u', 'gcd')
DEBUG: get_register_for_variable('u', 'gcd')
DEBUG: Variável 'u' já em R3 (reutilizando)
DEBUG: Variável 'u' -> R3 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[16]: LW (op=25) rs=R30 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R30)'

DEBUG: load_variable_to_register('v', 'gcd')
DEBUG: get_register_for_variable('v', 'gcd')
DEBUG: Variável 'v' já em R2 (reutilizando)
DEBUG: Variável 'v' -> R2 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[17]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R2, 1(R30)'

DEBUG: get_register_for_variable('t1', 'gcd')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 't1' -> R4
ADD_INSTRUCTION[18]: DIV (op=3) rs=R3 rt=R2 rd=R4 imm=0
DEBUG: load_variable_to_register('t1', 'gcd')
DEBUG: get_register_for_variable('t1', 'gcd')
DEBUG: Variável 't1' já em R4 (reutilizando)
DEBUG: Variável 't1' -> R4 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('v', 'gcd')
DEBUG: get_register_for_variable('v', 'gcd')
DEBUG: Variável 'v' já em R2 (reutilizando)
DEBUG: Variável 'v' -> R2 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[19]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R2, 1(R30)'

DEBUG: get_register_for_variable('t2', 'gcd')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't2' -> R5
ADD_INSTRUCTION[20]: MULT (op=2) rs=R4 rt=R2 rd=R5 imm=0
DEBUG: load_variable_to_register('u', 'gcd')
DEBUG: get_register_for_variable('u', 'gcd')
DEBUG: Variável 'u' já em R3 (reutilizando)
DEBUG: Variável 'u' -> R3 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[21]: LW (op=25) rs=R30 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R30)'

DEBUG: load_variable_to_register('t2', 'gcd')
DEBUG: get_register_for_variable('t2', 'gcd')
DEBUG: Variável 't2' já em R5 (reutilizando)
DEBUG: Variável 't2' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t3', 'gcd')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't3' -> R6
ADD_INSTRUCTION[22]: SUB (op=1) rs=R3 rt=R5 rd=R6 imm=0
DEBUG: Passando parâmetro 0: 'v'
DEBUG: load_variable_to_register('v', 'gcd')
DEBUG: get_register_for_variable('v', 'gcd')
DEBUG: Variável 'v' já em R2 (reutilizando)
DEBUG: Variável 'v' -> R2 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[23]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R2, 1(R30)'

DEBUG: Parâmetro 0: 'v' de R2 para R4 (forçado)
ADD_INSTRUCTION[24]: MOVE (op=11) rs=R2 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[24]: rs=2, rt=0, rd=4 (Armazenado: rs=2, rd=4)
DEBUG: Passando parâmetro 1: 't3'
DEBUG: load_variable_to_register('t3', 'gcd')
DEBUG: get_register_for_variable('t3', 'gcd')
DEBUG: Variável 't3' já em R6 (reutilizando)
DEBUG: Variável 't3' -> R6 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 1: 't3' de R6 para R5 (forçado)
ADD_INSTRUCTION[25]: MOVE (op=11) rs=R6 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[25]: rs=6, rt=0, rd=5 (Armazenado: rs=6, rd=5)
DEBUG: get_register_for_variable('t4', 'gcd')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't4' -> R7
DEBUG: add_move_if_different(R1 -> R7)
DEBUG: Gerando MOVE R7, R1
ADD_INSTRUCTION[27]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[27]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('t4', 'gcd')
DEBUG: get_register_for_variable('t4', 'gcd')
DEBUG: Variável 't4' já em R7 (reutilizando)
DEBUG: Variável 't4' -> R7 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R7 -> R1)
DEBUG: Gerando MOVE R1, R7
ADD_INSTRUCTION[28]: MOVE (op=11) rs=R7 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[28]: rs=7, rt=0, rd=1 (Armazenado: rs=7, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[30]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[31]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[32]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[33]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 2 parâmetros totais
ADD_INSTRUCTION[35]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[36]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[37]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[38]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[38]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro x na função main (param #1 de 2)
DEBUG: Parâmetro x registrado com offset 0 na função main
DEBUG: Detectado parâmetro y na função main (param #2 de 2)
DEBUG: Parâmetro y registrado com offset 1 na função main
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't5' -> R8
ADD_INSTRUCTION[39]: INPUT (op=34) rs=R0 rt=R0 rd=R8 imm=0
ADD_INSTRUCTION[40]: OUTPUTREG (op=32) rs=R8 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R8 (reutilizando)
DEBUG: Variável 't5' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('x', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 'x' -> R9
DEBUG: add_move_if_different(R8 -> R9)
DEBUG: Gerando MOVE R9, R8
ADD_INSTRUCTION[41]: MOVE (op=11) rs=R8 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[41]: rs=8, rt=0, rd=9 (Armazenado: rs=8, rd=9)
ADD_INSTRUCTION[42]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R30)'
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't6' -> R10
ADD_INSTRUCTION[43]: INPUT (op=34) rs=R0 rt=R0 rd=R10 imm=0
ADD_INSTRUCTION[44]: OUTPUTREG (op=32) rs=R10 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R10 (reutilizando)
DEBUG: Variável 't6' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('y', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 'y' -> R11
DEBUG: add_move_if_different(R10 -> R11)
DEBUG: Gerando MOVE R11, R10
ADD_INSTRUCTION[45]: MOVE (op=11) rs=R10 rt=R0 rd=R11 imm=0
DEBUG: add_instruction MOVE[45]: rs=10, rt=0, rd=11 (Armazenado: rs=10, rd=11)
ADD_INSTRUCTION[46]: SW (op=26) rs=R30 rt=R11 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R11, 1(R30)'
DEBUG: Passando parâmetro 0: 'x'
DEBUG: load_variable_to_register('x', 'main')
DEBUG: get_register_for_variable('x', 'main')
DEBUG: Variável 'x' já em R9 (reutilizando)
DEBUG: Variável 'x' -> R9 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[47]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R30)'

DEBUG: Parâmetro 0: 'x' de R9 para R4 (forçado)
ADD_INSTRUCTION[48]: MOVE (op=11) rs=R9 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[48]: rs=9, rt=0, rd=4 (Armazenado: rs=9, rd=4)
DEBUG: Passando parâmetro 1: 'y'
DEBUG: load_variable_to_register('y', 'main')
DEBUG: get_register_for_variable('y', 'main')
DEBUG: Variável 'y' já em R11 (reutilizando)
DEBUG: Variável 'y' -> R11 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[49]: LW (op=25) rs=R30 rt=R11 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R11, 1(R30)'

DEBUG: Parâmetro 1: 'y' de R11 para R5 (forçado)
ADD_INSTRUCTION[50]: MOVE (op=11) rs=R11 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[50]: rs=11, rt=0, rd=5 (Armazenado: rs=11, rd=5)
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't7' -> R12
DEBUG: add_move_if_different(R1 -> R12)
DEBUG: Gerando MOVE R12, R1
ADD_INSTRUCTION[52]: MOVE (op=11) rs=R1 rt=R0 rd=R12 imm=0
DEBUG: add_instruction MOVE[52]: rs=1, rt=0, rd=12 (Armazenado: rs=1, rd=12)
ADD_INSTRUCTION[53]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[53]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R12 (reutilizando)
DEBUG: Variável 't7' -> R12 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[54]: OUTPUTREG (op=32) rs=R12 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[55]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 29
Instruções geradas: 56
Labels: 4
Símbolos: 4
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
u               gcd             0       Não    Sim     Não    1      
v               gcd             1       Não    Sim     Não    1      
x               main            0       Não    Sim     Não    1      
y               main            1       Não    Sim     Não    1      
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
Entradas: [48, 18]
Resultado esperado: None
Traceback (most recent call last):
  File "d:\Projetinhos\Compilador\Utils\mips_simulator.py", line 870, in <module>
    main()
  File "d:\Projetinhos\Compilador\Utils\mips_simulator.py", line 783, in main
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
