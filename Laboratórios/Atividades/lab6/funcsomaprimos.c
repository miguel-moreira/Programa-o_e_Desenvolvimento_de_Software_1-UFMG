#include <stdio.h>
#include <math.h>
#include <string.h>

void Primo(long long n, long long vetorprimos[n], int *aux)
{   
    int contador=0, j=2;
    while (contador < n)
    {     
        int is_prime=1;
        for (int i = 2; i <= sqrt(j); i++)
        {    
            if (j % i == 0)
            {
                is_prime=0;
                break;   
            }
        }
            
        if (is_prime == 1)
        {
            vetorprimos[contador] = j;
            contador++;
        }    
        j++;
    }
    *aux=contador;
}

long long Soma_Primos(long long n, long long vetorprimos[n], int aux)
{
    long int soma=0;
    for (int i = 0; i < aux; i++)
    {
        soma += vetorprimos[i];
    }
    return soma;
}

int main()
{
    char buffer[50];
    long long n;
    int aux;
    while (1)
    { 
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) == 1 && buffer[0] == '\n')
            break;
        sscanf(buffer, "%lld", &n);
        
        long long vetorprimos[n];
        Primo(n,vetorprimos,&aux);
        long long soma = Soma_Primos(n,vetorprimos,aux);
        printf("%lld\n", soma);
    }
    return 0;
}