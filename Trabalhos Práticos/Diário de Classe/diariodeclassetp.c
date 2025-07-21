#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//7 funções no mínimo
#define MAX_CLASSES 2
#define MAX_STUDENTS 6

typedef struct{
    char studentname[100];
    char studentid[10];
    char situation[15];
    char concept;
    int grade1,grade2,grade3,media;
}student;

typedef struct{
    char classname[100];
    char classcode[10];
    student student_s[MAX_STUDENTS];
    int num_students;
}class;

typedef struct{
    char profname[100];
    char profid[10];
    class class_c[MAX_CLASSES];
    int num_classes;
}professor;

void concepts_situation(int x, int y, int z, int i, int j,professor* p){        //Determinar o conceito, a nota e a situação do aluno
    (*p).class_c[i].student_s[j].media = (x + y + z)/3;
    int media = (*p).class_c[i].student_s[j].media;
    char situacao[50],aprovado[9]={"Aprovado"},exameesp[15]={"Exame Especial"},reprovado[10]={"Reprovado"},conceito;
        if ((90 <= media) && (media <= 100)){
            (*p).class_c[i].student_s[j].concept = 'A';
            strcpy((*p).class_c[i].student_s[j].situation,aprovado);
        }
        if ((80 <= media) && (media <= 89)){
            (*p).class_c[i].student_s[j].concept = 'B';
            strcpy((*p).class_c[i].student_s[j].situation,aprovado);
        }
        if ((70 <= media) && (media <= 79)){
            (*p).class_c[i].student_s[j].concept = 'C';
            strcpy((*p).class_c[i].student_s[j].situation,aprovado);
        }
        if ((60 <= media) && (media <= 69)){
            (*p).class_c[i].student_s[j].concept = 'D';
            strcpy((*p).class_c[i].student_s[j].situation,aprovado);
        }
        if ((40 <= media) && (media <= 59)){
            (*p).class_c[i].student_s[j].concept = 'E';
            strcpy((*p).class_c[i].student_s[j].situation,exameesp);
        }
        if (media < 40){
            (*p).class_c[i].student_s[j].concept = 'F';
            strcpy((*p).class_c[i].student_s[j].situation,reprovado);
        }  
}

void info_professor(professor* p){                    //CERTA              //https://virtual.ufmg.br/20241/pluginfile.php/539772/mod_vpl/intro/image.png         
    fprintf(stdout,"Professor %s\n",(*p).profname);
    fprintf(stdout,"Registro numero %s\n",(*p).profid);            //bloco para ler informações do arquivo de entrada, printar a padrão e armazenar;
    for (int j = 0; j < (*p).num_classes; j++){
        fprintf(stdout,"Turma %d: %s - %s, %d alunos\n",j+1,(*p).class_c[j].classcode,(*p).class_c[j].classname,(*p).class_c[j].num_students);
    }
}

void info_student(professor* p){                //CERTA
    char buffer1[100],buffer2[100];                                                 //Informações do aluno, pega a matricula e o codigo da turma
    fscanf(stdin,"%s %[^\n]",buffer1,buffer2);
    fgetc(stdin);
    for (int i = 0; i < (*p).num_classes; i++){
        if (!strcmp(buffer2,(*p).class_c[i].classcode)){
            for (int j = 0; j < (*p).class_c[i].num_students; j++){
                if (!strcmp(buffer1,(*p).class_c[i].student_s[j].studentid)){
                    fprintf(stdout,"Aluno: %s\n",(*p).class_c[i].student_s[j].studentname);
                    fprintf(stdout,"Matricula: %s\n",(*p).class_c[i].student_s[j].studentid);
                    concepts_situation((*p).class_c[i].student_s[j].grade1,(*p).class_c[i].student_s[j].grade2,(*p).class_c[i].student_s[j].grade3,i,j,p);
                    fprintf(stdout,"Prova 1: %d / Prova 2: %d / Prova 3: %d\n",(*p).class_c[i].student_s[j].grade1,(*p).class_c[i].student_s[j].grade2,(*p).class_c[i].student_s[j].grade3);
                    fprintf(stdout,"Nota Final: %d - Conceito %c\n",(*p).class_c[i].student_s[j].media,(*p).class_c[i].student_s[j].concept);
                }   
            }
        }
    }
}

