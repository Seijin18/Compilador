/* Teste de passagem de vetor como parâmetro para função
   Valida: função recebendo array, acesso a elementos via parâmetro */

int test_array[3];

int sum_array(int arr[], int size)
{
    int i;
    int sum;
    sum = 0;
    i = 0;
    while (i < size) {
        sum = sum + arr[i];
        i = i + 1;
    }
    return sum;
}

void main(void)
{
    int result;
    
    /* Inicializa o array */
    test_array[0] = 5;
    test_array[1] = 10;
    test_array[2] = 15;
    
    /* Chama função passando array como parâmetro */
    result = sum_array(test_array, 3);
    
    /* Deve imprimir 30 (5+10+15) */
    output(result);
}