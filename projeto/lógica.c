#include "estrutura.h"
#include "CamadaDeInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"
#include <time.h>


ERROS valido(ESTADO *e , COORDENADA c);

//funçao que insere coordenadas numa lista 
LISTA insere_lista_coords(LISTA l,COORDENADA c)
{
        char* s = coord_to_str(c);
        l = insere_cabeca(l,s);
        return l;
}

//funçao que adiciona coordenadas abaixo da peça atual 
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
//Funçao que adiciona coordenadas acima da peça atual 
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
//funçao que adiciona coordenadas a este da peça atual
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
//Funçao que adiciona coordenadas a oeste da peça atual
LISTA add_coords_oeste(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =-1; i <=0 ; ++i)
    {
        COORDENADA c = {jC-1,jL +i};
        ERROS erro = valido(e,c);
        if ( erro == OK)
        {
            l = insere_lista_coords(l, c);
        }

    }
    return l;

}

// Funçao que para o bot  -atraves do caminho mais curto -segue dois trajetos possiveis 
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
// Funçao que faz com que o bot escolha aleatoriamnete a proxima posiçao 
LISTA add_coords_random(LISTA l,ESTADO *e)
{

    srandom(time(NULL));

        int op = -1,executados[4],check = 1;
    for (int i = 0; i < 4; ++i)
    {
        executados[0] = -1;
        executados[1] = -1;
        executados[2] = -1;
        executados[3] = -1;
        do
            {


            op = random() % 4;
            for (int j = 0; j < i; ++j)
            {
                if (executados[j] == op)
                    check = 0;
            }
        } while  (check == 0);



        switch (op)
        {
            case 0 :
                l = add_coords_norte(l, e);
                break;
            case 1 :
                l = add_coords_sul(l, e);
                break;
            case 2 :
                l = add_coords_oeste(l, e);
                break;
            case 3 :
                l = add_coords_este(l, e);
                break;
        }
        executados[i] = op;

    }

    return l;
}


//Funçao que verifica o lado oeste da peça 
int check_lado_oeste(ESTADO *e)// testa se tem pecas pretas na esquerda;
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset = -1;


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
        for (offset = -1 ; offset <=1 ; ++offset)
        {
            if (!(obter_estado_casa(e,jL+offset,jC-1) == PRETA))
                break;
        }
    }
    if (offset == 2) return 1;
    else return 0;
}

//Funçao que verifica o lado este 
int check_lado_este(ESTADO *e)// testa se tem pecas pretas na direita;
{

    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset = -1;


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
        for (offset = -1 ; offset <=1 ; ++offset)
        {
            if (!(obter_estado_casa(e,jL+offset,jC+1) == PRETA))
                break;
        }
    }
    if (offset == 2) return 1;
    else return 0;
}


//Funçao que verifica o lado sul
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
            for (offset = -1 ; offset <=1 ; ++offset)
            {
             if (!(obter_estado_casa(e,jL+1,jC+offset) == PRETA))
                break;
            }
    }

    if (offset == 2) return 1;
    else return 0;
}


//Funçao que verifica abaixo da peça atual
int check_lado_norte(ESTADO *e)// testa se tem pecas pretas em cima;
{

    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;
    int offset = -1;


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
            for (offset = -1 ; offset <=1 ; ++offset)
            {
             if (!(obter_estado_casa(e,jL-1,jC+offset) == PRETA))
                break;
            }
    }
    if (offset == 2) return 1;
    else return 0;
}


//Funçao que verifica se a jogada e válida
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

//Funçao que atraves das coordenadas inseridas averigua ( recorrendo a outras funçoes auxiliares ) se e possivel continuar a jogar ou fim do jogo ;
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



