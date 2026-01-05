# Relatório de Compilação - primes.c
## Data: 2025-10-04 00:55:58
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\primes.c
Tamanho: 531 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function isPrime children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
(goto,main, , )
(fun,isPrime, , )
(alloc,n,1, )
(alloc,i,1, )
(alloc,j,1, )
(alloc,k,1, )
(alloc,remainder,1, )
(immed,1, ,t0)
(bgt,n,t0,L0)
(immed,0, ,t1)
(ret,t1, , )
(goto,L1, , )
(label,L0, , )
(label,L1, , )
(immed,2, ,t2)
(asn,t2, ,i)
(*,i,i,t3)
(asn,t3, ,k)
(label,L2, , )
(<=,k,n,t4)
(if_f,t4,L3, )
(immed,0, ,t5)
(asn,t5, ,j)
(label,L4, , )
(<=,j,n,t6)
(if_f,t6,L5, )
(+,j,i,t7)
(asn,t7, ,j)
(goto,L4, , )
(label,L5, , )
(+,n,i,t8)
(bne,j,t8,L6)
(immed,0, ,t9)
(ret,t9, , )
(goto,L7, , )
(label,L6, , )
(label,L7, , )
(immed,1, ,t10)
(+,i,t10,t11)
(asn,t11, ,i)
(*,i,i,t12)
(asn,t12, ,k)
(goto,L2, , )
(label,L3, , )
(immed,1, ,t13)
(ret,t13, , )
(endfun, , , )
(fun,main, , )
(alloc,number,1, )
(alloc,result,1, )
(input, , ,t14)
(asn,t14, ,number)
(param,number, , )
(call,isPrime,number,t15)
(asn,t15, ,result)
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
Quadruplas lidas: 57
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'isPrime' detectada com 5 parâmetros totais
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
DEBUG: Configurando função 'isPrime' - salvando 5 parâmetros de registrador
DEBUG: Salvando 5 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[8]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[9]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Salvando R6->offset 2
ADD_INSTRUCTION[10]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: Salvando R7->offset 3
ADD_INSTRUCTION[11]: SW (op=26) rs=R30 rt=R7 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R7, 3(R30)'
DEBUG: Local offset configurado para 5 (baseado em 5 parâmetros)
DEBUG: Detectado parâmetro n na função isPrime (param #1 de 5)
DEBUG: Parâmetro n registrado com offset 0 na função isPrime
DEBUG: Detectado parâmetro i na função isPrime (param #2 de 5)
DEBUG: Parâmetro i registrado com offset 1 na função isPrime
DEBUG: Detectado parâmetro j na função isPrime (param #3 de 5)
DEBUG: Parâmetro j registrado com offset 2 na função isPrime
DEBUG: Detectado parâmetro k na função isPrime (param #4 de 5)
DEBUG: Parâmetro k registrado com offset 3 na função isPrime
DEBUG: Detectado parâmetro remainder na função isPrime (param #5 de 5)
DEBUG: Parâmetro remainder registrado com offset 4 na função isPrime
DEBUG: get_register_for_variable('t0', 'isPrime')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[12]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=1
DEBUG: load_variable_to_register('n', 'isPrime')
DEBUG: get_register_for_variable('n', 'isPrime')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'n' -> R2
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[13]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('t0', 'isPrime')
DEBUG: get_register_for_variable('t0', 'isPrime')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t1', 'isPrime')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[15]: LI (op=27) rs=R0 rt=R3 rd=R0 imm=0
DEBUG: load_variable_to_register('t1', 'isPrime')
DEBUG: get_register_for_variable('t1', 'isPrime')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R3 -> R1)
DEBUG: Gerando MOVE R1, R3
ADD_INSTRUCTION[16]: MOVE (op=11) rs=R3 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[16]: rs=3, rt=0, rd=1 (Armazenado: rs=3, rd=1)
DEBUG: get_register_for_variable('t2', 'isPrime')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 't2' -> R4
ADD_INSTRUCTION[21]: LI (op=27) rs=R0 rt=R4 rd=R0 imm=2
DEBUG: load_variable_to_register('t2', 'isPrime')
DEBUG: get_register_for_variable('t2', 'isPrime')
DEBUG: Variável 't2' já em R4 (reutilizando)
DEBUG: Variável 't2' -> R4 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 'i' -> R5
DEBUG: add_move_if_different(R4 -> R5)
DEBUG: Gerando MOVE R5, R4
ADD_INSTRUCTION[22]: MOVE (op=11) rs=R4 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[22]: rs=4, rt=0, rd=5 (Armazenado: rs=4, rd=5)
ADD_INSTRUCTION[23]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: load_variable_to_register('i', 'isPrime')
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Variável 'i' já em R5 (reutilizando)
DEBUG: Variável 'i' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[24]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: load_variable_to_register('i', 'isPrime')
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Variável 'i' já em R5 (reutilizando)
DEBUG: Variável 'i' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[25]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: get_register_for_variable('t3', 'isPrime')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't3' -> R6
ADD_INSTRUCTION[26]: MULT (op=2) rs=R5 rt=R5 rd=R6 imm=0
DEBUG: load_variable_to_register('t3', 'isPrime')
DEBUG: get_register_for_variable('t3', 'isPrime')
DEBUG: Variável 't3' já em R6 (reutilizando)
DEBUG: Variável 't3' -> R6 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('k', 'isPrime')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 'k' -> R7
DEBUG: add_move_if_different(R6 -> R7)
DEBUG: Gerando MOVE R7, R6
ADD_INSTRUCTION[27]: MOVE (op=11) rs=R6 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[27]: rs=6, rt=0, rd=7 (Armazenado: rs=6, rd=7)
ADD_INSTRUCTION[28]: SW (op=26) rs=R30 rt=R7 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R7, 3(R30)'
DEBUG: Processando comparação '<=' entre 'k' e 'n' -> 't4'
DEBUG: load_variable_to_register('k', 'isPrime')
DEBUG: get_register_for_variable('k', 'isPrime')
DEBUG: Variável 'k' já em R7 (reutilizando)
DEBUG: Variável 'k' -> R7 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[30]: LW (op=25) rs=R30 rt=R7 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R7, 3(R30)'

DEBUG: load_variable_to_register('n', 'isPrime')
DEBUG: get_register_for_variable('n', 'isPrime')
DEBUG: Variável 'n' já em R2 (reutilizando)
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[31]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: get_register_for_variable('t4', 'isPrime')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't4' -> R8
DEBUG: Registradores: 'k'->R7, 'n'->R2, resultado->R8
ADD_INSTRUCTION[32]: SLT (op=8) rs=R2 rt=R7 rd=R8 imm=0
DEBUG: SLT R8, R2, R7 (rt < rs, ou seja, rs > rt)
ADD_INSTRUCTION[33]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=1
ADD_INSTRUCTION[34]: SUB (op=1) rs=R1 rt=R8 rd=R8 imm=0
DEBUG: Resultado <= invertido: R8 = 1 - R8
DEBUG: load_variable_to_register('t4', 'isPrime')
DEBUG: get_register_for_variable('t4', 'isPrime')
DEBUG: Variável 't4' já em R8 (reutilizando)
DEBUG: Variável 't4' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t5', 'isPrime')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't5' -> R9
ADD_INSTRUCTION[36]: LI (op=27) rs=R0 rt=R9 rd=R0 imm=0
DEBUG: load_variable_to_register('t5', 'isPrime')
DEBUG: get_register_for_variable('t5', 'isPrime')
DEBUG: Variável 't5' já em R9 (reutilizando)
DEBUG: Variável 't5' -> R9 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('j', 'isPrime')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 'j' -> R10
DEBUG: add_move_if_different(R9 -> R10)
DEBUG: Gerando MOVE R10, R9
ADD_INSTRUCTION[37]: MOVE (op=11) rs=R9 rt=R0 rd=R10 imm=0
DEBUG: add_instruction MOVE[37]: rs=9, rt=0, rd=10 (Armazenado: rs=9, rd=10)
ADD_INSTRUCTION[38]: SW (op=26) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R10, 2(R30)'
DEBUG: Processando comparação '<=' entre 'j' e 'n' -> 't6'
DEBUG: load_variable_to_register('j', 'isPrime')
DEBUG: get_register_for_variable('j', 'isPrime')
DEBUG: Variável 'j' já em R10 (reutilizando)
DEBUG: Variável 'j' -> R10 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[40]: LW (op=25) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R10, 2(R30)'

DEBUG: load_variable_to_register('n', 'isPrime')
DEBUG: get_register_for_variable('n', 'isPrime')
DEBUG: Variável 'n' já em R2 (reutilizando)
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[41]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: get_register_for_variable('t6', 'isPrime')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't6' -> R11
DEBUG: Registradores: 'j'->R10, 'n'->R2, resultado->R11
ADD_INSTRUCTION[42]: SLT (op=8) rs=R2 rt=R10 rd=R11 imm=0
DEBUG: SLT R11, R2, R10 (rt < rs, ou seja, rs > rt)
ADD_INSTRUCTION[43]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=1
ADD_INSTRUCTION[44]: SUB (op=1) rs=R1 rt=R11 rd=R11 imm=0
DEBUG: Resultado <= invertido: R11 = 1 - R11
DEBUG: load_variable_to_register('t6', 'isPrime')
DEBUG: get_register_for_variable('t6', 'isPrime')
DEBUG: Variável 't6' já em R11 (reutilizando)
DEBUG: Variável 't6' -> R11 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('j', 'isPrime')
DEBUG: get_register_for_variable('j', 'isPrime')
DEBUG: Variável 'j' já em R10 (reutilizando)
DEBUG: Variável 'j' -> R10 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[46]: LW (op=25) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R10, 2(R30)'

DEBUG: load_variable_to_register('i', 'isPrime')
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Variável 'i' já em R5 (reutilizando)
DEBUG: Variável 'i' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[47]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: get_register_for_variable('t7', 'isPrime')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't7' -> R12
ADD_INSTRUCTION[48]: ADD (op=0) rs=R10 rt=R5 rd=R12 imm=0
  ADD PREVIEW: Will output 'ADD R12, R10, R5'
DEBUG: load_variable_to_register('t7', 'isPrime')
DEBUG: get_register_for_variable('t7', 'isPrime')
DEBUG: Variável 't7' já em R12 (reutilizando)
DEBUG: Variável 't7' -> R12 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('j', 'isPrime')
DEBUG: Variável 'j' já em R10 (reutilizando)
DEBUG: add_move_if_different(R12 -> R10)
DEBUG: Gerando MOVE R10, R12
ADD_INSTRUCTION[49]: MOVE (op=11) rs=R12 rt=R0 rd=R10 imm=0
DEBUG: add_instruction MOVE[49]: rs=12, rt=0, rd=10 (Armazenado: rs=12, rd=10)
ADD_INSTRUCTION[50]: SW (op=26) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R10, 2(R30)'
DEBUG: load_variable_to_register('n', 'isPrime')
DEBUG: get_register_for_variable('n', 'isPrime')
DEBUG: Variável 'n' já em R2 (reutilizando)
DEBUG: Variável 'n' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[53]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('i', 'isPrime')
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Variável 'i' já em R5 (reutilizando)
DEBUG: Variável 'i' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[54]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: get_register_for_variable('t8', 'isPrime')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 't8' -> R13
ADD_INSTRUCTION[55]: ADD (op=0) rs=R2 rt=R5 rd=R13 imm=0
  ADD PREVIEW: Will output 'ADD R13, R2, R5'
DEBUG: load_variable_to_register('j', 'isPrime')
DEBUG: get_register_for_variable('j', 'isPrime')
DEBUG: Variável 'j' já em R10 (reutilizando)
DEBUG: Variável 'j' -> R10 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[56]: LW (op=25) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R10, 2(R30)'

DEBUG: load_variable_to_register('t8', 'isPrime')
DEBUG: get_register_for_variable('t8', 'isPrime')
DEBUG: Variável 't8' já em R13 (reutilizando)
DEBUG: Variável 't8' -> R13 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t9', 'isPrime')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 't9' -> R14
ADD_INSTRUCTION[58]: LI (op=27) rs=R0 rt=R14 rd=R0 imm=0
DEBUG: load_variable_to_register('t9', 'isPrime')
DEBUG: get_register_for_variable('t9', 'isPrime')
DEBUG: Variável 't9' já em R14 (reutilizando)
DEBUG: Variável 't9' -> R14 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R14 -> R1)
DEBUG: Gerando MOVE R1, R14
ADD_INSTRUCTION[59]: MOVE (op=11) rs=R14 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[59]: rs=14, rt=0, rd=1 (Armazenado: rs=14, rd=1)
DEBUG: get_register_for_variable('t10', 'isPrime')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't10' -> R15
ADD_INSTRUCTION[64]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'isPrime')
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Variável 'i' já em R5 (reutilizando)
DEBUG: Variável 'i' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[65]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: load_variable_to_register('t10', 'isPrime')
DEBUG: get_register_for_variable('t10', 'isPrime')
DEBUG: Variável 't10' já em R15 (reutilizando)
DEBUG: Variável 't10' -> R15 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t11', 'isPrime')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 't11' -> R16
ADD_INSTRUCTION[66]: ADD (op=0) rs=R5 rt=R15 rd=R16 imm=0
  ADD PREVIEW: Will output 'ADD R16, R5, R15'
DEBUG: load_variable_to_register('t11', 'isPrime')
DEBUG: get_register_for_variable('t11', 'isPrime')
DEBUG: Variável 't11' já em R16 (reutilizando)
DEBUG: Variável 't11' -> R16 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Variável 'i' já em R5 (reutilizando)
DEBUG: add_move_if_different(R16 -> R5)
DEBUG: Gerando MOVE R5, R16
ADD_INSTRUCTION[67]: MOVE (op=11) rs=R16 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[67]: rs=16, rt=0, rd=5 (Armazenado: rs=16, rd=5)
ADD_INSTRUCTION[68]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: load_variable_to_register('i', 'isPrime')
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Variável 'i' já em R5 (reutilizando)
DEBUG: Variável 'i' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[69]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: load_variable_to_register('i', 'isPrime')
DEBUG: get_register_for_variable('i', 'isPrime')
DEBUG: Variável 'i' já em R5 (reutilizando)
DEBUG: Variável 'i' -> R5 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[70]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R5, 1(R30)'

DEBUG: get_register_for_variable('t12', 'isPrime')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 't12' -> R17
ADD_INSTRUCTION[71]: MULT (op=2) rs=R5 rt=R5 rd=R17 imm=0
DEBUG: load_variable_to_register('t12', 'isPrime')
DEBUG: get_register_for_variable('t12', 'isPrime')
DEBUG: Variável 't12' já em R17 (reutilizando)
DEBUG: Variável 't12' -> R17 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('k', 'isPrime')
DEBUG: Variável 'k' já em R7 (reutilizando)
DEBUG: add_move_if_different(R17 -> R7)
DEBUG: Gerando MOVE R7, R17
ADD_INSTRUCTION[72]: MOVE (op=11) rs=R17 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[72]: rs=17, rt=0, rd=7 (Armazenado: rs=17, rd=7)
ADD_INSTRUCTION[73]: SW (op=26) rs=R30 rt=R7 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R7, 3(R30)'
DEBUG: get_register_for_variable('t13', 'isPrime')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 't13' -> R18
ADD_INSTRUCTION[76]: LI (op=27) rs=R0 rt=R18 rd=R0 imm=1
DEBUG: load_variable_to_register('t13', 'isPrime')
DEBUG: get_register_for_variable('t13', 'isPrime')
DEBUG: Variável 't13' já em R18 (reutilizando)
DEBUG: Variável 't13' -> R18 (símbolo NÃO encontrado!)
DEBUG: add_move_if_different(R18 -> R1)
DEBUG: Gerando MOVE R1, R18
ADD_INSTRUCTION[77]: MOVE (op=11) rs=R18 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[77]: rs=18, rt=0, rd=1 (Armazenado: rs=18, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[80]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[81]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[82]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[83]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 2 parâmetros totais
ADD_INSTRUCTION[85]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[86]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[87]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[88]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[88]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro number na função main (param #1 de 2)
DEBUG: Parâmetro number registrado com offset 0 na função main
DEBUG: Detectado parâmetro result na função main (param #2 de 2)
DEBUG: Parâmetro result registrado com offset 1 na função main
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 't14' -> R19
ADD_INSTRUCTION[89]: INPUT (op=34) rs=R0 rt=R0 rd=R19 imm=0
ADD_INSTRUCTION[90]: OUTPUTREG (op=32) rs=R19 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t14', 'main')
DEBUG: get_register_for_variable('t14', 'main')
DEBUG: Variável 't14' já em R19 (reutilizando)
DEBUG: Variável 't14' -> R19 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('number', 'main')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 'number' -> R20
DEBUG: add_move_if_different(R19 -> R20)
DEBUG: Gerando MOVE R20, R19
ADD_INSTRUCTION[91]: MOVE (op=11) rs=R19 rt=R0 rd=R20 imm=0
DEBUG: add_instruction MOVE[91]: rs=19, rt=0, rd=20 (Armazenado: rs=19, rd=20)
ADD_INSTRUCTION[92]: SW (op=26) rs=R30 rt=R20 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R20, 0(R30)'
DEBUG: Passando parâmetro 0: 'number'
DEBUG: load_variable_to_register('number', 'main')
DEBUG: get_register_for_variable('number', 'main')
DEBUG: Variável 'number' já em R20 (reutilizando)
DEBUG: Variável 'number' -> R20 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[93]: LW (op=25) rs=R30 rt=R20 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R20, 0(R30)'

DEBUG: Parâmetro 0: 'number' de R20 para R4 (forçado)
ADD_INSTRUCTION[94]: MOVE (op=11) rs=R20 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[94]: rs=20, rt=0, rd=4 (Armazenado: rs=20, rd=4)
DEBUG: Salvando R2 (contém 'n') antes da chamada
ADD_INSTRUCTION[95]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[96]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 't1') antes da chamada
ADD_INSTRUCTION[97]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[98]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
DEBUG: Salvando R5 (contém 'i') antes da chamada
ADD_INSTRUCTION[99]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[100]: SW (op=26) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R2)'
DEBUG: Salvando R6 (contém 't3') antes da chamada
ADD_INSTRUCTION[101]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[102]: SW (op=26) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R2)'
DEBUG: Salvando R7 (contém 'k') antes da chamada
ADD_INSTRUCTION[103]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[104]: SW (op=26) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R2)'
DEBUG: Salvando R8 (contém 't4') antes da chamada
ADD_INSTRUCTION[105]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[106]: SW (op=26) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R2)'
DEBUG: Salvando R9 (contém 't5') antes da chamada
ADD_INSTRUCTION[107]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[108]: SW (op=26) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R2)'
DEBUG: Salvando R10 (contém 'j') antes da chamada
ADD_INSTRUCTION[109]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[110]: SW (op=26) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R10, 0(R2)'
DEBUG: Salvando R11 (contém 't6') antes da chamada
ADD_INSTRUCTION[111]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=9
ADD_INSTRUCTION[112]: SW (op=26) rs=R2 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R11, 0(R2)'
DEBUG: Salvando R12 (contém 't7') antes da chamada
ADD_INSTRUCTION[113]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=10
ADD_INSTRUCTION[114]: SW (op=26) rs=R2 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R12, 0(R2)'
DEBUG: Salvando R13 (contém 't8') antes da chamada
ADD_INSTRUCTION[115]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=11
ADD_INSTRUCTION[116]: SW (op=26) rs=R2 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R13, 0(R2)'
DEBUG: Salvando R14 (contém 't9') antes da chamada
ADD_INSTRUCTION[117]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=12
ADD_INSTRUCTION[118]: SW (op=26) rs=R2 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R14, 0(R2)'
DEBUG: Salvando R15 (contém 't10') antes da chamada
ADD_INSTRUCTION[119]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=13
ADD_INSTRUCTION[120]: SW (op=26) rs=R2 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R15, 0(R2)'
ADD_INSTRUCTION[121]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=13
ADD_INSTRUCTION[123]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=13
  ADDI PREVIEW: Will output 'ADDI R29, R29, 13'
