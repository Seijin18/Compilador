Para compilar:
bison -d bison.y
gcc -o testCompiler bison.tab.c funcs.c intermediate.c
gcc -o testAssembler assembler.c
testCompiler <file_execucao>
testAssembler intermediate.txt

Obs: Na pasta há dois assemblers. O assembler.c é o que gera o binário funcional, enquanto que o assembler_em_correcao_sort.c é o que apresenta as correções para o funcionamento do sort, porém ainda não gera .asm corretamente.