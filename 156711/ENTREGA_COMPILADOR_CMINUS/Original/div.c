void main(void){
    int x;
    int y;
    int z;
    int i;
    x = input();
    y = input();
    z = 0;
    while (x >= y){
        x = x - y;
        z = z + 1;
    }
    output(z,0);
}