#include "estrutura.h"
#include "CamadaDeInterface.h"
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
<<<<<<< HEAD
=======
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
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
{

    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset= -1;

<<<<<<< HEAD
    if (jC == 7) return 1; // Não pode ir para a direita;
    else if (jL == 0)
    {
        if (obter_estado_casa(e,jL,jC+1) == PRETA ||
            obter_estado_casa(e,jL+1,jC +1) == PRETA)
=======
    if (jL == 7) return 1; // Não pode ir para baixo;
    else if (jC == 0)
    {
        if (obter_estado_casa(e,jL-1,jC) == PRETA ||
            obter_estado_casa(e,jL-1,jC +1) == PRETA)
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
        {
            return 1;
        }
    }
<<<<<<< HEAD
    else if (jL == 7)
    {
        if (obter_estado_casa(e,jL,jC+1) == PRETA ||
            obter_estado_casa(e,jL-1,jC + 1) == PRETA)
=======
    else if (jC == 7)
    {
        if (obter_estado_casa(e,jL-1,jC) == PRETA ||
            obter_estado_casa(e,jL-1,jC - 1) == PRETA)
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
        {
            return 1;
        }
    }
    else
    {
        for (offset ; offset <=1 ; ++offset)
        {
<<<<<<< HEAD
            if (!(obter_estado_casa(e,jL+offset,jC+1) == PRETA))
=======
            if (!(obter_estado_casa(e,jL-1,jC+offset) == PRETA))
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
                break;
        }
    }
    if (offset == 2) return 1;
    else return 0;
}


<<<<<<< HEAD
int check_lado_sul(ESTADO *e,COORDENADA c)// testa se tem pecas pretas embaixo;
=======
int check_lado_norte(ESTADO *e,COORDENADA c)// testa se tem pecas pretas em cima;
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
{

    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset= -1;

<<<<<<< HEAD
    if (jL == 7) return 1; // Não pode ir para baixo;
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
=======
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
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
    if (offset == 2) return 1;
    else return 0;
}


<<<<<<< HEAD
int check_lado_norte(ESTADO *e,COORDENADA c)// testa se tem pecas pretas em cima;
{

    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset= -1;

    if (jL == 0) return 1; // Não pode ir para cima;
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

int casa_livre(ESTADO *e,COORDENADA c)
{

}
=======
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654

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


ERROS jogar (ESTADO *estado, COORDENADA c)
{

    printf("jogar %d %d\n", c.coluna, c.linha);
    COORDENADA posicao_atual = obter_pos_jogador(estado);
    ERROS erro = valido(estado, c);
    if (erro == OK)
    {
<<<<<<< HEAD
        if ( obter_numero_de_jogadas(estado) == 0)
        {
            incr_numero_de_jogadas(estado);
        }
            if (c.coluna == 7 && c.linha == 0)
=======
        if (c.coluna == 7 && c.linha == 0)
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
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
        add_jogadas(estado,c);
        int jog = obter_jogador_atual(estado);
<<<<<<< HEAD

        if (jog == 1)
        {
            set_jogador_atual(estado, 2);
        }
        else
            {
                incr_numero_de_jogadas(estado);
                set_jogador_atual(estado, 1);
            }
=======
        if (jog == 1)
        {
            set_jogador_atual(estado, 2);
        } else
            {
                incr_numero_de_jogadas(estado);
                set_jogador_atual(estado, 1);
        }
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654

    }
    else if (erro == COORDENADA_INVALIDA)
    {
        return erro;
    }
<<<<<<< HEAD
    printf("n%d e%d o%d s%d \n",check_lado_norte(estado, c),check_lado_este(estado, c)
                             ,check_lado_oeste(estado, c),check_lado_sul(estado, c));
=======
>>>>>>> ee4ee77029bc91d3c6d512b5e14a69bde4feb654
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



