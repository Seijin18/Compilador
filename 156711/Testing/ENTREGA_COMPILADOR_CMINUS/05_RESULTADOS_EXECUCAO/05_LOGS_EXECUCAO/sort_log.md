# Relatório de Compilação - sort.c
## Data: 2025-09-16 20:28:07
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\sort.c
Tamanho: 679 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function minloc children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=k
DEBUG: Child - node=0, stmt=2, exp=-1, name=x
DEBUG: Child - node=0, stmt=2, exp=-1, name=i
DEBUG: Child - node=0, stmt=1, exp=-1, name=NULL
DEBUG: Child - node=0, stmt=3, exp=-1, name=int
DEBUG: Processing function sort children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=i
DEBUG: Child - node=0, stmt=1, exp=-1, name=NULL
DEBUG: Processing function main children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=2, exp=-1, name=i
DEBUG: Child - node=0, stmt=1, exp=-1, name=NULL
DEBUG: Child - node=0, stmt=4, exp=-1, name=sort
DEBUG: Child - node=0, stmt=2, exp=-1, name=i
DEBUG: Child - node=0, stmt=1, exp=-1, name=NULL
(goto,main, , )
(alloc,vet,10, )
(fun,minloc, , )
(alloc,a,10, )
(alloc,low,1, )
(alloc,high,1, )
(alloc,i,1, )
(alloc,x,1, )
(alloc,k,1, )
(asn,low, ,k)
(load,a,low,t0)
(asn,t0, ,x)
(immed,1, ,t1)
(+,low,t1,t2)
(asn,t2, ,i)
(label,L0, , )
(<,i,high,t3)
(if_f,t3,L1, )
(load,a,i,t4)
(bge,t4,x,L2)
(load,a,i,t5)
(asn,t5, ,x)
(goto,L3, , )
(label,L2, , )
(asn,i, ,k)
(label,L3, , )
(immed,1, ,t6)
(+,i,t6,t7)
(asn,t7, ,i)
(goto,L0, , )
(label,L1, , )
(ret,k, , )
(endfun, , , )
(fun,sort, , )
(alloc,a,10, )
(alloc,low,1, )
(alloc,high,1, )
(alloc,i,1, )
(alloc,k,1, )
(asn,low, ,i)
(label,L4, , )
(immed,1, ,t8)
(-,high,t8,t9)
(<,i,t9,t10)
(if_f,t10,L5, )
(alloc,t,1, )
(param,a, , )
(param,i, , )
(param,high, , )
(call,minloc,a,t11)
(asn,t11, ,k)
(load,a,k,t12)
(asn,t12, ,t)
(load,a,i,t13)
(store,a,k,t13)
(store,a,i,t)
(immed,1, ,t14)
(+,i,t14,t15)
(asn,t15, ,i)
(goto,L4, , )
(label,L5, , )
(endfun, , , )
(fun,main, , )
(alloc,i,1, )
(immed,0, ,t16)
(asn,t16, ,i)
(label,L6, , )
(immed,10, ,t17)
(<,i,t17,t18)
(if_f,t18,L7, )
(input, , ,t19)
(store,vet,i,t19)
(immed,1, ,t20)
(+,i,t20,t21)
(asn,t21, ,i)
(goto,L6, , )
(label,L7, , )
(immed,0, ,t22)
(immed,10, ,t23)
(param,vet, , )
(param,t22, , )
(param,t23, , )
(call,sort,vet,t24)
(immed,0, ,t25)
(asn,t25, ,i)
(label,L8, , )
(immed,10, ,t26)
(<,i,t26,t27)
(if_f,t27,L9, )
(load,vet,i,t28)
(output,t28,0, )
(immed,1, ,t29)
(+,i,t29,t30)
(asn,t30, ,i)
(goto,L8, , )
(label,L9, , )
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
Quadruplas lidas: 97
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=292
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
DEBUG: Função 'minloc' detectada com 6 parâmetros totais
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
DEBUG: Configurando função 'minloc' - salvando 6 parâmetros de registrador
DEBUG: Salvando 6 parâmetros de forma genérica
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
DEBUG: Local offset configurado para 6 (baseado em 6 parâmetros)
DEBUG: Detectado parâmetro a na função minloc (param #1 de 6)
DEBUG: Parâmetro a registrado com offset 0 na função minloc
DEBUG: Detectado parâmetro low na função minloc (param #2 de 6)
DEBUG: Parâmetro low registrado com offset 1 na função minloc
DEBUG: Detectado parâmetro high na função minloc (param #3 de 6)
DEBUG: Parâmetro high registrado com offset 2 na função minloc
DEBUG: Detectado parâmetro i na função minloc (param #4 de 6)
DEBUG: Parâmetro i registrado com offset 3 na função minloc
DEBUG: Detectado parâmetro x na função minloc (param #5 de 6)
DEBUG: Parâmetro x registrado com offset 4 na função minloc
DEBUG: Detectado parâmetro k na função minloc (param #6 de 6)
DEBUG: Parâmetro k registrado com offset 5 na função minloc
DEBUG: load_variable_to_register('low', 'minloc')
DEBUG: get_register_for_variable('low', 'minloc')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 'low' -> R1
DEBUG: Variável 'low' -> R1 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[12]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R1, 1(R30)'

DEBUG: get_register_for_variable('k', 'minloc')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'k' -> R2
DEBUG: add_move_if_different(R1 -> R2)
DEBUG: Gerando MOVE R2, R1
ADD_INSTRUCTION[13]: MOVE (op=11) rs=R1 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[13]: rs=1, rt=0, rd=2 (Armazenado: rs=1, rd=2)
ADD_INSTRUCTION[14]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=5
  MEM PREVIEW: Will output 'SW R2, 5(R30)'

>>> PROCESSING QUAD: LOAD a[low] -> t0

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'low', Result: 't0', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('low', 'minloc')
DEBUG: get_register_for_variable('low', 'minloc')
DEBUG: Variável 'low' já em R1 (reutilizando)
DEBUG: Variável 'low' -> R1 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[15]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R1, 1(R30)'

Index register: R1 (loaded from 'low')
DEBUG: get_register_for_variable('temp_reg_0', 'minloc')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 'temp_reg_0' -> R3
DEBUG: get_register_for_variable('addr_reg_0', 'minloc')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 'addr_reg_0' -> R4
Temp register: R3 (temp_reg_0), Address register: R4 (addr_reg_0)
Generating: SLL R3, R1, 2 (index * 4)
ADD_INSTRUCTION[16]: SLL (op=6) rs=R1 rt=R0 rd=R3 imm=2
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R4, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[17]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R4, 0(R30)'
Generating: ADD R4, R4, R3 (final address = base + index*4)
ADD_INSTRUCTION[18]: ADD (op=0) rs=R4 rt=R3 rd=R4 imm=0
  ADD PREVIEW: Will output 'ADD R4, R4, R3'
DEBUG: get_register_for_variable('t0', 'minloc')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't0' -> R5
LOAD: Dest register R5 (to 't0')
Generating: LW R5, 0(R4) (load value from address)
ADD_INSTRUCTION[19]: LW (op=25) rs=R4 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R4)'
DEBUG: load_variable_to_register('t0', 'minloc')
DEBUG: get_register_for_variable('t0', 'minloc')
DEBUG: Variável 't0' já em R5 (reutilizando)
DEBUG: Variável 't0' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('x', 'minloc')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 'x' -> R6
DEBUG: add_move_if_different(R5 -> R6)
DEBUG: Gerando MOVE R6, R5
ADD_INSTRUCTION[20]: MOVE (op=11) rs=R5 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[20]: rs=5, rt=0, rd=6 (Armazenado: rs=5, rd=6)
ADD_INSTRUCTION[21]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=4
  MEM PREVIEW: Will output 'SW R6, 4(R30)'
DEBUG: get_register_for_variable('t1', 'minloc')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't1' -> R7
ADD_INSTRUCTION[22]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=1
DEBUG: load_variable_to_register('low', 'minloc')
DEBUG: get_register_for_variable('low', 'minloc')
DEBUG: Variável 'low' já em R1 (reutilizando)
DEBUG: Variável 'low' -> R1 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[23]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R1, 1(R30)'

DEBUG: load_variable_to_register('t1', 'minloc')
DEBUG: get_register_for_variable('t1', 'minloc')
DEBUG: Variável 't1' já em R7 (reutilizando)
DEBUG: Variável 't1' -> R7 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t2', 'minloc')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't2' -> R8
ADD_INSTRUCTION[24]: ADD (op=0) rs=R1 rt=R7 rd=R8 imm=0
  ADD PREVIEW: Will output 'ADD R8, R1, R7'
DEBUG: load_variable_to_register('t2', 'minloc')
DEBUG: get_register_for_variable('t2', 'minloc')
DEBUG: Variável 't2' já em R8 (reutilizando)
DEBUG: Variável 't2' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 'i' -> R9
DEBUG: add_move_if_different(R8 -> R9)
DEBUG: Gerando MOVE R9, R8
ADD_INSTRUCTION[25]: MOVE (op=11) rs=R8 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[25]: rs=8, rt=0, rd=9 (Armazenado: rs=8, rd=9)
ADD_INSTRUCTION[26]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R9, 3(R30)'
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[28]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

DEBUG: load_variable_to_register('high', 'minloc')
DEBUG: get_register_for_variable('high', 'minloc')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 'high' -> R10
DEBUG: Variável 'high' -> R10 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[29]: LW (op=25) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R10, 2(R30)'

DEBUG: get_register_for_variable('t3', 'minloc')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 't3' -> R11
ADD_INSTRUCTION[30]: SLT (op=8) rs=R9 rt=R10 rd=R11 imm=0
DEBUG: load_variable_to_register('t3', 'minloc')
DEBUG: get_register_for_variable('t3', 'minloc')
DEBUG: Variável 't3' já em R11 (reutilizando)
DEBUG: Variável 't3' -> R11 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD a[i] -> t4

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'i', Result: 't4', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[32]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

Index register: R9 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_1', 'minloc')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 'temp_reg_1' -> R12
DEBUG: get_register_for_variable('addr_reg_1', 'minloc')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 'addr_reg_1' -> R13
Temp register: R12 (temp_reg_1), Address register: R13 (addr_reg_1)
Generating: SLL R12, R9, 2 (index * 4)
ADD_INSTRUCTION[33]: SLL (op=6) rs=R9 rt=R0 rd=R12 imm=2
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R13, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[34]: LW (op=25) rs=R30 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R13, 0(R30)'
Generating: ADD R13, R13, R12 (final address = base + index*4)
ADD_INSTRUCTION[35]: ADD (op=0) rs=R13 rt=R12 rd=R13 imm=0
  ADD PREVIEW: Will output 'ADD R13, R13, R12'
DEBUG: get_register_for_variable('t4', 'minloc')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 't4' -> R14
LOAD: Dest register R14 (to 't4')
Generating: LW R14, 0(R13) (load value from address)
ADD_INSTRUCTION[36]: LW (op=25) rs=R13 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R14, 0(R13)'
DEBUG: load_variable_to_register('t4', 'minloc')
DEBUG: get_register_for_variable('t4', 'minloc')
DEBUG: Variável 't4' já em R14 (reutilizando)
DEBUG: Variável 't4' -> R14 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('x', 'minloc')
DEBUG: get_register_for_variable('x', 'minloc')
DEBUG: Variável 'x' já em R6 (reutilizando)
DEBUG: Variável 'x' -> R6 (símbolo encontrado: offset=4, global=0)ADD_INSTRUCTION[37]: LW (op=25) rs=R30 rt=R6 rd=R0 imm=4
  MEM PREVIEW: Will output 'LW R6, 4(R30)'


>>> PROCESSING QUAD: LOAD a[i] -> t5

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'i', Result: 't5', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[39]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

Index register: R9 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_2', 'minloc')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 'temp_reg_2' -> R15
DEBUG: get_register_for_variable('addr_reg_2', 'minloc')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 'addr_reg_2' -> R16
Temp register: R15 (temp_reg_2), Address register: R16 (addr_reg_2)
Generating: SLL R15, R9, 2 (index * 4)
ADD_INSTRUCTION[40]: SLL (op=6) rs=R9 rt=R0 rd=R15 imm=2
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R16, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[41]: LW (op=25) rs=R30 rt=R16 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R16, 0(R30)'
Generating: ADD R16, R16, R15 (final address = base + index*4)
ADD_INSTRUCTION[42]: ADD (op=0) rs=R16 rt=R15 rd=R16 imm=0
  ADD PREVIEW: Will output 'ADD R16, R16, R15'
DEBUG: get_register_for_variable('t5', 'minloc')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 't5' -> R17
LOAD: Dest register R17 (to 't5')
Generating: LW R17, 0(R16) (load value from address)
ADD_INSTRUCTION[43]: LW (op=25) rs=R16 rt=R17 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R17, 0(R16)'
DEBUG: load_variable_to_register('t5', 'minloc')
DEBUG: get_register_for_variable('t5', 'minloc')
DEBUG: Variável 't5' já em R17 (reutilizando)
DEBUG: Variável 't5' -> R17 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('x', 'minloc')
DEBUG: Variável 'x' já em R6 (reutilizando)
DEBUG: add_move_if_different(R17 -> R6)
DEBUG: Gerando MOVE R6, R17
ADD_INSTRUCTION[44]: MOVE (op=11) rs=R17 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[44]: rs=17, rt=0, rd=6 (Armazenado: rs=17, rd=6)
ADD_INSTRUCTION[45]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=4
  MEM PREVIEW: Will output 'SW R6, 4(R30)'
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[48]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

DEBUG: get_register_for_variable('k', 'minloc')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: add_move_if_different(R9 -> R2)
DEBUG: Gerando MOVE R2, R9
ADD_INSTRUCTION[49]: MOVE (op=11) rs=R9 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[49]: rs=9, rt=0, rd=2 (Armazenado: rs=9, rd=2)
ADD_INSTRUCTION[50]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=5
  MEM PREVIEW: Will output 'SW R2, 5(R30)'
DEBUG: get_register_for_variable('t6', 'minloc')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 't6' -> R18
ADD_INSTRUCTION[52]: LI (op=27) rs=R0 rt=R18 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[53]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

DEBUG: load_variable_to_register('t6', 'minloc')
DEBUG: get_register_for_variable('t6', 'minloc')
DEBUG: Variável 't6' já em R18 (reutilizando)
DEBUG: Variável 't6' -> R18 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t7', 'minloc')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 't7' -> R19
ADD_INSTRUCTION[54]: ADD (op=0) rs=R9 rt=R18 rd=R19 imm=0
  ADD PREVIEW: Will output 'ADD R19, R9, R18'
DEBUG: load_variable_to_register('t7', 'minloc')
DEBUG: get_register_for_variable('t7', 'minloc')
DEBUG: Variável 't7' já em R19 (reutilizando)
DEBUG: Variável 't7' -> R19 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: add_move_if_different(R19 -> R9)
DEBUG: Gerando MOVE R9, R19
ADD_INSTRUCTION[55]: MOVE (op=11) rs=R19 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[55]: rs=19, rt=0, rd=9 (Armazenado: rs=19, rd=9)
ADD_INSTRUCTION[56]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R9, 3(R30)'
DEBUG: load_variable_to_register('k', 'minloc')
DEBUG: get_register_for_variable('k', 'minloc')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: Variável 'k' -> R2 (símbolo encontrado: offset=5, global=0)ADD_INSTRUCTION[59]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=5
  MEM PREVIEW: Will output 'LW R2, 5(R30)'

DEBUG: add_move_if_different(R2 -> R1)
DEBUG: Gerando MOVE R1, R2
ADD_INSTRUCTION[60]: MOVE (op=11) rs=R2 rt=R0 rd=R1 imm=0
DEBUG: add_instruction MOVE[60]: rs=2, rt=0, rd=1 (Armazenado: rs=2, rd=1)
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[61]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[62]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[63]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[64]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'sort' detectada com 6 parâmetros totais
DEBUG_RA: === INICIO PROLOGO FUNCAO ===
DEBUG_RA: Decrementando SP em 8 posicoes
ADD_INSTRUCTION[66]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=8
DEBUG_RA: Salvando RA no stack em posição relativa (SP+7)
ADD_INSTRUCTION[67]: SW (op=26) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'SW R31, 7(R29)'
DEBUG_RA: Salvando FP no stack em posição relativa (SP+6)
ADD_INSTRUCTION[68]: SW (op=26) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'SW R30, 6(R29)'
DEBUG_RA: Estabelecendo novo FP (SP+0)
ADD_INSTRUCTION[69]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[69]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG_RA: === FIM PROLOGO FUNCAO ===
DEBUG: Configurando função 'sort' - salvando 6 parâmetros de registrador
DEBUG: Salvando 6 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[70]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[71]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Salvando R6->offset 2
ADD_INSTRUCTION[72]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: Salvando R7->offset 3
ADD_INSTRUCTION[73]: SW (op=26) rs=R30 rt=R7 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R7, 3(R30)'
DEBUG: Local offset configurado para 6 (baseado em 6 parâmetros)
DEBUG: Detectado parâmetro a na função sort (param #1 de 6)
DEBUG: Parâmetro a registrado com offset 0 na função sort
DEBUG: Detectado parâmetro low na função sort (param #2 de 6)
DEBUG: Parâmetro low registrado com offset 1 na função sort
DEBUG: Detectado parâmetro high na função sort (param #3 de 6)
DEBUG: Parâmetro high registrado com offset 2 na função sort
DEBUG: Detectado parâmetro i na função sort (param #4 de 6)
DEBUG: Parâmetro i registrado com offset 3 na função sort
DEBUG: Detectado parâmetro k na função sort (param #5 de 6)
DEBUG: Parâmetro k registrado com offset 4 na função sort
DEBUG: load_variable_to_register('low', 'sort')
DEBUG: get_register_for_variable('low', 'sort')
DEBUG: Variável 'low' já em R1 (reutilizando)
DEBUG: Variável 'low' -> R1 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[74]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R1, 1(R30)'

DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: add_move_if_different(R1 -> R9)
DEBUG: Gerando MOVE R9, R1
ADD_INSTRUCTION[75]: MOVE (op=11) rs=R1 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[75]: rs=1, rt=0, rd=9 (Armazenado: rs=1, rd=9)
ADD_INSTRUCTION[76]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R9, 3(R30)'
DEBUG: get_register_for_variable('t8', 'sort')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 't8' -> R20
ADD_INSTRUCTION[78]: LI (op=27) rs=R0 rt=R20 rd=R0 imm=1
DEBUG: load_variable_to_register('high', 'sort')
DEBUG: get_register_for_variable('high', 'sort')
DEBUG: Variável 'high' já em R10 (reutilizando)
DEBUG: Variável 'high' -> R10 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[79]: LW (op=25) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R10, 2(R30)'

DEBUG: load_variable_to_register('t8', 'sort')
DEBUG: get_register_for_variable('t8', 'sort')
DEBUG: Variável 't8' já em R20 (reutilizando)
DEBUG: Variável 't8' -> R20 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t9', 'sort')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 't9' -> R21
ADD_INSTRUCTION[80]: SUB (op=1) rs=R10 rt=R20 rd=R21 imm=0
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[81]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

DEBUG: load_variable_to_register('t9', 'sort')
DEBUG: get_register_for_variable('t9', 'sort')
DEBUG: Variável 't9' já em R21 (reutilizando)
DEBUG: Variável 't9' -> R21 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t10', 'sort')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 't10' -> R22
ADD_INSTRUCTION[82]: SLT (op=8) rs=R9 rt=R21 rd=R22 imm=0
DEBUG: load_variable_to_register('t10', 'sort')
DEBUG: get_register_for_variable('t10', 'sort')
DEBUG: Variável 't10' já em R22 (reutilizando)
DEBUG: Variável 't10' -> R22 (símbolo NÃO encontrado!)
DEBUG: Passando parâmetro 0: 'a'
DEBUG: Parâmetro 0 é array, carregando endereço
DEBUG: load_array_address_to_register('a', 'sort')
DEBUG: get_register_for_variable('a', 'sort')
DEBUG: Registrador livre encontrado: R23
DEBUG: Alocando 'a' -> R23
DEBUG: Array 'a' -> R23 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[84]: ADDI (op=15) rs=R30 rt=R23 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R23, R30, 0'

DEBUG: Parâmetro 0: 'a' de R23 para R4 (forçado)
ADD_INSTRUCTION[85]: MOVE (op=11) rs=R23 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[85]: rs=23, rt=0, rd=4 (Armazenado: rs=23, rd=4)
DEBUG: Passando parâmetro 1: 'i'
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[86]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

DEBUG: Parâmetro 1: 'i' de R9 para R5 (forçado)
ADD_INSTRUCTION[87]: MOVE (op=11) rs=R9 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[87]: rs=9, rt=0, rd=5 (Armazenado: rs=9, rd=5)
DEBUG: Passando parâmetro 2: 'high'
DEBUG: load_variable_to_register('high', 'sort')
DEBUG: get_register_for_variable('high', 'sort')
DEBUG: Variável 'high' já em R10 (reutilizando)
DEBUG: Variável 'high' -> R10 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[88]: LW (op=25) rs=R30 rt=R10 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R10, 2(R30)'

DEBUG: Parâmetro 2: 'high' de R10 para R6 (forçado)
ADD_INSTRUCTION[89]: MOVE (op=11) rs=R10 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[89]: rs=10, rt=0, rd=6 (Armazenado: rs=10, rd=6)
DEBUG: get_register_for_variable('t11', 'sort')
DEBUG: Registrador livre encontrado: R24
DEBUG: Alocando 't11' -> R24
DEBUG: add_move_if_different(R1 -> R24)
DEBUG: Gerando MOVE R24, R1
ADD_INSTRUCTION[91]: MOVE (op=11) rs=R1 rt=R0 rd=R24 imm=0
DEBUG: add_instruction MOVE[91]: rs=1, rt=0, rd=24 (Armazenado: rs=1, rd=24)
DEBUG: load_variable_to_register('t11', 'sort')
DEBUG: get_register_for_variable('t11', 'sort')
DEBUG: Variável 't11' já em R24 (reutilizando)
DEBUG: Variável 't11' -> R24 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('k', 'sort')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: add_move_if_different(R24 -> R2)
DEBUG: Gerando MOVE R2, R24
ADD_INSTRUCTION[92]: MOVE (op=11) rs=R24 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[92]: rs=24, rt=0, rd=2 (Armazenado: rs=24, rd=2)
ADD_INSTRUCTION[93]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=4
  MEM PREVIEW: Will output 'SW R2, 4(R30)'

>>> PROCESSING QUAD: LOAD a[k] -> t12

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'k', Result: 't12', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('k', 'sort')
DEBUG: get_register_for_variable('k', 'sort')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: Variável 'k' -> R2 (símbolo encontrado: offset=4, global=0)ADD_INSTRUCTION[94]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=4
  MEM PREVIEW: Will output 'LW R2, 4(R30)'

Index register: R2 (loaded from 'k')
DEBUG: get_register_for_variable('temp_reg_3', 'sort')
DEBUG: Registrador livre encontrado: R25
DEBUG: Alocando 'temp_reg_3' -> R25
DEBUG: get_register_for_variable('addr_reg_3', 'sort')
DEBUG: Registrador livre encontrado: R26
DEBUG: Alocando 'addr_reg_3' -> R26
Temp register: R25 (temp_reg_3), Address register: R26 (addr_reg_3)
Generating: SLL R25, R2, 2 (index * 4)
ADD_INSTRUCTION[95]: SLL (op=6) rs=R2 rt=R0 rd=R25 imm=2
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R26, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[96]: LW (op=25) rs=R30 rt=R26 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R26, 0(R30)'
Generating: ADD R26, R26, R25 (final address = base + index*4)
ADD_INSTRUCTION[97]: ADD (op=0) rs=R26 rt=R25 rd=R26 imm=0
  ADD PREVIEW: Will output 'ADD R26, R26, R25'
DEBUG: get_register_for_variable('t12', 'sort')
DEBUG: Registrador livre encontrado: R27
DEBUG: Alocando 't12' -> R27
LOAD: Dest register R27 (to 't12')
Generating: LW R27, 0(R26) (load value from address)
ADD_INSTRUCTION[98]: LW (op=25) rs=R26 rt=R27 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R27, 0(R26)'
DEBUG: load_variable_to_register('t12', 'sort')
DEBUG: get_register_for_variable('t12', 'sort')
DEBUG: Variável 't12' já em R27 (reutilizando)
DEBUG: Variável 't12' -> R27 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t', 'sort')
DEBUG: Liberando R3 (era temp_reg_0)
DEBUG: Alocando 't' -> R3
DEBUG: add_move_if_different(R27 -> R3)
DEBUG: Gerando MOVE R3, R27
ADD_INSTRUCTION[99]: MOVE (op=11) rs=R27 rt=R0 rd=R3 imm=0
DEBUG: add_instruction MOVE[99]: rs=27, rt=0, rd=3 (Armazenado: rs=27, rd=3)
ADD_INSTRUCTION[100]: SW (op=26) rs=R30 rt=R3 rd=R0 imm=6
  MEM PREVIEW: Will output 'SW R3, 6(R30)'

>>> PROCESSING QUAD: LOAD a[i] -> t13

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'i', Result: 't13', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[101]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

Index register: R9 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_4', 'sort')
DEBUG: Liberando R4 (era addr_reg_0)
DEBUG: Alocando 'temp_reg_4' -> R4
DEBUG: get_register_for_variable('addr_reg_4', 'sort')
DEBUG: Liberando R5 (era t0)
DEBUG: Alocando 'addr_reg_4' -> R5
Temp register: R4 (temp_reg_4), Address register: R5 (addr_reg_4)
Generating: SLL R4, R9, 2 (index * 4)
ADD_INSTRUCTION[102]: SLL (op=6) rs=R9 rt=R0 rd=R4 imm=2
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R5, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[103]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R30)'
Generating: ADD R5, R5, R4 (final address = base + index*4)
ADD_INSTRUCTION[104]: ADD (op=0) rs=R5 rt=R4 rd=R5 imm=0
  ADD PREVIEW: Will output 'ADD R5, R5, R4'
DEBUG: get_register_for_variable('t13', 'sort')
DEBUG: Liberando R7 (era t1)
DEBUG: Alocando 't13' -> R7
LOAD: Dest register R7 (to 't13')
Generating: LW R7, 0(R5) (load value from address)
ADD_INSTRUCTION[105]: LW (op=25) rs=R5 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R5)'

>>> PROCESSING QUAD: STORE t13 -> a[k]

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'k', Result: 't13', STORE
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('k', 'sort')
DEBUG: get_register_for_variable('k', 'sort')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: Variável 'k' -> R2 (símbolo encontrado: offset=4, global=0)ADD_INSTRUCTION[106]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=4
  MEM PREVIEW: Will output 'LW R2, 4(R30)'

Index register: R2 (loaded from 'k')
DEBUG: get_register_for_variable('temp_reg_5', 'sort')
DEBUG: Liberando R8 (era t2)
DEBUG: Alocando 'temp_reg_5' -> R8
DEBUG: get_register_for_variable('addr_reg_5', 'sort')
DEBUG: Liberando R11 (era t3)
DEBUG: Alocando 'addr_reg_5' -> R11
Temp register: R8 (temp_reg_5), Address register: R11 (addr_reg_5)
Generating: SLL R8, R2, 2 (index * 4)
ADD_INSTRUCTION[107]: SLL (op=6) rs=R2 rt=R0 rd=R8 imm=2
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R11, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[108]: LW (op=25) rs=R30 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R11, 0(R30)'
Generating: ADD R11, R11, R8 (final address = base + index*4)
ADD_INSTRUCTION[109]: ADD (op=0) rs=R11 rt=R8 rd=R11 imm=0
  ADD PREVIEW: Will output 'ADD R11, R11, R8'
DEBUG: load_variable_to_register('t13', 'sort')
DEBUG: get_register_for_variable('t13', 'sort')
DEBUG: Variável 't13' já em R7 (reutilizando)
DEBUG: Variável 't13' -> R7 (símbolo NÃO encontrado!)
STORE: Value register R7 (from 't13')
Generating: SW R7, 0(R11) (store value at address)
ADD_INSTRUCTION[110]: SW (op=26) rs=R11 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R11)'

>>> PROCESSING QUAD: STORE t -> a[i]

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'i', Result: 't', STORE
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[111]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

Index register: R9 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_6', 'sort')
DEBUG: Liberando R12 (era temp_reg_1)
DEBUG: Alocando 'temp_reg_6' -> R12
DEBUG: get_register_for_variable('addr_reg_6', 'sort')
DEBUG: Liberando R13 (era addr_reg_1)
DEBUG: Alocando 'addr_reg_6' -> R13
Temp register: R12 (temp_reg_6), Address register: R13 (addr_reg_6)
Generating: SLL R12, R9, 2 (index * 4)
ADD_INSTRUCTION[112]: SLL (op=6) rs=R9 rt=R0 rd=R12 imm=2
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R13, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[113]: LW (op=25) rs=R30 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R13, 0(R30)'
Generating: ADD R13, R13, R12 (final address = base + index*4)
ADD_INSTRUCTION[114]: ADD (op=0) rs=R13 rt=R12 rd=R13 imm=0
  ADD PREVIEW: Will output 'ADD R13, R13, R12'
DEBUG: load_variable_to_register('t', 'sort')
DEBUG: get_register_for_variable('t', 'sort')
DEBUG: Variável 't' já em R3 (reutilizando)
DEBUG: Variável 't' -> R3 (símbolo encontrado: offset=6, global=0)ADD_INSTRUCTION[115]: LW (op=25) rs=R30 rt=R3 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R3, 6(R30)'

STORE: Value register R3 (from 't')
Generating: SW R3, 0(R13) (store value at address)
ADD_INSTRUCTION[116]: SW (op=26) rs=R13 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R13)'
DEBUG: get_register_for_variable('t14', 'sort')
DEBUG: Liberando R14 (era t4)
DEBUG: Alocando 't14' -> R14
ADD_INSTRUCTION[117]: LI (op=27) rs=R0 rt=R14 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[118]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R9, 3(R30)'

DEBUG: load_variable_to_register('t14', 'sort')
DEBUG: get_register_for_variable('t14', 'sort')
DEBUG: Variável 't14' já em R14 (reutilizando)
DEBUG: Variável 't14' -> R14 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t15', 'sort')
DEBUG: Liberando R15 (era temp_reg_2)
DEBUG: Alocando 't15' -> R15
ADD_INSTRUCTION[119]: ADD (op=0) rs=R9 rt=R14 rd=R15 imm=0
  ADD PREVIEW: Will output 'ADD R15, R9, R14'
DEBUG: load_variable_to_register('t15', 'sort')
DEBUG: get_register_for_variable('t15', 'sort')
DEBUG: Variável 't15' já em R15 (reutilizando)
DEBUG: Variável 't15' -> R15 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: add_move_if_different(R15 -> R9)
DEBUG: Gerando MOVE R9, R15
ADD_INSTRUCTION[120]: MOVE (op=11) rs=R15 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[120]: rs=15, rt=0, rd=9 (Armazenado: rs=15, rd=9)
ADD_INSTRUCTION[121]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R9, 3(R30)'
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[124]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[125]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[126]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[127]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 1 parâmetros totais
ADD_INSTRUCTION[129]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[130]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[131]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[132]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[132]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro i na função main (param #1 de 1)
DEBUG: Parâmetro i registrado com offset 0 na função main
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Liberando R16 (era addr_reg_2)
DEBUG: Alocando 't16' -> R16
ADD_INSTRUCTION[133]: LI (op=27) rs=R0 rt=R16 rd=R0 imm=0
DEBUG: load_variable_to_register('t16', 'main')
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Variável 't16' já em R16 (reutilizando)
DEBUG: Variável 't16' -> R16 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: add_move_if_different(R16 -> R9)
DEBUG: Gerando MOVE R9, R16
ADD_INSTRUCTION[134]: MOVE (op=11) rs=R16 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[134]: rs=16, rt=0, rd=9 (Armazenado: rs=16, rd=9)
ADD_INSTRUCTION[135]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R30)'
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Liberando R17 (era t5)
DEBUG: Alocando 't17' -> R17
ADD_INSTRUCTION[137]: LI (op=27) rs=R0 rt=R17 rd=R0 imm=10
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[138]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R30)'

DEBUG: load_variable_to_register('t17', 'main')
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Variável 't17' já em R17 (reutilizando)
DEBUG: Variável 't17' -> R17 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t18', 'main')
DEBUG: Liberando R6 (era x)
DEBUG: Alocando 't18' -> R6
ADD_INSTRUCTION[139]: SLT (op=8) rs=R9 rt=R17 rd=R6 imm=0
DEBUG: load_variable_to_register('t18', 'main')
DEBUG: get_register_for_variable('t18', 'main')
DEBUG: Variável 't18' já em R6 (reutilizando)
DEBUG: Variável 't18' -> R6 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t19', 'main')
DEBUG: Liberando R18 (era t6)
DEBUG: Alocando 't19' -> R18
ADD_INSTRUCTION[141]: INPUT (op=34) rs=R0 rt=R0 rd=R18 imm=0
ADD_INSTRUCTION[142]: OUTPUTREG (op=32) rs=R18 rt=R0 rd=R0 imm=0

>>> PROCESSING QUAD: STORE t19 -> vet[i]

=== DEBUG ARRAY ACCESS ===
Array: 'vet', Index: 'i', Result: 't19', STORE
Symbol found: name='vet', offset=0, global=YES, is_array=YES, size=10
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[143]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R30)'

Index register: R9 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_7', 'main')
DEBUG: Liberando R19 (era t7)
DEBUG: Alocando 'temp_reg_7' -> R19
DEBUG: get_register_for_variable('addr_reg_7', 'main')
DEBUG: Liberando R1 (era low)
DEBUG: Alocando 'addr_reg_7' -> R1
Temp register: R19 (temp_reg_7), Address register: R1 (addr_reg_7)
Generating: SLL R19, R9, 2 (index * 4)
ADD_INSTRUCTION[144]: SLL (op=6) rs=R9 rt=R0 rd=R19 imm=2
Global array: GP=28, offset=0
Generating: ADDI R1, GP, 0 (base address)
ADD_INSTRUCTION[145]: ADDI (op=15) rs=R28 rt=R1 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R1, R28, 0'
Generating: ADD R1, R1, R19 (final address)
ADD_INSTRUCTION[146]: ADD (op=0) rs=R1 rt=R19 rd=R1 imm=0
  ADD PREVIEW: Will output 'ADD R1, R1, R19'
DEBUG: load_variable_to_register('t19', 'main')
DEBUG: get_register_for_variable('t19', 'main')
DEBUG: Variável 't19' já em R18 (reutilizando)
DEBUG: Variável 't19' -> R18 (símbolo NÃO encontrado!)
STORE: Value register R18 (from 't19')
Generating: SW R18, 0(R1) (store value at address)
ADD_INSTRUCTION[147]: SW (op=26) rs=R1 rt=R18 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R18, 0(R1)'
DEBUG: get_register_for_variable('t20', 'main')
DEBUG: Liberando R20 (era t8)
DEBUG: Alocando 't20' -> R20
ADD_INSTRUCTION[148]: LI (op=27) rs=R0 rt=R20 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[149]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R30)'

DEBUG: load_variable_to_register('t20', 'main')
DEBUG: get_register_for_variable('t20', 'main')
DEBUG: Variável 't20' já em R20 (reutilizando)
DEBUG: Variável 't20' -> R20 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t21', 'main')
DEBUG: Liberando R21 (era t9)
DEBUG: Alocando 't21' -> R21
ADD_INSTRUCTION[150]: ADD (op=0) rs=R9 rt=R20 rd=R21 imm=0
  ADD PREVIEW: Will output 'ADD R21, R9, R20'
DEBUG: load_variable_to_register('t21', 'main')
DEBUG: get_register_for_variable('t21', 'main')
DEBUG: Variável 't21' já em R21 (reutilizando)
DEBUG: Variável 't21' -> R21 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: add_move_if_different(R21 -> R9)
DEBUG: Gerando MOVE R9, R21
ADD_INSTRUCTION[151]: MOVE (op=11) rs=R21 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[151]: rs=21, rt=0, rd=9 (Armazenado: rs=21, rd=9)
ADD_INSTRUCTION[152]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R30)'
DEBUG: get_register_for_variable('t22', 'main')
DEBUG: Liberando R22 (era t10)
DEBUG: Alocando 't22' -> R22
ADD_INSTRUCTION[155]: LI (op=27) rs=R0 rt=R22 rd=R0 imm=0
DEBUG: get_register_for_variable('t23', 'main')
DEBUG: Liberando R23 (era a)
DEBUG: Alocando 't23' -> R23
ADD_INSTRUCTION[156]: LI (op=27) rs=R0 rt=R23 rd=R0 imm=10
DEBUG: Passando parâmetro 0: 'vet'
DEBUG: Parâmetro 0 é array, carregando endereço
DEBUG: load_array_address_to_register('vet', 'main')
DEBUG: get_register_for_variable('vet', 'main')
DEBUG: Liberando R10 (era high)
DEBUG: Alocando 'vet' -> R10
DEBUG: Array 'vet' -> R10 (símbolo encontrado: offset=0, global=1)ADD_INSTRUCTION[157]: ADDI (op=15) rs=R28 rt=R10 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R10, R28, 0'

DEBUG: Parâmetro 0: 'vet' de R10 para R4 (forçado)
ADD_INSTRUCTION[158]: MOVE (op=11) rs=R10 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[158]: rs=10, rt=0, rd=4 (Armazenado: rs=10, rd=4)
DEBUG: Passando parâmetro 1: 't22'
DEBUG: load_variable_to_register('t22', 'main')
DEBUG: get_register_for_variable('t22', 'main')
DEBUG: Variável 't22' já em R22 (reutilizando)
DEBUG: Variável 't22' -> R22 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 1: 't22' de R22 para R5 (forçado)
ADD_INSTRUCTION[159]: MOVE (op=11) rs=R22 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[159]: rs=22, rt=0, rd=5 (Armazenado: rs=22, rd=5)
DEBUG: Passando parâmetro 2: 't23'
DEBUG: load_variable_to_register('t23', 'main')
DEBUG: get_register_for_variable('t23', 'main')
DEBUG: Variável 't23' já em R23 (reutilizando)
DEBUG: Variável 't23' -> R23 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 2: 't23' de R23 para R6 (forçado)
ADD_INSTRUCTION[160]: MOVE (op=11) rs=R23 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[160]: rs=23, rt=0, rd=6 (Armazenado: rs=23, rd=6)
DEBUG: get_register_for_variable('t24', 'main')
DEBUG: Liberando R24 (era t11)
DEBUG: Alocando 't24' -> R24
DEBUG: add_move_if_different(R1 -> R24)
DEBUG: Gerando MOVE R24, R1
ADD_INSTRUCTION[162]: MOVE (op=11) rs=R1 rt=R0 rd=R24 imm=0
DEBUG: add_instruction MOVE[162]: rs=1, rt=0, rd=24 (Armazenado: rs=1, rd=24)
ADD_INSTRUCTION[163]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[163]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: get_register_for_variable('t25', 'main')
DEBUG: Liberando R25 (era temp_reg_3)
DEBUG: Alocando 't25' -> R25
ADD_INSTRUCTION[164]: LI (op=27) rs=R0 rt=R25 rd=R0 imm=0
DEBUG: load_variable_to_register('t25', 'main')
DEBUG: get_register_for_variable('t25', 'main')
DEBUG: Variável 't25' já em R25 (reutilizando)
DEBUG: Variável 't25' -> R25 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: add_move_if_different(R25 -> R9)
DEBUG: Gerando MOVE R9, R25
ADD_INSTRUCTION[165]: MOVE (op=11) rs=R25 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[165]: rs=25, rt=0, rd=9 (Armazenado: rs=25, rd=9)
ADD_INSTRUCTION[166]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R30)'
DEBUG: get_register_for_variable('t26', 'main')
DEBUG: Liberando R26 (era addr_reg_3)
DEBUG: Alocando 't26' -> R26
ADD_INSTRUCTION[168]: LI (op=27) rs=R0 rt=R26 rd=R0 imm=10
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[169]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R30)'

