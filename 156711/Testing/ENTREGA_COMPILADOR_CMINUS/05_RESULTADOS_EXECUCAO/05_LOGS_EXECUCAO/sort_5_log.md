# Relatório de Compilação - sort_5.c
## Data: 2025-12-02 17:12:37
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\sort_5.c
Tamanho: 677 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function minloc children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
DEBUG: Processing function sort children:
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=1, stmt=-1, exp=3, name=NULL
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
(goto,main, , )
(alloc,vet,5, )
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
(asn,i, ,k)
(goto,L3, , )
(label,L2, , )
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
(immed,5, ,t17)
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
(immed,5, ,t23)
(param,vet, , )
(param,t22, , )
(param,t23, , )
(call,sort,vet,t24)
(immed,0, ,t25)
(asn,t25, ,i)
(label,L8, , )
(immed,5, ,t26)
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
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
ADD_INSTRUCTION[3]: ADD (op=0) rs=R0 rt=R0 rd=R0 imm=0
  ADD PREVIEW: Will output 'ADD R0, R0, R0'
DEBUG: Função 'minloc' detectada com 6 parâmetros totais
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
DEBUG: Configurando função 'minloc' - salvando 6 parâmetros de registrador
DEBUG: Salvando 6 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[11]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[12]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Salvando R6->offset 2
ADD_INSTRUCTION[13]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: Salvando R7->offset 3
ADD_INSTRUCTION[14]: SW (op=26) rs=R30 rt=R7 rd=R0 imm=3
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
DEBUG: Variável 'low' -> R1 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[15]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R1, 1(R30)'

DEBUG: get_register_for_variable('k', 'minloc')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'k' -> R2
DEBUG: add_move_if_different(R1 -> R2)
DEBUG: Gerando MOVE R2, R1
ADD_INSTRUCTION[16]: MOVE (op=11) rs=R1 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[16]: rs=1, rt=0, rd=2 (Armazenado: rs=1, rd=2)
ADD_INSTRUCTION[17]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=5
  MEM PREVIEW: Will output 'SW R2, 5(R30)'

>>> PROCESSING QUAD: LOAD a[low] -> t0

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'low', Result: 't0', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('low', 'minloc')
DEBUG: get_register_for_variable('low', 'minloc')
DEBUG: Variável 'low' já em R1 (reutilizando)
DEBUG: Variável 'low' -> R1 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[18]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R1, 1(R30)'

Index register: R1 (loaded from 'low')
DEBUG: get_register_for_variable('addr_reg_0', 'minloc')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 'addr_reg_0' -> R3
Address register: R3 (addr_reg_0)
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R3, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[19]: LW (op=25) rs=R30 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R30)'
Generating: ADD R3, R3, R1 (final address = base + index)
ADD_INSTRUCTION[20]: ADD (op=0) rs=R3 rt=R1 rd=R3 imm=0
  ADD PREVIEW: Will output 'ADD R3, R3, R1'
DEBUG: get_register_for_variable('t0', 'minloc')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 't0' -> R4
LOAD: Dest register R4 (to 't0')
Generating: LW R4, 0(R3) (load value from address)
ADD_INSTRUCTION[21]: LW (op=25) rs=R3 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R4, 0(R3)'
DEBUG: load_variable_to_register('t0', 'minloc')
DEBUG: get_register_for_variable('t0', 'minloc')
DEBUG: Variável 't0' já em R4 (reutilizando)
DEBUG: Variável 't0' -> R4 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('x', 'minloc')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 'x' -> R5
DEBUG: add_move_if_different(R4 -> R5)
DEBUG: Gerando MOVE R5, R4
ADD_INSTRUCTION[22]: MOVE (op=11) rs=R4 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[22]: rs=4, rt=0, rd=5 (Armazenado: rs=4, rd=5)
ADD_INSTRUCTION[23]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=4
  MEM PREVIEW: Will output 'SW R5, 4(R30)'
DEBUG: get_register_for_variable('t1', 'minloc')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 't1' -> R6
ADD_INSTRUCTION[24]: LI (op=27) rs=R0 rt=R6 rd=R0 imm=1
DEBUG: load_variable_to_register('low', 'minloc')
DEBUG: get_register_for_variable('low', 'minloc')
DEBUG: Variável 'low' já em R1 (reutilizando)
DEBUG: Variável 'low' -> R1 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[25]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R1, 1(R30)'

DEBUG: load_variable_to_register('t1', 'minloc')
DEBUG: get_register_for_variable('t1', 'minloc')
DEBUG: Variável 't1' já em R6 (reutilizando)
DEBUG: Variável 't1' -> R6 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t2', 'minloc')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't2' -> R7
ADD_INSTRUCTION[26]: ADD (op=0) rs=R1 rt=R6 rd=R7 imm=0
  ADD PREVIEW: Will output 'ADD R7, R1, R6'
DEBUG: load_variable_to_register('t2', 'minloc')
DEBUG: get_register_for_variable('t2', 'minloc')
DEBUG: Variável 't2' já em R7 (reutilizando)
DEBUG: Variável 't2' -> R7 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 'i' -> R8
DEBUG: add_move_if_different(R7 -> R8)
DEBUG: Gerando MOVE R8, R7
ADD_INSTRUCTION[27]: MOVE (op=11) rs=R7 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[27]: rs=7, rt=0, rd=8 (Armazenado: rs=7, rd=8)
ADD_INSTRUCTION[28]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R8, 3(R30)'
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[30]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

DEBUG: load_variable_to_register('high', 'minloc')
DEBUG: get_register_for_variable('high', 'minloc')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 'high' -> R9
DEBUG: Variável 'high' -> R9 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[31]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R9, 2(R30)'

DEBUG: get_register_for_variable('t3', 'minloc')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't3' -> R10
ADD_INSTRUCTION[32]: SLT (op=8) rs=R8 rt=R9 rd=R10 imm=0
DEBUG: load_variable_to_register('t3', 'minloc')
DEBUG: get_register_for_variable('t3', 'minloc')
DEBUG: Variável 't3' já em R10 (reutilizando)
DEBUG: Variável 't3' -> R10 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD a[i] -> t4

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'i', Result: 't4', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[34]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

