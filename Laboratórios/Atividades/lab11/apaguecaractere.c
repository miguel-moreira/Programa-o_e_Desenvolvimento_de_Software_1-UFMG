#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void penis(char string[], char caractere, char auxiliar[]){
    if (*string == '\0'){
        *auxiliar = '\0';
        return;
    }
    if (*string != caractere){
        *auxiliar = *string;
        penis(string+1,caractere,auxiliar+1);
    }
    else 
        penis(string+1,caractere,auxiliar);  
}

int main(){
    char buffer[100],auxiliar[100],carac;
    char arroz[100];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1] = '\0';
    scanf("%c",&carac);
    penis(buffer,carac,auxiliar);
    printf("%s",auxiliar);
}