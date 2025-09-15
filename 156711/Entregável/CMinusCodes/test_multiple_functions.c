/* Teste de múltiplas funções com valores de retorno
   Valida: chamadas entre funções, valores de retorno, passagem de parâmetros */

int add(int a, int b)
{
    return a + b;
}

int multiply(int x, int y)
{
    return x * y;
}

int calculate(int num1, int num2)
{
    int sum_result;
    int mult_result;
    
    sum_result = add(num1, num2);
    mult_result = multiply(sum_result, 2);
    
    return mult_result;
}

void main(void)
{
    int result;
    
    /* Testa chamadas encadeadas de funções */
    result = calculate(3, 7);
    
    /* Deve imprimir 20: (3+7)*2 = 20 */
    output(result);
}