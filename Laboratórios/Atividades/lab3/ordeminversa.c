#include <stdio.h>

int main()
{
    int vetx[10];
    int vety[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vetx[i]);      
    }

    for (int i = 0; i < 10; i++)
    {
        vety[i]=vetx[9-i];
        printf("%d\n", vety[i]);
    }

    return 0;
}   
