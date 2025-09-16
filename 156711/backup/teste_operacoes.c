void main(void) {
    int a;
    int b;
    int resultado;
    
    a = input();
    b = input();
    
    resultado = a + b;
    output(resultado, 0);
    
    resultado = a - b;
    output(resultado, 0);
    
    resultado = a * b;
    output(resultado, 0);
    
    
    if (a < b) {
        output(1, 0);
    } else {
        output(0, 0);
    }
    
    if (a > b) {
        output(1, 0);
    } else {
        output(0, 0);
    }
    
    if (a == b) {
        output(1, 0);
    } else {
        output(0, 0);
    }
    
    if (a != b) {
        output(1, 0);
    } else {
        output(0, 0);
    }
}
