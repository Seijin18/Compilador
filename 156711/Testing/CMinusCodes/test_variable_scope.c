int globalvar;

int test_scope(int param)
{
    int localvar;
    localvar = param + 5;
    globalvar = localvar * 2;
    return localvar;
}

void main(void)
{
    int localmain;
    
    globalvar = 100;
    
    localmain = test_scope(10);

    output(localmain);

    output(globalvar);

    globalvar = globalvar + localmain;

    output(globalvar);
}