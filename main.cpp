#include <cstdio>
#include <stdlib.h>

struct Pessoa
{
    char nome[101];
    int cpf;
    int nDoses;
    Pessoa *prox;
};

typedef struct Pessoa *list;

list *li;
void imprimeLista(Pessoa *lst)
{
    Pessoa *p;
    for (p = lst; p != NULL; p = p->prox)
    {
        printf(" cpf: %d\n", p->cpf);
    }
}
list *criaLista()
{
    // Alocando espaço para a minha lista com cabeça
    list *li = (list *)malloc(sizeof(list));
    if (li != NULL)
    {
        *li = NULL;
    }
    return li;
}

void insere(Pessoa *lst, char *nome, int cpf)
{
    if (li == NULL)
    { // Verifica se ela existe , se a lista não existe retorna 0
        list *li = criaLista();
    }
    //   return fals
    Pessoa *celula;
    celula = (Pessoa *)malloc(sizeof(Pessoa)); // Criei um espaço para recber o conteúdo

    // if (celula == NULL)
    //   return false; // Retorno falso pois deu erro
    *celula->nome = *nome;
    celula->cpf = cpf;
    celula->nDoses = 0;
    celula->prox = *li; // digo que o proximo elemento dele é a propria lista
    // celula->prox = *lst;
    lst = celula; // Inicio da lista parssa a ser a nova célula que inseri.
    printf("Inseriu?\n");
    // return true;
}

void libera_lista(list *li)
{
    if (li != NULL)
    {
        Pessoa *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanhoLista(list *li)
{
    if (li == NULL)
    {
        return 0;
    }
    int cont = 0;
    Pessoa *no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(list *li)
{
    if (li == NULL)
    {
        return 1;
    }
    if (*li == NULL)
    {
        return 1;
    }
    return 0; // Se não estiver vazia
}

int main()
{
    char nome[101] = {"Kevin"};
    int cpf = 123;
    // int ndoses = 0;
    //  scanf(" %[^\n]", nome);

    insere(*li, nome, cpf);
    imprimeLista(*li);
    libera_lista(li);
}
