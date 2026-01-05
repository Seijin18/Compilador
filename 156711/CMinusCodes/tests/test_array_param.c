int testarray[3];

int sumarray(int arr[], int size)
{
    int i;
    int sum;
    sum = 0;
    i = 0;
    while (i < size) {
        sum = sum + arr[i];
        i = i + 1;
    }
    return sum;
}

void main(void)
{
    int result;
    
    testarray[0] = 5;
    testarray[1] = 10;
    testarray[2] = 15;

    result = sumarray(testarray, 3);

    output(result);
}