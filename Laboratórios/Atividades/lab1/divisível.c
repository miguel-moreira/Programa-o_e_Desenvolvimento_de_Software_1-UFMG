#include <stdio.h>

int main(void){
    
    int x, y, z, mod;
    

    printf("Digite os 3 números:");
    scanf("%d %d %d", &x, &y, &z);

    if ((x % y == 0) && (x % z == 0)){
        printf("O número é divisível");
    }else {
        printf("O número não é divisível");
    } 

    return 0;
}
