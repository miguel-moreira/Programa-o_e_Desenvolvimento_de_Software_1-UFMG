#include <stdio.h>

int main()
{
    int alfa;
    int i=1;
    int p2=0,p3=0,p5=0,pall=0; 
    
    scanf("%d",&alfa);

    while (i<=alfa)
    {
        if (i % 2 == 0)
            p2++;
        if (i % 3 == 0)
            p3++;
        if (i % 5== 0)
            p5++;
        if (i%2==0 && i%3==0 && i%5==0)
            pall++;
        
        i++;

    }

    printf("Múltiplos de 2: %d\n", p2);
    printf("Múltiplos de 3: %d\n", p3);
    printf("Múltiplos de 5: %d\n", p5);
    printf("Múltiplos de 2, 3 e 5: %d\n", pall);

    return 0;
 
}