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
        printf("Pessoa de nome: %s\n", p->nome);
        printf("CPF: %d\n", p->cpf);
        printf("Num. de doses aplicadas : %d\n", p->nDoses);
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
bool removePorCPF(Pessoa *lst, int cpf)
{
    Pessoa *ant = NULL;
    Pessoa *p;

    p = buscaCPF(lst, cpf);
    if (p != NULL && p->cpf == cpf)
    {
        lst = p->prox;
        ant = p->prox;
        free(p);
        printf("\nAcho que removi\n");
        return true;
    }
    else
    {
        printf("\nNao removi\n");

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
        return true;
    }
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
    char op, op2;

    // Teste pra ver se vindo NULL
    /*  aux = buscaCPF(list, 123);
     if (aux != NULL)
         printf(" O CPF DA BUSCA FOI ACHADO %d\n", aux->cpf);
     else
         printf("%p ", aux); */

    /*imprimir - i: Essa opção requisitar a impressão de uma pessoa
    • remover: - r: Essa opção sinaliza a remoção de uma pessoa da lista
    • incrementar doses - d: Essa opção sinaliza o incremento de número de doses de uma
    pessoa da lista
    */
    printf("\nANTES DA REMOCAO \n");
    imprimeLista(list);
    incrementaDosesPorCPF(list, 123);
    incrementaDosesPorCPF(list, 123);
    // incrementaDosesPorCPF(list, 123);
    op = 'r';
    // scanf("%c", &op);
    //  while (op != 'x')
    //{
    /* if (op == 'r')
    {
        int cpf = 123;
        removePorCPF(list, cpf);
    } */
    // printf("\n DEPOIS DA REMOCAO \n");
    imprimeLista(list);

    //}

    printf("%d\n", cont);
}