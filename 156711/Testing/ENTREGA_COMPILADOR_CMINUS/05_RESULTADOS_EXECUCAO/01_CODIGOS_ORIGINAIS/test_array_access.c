int data[4];

void main(void)
{
    int temp;
    
    data[0] = 100;
    data[1] = 200;
    data[2] = 300;
    data[3] = 400;
    
    temp = data[1];
    data[1] = data[0] + data[2];
    data[0] = temp;
    
    output(data[0]);
    output(data[1]);
    output(data[2]);
    output(data[3]);
}