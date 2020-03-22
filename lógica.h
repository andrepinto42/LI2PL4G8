
#ifndef RASTROS02_LOGICA_H
#define RASTROS02_LOGICA_H

//Função que executa a jogada;
int jogar (ESTADO *estado, COORDENADA c);

//Função que verifica se a jogada é válida;
int valido(ESTADO *estado, COORDENADA c);

//Função que testa se existem peças à esquerda do jogador;
int check_lado_oeste(ESTADO *e,COORDENADA c);

//Função que testa se existem peças à direita do jogador;
int check_lado_este(ESTADO *e,COORDENADA c);

//Função que testa se existem peças acima do jogador;
int check_lado_norte(ESTADO *e,COORDENADA c);

//Função que testa se existem peças abaixo do jogador;
int check_lado_sul(ESTADO *e,COORDENADA c);

#endif //RASTROS02_LOGICA_H
