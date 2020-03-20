#ifndef RASTROS02_ESTRUTURA_H
#define RASTROS02_ESTRUTURA_H

typedef enum {
    OK,
    COORDENADA_INVALIDA,
    JOGADA_INVALIDA,
    ERRO_LER_TAB,
    ERRO_ABRIR_FICHEIRO,
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
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;


ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
CASA obter_estado_casa(ESTADO *e, int linha, int coluna);
COORDENADA obter_pos_jogador(ESTADO *e);
void set_Branca_Tabuleiro(ESTADO *e,COORDENADA c);
void set_Preta_Tabuleiro(ESTADO *e,COORDENADA c);
void set_ultima_jogada(ESTADO *e,COORDENADA c);
int print_prompt(ESTADO *e,int iteracoes);
void set_numero_de_jogadas(ESTADO *e);
void set_jogador_atual(ESTADO *e,int jogador);


#endif //RASTROS02_ESTRUTURA_H