void insert_student(professor* p){                                      //CERTA
    char buffer1[100],buffer2[10],buffer3[10];                          //copiar as informações do buffer para o novo estudante e inicializar as novas notas com 0
    fscanf(stdin,"%[^\n] %s %[^\n]",buffer1,buffer2,buffer3);
    fgetc(stdin);
    for (int i = 0; i < (*p).num_classes; i++){
        if (!strcmp(buffer3,(*p).class_c[i].classcode)){
            if((*p).class_c[i].num_students < MAX_STUDENTS){
                strcpy((*p).class_c[i].student_s[(*p).class_c[i].num_students].studentname,buffer1);
                strcpy((*p).class_c[i].student_s[(*p).class_c[i].num_students].studentid,buffer2);
                (*p).class_c[i].student_s[(*p).class_c[i].num_students].grade1 = 0;
                (*p).class_c[i].student_s[(*p).class_c[i].num_students].grade2 = 0;
                (*p).class_c[i].student_s[(*p).class_c[i].num_students].grade3 = 0; 
                (*p).class_c[i].num_students++;
            }
        }
    }
}

void insert_grades(professor* p){               //CERTA
    char buffer1[10],buffer2[10];
    fscanf(stdin,"%s %[^\n]",buffer1,buffer2);
    for (int i = 0; i < (*p).num_classes; i++){
        if(!strcmp(buffer2,(*p).class_c[i].classcode)){
            for (int j = 0; j < (*p).class_c[i].num_students; j++){
                if(!strcmp(buffer1,(*p).class_c[i].student_s[j].studentid)){
                    fscanf(stdin,"%d %d %d",&(*p).class_c[i].student_s[j].grade1,&(*p).class_c[i].student_s[j].grade2,&(*p).class_c[i].student_s[j].grade3);
                    fgetc(stdin);
                }
            }
        }
    }  
}

void class_info(professor* p){        //CERTA
    char buffer[10];
    fscanf(stdin,"%[^\n]",buffer);
    fgetc(stdin);                                       //printar COD - NOME \n x alunos \n para cada aluno Aluno nome\n Matricula matricula\n, printa a turma e todos os seus alunos
    for (int i = 0; i < (*p).num_classes; i++){
        if(!strcmp(buffer,(*p).class_c[i].classcode)){
            fprintf(stdout,"Informacoes da turma %s - %s:\n%d alunos\n",(*p).class_c[i].classcode,(*p).class_c[i].classname,(*p).class_c[i].num_students);
            for (int j = 0; j < (*p).class_c[i].num_students; j++){
                fprintf(stdout,"Aluno: %s\nMatricula: %s\n",(*p).class_c[i].student_s[j].studentname,(*p).class_c[i].student_s[j].studentid);
            }
        }
    }   
}

void students_situation(professor* p){    //CERTA
    char buffer[10];                                                            //basicamente as informações + a situação
    fscanf(stdin,"%[^\n]",buffer);
    fgetc(stdin);
    for (int i = 0; i < (*p).num_classes; i++){
        if(!strcmp(buffer,(*p).class_c[i].classcode)){
            fprintf(stdout,"Situacao na turma %s - %s\n",(*p).class_c[i].classcode,(*p).class_c[i].classname);
            for (int j = 0; j < (*p).class_c[i].num_students; j++){
                fprintf(stdout,"Aluno: %s\nMatricula: %s\n",(*p).class_c[i].student_s[j].studentname,(*p).class_c[i].student_s[j].studentid);
                concepts_situation((*p).class_c[i].student_s[j].grade1,(*p).class_c[i].student_s[j].grade2,(*p).class_c[i].student_s[j].grade3,i,j,p);
                fprintf(stdout,"Nota Final: %d - Conceito %c\n",(*p).class_c[i].student_s[j].media,(*p).class_c[i].student_s[j].concept);
                fprintf(stdout,"Situacao: %s\n",(*p).class_c[i].student_s[j].situation);
            }
        }
    }
}

