# Relatório de Compilação - test_multiple_functions.c
## Data: 2025-09-16 20:28:08
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\tests\test_multiple_functions.c
Tamanho: 399 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function add children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=3, exp=-1, name=int
DEBUG: Processing function multiply children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=3, exp=-1, name=int
DEBUG: Processing function calculate children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=sumresult
DEBUG: Child - node=0, stmt=2, exp=-1, name=multresult
DEBUG: Child - node=0, stmt=3, exp=-1, name=int
DEBUG: Processing function main children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=result
DEBUG: Child - node=0, stmt=10, exp=-1, name=output
(goto,main, , )
(fun,add, , )
(alloc,a,1, )
(alloc,b,1, )
(+,a,b,t0)
(ret,t0, , )
(endfun, , , )
(fun,multiply, , )
(alloc,x,1, )
(alloc,y,1, )
(*,x,y,t1)
(ret,t1, , )
(endfun, , , )
(fun,calculate, , )
(alloc,numa,1, )
(alloc,numb,1, )
(alloc,sumresult,1, )
(alloc,multresult,1, )
(param,numa, , )
(param,numb, , )
(call,add,numa,t2)
(asn,t2, ,sumresult)
(immed,2, ,t3)
(param,sumresult, , )
(param,t3, , )
(call,multiply,sumresult,t4)
(asn,t4, ,multresult)
(ret,multresult, , )
(endfun, , , )
(fun,main, , )
(alloc,result,1, )
(immed,3, ,t5)
(immed,7, ,t6)
(param,t5, , )
(param,t6, , )
(call,calculate,t5,t7)
(asn,t7, ,result)
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
Quadruplas lidas: 39
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=164
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'add' detectada com 2 parâmetros totais
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
DEBUG: Configurando função 'add' - salvando 2 parâmetros de registrador
DEBUG: Salvando 2 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[8]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[9]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Local offset configurado para 2 (baseado em 2 parâmetros)
DEBUG: Detectado parâmetro a na função add (param #1 de 2)
DEBUG: Parâmetro a registrado com offset 0 na função add
DEBUG: Detectado parâmetro b na função add (param #2 de 2)
DEBUG: Parâmetro b registrado com offset 1 na função add
DEBUG: load_variable_to_register('a', 'add')
DEBUG: get_register_for_variable('a', 'add')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 'a' -> R1
DEBUG: Variável 'a' -> R1 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[10]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R1, 0(R30)'

DEBUG: load_variable_to_register('b', 'add')
DEBUG: get_register_for_variable('b', 'add')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'b' -> R2
DEBUG: Variável 'b' -> R2 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[11]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R2, 1(R30)'

DEBUG: get_register_for_variable('t0', 'add')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't0' -> R3
ADD_INSTRUCTION[12]: ADD (op=0) rs=R1 rt=R2 rd=R3 imm=0
  ADD PREVIEW: Will output 'ADD R3, R1, R2'
DEBUG: load_variable_to_register('t0', 'add')
DEBUG: get_register_for_variable('t0', 'add')
DEBUG: Variável 't0' já em R3 (reutilizando)
DEBUG: Variável 't0' -> R3 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R3 -> R1)
DEBUG: Gerando MOVE R1, R3
ADD_INSTRUCTION[13]: MOVE (op=11) rs=R3 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[13]: rs=3, rt=0, rd=1 (Armazenado: rs=3, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[14]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[15]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[16]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[17]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'multiply' detectada com 2 parâmetros totais
DEBUG_RA: === INICIO PROLOGO FUNCAO ===
DEBUG_RA: Decrementando SP em 8 posicoes
ADD_INSTRUCTION[19]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=8
DEBUG_RA: Salvando RA no stack em posição relativa (SP+7)
ADD_INSTRUCTION[20]: SW (op=26) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'SW R31, 7(R29)'
DEBUG_RA: Salvando FP no stack em posição relativa (SP+6)
ADD_INSTRUCTION[21]: SW (op=26) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'SW R30, 6(R29)'
DEBUG_RA: Estabelecendo novo FP (SP+0)
ADD_INSTRUCTION[22]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[22]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG_RA: === FIM PROLOGO FUNCAO ===
DEBUG: Configurando função 'multiply' - salvando 2 parâmetros de registrador
DEBUG: Salvando 2 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[23]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[24]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Local offset configurado para 2 (baseado em 2 parâmetros)
DEBUG: Detectado parâmetro x na função multiply (param #1 de 2)
DEBUG: Parâmetro x registrado com offset 0 na função multiply
DEBUG: Detectado parâmetro y na função multiply (param #2 de 2)
DEBUG: Parâmetro y registrado com offset 1 na função multiply
DEBUG: load_variable_to_register('x', 'multiply')
DEBUG: get_register_for_variable('x', 'multiply')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 'x' -> R4
DEBUG: Variável 'x' -> R4 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[25]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R4, 0(R30)'

DEBUG: load_variable_to_register('y', 'multiply')
DEBUG: get_register_for_variable('y', 'multiply')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 'y' -> R5
DEBUG: Variável 'y' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[26]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: get_register_for_variable('t1', 'multiply')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't1' -> R6
ADD_INSTRUCTION[27]: MULT (op=2) rs=R4 rt=R5 rd=R6 imm=0
DEBUG: load_variable_to_register('t1', 'multiply')
DEBUG: get_register_for_variable('t1', 'multiply')
DEBUG: Variável 't1' já em R6 (reutilizando)
DEBUG: Variável 't1' -> R6 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R6 -> R1)
DEBUG: Gerando MOVE R1, R6
ADD_INSTRUCTION[28]: MOVE (op=11) rs=R6 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[28]: rs=6, rt=0, rd=1 (Armazenado: rs=6, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[29]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[30]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[31]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[32]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'calculate' detectada com 4 parâmetros totais
DEBUG_RA: === INICIO PROLOGO FUNCAO ===
DEBUG_RA: Decrementando SP em 8 posicoes
ADD_INSTRUCTION[34]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=8
DEBUG_RA: Salvando RA no stack em posição relativa (SP+7)
ADD_INSTRUCTION[35]: SW (op=26) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'SW R31, 7(R29)'
DEBUG_RA: Salvando FP no stack em posição relativa (SP+6)
ADD_INSTRUCTION[36]: SW (op=26) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'SW R30, 6(R29)'
DEBUG_RA: Estabelecendo novo FP (SP+0)
ADD_INSTRUCTION[37]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[37]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG_RA: === FIM PROLOGO FUNCAO ===
DEBUG: Configurando função 'calculate' - salvando 4 parâmetros de registrador
DEBUG: Salvando 4 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[38]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[39]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Salvando R6->offset 2
ADD_INSTRUCTION[40]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: Salvando R7->offset 3
ADD_INSTRUCTION[41]: SW (op=26) rs=R30 rt=R7 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R7, 3(R30)'
DEBUG: Local offset configurado para 4 (baseado em 4 parâmetros)
DEBUG: Detectado parâmetro numa na função calculate (param #1 de 4)
DEBUG: Parâmetro numa registrado com offset 0 na função calculate
DEBUG: Detectado parâmetro numb na função calculate (param #2 de 4)
DEBUG: Parâmetro numb registrado com offset 1 na função calculate
DEBUG: Detectado parâmetro sumresult na função calculate (param #3 de 4)
DEBUG: Parâmetro sumresult registrado com offset 2 na função calculate
DEBUG: Detectado parâmetro multresult na função calculate (param #4 de 4)
DEBUG: Parâmetro multresult registrado com offset 3 na função calculate
DEBUG: Passando parâmetro 0: 'numa'
DEBUG: load_variable_to_register('numa', 'calculate')
DEBUG: get_register_for_variable('numa', 'calculate')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 'numa' -> R7
DEBUG: Variável 'numa' -> R7 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[42]: LW (op=25) rs=R30 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R30)'

DEBUG: Parâmetro 0: 'numa' de R7 para R4 (forçado)
ADD_INSTRUCTION[43]: MOVE (op=11) rs=R7 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[43]: rs=7, rt=0, rd=4 (Armazenado: rs=7, rd=4)
DEBUG: Passando parâmetro 1: 'numb'
DEBUG: load_variable_to_register('numb', 'calculate')
DEBUG: get_register_for_variable('numb', 'calculate')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 'numb' -> R8
DEBUG: Variável 'numb' -> R8 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[44]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R8, 1(R30)'

DEBUG: Parâmetro 1: 'numb' de R8 para R5 (forçado)
ADD_INSTRUCTION[45]: MOVE (op=11) rs=R8 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[45]: rs=8, rt=0, rd=5 (Armazenado: rs=8, rd=5)
DEBUG: get_register_for_variable('t2', 'calculate')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't2' -> R9
DEBUG: add_move_if_different(R1 -> R9)
DEBUG: Gerando MOVE R9, R1
ADD_INSTRUCTION[47]: MOVE (op=11) rs=R1 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[47]: rs=1, rt=0, rd=9 (Armazenado: rs=1, rd=9)
DEBUG: load_variable_to_register('t2', 'calculate')
DEBUG: get_register_for_variable('t2', 'calculate')
DEBUG: Variável 't2' já em R9 (reutilizando)
DEBUG: Variável 't2' -> R9 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('sumresult', 'calculate')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 'sumresult' -> R10
DEBUG: add_move_if_different(R9 -> R10)
DEBUG: Gerando MOVE R10, R9
ADD_INSTRUCTION[48]: MOVE (op=11) rs=R9 rt=R0 rd=R10 imm=0
DEBUG: add_instruction MOVE[48]: rs=9, rt=0, rd=10 (Armazenado: rs=9, rd=10)
ADD_INSTRUCTION[49]: SW (op=26) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R10, 2(R30)'
DEBUG: get_register_for_variable('t3', 'calculate')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't3' -> R11
ADD_INSTRUCTION[50]: LI (op=27) rs=R0 rt=R11 rd=R0 imm=2
DEBUG: Passando parâmetro 0: 'sumresult'
DEBUG: load_variable_to_register('sumresult', 'calculate')
DEBUG: get_register_for_variable('sumresult', 'calculate')
DEBUG: Variável 'sumresult' já em R10 (reutilizando)
DEBUG: Variável 'sumresult' -> R10 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[51]: LW (op=25) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R10, 2(R30)'

DEBUG: Parâmetro 0: 'sumresult' de R10 para R4 (forçado)
ADD_INSTRUCTION[52]: MOVE (op=11) rs=R10 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[52]: rs=10, rt=0, rd=4 (Armazenado: rs=10, rd=4)
DEBUG: Passando parâmetro 1: 't3'
DEBUG: load_variable_to_register('t3', 'calculate')
DEBUG: get_register_for_variable('t3', 'calculate')
DEBUG: Variável 't3' já em R11 (reutilizando)
DEBUG: Variável 't3' -> R11 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 1: 't3' de R11 para R5 (forçado)
ADD_INSTRUCTION[53]: MOVE (op=11) rs=R11 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[53]: rs=11, rt=0, rd=5 (Armazenado: rs=11, rd=5)
DEBUG: get_register_for_variable('t4', 'calculate')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't4' -> R12
DEBUG: add_move_if_different(R1 -> R12)
DEBUG: Gerando MOVE R12, R1
ADD_INSTRUCTION[55]: MOVE (op=11) rs=R1 rt=R0 rd=R12 imm=0
DEBUG: add_instruction MOVE[55]: rs=1, rt=0, rd=12 (Armazenado: rs=1, rd=12)
DEBUG: load_variable_to_register('t4', 'calculate')
DEBUG: get_register_for_variable('t4', 'calculate')
DEBUG: Variável 't4' já em R12 (reutilizando)
DEBUG: Variável 't4' -> R12 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('multresult', 'calculate')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 'multresult' -> R13
DEBUG: add_move_if_different(R12 -> R13)
DEBUG: Gerando MOVE R13, R12
ADD_INSTRUCTION[56]: MOVE (op=11) rs=R12 rt=R0 rd=R13 imm=0
DEBUG: add_instruction MOVE[56]: rs=12, rt=0, rd=13 (Armazenado: rs=12, rd=13)
ADD_INSTRUCTION[57]: SW (op=26) rs=R30 rt=R13 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R13, 3(R30)'
DEBUG: load_variable_to_register('multresult', 'calculate')
DEBUG: get_register_for_variable('multresult', 'calculate')
DEBUG: Variável 'multresult' já em R13 (reutilizando)
DEBUG: Variável 'multresult' -> R13 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[58]: LW (op=25) rs=R30 rt=R13 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R13, 3(R30)'

DEBUG: add_move_if_different(R13 -> R1)
DEBUG: Gerando MOVE R1, R13
ADD_INSTRUCTION[59]: MOVE (op=11) rs=R13 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[59]: rs=13, rt=0, rd=1 (Armazenado: rs=13, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[60]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[61]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[62]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[63]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 1 parâmetros totais
ADD_INSTRUCTION[65]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[66]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[67]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[68]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[68]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro result na função main (param #1 de 1)
DEBUG: Parâmetro result registrado com offset 0 na função main
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 't5' -> R14
ADD_INSTRUCTION[69]: LI (op=27) rs=R0 rt=R14 rd=R0 imm=3
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't6' -> R15
ADD_INSTRUCTION[70]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=7
DEBUG: Passando parâmetro 0: 't5'
DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R14 (reutilizando)
DEBUG: Variável 't5' -> R14 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 0: 't5' de R14 para R4 (forçado)
ADD_INSTRUCTION[71]: MOVE (op=11) rs=R14 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[71]: rs=14, rt=0, rd=4 (Armazenado: rs=14, rd=4)
DEBUG: Passando parâmetro 1: 't6'
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R15 (reutilizando)
DEBUG: Variável 't6' -> R15 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 1: 't6' de R15 para R5 (forçado)
ADD_INSTRUCTION[72]: MOVE (op=11) rs=R15 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[72]: rs=15, rt=0, rd=5 (Armazenado: rs=15, rd=5)
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 't7' -> R16
DEBUG: add_move_if_different(R1 -> R16)
DEBUG: Gerando MOVE R16, R1
ADD_INSTRUCTION[74]: MOVE (op=11) rs=R1 rt=R0 rd=R16 imm=0
DEBUG: add_instruction MOVE[74]: rs=1, rt=0, rd=16 (Armazenado: rs=1, rd=16)
ADD_INSTRUCTION[75]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[75]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('t7', 'main')
DEBUG: get_register_for_variable('t7', 'main')
DEBUG: Variável 't7' já em R16 (reutilizando)
DEBUG: Variável 't7' -> R16 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('result', 'main')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 'result' -> R17
DEBUG: add_move_if_different(R16 -> R17)
DEBUG: Gerando MOVE R17, R16
ADD_INSTRUCTION[76]: MOVE (op=11) rs=R16 rt=R0 rd=R17 imm=0
DEBUG: add_instruction MOVE[76]: rs=16, rt=0, rd=17 (Armazenado: rs=16, rd=17)
ADD_INSTRUCTION[77]: SW (op=26) rs=R30 rt=R17 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R17, 0(R30)'
DEBUG: load_variable_to_register('result', 'main')
DEBUG: get_register_for_variable('result', 'main')
DEBUG: Variável 'result' já em R17 (reutilizando)
DEBUG: Variável 'result' -> R17 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[78]: LW (op=25) rs=R30 rt=R17 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R17, 0(R30)'

ADD_INSTRUCTION[79]: OUTPUTREG (op=32) rs=R17 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[80]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 39
Instruções geradas: 81
Labels: 4
Símbolos: 9
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
a               add             0       Não    Sim     Não    1      
b               add             1       Não    Sim     Não    1      
x               multiply        0       Não    Sim     Não    1      
y               multiply        1       Não    Sim     Não    1      
numa            calculate       0       Não    Sim     Não    1      
numb            calculate       1       Não    Sim     Não    1      
sumresult       calculate       2       Não    Sim     Não    1      
multresult      calculate       3       Não    Sim     Não    1      
result          main            0       Não    Sim     Não    1      
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
Entradas: [6, 7]
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
