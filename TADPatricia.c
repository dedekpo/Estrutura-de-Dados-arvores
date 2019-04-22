#include "TADPatricia.h"
#include "TADLista.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Inicializa(TipoArvore *t){
    *t = NULL;
}

int EExterno(TipoArvore aux){
    return (aux->tipoNo == Externo);
}

TipoArvore CriaNoExt(char *palavra, int idDoc){
    TipoArvore aux;
    TipoItem item;
    item.ocorrencias = 1;
    item.indice = idDoc;
    aux = (TipoArvore)malloc(sizeof(TipoPatricia));
    aux->tipoNo = Externo;
    strcpy(aux->NO.NExterno.palavra, palavra);
    FLVazia(&(aux->NO.NExterno.indiceI));
    InsereLista(item,&(aux->NO.NExterno.indiceI));
    aux->NO.NExterno.tamanho = 1;
    return aux;
}

TipoArvore CriaNoInt(int i, TipoArvore *esq, TipoArvore *dir, char letra){
    TipoArvore aux;
    aux = (TipoArvore)malloc(sizeof(TipoPatricia));
    aux->tipoNo = Interno;
    aux->NO.NInterno.dir = *dir;
    aux->NO.NInterno.esq = *esq;
    aux->NO.NInterno.index = i;
    aux->NO.NInterno.letra = letra;
    return aux;
}

TipoArvore InsereEntre(char *palavra, TipoArvore *t, int i, char letra, int idDoc){
    TipoArvore aux;
    //Se for um nó externo, ele cria outro nó externo para a nova palavra, depois cria um no interno que aponta para esses dois nós(t e aux)
    if (EExterno(*t) || i < (*t)->NO.NInterno.index){
        aux = CriaNoExt(palavra,idDoc);
        if (palavra[i] > letra){
            return (CriaNoInt(i, t, &aux, letra));
        }
        else{
            return (CriaNoInt(i, &aux, t, letra));
        }
    }
    else{//Caminha até achar um nó externo
        if (palavra[(*t)->NO.NInterno.index] > (*t)->NO.NInterno.letra)
            (*t)->NO.NInterno.dir = InsereEntre(palavra,&(*t)->NO.NInterno.dir, i ,letra, idDoc);
        else
            (*t)->NO.NInterno.esq = InsereEntre(palavra,&(*t)->NO.NInterno.esq, i , letra, idDoc);
        return (*t);
    }
}


TipoArvore Insere(char *palavra, TipoArvore *t, int idDoc){
    TipoArvore aux;
    TipoApontador auxL;
    TipoItem item;
    int i;
    if(*t == NULL){//Se for uma arvore nula cria uma arvore sendo no externo
        return (CriaNoExt(palavra,idDoc));
    }
    else{
        aux = *t;
        while(!EExterno(aux)){//Caminha na arvore até encontrar um nó externo
            if(palavra[aux->NO.NInterno.index] > aux->NO.NInterno.letra)
                aux = aux->NO.NInterno.dir;
            else
                aux = aux->NO.NInterno.esq;
        }
        //A palavra é igual? Se sim, incremente na lista encadeada; Se não, criar um nó entre;
        if(strcmp(palavra, aux->NO.NExterno.palavra) == 0){
            printf("palavra ja existente\n");
            auxL = aux->NO.NExterno.indiceI.Primeiro->Prox; //Aux Lista recebe a lista do indice invertido
            while (auxL != NULL) {//Incrementa o numero de ocorrecinas
                if (auxL->Item.indice == idDoc){
                    auxL->Item.ocorrencias ++;
                }
                else{
                    while(auxL->Prox != NULL && auxL->Item.indice != idDoc)
                        auxL = auxL->Prox;
                        if(auxL->Item.indice == idDoc)
                            auxL->Item.ocorrencias++;
                        else{
                            if(auxL->Item.indice != idDoc && auxL->Prox == NULL){
                                item.indice = idDoc;
                                item.ocorrencias = 0;
                                InsereLista(item,&(aux->NO.NExterno.indiceI));
                                aux->NO.NExterno.tamanho++;
                            }
                        }
                }
                auxL = auxL->Prox;
            }
            return (*t);
        }
        i = 0;
        while (palavra[i] == (aux->NO.NExterno.palavra[i])){
            i++;
		}
		if(palavra[i] > (aux->NO.NExterno.palavra[i])){//A letra é maior? Se sim, InsereEntre recebe a palvra contida na arvore
            return InsereEntre(palavra, t, i, aux->NO.NExterno.palavra[i],idDoc);
		}
		else{//Senão InsereEntre recebe a palavra que está sendo inserida
            return InsereEntre(palavra, t, i, palavra[i],idDoc);
		}
    }
}

void ImprimeArvore(TipoArvore t){//Imprime todos os nós externos
    if(t == NULL){
        printf("Nao ha registros!!!\n");
        return;
    }
    //Quando No é externo, imprime a palavra.
    if(EExterno(t)){
        printf("-> %s \n", t->NO.NExterno.palavra);
        return;
    }
    //Quando não é No externo, percorre a arvore ate encontrar.
    else{
        ImprimeArvore(t->NO.NInterno.esq);
        ImprimeArvore(t->NO.NInterno.dir);
    }
}

void ImprimeIndice(TipoArvore t){//Imprime todos os nós externos
    if(t == NULL){
        printf("Nao ha registros!!!\n");
        return;
    }
    //Quando No é externo, imprime a palavra.
    if(EExterno(t)){
        printf("\nPalavra: %s\n",t->NO.NExterno.palavra);
        Imprime(t->NO.NExterno.indiceI);
        return;
    }
    //Quando não é No externo, percorre a arvore ate encontrar.
    else{
        ImprimeIndice(t->NO.NInterno.esq);
        ImprimeIndice(t->NO.NInterno.dir);
    }
}

void remove_char(char* str, char c)//função para remover pontos e \n não implementada por nós
{
    char *pr= str, *pw = str;

    while(*pr)
    {
        *pw = *pr++;
        pw += (*pw != c);
    }
    *pw = '\0';
}
