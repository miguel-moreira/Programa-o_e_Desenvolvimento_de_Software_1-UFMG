#include <stdio.h>

int main(void)
{
    int i=228;
    do
    {
        if (i>=300 && i<=400)
            i+=3;   
        else 
            i+=5;
        printf("%d\n", i);      
        
    } while(i <457);

    return 0;
}