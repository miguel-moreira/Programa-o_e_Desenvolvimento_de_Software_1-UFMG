#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int penis(char string[], char caractere){
    if (*string == '\0')
        return 0;
    int c = (*string == caractere)? 1:0;
    return c + penis(string+1,caractere);
}

int main(){
    char buffer[100],carac;
    int arroz=0;
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1] = '\0';
    int tam = strlen(buffer);
    scanf("%c",&carac);
    arroz = penis(buffer,carac);
    printf("%d",arroz);
}