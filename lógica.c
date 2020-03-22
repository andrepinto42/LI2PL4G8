#include "estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int valido(ESTADO *e , COORDENADA c)
{
    int distlinha = pow(c.linha - obter_pos_jogador(e).linha,2);
    int distcoluna = pow(c.coluna - obter_pos_jogador(e).coluna,2);

    float dist = (sqrt( distlinha+ distcoluna ) ) ;

        if ( obter_estado_casa(e,c.linha,c.coluna) == VAZIO )
        {
            if (dist < 1.42 )
            return 1 ;

        }
    return 0 ;
}

int fim (ESTADO *e, COORDENADA c)
{
    {
        if ( c.coluna==0 && c.linha ==8 )
            return 3;
        if (c.coluna ==8 && c.linha ==0)
            return 2;
        if ( e-> tab[c.linha][c.coluna+1] ==PRETA && e-> tab[c.linha-1][c.coluna+1]==PRETA
             && e-> tab[c.linha-1][c.coluna-1] == PRETA && e-> tab[c.linha-1][c.coluna]==PRETA &&
        e-> tab[c.linha-1][c.coluna-1] == PRETA &&e-> tab[c.linha][c.coluna-1]==PRETA &&
        e-> tab[c.linha+1][c.coluna]==PRETA && e-> tab[c.linha+1][c.coluna+1]==PRETA &&
        e-> tab[c.linha][c.coluna]==BRANCA )
        {
            return 4;
        }
        if (( e-> tab[c.linha][8]==BRANCA && e-> tab[c.linha-1][8]==PRETA
              && e-> tab[c.linha-1][c.coluna-1] == PRETA && e-> tab[c.linha][c.coluna-1]==PRETA &&
              e-> tab[c.linha+1][8]==PRETA && e-> tab[c.linha+1][c.coluna-1]==PRETA) ||
            (e-> tab[0][c.coluna-1]==PRETA && e-> tab[0][c.coluna+1] == PRETA &&
             e-> tab[0][c.coluna]==BRANCA && e-> tab[c.linha+1][c.coluna]==PRETA &&
             e-> tab[c.linha+1][c.coluna-1]==PRETA && e-> tab[c.linha+1][c.coluna+1]==PRETA) ||

            ( e-> tab[c.linha][0] == BRANCA  && e-> tab[c.linha+1][0]==PRETA
              && e-> tab[c.linha-1][c.coluna+1] == PRETA && e-> tab[c.linha][c.coluna+1]==PRETA &&
              e-> tab[c.linha-1][0]==PRETA && e-> tab[c.linha+1][c.coluna+1]==PRETA)||

            ( e-> tab[8][c.coluna-1]==PRETA && e-> tab[8][c.coluna+1] == PRETA &&
              e-> tab[8][c.coluna]==BRANCA && e-> tab[c.linha-1][c.coluna+1]==PRETA &&
              e-> tab[c.linha-1][c.coluna-1]==PRETA &&  e->tab[c.linha-1][c.coluna]==PRETA) ||

            (e->tab[0][0]==BRANCA && e->tab[0][1]==PRETA && e->tab[1][0]==PRETA && e->tab[1][1]==PRETA) ||
            (e->tab[8][8]==BRANCA && e->tab[7][8]==PRETA && e->tab[7][7]==PRETA && e->tab[8][7]==PRETA ))

            return 4 ;
    }

    return 1 ;
}



ERROS jogar (ESTADO *estado, COORDENADA c)
{
    printf("jogar %d %d\n", c.coluna, 7-c.linha);
    COORDENADA posicao_atual =obter_pos_jogador(estado);
    if (valido(estado, c))
    {
        set_Branca_Tabuleiro(estado,c);
        set_Preta_Tabuleiro(estado,posicao_atual);
        int jog = obter_jogador_atual(estado);
        if (jog ==1)
        {
            set_numero_de_jogadas(estado);
            set_jogador_atual(estado,2);
        }
        else
        {
            set_jogador_atual(estado,1);
        }
        return OK;
    }
    if (fim(estado, c) == 1)
    {

        return COORDENADA_INVALIDA;
    }
    if (fim(estado, c) == 3)
        printf("Ganhou o jogador 1.Parabéns!\n");

    if (fim(estado, c) == 2)
    {
        printf("Ganhou o jogador 2.Parabéns!\n");
    }
    if (fim(estado, c) == 4)
    {
        int vencedor = obter_jogador_atual(estado);
        printf("Ganhou o jogador %c.Parabéns!\n", vencedor);
    }
}


