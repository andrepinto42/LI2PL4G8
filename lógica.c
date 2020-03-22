#include "estrutura.h"
#include <stdio.h>
int obter_ultima_jogada {

}

int valido(ESTADO *e , COORDENADA c) {
    obter_pos_jogador(e) =posicao_atual;
    int linha = posicao_atual.linha;
    int coluna = posicao_atual.coluna;
    float dist = sqrt((c.linha-linha)^2 + (c.coluna -coluna)^2));
if (c.linha < 8 && c.coluna< 8){
    if ( e->tab[c.linha][c.coluna] = VAZIO ){
        if (dist < (sqrt (2)) ){
            return 1 ;
        }
    }    
    return 0 ;
}
int fim (ESTADO *e, COORDENADAS c){
    if ( c.coluna=0 && c.linha =8 )
    return 3;
    if (c.coluna =8 && c.linha =0)
    return 2;
    if ( e-> tab[c.linha][c.coluna+1] ==PRETA && e-> tab[c.linha-1][c.coluna+1]==PRETA 
    && e-> tab[c.linha-1][c.coluna-1] == PRETA && e-> tab[c.linha-1][c.coluna]==PRETA)&&
    e-> tab[c.linha-1][c.coluna-1] == PRETA &&e-> tab[c.linha][c.coluna-1]==PRETA &&
    e-> tab[c.linha+1][c.coluna]==PRETA && e-> tab[c.linha+1][c.coluna+1]==PRETA ){
        return 4;
    }
   if ( e-> tab[c.linha][8]  && e-> tab[c.linha-1][8]==PRETA 
    && e-> tab[c.linha-1][c.coluna-1] == PRETA && e-> tab[c.linha][c.coluna-1]==PRETA &&
    e-> tab[c.linha+1][8]==PRETA && e-> tab[c.linha+1][c.coluna-1]==PRETA ||
    
    (e-> tab[0][c.coluna-1]==PRETA && e-> tab[0][c.coluna+1] == PRETA &&
     e-> tab[0][c.coluna] && e-> tab[c.linha+1][c.coluna]==PRETA &&
    e-> tab[c.linha+1][c.coluna-1]==PRETA && e-> tab[c.linha+1][c.coluna+1]==PRETA) ||

    ( e-> tab[c.linha-1][0]  && e-> tab[c.linha+1][0]==PRETA 
    && e-> tab[c.linha-1][c.coluna+1] == PRETA && e-> tab[c.linha][c.coluna+1]==PRETA &&
    e-> tab[c.linha-1][0]==PRETA && e-> tab[c.linha+1][c.coluna+1]==PRETA)||
    
    ( (e-> tab[8][c.coluna-1]==PRETA && e-> tab[8][c.coluna+1] == PRETA &&
     e-> tab[8][c.coluna] && e-> tab[c.linha-1][c.coluna+1]==PRETA &&
    e-> tab[c.linha-1][c.coluna-1]==PRETA &&  tab[c.linha-1][c.coluna]==PRETA) 
    
    return 4 ;
}  

       return 1 ; 
    }



int jogar (ESTADO *estado, COORDENADA c){
    printf ("jogar %d %d\n",c.coluna ,c.linha);
    obter_pos_jogador(e) =posicao_atual;
    if (valido(estado,c))
    {
     set_Branca_Tabuleiro(estado,c);
     set_Preta_Tabuleiro (estado ,posiçao_atual);
    return 1;
    if ( fim ( e,c) ==3) 

    printf ( "Ganhou o jogador 1.Parabéns!");
    }
    if  (fim (e,c)==2){
    printf ( "Ganhou o jogador 2.Parabéns!");
    }
    if (fim (e,c)== 4){
       vencedor = obter_jogador_atual (e);
       printf ( "Ganhou o jogador %c.Parabéns!" , vencedor);
    }
    else return 0;
}


