#include <stdio.h>

int main()
{
    #define linhas 20
    #define colunas 20

    char tabuleiro1[linhas][colunas], tabuleiro2[linhas][colunas];   
    unsigned int n;
    int x,y;
    char tipo;
    char P[7][1], E[5][1], C[3][1]; 
    char direcao;

    //inicializa a matriz com '~'
    for (int i = 0; i < 20; i++) 
    {
        for (int j = 0; j < 20; j++) 
            tabuleiro1[i][j] = '~', tabuleiro2[i][j] = '~';
    }    
    
    scanf("%u\n",&n);
    
    //bloco para registrar a quantidade e os tipos de barco no tabuleiro 1
    for (int vezes = 0; vezes < n; vezes++)
    {
        scanf("%d %d %c %c",&x,&y,&tipo,&direcao); 
    
        if (direcao == 'H'){
            if (tipo == 'P')
            {
                for (int p = y - 3; p <= y + 3; p++)
                    tabuleiro1[x][p] = 'P';
            }    
            if (tipo == 'E')
            {
                for (int e = y - 2; e <= y + 2; e++)
                    tabuleiro1[x][e] = 'E';
            }  
            if (tipo == 'C')
            {
                for (int c = y - 1; c <= y + 1; c++)
                    tabuleiro1[x][c] = 'C'; 
            }
        }
        if (direcao == 'V'){
            if (tipo == 'P')
            {
                for (int p = x - 3; p <= x + 3; p++)
                    tabuleiro1[p][y] =  'P';         
            }
            if (tipo == 'E')
            {
                for (int e = x - 2; e <= x + 2; e++)
                    tabuleiro1[e][y] = 'E';
            }
            if (tipo == 'C')
            {
                for (int c = x - 1; c <= x + 1; c++)
                    tabuleiro1[c][y] = 'C';
            }
        }   
    }
    
    //bloco para registrar a quantidade e os tipos de barco no tabuleiro 2
    for (int vezes = 0; vezes < n; vezes++)
    {
        scanf("%d %d %c %c",&x,&y,&tipo,&direcao); 
    
        if (direcao == 'H'){
            if (tipo == 'P')
            {
                for (int p = y - 3; p <= y + 3; p++)
                    tabuleiro2[x][p] = 'P';
            }    
            if (tipo == 'E')
            {
                for (int e = y - 2; e <= y + 2; e++)
                    tabuleiro2[x][e] = 'E';
            }  
            if (tipo == 'C')
            {
                for (int c = y - 1; c <= y + 1; c++)
                    tabuleiro2[x][c] = 'C'; 
            }
        }
        if (direcao == 'V'){
            if (tipo == 'P')
            {
                for (int p = x - 3; p <= x + 3; p++)
                    tabuleiro2[p][y] =  'P';         
            }
            if (tipo == 'E')
            {
                for (int e = x - 2; e <= x + 2; e++)
                    tabuleiro2[e][y] = 'E';
            }
            if (tipo == 'C')
            {
                for (int c = x - 1; c <= x + 1; c++)
                    tabuleiro2[c][y] = 'C';
            }
        }   
    }
   
    //bloco para registrar os ataques do jogador 1
    unsigned int m;
    int cax1, cay1, cax2, cay2; //coordenadas de ataque x e coordenadas de ataque y
    int pontos1 = 0, pontos2 = 0;
    
    scanf("%u\n",&m);
    
    for (int a = 0; a < m; a++)
    {
        scanf("%d %d",&cax1,&cay1);
        
        if (cax1 >= 0 && cax1 < linhas && cay1 >= 0 && cay1 < colunas)
        {
            if (tabuleiro2[cax1][cay1] == 'P')
            {
                pontos1 += 10;
                tabuleiro2[cax1][cay1] = 'O';
            }
            if (tabuleiro2[cax1][cay1] == 'E')
            {
                pontos1 += 5;
                tabuleiro2[cax1][cay1] = 'O';
            }
            if (tabuleiro2[cax1][cay1] == 'C')
            {
                pontos1 += 2;
                tabuleiro2[cax1][cay1] = 'O';
            }
            if (tabuleiro2[cax1][cay1] == '~')
            {    
                tabuleiro2[cax1][cay1] = 'O';
            }    
        }      
    
   //bloco para registrar os ataques do jogador 2
        scanf("%d %d",&cax2,&cay2);

        if (cax2 >= 0 && cax2 < linhas && cay2 >= 0 && cay2 < colunas)
        {
            if (tabuleiro1[cax2][cay2] == 'P')
            {
                pontos2 += 10;
                tabuleiro1[cax2][cay2] = 'O';
            }
            if (tabuleiro1[cax2][cay2] == 'E')
            {
                pontos2 += 5;
                tabuleiro1[cax2][cay2] = 'O';
            }
            if (tabuleiro1[cax2][cay2] == 'C')
            {
                pontos2 += 2;
                tabuleiro1[cax2][cay2] = 'O';
            }
            if (tabuleiro1[cax2][cay2] == '~')
            {    
                tabuleiro1[cax2][cay2] = 'O';
            }
        }
    }

    
    //tabuleiro atualizado jogador 1
    printf("TABULEIRO JOGADOR 1\n");
    for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                printf("%3c", tabuleiro1[i][j]);
            }
            printf("\n");
        }
    
    //tabuleiro atualizdo jogador 2
    printf("TABULEIRO JOGADOR 2\n");
    for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                printf("%3c", tabuleiro2[i][j]);
            }
            printf("\n");
        }
    
    char g = '1', v = '2'; 
    if (pontos1 != pontos2)
    {    
        if (pontos1 > pontos2)
            printf("O jogador %c venceu com %d pontos, contra %d pontos do jogador %c.",g,pontos1,pontos2,v);
        if (pontos2 > pontos1)
            printf("O jogador %c venceu com %d pontos, contra %d pontos do jogador %c.",v,pontos2,pontos1,g);
    }
    if (pontos1 == pontos2)
    {
        printf("O jogo terminou empatado em %d pontos.", pontos1);
    }  

    return 0;
} 