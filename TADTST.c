/*    #include <stdio.h>
#include <stdlib.h>
#include "TADTST.h"

void Inicializa(TipoApontador *Raiz){
  *Raiz = NULL;
}

//Fun��o para inserir uma nova palavra na TST
void Insercao(TipoApontador *Raiz, char *Palavra){
    //Caso base: A �rvore � vazia
    if (*Raiz == NULL){
      *Raiz = (TipoApontador)malloc(sizeof(TipoNoTST));
      (*Raiz)->Chave = *Palavra;
      (*Raiz)->FimDeString = 0;
      (*Raiz)->Esq = (*Raiz)->Meio = (*Raiz)->Dir = NULL;
    }
    //Se a letra atual da palavra � menor que a letra da raiz,
    //ent�o insere esta palavra na esquerda da raiz
    if ((*Palavra) < (*Raiz)->Chave){
        Insercao(&((*Raiz)->Esq), Palavra);
    }
    //Se a letra atual da palavra � maior que a letra da raiz,
    //ent�o insere esta palavra na direita da raiz
    else if ((*Palavra) > (*Raiz)->Chave){
        Insercao(&((*Raiz)->Dir), Palavra);
    }
    //Se a letra atual da palavra � a mesma da raiz,
    else{
        if (*(Palavra+1) != '\0'){
            Insercao(&((*Raiz)->Meio), Palavra+1);
        }
        else{
            //O �ltimo caracter da palavra
            (*Raiz)->FimDeString = 1;
        }
    }
}


//Fun��o para pesquisar uma dada palavra na TST
void Pesquisa(TipoApontador Raiz, char *Palavra){
    if (Raiz == NULL){
        printf("Palavra nao encontrada ou arvore vazia!\n");
    }
    else if (*Palavra < (Raiz)->Chave){
        Pesquisa(Raiz->Esq, Palavra);
    }
    else if (*Palavra > (Raiz)->Chave){
        Pesquisa(Raiz->Dir, Palavra);
    }
    else{
        if (*(Palavra+1) == '\0' && Raiz->FimDeString == 1){
            printf("Palavra encontrada!\n");
        }
        else{
          Pesquisa(Raiz->Meio, Palavra+1);
        }
    }
}*/
