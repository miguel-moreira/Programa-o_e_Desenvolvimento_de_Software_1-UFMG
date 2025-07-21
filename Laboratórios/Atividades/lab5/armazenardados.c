#include <stdio.h>
#include <string.h>

struct jadsom
{
    char nome[50];
    unsigned int  idade;
    float salario;
};

int main()
{
    struct jadsom jadsom[4];
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
            if (contador < 4)
            {
                char input[50];
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%s %u %f", jadsom[contador].nome, &jadsom[contador].idade, &jadsom[contador].salario);
                printf("Registro %s %u %.2f inserido\n", jadsom[contador].nome, jadsom[contador].idade, jadsom[contador].salario);
                //strcpy(aux, jadsom[contador].nome);
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
                    printf("Registro %s %u %.2f\n", jadsom[i].nome, jadsom[i].idade, jadsom[i].salario); 
                    aux2=1;
                    break;
                }
            
            }
            if (!aux2)
                printf("Registro ausente\n");
        }
    }
    return 0;
}