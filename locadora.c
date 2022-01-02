#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme
{
    int id;
    char nome[60];
    char categoria[30];
    int qtd;
    float preco;
};

struct cliente
{
    int id;
    char nome[60];
    char endereco[60];
    char email[30];
    char telefone[14];
};

int CadastrarCliente(struct cliente *pcliente, int contc)
{

    printf("Id: ");
    scanf("%d", &(pcliente + contc)->id);

    setbuf(stdin, NULL);
    printf("Nome: ");
    fgets((pcliente + contc)->nome, 60, stdin);

    setbuf(stdin, NULL);
    printf("Endereco: ");
    fgets((pcliente + contc)->endereco, 60, stdin);

    setbuf(stdin, NULL);
    printf("Telefone: ");
    fgets((pcliente + contc)->telefone, 14, stdin);

    setbuf(stdin, NULL);
    printf("E-mail: ");
    fgets((pcliente + contc)->email, 30, stdin);

    contc++;
    return contc;
}

void ListarCliente(struct cliente *pcliente, int contc)
{
    for (int i = 0; i < contc; i++)
    {
        if ((pcliente + i)->id != -9999)
        {
            printf("\nId: %d\n", (pcliente + i)->id);
            setbuf(stdin, NULL);
            printf("Nome: %s\n\n", (pcliente + i)->nome);
            setbuf(stdin, NULL);
        }
    }
}

void ExcluirCliente(struct cliente *pcliente, int contc)
{
    int aux, op;

    do
    {
        aux = 0;

        printf("\n\nInforme a ID do cliente a ser excluido: ");
        scanf("%d", &op);

        if (op > 0)
        {
            for (int i = 0; i < contc; i++)
            {
                if ((pcliente + i)->id == op)
                {
                    (pcliente + i)->id = -9999;
                    aux = 1;
                }
            }
        }

        if (aux > 0)
        {
            printf("\n\nCliente excluido com sucesso!\n\n");
        }
        else
        {
            printf("\n\nID do cliente invalida, tente novamente! ");
        }
    } while (aux == 0);
}

void BuscarCliente(struct cliente *pcliente, int contc)
{
    int op;

    printf("Insira a ID do cliente:");
    scanf("%d", &op);

    if (op > 0)
    {
        for (int i = 0; i < contc; i++)
        {
            if ((pcliente + i)->id == op)
            {
                printf("\nId: %d\n", (pcliente + i)->id);
                setbuf(stdin, NULL);
                printf("Nome: %s\n", (pcliente + i)->nome);
                setbuf(stdin, NULL);
                printf("Endereco: %s\n", (pcliente + i)->endereco);
                setbuf(stdin, NULL);
                printf("E-mail: %s\n", (pcliente + i)->email);
                setbuf(stdin, NULL);
                printf("Telefone: %s\n\n\n", (pcliente + i)->telefone);
                setbuf(stdin, NULL);
            }
        }
    }
    else
    {
        printf("Cliente nao encontrado!");
    }
}

int CadastrarFilme(struct filme *pfilme, int contf)
{

    printf("Id: ");
    scanf("%d", &(pfilme + contf)->id);

    setbuf(stdin, NULL);
    printf("Nome: ");
    fgets((pfilme + contf)->nome, 60, stdin);

    setbuf(stdin, NULL);
    printf("Catgoria: ");
    fgets((pfilme + contf)->categoria, 30, stdin);

    setbuf(stdin, NULL);
    printf("Quantidade: ");
    scanf("%d", &(pfilme + contf)->qtd);

    setbuf(stdin, NULL);
    printf("Preco: ");
    scanf("%f", &(pfilme + contf)->preco);

    contf++;
    return contf;
}

void ListarFilme(struct filme *pfilme, int contf)
{
    for (int i = 0; i < contf; i++)
    {
        if ((pfilme + i)->id != -9999)
        {
            printf("\nId: %d\n", (pfilme + i)->id);
            setbuf(stdin, NULL);
            printf("Nome: %s\n\n", (pfilme + i)->nome);
            setbuf(stdin, NULL);
        }
    }
}