Index register: R8 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_1', 'minloc')
DEBUG: Registrador livre encontrado: R11
DEBUG: Alocando 'addr_reg_1' -> R11
Address register: R11 (addr_reg_1)
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R11, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[35]: LW (op=25) rs=R30 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R11, 0(R30)'
Generating: ADD R11, R11, R8 (final address = base + index)
ADD_INSTRUCTION[36]: ADD (op=0) rs=R11 rt=R8 rd=R11 imm=0
  ADD PREVIEW: Will output 'ADD R11, R11, R8'
DEBUG: get_register_for_variable('t4', 'minloc')
DEBUG: Registrador livre encontrado: R12
DEBUG: Alocando 't4' -> R12
LOAD: Dest register R12 (to 't4')
Generating: LW R12, 0(R11) (load value from address)
ADD_INSTRUCTION[37]: LW (op=25) rs=R11 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R12, 0(R11)'
DEBUG: load_variable_to_register('t4', 'minloc')
DEBUG: get_register_for_variable('t4', 'minloc')
DEBUG: Variável 't4' já em R12 (reutilizando)
DEBUG: Variável 't4' -> R12 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('x', 'minloc')
DEBUG: get_register_for_variable('x', 'minloc')
DEBUG: Variável 'x' já em R5 (reutilizando)
DEBUG: Variável 'x' -> R5 (símbolo encontrado: offset=4, global=0)ADD_INSTRUCTION[38]: LW (op=25) rs=R30 rt=R5 rd=R0 imm=4
  MEM PREVIEW: Will output 'LW R5, 4(R30)'


>>> PROCESSING QUAD: LOAD a[i] -> t5

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'i', Result: 't5', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[40]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

Index register: R8 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_2', 'minloc')
DEBUG: Registrador livre encontrado: R13
DEBUG: Alocando 'addr_reg_2' -> R13
Address register: R13 (addr_reg_2)
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R13, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[41]: LW (op=25) rs=R30 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R13, 0(R30)'
Generating: ADD R13, R13, R8 (final address = base + index)
ADD_INSTRUCTION[42]: ADD (op=0) rs=R13 rt=R8 rd=R13 imm=0
  ADD PREVIEW: Will output 'ADD R13, R13, R8'
DEBUG: get_register_for_variable('t5', 'minloc')
DEBUG: Registrador livre encontrado: R14
DEBUG: Alocando 't5' -> R14
LOAD: Dest register R14 (to 't5')
Generating: LW R14, 0(R13) (load value from address)
ADD_INSTRUCTION[43]: LW (op=25) rs=R13 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R14, 0(R13)'
DEBUG: load_variable_to_register('t5', 'minloc')
DEBUG: get_register_for_variable('t5', 'minloc')
DEBUG: Variável 't5' já em R14 (reutilizando)
DEBUG: Variável 't5' -> R14 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('x', 'minloc')
DEBUG: Variável 'x' já em R5 (reutilizando)
DEBUG: add_move_if_different(R14 -> R5)
DEBUG: Gerando MOVE R5, R14
ADD_INSTRUCTION[44]: MOVE (op=11) rs=R14 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[44]: rs=14, rt=0, rd=5 (Armazenado: rs=14, rd=5)
ADD_INSTRUCTION[45]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=4
  MEM PREVIEW: Will output 'SW R5, 4(R30)'
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[46]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

DEBUG: get_register_for_variable('k', 'minloc')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: add_move_if_different(R8 -> R2)
DEBUG: Gerando MOVE R2, R8
ADD_INSTRUCTION[47]: MOVE (op=11) rs=R8 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[47]: rs=8, rt=0, rd=2 (Armazenado: rs=8, rd=2)
ADD_INSTRUCTION[48]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=5
  MEM PREVIEW: Will output 'SW R2, 5(R30)'
DEBUG: get_register_for_variable('t6', 'minloc')
DEBUG: Registrador livre encontrado: R15
DEBUG: Alocando 't6' -> R15
ADD_INSTRUCTION[52]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'minloc')
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[53]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

DEBUG: load_variable_to_register('t6', 'minloc')
DEBUG: get_register_for_variable('t6', 'minloc')
DEBUG: Variável 't6' já em R15 (reutilizando)
DEBUG: Variável 't6' -> R15 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t7', 'minloc')
DEBUG: Registrador livre encontrado: R16
DEBUG: Alocando 't7' -> R16
ADD_INSTRUCTION[54]: ADD (op=0) rs=R8 rt=R15 rd=R16 imm=0
  ADD PREVIEW: Will output 'ADD R16, R8, R15'
DEBUG: load_variable_to_register('t7', 'minloc')
DEBUG: get_register_for_variable('t7', 'minloc')
DEBUG: Variável 't7' já em R16 (reutilizando)
DEBUG: Variável 't7' -> R16 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'minloc')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: add_move_if_different(R16 -> R8)
DEBUG: Gerando MOVE R8, R16
ADD_INSTRUCTION[55]: MOVE (op=11) rs=R16 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[55]: rs=16, rt=0, rd=8 (Armazenado: rs=16, rd=8)
ADD_INSTRUCTION[56]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R8, 3(R30)'
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
ADD_INSTRUCTION[63]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[64]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[65]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[66]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'sort' detectada com 6 parâmetros totais
DEBUG_RA: === INICIO PROLOGO FUNCAO ===
DEBUG_RA: Decrementando SP em 8 posicoes
ADD_INSTRUCTION[68]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=8
DEBUG_RA: Salvando RA no stack em posição relativa (SP+7)
ADD_INSTRUCTION[69]: SW (op=26) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'SW R31, 7(R29)'
DEBUG_RA: Salvando FP no stack em posição relativa (SP+6)
ADD_INSTRUCTION[70]: SW (op=26) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'SW R30, 6(R29)'
DEBUG_RA: Estabelecendo novo FP (SP+0)
ADD_INSTRUCTION[71]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[71]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG_RA: === FIM PROLOGO FUNCAO ===
DEBUG: Configurando função 'sort' - salvando 6 parâmetros de registrador
DEBUG: Salvando 6 parâmetros de forma genérica
DEBUG: Salvando R4->offset 0
ADD_INSTRUCTION[72]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R4, 0(R30)'
DEBUG: Salvando R5->offset 1
ADD_INSTRUCTION[73]: SW (op=26) rs=R30 rt=R5 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R5, 1(R30)'
DEBUG: Salvando R6->offset 2
ADD_INSTRUCTION[74]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: Salvando R7->offset 3
ADD_INSTRUCTION[75]: SW (op=26) rs=R30 rt=R7 rd=R0 imm=3
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
DEBUG: Variável 'low' -> R1 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[76]: LW (op=25) rs=R30 rt=R1 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R1, 1(R30)'

DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: add_move_if_different(R1 -> R8)
DEBUG: Gerando MOVE R8, R1
ADD_INSTRUCTION[77]: MOVE (op=11) rs=R1 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[77]: rs=1, rt=0, rd=8 (Armazenado: rs=1, rd=8)
ADD_INSTRUCTION[78]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R8, 3(R30)'
DEBUG: get_register_for_variable('t8', 'sort')
DEBUG: Registrador livre encontrado: R17
DEBUG: Alocando 't8' -> R17
ADD_INSTRUCTION[80]: LI (op=27) rs=R0 rt=R17 rd=R0 imm=1
DEBUG: load_variable_to_register('high', 'sort')
DEBUG: get_register_for_variable('high', 'sort')
DEBUG: Variável 'high' já em R9 (reutilizando)
DEBUG: Variável 'high' -> R9 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[81]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R9, 2(R30)'

DEBUG: load_variable_to_register('t8', 'sort')
DEBUG: get_register_for_variable('t8', 'sort')
DEBUG: Variável 't8' já em R17 (reutilizando)
DEBUG: Variável 't8' -> R17 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t9', 'sort')
DEBUG: Registrador livre encontrado: R18
DEBUG: Alocando 't9' -> R18
ADD_INSTRUCTION[82]: SUB (op=1) rs=R9 rt=R17 rd=R18 imm=0
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[83]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

DEBUG: load_variable_to_register('t9', 'sort')
DEBUG: get_register_for_variable('t9', 'sort')
DEBUG: Variável 't9' já em R18 (reutilizando)
DEBUG: Variável 't9' -> R18 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t10', 'sort')
DEBUG: Registrador livre encontrado: R19
DEBUG: Alocando 't10' -> R19
ADD_INSTRUCTION[84]: SLT (op=8) rs=R8 rt=R18 rd=R19 imm=0
DEBUG: load_variable_to_register('t10', 'sort')
DEBUG: get_register_for_variable('t10', 'sort')
DEBUG: Variável 't10' já em R19 (reutilizando)
DEBUG: Variável 't10' -> R19 (símbolo NÃO encontrado!)
DEBUG: Passando parâmetro 0: 'a'
DEBUG: Parâmetro 0 é array, carregando endereço
DEBUG: load_array_address_to_register('a', 'sort')
DEBUG: get_register_for_variable('a', 'sort')
DEBUG: Registrador livre encontrado: R20
DEBUG: Alocando 'a' -> R20
DEBUG: Array 'a' -> R20 (símbolo encontrado: offset=0, global=0, is_arg=1, is_array=1)DEBUG: Array parameter - using LW to load address from parameter
ADD_INSTRUCTION[86]: LW (op=25) rs=R30 rt=R20 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R20, 0(R30)'

DEBUG: Parâmetro 0: 'a' de R20 para R4 (forçado)
ADD_INSTRUCTION[87]: MOVE (op=11) rs=R20 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[87]: rs=20, rt=0, rd=4 (Armazenado: rs=20, rd=4)
DEBUG: Passando parâmetro 1: 'i'
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[88]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

DEBUG: Parâmetro 1: 'i' de R8 para R5 (forçado)
ADD_INSTRUCTION[89]: MOVE (op=11) rs=R8 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[89]: rs=8, rt=0, rd=5 (Armazenado: rs=8, rd=5)
DEBUG: Passando parâmetro 2: 'high'
DEBUG: load_variable_to_register('high', 'sort')
DEBUG: get_register_for_variable('high', 'sort')
DEBUG: Variável 'high' já em R9 (reutilizando)
DEBUG: Variável 'high' -> R9 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[90]: LW (op=25) rs=R30 rt=R9 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R9, 2(R30)'

DEBUG: Parâmetro 2: 'high' de R9 para R6 (forçado)
ADD_INSTRUCTION[91]: MOVE (op=11) rs=R9 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[91]: rs=9, rt=0, rd=6 (Armazenado: rs=9, rd=6)
DEBUG: Salvando R2 (contém 'k') antes da chamada
ADD_INSTRUCTION[92]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[93]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 'addr_reg_0') antes da chamada
ADD_INSTRUCTION[94]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[95]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
DEBUG: Salvando R5 (contém 'x') antes da chamada
ADD_INSTRUCTION[96]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[97]: SW (op=26) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R2)'
DEBUG: Salvando R6 (contém 't1') antes da chamada
ADD_INSTRUCTION[98]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[99]: SW (op=26) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R2)'
DEBUG: Salvando R7 (contém 't2') antes da chamada
ADD_INSTRUCTION[100]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[101]: SW (op=26) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R2)'
DEBUG: Salvando R8 (contém 'i') antes da chamada
ADD_INSTRUCTION[102]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[103]: SW (op=26) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R2)'
DEBUG: Salvando R9 (contém 'high') antes da chamada
ADD_INSTRUCTION[104]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[105]: SW (op=26) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R2)'
DEBUG: Salvando R10 (contém 't3') antes da chamada
ADD_INSTRUCTION[106]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[107]: SW (op=26) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R10, 0(R2)'
DEBUG: Salvando R11 (contém 'addr_reg_1') antes da chamada
ADD_INSTRUCTION[108]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=9
ADD_INSTRUCTION[109]: SW (op=26) rs=R2 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R11, 0(R2)'
DEBUG: Salvando R12 (contém 't4') antes da chamada
ADD_INSTRUCTION[110]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=10
ADD_INSTRUCTION[111]: SW (op=26) rs=R2 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R12, 0(R2)'
DEBUG: Salvando R13 (contém 'addr_reg_2') antes da chamada
ADD_INSTRUCTION[112]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=11
ADD_INSTRUCTION[113]: SW (op=26) rs=R2 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R13, 0(R2)'
DEBUG: Salvando R14 (contém 't5') antes da chamada
ADD_INSTRUCTION[114]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=12
ADD_INSTRUCTION[115]: SW (op=26) rs=R2 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R14, 0(R2)'
DEBUG: Salvando R15 (contém 't6') antes da chamada
ADD_INSTRUCTION[116]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=13
ADD_INSTRUCTION[117]: SW (op=26) rs=R2 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R15, 0(R2)'
ADD_INSTRUCTION[118]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=13
ADD_INSTRUCTION[120]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=13
  ADDI PREVIEW: Will output 'ADDI R29, R29, 13'
