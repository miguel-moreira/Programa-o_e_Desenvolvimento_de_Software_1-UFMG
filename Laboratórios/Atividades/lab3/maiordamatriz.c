#include <stdio.h>

int main()
{
    int nlinhas,ncols;
    scanf("%d %d", &nlinhas,&ncols);

    int matriz[nlinhas][ncols];
    for (int l = 0; l < nlinhas; l++)
    {
        for (int c = 0; c < ncols; c++)
        {
            scanf("%d", &matriz[l][c]);
        }
        
    }
    
    int ma = matriz[0][0];

    for (int l = 0; l < nlinhas; l++)
    {
        for (int c = 0; c < ncols; c++)
        {
            if (ma < matriz[l][c])
                    ma = matriz[l][c];
        } 
    }
    
    printf("%d\n", ma);
    
    return 0;
}