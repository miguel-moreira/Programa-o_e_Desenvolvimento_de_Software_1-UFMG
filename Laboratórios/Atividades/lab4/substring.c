#include <stdio.h>

int main()
{

    char str[100], str2[100];

    fgets(str, 100, stdin);
    fgets(str2, 100, stdin);

    int k = 0;
    for(k; str2[k] != '\n'; k++){}

    //printf("%d", k);
    
    int j = 0;

    for(int i=0; str[i] != '\n'; i++){
        if(str[i] == str2[j]){
            j++;
            if(j == k){
                printf("É substring");
                return 0;
            }
        }else{
            if(j > 0) i--;
            j=0;
        }
    }

    printf("Não é substring");

    return 0;
}