DEBUG: Restaurando R15 (contém 't6') após a chamada
ADD_INSTRUCTION[121]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=13
ADD_INSTRUCTION[122]: LW (op=25) rs=R2 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R15, 0(R2)'
DEBUG: Restaurando R14 (contém 't5') após a chamada
ADD_INSTRUCTION[123]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=12
ADD_INSTRUCTION[124]: LW (op=25) rs=R2 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R14, 0(R2)'
DEBUG: Restaurando R13 (contém 'addr_reg_2') após a chamada
ADD_INSTRUCTION[125]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=11
ADD_INSTRUCTION[126]: LW (op=25) rs=R2 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R13, 0(R2)'
DEBUG: Restaurando R12 (contém 't4') após a chamada
ADD_INSTRUCTION[127]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=10
ADD_INSTRUCTION[128]: LW (op=25) rs=R2 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R12, 0(R2)'
DEBUG: Restaurando R11 (contém 'addr_reg_1') após a chamada
ADD_INSTRUCTION[129]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=9
ADD_INSTRUCTION[130]: LW (op=25) rs=R2 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R11, 0(R2)'
DEBUG: Restaurando R10 (contém 't3') após a chamada
ADD_INSTRUCTION[131]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[132]: LW (op=25) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R10, 0(R2)'
DEBUG: Restaurando R9 (contém 'high') após a chamada
ADD_INSTRUCTION[133]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[134]: LW (op=25) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R2)'
DEBUG: Restaurando R8 (contém 'i') após a chamada
ADD_INSTRUCTION[135]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[136]: LW (op=25) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R2)'
DEBUG: Restaurando R7 (contém 't2') após a chamada
ADD_INSTRUCTION[137]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[138]: LW (op=25) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R2)'
DEBUG: Restaurando R6 (contém 't1') após a chamada
ADD_INSTRUCTION[139]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[140]: LW (op=25) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R6, 0(R2)'
DEBUG: Restaurando R5 (contém 'x') após a chamada
ADD_INSTRUCTION[141]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[142]: LW (op=25) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R2)'
DEBUG: Restaurando R3 (contém 'addr_reg_0') após a chamada
ADD_INSTRUCTION[143]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[144]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'k') após a chamada
ADD_INSTRUCTION[145]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[146]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t11', 'sort')
DEBUG: Registrador livre encontrado: R21
DEBUG: Alocando 't11' -> R21
DEBUG: add_move_if_different(R1 -> R21)
DEBUG: Gerando MOVE R21, R1
ADD_INSTRUCTION[147]: MOVE (op=11) rs=R1 rt=R0 rd=R21 imm=0
DEBUG: add_instruction MOVE[147]: rs=1, rt=0, rd=21 (Armazenado: rs=1, rd=21)
DEBUG: load_variable_to_register('t11', 'sort')
DEBUG: get_register_for_variable('t11', 'sort')
DEBUG: Variável 't11' já em R21 (reutilizando)
DEBUG: Variável 't11' -> R21 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('k', 'sort')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: add_move_if_different(R21 -> R2)
DEBUG: Gerando MOVE R2, R21
ADD_INSTRUCTION[148]: MOVE (op=11) rs=R21 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[148]: rs=21, rt=0, rd=2 (Armazenado: rs=21, rd=2)
ADD_INSTRUCTION[149]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=4
  MEM PREVIEW: Will output 'SW R2, 4(R30)'

>>> PROCESSING QUAD: LOAD a[k] -> t12

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'k', Result: 't12', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('k', 'sort')
DEBUG: get_register_for_variable('k', 'sort')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: Variável 'k' -> R2 (símbolo encontrado: offset=4, global=0)ADD_INSTRUCTION[150]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=4
  MEM PREVIEW: Will output 'LW R2, 4(R30)'

Index register: R2 (loaded from 'k')
DEBUG: get_register_for_variable('addr_reg_3', 'sort')
DEBUG: Registrador livre encontrado: R22
DEBUG: Alocando 'addr_reg_3' -> R22
Address register: R22 (addr_reg_3)
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R22, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[151]: LW (op=25) rs=R30 rt=R22 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R22, 0(R30)'
Generating: ADD R22, R22, R2 (final address = base + index)
ADD_INSTRUCTION[152]: ADD (op=0) rs=R22 rt=R2 rd=R22 imm=0
  ADD PREVIEW: Will output 'ADD R22, R22, R2'
DEBUG: get_register_for_variable('t12', 'sort')
DEBUG: Registrador livre encontrado: R23
DEBUG: Alocando 't12' -> R23
LOAD: Dest register R23 (to 't12')
Generating: LW R23, 0(R22) (load value from address)
ADD_INSTRUCTION[153]: LW (op=25) rs=R22 rt=R23 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R23, 0(R22)'
DEBUG: load_variable_to_register('t12', 'sort')
DEBUG: get_register_for_variable('t12', 'sort')
DEBUG: Variável 't12' já em R23 (reutilizando)
DEBUG: Variável 't12' -> R23 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t', 'sort')
DEBUG: Registrador livre encontrado: R24
DEBUG: Alocando 't' -> R24
DEBUG: add_move_if_different(R23 -> R24)
DEBUG: Gerando MOVE R24, R23
ADD_INSTRUCTION[154]: MOVE (op=11) rs=R23 rt=R0 rd=R24 imm=0
DEBUG: add_instruction MOVE[154]: rs=23, rt=0, rd=24 (Armazenado: rs=23, rd=24)
ADD_INSTRUCTION[155]: SW (op=26) rs=R30 rt=R24 rd=R0 imm=6
  MEM PREVIEW: Will output 'SW R24, 6(R30)'

>>> PROCESSING QUAD: LOAD a[i] -> t13

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'i', Result: 't13', LOAD
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[156]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

Index register: R8 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_4', 'sort')
DEBUG: Registrador livre encontrado: R25
DEBUG: Alocando 'addr_reg_4' -> R25
Address register: R25 (addr_reg_4)
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R25, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[157]: LW (op=25) rs=R30 rt=R25 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R25, 0(R30)'
Generating: ADD R25, R25, R8 (final address = base + index)
ADD_INSTRUCTION[158]: ADD (op=0) rs=R25 rt=R8 rd=R25 imm=0
  ADD PREVIEW: Will output 'ADD R25, R25, R8'
