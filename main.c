#include <stdio.h>
#include "estrutura.h"
#include "lógica.h"
#include "CamadaDeInterface.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{

   FILE *file = fopen("dados.txt","r");
   ESTADO *e = inicializar_estado();


   mostrar_tabuleiro(e,file);
    while (interpretador(e,file))
    {
    }

    free(e);
    return 0;
}
