int globalvar;

int testscope(int param)
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
    
    localmain = testscope(10);

    output(localmain);

    output(globalvar);

    globalvar = globalvar + localmain;

    output(globalvar);
}