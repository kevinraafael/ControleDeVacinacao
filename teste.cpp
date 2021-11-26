#include <cstdio>
#include <string.h>

int main()
{
    char nome1[50];
    char nome2[50];

    scanf("%s", nome1);
    scanf("%s", nome2);
    int x = strcmp(nome1, nome2);
    if (x == 0)
    {
        printf("iguais");
    }
    else
        printf("nao");
}