#include "estrutura.h"
#include "CamadaDeInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"

ERROS valido(ESTADO *e , COORDENADA c);

LISTA insere_lista_coords(LISTA l,COORDENADA c)
{
        char* s = coord_to_str(c);
        l = insere_cabeca(l,s);
        return l;
}


LISTA add_coords_norte(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =0; i <= 1 ; ++i)
        {
            COORDENADA c = {jC+i,jL -1};
            ERROS erro = valido(e,c);

            if ( erro == OK)
            {
                l = insere_lista_coords(l,c);

            }


        }
    return l;

}
LISTA add_coords_sul(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =0; i >= -1 ; i--)
    {
        COORDENADA c = {jC+i,jL +1};
        ERROS erro = valido(e,c);
        if ( erro == OK){
            l = insere_lista_coords(l,c);

        }


    }
    return l;

}

LISTA add_coords_este(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =1; i >=0 ; i--)
    {
        COORDENADA c = {jC+1,jL +i};
        ERROS erro = valido(e,c);
        if ( erro == OK){
            l = insere_lista_coords(l,c);

        }


    }
    return l;

}
LISTA add_coords_oeste(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =-1; i <=0 ; ++i)
    {
        COORDENADA c = {jC-1,jL +i};
        ERROS erro = valido(e,c);
        if ( erro == OK){
            l = insere_lista_coords(l, c);
        }

    }
    return l;

}


LISTA add_coords_lista(LISTA l,ESTADO *e)
{

    if (obter_jogador_atual(e) == 1)
    {
        l = add_coords_norte(l,e); // COORDENADAS ULTIMAS SAO AS QUE FICAM MAIS LONGE DO OBJETIVO
        l = add_coords_este(l,e);
        l = add_coords_oeste(l,e);
        l = add_coords_sul(l,e); // FICA na cabeça as coordenadas mais  para sul;
        // sendo estas as preferenciais para chegar ao fim;

    }
    else
    {
        l = add_coords_sul(l,e); // COORDENADAS ULTIMAS SAO AS QUE FICAM MAIS LONGE DO OBJETIVO
        l = add_coords_oeste(l,e);
        l = add_coords_este(l,e);
        l = add_coords_norte(l,e); //FICA na cabeça as coordenadas mais para norte;
    }

    return l;



}

int check_lado_oeste(ESTADO *e)// testa se tem pecas pretas na esquerda;
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


int check_lado_este(ESTADO *e)// testa se tem pecas pretas na direita;
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



int check_lado_sul(ESTADO *e)// testa se tem pecas pretas emcima;

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



int check_lado_norte(ESTADO *e)// testa se tem pecas pretas em cima;
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



ERROS valido(ESTADO *e , COORDENADA c)
{
   if ( c.linha < 0 || c.coluna < 0 || c.linha >= 8 || c.coluna >= 8)
       return COORDENADA_INVALIDA;
    int distlinha = pow(c.linha - obter_pos_jogador(e).linha,2);
    int distcoluna = pow(c.coluna - obter_pos_jogador(e).coluna,2);

    float dist = (sqrt( distlinha+ distcoluna ) ) ;

        if (dist < 1.42 )
        {
            CASA casita = obter_estado_casa(e,c.linha,c.coluna);
            if (  casita == VAZIO || casita == UM || casita == DOIS )
            return OK ;
            else
                return COORDENADA_OCUPADA;

        }
        else return COORDENADA_INVALIDA;

}


ERROS jogar (ESTADO *estado, COORDENADA c)
{

    printf("Jogar c:%d l:%d\n", c.coluna, c.linha);
    COORDENADA posicao_atual = obter_pos_jogador(estado);
    ERROS erro = valido(estado, c);
    if (erro == OK)
    {
        if ( obter_numero_de_jogadas(estado) == 0)
        {
            incr_numero_de_jogadas(estado);
        }
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
        add_jogadas(estado,c);
        int jog = obter_jogador_atual(estado);

        if (jog == 1)
        {
            set_jogador_atual(estado, 2);
        }
        else
            {
                incr_numero_de_jogadas(estado);
                set_jogador_atual(estado, 1);
            }



    }
    else if (erro == COORDENADA_INVALIDA)
    {
        return erro;
    }


    if (check_lado_este(estado) && check_lado_norte(estado) &&
               check_lado_oeste(estado) && check_lado_sul(estado))
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



