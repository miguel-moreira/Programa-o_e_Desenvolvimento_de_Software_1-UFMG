#include <stdio.h>
#include <math.h>

int main(void)
{
    double precisao, pi=0.0, dif;
    int vezes=0;
    scanf("%lf", &precisao);

    for (int k=0;; k++)
    {
        pi += pow(-1, k) * 4 / (2.0*k + 1); //tradução do somatório 
        vezes++;
        
        dif = M_PI - pi;
        if (dif < 0)
            dif = -dif;
        if (dif<precisao)
            break;

    } 
      
    printf("%d", vezes);
    
    return 0;
  
}
