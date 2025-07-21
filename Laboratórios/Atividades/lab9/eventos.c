#include <stdio.h>
#include <stdlib.h>

typedef enum{
    janeiro=1, fevereiro=2, marco=3, abril=4, maio=5, junho=6, julho=7, agosto=8, setembro=9, outubro=10, novembro=11, dezembro=12
}Mes; 

typedef struct{
    int dia;
    Mes mes;
    int ano;
}Data;

typedef struct{
    char nome[100];
    char local[100];
    Data d;
}Evento;

void cadastrar_eventos(Evento agenda[], int n){
    for (int i = 0; i < n; i++)
        scanf("%s %s %d %d %d",agenda[i].nome,agenda[i].local,&agenda[i].d.dia,&agenda[i].d.mes,&agenda[i].d.ano);  
}

void imprimir_eventos(Evento agenda[], Data d, int n){
    int dia,mes,ano,aux=0;
    scanf("%d %d %d",&dia,&mes,&ano);
    for (int i = 0; i < n; i++){
        if ((dia == agenda[i].d.dia) && (mes == agenda[i].d.mes) && (ano == agenda[i].d.ano)){
            printf("%s %s\n",agenda[i].nome,agenda[i].local);
            aux=1;
        }
    }
    if (aux == 0)
        printf("Nenhum evento encontrado!");
}        

int main(){
    int n;
    scanf("%d",&n);
    Evento agenda[n];
    Data d;
    cadastrar_eventos(agenda,n);
    imprimir_eventos(agenda,d,n);
}