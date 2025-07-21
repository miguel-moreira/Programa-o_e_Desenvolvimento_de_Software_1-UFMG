#include <stdio.h>
#include <string.h>

struct jadsomcep
{
    char rua[50];
    unsigned int numero;
    char estado[50]; 
};

struct jadsom
{
    char nome[50];
    unsigned int  idade;
    float salario;
    struct jadsomcep endereco;
};

int main()
{
    struct jadsom jadsom[5];
    char buffer[50];
    int contador=0;
    char aux[50];

    while(1)
    {
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) == 1 && buffer[0] == '\n')
            break;
        buffer[strlen(buffer)-1] = '\0';   
        
        if(!strcmp(buffer, "inserir"))
        {
            if (contador < 5)
            {
                char input[50];
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%s %u %f %s %u %s", jadsom[contador].nome, &jadsom[contador].idade, &jadsom[contador].salario, jadsom[contador].endereco.rua, &jadsom[contador].endereco.numero, jadsom[contador].endereco.estado);
                printf("Registro %s %u %.2f %s %u %s inserido\n", jadsom[contador].nome, jadsom[contador].idade, jadsom[contador].salario, jadsom[contador].endereco.rua, jadsom[contador].endereco.numero, jadsom[contador].endereco.estado);
                contador++;
            }
            else
            {
                printf("Espaco insuficiente\n");
            }
        }   
        else if(!strcmp(buffer, "mostrar"))
        {
            fgets(aux, 50, stdin);
            aux[strlen(aux)-1] = '\0';
            int aux2=0;
            for (int i = 0; i < contador; i++)
            {
                if (!strcmp(aux, jadsom[i].nome))
                {   
                    printf("Registro %s %u %.2f %s %u %s\n", jadsom[i].nome, jadsom[i].idade, jadsom[i].salario, jadsom[i].endereco.rua, jadsom[i].endereco.numero, jadsom[i].endereco.estado);
                    aux2=1;
                    break;
                }
            }
            if (!aux2)
                printf("Registro ausente\n");
        }
         else if(!strcmp(buffer, "alterar"))
        {
            int aux2=0;
            char input[50];
            fgets(input, sizeof(input), stdin);
            char nome[50]; unsigned int idade; float salario;
            char rua[50]; unsigned int numero; char estado[50];
            sscanf(input, "%s %u %f %s %u %s", nome, &idade, &salario, rua, &numero, estado);
            
            for (int i = 0; i < contador; i++)
            {
                if (!strcmp(nome, jadsom[i].nome))
                {   
                    strcpy(jadsom[i].nome, nome);
                    jadsom[i].idade = idade;
                    jadsom[i].salario = salario;
                    strcpy(jadsom[i].endereco.rua, rua);
                    jadsom[i].endereco.numero = numero;
                    strcpy(jadsom[i].endereco.estado, estado);
                    printf("Registro %s %u %.2f %s %u %s alterado\n", jadsom[i].nome, jadsom[i].idade, jadsom[i].salario, jadsom[i].endereco.rua, jadsom[i].endereco.numero, jadsom[i].endereco.estado);
                    aux2=1;
                    break;
                }
            }
            if (!aux2)
                printf("Registro ausente para alteracao\n");
        }
    }
    return 0;
}