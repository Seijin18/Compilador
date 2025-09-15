int add(int a, int b)
{
    return a + b;
}

int multiply(int x, int y)
{
    return x * y;
}

int calculate(int num1, int num2)
{
    int sumresult;
    int multresult;
    
    sumresult = add(num1, num2);
    multresult = multiply(sumresult, 2);

    return multresult;
}

void main(void)
{
    int result;
    
    result = calculate(3, 7);
    
    output(result);
}