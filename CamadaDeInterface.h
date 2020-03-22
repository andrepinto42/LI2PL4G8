#ifndef CamadaDeInterface_H
#define CamadaDeInterface_H

void mostrar_tabuleiro(ESTADO *e,FILE *file);
int interpretador(ESTADO *e,FILE *file);
ERROS ler_tabuleiro(ESTADO *e,FILE * file);

ERROS ler(ESTADO *e,char *file);
void gravar_tabuleiro(ESTADO *e,char* filename);



#endif //CamadaDeInterface
