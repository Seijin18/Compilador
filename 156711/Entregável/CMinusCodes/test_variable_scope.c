/* Teste de escopo de variáveis locais vs globais
   Valida: diferenciação entre variáveis globais e locais, shadowing */

int global_var;

int test_scope(int param)
{
    int local_var;
    local_var = param + 5;
    global_var = local_var * 2;
    return local_var;
}

void main(void)
{
    int local_main;
    
    /* Inicializa variável global */
    global_var = 100;
    
    /* Chama função que modifica global_var */
    local_main = test_scope(10);
    
    /* local_main deve ser 15 (10+5) */
    output(local_main);
    
    /* global_var deve ser 30 (15*2) */
    output(global_var);
    
    /* Testa modificação direta da variável global */
    global_var = global_var + local_main;
    
    /* global_var deve ser 45 (30+15) */
    output(global_var);
}