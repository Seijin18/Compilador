/* Teste de acesso e modificação de elementos de vetor
   Valida: indexação de arrays, atribuição a elementos específicos, leitura de elementos */

int data[4];

void main(void)
{
    int temp;
    
    /* Teste de atribuição direta a elementos específicos */
    data[0] = 100;
    data[1] = 200;
    data[2] = 300;
    data[3] = 400;
    
    /* Teste de leitura e modificação */
    temp = data[1];           /* temp = 200 */
    data[1] = data[0] + data[2]; /* data[1] = 100 + 300 = 400 */
    data[0] = temp;           /* data[0] = 200 */
    
    /* Imprime valores modificados */
    output(data[0]);  /* Deve imprimir 200 */
    output(data[1]);  /* Deve imprimir 400 */
    output(data[2]);  /* Deve imprimir 300 */
    output(data[3]);  /* Deve imprimir 400 */
}