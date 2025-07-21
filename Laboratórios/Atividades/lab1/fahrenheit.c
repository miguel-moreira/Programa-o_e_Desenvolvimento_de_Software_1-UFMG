#include <stdio.h>

int main(void) 
{
    float temp;

    scanf("%f", &temp);
    printf("%.0f", 1.8 * temp + 32);
    return 0;

}