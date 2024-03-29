#include "estrutura.h"
#include "lógica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"

#define BUF_SIZE 1024

// Funçao que reconstroi a jogada apos o jogador jogar 
void reconstruir_jogadas(ESTADO *e,int num_jog)
{
    for (int i = 0; i <= num_jog; ++i)
    {
        int status = check_jogada_conteudo(e->jogadas[i]);
        if (status == 2 || status == 1)
        {
            COORDENADA cords1 = e->jogadas[i].jogador1;
            jogar(e, cords1);
            if (status == 2)
            {
                COORDENADA cords2 = e->jogadas[i].jogador2;
                jogar(e, cords2);
            }
        }

    }
}

void mostrar_tabuleiro(ESTADO *e);
// Funçao que le o tabuleiro e coloca a informaçao contida em dados.txt
ERROS ler_tabuleiro(ESTADO *e,FILE * file)
{
    int max=0,player = 1;
    for (int l = 0; l < 8; ++l)
    {
        char linha[BUF_SIZE];
        if(fgets(linha,BUF_SIZE,file) == NULL)
            return ERRO_LER_TAB;
        for (int c = 0; c <8 ; ++c)
        {
            COORDENADA C = {c,l};
            set_casa(e,C,(CASA) linha[c]); 
        }
    }


    char fake[BUF_SIZE];
    if (fgets(fake,BUF_SIZE,file) == NULL)
    {


        char linha[BUF_SIZE];

        while (fgets(linha, BUF_SIZE, file) != NULL) {
            int num_jog;
            char jog1[BUF_SIZE];
            char jog2[BUF_SIZE];
            int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
            if (num_tokens == 3) {
                COORDENADA c1 = str_to_coord(jog1);
                COORDENADA c2 = str_to_coord(jog2);
                set_jogadas(e, c1, 1, num_jog - 1);
                set_jogadas(e, c2, 2, num_jog - 1);
            } else if (num_tokens == 2) {
                COORDENADA c1 = str_to_coord(jog1);

                set_jogadas(e, c1, 1, num_jog - 1);

                player = 2;
            }
            if (num_jog > max) max = num_jog;
        }

        set_num_jogadas(e, max);
        set_jogador_atual(e, player);
        print_movs_tab(e);

        fclose(file);
    }
    return OK;
}


// Função que imprime o tabuleiro e mostra cada estado da casa no terminal 
void mostrar_tabuleiro(ESTADO *e)
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
            printf("%c",obter_estado_casa(e,j,i));
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
// funçao que grava o tabuleiro
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

    fprintf(f,"\n");
        print_movs(e,f);

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
int interpretador(ESTADO *e)
{
    char linha[BUF_SIZE],nomefile[BUF_SIZE];
    char col[2], lin[2];
    int num_jog;

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
            mostrar_tabuleiro(e);
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
        ERROS erro=ler(e,nomefile);

        if (erro == ERRO_ABRIR_FICHEIRO)
            print_erro(erro);

        else
        mostrar_tabuleiro(e);

     }

    if (strcmp(linha,"Q\n") == 0)
        return 0;

    if (sscanf(linha,"pos %d",&num_jog) == 1)
    {
        num_jog--;
        zerar_tabuleiro(e);
        reconstruir_jogadas(e,num_jog);
        mostrar_tabuleiro(e);

    }
    if (strcmp(linha,"movs\n") == 0)
    {
        printf("\n");
        print_movs_tab(e);


    }
    if (strcmp(linha,"jog1\n") == 0)
    {
        LISTA l = NULL;
        l = add_coords_lista(l,e); // adiciona na lista

        char* coords = devolve_cabeca(l); // coordenada da lista

        ERROS erro = jogar(e,str_to_coord(coords) ); // jogar a coordenada
        if (erro  == OK )
        {
            mostrar_tabuleiro(e);
        }
        else if (erro == ACABOU)
        {
            int vencedor = obter_jogador_atual(e);
            printf("Ganhou o jogador %d.Parabéns!\n", vencedor);
            return 0;
        }


    }
    if (strcmp(linha,"jog2\n") == 0)
    {
        LISTA l = NULL;
        l = add_coords_random(l,e); // adiciona na lista

        char* coords = devolve_cabeca(l); // coordenada da lista

        ERROS erro = jogar(e,str_to_coord(coords) ); // jogar a coordenada
        if (erro  == OK )
        {
            mostrar_tabuleiro(e);
        }
        else if (erro == ACABOU)
        {
            int vencedor = obter_jogador_atual(e);
            printf("Ganhou o jogador %d.Parabéns!\n", vencedor);
            return 0;
        }


    }



    return 1;
}

