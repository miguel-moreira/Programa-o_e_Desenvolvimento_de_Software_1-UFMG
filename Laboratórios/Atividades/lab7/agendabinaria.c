#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct agenda{
    char nome[50];
    int idade;
    char telefone[20];
} agenda_a;


void inserir(FILE *file){
    agenda_a agenda;
    scanf("%s %d %s", agenda.nome, &agenda.idade, agenda.telefone);
    fseek(file, 0, SEEK_END);
    fwrite(&agenda, sizeof(agenda_a), 1, file);
    printf("Registro %s %d %s inserido\n", agenda.nome,agenda.idade,agenda.telefone);
}

void exibir(FILE *file){
    agenda_a agenda;
    char temp[50];
    scanf("%s", temp);
    fseek(file, 0, SEEK_SET);
    while(fread(&agenda, sizeof(agenda_a), 1, file)){
        if (!strcmp(agenda.nome, temp)){
            printf("Registro %s %d %s exibido\n", agenda.nome, agenda.idade, agenda.telefone);
            return;
        }
    }
    printf("Registro %s invalido\n", temp);
}

int excluir(FILE *file){
    int found = 0;
    agenda_a agenda;
    char temp[50];

    scanf("%s", temp);
    fseek(file, 0, SEEK_SET);

    while(fread(&agenda, sizeof(agenda_a), 1, file)){

        if (strcmp(agenda.nome, temp) == 0){
            printf("Registro %s %d %s excluido\n", agenda.nome, agenda.idade, agenda.telefone);
            strcpy(agenda.nome, "@@@@");
            fseek(file, -(sizeof(agenda_a)), SEEK_CUR);
            fwrite(&agenda, sizeof(agenda_a), 1, file);
            found++;
            break;
        }
    }
    if (found == 0){
        printf("Registro %s invalido\n", temp);
        return 0;
    }
    else return 1;
}

int counter_agenda(FILE *file){
    agenda_a agenda;
    int count = 0;
    fseek(file, 0, SEEK_SET);
    while(fread(&agenda, sizeof(agenda_a), 1, file)){
        count++;
    }
    return count;
}

void comparar(FILE *file){
    int quant_agenda = counter_agenda(file);
    char buffer[200];
    while (scanf("%s", buffer) == 1){
        if (!strcmp(buffer, "Inserir")){
            if (quant_agenda == 100){
                printf("Espaco insuficiente\n");
                continue;
            }
            inserir(file);
            quant_agenda++;
        }
        else if (!strcmp(buffer, "Excluir")){
            quant_agenda -= excluir(file);
        }
        else if (!strcmp(buffer, "Exibir")) 
            exibir(file);
    }
}

int main(){
    char filename[50];
    scanf("%s",filename);
    FILE *file = fopen(filename,"rb+");
    comparar(file);
    fclose(file);
}