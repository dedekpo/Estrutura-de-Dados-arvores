#include "TST.h"

ApontadorNoTST criaNoTST(valorTST caracter) {
    ApontadorNoTST no = (ApontadorNoTST)malloc(sizeof(noTST));
    no->caracter = caracter;
    no->fimDaString = 0;
    no->esq = NULL;
    no->meio = NULL;
    no->dir = NULL;
    return no;
}

void insereNoTST(ApontadorNoTST *arvore, char *palavra) {
    if (!(*arvore))
        *arvore = criaNoTST(*palavra);

    if ((*palavra) < (*arvore)->caracter) {
        insereNoTST(&((*arvore)->esq), palavra);
    } else if ((*palavra) > (*arvore)->caracter) {
        insereNoTST(&((*arvore)->dir), palavra);
    } else {
        if (*(palavra + 1))
            insereNoTST(&((*arvore)->meio), palavra + 1);
        else
            (*arvore)->fimDaString = 1;
    }
}
