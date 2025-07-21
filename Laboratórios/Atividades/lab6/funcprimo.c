#include <stdio.h>
#include <math.h>
#include <string.h>

int is_prime(long long x)
{
    if (x < 2)
        return -1;
    for (long long i = 2; i <= (long long)sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return 0;
            break;   
        }
    }
    return 1;
}   

int main()
{
    int a;
    char buffer[50];
    while(1)
    {   
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) == 1 && buffer[0] == '\n')
            break;
        sscanf(buffer, "%lld", &a);
        printf("%d\n", is_prime(a));
    }
    return 0;
}