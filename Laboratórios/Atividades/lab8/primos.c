#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Faça uma função chamada primo que recebe como parâmetro um inteiro m e dois
outros inteiros p1 e p2 passados por referência. Ou seja, você deve passar o endereço
das variáveis e usar os conceitos de ponteiros ensinados na última aula. A função deve
armazenar em p1 o maior número primo que é menor do que m e deve armazenar em
p2 o menor número primo que é maior do que m. Você pode adaptar os métodos de
identificação de números primos discutidos em aulas anteriores. Cabeçalho: void
primos(int m, int *p1, int *p2); 

entrada                         saída
13 //valor de m                 17 
                                11 */

void primos(int m, int *p1, int *p2){
    int vetorp[m],x=2;                  //bloco para pegar o maior primo antes de m
    while (x < m){   
        int primo=1;
        for (int i = 2; i <= sqrt(m); i++){
            if (x % i == 0){
                primo=0;
                break;
            }
        }    
        if (primo){
            for (int j = 0; j < m; j++){
                vetorp[j]=x;
                *p1=vetorp[j];
            }
        }    
        x++;
    }
    
    int found=0;
    int num=m+1;
    while (!found){
        int primo=1;
        for (int i = 2; i <= sqrt(num); i++){   //bloco para pegar o menor primo depois de m
            if (num % i == 0){
                primo=0;
                break;
            }
        }
        if (primo)
            found=1;
        else
            num++;
    }   
    *p2=num;
}

int main(){
    int p1,p2,m;
    scanf("%d",&m);

    primos(m,&p1,&p2);
    printf("%d\n%d",p1,p2);

    return 0;
}

//throughout the heaven and the earth, i alone am the honored one