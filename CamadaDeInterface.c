#include "estrutura.h"
#include <stdio.h>
#include "lógica.h"
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

// Função que imprime o tabuleiro
void mostrar_tabuleiro(ESTADO *e){
    int a,b;
    for ( a=0 ; a<=7 ; a++){
        for ( b=0 ; b<=7 ; b++){
            if ( a == 7 && b == 0 )
                printf("1");
            
            else if ( a== 0 && b == 7)
                printf("2");
             else if (e->tab[a][b] == VAZIO)
            printf(".");
            else if (e->tab[a][b] == BRANCA)
            printf("*");
            else
                printf("#");
           
        }
        printf("\n");
    }
}

//Interpretador fornecido pelo guião
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    mostrar_tabuleiro(e);

    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}

