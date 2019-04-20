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

//Fun��o que insere um novo n� na arvore seguindo as condi��es
void insereNoTST(ApontadorNoTST *arvore, char *palavra);

//Fun��o que cria um novo n�
ApontadorNoTST criaNoTST(char caracter);
