Para compilar:
bison -d bison.y
gcc -o <nome exec> bison.tab.c funcs.c intermediate.c
gcc -o <nome asm> assembler.c
<nome exec> <file_execucao>
<nome asm> intermediate.txt

=== CORREÇÕES IMPLEMENTADAS (VERSÃO FINAL) ===

O compilador C- e assembler MIPS foram corrigidos com as seguintes melhorias:

1. COMPILADOR (intermediate.c):
   - Correção no acesso a arrays: Agora gera corretamente quadruplas (store,array,index,value) e (load,array,index,result)
   - Correção em loops while: Processamento correto de múltiplas instruções no corpo do loop
   - Melhoria na geração de código intermediário para operações de array indexado

2. ASSEMBLER (assembler.c):
   - Correção na alocação de arrays globais: GP agora é ajustado baseado no tamanho total dos arrays globais
   - Reserva de memória: Arrays globais têm espaço adequadamente reservado antes da execução da main
   - Melhoria no gerenciamento de símbolos: Offsets corretos para variáveis globais e locais
   - Suporte completo a store/load com indexação para arrays

3. FUNCIONALIDADES VALIDADAS:
   - Arrays globais com acesso indexado (test_global_array.c)
   - Loops while com múltiplas instruções (test_while.c)
   - Funções com parâmetros e valores de retorno
   - Operações aritméticas e de comparação

O assembler.c atual é a versão final funcional que gera assembly e binário corretos.
Os arquivos intermediate.c e assembler.c foram completamente corrigidos e testados.