DEBUG: Restaurando R15 (contém 't10') após a chamada
ADD_INSTRUCTION[124]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=13
ADD_INSTRUCTION[125]: LW (op=25) rs=R2 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R15, 0(R2)'
DEBUG: Restaurando R14 (contém 't9') após a chamada
ADD_INSTRUCTION[126]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=12
ADD_INSTRUCTION[127]: LW (op=25) rs=R2 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R14, 0(R2)'
DEBUG: Restaurando R13 (contém 't8') após a chamada
ADD_INSTRUCTION[128]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=11
ADD_INSTRUCTION[129]: LW (op=25) rs=R2 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R13, 0(R2)'
DEBUG: Restaurando R12 (contém 't7') após a chamada
ADD_INSTRUCTION[130]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=10
ADD_INSTRUCTION[131]: LW (op=25) rs=R2 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R12, 0(R2)'
DEBUG: Restaurando R11 (contém 't6') após a chamada
ADD_INSTRUCTION[132]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=9
ADD_INSTRUCTION[133]: LW (op=25) rs=R2 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R11, 0(R2)'
DEBUG: Restaurando R10 (contém 'j') após a chamada
ADD_INSTRUCTION[134]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[135]: LW (op=25) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R10, 0(R2)'
DEBUG: Restaurando R9 (contém 't5') após a chamada
ADD_INSTRUCTION[136]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[137]: LW (op=25) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R2)'
DEBUG: Restaurando R8 (contém 't4') após a chamada
ADD_INSTRUCTION[138]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[139]: LW (op=25) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R2)'
DEBUG: Restaurando R7 (contém 'k') após a chamada
ADD_INSTRUCTION[140]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[141]: LW (op=25) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R2)'
DEBUG: Restaurando R6 (contém 't3') após a chamada
ADD_INSTRUCTION[142]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[143]: LW (op=25) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R6, 0(R2)'
DEBUG: Restaurando R5 (contém 'i') após a chamada
ADD_INSTRUCTION[144]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[145]: LW (op=25) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R2)'
DEBUG: Restaurando R3 (contém 't1') após a chamada
ADD_INSTRUCTION[146]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[147]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'n') após a chamada
ADD_INSTRUCTION[148]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[149]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 't15' -> R21
DEBUG: add_move_if_different(R1 -> R21)
DEBUG: Gerando MOVE R21, R1
ADD_INSTRUCTION[150]: MOVE (op=11) rs=R1 rt=R0 rd=R21 imm=0
DEBUG: add_instruction MOVE[150]: rs=1, rt=0, rd=21 (Armazenado: rs=1, rd=21)
ADD_INSTRUCTION[151]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[151]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: load_variable_to_register('t15', 'main')
DEBUG: get_register_for_variable('t15', 'main')
DEBUG: Variável 't15' já em R21 (reutilizando)
DEBUG: Variável 't15' -> R21 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('result', 'main')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 'result' -> R22
DEBUG: add_move_if_different(R21 -> R22)
DEBUG: Gerando MOVE R22, R21
ADD_INSTRUCTION[152]: MOVE (op=11) rs=R21 rt=R0 rd=R22 imm=0
DEBUG: add_instruction MOVE[152]: rs=21, rt=0, rd=22 (Armazenado: rs=21, rd=22)
ADD_INSTRUCTION[153]: SW (op=26) rs=R30 rt=R22 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R22, 1(R30)'
DEBUG: load_variable_to_register('result', 'main')
DEBUG: get_register_for_variable('result', 'main')
DEBUG: Variável 'result' já em R22 (reutilizando)
DEBUG: Variável 'result' -> R22 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[154]: LW (op=25) rs=R30 rt=R22 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R22, 1(R30)'

ADD_INSTRUCTION[155]: OUTPUTREG (op=32) rs=R22 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[156]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 57
Instruções geradas: 157
Labels: 11
Símbolos: 7
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
n               isPrime         0       Não    Sim     Não    1      
i               isPrime         1       Não    Sim     Não    1      
j               isPrime         2       Não    Sim     Não    1      
k               isPrime         3       Não    Sim     Não    1      
remainder       isPrime         4       Não    Sim     Não    1      
number          main            0       Não    Sim     Não    1      
result          main            1       Não    Sim     Não    1      
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
Entradas: [10]
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
