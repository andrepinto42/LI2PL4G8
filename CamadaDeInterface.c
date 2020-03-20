#include "estrutura.h"
#include <stdio.h>
#include "lógica.h"
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

// Função que imprime o tabuleiro
void mostrar_tabuleiro(ESTADO *e){

    for (int j = 0; j <8 ; ++j)
    {
        for (int i = 0; i < 8; ++i) {
            if (i==0 && j==7)
                printf("1");
            else if (i== 7 && j == 0)
                printf("2");

            else if (obter_estado_casa(e,j,i) == VAZIO)
                printf(".");
            else if (obter_estado_casa(e,j,i) == PRETA)
                printf("#");
            else
                printf("*");
        }
        printf("\n");
    }
}

//Interpretador fornecido pelo guião
int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    int i=0;
    mostrar_tabuleiro(e);


    while ( print_prompt(e,i) && fgets(linha, BUF_SIZE, stdin) != NULL)
        {
         if( (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) )
         {
            COORDENADA coord = {(*col - 'a'),7- (*lin - '1')};
            jogar(e, coord);
            mostrar_tabuleiro(e);
         }
         else return 0;
         i++;
        }
    return 1;
}

