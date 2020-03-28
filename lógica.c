#include "estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int check_lado_oeste(ESTADO *e,COORDENADA c)// testa se tem pecas pretas na esquerda;
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset= -1;

    if (jC == 0) return 1; // Não pode ir para a esquerda;
    else if (jL == 0)
    {
        if (obter_estado_casa(e,jL,jC-1) == PRETA ||
            obter_estado_casa(e,jL+1,jC -1) == PRETA)
        {
            return 1;
        }
    }
    else if (jL == 7)
    {
        if (obter_estado_casa(e,jL,jC-1) == PRETA ||
            obter_estado_casa(e,jL-1,jC- 1) == PRETA)
        {
            return 1;
        }
    }
    else
    {
        for (offset ; offset <=1 ; ++offset)
        {
            if (!(obter_estado_casa(e,jL+offset,jC-1) == PRETA))
                break;
        }
    }
    if (offset == 2) return 1;
    else return 0;
}


int check_lado_este(ESTADO *e,COORDENADA c)// testa se tem pecas pretas na direita;
{

    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset= -1;

    if (jC == 7) return 1; // Não pode ir para a direita;
    else if (jL == 0)
    {
        if (obter_estado_casa(e,jL,jC+1) == PRETA ||
            obter_estado_casa(e,jL+1,jC +1) == PRETA)
        {
            return 1;
        }
    }
    else if (jL == 7)
    {
        if (obter_estado_casa(e,jL,jC+1) == PRETA ||
            obter_estado_casa(e,jL-1,jC + 1) == PRETA)
        {
            return 1;
        }
    }
    else
    {
        for (offset ; offset <=1 ; ++offset)
        {
            if (!(obter_estado_casa(e,jL+offset,jC+1) == PRETA))
                break;
        }
    }
    if (offset == 2) return 1;
    else return 0;
}


int check_lado_sul(ESTADO *e,COORDENADA c)// testa se tem pecas pretas embaixo;
{

    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset= -1;

    if (jL == 7) return 1; // Não pode ir para baixo;
    else if (jC == 0)
    {
        if (obter_estado_casa(e,jL-1,jC) == PRETA ||
            obter_estado_casa(e,jL-1,jC +1) == PRETA)
        {
            return 1;
        }
    }
    else if (jC == 7)
    {
        if (obter_estado_casa(e,jL-1,jC) == PRETA ||
            obter_estado_casa(e,jL-1,jC - 1) == PRETA)
        {
            return 1;
        }
    }
    else
    {
        for (offset ; offset <=1 ; ++offset)
        {
            if (!(obter_estado_casa(e,jL-1,jC+offset) == PRETA))
                break;
        }
    }
    if (offset == 2) return 1;
    else return 0;
}


int check_lado_norte(ESTADO *e,COORDENADA c)// testa se tem pecas pretas em cima;
{

    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset= -1;

    if (jL == 0) return 1; // Não pode ir para cima;
    else if (jC == 0)
    {
        if (obter_estado_casa(e,jL+1,jC) == PRETA ||
            obter_estado_casa(e,jL+1,jC +1) == PRETA)
        {
            return 1;
        }
    }
    else if (jC == 7)
    {
        if (obter_estado_casa(e,jL+1,jC) == PRETA ||
            obter_estado_casa(e,jL+1,jC - 1) == PRETA)
        {
            return 1;
        }
    }
    else
        {
            for (offset ; offset <=1 ; ++offset)
            {
             if (!(obter_estado_casa(e,jL+1,jC+offset) == PRETA))
                break;
            }
    }
    if (offset == 2) return 1;
    else return 0;
}



ERROS valido(ESTADO *e , COORDENADA c)
{
    int distlinha = pow(c.linha - obter_pos_jogador(e).linha,2);
    int distcoluna = pow(c.coluna - obter_pos_jogador(e).coluna,2);

    float dist = (sqrt( distlinha+ distcoluna ) ) ;

        if (dist < 1.42 )
        {
            if ( obter_estado_casa(e,c.linha,c.coluna) == VAZIO )
            return OK ;
            else
                return COORDENADA_OCUPADA;

        }
        else return COORDENADA_INVALIDA;

}
/*
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

*/

ERROS jogar (ESTADO *estado, COORDENADA c)
{

    printf("jogar %d %d\n", c.coluna, 7 - c.linha);
    COORDENADA posicao_atual = obter_pos_jogador(estado);
    ERROS erro = valido(estado, c);
    if (erro == OK)
    {
        if (c.coluna == 7 && c.linha == 0)
        {
            set_jogador_atual(estado,2);
            return ACABOU;
        }
        else if (c.coluna == 0 && c.linha == 7)
        {
            set_jogador_atual(estado,1);
            return ACABOU;
        }


        set_Branca_Tabuleiro(estado, c);
        set_Preta_Tabuleiro(estado, posicao_atual);
        int jog = obter_jogador_atual(estado);
        if (jog == 1)
        {
            set_numero_de_jogadas(estado);
            set_jogador_atual(estado, 2);
        } else
            {
            set_jogador_atual(estado, 1);
        }

    }
    else if (erro == COORDENADA_INVALIDA)
    {
        return erro;
    }
    if (check_lado_este(estado, c) && check_lado_norte(estado, c) &&
               check_lado_oeste(estado, c) && check_lado_sul(estado, c))
        // o jogador nao pode sair;
    {
        int jog = obter_jogador_atual(estado);
        if (jog == 1)
            set_jogador_atual(estado, 2);
        else
            set_jogador_atual(estado, 1);
        return ACABOU;
    }

     return erro;
}


/*
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
*/

