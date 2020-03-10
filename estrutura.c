
#include <stdio.h>
#include "estrutura.h"
#include <stdlib.h>

void set_ultima_jogada(ESTADO *e,COORDENADA c)
{
    COORDENADA ult_jog = {c.linha,c.coluna};
    e->ultima_jogada = ult_jog;
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
    int i=0,j=0;
    COORDENADA joga = {i,j};
    for (i ; i <8 ; ++i)
    {
        for ( j; j <8 ; ++j)
        {
           if ( e->tab[i][j] == PRETA)
               return joga;

        }

    }

}


CASA obter_estado_casa(ESTADO *e, COORDENADA c)
{

    return e->tab[c.linha][c.coluna];


}

int obter_jogador_atual(ESTADO *estado)
{
    return estado->jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *estado)
{
    return estado->num_jogadas;
}




ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1; // O Jogador da primeira jogada
    e->num_jogadas = 0; // quantas jogadas foram efetuadas

    for (int i = 0; i <8 ; ++i) {       // preenche o tabuleiro com VAZIO
        for (int j = 0; j <8 ; ++j) {
            e->tab[i][j] = VAZIO;
            if(i==3 && j ==4)
                printf("*");
            else printf(".");
        }
        printf("\n");
    }
    e->tab[3][4] = PRETA;

    return e;
}
