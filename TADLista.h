#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int ocorrencias;
  int indice;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);
int Vazia(TipoLista Lista);
void InsereLista(TipoItem *x, TipoLista *Lista);
void Imprime(TipoLista Lista);
