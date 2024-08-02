#include<stdio.h>

int f(int n)
{
    return 7*n+5;
}

int g(int n,int c)
{
    return c*n;
}

int main()
{
    int c=8;
    int n=1;
    int n0=-1;
    for(n=1;n<=30;n++)
    {
        if(f(n)<=g(n,c))
        {
            n0=n;
            break;
        }
    }
    printf("The value of n0 is %d\n",n0);

    printf("n\tf(n)\tc*g(n)");
    for(n=10;n<=30;n++)
    {
        printf("%d\t%d\t%d\n",n,f(n),g(n,c));
    }

}
