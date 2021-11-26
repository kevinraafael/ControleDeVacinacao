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
int cont = 0;
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
    cont++;
    //}
}
/*
A Função busca cpf recebe minha lista e o cpf a ser encontrado
se encontrar ela retorna o endereço do cpf , se não retorna null
*/
Pessoa *buscaCPF(Pessoa *lst, int cpf)
{
    Pessoa *p;
    p = lst;
    if (list == NULL)
    {
        return NULL;
    }
    while (p != NULL && p->cpf != cpf)
    {
        p = p->prox;
    }
    if (p->cpf == cpf)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}
Pessoa *buscaNome(Pessoa *lst, char *nome)
{
    Pessoa *p;
    p = lst;
    if (lst == NULL)
    {
        return NULL;
    }
    while (p != NULL && (strcmp(p->nome, nome) != 0))
    {
        p = p->prox;
    }
    if (strcmp(p->nome, nome) == 0)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

bool removePorCPF(Pessoa *lst, int cpf)
{
    Pessoa *remover = NULL;
}
bool removePorNome(Pessoa *lst, char *nome)
{
    Pessoa *ant = NULL;
    Pessoa *p;
    p = buscaNome(lst, nome);
    if (p != NULL && (strcmp(p->nome, nome) == 0))
    {
        lst = p->prox;
        ant = p->prox;
        free(p);
        printf("\nAcho que removi por nome\n");
        return true;
    }
    else
    {
        printf("\nNao removi por nome\n");

        return false;
    }
}

bool incrementaDosesPorCPF(Pessoa *lst, int cpf)
{
    Pessoa *p;
    p = buscaCPF(lst, cpf);
    if (p != NULL && p->nDoses < 2)
    {
        p->nDoses++;
        printf("OK!");
        return true;
    }
    printf("FAIL!");
    return false;
}
bool incrementaDosesPorNome(Pessoa *lst, char *nome)
{
    Pessoa *p;
    p = buscaNome(lst, nome);
    if (p != NULL && p->nDoses < 2)
    {
        p->nDoses++;
        printf("OK!");

        return true;
    }
    printf("FAIL!");

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
    int nDoses, nPessoas;
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
    char op, op2;
    scanf(" %c", &op);
    scanf(" %c", &op2);

    while (op != 'x' || op2 != 'x')
    {

        /* if (op == 'r')
{
    int cpf = 123;
    removePorCPF(list, cpf);
} */
        if (op == 'd' && op2 == 'c')
        {
            scanf("%d", &cpf);
            incrementaDosesPorCPF(list, cpf);
            removePorCPF(list, cpf);
        }
        if (op == 'd' && op2 == 'n')
        {
            scanf("%s", nome);
            incrementaDosesPorNome(list, nome);
        }
        if (op == 'i' && op2 == 'c')
        {
            scanf("%d", &cpf);
            aux = buscaCPF(list, cpf);
            imprimePessoa(aux);
        }
        if (op == 'i' && op2 == 'n')
        {
            scanf("%s", nome);
            aux = buscaNome(list, nome);
            imprimePessoa(aux);
        }
        printf("OPERACAO 1 - DOSE , REMOCAO OU IMPRESSAO\n");
        scanf(" %c", &op);

        printf("OPERACAO 2 - BUSCA POR NOME OU CPF\n");
        scanf(" %c", &op2);
    };

    // printf("\n DEPOIS DA REMOCAO \n");
    imprimeLista(list);

    //}

    printf("%d\n", cont);
}