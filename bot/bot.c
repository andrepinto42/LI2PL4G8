#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bot.h"

#define BUF_SIZE 1024

/*
 *
 * CODIGO DAS LISTAS
 *
 */


// Cria uma lista vazia
LISTA criar_lista()
{
    LISTA l = NULL;
    return l;
}
// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor)
{
    LISTA l1 = malloc(sizeof(Nodo));
    l1->valor = valor;
    l1->prox = L;
    return l1;
}
// Devolve a cabeça da lista
void* devolve_cabeca(LISTA L)
{
    return L->valor;

}
// Devolve a cauda da lista
LISTA proximo(LISTA L)
{
    return L->prox;

}
// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L)
{
    LISTA l1 = L->prox;
    free(L);
    return l1;
}
// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L)
{
    if (L) return 0;
    else return 1;
}





// ESTRUTURA DA BASE DE DADOS

ESTADO *inicializar_estado()
{
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1; // O Jogador da primeira jogada
    e->num_jogadas = 0; // quantas jogadas foram efetuadas
    e->num_comando = 0;
    for (int i = 0; i <8 ; ++i)
    {       // preenche o tabuleiro com VAZIO
        for (int j = 0; j <8 ; ++j)
        {
            e->tab[i][j] = VAZIO;
        }
    }
    e->tab[3][4] = BRANCA;
    e->tab[7][0] = UM;
    e->tab[0][7] = DOIS;
    for (int k = 0; k< 32 ; ++k)
    {
        e->jogadas[k].jogador1.coluna = -1;
        e->jogadas[k].jogador1.linha  = -1;
        e->jogadas[k].jogador2.coluna = -1;
        e->jogadas[k].jogador2.linha  = -1;
    }
    e->jogadas[0].jogador1.coluna = -2;
    e->jogadas[0].jogador1.linha  = -2;

    return e;
}

void print_erro(ERROS erro)
{
    if      (erro == OK) printf("OK\n");
    else if (erro == COORDENADA_INVALIDA) printf("Coordenada Inválida\n");
    else if (erro == JOGADA_INVALIDA) printf("Jogada Inválida\n");
    else if (erro == ERRO_LER_TAB) printf ("Erro ao ler o Tabuleiro\n");
    else if (erro == ERRO_ABRIR_FICHEIRO) printf("Erro ao Abrir Ficheiro\n");
    else if (erro == ACABOU) printf("ACABOU \n");
    else printf("Coordenada Ocupada\n");

}



void set_Branca_Tabuleiro(ESTADO *e,COORDENADA c)
{

    e->tab[c.linha][c.coluna] = BRANCA;
}
void set_Preta_Tabuleiro(ESTADO *e,COORDENADA c)
{

    e->tab[c.linha][c.coluna] = PRETA;
}




COORDENADA obter_pos_jogador(ESTADO *e)
{
    COORDENADA joga;

    for (int i=0 ; i <8 ; ++i)
    {
        for ( int j =0; j <8 ; ++j)
        {
            if ( e->tab[i][j] == BRANCA)
                return  joga =(COORDENADA){.linha = i,.coluna = j};
        }
    }
    return joga = (COORDENADA){.linha = -1,.coluna = -1};
}
int check_jogada_conteudo(JOGADA j)
{
    int j1linha = j.jogador1.linha ;
    int j1coluna = j.jogador1.coluna ;

    int j2linha = j.jogador2.linha ;
    int j2coluna = j.jogador2.coluna ;

    if (j1linha == -2 && j1coluna == -2)
        return -1;

    if (j1linha >= 0 && j1coluna >= 0)
    {
        if (j2linha >=0 && j2coluna >= 0)
            return 2; //A Jogada tem coordenadas para ambos os jogadores;

            else return 1; // A jogada só tem coordenadas para o 1º Jogador
    }
    else return 0; // A jogada é vazia;
}


void print_movs(ESTADO *e,FILE *file)
{
    int i=0,check,var = 0;
    if (check_jogada_conteudo( e->jogadas[i]) == -1)
    {
        fprintf(file,"01: ");
    }
    while ( (check = check_jogada_conteudo( e->jogadas[i]) ) )
    {
        if ((check == 2) || (check == 1)) {
            if (var < 9 && var <= e->num_jogadas)
            {
                fprintf(file, "0");
                var++;
            }

            fprintf(file, "%d: %c%d", i + 1, 97 + e->jogadas[i].jogador1.coluna, 8 - e->jogadas[i].jogador1.linha);
            if (check == 2) {
                fprintf(file, " %c%d", 97 + e->jogadas[i].jogador2.coluna, 8 - e->jogadas[i].jogador2.linha);
                if (check_jogada_conteudo(e->jogadas[i + 1]))
                    fprintf(file, "\n");
            }

        }

        i++;
    }
    fprintf(file,"\n");
}




