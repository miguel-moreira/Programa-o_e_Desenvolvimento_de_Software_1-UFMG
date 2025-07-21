#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que aloque uma matriz dinamicamente e depois imprima os
valores da matriz. A matriz deve ser formada por N arrays de tamanhos idênticos, e
cada array deve ter seus valores preenchidos pelo usuário assim que for alocado. Ou
seja, cada array referente a uma linha da matriz deve ser preenchido antes do array
referente à próxima linha ser alocado. Imprima o conteúdo dos vetores e libere a
memória alocada para eles.*/

//scanf("%d", &mat[i*n_colunas + j]); 

void ler_matriz(int *matriz, int linhas, int cols){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < cols; j++){
            scanf("%d", &matriz[i*cols + j]);
        }
    }
}

void print_matriz(int *matriz, int linhas, int cols){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < cols; j++){
            printf("%3d ",matriz[i*cols + j]);
        }
        printf("\n"); 
    } 
}

int main(){
    int linhas=0, cols=0;
    scanf("%d %d",&linhas,&cols);
    int *matriz = (int *) malloc(cols * linhas * sizeof(int));
    ler_matriz(matriz,linhas,cols);
    print_matriz(matriz,linhas,cols);
    free(matriz);
    return 0;
}