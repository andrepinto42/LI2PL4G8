#include "estrutura.h"
#include <stdio.h>
#include "lógica.h"
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024


ERROS ler_tabuleiro(ESTADO *e,FILE * file)
{
    for (int l = 0; l < 8; ++l)
    {
        char linha[BUF_SIZE];
        if(fgets(linha,BUF_SIZE,file) == NULL)
            return ERRO_LER_TAB;
        for (int c = 0; c <8 ; ++c)
        {
            COORDENADA C = {c,l};
            set_casa(e,C,(CASA) linha[c]); // coloca no estado a informacao contida em dados.txt
        }
    }
    fclose(file);
    return OK;
}


// Função que imprime o tabuleiro
void mostrar_tabuleiro(ESTADO *e,FILE *f)
{
    for (int j = 0; j <8 ; ++j)
    {
         printf("%d ", 8-j);

        for (int i = 0; i < 8; ++i)
        {
            if ( j == 0 && i == 7)
                printf("2");
            else if (j == 7 && i == 0)
                printf ("1");
            else
            printf("%c",obter_estado_casa(e,j,i));//mostra cada estado da casa no terminal
        }
        printf("\n");
    }


        printf("  ");
        for (int c = 0; c < 8; ++c)
        {
            putchar('a' + c);
        }
        printf("\n");

}

void gravar_tabuleiro(ESTADO *e,char *filename)
{
    FILE *f = fopen(filename,"w");

        for (int j = 0; j <8 ; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            fprintf(f, "%c",obter_estado_casa(e,j,i));
        }
        fprintf(f,"\n");
    }

    fclose(f);
}


ERROS ler(ESTADO *e,char *file)
{
    FILE *f = fopen(file,"r");
    if (f == NULL)
        return ERRO_ABRIR_FICHEIRO;
    return ler_tabuleiro(e,f);
}



//Interpretador fornecido pelo guião
int interpretador(ESTADO *e,FILE *file)
{
    char linha[BUF_SIZE],nomefile[BUF_SIZE];
    char col[2], lin[2];

    e->num_comando++;
    print_prompt(e);

    if (fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if( (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) )
    {
        COORDENADA coord = {(*col - 'a'),7- (*lin - '1')};
        ERROS erro = jogar(e,coord);
        if (erro  == OK )
        {
            mostrar_tabuleiro(e, stdout);
        }
        else if (erro == ACABOU)
        {
            int vencedor = obter_jogador_atual(e);
            printf("Ganhou o jogador %d.Parabéns!\n", vencedor);
            return 0;
        }
        else
            print_erro(erro);
        return 1;

    }
    if (sscanf(linha,"gr %s",nomefile) == 1)
    {
       gravar_tabuleiro(e,nomefile);
    }
    if (sscanf(linha,"ler %s",nomefile) == 1)
    {
        ERROS erro;
        if ((erro =ler(e,nomefile)) == ERRO_ABRIR_FICHEIRO)
            print_erro(erro);
        else
        {
            FILE *f = fopen(nomefile,"r");
            mostrar_tabuleiro(e,f);

        }

    }



    return 1;
}

