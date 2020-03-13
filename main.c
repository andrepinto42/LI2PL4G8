#include <stdio.h>
#include "estrutura.h"
#include "lógica.h"
#include "CamadaDeInterface.h"
#include <stdlib.h>
#include <string.h>

int main()
{
ESTADO *e = inicializar_estado();
 interpretador(e);
}
