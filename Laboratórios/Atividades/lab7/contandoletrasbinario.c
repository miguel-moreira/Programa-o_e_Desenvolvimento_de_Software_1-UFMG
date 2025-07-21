#include <stdio.h>
#include <stdlib.h>

void read_and_print_file(const char *filename, int *aux) 
{    
    FILE *file = fopen(filename, "rb");

    unsigned char byte;
    int count=0;
    while (fread(&byte, sizeof(unsigned char), 1, file)) 
    {    
        if (byte == 'a')
            count++;
    }    
    *aux=count;
    fclose(file);
}

int main()
{
    int aux;
    char filename[100];
    scanf("%99s", filename);
    read_and_print_file(filename,&aux);
    printf("%d",aux);
    return 0;
}