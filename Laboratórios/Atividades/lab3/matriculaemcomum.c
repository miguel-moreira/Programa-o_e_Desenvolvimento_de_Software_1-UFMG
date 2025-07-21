#include <stdio.h>

int main()
{
    int nal=0,nc=0;
    scanf("%d",&nal);

    int matae[nal];
        for (int i = 0; i < nal; i++)
        {
            scanf("%d", &matae[i]);
        }

    scanf("%d",&nc);
    
    int matc[nc];
        for (int i = 0; i < nc; i++)
        {
            scanf("%d", &matc[i]);
        }
    
    for (int i = 0; i < nal; i++)
    {
        for (int j = 0; j < nc; j++)
        {
           if (matae[i] == matc[j])
           {
            printf("%d\n", matae[i]);
           }
           
        }
        
    }
 
    return 0;
}