int data[4];

void main(void) {
    data[0] = 100;
    data[1] = 200; 
    data[2] = 300;
    data[3] = 400;
    
    output(data[2]);
    
    data[1] = data[0] + data[2];
    
    output(data[2]);
}