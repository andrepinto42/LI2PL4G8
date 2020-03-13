#include "estrutura.h"
#include <stdio.h>


int jogar (ESTADO *estado, COORDENADA c){
    printf ("jogar %d %d\n",c.coluna ,c.linha);

    if (valido(estado,c))
    {
     set_Branca_Tabuleiro(estado,c);
    return 1;
    }
    else return 0;
}
valido(ESTADO *e , COORDENADAS c) 
{
    return 1 ;
}
