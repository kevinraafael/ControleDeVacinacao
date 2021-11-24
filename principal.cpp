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
    for (p = lst; p != NULL; p = p->prox)
    {
        printf("\n%s\n", p->nome);
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

int main()
{

    // Alocando espaço para  a minha lista
    list = (Pessoa *)malloc(sizeof(Pessoa));
    list->prox = NULL;

    char nome[101] = {"Pinheiro"};
    int cpf = 5555;
    // scanf(" %[^\n]", &nome);
    insere(list, nome, cpf);

    imprimeLista(list);
    printf("%d", cont);

    insere(list, nome, cpf);
    insere(list, nome, cpf);
    insere(list, nome, cpf);
}