void main(void){
    int a;
    int b;
    int i;
    int original;
    a = input();
    b = input();
    original = a;
    a = 0;
    i = 0;
    while (i < b){
        a = a + original;
        i = i + 1;
    }
    output(a,0);
}