CASA obter_estado_casa(ESTADO *e, int linha,int coluna)
{
    return e->tab[linha][coluna];
}

void set_jogador_atual(ESTADO *e,int jogador)
{
    e->jogador_atual = jogador;
}

void incr_numero_de_jogadas(ESTADO *e)
{
    e->num_jogadas = e->num_jogadas + 1;
}

int obter_jogador_atual(ESTADO *estado)
{
    return estado->jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *estado)
{
    return estado->num_jogadas;
}

void set_casa(ESTADO *e,COORDENADA c,CASA casita)
{
    e->tab[c.linha][c.coluna] = casita;
}





void set_num_jogadas(ESTADO *e,int num_jogs)
{
    e->num_jogadas = num_jogs;
}


void set_jogadas(ESTADO *e,COORDENADA c,int jogador,int num_jog)
{
    if (jogador == 1)


        e->jogadas[num_jog].jogador1 = c;

    else

        e->jogadas[num_jog].jogador2 = c;

}

void add_jogadas(ESTADO *e,COORDENADA c)
{

    if (e->jogador_atual == 1)
        e->jogadas[e->num_jogadas].jogador1 = c;
    else
        e->jogadas[e->num_jogadas].jogador2 = c;

}





char* coord_to_str(COORDENADA c)
{
    char *s = malloc(sizeof(2));
    s[0] = c.coluna + 97;
    s[1] = (8 - c.linha) + 48;

    return s;
}

COORDENADA str_to_coord(char jog[])
{
    COORDENADA c1;
    if (jog[0] <= 105 && jog[0] >= 96 && jog[1] > 48 && jog[1] < 57)
        return c1 = (COORDENADA){.coluna = (jog[0] - 97) ,.linha= 7 -(jog[1] - 49) };

    else return c1 = (COORDENADA){.coluna = -1,.linha = -1};
}

/*
 * CAMADA DE LOGICA
 *
 */


void gravar_tabuleiro(ESTADO *e,char *filename)
{
    FILE *f = fopen(filename,"w");

    for (int j = 0; j <8 ; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            fprintf(f, "%c",obter_estado_casa(e,j,i));
        }
        fprintf(f,"\n");
    }

    fprintf(f,"\n");
    print_movs(e,f);

    fclose(f);
}



ERROS ler_tabuleiro(ESTADO *e,FILE * file)
{
    int max=0,player = 1;
    for (int l = 0; l < 8; ++l)
    {
        char linha[BUF_SIZE];
        if(fgets(linha,BUF_SIZE,file) == NULL)
            return ERRO_LER_TAB;
        for (int c = 0; c <8 ; ++c)
        {
            COORDENADA C = {c,l};
            set_casa(e,C,(CASA) linha[c]); // coloca no estado a informacao contida em dados.txt
        }
    }


    char fake[BUF_SIZE];
    if ( fgets(fake,BUF_SIZE,file) )
    {

    }



        char linha[BUF_SIZE];
        while (fgets(linha, BUF_SIZE, file) != NULL)
        {
            int num_jog = -1 ;
            char jog1[BUF_SIZE];
            char jog2[BUF_SIZE];
            int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
            if (num_tokens == 3)
            {
                COORDENADA c1 = str_to_coord(jog1);
                COORDENADA c2 = str_to_coord(jog2);
                set_jogadas(e, c1, 1, num_jog - 1);
                set_jogadas(e, c2, 2, num_jog - 1);


            }
            else if (num_tokens == 2)
            {
                COORDENADA c1 = str_to_coord(jog1);

                set_jogadas(e, c1, 1, num_jog - 1);

            }
           if (num_jog > max) max = num_jog;
           if (num_tokens == 3)
           {
              player = 1;
           }
           else if (num_tokens == 2) player = 2;
           jog1[0] = 0;
           jog2[0] = 0;



        }

        set_jogador_atual(e,player);
        if (obter_jogador_atual(e) == 2)
            max--;// max se for 1 passa para proxima jogada;
        set_num_jogadas(e,max);


        fclose(file);

    return OK;
}


ERROS ler(ESTADO *e,char *file)
{
    FILE *f = fopen(file,"r");
    if (f == NULL)
        return ERRO_ABRIR_FICHEIRO;
    return ler_tabuleiro(e,f);
}



/*
 * CAMADA DE LOGICA
 *
 *
 */