DEBUG: get_register_for_variable('t13', 'sort')
DEBUG: Registrador livre encontrado: R26
DEBUG: Alocando 't13' -> R26
LOAD: Dest register R26 (to 't13')
Generating: LW R26, 0(R25) (load value from address)
ADD_INSTRUCTION[159]: LW (op=25) rs=R25 rt=R26 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R26, 0(R25)'

>>> PROCESSING QUAD: STORE t13 -> a[k]

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'k', Result: 't13', STORE
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('k', 'sort')
DEBUG: get_register_for_variable('k', 'sort')
DEBUG: Variável 'k' já em R2 (reutilizando)
DEBUG: Variável 'k' -> R2 (símbolo encontrado: offset=4, global=0)ADD_INSTRUCTION[160]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=4
  MEM PREVIEW: Will output 'LW R2, 4(R30)'

Index register: R2 (loaded from 'k')
DEBUG: get_register_for_variable('addr_reg_5', 'sort')
DEBUG: Registrador livre encontrado: R27
DEBUG: Alocando 'addr_reg_5' -> R27
Address register: R27 (addr_reg_5)
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R27, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[161]: LW (op=25) rs=R30 rt=R27 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R27, 0(R30)'
Generating: ADD R27, R27, R2 (final address = base + index)
ADD_INSTRUCTION[162]: ADD (op=0) rs=R27 rt=R2 rd=R27 imm=0
  ADD PREVIEW: Will output 'ADD R27, R27, R2'
DEBUG: load_variable_to_register('t13', 'sort')
DEBUG: get_register_for_variable('t13', 'sort')
DEBUG: Variável 't13' já em R26 (reutilizando)
DEBUG: Variável 't13' -> R26 (símbolo NÃO encontrado!)
STORE: Value register R26 (from 't13')
Generating: SW R26, 0(R27) (store value at address)
ADD_INSTRUCTION[163]: SW (op=26) rs=R27 rt=R26 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R26, 0(R27)'

>>> PROCESSING QUAD: STORE t -> a[i]

=== DEBUG ARRAY ACCESS ===
Array: 'a', Index: 'i', Result: 't', STORE
Symbol found: name='a', offset=0, global=NO, is_array=YES, size=1
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[164]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

Index register: R8 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_6', 'sort')
DEBUG: Liberando R3 (era addr_reg_0)
DEBUG: Alocando 'addr_reg_6' -> R3
Address register: R3 (addr_reg_6)
Array parameter: FP=30, offset=0 (contains base address)
Generating: LW R3, 0(FP) (load base address from parameter)
ADD_INSTRUCTION[165]: LW (op=25) rs=R30 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R30)'
Generating: ADD R3, R3, R8 (final address = base + index)
ADD_INSTRUCTION[166]: ADD (op=0) rs=R3 rt=R8 rd=R3 imm=0
  ADD PREVIEW: Will output 'ADD R3, R3, R8'
DEBUG: load_variable_to_register('t', 'sort')
DEBUG: get_register_for_variable('t', 'sort')
DEBUG: Variável 't' já em R24 (reutilizando)
DEBUG: Variável 't' -> R24 (símbolo encontrado: offset=6, global=0)ADD_INSTRUCTION[167]: LW (op=25) rs=R30 rt=R24 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R24, 6(R30)'

STORE: Value register R24 (from 't')
Generating: SW R24, 0(R3) (store value at address)
ADD_INSTRUCTION[168]: SW (op=26) rs=R3 rt=R24 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R24, 0(R3)'
DEBUG: get_register_for_variable('t14', 'sort')
DEBUG: Liberando R4 (era t0)
DEBUG: Alocando 't14' -> R4
ADD_INSTRUCTION[169]: LI (op=27) rs=R0 rt=R4 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'sort')
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=3, global=0)ADD_INSTRUCTION[170]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'LW R8, 3(R30)'

DEBUG: load_variable_to_register('t14', 'sort')
DEBUG: get_register_for_variable('t14', 'sort')
DEBUG: Variável 't14' já em R4 (reutilizando)
DEBUG: Variável 't14' -> R4 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t15', 'sort')
DEBUG: Liberando R6 (era t1)
DEBUG: Alocando 't15' -> R6
ADD_INSTRUCTION[171]: ADD (op=0) rs=R8 rt=R4 rd=R6 imm=0
  ADD PREVIEW: Will output 'ADD R6, R8, R4'
DEBUG: load_variable_to_register('t15', 'sort')
DEBUG: get_register_for_variable('t15', 'sort')
DEBUG: Variável 't15' já em R6 (reutilizando)
DEBUG: Variável 't15' -> R6 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'sort')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: add_move_if_different(R6 -> R8)
DEBUG: Gerando MOVE R8, R6
ADD_INSTRUCTION[172]: MOVE (op=11) rs=R6 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[172]: rs=6, rt=0, rd=8 (Armazenado: rs=6, rd=8)
ADD_INSTRUCTION[173]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=3
  MEM PREVIEW: Will output 'SW R8, 3(R30)'
DEBUG_RA: === INICIO EPILOGO FUNCAO ===
DEBUG_RA: Restaurando RA do stack usando SP original
ADD_INSTRUCTION[177]: LW (op=25) rs=R29 rt=R31 rd=R0 imm=7
  MEM PREVIEW: Will output 'LW R31, 7(R29)'
DEBUG_RA: Restaurando FP do stack usando SP original
ADD_INSTRUCTION[178]: LW (op=25) rs=R29 rt=R30 rd=R0 imm=6
  MEM PREVIEW: Will output 'LW R30, 6(R29)'
DEBUG_RA: Restaurando SP para posição anterior (SP+8)
ADD_INSTRUCTION[179]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=8
  ADDI PREVIEW: Will output 'ADDI R29, R29, 8'
