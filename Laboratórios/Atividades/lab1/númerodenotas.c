#include <stdio.h>

int main(void)
{
   //os valores v1-v7 dizem respeito aos valores das notas 
   int montante, v1, v2, v3, v4, v5, v6, v7, resto; 

   scanf("%d", &montante);

   v1 = montante / 100;
   resto = montante % 100;
   printf("100:%d\n", v1);
   
   v2 = resto / 50;
   resto %= 50;
   printf("50:%d\n", v2);
   
   v3 = resto / 20;
   resto %= 20;
   printf("20:%d\n", v3);
   
   v4 = resto / 10;
   resto %= 10;
   printf("10:%d\n", v4);
   
   v5 = resto / 5;
   resto %= 5;
   printf("5:%d\n", v5);
   
   v6 = resto / 2;
   resto %= 2;
   printf("2:%d\n", v6);
   
   v7 = resto;
   printf("1:%d\n", v7);

   return 0;

}
