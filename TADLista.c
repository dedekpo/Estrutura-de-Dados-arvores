#include "TADLista.h"

void FLVazia(TipoLista *Lista){
    Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void InsereLista(TipoItem *x, TipoLista *Lista){
    Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Item = *x;
    Lista -> Ultimo -> Prox = NULL;
}

void Imprime(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Primeiro -> Prox;
    while (Aux != NULL){
        printf("Ocorrencias: %d\n", Aux -> Item.ocorrencias);
        printf("Indice: %d\n", Aux -> Item.indice);
        Aux = Aux -> Prox;
    }
}
