
#ifndef RASTROS02_LOGICA_H
#define RASTROS02_LOGICA_H

int jogar (ESTADO *estado, COORDENADA c);
int valido(ESTADO *estado, COORDENADA c);

int check_lado_oeste(ESTADO *e,COORDENADA c);
int check_lado_este(ESTADO *e,COORDENADA c);
int check_lado_norte(ESTADO *e,COORDENADA c);
int check_lado_sul(ESTADO *e,COORDENADA c);

#endif //RASTROS02_LOGICA_H
