#include <stdio.h>
#include <stdlib.h>

void media(double vet[], int n, int *i){
    double soma=0,media=0;
    double vetaux[n];
    for (int j = 0; j < n; j++){   
        scanf("%lf",&vet[j]); 
        soma+=vet[j];
        //printf("%lf\n",vetaux[j]);
    }       
       
    media=soma/n;
    //printf("soma:%lf\n media:%lf\n",soma,media);
    
    for (int m = 0; m < n; m++){
        vetaux[m]=vet[m]-media;
        if (vetaux[m]<0){
            vetaux[m]*=-1;    
           // printf("%lf\n",vetaux[m]);
        }
    }
    
    double menor=vetaux[0];

    for (int m = 0; m < n; m++){  
        if (menor>vetaux[m]){
            menor=vetaux[m];
            //printf("%.lf",vetaux[m]);
            *i=m;
        }       
    }    
}

int main(){
    int n,i=0;
    scanf("%d",&n);
    double vet[n];
    
    media(vet,n,&i);
    printf("%d\n",i);
    return 0;
}

//*i tem que passar a posição do elemento mais próximo da média
//fazer um algoritmo que determine qual o elemento mais próximo da média e sua posição
//o mais próximo da média no vetor "vetaux" será o elemento mais próximo de 0;