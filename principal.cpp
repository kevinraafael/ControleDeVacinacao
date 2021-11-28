#include <cstdio>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    char nome[101];
    int cpf;
    int nDoses;
    Pessoa *prox;
};

Pessoa *list = NULL;

/*A Função busca cpf recebe minha lista e o cpf a ser encontrado
se encontrar ela retorna o endereço do cpf , se não retorna null
*/
Pessoa *buscaCPF(Pessoa *lst, int cpf)
{
    Pessoa *p;
    p = lst->prox;
    if (list == NULL)
    {
        return NULL;
    }
    while (p != NULL)
    {
        if (p->cpf == cpf)
        {
            return p;
        }
        p = p->prox;
    }

    return NULL;
}
Pessoa *buscaNome(Pessoa *lst, char *nome)
{
    Pessoa *p;
    p = lst->prox;
    if (lst == NULL)
    {
        return NULL;
    }
    while (p != NULL)
    {
        if (strcmp(p->nome, nome) == 0)
        {
            return p;
        }
        p = p->prox;
    }

    return NULL;
}
void imprimePessoa(Pessoa *p)
{
    if (p != NULL && buscaCPF(list, p->cpf) != NULL)
    {
        printf("------------\n");
        printf("Pessoa de nome: %s\n", p->nome);
        printf("CPF: %d\n", p->cpf);
        printf("Num. de doses aplicadas: %d\n", p->nDoses);
        printf("------------\n");
    }
    else
    {
        printf("------------\n");
        printf("Pessoa de nome: null\n");
        printf("CPF: null\n");
        printf("Num. de doses aplicadas: null\n");
        printf("------------\n");
    }
}
void imprimeLista(Pessoa *lst)
{
    Pessoa *p;
    /*
    Nessa estrutura inicializo a minha lista apontando para o
    próximo  elemento , pois se colocar p = lst ele acaba imprimindo a cabeça
    que não possuí conteúdo relevante.
    */
    for (p = lst->prox; p != NULL; p = p->prox)
    {
        imprimePessoa(p);
    }
}

void insere(Pessoa *lst, char *nome, int cpf)
{
    Pessoa *celula;
    celula = (Pessoa *)malloc(sizeof(Pessoa)); // Criei um espaço para recber o conteúdo
    strcpy(celula->nome, nome);
    celula->cpf = cpf;
    celula->nDoses = 0;

    celula->prox = lst->prox;
    list->prox = celula;
}

bool removePorNome(Pessoa *lst, char *nome)
{
    Pessoa *ant = NULL;
    Pessoa *aux = lst;
    // p = buscaNome(lst, nome);

    while (aux != NULL && (strcmp(aux->nome, nome) != 0))
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("FAIL\n");
        return false;
    }
    else
    {
        if (ant == NULL) // Se o anterior for o primeiro elemento da lista
        {
            lst = aux->prox;
            free(aux);
        }
        else
        {
            ant->prox = aux->prox;
            free(aux);
            printf("OK!\n");
            return true;
        }
    }

    printf("FAIL!\n");
    return false;
}
bool removePorCPF(Pessoa *lst, int cpf)
{
    Pessoa *ant = NULL;
    Pessoa *aux = lst;
    // p = buscaNome(lst, nome);

    while (aux != NULL && aux->cpf != cpf)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("FAIL\n");
        return false;
    }
    else
    {
        if (ant == NULL) // Se o anterior for o primeiro elemento da lista
        {
            lst = aux->prox;
            free(aux);
        }
        else
        {
            ant->prox = aux->prox;
            free(aux);
            printf("OK!\n");
            return true;
        }
    }

    printf("FAIL!\n");
    return false;
}

bool incrementaDosesPorCPF(Pessoa *lst, int cpf)
{
    Pessoa *p;
    p = buscaCPF(lst, cpf);

    if (p != NULL && p->nDoses < 2)
    {
        p->nDoses++;
        printf("OK!\n");
        return true;
    }
    printf("FAIL!\n");
    return false;
}
bool incrementaDosesPorNome(Pessoa *lst, char *nome)
{
    Pessoa *p;
    p = buscaNome(lst, nome);
    if (p != NULL && p->nDoses < 2)
    {
        p->nDoses++;
        printf("OK!\n");

        return true;
    }
    printf("FAIL!\n");

    return false;
}
void limpalista(Pessoa *lst)
{
    Pessoa *p = lst->prox;
    while (p != NULL)
    {
        Pessoa *lixo = p;
        p = p->prox;

        free(lixo);
    }
    list->prox = NULL;
    free(lst);
}
int main()
{

    // Alocando espaço para  a minha lista
    list = (Pessoa *)malloc(sizeof(Pessoa));
    list->prox = NULL;
    Pessoa *aux = (Pessoa *)malloc(sizeof(Pessoa));
    // Declarando variáveis a serem uitlizadas
    char nome[101] = "";
    int cpf = 0;
    int nPessoas = 0;
    scanf("%d", &nPessoas);
    for (int i = 0; i < nPessoas; i++)
    {
        scanf(" %[^\n]", nome);
        scanf("%d", &cpf);
        insere(list, nome, cpf);
    }

    char op, op2;
    scanf(" %c", &op);

    do
    {

        scanf(" %c", &op2);
        switch (op)
        {
        case 'd':

            if (op2 == 'c')
            {
                scanf(" %d", &cpf);
                incrementaDosesPorCPF(list, cpf);
            }
            else if (op2 == 'n')
            {
                scanf(" %[^\n]", nome);
                incrementaDosesPorNome(list, nome);
            }
            break;
        case 'i':
            if (op2 == 'c')
            {
                scanf(" %d", &cpf);
                aux = buscaCPF(list, cpf);
                imprimePessoa(aux);
            }
            else if (op2 == 'n')
            {
                scanf(" %[^\n]", nome);
                aux = buscaNome(list, nome);
                imprimePessoa(aux);
            }
            break;
        case 'r':
            if (op2 == 'n')
            {
                scanf(" %[^\n]", nome);
                removePorNome(list, nome);
            }
            else if (op2 == 'c')
            {
                scanf(" %d", &cpf);
                removePorCPF(list, cpf);
            }
        default:
            break;
        }
        scanf(" %c", &op);
    } while (op != 'x');

    // printf("\n DEPOIS DA REMOCAO \n");
    imprimeLista(list);
    // printf("\nLIMPANDO\n");
    aux = NULL;

    limpalista(list);

    //}
}