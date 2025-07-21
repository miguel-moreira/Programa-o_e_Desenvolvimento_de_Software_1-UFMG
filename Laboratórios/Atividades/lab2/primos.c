#include <stdio.h>
#include <math.h>

int main()
{
    int x,y;
    scanf("%d %d", &x, &y);

    while (x <= y)   
    {    
        int primo = 1;
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                primo = 0;
                break;
            }
        }
        
        if (primo)
        {
            printf("%d\n", x);
        }
        
        x++;
        
    }     
    
    return 0;

}