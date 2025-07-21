#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define initial_capacity 10

typedef struct{
    int id;
    char name[50];
    char depart[50];
    float price;
}product;

typedef struct node{           
    product prod;
    struct node *left;
    struct node *right;
}node;

product *products = NULL;
int count = 0;
int capacity = initial_capacity;

void arraysortid(product *vetaux_depart, int n){          //linguagem C nao aceita passar string como parametro pra struct:(
    for (int i = 0; i < n; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++){
            if (vetaux_depart[j].id < vetaux_depart[menor].id)
                menor = j;
        }
        if (menor != i){
            product temp = vetaux_depart[i];
            vetaux_depart[i] = vetaux_depart[menor];
            vetaux_depart[menor] = temp;
        }
    }
}

void arraysortprice(product *vetaux_price, int n){
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++){
            if (vetaux_price[j].price < vetaux_price[menor].price)
                menor = j;
        }
        if (menor != i){
            product temp = vetaux_price[i];
            vetaux_price[i] = vetaux_price[menor];
            vetaux_price[menor] = temp;
        }
    }
}

node* createnode(product prod){
    node* newnode = (node*)calloc(1,sizeof(node));
    (*newnode).prod = prod;
    return newnode;
}

void free_tree(node* root){
    if (root != NULL) {
        free_tree((*root).left);
        free_tree((*root).right);
        free(root);
    }
}

void insert_node(node** root, product prod){
    if (*root == NULL){ *root = createnode(prod); return; }
    if (prod.id < (*(*root)).prod.id) insert_node(&(*(*root)).left,prod);
    if (prod.id > (*(*root)).prod.id) insert_node(&(*(*root)).right,prod);
}

int search_id(node* root, int idaux){
    if (root == NULL){ printf("Produto nao encontrado!\n"); return 0; }
    printf("(%s) %s - R$ %.2f\n",(*root).prod.depart,(*root).prod.name,(*root).prod.price);
    if ((*root).prod.id == idaux) return 1;
    if ((*root).prod.id < idaux) return search_id((*root).right,idaux);
    else return (search_id((*root).left,idaux));
}

int depart_quant(node* root, char departaux[50]){
    int i = 0;
    if(root == NULL) return 0;
    if (!strcmp((*root).prod.depart,departaux)) i=1;
    return i + depart_quant((*root).left,departaux) + depart_quant((*root).right,departaux);
}

void search_depart(node* root, char departaux[50], product *vetaux_depart, int *i){
    if (root == NULL) return;
    if (!strcmp((*root).prod.depart,departaux)){ vetaux_depart[*i] = (*root).prod; (*i)++; }
    search_depart((*root).left,departaux,vetaux_depart,i);
    search_depart((*root).right,departaux,vetaux_depart,i);
}

void print_depart_products(node* root, char departaux[50]){
    int size = depart_quant(root,departaux);
    if (size == 0){ printf("Departamento vazio!\n"); return; }

    int i=0;
    product *vetaux_depart = (product*)malloc(size*sizeof(product));
    search_depart(root,departaux,vetaux_depart,&i);
    arraysortid(vetaux_depart,size);

    for (int j = 0; j < size; j++){
        printf("(%s) %s - R$ %.2f\n",vetaux_depart[j].depart,vetaux_depart[j].name,vetaux_depart[j].price);
    }  
    
    free(vetaux_depart);
}   

void insert_prod(node** root){
    
    product newprod;
    scanf("%d %s %s %f",&newprod.id,newprod.name,newprod.depart,&newprod.price);
    
    products[count] = newprod;
    count++;

    insert_node(root, newprod);
}

int price_quant(node* root, float priceaux){
    int j = 0;
    if (root == NULL) return 0;
    if ((*root).prod.price <= priceaux) j = 1;
    return j + price_quant((*root).left,priceaux) + price_quant((*root).right,priceaux);
}

void search_price(node* root, float priceaux, product* vetaux_price, int *j){
    if (root == NULL) return;
    if ((*root).prod.price <= priceaux){ vetaux_price[*j] = (*root).prod; (*j)++; }
    search_price((*root).left,priceaux,vetaux_price,j);
    search_price((*root).right,priceaux,vetaux_price,j);
}

void print_price_products(node* root, float priceaux){
    int size = price_quant(root,priceaux);
    if (size == 0){ printf("Sem resultados para o filtro!\n"); return; }

    int j=0;
    product* vetaux_price = (product*)malloc(size*sizeof(product));
    search_price(root,priceaux,vetaux_price,&j);
    arraysortprice(vetaux_price,size);

    for (int k = 0; k < size; k++){
        printf("(%s) %s - R$ %.2f\n",vetaux_price[k].depart,vetaux_price[k].name,vetaux_price[k].price);
    }
    
    free(vetaux_price);
}

void info_read(FILE *file, node** root){
    products = (product *)malloc(capacity*10*sizeof(product));
    while (fscanf(file,"%d %s %s %f",&products[count].id,products[count].name,products[count].depart,&products[count].price) != EOF) count++;
    if (count > 0){
        *root = createnode(products[0]);
        for (int i = 1; i < count; i++)
            insert_node(root, products[i]);
    }
}

int main(int argc, char *argv[]){
    node* root = NULL;
    if (argc < 2){
        printf("Numero de argumentos passados incorreto\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen(argv[1],"r");
    if (file == NULL){
        perror("Error: \n");
        return EXIT_FAILURE;
    }
    info_read(file,&root);
    fclose(file);
    int option=0;
    printf("1 - Procurar por ID\n2 - Procurar por Departamento\n3 - Inserir Produto\n4 - Filtrar por Preco\n5 - Sair\n");
    while (1){
        scanf("%d",&option);
        if (option == 1){ int idaux=0; scanf("%d",&idaux); search_id(root,idaux); }
        if (option == 2){ char departaux[50]; scanf("%s",departaux); print_depart_products(root,departaux); }                     
        if (option == 3) insert_prod(&root);
        if (option == 4){ float priceaux=0; scanf("%f",&priceaux); print_price_products(root,priceaux); }
        if (option == 5){ free_tree(root); free(products); break; }
    }
    return 0;
}