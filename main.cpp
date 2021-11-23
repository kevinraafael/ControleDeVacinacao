#include <cstdio>
#include <stdlib.h>

struct Pessoa
{
    char nome[101];
    int cpf;
    int nDoses;
    Pessoa *prox;
};

Pessoa *lst;

void imprimeLista(Pessoa *lst)
{
    Pessoa *p;
    for (p = lst; p != NULL; p = p->prox)
    {
        printf("%d\n", p->cpf);
    }
}

bool insere(Pessoa *lst, char *nome, int cpf)
{
    if (lst == NULL) // Verifica se ela existe , se a lista não existe retorna 0
        return false;
    Pessoa *celula = (Pessoa *)malloc(sizeof(Pessoa)); // Criei um espaço para recber o conteúdo
    if (celula == NULL)
        return false; // Retorno falso pois deu erro
    *celula->nome = *nome;
    celula->cpf = cpf;
    printf("Inseriu?");
    return true;
}

int main()
{
    // Alocando espaço para  a minha lista
    lst = (Pessoa *)malloc(sizeof(Pessoa));
    lst->prox = NULL;
    char nome[101];
    int cpf = 123;
    scanf(" %[^\n]", nome);
    insere(lst, nome, cpf);
    imprimeLista(lst);
}
