#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct filme{
    int id;
    char nome[60];
    char categoria[20];
    int qtd;
    float preco;
};

struct elemento{
    struct filme dadosfilme;
    struct elemento *prox;
    
};

typedef struct elemento *lista;
typedef struct elemento Elem;

lista* crialista(){
 lista* li = (lista*) malloc(sizeof(lista));
 if(li != NULL){
 *li = NULL;
 }
 return li;
}

int criarinicio(struct filme cf, lista* li){
    if(li == NULL){
     return 0;
    }
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
     return 0;
    }
    no->dadosfilme = cf;
    no->prox = (*li);
    *li = no;
    return 1;

}

void mostralista(lista* li){
    Elem* aux = *li;
 
    while(aux != NULL){
        setbuf(stdin, NULL);
        printf("Id: %d\n", aux->dadosfilme.id);
        setbuf(stdin, NULL);
        printf("Nome: %s\n", aux->dadosfilme.nome);
        setbuf(stdin, NULL);
        printf("Categoria: %s\n", aux->dadosfilme.categoria);
        setbuf(stdin, NULL);
        printf("Quantidade de copias: %d\n", aux->dadosfilme.qtd);
        setbuf(stdin, NULL);
        printf("Preco: %.2f\n\n\n", aux->dadosfilme.preco);
        setbuf(stdin, NULL);
        aux = aux->prox;
    }
    
}

int main(){
    struct filme cadastrafilme;
    int op, op2, ok;
    lista* li;
    li = crialista();
    
    do{
        printf("Insira a opcao desejada:\n\n1-Cadastrar filme\n2-Listar filmes\n3-Sair\n");
        scanf("%d", &op);
        
        switch(op){
            case 1:{
                do{
                    setbuf(stdin, NULL);
                    printf("Insira a ID do filme:");
                    scanf("%d", &cadastrafilme.id);
                    setbuf(stdin, NULL);       
                    printf("Insira o nome do filme:");
                    fgets(cadastrafilme.nome, 60, stdin);
                    setbuf(stdin, NULL);        
                    printf("Insira a categoria:");
                    fgets(cadastrafilme.categoria, 20, stdin);
                    setbuf(stdin, NULL);       
                    printf("Insira a quantidade de copias:");
                    scanf("%d", &cadastrafilme.qtd);
                     setbuf(stdin, NULL);       
                    printf("Insira o preco por locacao:");
                    scanf("%f", &cadastrafilme.preco);
                    setbuf(stdin, NULL);       
                    ok = criarinicio(cadastrafilme, li);
                            
                    printf("Deseja continuar cadastrando?\n1-Sim\n2-nao\n");
                    scanf("%d", &op2);
                    setbuf(stdin, NULL);        
                }while(op2 != 2);
                break;
            }
            case 2:{
                mostralista(li);
                break;
            }
            case 3:{
                printf("***SAIR***");
                break;
            }
            default:{
                printf("Opcao invalida, tente novamente!");
                break;
            }
        }  
       
        
    } while(op != 3);
}