void data_export(FILE *file2, professor* p){
    fprintf(file2,"DADOS EXPORTADOS\n\n");                                              
    fprintf(file2,"Professor %s - Registro %s\n\n",(*p).profname,(*p).profid); 
    if ((*p).num_classes == 2){
        for (int i = 0; i < 1; i++){
            fprintf(file2,"Turma %s - %s\n",(*p).class_c[i].classcode,(*p).class_c[i].classname);
            for (int j = 0; j < (*p).class_c[i].num_students; j++){
                fprintf(file2,"Aluno: %s\nMatricula: %s\n",(*p).class_c[i].student_s[j].studentname,(*p).class_c[i].student_s[j].studentid);
                concepts_situation((*p).class_c[i].student_s[j].grade1,(*p).class_c[i].student_s[j].grade2,(*p).class_c[i].student_s[j].grade3,i,j,p);
                fprintf(file2,"Nota Final: %d - Conceito %c - %s\n",(*p).class_c[i].student_s[j].media,(*p).class_c[i].student_s[j].concept,(*p).class_c[i].student_s[j].situation);
            }               
        }   
        fprintf(file2,"\n");
        for (int i = 1; i < 2; i++){
            fprintf(file2,"Turma %s - %s\n",(*p).class_c[i].classcode,(*p).class_c[i].classname);
            for (int j = 0; j < (*p).class_c[i].num_students; j++){
                fprintf(file2,"Aluno: %s\nMatricula: %s\n",(*p).class_c[i].student_s[j].studentname,(*p).class_c[i].student_s[j].studentid);
                concepts_situation((*p).class_c[i].student_s[j].grade1,(*p).class_c[i].student_s[j].grade2,(*p).class_c[i].student_s[j].grade3,i,j,p);
                fprintf(file2,"Nota Final: %d - Conceito %c - %s\n",(*p).class_c[i].student_s[j].media,(*p).class_c[i].student_s[j].concept,(*p).class_c[i].student_s[j].situation);
            }   
        }   
    }
    else {
        for (int i = 0; i < (*p).num_classes; i++){
            fprintf(file2,"Turma %s - %s\n",(*p).class_c[i].classcode,(*p).class_c[i].classname);
            for (int j = 0; j < (*p).class_c[i].num_students; j++){
                fprintf(file2,"Aluno: %s\nMatricula: %s\n",(*p).class_c[i].student_s[j].studentname,(*p).class_c[i].student_s[j].studentid);
                concepts_situation((*p).class_c[i].student_s[j].grade1,(*p).class_c[i].student_s[j].grade2,(*p).class_c[i].student_s[j].grade3,i,j,p);
                fprintf(file2,"Nota Final: %d - Conceito %c - %s\n",(*p).class_c[i].student_s[j].media,(*p).class_c[i].student_s[j].concept,(*p).class_c[i].student_s[j].situation);
            }               
        }   
    }
}

void grades0(professor *p){                                 //Inicializar as notas de todos os alunos com 0
    for (int i = 0; i < (*p).num_classes; i++){
        for (int j = 0; j < (*p).class_c[i].num_students; j++){
            (*p).class_c[i].student_s[j].grade1 = 0;
            (*p).class_c[i].student_s[j].grade2 = 0;
            (*p).class_c[i].student_s[j].grade3 = 0; 
        }
    }
}

void info_read(FILE *file1,professor* p){
    fscanf(file1,"%[^\n] %s %d",(*p).profname,(*p).profid,&(*p).num_classes);         //bloco para ler informações do arquivo de entrada e armazenar;
    fgetc(file1);
    for (int i = 0; i < (*p).num_classes; i++){
        fscanf(file1,"%[^\n] %[^\n]",(*p).class_c[i].classname,(*p).class_c[i].classcode);
        fgetc(file1);
    }
    for (int j = 0; j < (*p).num_classes; j++){
        fscanf(file1,"%d",&(*p).class_c[j].num_students);
        fgetc(file1);
        for (int k = 0; k < (*p).class_c[j].num_students; k++){   
            fscanf(file1,"%[^\n] %s",(*p).class_c[j].student_s[k].studentname,(*p).class_c[j].student_s[k].studentid);
            fgetc(file1);
        }
    }
}

int main(int argc, char *argv[]){
    professor p;
    if (argc < 3){
        fprintf(stdout,"Quantidade de parametros incorreta ");
    }
    FILE *file1 = fopen(argv[1],"r");
        if (file1 == NULL){
            perror("Error: ");
            return EXIT_FAILURE;
        }
    FILE *file2 = fopen(argv[2],"w");
    
    info_read(file1,&p);
    grades0(&p);
    int option=0;
    printf("1 - Informacoes do Professor\n2 - Informacoes do Aluno\n3 - Inserir Aluno\n4 - Lancar Notas\n5 - Informacoes da Turma\n6 - Situacao dos Alunos\n7 - Exportar Dados\n");
    while(1){
        scanf("%d",&option);
        getchar();
            if (option == 1){
                info_professor(&p);                 //função menu estava dando erro,transferi pra main e deu certo;
            }
            if (option == 2){
                info_student(&p);
            }
            if (option == 3){
                insert_student(&p);
            }
            if (option == 4){
                insert_grades(&p);
            }
            if (option == 5){
                class_info(&p);
            }
            if (option == 6){
                students_situation(&p);
            }
            if (option == 7){
                data_export(file2,&p);  
                break;
            }    
    }

    fclose(file1);
    fclose(file2);
}