DEBUG: load_variable_to_register('t26', 'main')
DEBUG: get_register_for_variable('t26', 'main')
DEBUG: Variável 't26' já em R26 (reutilizando)
DEBUG: Variável 't26' -> R26 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t27', 'main')
DEBUG: Liberando R27 (era t12)
DEBUG: Alocando 't27' -> R27
ADD_INSTRUCTION[170]: SLT (op=8) rs=R9 rt=R26 rd=R27 imm=0
DEBUG: load_variable_to_register('t27', 'main')
DEBUG: get_register_for_variable('t27', 'main')
DEBUG: Variável 't27' já em R27 (reutilizando)
DEBUG: Variável 't27' -> R27 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD vet[i] -> t28

=== DEBUG ARRAY ACCESS ===
Array: 'vet', Index: 'i', Result: 't28', LOAD
Symbol found: name='vet', offset=0, global=YES, is_array=YES, size=10
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[172]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R30)'

Index register: R9 (loaded from 'i')
DEBUG: get_register_for_variable('temp_reg_8', 'main')
DEBUG: Liberando R4 (era temp_reg_4)
DEBUG: Alocando 'temp_reg_8' -> R4
DEBUG: get_register_for_variable('addr_reg_8', 'main')
DEBUG: Liberando R5 (era addr_reg_4)
DEBUG: Alocando 'addr_reg_8' -> R5
Temp register: R4 (temp_reg_8), Address register: R5 (addr_reg_8)
Generating: SLL R4, R9, 2 (index * 4)
ADD_INSTRUCTION[173]: SLL (op=6) rs=R9 rt=R0 rd=R4 imm=2
Global array: GP=28, offset=0
Generating: ADDI R5, GP, 0 (base address)
ADD_INSTRUCTION[174]: ADDI (op=15) rs=R28 rt=R5 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R5, R28, 0'
Generating: ADD R5, R5, R4 (final address)
ADD_INSTRUCTION[175]: ADD (op=0) rs=R5 rt=R4 rd=R5 imm=0
  ADD PREVIEW: Will output 'ADD R5, R5, R4'