DEBUG_RA: Gerando JR RA para retorno
ADD_INSTRUCTION[180]: JR (op=12) rs=R31 rt=R0 rd=R0 imm=0
DEBUG_RA: === FIM EPILOGO FUNCAO ===
DEBUG: Função 'main' detectada com 1 parâmetros totais
ADD_INSTRUCTION[182]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[183]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[184]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[185]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[185]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro i na função main (param #1 de 1)
DEBUG: Parâmetro i registrado com offset 0 na função main
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Liberando R7 (era t2)
DEBUG: Alocando 't16' -> R7
ADD_INSTRUCTION[186]: LI (op=27) rs=R0 rt=R7 rd=R0 imm=0
DEBUG: load_variable_to_register('t16', 'main')
DEBUG: get_register_for_variable('t16', 'main')
DEBUG: Variável 't16' já em R7 (reutilizando)
DEBUG: Variável 't16' -> R7 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: add_move_if_different(R7 -> R8)
DEBUG: Gerando MOVE R8, R7
ADD_INSTRUCTION[187]: MOVE (op=11) rs=R7 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[187]: rs=7, rt=0, rd=8 (Armazenado: rs=7, rd=8)
ADD_INSTRUCTION[188]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R30)'
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Liberando R10 (era t3)
DEBUG: Alocando 't17' -> R10
ADD_INSTRUCTION[190]: LI (op=27) rs=R0 rt=R10 rd=R0 imm=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[191]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R30)'

DEBUG: load_variable_to_register('t17', 'main')
DEBUG: get_register_for_variable('t17', 'main')
DEBUG: Variável 't17' já em R10 (reutilizando)
DEBUG: Variável 't17' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t18', 'main')
DEBUG: Liberando R11 (era addr_reg_1)
DEBUG: Alocando 't18' -> R11
ADD_INSTRUCTION[192]: SLT (op=8) rs=R8 rt=R10 rd=R11 imm=0
DEBUG: load_variable_to_register('t18', 'main')
DEBUG: get_register_for_variable('t18', 'main')
DEBUG: Variável 't18' já em R11 (reutilizando)
DEBUG: Variável 't18' -> R11 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t19', 'main')
DEBUG: Liberando R12 (era t4)
DEBUG: Alocando 't19' -> R12
ADD_INSTRUCTION[194]: INPUT (op=34) rs=R0 rt=R0 rd=R12 imm=0
ADD_INSTRUCTION[195]: OUTPUTREG (op=32) rs=R12 rt=R0 rd=R0 imm=0

>>> PROCESSING QUAD: STORE t19 -> vet[i]

=== DEBUG ARRAY ACCESS ===
Array: 'vet', Index: 'i', Result: 't19', STORE
Symbol found: name='vet', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[196]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R30)'

Index register: R8 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_7', 'main')
DEBUG: Liberando R13 (era addr_reg_2)
DEBUG: Alocando 'addr_reg_7' -> R13
Address register: R13 (addr_reg_7)
Global array: GP=28, offset=0
Generating: ADDI R13, GP, 0 (base address)
ADD_INSTRUCTION[197]: ADDI (op=15) rs=R28 rt=R13 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R13, R28, 0'
Generating: ADD R13, R13, R8 (final address = base + index)
ADD_INSTRUCTION[198]: ADD (op=0) rs=R13 rt=R8 rd=R13 imm=0
  ADD PREVIEW: Will output 'ADD R13, R13, R8'
DEBUG: load_variable_to_register('t19', 'main')
DEBUG: get_register_for_variable('t19', 'main')
DEBUG: Variável 't19' já em R12 (reutilizando)
DEBUG: Variável 't19' -> R12 (símbolo NÃO encontrado!)
STORE: Value register R12 (from 't19')
Generating: SW R12, 0(R13) (store value at address)
ADD_INSTRUCTION[199]: SW (op=26) rs=R13 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R12, 0(R13)'
DEBUG: get_register_for_variable('t20', 'main')
DEBUG: Liberando R14 (era t5)
DEBUG: Alocando 't20' -> R14
ADD_INSTRUCTION[200]: LI (op=27) rs=R0 rt=R14 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[201]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R30)'

DEBUG: load_variable_to_register('t20', 'main')
DEBUG: get_register_for_variable('t20', 'main')
DEBUG: Variável 't20' já em R14 (reutilizando)
DEBUG: Variável 't20' -> R14 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t21', 'main')
DEBUG: Liberando R5 (era x)
DEBUG: Alocando 't21' -> R5
ADD_INSTRUCTION[202]: ADD (op=0) rs=R8 rt=R14 rd=R5 imm=0
  ADD PREVIEW: Will output 'ADD R5, R8, R14'
DEBUG: load_variable_to_register('t21', 'main')
DEBUG: get_register_for_variable('t21', 'main')
DEBUG: Variável 't21' já em R5 (reutilizando)
DEBUG: Variável 't21' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: add_move_if_different(R5 -> R8)
DEBUG: Gerando MOVE R8, R5
ADD_INSTRUCTION[203]: MOVE (op=11) rs=R5 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[203]: rs=5, rt=0, rd=8 (Armazenado: rs=5, rd=8)
ADD_INSTRUCTION[204]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R30)'
DEBUG: get_register_for_variable('t22', 'main')
DEBUG: Liberando R15 (era t6)
DEBUG: Alocando 't22' -> R15
ADD_INSTRUCTION[207]: LI (op=27) rs=R0 rt=R15 rd=R0 imm=0
DEBUG: get_register_for_variable('t23', 'main')
DEBUG: Liberando R16 (era t7)
DEBUG: Alocando 't23' -> R16
ADD_INSTRUCTION[208]: LI (op=27) rs=R0 rt=R16 rd=R0 imm=5
DEBUG: Passando parâmetro 0: 'vet'
DEBUG: Parâmetro 0 é array, carregando endereço
DEBUG: load_array_address_to_register('vet', 'main')
DEBUG: get_register_for_variable('vet', 'main')
DEBUG: Liberando R1 (era low)
DEBUG: Alocando 'vet' -> R1
DEBUG: Array 'vet' -> R1 (símbolo encontrado: offset=0, global=1, is_arg=0, is_array=1)ADD_INSTRUCTION[209]: ADDI (op=15) rs=R28 rt=R1 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R1, R28, 0'

