int main(void){
    int offset;
    int i;
    offset = input();
    i = 0;
    while (i < 10){
        offset = offset + 100;
        i = i + 1;
        output(offset);
    }
}
