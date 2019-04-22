#include <stdio.h>
#include <stdlib.h>
#ifndef TADLISTA_H_INCLUDED
#define TADLISTA_H_INCLUDED

typedef struct TipoItem{//TipoItem armazena as o numero de ocorrencias e o indice do arquivo
  int ocorrencias;
  int indice;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);
int Vazia(TipoLista Lista);
void InsereLista(TipoItem x, TipoLista *Lista);
void InsereIgual(TipoLista *Lista, int idDoc);
void Imprime(TipoLista Lista);
void IniciarItem(TipoItem *item);


#endif