void ExcluirFilme(struct filme *pfilme, int contf)
{
    int aux, op;

    do
    {
        aux = 0;

        printf("\n\nInforme a ID do filme a ser excluido: ");
        scanf("%d", &op);

        if (op > 0)
        {
            for (int i = 0; i < contf; i++)
            {
                if ((pfilme + i)->id == op)
                {
                    (pfilme + i)->id = -9999;
                    aux = 1;
                }
            }
        }

        if (aux > 0)
        {
            printf("\n\nFilme excluido com sucesso!\n\n");
        }
        else
        {
            printf("\n\nID do filme invalida, tente novamente! ");
        }
    } while (aux == 0);
}

void BuscarFilme(struct filme *pfilme, int contf)
{
    int op;

    printf("Insira a ID do filme:");
    scanf("%d", &op);

    if (op > 0)
    {
        for (int i = 0; i < contf; i++)
        {
            if ((pfilme + i)->id == op)
            {
                printf("Id: %d\n", (pfilme + i)->id);
                setbuf(stdin, NULL);
                printf("Nome: %s\n", (pfilme + i)->nome);
                setbuf(stdin, NULL);
                printf("Quantidade: %d\n", (pfilme + i)->qtd);
                printf("Preco: %.2f\n\n", (pfilme + i)->preco);
            }
        }
    }
    else
    {
        printf("Filme nao encontrado!");
    }
}

int main(void)
{
    struct cliente *pcliente;
    struct filme *pfilme;

    int contc = 0, op, menuc, menuf, contf = 0;

    do
    {
        printf("Insira a opcao desejada:\n 1-Menu do cliente\n 2-Menu do Filme\n 3-Sair\n\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            printf("\n\nMenu do Cliente\n\n");
            printf("1 - Cadastrar cliente \n2 - Listar Clientes \n3 - Excluir Cliente \n4 - Buscar cliente\n");
            scanf("%d", &menuc);

            switch (menuc)
            {
            case 1:
            {
                if (pcliente != NULL)
                {
                    if (contc == 0)
                    {
                        pcliente = (struct cliente *)malloc(sizeof(struct cliente));
                    }
                    else
                    {
                        pcliente = (struct cliente *)realloc(pcliente, sizeof(struct cliente));
                    }
                    contc = CadastrarCliente(pcliente, contc);
                }
                else
                {
                    printf("\n\nMemoria indisponivel!");
                }

                break;
            }
            case 2:
            {
                ListarCliente(pcliente, contc);
                break;
            }
            case 3:
            {
                ExcluirCliente(pcliente, contc);
                break;
            }
            case 4:
            {
                BuscarCliente(pcliente, contc);
                break;
            }
            default:
            {
                printf("\n\nOpcao invalida!\n");
            }
            }
            break;
        }
        case 2:
        {
            printf("\n\nMenu do Filme\n\n");
            printf("1-Cadastrar Filme\n2-Listar Filmes\n3-Excluir Filme\n4-Buscar Filme\n");
            scanf("%d", &menuf);

            switch (menuf)
            {
            case 1:
            {
                if (pfilme != NULL)
                {
                    if (contf == 0)
                    {
                        pfilme = (struct filme *)malloc(sizeof(struct filme));
                    }
                    else
                    {
                        pfilme = (struct filme *)realloc(pfilme, sizeof(struct filme));
                    }
                    contf = CadastrarFilme(pfilme, contf);
                }
                else
                {
                    printf("\n\nMemoria indisponivel!");
                }
                break;
            }
            case 2:
            {
                ListarFilme(pfilme, contf);
                break;
            }
            case 3:
            {
                ExcluirFilme(pfilme, contf);
                break;
            }
            case 4:
            {
                BuscarFilme(pfilme, contf);
                break;
            }
            default:
            {
                printf("\n\nOpcao invalida!\n");
                break;
            }
            }
            break;
        }
        default:
        {
            printf("\n\nOpcao invalida!\n");
            break;
        }
        }

    } while (op != 3);

    free(pcliente);
    free(pfilme);
}
