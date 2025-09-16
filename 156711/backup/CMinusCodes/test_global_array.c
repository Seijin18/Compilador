/* Teste básico de declaração e uso de vetor global
   Valida: declaração de vetor global, inicialização básica */

int global_array[5];

void main(void)
{
    int i;
    i = 0;
    
    /* Inicializa o vetor global com valores simples */
    global_array[0] = 10;
    global_array[1] = 20;
    global_array[2] = 30;
    
    /* Lê e imprime alguns valores para verificar funcionamento */
    output(global_array[0]);
    output(global_array[1]);
    output(global_array[2]);
}