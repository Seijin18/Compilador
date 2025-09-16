# Arquivos essenciais para manter na pasta Testing:

## COMPILADOR/ASSEMBLER (essenciais)
- assembler.c (código fonte do assembler funcional)
- assembler.exe (executável atual)
- testCompilerFixed.exe (compilador funcional)
- funcs.c, funcs.h, funcs.o (dependências do assembler)
- bison.tab.c, bison.tab.h, bison.y (parser)
- dfa.c (analisador léxico)
- intermediate.c, intermediate.h, intermediate.o (geração de código intermediário)

## SIMULADOR
- mips_simulator.py (simulador MIPS)

## CÓDIGOS DE TESTE (essenciais)
- CMinusCodes/ (pasta com todos os códigos de teste)

## DOCUMENTAÇÃO (essencial)
- relatorio_problemas_testes.txt (documentação dos problemas)
- instrucoes_processador.md (documentação do processador)
- Readme.txt (instruções básicas)

## ARQUIVOS TEMPORÁRIOS (remover)
- assembly_fixed.asm, assembly_output_corrected.asm (outputs temporários)
- binary_output_corrected.txt (output temporário)
- debug_*.txt, detailed_output.txt, execution_debug.txt (logs de debug temporários)
- test_*.c (duplicatas de testes)
- intermediate.txt, symbol_table.txt, tree.txt (outputs temporários)
- *.exe duplicados (testAssembler.exe, testCompiler.exe, teste.exe, assTst.exe)
- debug_intermediate.c (arquivo temporário)
- ENTREGA_COMPILADOR_CMINUS/ (duplicata da pasta principal)
- __pycache__/ (cache do Python)
- test_intermediate_corrected.txt (temporário)
- RELATORIO_*.txt (relatórios antigos)