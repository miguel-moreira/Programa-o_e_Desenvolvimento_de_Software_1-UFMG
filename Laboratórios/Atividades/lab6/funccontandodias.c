#include <stdio.h>
#include <string.h>

int is_leap_year(int ano)
{
    return (ano%4==0 && (ano%100!=0 || ano%400==0));
}

void leap_year_quant(int ano, int *aux)
{
    int count=0;
    for (; ano <= 2020; ano++)
    {
        if (ano%4==0 && (ano%100!=0 || ano%400==0))
            count++;  
    }
    *aux=count;    
}

int calc_day_ot_year(int dia, int mes, int ano)
{
    int total_days[12]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    if (is_leap_year(ano))
        for (int i = 2; i < 12; i++)
        {
            total_days[i] += 1;
        }
    
    int day_ot_year=total_days[mes-1]+dia;
    return day_ot_year;
}

int difference(int dia, int mes, int ano)
{
    int day_ot_year = calc_day_ot_year(dia, mes, ano);
    int dif=0, aux3=0;
    if (day_ot_year >= 261)
    {
        aux3=day_ot_year - 261;
        dif=365*(2020 - ano) - aux3;
    }
    else if (day_ot_year <= 261)
    {
        aux3=261 - day_ot_year;
        dif=365*(2020 - ano) + aux3;
    }    
    return dif; 
}

int main()
{
    char buffer[50];
    int dia,mes,ano;
    
    while (1)
    {
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) == 1 && buffer[0] == '\n')
            break;
        sscanf(buffer, "%d %d %d", &dia,&mes,&ano);
        int dif=difference(dia,mes,ano);
        int count_leap;
        leap_year_quant(ano,&count_leap);
            printf("%d\n", dif+count_leap);
    }
    return 0;
}