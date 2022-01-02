#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicamento{         // ESTRUTURAS medicamento
    int id;
    char nome[60];
    int quantidade;
    float preco;
    char laboratorio[60];
    float dosagem;
    char targa[10];
    char validade[12];
};

struct cliente{                                            

    char nome[60];
    char cpf[16];
    char telefone[15];
    char sangue[5];
    int id;
    char email[40];
    int medicamentoscomprou[10];
};

struct elementoM{
    struct medicamento dadomed;
    struct elementoM *prox;
};

typedef struct elementoM *ListaM;
typedef struct elementoM Elemed;

struct elemento{                                       //ESTRUTURAS PARA CLIENTE;
    struct cliente dadocliente;
    struct elemento *prox;
};

typedef struct elemento *Lista;
typedef struct elemento Elem;

ListaM *crialistaM(){                                       // CRIAR LISTA MEDICAMENTOS;
    ListaM *li = (ListaM *)malloc(sizeof(ListaM));
    if (li != NULL){
        *li = NULL;
    }
    return li;
}

int inserirlistaMed(struct medicamento Med, ListaM* listaM){        // INSERIR NO MEIO DA LISTA MEDICAMENTO (ordem crescente);
    if (listaM == NULL){
        return 0;
    }

    Elemed *no = (Elemed *)malloc(sizeof(Elemed));

    if (no == NULL){
        return 0;
    }

    no->dadomed = Med;

    if ((*listaM) == NULL){
        no->prox = *listaM;
        *listaM = no;
    }
    else{
        Elemed *ant, *at = *listaM;

        while (at != NULL && at->dadomed.id < Med.id){
            ant = at;
            at = at->prox;
        }

        if (at == (*listaM)){
            no->prox = (*listaM);
            (*listaM) = no;
        }
        else{
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}


void buscarMed(ListaM* li, int id, Lista* c){    
    int i, qtdcomprado = 0;                                     //BUSCAR MEDICAMENTO
    Elemed *aux = *li;
    Elem *auxc = *c;
    while (aux != NULL && aux->dadomed.id != id){
        aux = aux->prox;
    }
    if (aux == NULL){
        printf("Nenhum id cadastrado.\n");

    }else{
        setbuf(stdin, NULL);
        printf("ID: %d\n", aux->dadomed.id);
        setbuf(stdin, NULL);

        printf("Nome do Medicamento: %s\n", aux->dadomed.nome);
        setbuf(stdin, NULL);

		printf("Laboratorio: %s\n", aux->dadomed.laboratorio);
        setbuf(stdin, NULL);

		printf("Tarja: %s\n", aux->dadomed.targa);
        setbuf(stdin, NULL);

		printf("Validade: %s\n", aux->dadomed.validade);
        setbuf(stdin, NULL);

		printf("Preco: %.2f\n", aux->dadomed.preco);
        setbuf(stdin, NULL);

		printf("Dosagem: %.2f\n", aux->dadomed.dosagem);
        setbuf(stdin, NULL);

	    printf("Quantidade: %d\n\n", aux->dadomed.quantidade);
		setbuf(stdin, NULL);

        while(auxc != NULL){
            qtdcomprado = 0;
            for(i=0; i<10; i++){
                if(aux->dadomed.id == auxc->dadocliente.medicamentoscomprou[i]){
                    qtdcomprado++;
                }
            }
            if(qtdcomprado > 0){
                printf("Id do cliente: %d   Quantidade: %d\n\n", auxc->dadocliente.id, qtdcomprado);
            }
            
            auxc = auxc->prox;  
        }
    }
}

int removerMedicamento(ListaM *li, int id, Lista* c){              //EXCLUIR MEDICAMENTO
    if (li == NULL){
        printf("Nenhum medicamento encontrado!\n");
    }

    Elemed *anterior, *no = *li;
    Elem *listac = *c;

    while (no->prox != NULL && id != no->dadomed.id){
        anterior = no;
        no = no->prox;
    }
    if (no == NULL){
        printf("Id nao encontrado!\n");
        return 0;
    }
    if (no == *li){
        *li = no->prox;
    }
    else{
        anterior->prox = no->prox;
    }
    while(listac != NULL){
        for(int i=0; i<10; i++){
            if(id == listac->dadocliente.medicamentoscomprou[i]){
                listac->dadocliente.medicamentoscomprou[i] = NULL;

            }
        }
        listac = listac->prox;
    }

    free(no);
}

 void listarMedicamento(ListaM * li){                   // LISTAR MEDICAMENTOS
    
    Elemed *aux = *li;

    while (aux != NULL){   
        setbuf(stdin, NULL);
        printf("ID: %d\n", aux->dadomed.id);
        setbuf(stdin, NULL);

        printf("Nome do Medicamento: %s\n", aux->dadomed.nome);
        setbuf(stdin, NULL);

		printf("Laboratorio: %s\n", aux->dadomed.laboratorio);
        setbuf(stdin, NULL);

		printf("Tarja: %s\n", aux->dadomed.targa);
        setbuf(stdin, NULL);

		printf("Validade: %s\n", aux->dadomed.validade);
        setbuf(stdin, NULL);

		printf("Preco: %.2f\n", aux->dadomed.preco);
        setbuf(stdin, NULL);

		printf("Dosagem: %.2f\n", aux->dadomed.dosagem);
        setbuf(stdin, NULL);

	    printf("Quantidade: %d\n\n", aux->dadomed.quantidade);
		setbuf(stdin, NULL);
        

        aux = aux->prox;
    
    }
}

                                    



Lista *crialista(){                                                          // CRIAR LISTA CLIENTE;
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL){
        *li = NULL;
    }
    return li;
}

int inserirmeiocliente(struct cliente ccliente, Lista *listac){          //INSERIR MEIO CLIENTE (ordem alfabética);
    if (listac == NULL){
        return 0;
    }

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL){
        return 0;
    }

    no->dadocliente = ccliente;

    if ((*listac) == NULL){
        no->prox = *listac;
        *listac = no;
    }
    else{
        Elem *ant, *at = *listac;

        while (at != NULL && strcmp(at->dadocliente.nome, ccliente.nome) < 0){
            ant = at;
            at = at->prox;
        }

        if (at == (*listac)){
            no->prox = (*listac);
            (*listac) = no;
        }
        else{
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}

void buscarcliente(Lista *li, int id){                          //BUSCAR CLIENTE
    int i=0;
    Elem *aux = *li;
    while (aux != NULL && aux->dadocliente.id != id){
        aux = aux->prox;
    }
    if (aux == NULL){
        printf("ID nao encontrado!\n\n");
    }
    else{
        setbuf(stdin, NULL);
        printf("Nome: %s\n", aux->dadocliente.nome);
        setbuf(stdin, NULL);
        printf("CPF: %s\n", aux->dadocliente.cpf);
        setbuf(stdin, NULL);
        printf("Tipo sanguineo: %s\n", aux->dadocliente.sangue);
        setbuf(stdin, NULL);
        printf("E-mail: %s\n", aux->dadocliente.email);
        setbuf(stdin, NULL);
        printf("Telefone: %s\n", aux->dadocliente.telefone);
        setbuf(stdin, NULL);
        printf("Medicamento(s) comprado(s):\n");
        for(i=0; i<10; i++){
            if(aux->dadocliente.medicamentoscomprou[i] != NULL){
                printf("%d\n", aux->dadocliente.medicamentoscomprou[i]);
            }

        }
    }
}
int removemeiolistacliente(Lista *li, int id){              // EXCLUIR CLIENTE
    if (li == NULL){
		printf("Nenhum cliente cadastrado!\n");
    }
    Elem *anterior, *no = *li;
    while (no->prox != NULL && id != no->dadocliente.id){
        anterior = no;
        no = no->prox;
    }
    if (no == NULL){
        printf("Nenhum id encontrado!\n\n");
        return 0;
    }
    if (no == *li){
        *li = no->prox;
    }
    else{
        anterior->prox = no->prox;
    }
    printf("Cliente excluido com sucesso!\n\n");
    free(no);
}

void listarcliente(Lista * li){                         // LISTAR CLIENTE
    Elem *aux = *li;

    while (aux != NULL){
        setbuf(stdin, NULL);
        printf("Nome: %s\n", aux->dadocliente.nome);
        setbuf(stdin, NULL);
        printf("CPF: %s\n", aux->dadocliente.cpf);
        setbuf(stdin, NULL);
        printf("Tipo sanguineo: %s\n", aux->dadocliente.sangue);
        setbuf(stdin, NULL);
        printf("E-mail: %s\n", aux->dadocliente.email);
        setbuf(stdin, NULL);
        printf("Telefone: %s\n\n", aux->dadocliente.telefone);
        setbuf(stdin, NULL);

        aux = aux->prox;
    }
}

int comprarmedicamento(Lista* listac, ListaM* listaM){
    int idc, idm, i = 0, qtd;
    Elem *auxc = *listac;
    Elemed *auxm = *listaM;
    
    if (listac == NULL){
		printf("Nenhum cliente cadastrado!\n\n");
        return 0;
    }
    if(listaM == NULL){
        printf("Nenhum medicamento cadastrado!\n\n");
        return 0;
    }

    printf("Insira o id do Cliente:");
    scanf("%d", &idc);

    while (auxc != NULL && auxc->dadocliente.id != idc){
        auxc = auxc->prox;
    }
    if(auxc == NULL){
        printf("Nenhum cliente com este ID!\n\n");
        return 0;
    }else{
        printf("Insira o id do Medicamento:");
        scanf("%d", &idm);

        printf("Insira q quantidade de medicamento:");
        scanf("%d", &qtd);

        while (auxm != NULL && auxm->dadomed.id != idm){
            auxm = auxm->prox;
        }
        if(auxm == NULL){
            printf("Nenhum medicamento com este Id.\n\n");
            return 0;
        }else{
            while(qtd> 0){
                if(qtd <=auxm->dadomed.quantidade){
                    auxc->dadocliente.medicamentoscomprou[i] = auxm->dadomed.id;
                    i++;
                    auxm->dadomed.quantidade--;
                    qtd--;
                }else{
                    printf("Este medicamento nao esta mais disponivel!\n\n");
                    return 0;  
                }
            }
        }
    }
    printf("Compra realizada!\n\n");
}

int main(){
    struct medicamento cadastrarmedicamento;
    struct cliente cadastracliente;
    ListaM *listaM = crialistaM();
    Lista *listac = crialista();
    int op, op1, ok1, op2, ok2, id;

    do{
        printf("INSIRA A OPCAO DESEJADA:\n\n1-MENU DO CLIENTE\n2-MENU DO MEDICAMENTO\n3-COMPRAR MEDICAMENTO\n4-SAIR DO PROGRAMA\n");
        scanf("%d", &op);
        switch (op){
        case 1:{
             do{
                printf("\n1-CADASTRAR CLIENTE\n2-BUSCAR CLIENTE\n3-EXCLUIR CLIENTE\n4-LISTAR CLIENTES\n5-VOLTAR AO MENU PRINCIPAL\n");
                scanf("%d", &op1);

                switch (op1){
                case 1:
                    setbuf(stdin, NULL);
                    printf("Id:");
                    scanf("%d", &cadastracliente.id);
                    setbuf(stdin, NULL);
                    printf("Nome:");
                    fgets(cadastracliente.nome, 60, stdin);
                    setbuf(stdin, NULL);
                    printf("CPF:");
                    fgets(cadastracliente.cpf, 16, stdin);
                    setbuf(stdin, NULL);
                    printf("E-mail:");
                    fgets(cadastracliente.email, 40, stdin);
                    setbuf(stdin, NULL);
                    printf("Telefone:");
                    fgets(cadastracliente.telefone, 15, stdin);
                    setbuf(stdin, NULL);
                    printf("Tipo sanguineo:");
                    fgets(cadastracliente.sangue, 5, stdin);
                    setbuf(stdin, NULL);
                    for(int i=0; i<10; i++){
                        cadastracliente.medicamentoscomprou[i] = NULL;
                    }
                    ok1 = inserirmeiocliente(cadastracliente, listac);

                    break;
                case 2:
                    printf("Insira o id do cliente:");
                    scanf("%d", &id);
                    buscarcliente(listac, id);

                    break;

                case 3:
                
                    printf("Insira o id do cliente:");
                    scanf("%d", &id);
                    removemeiolistacliente(listac, id);
                    break;
                
                case 4:
                
                    listarcliente(listac);
                    break;
                
                default:
                    printf("\nOpcao invalida, tente novamente!\n");
                    break;
                }

            } while (op1 != 5);

            break;
        }

        case 2:
            do{
                printf("\n1-CADASTRAR MEDICAMENTO\n2-BUSCAR MEDICAMENTO\n3-EXCLUIR MEDICAMENTO\n4-LISTAR MEDICAMENTOS\n5-VOLTAR AO MENU PRINCIPAL\n");
                scanf("%d", &op2);

                switch (op2){
                    
                    case 1:

                        setbuf(stdin, NULL); 
                        printf("ID:");
                        scanf("%d", &cadastrarmedicamento.id);

                        setbuf(stdin, NULL);
                        printf("Nome do Medicamento:");
                        fgets(cadastrarmedicamento.nome, 60, stdin);

                        setbuf(stdin, NULL);	
                        printf("Laboratorio:");
                        fgets(cadastrarmedicamento.laboratorio, 60, stdin);

                        setbuf(stdin, NULL);	
                        printf("Tarja:");
                        fgets(cadastrarmedicamento.targa, 10, stdin);

                        setbuf(stdin, NULL);	
                        printf("Validade:");
                        fgets(cadastrarmedicamento.validade, 12, stdin);

                        setbuf(stdin, NULL);	
                        printf("Preco:");
                        scanf("%f",&cadastrarmedicamento.preco);

                        setbuf(stdin, NULL);	
                        printf("Dosagem:");
                        scanf("%f",&cadastrarmedicamento.dosagem);

                        setbuf(stdin, NULL);	
                        printf("Quantidade:");
                        scanf("%d",&cadastrarmedicamento.quantidade);

                        setbuf(stdin, NULL);
                        ok2 = inserirlistaMed(cadastrarmedicamento, listaM);
                            
                        break;
                    case 2:
                        printf("Insira a Id do Medicamento:");
                        scanf("%d", &id);
                       buscarMed(listaM, id, listac);

                        break;
                    case 3:
                        printf("Insira a ID do Medicamento para exclusao:");
                        scanf("%d", &id);
                        removerMedicamento(listaM, id, listac);
                        break;
                    case 4:
                        listarMedicamento(listaM);
                        break;
                    default:
                        printf("Opcao invalida, tente novamente!\n");
                        break;
                    }

            }while(op2 != 5);
    
            break;
        case 3:{
            comprarmedicamento(listac, listaM);
            break;
        }
        case 4:{
            printf("SAIR");
            free(listac);
            free(listaM);
            break;
        }
	    default:
            printf("\nOpcao invalida, tente novamente!\n");
            break;
        }

    }while(op != 4);
    
}