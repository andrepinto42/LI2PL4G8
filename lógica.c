#include "estrutura.h"
#include <stdio.h>

int valido(ESTADO *e , COORDENADA c) 
{
    return 1 ;
}
int jogar (ESTADO *estado, COORDENADA c)
{
    printf ("jogar %d %d\n",c.coluna ,7-(c.linha));
    if (valido(estado,c))
    {
     set_Branca_Tabuleiro(estado,c);
     int jog = obter_jogador_atual(estado);
     if (jog ==1)
     {
         set_numero_de_jogadas(estado);
         set_jogador_atual(estado,2);
     }
     else
     {
         set_jogador_atual(estado,1);
     }
    return 1;
    }
    else return 0;
}

