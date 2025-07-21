#include <stdio.h> 
#include <stdlib.h>

int soma(int vetor[], int tamanho_vetor){
    if (tamanho_vetor == 0)
        return 0;
    if (tamanho_vetor == 1)
        return vetor[0];
    else    
        return vetor[tamanho_vetor-1] + soma(vetor,tamanho_vetor-1);
}

int main(){
    int tam=0,jeba=0;
    scanf("%d",&tam);
    int *vetor = (int *) malloc(tam*sizeof(int));
    for (int i = 0; i < tam; i++)
        scanf("%d",&vetor[i]);
    jeba = soma(vetor,tam);
    printf("%d",jeba);
    free(vetor);  
}