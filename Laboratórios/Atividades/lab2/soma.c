#include <stdio.h>

int main(void)
{
    int soma, n, i;

    scanf("%d", &n);
    soma=0;
    for (i = 1; i <= n; i++)
    {
        soma += i;
    }
    printf("%d", soma);

    return 0;
     
}
