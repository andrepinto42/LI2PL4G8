#include "estrutura.h"
#include <stdio.h>


int valido(ESTADO *e , COORDENADA c)
{
    int distlinha = pow(c.linha - obter_pos_jogador(e).linha,2);
    int distcoluna = pow(c.coluna - obter_pos_jogador(e).coluna,2);

    float dist = (sqrt( distlinha+ distcoluna ) ) ;

        if ( obter_estado_casa(e,c.linha,c.coluna) == VAZIO )
        {
            if (dist < 1.42 )
            return 1 ;

        }
    return 0 ;
}

int verificar_enc_meio (ESTADO *e, COORDENADAS c){
 if (obter_estado_casa (e, linha+1,coluna) ==PRETA && obter_estado_casa (e,c.linha-1,c.coluna+1)==PRETA 
    && obter_estado_casa (e,c.linha-1 ,c.coluna-1) == PRETA && obter_estado_casa (e,c.linha-1,c.coluna)==PRETA &&
    && obter_estado_casa (e,c.linha ,c.coluna-1)==PRETA && obter_estado_casa (e,c.linha+1 ,c.coluna-1)==PRETA &&
     obter_estado_casa (e,c.linha+1 ,c.coluna+1)==PRETA && obter_estado_casa (e,c.linha,c.coluna+1) &&
      obter_estado_casa (e,c.linha,c.coluna]==BRANCA ){
        return 1;  
      }

   int verificar_enc_ladod (ESTADO *e, COORDENADAS c){
      if obter_estado_casa (e,c.linha ,8)==BRANCA && obter_estado_casa (e,c.linha-1,8)==PRETA
    && obter_estado_casa(e,c.linha-1,c.coluna-1) == PRETA && obter_estado_casa(e,c.linha,c.coluna-1)==PRETA 
    && obter_estado_casa (e,c.linha+1,8)==PRETA && obter_estado_casa (e,c.linha+1,c.coluna-1)==PRETA) {
     return 1 ;
   }  
   }  

   int verificar_enc_cima (ESTADO *e, COORDENADAS c){
    if (obter_estado_casa(e,8 ,c.coluna-1)==PRETA && obter_estado_casa(e,8 ,c.coluna+1)== PRETA &&
    obter_estado_casa(e,8,c.coluna)==BRANCA && obter_estado_casa(e,c.linha-1 ,c.coluna)==PRETA &&
    obter_estado_casa(e,c.linha-1,c.coluna-1)==PRETA && obter_estado_casa (e,c.linha-1 ,c.coluna+1)==PRETA) {
        return 1;
    }
   }

   int verificar_enc_ladoe (ESTADO *e, COORDENADAS c){
       if (obter_estado_casa(e,c.linha ,1) == BRANCA  && obter_estado_casa(e,c.linha+1,1)==PRETA 
    && obter_estado_casa(e,c.linha-1,c.coluna+1) == PRETA && obter_estado_casa(e,c.linha,c.coluna+1)==PRETA &&
    obter_estado_casa(e,c.linha-1,1)==PRETA && obter_estado_casa(e,c.linha+1 ,c.coluna+1)==PRETA){
        return 1;
    }
   }

   int verificar_enc_baixo (ESTADO *e, COORDENADAS c){
    if (obter_estado_casa(e,1,c.coluna-1)==PRETA && obter_estado_casa(e,1,c.coluna+1) == PRETA &&
    obter_estado_casa(e,1,c.coluna)==BRANCA && obter_estado_casa(e,c.linha+1,c.coluna+1)==PRETA &&
    obter_estado_casa(e,c.linha+1,c.coluna-1)==PRETA && obter_estado_casa(e,c.linha+1,c.coluna)==PRETA){
        return 1;
    }
   }

   int verificar_enc_cantos (ESTADO *e, COORDENADAS c){
    (if (obter_estado_casa(e,1,8)==BRANCA) &&(obter_estado_casa(e,1,7)==PRETA && (obter_estado_casa(e,2,7)==PRETA )&& (obter_estado_casa(e,2,8)==PRETA) ||
     (obter_estado_casa(e,8,1)==BRANCA) &&(obter_estado_casa(e,7,1)==PRETA && (obter_estado_casa(e,7,2)==PRETA )&& (obter_estado_casa(e,8,2)==PRETA) ||
            


int fim (ESTADO *e, COORDENADAS c){
    if ( c.coluna=0 && c.linha =8 ){
    return 3;
    }
    if (c.coluna =8 && c.linha =0){
    return 2;
    }
    if (verificar_enc_meio (e,c)==1){
  return 4;
    }
    if (verificar_enc_ladod (e,c)==1){
    return 4;
    }
    if (verificar_enc_cima (e,c) ==1){
        return 4;
    }
    if (verificar_enc_ladoe (e,c)==1){
        return 4;
    }
    if (verificar_enc_baixo (e,c)==1) {
        return 4 ; 
    }
    if (verificar_enc_cantos (e,c) ==1 ){
        return 4;
    }




  ERROS jogar (ESTADO *estado, COORDENADA c)
{
    printf("jogar %d %d\n", c.coluna, 7-c.linha);
    COORDENADA posicao_atual =obter_pos_jogador(estado);
    if (valido(estado, c))
    {
        set_Branca_Tabuleiro(estado,c);
        set_Preta_Tabuleiro(estado,posicao_atual);
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
        return OK;
    }
    if (fim(estado, c) == 1)
    {

        return COORDENADA_INVALIDA;
    }
    if (fim(estado, c) == 3)
        printf("Ganhou o jogador 1.Parabéns!\n");

    if (fim(estado, c) == 2)
    {
        printf("Ganhou o jogador 2.Parabéns!\n");
    }
    if (fim(estado, c) == 4)
    {
        int vencedor = obter_jogador_atual(estado);
        printf("Ganhou o jogador %c.Parabéns!\n", vencedor);
    }
}