DEBUG: get_register_for_variable('t28', 'main')
DEBUG: Liberando R2 (era k)
DEBUG: Alocando 't28' -> R2
LOAD: Dest register R2 (to 't28')
Generating: LW R2, 0(R5) (load value from address)
ADD_INSTRUCTION[176]: LW (op=25) rs=R5 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R5)'
DEBUG: load_variable_to_register('t28', 'main')
DEBUG: get_register_for_variable('t28', 'main')
DEBUG: Variável 't28' já em R2 (reutilizando)
DEBUG: Variável 't28' -> R2 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[177]: OUTPUTREG (op=32) rs=R2 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t29', 'main')
DEBUG: Liberando R8 (era temp_reg_5)
DEBUG: Alocando 't29' -> R8
ADD_INSTRUCTION[178]: LI (op=27) rs=R0 rt=R8 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: Variável 'i' -> R9 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[179]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R30)'

DEBUG: load_variable_to_register('t29', 'main')
DEBUG: get_register_for_variable('t29', 'main')
DEBUG: Variável 't29' já em R8 (reutilizando)
DEBUG: Variável 't29' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t30', 'main')
DEBUG: Liberando R11 (era addr_reg_5)
DEBUG: Alocando 't30' -> R11
ADD_INSTRUCTION[180]: ADD (op=0) rs=R9 rt=R8 rd=R11 imm=0
  ADD PREVIEW: Will output 'ADD R11, R9, R8'