DEBUG: Parâmetro 0: 'vet' de R1 para R4 (forçado)
ADD_INSTRUCTION[210]: MOVE (op=11) rs=R1 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[210]: rs=1, rt=0, rd=4 (Armazenado: rs=1, rd=4)
DEBUG: Passando parâmetro 1: 't22'
DEBUG: load_variable_to_register('t22', 'main')
DEBUG: get_register_for_variable('t22', 'main')
DEBUG: Variável 't22' já em R15 (reutilizando)
DEBUG: Variável 't22' -> R15 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 1: 't22' de R15 para R5 (forçado)
ADD_INSTRUCTION[211]: MOVE (op=11) rs=R15 rt=R0 rd=R5 imm=0
DEBUG: add_instruction MOVE[211]: rs=15, rt=0, rd=5 (Armazenado: rs=15, rd=5)
DEBUG: Passando parâmetro 2: 't23'
DEBUG: load_variable_to_register('t23', 'main')
DEBUG: get_register_for_variable('t23', 'main')
DEBUG: Variável 't23' já em R16 (reutilizando)
DEBUG: Variável 't23' -> R16 (símbolo NÃO encontrado!)
DEBUG: Parâmetro 2: 't23' de R16 para R6 (forçado)
ADD_INSTRUCTION[212]: MOVE (op=11) rs=R16 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[212]: rs=16, rt=0, rd=6 (Armazenado: rs=16, rd=6)
DEBUG: Salvando R2 (contém 'k') antes da chamada
ADD_INSTRUCTION[213]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[214]: SW (op=26) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R2)'
DEBUG: Salvando R3 (contém 'addr_reg_6') antes da chamada
ADD_INSTRUCTION[215]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[216]: SW (op=26) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R3, 0(R2)'
DEBUG: Salvando R5 (contém 't21') antes da chamada
ADD_INSTRUCTION[217]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[218]: SW (op=26) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R5, 0(R2)'
DEBUG: Salvando R6 (contém 't15') antes da chamada
ADD_INSTRUCTION[219]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[220]: SW (op=26) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R6, 0(R2)'
DEBUG: Salvando R7 (contém 't16') antes da chamada
ADD_INSTRUCTION[221]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[222]: SW (op=26) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R7, 0(R2)'
DEBUG: Salvando R8 (contém 'i') antes da chamada
ADD_INSTRUCTION[223]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[224]: SW (op=26) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R2)'
DEBUG: Salvando R9 (contém 'high') antes da chamada
ADD_INSTRUCTION[225]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[226]: SW (op=26) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R9, 0(R2)'
DEBUG: Salvando R10 (contém 't17') antes da chamada
ADD_INSTRUCTION[227]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[228]: SW (op=26) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R10, 0(R2)'
DEBUG: Salvando R11 (contém 't18') antes da chamada
ADD_INSTRUCTION[229]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=9
ADD_INSTRUCTION[230]: SW (op=26) rs=R2 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R11, 0(R2)'
DEBUG: Salvando R12 (contém 't19') antes da chamada
ADD_INSTRUCTION[231]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=10
ADD_INSTRUCTION[232]: SW (op=26) rs=R2 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R12, 0(R2)'
DEBUG: Salvando R13 (contém 'addr_reg_7') antes da chamada
ADD_INSTRUCTION[233]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=11
ADD_INSTRUCTION[234]: SW (op=26) rs=R2 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R13, 0(R2)'
DEBUG: Salvando R14 (contém 't20') antes da chamada
ADD_INSTRUCTION[235]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=12
ADD_INSTRUCTION[236]: SW (op=26) rs=R2 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R14, 0(R2)'
DEBUG: Salvando R15 (contém 't22') antes da chamada
ADD_INSTRUCTION[237]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=13
ADD_INSTRUCTION[238]: SW (op=26) rs=R2 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R15, 0(R2)'
ADD_INSTRUCTION[239]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=13
ADD_INSTRUCTION[241]: ADDI (op=15) rs=R29 rt=R29 rd=R0 imm=13
  ADDI PREVIEW: Will output 'ADDI R29, R29, 13'
DEBUG: Restaurando R15 (contém 't22') após a chamada
ADD_INSTRUCTION[242]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=13
ADD_INSTRUCTION[243]: LW (op=25) rs=R2 rt=R15 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R15, 0(R2)'
DEBUG: Restaurando R14 (contém 't20') após a chamada
ADD_INSTRUCTION[244]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=12
ADD_INSTRUCTION[245]: LW (op=25) rs=R2 rt=R14 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R14, 0(R2)'
DEBUG: Restaurando R13 (contém 'addr_reg_7') após a chamada
ADD_INSTRUCTION[246]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=11
ADD_INSTRUCTION[247]: LW (op=25) rs=R2 rt=R13 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R13, 0(R2)'
DEBUG: Restaurando R12 (contém 't19') após a chamada
ADD_INSTRUCTION[248]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=10
ADD_INSTRUCTION[249]: LW (op=25) rs=R2 rt=R12 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R12, 0(R2)'
DEBUG: Restaurando R11 (contém 't18') após a chamada
ADD_INSTRUCTION[250]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=9
ADD_INSTRUCTION[251]: LW (op=25) rs=R2 rt=R11 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R11, 0(R2)'
DEBUG: Restaurando R10 (contém 't17') após a chamada
ADD_INSTRUCTION[252]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=8
ADD_INSTRUCTION[253]: LW (op=25) rs=R2 rt=R10 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R10, 0(R2)'
DEBUG: Restaurando R9 (contém 'high') após a chamada
ADD_INSTRUCTION[254]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=7
ADD_INSTRUCTION[255]: LW (op=25) rs=R2 rt=R9 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R9, 0(R2)'
DEBUG: Restaurando R8 (contém 'i') após a chamada
ADD_INSTRUCTION[256]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=6
ADD_INSTRUCTION[257]: LW (op=25) rs=R2 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R2)'
DEBUG: Restaurando R7 (contém 't16') após a chamada
ADD_INSTRUCTION[258]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=5
ADD_INSTRUCTION[259]: LW (op=25) rs=R2 rt=R7 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R7, 0(R2)'
DEBUG: Restaurando R6 (contém 't15') após a chamada
ADD_INSTRUCTION[260]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=4
ADD_INSTRUCTION[261]: LW (op=25) rs=R2 rt=R6 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R6, 0(R2)'
DEBUG: Restaurando R5 (contém 't21') após a chamada
ADD_INSTRUCTION[262]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=3
ADD_INSTRUCTION[263]: LW (op=25) rs=R2 rt=R5 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R5, 0(R2)'
DEBUG: Restaurando R3 (contém 'addr_reg_6') após a chamada
ADD_INSTRUCTION[264]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[265]: LW (op=25) rs=R2 rt=R3 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R3, 0(R2)'
DEBUG: Restaurando R2 (contém 'k') após a chamada
ADD_INSTRUCTION[266]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=1
ADD_INSTRUCTION[267]: LW (op=25) rs=R2 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R2)'
DEBUG: get_register_for_variable('t24', 'main')
DEBUG: Liberando R17 (era t8)
DEBUG: Alocando 't24' -> R17
DEBUG: add_move_if_different(R1 -> R17)
DEBUG: Gerando MOVE R17, R1
ADD_INSTRUCTION[268]: MOVE (op=11) rs=R1 rt=R0 rd=R17 imm=0
DEBUG: add_instruction MOVE[268]: rs=1, rt=0, rd=17 (Armazenado: rs=1, rd=17)
ADD_INSTRUCTION[269]: MOVE (op=11) rs=R1 rt=R0 rd=R7 imm=0
DEBUG: add_instruction MOVE[269]: rs=1, rt=0, rd=7 (Armazenado: rs=1, rd=7)
DEBUG: get_register_for_variable('t25', 'main')
DEBUG: Liberando R18 (era t9)
DEBUG: Alocando 't25' -> R18
ADD_INSTRUCTION[270]: LI (op=27) rs=R0 rt=R18 rd=R0 imm=0
DEBUG: load_variable_to_register('t25', 'main')
DEBUG: get_register_for_variable('t25', 'main')
DEBUG: Variável 't25' já em R18 (reutilizando)
DEBUG: Variável 't25' -> R18 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: add_move_if_different(R18 -> R8)
DEBUG: Gerando MOVE R8, R18
ADD_INSTRUCTION[271]: MOVE (op=11) rs=R18 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[271]: rs=18, rt=0, rd=8 (Armazenado: rs=18, rd=8)
ADD_INSTRUCTION[272]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R30)'
DEBUG: get_register_for_variable('t26', 'main')
DEBUG: Liberando R19 (era t10)
DEBUG: Alocando 't26' -> R19
ADD_INSTRUCTION[274]: LI (op=27) rs=R0 rt=R19 rd=R0 imm=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[275]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R30)'

