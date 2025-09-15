/* Teste de loops while com manipulação de vetores
   Valida: estruturas de repetição, contadores, condições de parada */

int numbers[5];

void main(void)
{
    int i;
    int sum;
    
    /* Inicializa array usando loop */
    i = 0;
    while (i < 5) {
        numbers[i] = (i + 1) * 10;  /* 10, 20, 30, 40, 50 */
        i = i + 1;
    }
    
    /* Calcula soma usando loop */
    i = 0;
    sum = 0;
    while (i < 5) {
        sum = sum + numbers[i];
        i = i + 1;
    }
    
    /* Imprime resultado da soma */
    output(sum);  /* Deve imprimir 150 (10+20+30+40+50) */
    
    /* Imprime alguns elementos para verificação */
    i = 0;
    while (i < 3) {
        output(numbers[i]);
        i = i + 1;
    }
}