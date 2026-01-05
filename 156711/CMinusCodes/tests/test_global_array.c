int globalarray[5];

void main(void)
{
    int i;
    i = 0;
    
    globalarray[0] = 10;
    globalarray[1] = 20;
    globalarray[2] = 30;

    output(globalarray[0]);
    output(globalarray[1]);
    output(globalarray[2]);
}