DEBUG: load_variable_to_register('t30', 'main')
DEBUG: get_register_for_variable('t30', 'main')
DEBUG: Variável 't30' já em R11 (reutilizando)
DEBUG: Variável 't30' -> R11 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R9 (reutilizando)
DEBUG: add_move_if_different(R11 -> R9)
DEBUG: Gerando MOVE R9, R11
ADD_INSTRUCTION[181]: MOVE (op=11) rs=R11 rt=R0 rd=R9 imm=0
DEBUG: add_instruction MOVE[181]: rs=11, rt=0, rd=9 (Armazenado: rs=11, rd=9)
ADD_INSTRUCTION[182]: SW (op=26) rs=R30 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R30)'
ADD_INSTRUCTION[185]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 97
Instruções geradas: 186
Labels: 13
Símbolos: 14
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
vet                             0       Sim     Não    Sim     10     
a               minloc          0       Não    Sim     Sim     1      
low             minloc          1       Não    Sim     Não    1      
high            minloc          2       Não    Sim     Não    1      
i               minloc          3       Não    Sim     Não    1      
x               minloc          4       Não    Sim     Não    1      
k               minloc          5       Não    Sim     Não    1      
a               sort            0       Não    Sim     Sim     1      
low             sort            1       Não    Sim     Não    1      
high            sort            2       Não    Sim     Não    1      
i               sort            3       Não    Sim     Não    1      
k               sort            4       Não    Sim     Não    1      
t               sort            6       Não    Não    Não    1      
i               main            0       Não    Sim     Não    1      
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
Entradas: [10]
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
