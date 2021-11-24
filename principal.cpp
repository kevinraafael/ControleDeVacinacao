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
Pessoa *buscaCPF(Pessoa *lst)

    int main()
{

    // Alocando espaço para  a minha lista
    list = (Pessoa *)malloc(sizeof(Pessoa));
    list->prox = NULL;

    //Declarando variáveis a serem uitlizadas
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
    //Ler as operações a serem realizadas na lista
    char op, op2;
    /*imprimir - i: Essa opção requisitar a impressão de uma pessoa
    • remover: - r: Essa opção sinaliza a remoção de uma pessoa da lista
    • incrementar doses - d: Essa opção sinaliza o incremento de número de doses de uma
    pessoa da lista
    */
    scanf("%c", &op);
    while (op != 'x')
    {
    }

    imprimeLista(list);
    printf("%d\n", cont);
}