DEBUG: load_variable_to_register('t26', 'main')
DEBUG: get_register_for_variable('t26', 'main')
DEBUG: Variável 't26' já em R19 (reutilizando)
DEBUG: Variável 't26' -> R19 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t27', 'main')
DEBUG: Liberando R20 (era a)
DEBUG: Alocando 't27' -> R20
ADD_INSTRUCTION[276]: SLT (op=8) rs=R8 rt=R19 rd=R20 imm=0
DEBUG: load_variable_to_register('t27', 'main')
DEBUG: get_register_for_variable('t27', 'main')
DEBUG: Variável 't27' já em R20 (reutilizando)
DEBUG: Variável 't27' -> R20 (símbolo NÃO encontrado!)

>>> PROCESSING QUAD: LOAD vet[i] -> t28

=== DEBUG ARRAY ACCESS ===
Array: 'vet', Index: 'i', Result: 't28', LOAD
Symbol found: name='vet', offset=0, global=YES, is_array=YES, size=5
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[278]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R30)'

Index register: R8 (loaded from 'i')
DEBUG: get_register_for_variable('addr_reg_8', 'main')
DEBUG: Liberando R9 (era high)
DEBUG: Alocando 'addr_reg_8' -> R9
Address register: R9 (addr_reg_8)
Global array: GP=28, offset=0
Generating: ADDI R9, GP, 0 (base address)
ADD_INSTRUCTION[279]: ADDI (op=15) rs=R28 rt=R9 rd=R0 imm=0
  ADDI PREVIEW: Will output 'ADDI R9, R28, 0'
Generating: ADD R9, R9, R8 (final address = base + index)
ADD_INSTRUCTION[280]: ADD (op=0) rs=R9 rt=R8 rd=R9 imm=0
  ADD PREVIEW: Will output 'ADD R9, R9, R8'
DEBUG: get_register_for_variable('t28', 'main')
DEBUG: Liberando R21 (era t11)
DEBUG: Alocando 't28' -> R21
LOAD: Dest register R21 (to 't28')
Generating: LW R21, 0(R9) (load value from address)
ADD_INSTRUCTION[281]: LW (op=25) rs=R9 rt=R21 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R21, 0(R9)'
DEBUG: load_variable_to_register('t28', 'main')
DEBUG: get_register_for_variable('t28', 'main')
DEBUG: Variável 't28' já em R21 (reutilizando)
DEBUG: Variável 't28' -> R21 (símbolo NÃO encontrado!)
ADD_INSTRUCTION[282]: OUTPUTREG (op=32) rs=R21 rt=R0 rd=R0 imm=0
DEBUG: get_register_for_variable('t29', 'main')
DEBUG: Liberando R22 (era addr_reg_3)
DEBUG: Alocando 't29' -> R22
ADD_INSTRUCTION[283]: LI (op=27) rs=R0 rt=R22 rd=R0 imm=1
DEBUG: load_variable_to_register('i', 'main')
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: Variável 'i' -> R8 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[284]: LW (op=25) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R8, 0(R30)'

DEBUG: load_variable_to_register('t29', 'main')
DEBUG: get_register_for_variable('t29', 'main')
DEBUG: Variável 't29' já em R22 (reutilizando)
DEBUG: Variável 't29' -> R22 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t30', 'main')
DEBUG: Liberando R23 (era t12)
DEBUG: Alocando 't30' -> R23
ADD_INSTRUCTION[285]: ADD (op=0) rs=R8 rt=R22 rd=R23 imm=0
  ADD PREVIEW: Will output 'ADD R23, R8, R22'
DEBUG: load_variable_to_register('t30', 'main')
DEBUG: get_register_for_variable('t30', 'main')
DEBUG: Variável 't30' já em R23 (reutilizando)
DEBUG: Variável 't30' -> R23 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('i', 'main')
DEBUG: Variável 'i' já em R8 (reutilizando)
DEBUG: add_move_if_different(R23 -> R8)
DEBUG: Gerando MOVE R8, R23
ADD_INSTRUCTION[286]: MOVE (op=11) rs=R23 rt=R0 rd=R8 imm=0
DEBUG: add_instruction MOVE[286]: rs=23, rt=0, rd=8 (Armazenado: rs=23, rd=8)
ADD_INSTRUCTION[287]: SW (op=26) rs=R30 rt=R8 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R8, 0(R30)'
ADD_INSTRUCTION[290]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 97
Instruções geradas: 291
Labels: 15
Símbolos: 14
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
vet                             0       Sim     Não    Sim     5      
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
