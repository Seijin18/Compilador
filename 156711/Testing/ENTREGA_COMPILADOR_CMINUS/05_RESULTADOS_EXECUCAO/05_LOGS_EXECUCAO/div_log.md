# Relatório de Compilação - div.c
## Data: 2025-12-02 17:12:36
## Status: ✅ SUCESSO

### 📄 Arquivo Original
Localização: CMinusCodes\div.c
Tamanho: 201 bytes

### 🔧 Compilação C-Minus
```
Tree written to tree.txt
Symbol table written to symbol_table.txt
DEBUG: Processing function main children:
DEBUG: Child - node=0, stmt=11, exp=-1, name=NULL
(goto,main, , )
(fun,main, , )
(alloc,x,1, )
(alloc,y,1, )
(alloc,z,1, )
(alloc,i,1, )
(input, , ,t0)
(asn,t0, ,x)
(input, , ,t1)
(asn,t1, ,y)
(immed,0, ,t2)
(asn,t2, ,z)
(label,L0, , )
(>=,x,y,t3)
(if_f,t3,L1, )
(-,x,y,t4)
(asn,t4, ,x)
(immed,1, ,t5)
(+,z,t5,t6)
(asn,t6, ,z)
(goto,L0, , )
(label,L1, , )
(output,z,0, )
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
Quadruplas lidas: 24
Primeira passada: mapeando labels...
Segunda passada: gerando código...
ADD_INSTRUCTION[0]: LI (op=27) rs=R0 rt=R28 rd=R0 imm=128
ADD_INSTRUCTION[1]: LI (op=27) rs=R0 rt=R29 rd=R0 imm=255
ADD_INSTRUCTION[3]: ADD (op=0) rs=R0 rt=R0 rd=R0 imm=0
  ADD PREVIEW: Will output 'ADD R0, R0, R0'
DEBUG: Função 'main' detectada com 4 parâmetros totais
ADD_INSTRUCTION[7]: SUBI (op=16) rs=R29 rt=R2 rd=R0 imm=2
ADD_INSTRUCTION[8]: SW (op=26) rs=R2 rt=R30 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R30, 0(R2)'
ADD_INSTRUCTION[9]: SUBI (op=16) rs=R29 rt=R29 rd=R0 imm=2
ADD_INSTRUCTION[10]: MOVE (op=11) rs=R29 rt=R0 rd=R30 imm=0
DEBUG: add_instruction MOVE[10]: rs=29, rt=0, rd=30 (Armazenado: rs=29, rd=30)
DEBUG: Detectado parâmetro x na função main (param #1 de 4)
DEBUG: Parâmetro x registrado com offset 0 na função main
DEBUG: Detectado parâmetro y na função main (param #2 de 4)
DEBUG: Parâmetro y registrado com offset 1 na função main
DEBUG: Detectado parâmetro z na função main (param #3 de 4)
DEBUG: Parâmetro z registrado com offset 2 na função main
DEBUG: Detectado parâmetro i na função main (param #4 de 4)
DEBUG: Parâmetro i registrado com offset 3 na função main
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Registrador livre encontrado: R1
DEBUG: Alocando 't0' -> R1
ADD_INSTRUCTION[11]: INPUT (op=34) rs=R0 rt=R0 rd=R1 imm=0
ADD_INSTRUCTION[12]: OUTPUTREG (op=32) rs=R1 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t0', 'main')
DEBUG: get_register_for_variable('t0', 'main')
DEBUG: Variável 't0' já em R1 (reutilizando)
DEBUG: Variável 't0' -> R1 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('x', 'main')
DEBUG: Registrador livre encontrado: R2
DEBUG: Alocando 'x' -> R2
DEBUG: add_move_if_different(R1 -> R2)
DEBUG: Gerando MOVE R2, R1
ADD_INSTRUCTION[13]: MOVE (op=11) rs=R1 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[13]: rs=1, rt=0, rd=2 (Armazenado: rs=1, rd=2)
ADD_INSTRUCTION[14]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Registrador livre encontrado: R3
DEBUG: Alocando 't1' -> R3
ADD_INSTRUCTION[15]: INPUT (op=34) rs=R0 rt=R0 rd=R3 imm=0
ADD_INSTRUCTION[16]: OUTPUTREG (op=32) rs=R3 rt=R0 rd=R0 imm=0
DEBUG: load_variable_to_register('t1', 'main')
DEBUG: get_register_for_variable('t1', 'main')
DEBUG: Variável 't1' já em R3 (reutilizando)
DEBUG: Variável 't1' -> R3 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('y', 'main')
DEBUG: Registrador livre encontrado: R4
DEBUG: Alocando 'y' -> R4
DEBUG: add_move_if_different(R3 -> R4)
DEBUG: Gerando MOVE R4, R3
ADD_INSTRUCTION[17]: MOVE (op=11) rs=R3 rt=R0 rd=R4 imm=0
DEBUG: add_instruction MOVE[17]: rs=3, rt=0, rd=4 (Armazenado: rs=3, rd=4)
ADD_INSTRUCTION[18]: SW (op=26) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'SW R4, 1(R30)'
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Registrador livre encontrado: R5
DEBUG: Alocando 't2' -> R5
ADD_INSTRUCTION[19]: LI (op=27) rs=R0 rt=R5 rd=R0 imm=0
DEBUG: load_variable_to_register('t2', 'main')
DEBUG: get_register_for_variable('t2', 'main')
DEBUG: Variável 't2' já em R5 (reutilizando)
DEBUG: Variável 't2' -> R5 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('z', 'main')
DEBUG: Registrador livre encontrado: R6
DEBUG: Alocando 'z' -> R6
DEBUG: add_move_if_different(R5 -> R6)
DEBUG: Gerando MOVE R6, R5
ADD_INSTRUCTION[20]: MOVE (op=11) rs=R5 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[20]: rs=5, rt=0, rd=6 (Armazenado: rs=5, rd=6)
ADD_INSTRUCTION[21]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: Processando comparação '>=' entre 'x' e 'y' -> 't3'
DEBUG: load_variable_to_register('x', 'main')
DEBUG: get_register_for_variable('x', 'main')
DEBUG: Variável 'x' já em R2 (reutilizando)
DEBUG: Variável 'x' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[23]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('y', 'main')
DEBUG: get_register_for_variable('y', 'main')
DEBUG: Variável 'y' já em R4 (reutilizando)
DEBUG: Variável 'y' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[24]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Registrador livre encontrado: R7
DEBUG: Alocando 't3' -> R7
DEBUG: Registradores: 'x'->R2, 'y'->R4, resultado->R7
ADD_INSTRUCTION[25]: SLT (op=8) rs=R2 rt=R4 rd=R7 imm=0
DEBUG: SLT R7, R2, R4 (rs < rt)
ADD_INSTRUCTION[26]: LI (op=27) rs=R0 rt=R1 rd=R0 imm=1
ADD_INSTRUCTION[27]: SUB (op=1) rs=R1 rt=R7 rd=R7 imm=0
DEBUG: Resultado >= invertido: R7 = 1 - R7
DEBUG: load_variable_to_register('t3', 'main')
DEBUG: get_register_for_variable('t3', 'main')
DEBUG: Variável 't3' já em R7 (reutilizando)
DEBUG: Variável 't3' -> R7 (símbolo NÃO encontrado!)
DEBUG: load_variable_to_register('x', 'main')
DEBUG: get_register_for_variable('x', 'main')
DEBUG: Variável 'x' já em R2 (reutilizando)
DEBUG: Variável 'x' -> R2 (símbolo encontrado: offset=0, global=0)ADD_INSTRUCTION[29]: LW (op=25) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'LW R2, 0(R30)'

DEBUG: load_variable_to_register('y', 'main')
DEBUG: get_register_for_variable('y', 'main')
DEBUG: Variável 'y' já em R4 (reutilizando)
DEBUG: Variável 'y' -> R4 (símbolo encontrado: offset=1, global=0)ADD_INSTRUCTION[30]: LW (op=25) rs=R30 rt=R4 rd=R0 imm=1
  MEM PREVIEW: Will output 'LW R4, 1(R30)'

DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Registrador livre encontrado: R8
DEBUG: Alocando 't4' -> R8
ADD_INSTRUCTION[31]: SUB (op=1) rs=R2 rt=R4 rd=R8 imm=0
DEBUG: load_variable_to_register('t4', 'main')
DEBUG: get_register_for_variable('t4', 'main')
DEBUG: Variável 't4' já em R8 (reutilizando)
DEBUG: Variável 't4' -> R8 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('x', 'main')
DEBUG: Variável 'x' já em R2 (reutilizando)
DEBUG: add_move_if_different(R8 -> R2)
DEBUG: Gerando MOVE R2, R8
ADD_INSTRUCTION[32]: MOVE (op=11) rs=R8 rt=R0 rd=R2 imm=0
DEBUG: add_instruction MOVE[32]: rs=8, rt=0, rd=2 (Armazenado: rs=8, rd=2)
ADD_INSTRUCTION[33]: SW (op=26) rs=R30 rt=R2 rd=R0 imm=0
  MEM PREVIEW: Will output 'SW R2, 0(R30)'
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Registrador livre encontrado: R9
DEBUG: Alocando 't5' -> R9
ADD_INSTRUCTION[34]: LI (op=27) rs=R0 rt=R9 rd=R0 imm=1
DEBUG: load_variable_to_register('z', 'main')
DEBUG: get_register_for_variable('z', 'main')
DEBUG: Variável 'z' já em R6 (reutilizando)
DEBUG: Variável 'z' -> R6 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[35]: LW (op=25) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R6, 2(R30)'

DEBUG: load_variable_to_register('t5', 'main')
DEBUG: get_register_for_variable('t5', 'main')
DEBUG: Variável 't5' já em R9 (reutilizando)
DEBUG: Variável 't5' -> R9 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Registrador livre encontrado: R10
DEBUG: Alocando 't6' -> R10
ADD_INSTRUCTION[36]: ADD (op=0) rs=R6 rt=R9 rd=R10 imm=0
  ADD PREVIEW: Will output 'ADD R10, R6, R9'
DEBUG: load_variable_to_register('t6', 'main')
DEBUG: get_register_for_variable('t6', 'main')
DEBUG: Variável 't6' já em R10 (reutilizando)
DEBUG: Variável 't6' -> R10 (símbolo NÃO encontrado!)
DEBUG: get_register_for_variable('z', 'main')
DEBUG: Variável 'z' já em R6 (reutilizando)
DEBUG: add_move_if_different(R10 -> R6)
DEBUG: Gerando MOVE R6, R10
ADD_INSTRUCTION[37]: MOVE (op=11) rs=R10 rt=R0 rd=R6 imm=0
DEBUG: add_instruction MOVE[37]: rs=10, rt=0, rd=6 (Armazenado: rs=10, rd=6)
ADD_INSTRUCTION[38]: SW (op=26) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'SW R6, 2(R30)'
DEBUG: load_variable_to_register('z', 'main')
DEBUG: get_register_for_variable('z', 'main')
DEBUG: Variável 'z' já em R6 (reutilizando)
DEBUG: Variável 'z' -> R6 (símbolo encontrado: offset=2, global=0)ADD_INSTRUCTION[41]: LW (op=25) rs=R30 rt=R6 rd=R0 imm=2
  MEM PREVIEW: Will output 'LW R6, 2(R30)'

ADD_INSTRUCTION[42]: OUTPUTREG (op=32) rs=R6 rt=R0 rd=R0 imm=0
ADD_INSTRUCTION[43]: HALT (op=30) rs=R0 rt=R0 rd=R0 imm=0
Terceira passada: corrigindo endereços...
Escrevendo arquivos de saída...
=== Estatísticas do Assembler Corrigido ===
Quadruplas processadas: 24
Instruções geradas: 44
Labels: 3
Símbolos: 4
==========================================
=== Tabela de Símbolos Corrigida ===
Nome            Escopo          Offset  Global  Arg     Array   Tamanho
------------------------------------------------------------------------
x               main            0       Não    Sim     Não    1      
y               main            1       Não    Sim     Não    1      
z               main            2       Não    Sim     Não    1      
i               main            3       Não    Sim     Não    1      
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
Entradas: [15, 3]
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
