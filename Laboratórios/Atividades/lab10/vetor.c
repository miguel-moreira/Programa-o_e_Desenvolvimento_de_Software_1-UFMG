#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int vetor[], int n){
    for (int i = 0; i < n; i++){
        scanf("%d",&vetor[i]);
    } 
}

void mostrar_vetor(int vetor[], int n){
    for (int i = 0; i < n; i++){
        printf("%d\n",vetor[i]);
    }
}

int main(){
    int n=0;
    scanf("%d",&n); //tamanho vetor
    int *vetor = (int *) malloc(n*sizeof(int));
    ler_vetor(vetor,n);
    mostrar_vetor(vetor,n);
    free(vetor);
}