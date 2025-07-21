#include <stdio.h>

int main(void)
{
    for (int i = 233; i < 457; i++)
    {
        if (i<=399 && i>=299)
            i+=4;
        else
            i+=2; 
   
    printf(" %i\n", i);
    }
   
    return 0;
}