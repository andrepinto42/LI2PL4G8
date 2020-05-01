#ifndef BOT
#define BOT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

typedef  struct  listas* LISTA;
typedef struct listas
{
    void *valor;
    LISTA prox;
} Nodo;

#endif //BOT