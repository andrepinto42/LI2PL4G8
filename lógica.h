#ifndef RASTROS02_LOGICA_H
#define RASTROS02_LOGICA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"


int jogar (ESTADO *estado, COORDENADA c);
int valido(ESTADO *estado, COORDENADA c);

LISTA insere_lista_coords(LISTA l,COORDENADA C);

LISTA add_coords_norte(LISTA l,ESTADO *e);
LISTA add_coords_sul(LISTA l,ESTADO *e);
LISTA add_coords_este(LISTA l,ESTADO *e);
LISTA add_coords_oeste(LISTA l,ESTADO *e);

LISTA add_coords_lista(LISTA l,ESTADO *e);





int check_lado_oeste(ESTADO *e);
int check_lado_este(ESTADO *e);
int check_lado_norte(ESTADO *e);
int check_lado_sul(ESTADO *e);
#endif //RASTROS02_LOGICA_H
