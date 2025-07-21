#include <stdio.h>
#include <stdlib.h>

/*Para favorecer a consolidação do aprendizado de passagem de parâmetros por
referência e ponteiros, faça um programa em C que realize a soma de dois vetores e
armazene o resultado em um terceiro vetor. Os três vetores devem ser criados na
função main e passados como parâmetro para a função que realizará a soma. Dentro
da função main, você deve imprimir o conteúdo do vetor que contém a soma e depois
liberar a memória utilizada pelos três vetores. */

/*int soma_vetor(int *vet, int n){
    int soma=0;
    for (int i = 0; i < n; i++){
        soma += vet[i];        
    }
    return soma;
}*/

void print_vetor(int *vetsoma, int n){
    for (int i = 0; i < n; i++){
        printf("%d\n",vetsoma[i]);
    }     
}

void vetor_somakkkk(int *vetsoma, int *vet1, int *vet2, int n){
    for (int i = 0; i < n; i++){
        vetsoma[i] = vet1[i] + vet2[i];
    }
}

int main(){
    int n=0,soma1=0,soma2=0;
    scanf("%d",&n);
    int *vet1 = (int *) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d",&vet1[i]);
    }
    int *vet2 = (int *) malloc(n*sizeof(int));
    for (int j = 0; j < n; j++){
        scanf("%d",&vet2[j]);
    }
    int *vetsoma = (int *) malloc((n/2)*sizeof(int));  
    /*soma1 = soma_vetor(vet1,n);
    soma2 = soma_vetor(vet2,n); 
    vetsoma[0] = soma1;
    vetsoma[1] = soma2;*/

    vetor_somakkkk(vetsoma,vet1,vet2,n);
    print_vetor(vetsoma,n);
    free(vet1);
    free(vet2);
    free(vetsoma);
}