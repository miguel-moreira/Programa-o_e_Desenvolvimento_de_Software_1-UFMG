#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    fgets(str1, 100, stdin);

    int i,j;
    
    for (i = 0; str1[i] != '\0'; i++)
    {
    }

    for (j = 0; i > 0 ; i--, j++)
    {
        str2[j] = str1[i-1];
    }
    str2[j] = '\0';
    printf("%s", str2);
    
    return 0;
}