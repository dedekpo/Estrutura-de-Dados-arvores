#include "TADLista.h"

void FLVazia(TipoLista *Lista){
    Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Primeiro;
    Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void InsereLista(TipoItem x, TipoLista *Lista){
    Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista -> Ultimo = Lista -> Ultimo -> Prox;
    Lista -> Ultimo -> Item = x;
    Lista -> Ultimo -> Prox = NULL;
}

void InsereIgual(TipoLista *Lista, int idDoc){
  Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;

  // Iniciando os dados da célula antes de atribuir seus valores iniciais para
  // utilização na árvore PATRICIA
  IniciarItem(&Lista->Ultimo->Item);
  Lista->Ultimo->Item.indice = 0;
  Lista->Ultimo->Item.ocorrencias = 0;
  Lista -> Ultimo -> Item.ocorrencias++;
  Lista -> Ultimo -> Item.indice = idDoc;
  Lista -> Ultimo -> Prox = NULL;
}

void IniciarItem(TipoItem *Item){
  Item->indice = 0;
  Item->ocorrencias = 0;
}

void Imprime(TipoLista Lista){
    TipoApontador Aux;
    Aux = Lista.Primeiro->Prox;
    while (Aux != NULL){
        printf("Indice: %d\n", Aux -> Item.indice);
        printf("Ocorrencias: %d\n", Aux -> Item.ocorrencias);
        Aux = Aux -> Prox;
    }
}

