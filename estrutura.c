
#include <stdio.h>
#include "estrutura.h"
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

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

void set_numero_de_jogadas(ESTADO *e)
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

    return e;
}

void movs(ESTADO *e, COORDENADA){
    set_Preta_Tabuleiro(e, e->tab[c.linha][c.coluna]);
    set_Branca_Tabuleiro(e, COORDENADA);
    while ((e->num_jogadas)<10){
        printf("0%d : %d%d %d%d\n",num_jogadas,e->tab[c.linha],e->tab[c.coluna],COORDENADA);
    }
    else{
        printf("%d : %d%d %d%d\n",num_jogadas,e->tab[c.linha],e->tab[c.coluna],COORDENADA);
    }
}

