#include <stdio.h>
#include <string.h>

int is_leap_year(int ano)
{
    return (ano%4==0 && ano%100!=0 || ano%400==0);
}

int main()
{
    char buffer[50];
    int ano=0;
    while (1)
    {    
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) == 1 && buffer[0] == '\n')
            break;
        sscanf(buffer, "%d\n", &ano);

        printf("%d\n", is_leap_year(ano));
    }
    return 0;
}   