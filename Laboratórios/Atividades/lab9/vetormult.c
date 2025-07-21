#include <stdio.h>
#include <stdlib.h>

void imprime(int vetor[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ",vetor[i]);
}

void multiplica(int vetor[], int n, double v){
    for (int i = 0; i < n; i++){
        vetor[i] *= v;
    }
}

int main(){
    int n=0;
    double v=0;
    scanf("%d\n",&n);
    int vetor[n];
    for (int i = 0; i < n; i++){
        scanf("%d\n",&vetor[i]);
    }
    scanf("%lf",&v);
    imprime(vetor,n);
    printf("\n");
    multiplica(vetor,n,v);
    imprime(vetor,n);
    printf("\n");
    multiplica(vetor,n,1/v);
    imprime(vetor,n);
}