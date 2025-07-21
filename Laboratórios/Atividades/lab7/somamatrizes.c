#include <stdio.h>
#include <stdlib.h>

#define linhas 5
#define colunas 5

void mat_set_values(FILE *file, long long matrix[linhas][colunas])
{
    if (file == NULL)
    {    
        perror("Erro: ");
        exit(EXIT_FAILURE);
    }    
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
            fscanf(file,"%lld", &matrix[i][j]);
    }
    
}

void sum_mat(long long matrix1[linhas][colunas], long long matrix2[linhas][colunas], long long sum[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
    }
}

void print_mat(long long matrix[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
            printf("%lld ", matrix[i][j]);
        printf("\n");
    }  
}

int main()
{
    FILE *file;
    char filename[100];
    scanf("%99s", filename);
    long long matrix1[linhas][colunas], matrix2[linhas][colunas], sum[linhas][colunas];

    file = fopen(filename, "r");
    mat_set_values(file,matrix1);
    mat_set_values(file,matrix2);
    fclose(file);

    sum_mat(matrix1, matrix2, sum);
    print_mat(sum);
    
    return 0;
}