ERROS valido(ESTADO *e , COORDENADA c)
{
    if ( c.linha < 0 || c.coluna < 0 || c.linha >= 8 || c.coluna >= 8)
        return COORDENADA_INVALIDA;
    int distlinha = pow(c.linha - obter_pos_jogador(e).linha,2);
    int distcoluna = pow(c.coluna - obter_pos_jogador(e).coluna,2);

    float dist = (sqrt( distlinha+ distcoluna ) ) ;

    if (dist < 1.42 )
    {
        CASA casita = obter_estado_casa(e,c.linha,c.coluna);
        if (  casita == VAZIO || casita == UM || casita == DOIS )
            return OK ;
        else
            return COORDENADA_OCUPADA;

    }
    else return COORDENADA_INVALIDA;

}

LISTA insere_lista_coords(LISTA l,COORDENADA c)
{
    char* s = coord_to_str(c);
    l = insere_cabeca(l,s);
    return l;
}


LISTA add_coords_norte(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =0; i <= 1 ; ++i)
    {
        COORDENADA c = {jC+i,jL -1};
        ERROS erro = valido(e,c);

        if ( erro == OK)
        {
            l = insere_lista_coords(l,c);

        }


    }
    return l;

}
LISTA add_coords_sul(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =0; i >= -1 ; i--)
    {
        COORDENADA c = {jC+i,jL +1};
        ERROS erro = valido(e,c);
        if ( erro == OK){
            l = insere_lista_coords(l,c);

        }


    }
    return l;

}

LISTA add_coords_este(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =1; i >=0 ; i--)
    {
        COORDENADA c = {jC+1,jL +i};
        ERROS erro = valido(e,c);
        if ( erro == OK){
            l = insere_lista_coords(l,c);

        }


    }
    return l;

}
LISTA add_coords_oeste(LISTA l,ESTADO *e)
{
    int jL = obter_pos_jogador(e).linha;
    int jC = obter_pos_jogador(e).coluna;

    for (int i =-1; i <=0 ; ++i)
    {
        COORDENADA c = {jC-1,jL +i};
        ERROS erro = valido(e,c);
        if ( erro == OK){
            l = insere_lista_coords(l, c);
        }

    }
    return l;

}


LISTA add_coords_lista(LISTA l,ESTADO *e)
{

    if (obter_jogador_atual(e) == 1)
    {
        l = add_coords_norte(l,e); // COORDENADAS ULTIMAS SAO AS QUE FICAM MAIS LONGE DO OBJETIVO
        l = add_coords_este(l,e);
        l = add_coords_oeste(l,e);
        l = add_coords_sul(l,e); // FICA na cabeça as coordenadas mais  para sul;
        // sendo estas as preferenciais para chegar ao fim;

    }
    else
    {
        l = add_coords_sul(l,e); // COORDENADAS ULTIMAS SAO AS QUE FICAM MAIS LONGE DO OBJETIVO
        l = add_coords_oeste(l,e);
        l = add_coords_este(l,e);
        l = add_coords_norte(l,e); //FICA na cabeça as coordenadas mais para norte;
    }

    return l;



}

ERROS jogar (ESTADO *estado, COORDENADA c)
{

    printf("Jogar c:%d l:%d\n", c.coluna, c.linha);
    COORDENADA posicao_atual = obter_pos_jogador(estado);
    ERROS erro = valido(estado, c);
    if (erro == OK)
    {

        if (c.coluna == 7 && c.linha == 0)

        {
            set_jogador_atual(estado,2);
            erro = ACABOU;
        }
        else if (c.coluna == 0 && c.linha == 7)
        {
            set_jogador_atual(estado,1);
            erro = ACABOU;
        }


        set_Branca_Tabuleiro(estado, c);
        set_Preta_Tabuleiro(estado, posicao_atual);

        // adicionar a jogada
        add_jogadas(estado,c);

        if (erro == ACABOU)
            return erro;

        if (obter_jogador_atual(estado) == 1)
            set_jogador_atual(estado,2);
        else
            set_jogador_atual(estado,1);








    }
    return erro;

}





/*
 * MAIN
 */

int main (int argc, char* argv[])
{


if (argc >= 3) {
    char *entrada = argv[1];
    char *saida = argv[2];

    ESTADO *e = inicializar_estado();

    // LER O FICHEIRO

    ERROS erro1 = ler(e, entrada);

    if (erro1 == ERRO_ABRIR_FICHEIRO)
        print_erro(erro1);


    // JOGADO DO BOT
    LISTA l = NULL;
    l = add_coords_lista(l, e); // adiciona na lista

    char *coords = devolve_cabeca(l); // coordenada da lista

    ERROS erro2 = jogar(e, str_to_coord(coords)); // jogar a coordenada
    //print_movs(e,stdout);
    // GRAVAR NO FICHEIRO
    if (erro2 == OK || erro2 == ACABOU)
        gravar_tabuleiro(e, saida);

}

    return 0;
}
