#include <stdio.h>

int main ()
{
    int x0,x1,n;
    scanf("%d%d%d",&n,&x0,&x1);
    printf("x0: %d\n x1: %d\n", x0, x1);

    for (int i = 2; i <= n; i++)
    {
        int xn = 4*x1 - 2*x0;
        printf("x%d: %d\n",i,xn);
        x0=x1;
        x1=xn;
    }
    
    return 0;
}