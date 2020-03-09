
#include <stdio.h>
#include "estrutura.h"
#include <stdlib.h>


int obter_estado_casa(ESTADO *e, COORDENADA c)
{
    int colunaJ,linhaJ;
    c.coluna = colunaJ;
    c.linha = linhaJ;


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