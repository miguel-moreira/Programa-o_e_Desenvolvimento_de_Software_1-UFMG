#include <stdio.h>

int main()
{
    int n, aux=0;
    while (aux>=0 && aux<800)
    {
        scanf("%d", &n);
        aux = n;
        if (n>=0 && n<800)
        {
            int fib[n];
            fib[0]=0;
            fib[1]=1;

            for (int i = 2; i < n+1; i++)
            {
                fib[i]=fib[i-1] + fib[i-2];
            }
            printf("%d\n", fib[n]);
        } 
        
    }
    
    return 0;
}    
