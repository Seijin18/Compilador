int numbers[5];

void main(void)
{
    int i;
    int sum;
    
    i = 0;
    while (i < 5) {
        numbers[i] = (i + 1) * 10;  /* 10, 20, 30, 40, 50 */
        i = i + 1;
    }
    
    i = 0;
    sum = 0;
    while (i < 5) {
        sum = sum + numbers[i];
        i = i + 1;
    }
    
    output(sum);  /* Deve imprimir 150 (10+20+30+40+50) */
    
    i = 0;
    while (i < 3) {
        output(numbers[i]);
        i = i + 1;
    }
}