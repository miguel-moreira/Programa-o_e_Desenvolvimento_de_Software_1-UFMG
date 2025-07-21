#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char marca[50];
    float preco;
} product;

int main() {
    product prod[8];
    float mtotal = 0, ptotal = 0, pmmarca = 0;
    char marcas[8][50];
    float somatotalmarca[8] = {0};
    int countmarcas[8] = {0}, totalmarcas = 0;

    for (int i = 0; i < 8; i++) {
        scanf("%s %s %f", prod[i].nome, prod[i].marca, &prod[i].preco);
    }

    for (int k = 0; k < 8; k++) {
        int aux = 0;
        for (int l = 0; l < totalmarcas; l++) {
            if (strcmp(prod[k].marca, marcas[l]) == 0) {
                countmarcas[l]++;
                somatotalmarca[l] += prod[k].preco;
                aux = 1;
                break;
            }
        }
        if (!aux) {
            strcpy(marcas[totalmarcas], prod[k].marca);
            countmarcas[totalmarcas] = 1;
            somatotalmarca[totalmarcas] = prod[k].preco;
            totalmarcas++;
        }
    }

    for (int j = 0; j < 8; j++) {
        ptotal += prod[j].preco;
    }
    mtotal = ptotal / 8;

    for (int m = 0; m < totalmarcas; m++) {
        printf("%s %d\n", marcas[m], countmarcas[m]);
    }

    printf("media total: %.2f\n", mtotal);

    for (int n = 0; n < totalmarcas; n++) {
        pmmarca = somatotalmarca[n] / countmarcas[n];
        printf("media %s: %.2f\n", marcas[n], pmmarca);
    }

    return 0;
}