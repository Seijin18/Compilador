Para compilar:
bison -d bison.y
gcc -o <nome exec> bison.tab.c funcs.c intermediate.c
gcc -o <nome asm> assembler.c
<nome exec> <file_execucao>
<nome asm> intermediate.txt

Obs: Na pasta há dois assemblers. O assembler.c é o que gera o binário funcional, enquanto que o assembler_em_correcao_sort.c é o que apresenta as correções para o funcionamento do sort, porém ainda não gera .asm corretamente.