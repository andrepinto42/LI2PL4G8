#ifndef RASTROS02_ESTRUTURA_H
#define RASTROS02_ESTRUTURA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"


typedef enum {
    OK,
    COORDENADA_INVALIDA,
    JOGADA_INVALIDA,
    ERRO_LER_TAB,
    ERRO_ABRIR_FICHEIRO,
    ACABOU,
    COORDENADA_OCUPADA,
} ERROS;

typedef enum {
    UM = '1',
    DOIS = '2',
    VAZIO = '.',
    BRANCA = '*',
    PRETA = '#'
} CASA;

typedef struct {
    int coluna;
    int linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA MOVIMENTOS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    MOVIMENTOS jogadas;
    int num_jogadas;
    int jogador_atual;
    int num_comando;
} ESTADO;


void add_jogadas(ESTADO *e,COORDENADA c);
void print_movs(ESTADO *e,FILE *file);
ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
CASA obter_estado_casa(ESTADO *e, int linha, int coluna);
COORDENADA obter_pos_jogador(ESTADO *e);
void set_Branca_Tabuleiro(ESTADO *e,COORDENADA c);
void set_Preta_Tabuleiro(ESTADO *e,COORDENADA c);
void set_ultima_jogada(ESTADO *e,COORDENADA c);
int  print_prompt(ESTADO *e);
void incr_numero_de_jogadas(ESTADO *e);
void set_jogador_atual(ESTADO *e,int jogador);
void set_casa(ESTADO *e,COORDENADA c,CASA casita);
int  obter_num_comando(ESTADO *e);
void print_erro(ERROS erro);
void set_jogadas(ESTADO *e,COORDENADA c,int jogador,int num_jog);
void set_num_jogadas(ESTADO *e,int num_jogs);
void zerar_tabuleiro(ESTADO *e);
int  check_jogada_conteudo(JOGADA j);
void reconstruir_jogadas(ESTADO *e,int num_jogs);
char* coord_to_str(COORDENADA c);
void print_movs_tab(ESTADO *e);
COORDENADA str_to_coord(char jog[]);









#endif //RASTROS02_ESTRUTURA_H
