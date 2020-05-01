#include <stdio.h>
#include "estrutura.h"
#include "lógica.h"
#include "CamadaDeInterface.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{

   ESTADO *e = inicializar_estado();


   mostrar_tabuleiro(e);
    while (interpretador(e))
    {
    }

    free(e);
    return 0;
}
