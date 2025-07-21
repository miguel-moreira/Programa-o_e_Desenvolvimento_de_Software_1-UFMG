#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_and_print_file(const char *filename, int *aux) 
{    
    FILE *file = fopen(filename, "r");

    char line[256];
    int count=0;
    while (fgets(line,sizeof(line),file))
    {    
        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i]=='a')
                count++;
        }
    }    
    *aux=count;
    fclose(file);
}

int main(int argc, char *argv[])
{
    int aux;
    read_and_print_file(argv[1],&aux);
    printf("%d",aux);
    return 0;
}