#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define BUF_SIZE 1024


// Cria uma lista vazia
LISTA criar_lista()
{
    LISTA l = NULL;
    return l;
}
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor)
{
    LISTA l1 = malloc(sizeof(Nodo));
    l1->valor = valor;
    l1->prox = L;
    return l1;
}
// Devolve a cabeça da lista
void* devolve_cabeca(LISTA L)
{
    return L->valor;

}
// Devolve a cauda da lista
LISTA proximo(LISTA L)
{
    return L->prox;

}
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L)
{
    LISTA l1 = L->prox;
    free(L);
    return l1;
}
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L)
{
    if (L) return 0;
    else return 1;
}

int main()
{
        LISTA L = criar_lista(); // Criar uma lista vazia
        char linha[BUF_SIZE];

        printf("Insira várias linhas, acabando com CTRL-D:\n");

        // control-D é a tecla CTRL e a tecla D ao mesmo tempo
        // Em windows é capaz de ser CTRL-Z
        while (fgets(linha, BUF_SIZE, stdin) != 0)
        {
            // A função strdup cria uma cópia da string que foi lida
            // Insere uma cópia da linha lida na cabeça da lista
            L = insere_cabeca(L, strdup(linha));
        }

        printf("\n==============================\n");
        printf(  "=          PERCURSO          =\n");
        printf(  "==============================\n\n");
        // percorre sem remover os elementos da lista
        for (LISTA T = L; !lista_esta_vazia(T); T = proximo(T))
        {
            // Vai buscar a cabeça da lista
            // Passa do tipo genérico void * para char *
            char *str = (char *) devolve_cabeca(T);
            printf("%s", str);
        }

        printf("\n==============================\n");
        printf(  "=           REMOCAO          =\n");
        printf(  "==============================\n\n");
        // percorre e vai removendo a cabeça
        while (!lista_esta_vazia(L))
        {
            char *str = (char *) devolve_cabeca(L);
            L = remove_cabeca(L);
            printf("%s", str);
            free(str);
        }
        return 0;

}