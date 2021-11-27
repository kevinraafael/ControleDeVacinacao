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

void imprimePessoa(Pessoa *p)
{
    if (p != NULL)
    {
        printf("------------\n");
        printf("Pessoa de nome: %s\n", p->nome);
        printf("CPF: %d\n", p->cpf);
        printf("Num. de doses aplicadas : %d\n", p->nDoses);
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
    // Para a primeira inserção da lista
    /* if (lst->prox == NULL)
    {
        lst->prox = celula;
        celula->prox = NULL;
        cont++;
    } */

    // else
    //{
    //   O proximo da célula vai receber o próximo da minha lista,
    celula->prox = lst->prox; //
    list->prox = celula;

    //}
}
/*
A Função busca cpf recebe minha lista e o cpf a ser encontrado
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
    p = lst;
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

// bool removePorCPF(Pessoa *lst, int cpf)
//{
/*  Pessoa *p = buscaCPF(lst, cpf);
 Pessoa *aux = list;
 Pessoa *ant = NULL;
 if (p != NULL)
 {
     while (aux->prox != &&aux->cpf != p->cpf)
     {
         aux = aux->prox;
     }
 } */
/* Pessoa *lixo;
Pessoa *p = buscaCPF(lst, cpf);
if (p != NULL && p->prox != NULL)
{
    lixo = p->prox;
    p->prox = lst->prox;
    free(lixo);
    printf("OK!\n");
    return true;
}
return false; */

/*  Pessoa *p, *q;
 p = lst;
 q = lst->prox;
 while (q != NULL && q->cpf != cpf)
 {
     p = q;
     q = q->prox;
 }
 if (q != NULL)
 {
     p->prox = q->prox;
     free(q);
     return true;
 } */
//}
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

int main()
{

    // Alocando espaço para  a minha lista
    list = (Pessoa *)malloc(sizeof(Pessoa));
    list->prox = NULL;
    Pessoa *aux;
    // Declarando variáveis a serem uitlizadas
    char nome[101];
    int cpf;
    int nPessoas;
    scanf("%d", &nPessoas);
    for (int i = 0; i < nPessoas; i++)
    {
        scanf(" %[^\n]", nome);
        scanf("%d", &cpf);
        insere(list, nome, cpf);
    }
    // Ler as operações a serem realizadas na lista

    // Teste pra ver se vindo NULL
    /* char name[100] = "Kevin";
    aux = buscaNome(list, name); */
    /* if (aux != NULL)
        printf(" O Nome DA BUSCA FOI ACHADO %s\n", aux->nome);
    else
        printf("%p ", aux); */

    /*imprimir - i: Essa opção requisitar a impressão de uma pessoa
    • remover: - r: Essa opção sinaliza a remoção de uma pessoa da lista
    • incrementar doses - d: Essa opção sinaliza o incremento de número de doses de uma
    pessoa da lista
    */
    // printf("\nANTES DA REMOCAO \n");
    // imprimeLista(list);
    // incrementaDosesPorCPF(list, 123);
    // incrementaDosesPorNome(list, name);

    // incrementaDosesPorCPF(list, 123);
    // scanf("%c", &op);
    /* scanf("%c", &op);
    scanf("%c", &op2); */
    printf("OPERACAO 1 - DOSE , REMOCAO OU IMPRESSAO\n");
    char op, op2;
    scanf(" %c", &op);

    do
    {
        printf("OPERACAO 2 - BUSCA POR NOME OU CPF\n");

        scanf(" %c", &op2);
        if (op == 'd' && op2 == 'c')
        {
            scanf(" %d", &cpf);
            incrementaDosesPorCPF(list, cpf);
        }
        else if (op == 'd' && op2 == 'n')
        {
            scanf(" %[^\n]", nome);
            incrementaDosesPorNome(list, nome);
        }
        else if (op == 'i' && op2 == 'c')
        {
            scanf(" %d", &cpf);
            aux = buscaCPF(list, cpf);
            imprimePessoa(aux);
        }
        else if (op == 'i' && op2 == 'n')
        {
            scanf(" %[^\n]", nome);
            aux = buscaNome(list, nome);
            imprimePessoa(aux);
        }
        else if (op == 'r', op2 == 'n')
        {
            scanf(" %[^\n]", nome);
            removePorNome(list, nome);
        }
        else if (op == 'r', op2 == 'c')
        {
            scanf(" %d", &cpf);
            removePorCPF(list, cpf);
        }

        printf("OPERACAO 1 - DOSE , REMOCAO OU IMPRESSAO\n");
        scanf(" %c", &op);
    } while (op != 'x');

    // printf("\n DEPOIS DA REMOCAO \n");
    imprimeLista(list);

    //}
}