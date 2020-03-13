#include "estrutura.h"
#include <stdio.h>

void mostrar_tabuleiro(Estado *e){
    int a,b;
    for ( a=0 ; a<=7 ; a++){
        for ( b=0 ; b<=7 ; b++){
            if ( a == 0 && b == 0 )
                printf("1");
            else if ( a == 5 && b == 5 )
                printf("*");
            else if ( a== 7 && b == 7)
                printf("2");
            else printf(".");
        }
    }
}
