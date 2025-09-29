Para compilar:
bison -d bison.y
gcc -o testCompiler bison.tab.c funcs.c intermediate.c dfa.c
gcc -o testAssembler assembler.c
testCompiler <file_execucao>
testAssembler intermediate.txt
