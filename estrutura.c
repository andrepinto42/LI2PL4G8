#include <math.h>
#include <stdio.h>
#include "estrutura.h"
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

<<<<<<< HEAD
COORDENADA str_to_coord(char jog[])
{
    COORDENADA c1;
    if (jog[0] <= 105 && jog[0] >= 96 && jog[1] > 48 && jog[1] < 57)
        return c1 = (COORDENADA){.coluna = (jog[0] - 97) ,.linha= 7 -(jog[1] - 49) };

    else return c1 = (COORDENADA){.coluna = -1,.linha = -1};
}

=======
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654

void zerar_tabuleiro(ESTADO *e)
{
    e->jogador_atual = 1; // O Jogador da primeira jogada
    e->num_jogadas = 0; // quantas jogadas foram efetuadas
    e->num_comando = 0;
    for (int i = 0; i <8 ; ++i)
    {       // preenche o tabuleiro com VAZIO
        for (int j = 0; j <8 ; ++j)
        {
            e->tab[i][j] = VAZIO;
        }
    }
    e->tab[3][4] = BRANCA;
    e->tab[7][0] = UM;
    e->tab[0][7] = DOIS;
}


void set_num_jogadas(ESTADO *e,int num_jogs)
{
    e->num_jogadas = num_jogs;
}


void set_jogadas(ESTADO *e,COORDENADA c,int jogador,int num_jog)
{
    if (jogador == 1)
<<<<<<< HEAD

        e->jogadas[num_jog].jogador1 = c;

    else

        e->jogadas[num_jog].jogador2 = c;

=======
        e->jogadas[num_jog].jogador1 = c;
    else
        e->jogadas[num_jog].jogador1 = c;
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
}

void add_jogadas(ESTADO *e,COORDENADA c)
{
    if (e->jogador_atual == 1)
<<<<<<< HEAD
        e->jogadas[e->num_jogadas -1].jogador1 = c;
    else
        e->jogadas[e->num_jogadas -1].jogador2 = c;
=======
        e->jogadas[e->num_jogadas].jogador1 = c;
    else
        e->jogadas[e->num_jogadas].jogador2 = c;
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
}


