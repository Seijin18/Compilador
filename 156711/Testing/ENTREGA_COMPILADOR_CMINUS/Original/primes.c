int isPrime(int n) {
    int i;
    int j;
    int k;
    int remainder;
    
    if (n <= 1) {
        return 0;
    }
    
    i = 2;
    k = i * i;
    while (k <= n) {
        j = 0;
        while (j <= n) {
            j = j + i;
        }
        if (j == n + i) {
            return 0;
        }
        i = i + 1;
        k = i * i;
    }
    
    return 1;
}

void main(void) {
    int number;
    int result;
    
    number = input();
    result = isPrime(number);
    output(result);
}