# Relatório de Compilação - fibonacci.c
## Data: 2025-12-02 17:12:37
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\fibonacci.c
Tamanho: 222 bytes

### 🔧 Compilação C-Minus
```
ERRO LEXICO: '' INVALIDO [linha: 14, coluna: 0]
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function fibonacci children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
(goto,main, , )
(fun,fibonacci, , )
(alloc,n,1, )
(immed,1, ,t0)
(ble,n,t0,L0)
(immed,1, ,t1)
(-,n,t1,t2)
(param,t2, , )
(call,fibonacci,t2,t3)
(immed,2, ,t4)
(-,n,t4,t5)
(param,t5, , )
(call,fibonacci,t5,t6)
(+,t3,t6,t7)
(ret,t7, , )
(goto,L1, , )
(label,L0, , )
(ret,n, , )
(label,L1, , )
(endfun, , , )
(fun,main, , )
(alloc,n,1, )
(input, , ,t8)
(asn,t8, ,n)
(param,n, , )
(call,fibonacci,n,t9)
(output,t9,0, )
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
ADD_INSTRUCTION[3]: ADD (op=0) rs=R0 rt=R0 rd=R0 imm=0
  ADD PREVIEW: Will output 'ADD R0, R0, R0'
DEBUG: Função 'fibonacci' detectada com 1 parâmetros totais
DEBUG_RA: === INICIO PROLOGO FUNCAO ===
DEBUG_RA: Decrementando SP em 8 posicoes
ADD_INSTRUCTION[7]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=8
DEBUG_RA: Salvando RA no stack em posição relativa (SP+7)
ADD_INSTRUCTION[8]: SW (op=26) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'SW R31, 7(R29)'
DEBUG_RA: Salvando FP no stack em posição relativa (SP+6)
ADD_INSTRUCTION[9]: SW (op=26) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'SW R30, 6(R29)'
DEBUG_RA: Estabelecendo novo FP (SP+0)
ADD_INSTRUCTION[10]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[10]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG_RA: === FIM PROLOGO FUNCAO ===
DEBUG: Configurando função 'fibonacci' - salvando 1 parâmetros de registrador
DEBUG: Salvando 1 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[11]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Local offset configurado para 1 (baseado em 1 parâmetros)
DEBUG: Detectado parâmetro n na função fibonacci (param #1 de 1)
DEBUG: Parâmetro n registrado com offset 0 na função fibonacci
DEBUG: get_register_for_variable('t0', 'fibonacci')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[12]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=1
DEBUG: load_variable_to_register('n', 'fibonacci')
DEBUG: get_register_for_variable('n', 'fibonacci')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'n' -> R2
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[13]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t0', 'fibonacci')
DEBUG: get_register_for_variable('t0', 'fibonacci')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t1', 'fibonacci')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[15]: LI (op=27) rs=R0 rt=R3 rd=R0 imm=1
DEBUG: load_variable_to_register('n', 'fibonacci')
DEBUG: get_register_for_variable('n', 'fibonacci')
DEBUG: Variável 'n' já em R2 (reutilizando)
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[16]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t1', 'fibonacci')
DEBUG: get_register_for_variable('t1', 'fibonacci')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t2', 'fibonacci')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 't2' -> R4
ADD_INSTRUCTION[17]: SUB (op=1) rs=R2 rt=R3 rd=R4 imm=0
DEBUG: Passando parâmetro 0: 't2'
DEBUG: load_variable_to_register('t2', 'fibonacci')
DEBUG: get_register_for_variable('t2', 'fibonacci')
DEBUG: Variável 't2' já em R4 (reutilizando)
DEBUG: Variável 't2' -> R4 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 0: 't2' de R4 para R4 (forçado)
ADD_INSTRUCTION[18]: MOVE (op=11) rs=R4 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[18]: rs=4, rt=0, rd=4 (Armazenado: rs=4, rd=4)
DEBUG: Salvando R2 (contém 'n') antes da chamada
ADD_INSTRUCTION[19]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[20]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 't1') antes da chamada
ADD_INSTRUCTION[21]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[22]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
ADD_INSTRUCTION[23]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[25]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=2
  ADDI PREVIEW: Will output 'ADDI R29, R29, 2'
DEBUG: Restaurando R3 (contém 't1') após a chamada
ADD_INSTRUCTION[26]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[27]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'n') após a chamada
ADD_INSTRUCTION[28]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[29]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t3', 'fibonacci')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't3' -> R5
DEBUG: add_move_if_different(R1 -> R5)
DEBUG: Gerando MOVE R5, R1
ADD_INSTRUCTION[30]: MOVE (op=11) rs=R1 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[30]: rs=1, rt=0, rd=5 (Armazenado: rs=1, rd=5)
DEBUG: get_register_for_variable('t4', 'fibonacci')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't4' -> R6
ADD_INSTRUCTION[31]: LI (op=27) rs=R0 rt=R6 rd=R0 imm=2
DEBUG: load_variable_to_register('n', 'fibonacci')
DEBUG: get_register_for_variable('n', 'fibonacci')
DEBUG: Variável 'n' já em R2 (reutilizando)
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[32]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t4', 'fibonacci')
DEBUG: get_register_for_variable('t4', 'fibonacci')
DEBUG: Variável 't4' já em R6 (reutilizando)
DEBUG: Variável 't4' -> R6 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t5', 'fibonacci')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't5' -> R7
ADD_INSTRUCTION[33]: SUB (op=1) rs=R2 rt=R6 rd=R7 imm=0
DEBUG: Passando parâmetro 0: 't5'
DEBUG: load_variable_to_register('t5', 'fibonacci')
DEBUG: get_register_for_variable('t5', 'fibonacci')
DEBUG: Variável 't5' já em R7 (reutilizando)
DEBUG: Variável 't5' -> R7 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 0: 't5' de R7 para R4 (forçado)
ADD_INSTRUCTION[34]: MOVE (op=11) rs=R7 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[34]: rs=7, rt=0, rd=4 (Armazenado: rs=7, rd=4)
DEBUG: Salvando R2 (contém 'n') antes da chamada
ADD_INSTRUCTION[35]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[36]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 't1') antes da chamada
ADD_INSTRUCTION[37]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[38]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
DEBUG: Salvando R5 (contém 't3') antes da chamada
ADD_INSTRUCTION[39]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[40]: SW (op=26) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R2)'
DEBUG: Salvando R6 (contém 't4') antes da chamada
ADD_INSTRUCTION[41]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[42]: SW (op=26) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R2)'
DEBUG: Salvando R7 (contém 't5') antes da chamada
ADD_INSTRUCTION[43]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[44]: SW (op=26) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R2)'
ADD_INSTRUCTION[45]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=5
ADD_INSTRUCTION[47]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=5
  ADDI PREVIEW: Will output 'ADDI R29, R29, 5'
DEBUG: Restaurando R7 (contém 't5') após a chamada
ADD_INSTRUCTION[48]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[49]: LW (op=25) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R2)'
DEBUG: Restaurando R6 (contém 't4') após a chamada
ADD_INSTRUCTION[50]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[51]: LW (op=25) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R6, 0(R2)'
DEBUG: Restaurando R5 (contém 't3') após a chamada
ADD_INSTRUCTION[52]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[53]: LW (op=25) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R2)'
DEBUG: Restaurando R3 (contém 't1') após a chamada
ADD_INSTRUCTION[54]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[55]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'n') após a chamada
ADD_INSTRUCTION[56]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[57]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t6', 'fibonacci')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't6' -> R8
DEBUG: add_move_if_different(R1 -> R8)
DEBUG: Gerando MOVE R8, R1
ADD_INSTRUCTION[58]: MOVE (op=11) rs=R1 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[58]: rs=1, rt=0, rd=8 (Armazenado: rs=1, rd=8)
DEBUG: load_variable_to_register('t3', 'fibonacci')
DEBUG: get_register_for_variable('t3', 'fibonacci')
DEBUG: Variável 't3' já em R5 (reutilizando)
DEBUG: Variável 't3' -> R5 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('t6', 'fibonacci')
DEBUG: get_register_for_variable('t6', 'fibonacci')
DEBUG: Variável 't6' já em R8 (reutilizando)
DEBUG: Variável 't6' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t7', 'fibonacci')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't7' -> R9
ADD_INSTRUCTION[59]: ADD (op=0) rs=R5 rt=R8 rd=R9 imm=0
  ADD PREVIEW: Will output 'ADD R9, R5, R8'
DEBUG: load_variable_to_register('t7', 'fibonacci')
DEBUG: get_register_for_variable('t7', 'fibonacci')
DEBUG: Variável 't7' já em R9 (reutilizando)
DEBUG: Variável 't7' -> R9 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R9 -> R1)
DEBUG: Gerando MOVE R1, R9
ADD_INSTRUCTION[60]: MOVE (op=11) rs=R9 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[60]: rs=9, rt=0, rd=1 (Armazenado: rs=9, rd=1)
DEBUG: load_variable_to_register('n', 'fibonacci')
DEBUG: get_register_for_variable('n', 'fibonacci')
DEBUG: Variável 'n' já em R2 (reutilizando)
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[64]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: add_move_if_different(R2 -> R1)
DEBUG: Gerando MOVE R1, R2
ADD_INSTRUCTION[65]: MOVE (op=11) rs=R2 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[65]: rs=2, rt=0, rd=1 (Armazenado: rs=2, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[69]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[70]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[71]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[72]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 1 parâmetros totais
ADD_INSTRUCTION[74]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[75]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[76]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[77]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[77]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro n na função main (param #1 de 1)
DEBUG: Parâmetro n registrado com offset 0 na função main
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't8' -> R10
ADD_INSTRUCTION[78]: INPUT (op=34) rs=R0 rt=R0 rd=R10 imm=0
ADD_INSTRUCTION[79]: OUTPUTREG (op=32) rs=R10 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t8', 'main')
DEBUG: get_register_for_variable('t8', 'main')
DEBUG: Variável 't8' já em R10 (reutilizando)
DEBUG: Variável 't8' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('n', 'main')
DEBUG: Variável 'n' já em R2 (reutilizando)
DEBUG: add_move_if_different(R10 -> R2)
DEBUG: Gerando MOVE R2, R10
ADD_INSTRUCTION[80]: MOVE (op=11) rs=R10 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[80]: rs=10, rt=0, rd=2 (Armazenado: rs=10, rd=2)
ADD_INSTRUCTION[81]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: Passando parâmetro 0: 'n'
DEBUG: load_variable_to_register('n', 'main')
DEBUG: get_register_for_variable('n', 'main')
DEBUG: Variável 'n' já em R2 (reutilizando)
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[82]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: Parâmetro 0: 'n' de R2 para R4 (forçado)
ADD_INSTRUCTION[83]: MOVE (op=11) rs=R2 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[83]: rs=2, rt=0, rd=4 (Armazenado: rs=2, rd=4)
DEBUG: Salvando R2 (contém 'n') antes da chamada
ADD_INSTRUCTION[84]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[85]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 't1') antes da chamada
ADD_INSTRUCTION[86]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[87]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
DEBUG: Salvando R5 (contém 't3') antes da chamada
ADD_INSTRUCTION[88]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[89]: SW (op=26) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R2)'
DEBUG: Salvando R6 (contém 't4') antes da chamada
ADD_INSTRUCTION[90]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[91]: SW (op=26) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R2)'
DEBUG: Salvando R7 (contém 't5') antes da chamada
ADD_INSTRUCTION[92]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[93]: SW (op=26) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R2)'
DEBUG: Salvando R8 (contém 't6') antes da chamada
ADD_INSTRUCTION[94]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[95]: SW (op=26) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R2)'
DEBUG: Salvando R9 (contém 't7') antes da chamada
ADD_INSTRUCTION[96]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[97]: SW (op=26) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R2)'
DEBUG: Salvando R10 (contém 't8') antes da chamada
ADD_INSTRUCTION[98]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[99]: SW (op=26) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R10, 0(R2)'
ADD_INSTRUCTION[100]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=8
ADD_INSTRUCTION[102]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG: Restaurando R10 (contém 't8') após a chamada
ADD_INSTRUCTION[103]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[104]: LW (op=25) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R10, 0(R2)'
DEBUG: Restaurando R9 (contém 't7') após a chamada
ADD_INSTRUCTION[105]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[106]: LW (op=25) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R2)'
DEBUG: Restaurando R8 (contém 't6') após a chamada
ADD_INSTRUCTION[107]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[108]: LW (op=25) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R2)'
DEBUG: Restaurando R7 (contém 't5') após a chamada
ADD_INSTRUCTION[109]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[110]: LW (op=25) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R2)'
DEBUG: Restaurando R6 (contém 't4') após a chamada
ADD_INSTRUCTION[111]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[112]: LW (op=25) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R6, 0(R2)'
DEBUG: Restaurando R5 (contém 't3') após a chamada
ADD_INSTRUCTION[113]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[114]: LW (op=25) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R2)'
DEBUG: Restaurando R3 (contém 't1') após a chamada
ADD_INSTRUCTION[115]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[116]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'n') após a chamada
ADD_INSTRUCTION[117]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[118]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't9' -> R11
DEBUG: add_move_if_different(R1 -> R11)
DEBUG: Gerando MOVE R11, R1
ADD_INSTRUCTION[119]: MOVE (op=11) rs=R1 rt=R0 rd=R11 imm=0
DEBUG: add_instruction MOVE[119]: rs=1, rt=0, rd=11 (Armazenado: rs=1, rd=11)
ADD_INSTRUCTION[120]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[120]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('t9', 'main')
DEBUG: get_register_for_variable('t9', 'main')
DEBUG: Variável 't9' já em R11 (reutilizando)
DEBUG: Variável 't9' -> R11 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[121]: OUTPUTREG (op=32) rs=R11 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[122]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 28
Instruções geradas: 123
Labels: 5
Símbolos: 2
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
n               fibonacci       0       Não    Sim     Não    1      
n               main            0       Não    Sim     Não    1      
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
