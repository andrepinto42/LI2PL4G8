
#include <stdio.h>
#include "estrutura.h"
#include <stdlib.h>

//Função que indica qual foi a última jogada;
void set_ultima_jogada(ESTADO *e,COORDENADA c)
{
    COORDENADA ult_jog = {c.linha,c.coluna};
}

//Função que troca o estado do quadrado correspondente à coordenada para branco;
void set_Branca_Tabuleiro(ESTADO *e,COORDENADA c)
{

    e->tab[c.linha][c.coluna] = BRANCA;
}
//Função que troca o estado do quadrado correspondente à coordenada para preto;
void set_Preta_Tabuleiro(ESTADO *e,COORDENADA c)
{

    e->tab[c.linha][c.coluna] = PRETA;
}

//Função que representa a coordenada do  jogador;
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

//Função que retorna o estado de uma casa;
CASA obter_estado_casa(ESTADO *e, int linha,int coluna)
{
    return e->tab[linha][coluna];
}

//Função que troca o turno dos jogadores;
void set_jogador_atual(ESTADO *e,int jogador)
{
    e->jogador_atual = jogador;
}

//Função que altera o número de jogadas;
void set_numero_de_jogadas(ESTADO *e)
{
    e->num_jogadas = e->num_jogadas + 1;
}

//Função que indica o jogador atual;
int obter_jogador_atual(ESTADO *estado)
{
    return estado->jogador_atual;
}

//Função que indica  o número de jogadas realizadas;
int obter_numero_de_jogadas(ESTADO *estado)
{
    return estado->num_jogadas;
}

//Função que imprime as informações do jogo;

int print_prompt(ESTADO *e,int iteracoes)
{
    printf("# %d PL%d (%d)> ",
           iteracoes,obter_jogador_atual(e),obter_numero_de_jogadas(e)) ;
    return 1;
}

//Função que inicializa o estado;
ESTADO *inicializar_estado()
{
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1; // O Jogador da primeira jogada
    e->num_jogadas = 0; // quantas jogadas foram efetuadas

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
