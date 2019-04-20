#include <stdio.h>
#include <stdlib.h>

typedef char valorTST;
typedef struct noTST *ApontadorNoTST;

//estrutura do no da TST
typedef struct noTST {
    valorTST caracter;
    short fimDaString : 1; //Flag que indica fim da string
    ApontadorNoTST esq;
    ApontadorNoTST meio;
    ApontadorNoTST dir;
} noTST;

//Função que insere um novo nó na arvore seguindo as condições
void insereNoTST(ApontadorNoTST *arvore, char *palavra);

//Função que cria um novo nó
ApontadorNoTST criaNoTST(char caracter);
