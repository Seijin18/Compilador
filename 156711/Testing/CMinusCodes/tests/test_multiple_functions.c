int add(int a, int b)
{
    return a + b;
}

int multiply(int x, int y)
{
    return x * y;
}

int calculate(int numa, int numb)
{
    int sumresult;
    int multresult;
    
    sumresult = add(numa, numb);
    multresult = multiply(sumresult, 2);

    return multresult;
}

void main(void)
{
    int result;
    
    result = calculate(3, 7);
    
    output(result);
}