#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double compsep;
    double largsep;
    double comppet;
    double largpet;
    char tipo[50];
}iris;

void classificar(iris nao_identificada, iris registros_identificados[], int n){    
    double vetor2[n];
    int num=0;
    for (int i = 0; i < n; i++){
        vetor2[i] = sqrt(pow(registros_identificados[i].compsep - nao_identificada.compsep,2)) + sqrt(pow(registros_identificados[i].largsep - nao_identificada.largsep,2)) + sqrt(pow(registros_identificados[i].comppet - nao_identificada.comppet,2)) + sqrt(pow(registros_identificados[i].largpet - nao_identificada.largpet,2));
    }
    
    double menor = vetor2[0];
    
    /* for (int k = 0; k < n; k++){
        printf("%.4lf\n",vetor2[k]);
    }
    */

    for (int j = 0; j < n; j++){
        if (menor>vetor2[j]){
            menor=vetor2[j];
            num=j;
        }
    }
    printf("%s",registros_identificados[num].tipo);  
}

int main(){
    int n;
    scanf("%d",&n);
    iris registros_identificados[n];
    iris nao_identificada;
    for (int i = 0; i < n; i++){
        scanf("%lf %lf %lf %lf %s",&registros_identificados[i].compsep,&registros_identificados[i].largsep,&registros_identificados[i].comppet,&registros_identificados[i].largpet,registros_identificados[i].tipo);
    }
    scanf("%lf %lf %lf %lf",&nao_identificada.compsep,&nao_identificada.largsep,&nao_identificada.comppet,&nao_identificada.largpet);
    classificar(nao_identificada, registros_identificados, n); 
}