int check_jogada_conteudo(JOGADA j)
{
    int j1linha = j.jogador1.linha ;
    int j1coluna = j.jogador1.coluna ;

    int j2linha = j.jogador2.linha ;
    int j2coluna = j.jogador2.coluna ;

<<<<<<< HEAD
    if (j1linha >= 0 && j1coluna >= 0)
    {
        if (j2linha >=0 && j2coluna >= 0)
=======
    if (j1linha > 0 && j1coluna > 0)
    {
        if (j2linha >0 && j2coluna > 0)
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
            return 2; //A Jogada tem coordenadas para ambos os jogadores;
        else return 1; // A jogada só tem coordenadas para o 1º Jogador
    }
    else return 0; // A jogada é vazia;
}


<<<<<<< HEAD
void print_movs_tab(ESTADO *e)
{
    int i=0,check;

    while (check = check_jogada_conteudo( e->jogadas[i]) )
    {
        if (( check == 2) || (check == 1) )
        {
            if (e->num_jogadas <10)
                printf("0");

            printf("%d: %c%d", i+1,97 + e->jogadas[i].jogador1.coluna, 8-e->jogadas[i].jogador1.linha);
            if (check == 2)
                printf(" %c%d\n",97 + e->jogadas[i].jogador2.coluna, 8-e->jogadas[i].jogador2.linha);
        }
        if (check == 1) printf("\n");
        i++;
    }
    printf("\n");
}


=======
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
void print_movs(ESTADO *e,FILE *file)
{
    int i=0,check;

    while (check = check_jogada_conteudo( e->jogadas[i]) )
    {
        if (( check == 2) || (check == 1) )
        {
            if (e->num_jogadas <10)
                fprintf(file,"0");

<<<<<<< HEAD
            fprintf(file,"%d: %c%d", i+1,97 + e->jogadas[i].jogador1.coluna, 8-e->jogadas[i].jogador1.linha);
=======
            fprintf(file,"%d : %c%d", i+1,97 + e->jogadas[i].jogador1.coluna, 8-e->jogadas[i].jogador1.linha);
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
            if (check == 2)
                fprintf(file," %c%d\n",                  97 + e->jogadas[i].jogador2.coluna, 8-e->jogadas[i].jogador2.linha);
        }
        if (check == 1) fprintf(file,"\n");
        i++;
    }
    fprintf(file,"\n");
}


void set_ultima_jogada(ESTADO *e,COORDENADA c)
{
    COORDENADA ult_jog = {c.linha,c.coluna};
}

void set_Branca_Tabuleiro(ESTADO *e,COORDENADA c)
{

    e->tab[c.linha][c.coluna] = BRANCA;
}
void set_Preta_Tabuleiro(ESTADO *e,COORDENADA c)
{

    e->tab[c.linha][c.coluna] = PRETA;
}




COORDENADA obter_pos_jogador(ESTADO *e)
{
    COORDENADA joga;

    for (int i=0 ; i <8 ; ++i)
    {
        for ( int j =0; j <8 ; ++j)
        {
           if ( e->tab[i][j] == BRANCA)
               return  joga =(COORDENADA){.linha = i,.coluna = j};
        }
    }
}



CASA obter_estado_casa(ESTADO *e, int linha,int coluna)
{
    return e->tab[linha][coluna];
}

void set_jogador_atual(ESTADO *e,int jogador)
{
    e->jogador_atual = jogador;
}

void incr_numero_de_jogadas(ESTADO *e)
{
    e->num_jogadas = e->num_jogadas + 1;
}

int obter_jogador_atual(ESTADO *estado)
{
    return estado->jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *estado)
{
    return estado->num_jogadas;
}

int obter_num_comando(ESTADO *e)
{
    return e->num_comando;
}
<<<<<<< HEAD

void print_erro(ERROS erro)
{
    if      (erro == OK) printf("OK\n");
    else if (erro == COORDENADA_INVALIDA) printf("Coordenada Inválida\n");
    else if (erro == JOGADA_INVALIDA) printf("Jogada Inválida\n");
    else if (erro == ERRO_LER_TAB) printf ("Erro ao ler o Tabuleiro\n");
    else if (erro == ERRO_ABRIR_FICHEIRO) printf("Erro ao Abrir Ficheiro\n");
    else if (erro == ACABOU) printf("ACABOU \n");
    else printf("Coordenada Ocupada\n");

}

int print_prompt(ESTADO *e)
{
    printf("# %d PL%d (%d)> ",
           obter_num_comando(e),obter_jogador_atual(e),obter_numero_de_jogadas(e)) ;
    return 1;
}

=======

void print_erro(ERROS erro)
{
    if      (erro == OK) printf("OK\n");
    else if (erro == COORDENADA_INVALIDA) printf("Coordenada Inválida\n");
    else if (erro == JOGADA_INVALIDA) printf("Jogada Inválida\n");
    else if (erro == ERRO_LER_TAB) printf ("Erro ao ler o Tabuleiro\n");
    else if (erro == ERRO_ABRIR_FICHEIRO) printf("Erro ao Abrir Ficheiro\n");
    else if (erro == ACABOU) printf("ACABOU \n");
    else printf("Coordenada Ocupada\n");

}

int print_prompt(ESTADO *e)
{
    printf("# %d PL%d (%d)> ",
           obter_num_comando(e),obter_jogador_atual(e),obter_numero_de_jogadas(e)) ;
    return 1;
}

>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
void set_casa(ESTADO *e,COORDENADA c,CASA casita)
{
    e->tab[c.linha][c.coluna] = casita;
}

ESTADO *inicializar_estado()
{
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1; // O Jogador da primeira jogada
    e->num_jogadas = 0; // quantas jogadas foram efetuadas
    e->num_comando = 0;
    for (int i = 0; i <8 ; ++i)
    {       // preenche o tabuleiro com VAZIO
        for (int j = 0; j <8 ; ++j)
        {
            e->tab[i][j] = VAZIO;
        }
    }
    e->tab[3][4] = BRANCA;
    e->tab[7][0] = UM;
    e->tab[0][7] = DOIS;
    for (int k = 0; k< 32 ; ++k)
    {
        e->jogadas[k].jogador1.coluna = -1;
        e->jogadas[k].jogador1.linha  = -1;
        e->jogadas[k].jogador2.coluna = -1;
        e->jogadas[k].jogador2.linha  = -1;
    }

    return e;
}




