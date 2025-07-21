#include <stdio.h>

int main()
{
    int nlinhas,ncols;
    scanf("%d %d", &nlinhas,&ncols);

    int matriz1[nlinhas][ncols];
    for (int l = 0; l < nlinhas; l++)
    {
        for (int c = 0; c < ncols; c++)
        {
            scanf("%d", &matriz1[l][c]);
        }
        
    }
    
    for (int l = 0; l < nlinhas; l++)
    {
        for (int c = 0; c < ncols; c++)
        {
            printf("%3d", matriz1[l][c] * -1);
        }
        printf("\n"); 
    }
    return 0;
}