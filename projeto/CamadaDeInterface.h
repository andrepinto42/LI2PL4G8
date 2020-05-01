#ifndef CamadaDeInterface_H
#define CamadaDeInterface_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mostrar_tabuleiro(ESTADO *e,FILE *file);
int interpretador(ESTADO *e,FILE *file);
ERROS ler_tabuleiro(ESTADO *e,FILE * file);
ERROS ler(ESTADO *e,char *file);
void gravar_tabuleiro(ESTADO *e,char* filename);
void reconstruir_jogadas(ESTADO *e,int num_jogs);




#endif //CamadaDeInterface
