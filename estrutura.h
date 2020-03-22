#ifndef RASTROS02_ESTRUTURA_H
#define RASTROS02_ESTRUTURA_H

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
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
    int num_comando;
} ESTADO;

//Função que inicializa o estado;
ESTADO *inicializar_estado();

//Função que indica o jogador em jogo;
int obter_jogador_atual(ESTADO *estado);

//Função que retorna o número de jogadas efetuadas;
int obter_numero_de_jogadas(ESTADO *estado);

//Função que retorna o estado da casa correspondente às coordenadas;
CASA obter_estado_casa(ESTADO *e, int linha, int coluna);

//Função que retorna a posição do jogador;
COORDENADA obter_pos_jogador(ESTADO *e);

//Função que troca o estado da casa para branca;
void set_Branca_Tabuleiro(ESTADO *e,COORDENADA c);

//Função que troca o estado da casa para preta;
void set_Preta_Tabuleiro(ESTADO *e,COORDENADA c);

//Função que reescreve a última jogada;
void set_ultima_jogada(ESTADO *e,COORDENADA c);

//Função que imprime as informações do jogo;
int print_prompt(ESTADO *e);

//Função que troca o número de jogadas atual;
void set_numero_de_jogadas(ESTADO *e);

//Função que vê qual o jogador atual;
void set_jogador_atual(ESTADO *e,int jogador);


//Função que preenche uma coordenada do tabuleiro;
void set_casa(ESTADO *e,COORDENADA c,CASA casita);

//Função que conta o número de comandos executados;
int obter_num_comando(ESTADO *e);

//Função que imprime o erro;
void print_erro(ERROS erro);






#endif //RASTROS02_ESTRUTURA_H
