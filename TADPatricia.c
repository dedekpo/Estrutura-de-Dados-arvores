#include "TADPatricia.h"
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


TipoArvore CriaNoExt(char *palavra){
    TipoArvore aux;
    TipoItem item;

    aux = (TipoArvore)malloc(sizeof(TipoPatricia));
    aux->tipoNo = Externo;
    strcpy(aux->NO.NExterno.palavra, palavra);

    // chama função da lista encadeada para inserir o diretorio
    //Inicializa(&(aux->NO.NExterno.lista));
    //InsereLista(&item,&(aux->NO.NExterno.lista));
    //aux->NO.NExterno.tamanho = 1;
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
/*//Função que cria uma No interno.
TipoArvore CriaNoInt (int bit, TipoArvore *Esq, TipoArvore *Dir, char c){
	TipoArvore p;
	p = (TipoArvore)malloc(sizeof(TipoPatNo));
	p-> Nt = Interno;
	p->NO.NInterno.Esq = *Esq;
	p->NO.NInterno.Dir = *Dir;
	p->NO.NInterno.Avancar = bit;
	p->NO.NInterno.Comparar = c;
	return p;
}*/


/*int ComparaLetra(TipoArvore *t, char *palavra){
    TipoArvore aux;
    printf("%d", aux->NO.NInterno.index);
    if(palavra[aux->NO.NInterno.index] > aux->NO.NInterno.letra)
        return 1;                                   //1 anda pra direita
    else
        return 0;                                   //0 anda pra esquerda
}*/


/*char ComparaIndice(int i, char *palavra){
    return palavra[i];
}*/


TipoArvore InsereEntre(char *palavra, TipoArvore *t, int i, char letra){
    TipoArvore aux;

    if (EExterno(*t) || i < (*t)->NO.NInterno.index){
        aux = CriaNoExt(palavra);
        if (palavra[i] > letra)
            return (CriaNoInt(i, t, &aux, letra));
        else
            return (CriaNoInt(i, &aux, t, letra));
    }
    else{
        if (palavra[(*t)->NO.NInterno.index] > (*t)->NO.NInterno.letra)
            (*t)->NO.NInterno.dir = InsereEntre(palavra,&(*t)->NO.NInterno.dir, i ,letra);
        else
            (*t)->NO.NInterno.esq = InsereEntre(palavra,&(*t)->NO.NInterno.esq, i , letra);
        return (*t);
    }
}


TipoArvore Insere(char *palavra, TipoArvore *t){
    TipoArvore aux;
    int i;
   // TipoCelula *celula;
   // TipoItem item;
   CorrigePalavra(palavra);
    if(*t == NULL)
        return (CriaNoExt(palavra));
    //Se é nó externo; Compare: é igual? Se sim, incremente na lista encadeada; Se não, criar um nó entre;
    else{
        aux = *t;
        while(!EExterno(aux)){
            if(palavra[aux->NO.NInterno.index] > aux->NO.NInterno.letra)
                aux = aux->NO.NInterno.dir;
            else
                aux = aux->NO.NInterno.esq;
        }
    //Se não, verifique se esta palavra já existe na árvore. Caso sim, chame funcao da lista encadeada para incrementar o diretório. E retorne.
        if(strcmp(palavra, aux->NO.NExterno.palavra) == 0){
            printf("palavra ja existe\n");
            return (*t);
        }
        i = 0;
        /*while ((i <= strlen(palavra)) && (ComparaIndice(i, palavra) == ComparaIndice(i, aux->NO.NExterno.palavra)))
            i++;
        if(palavra[i] > aux->NO.NExterno.palavra[i])
            (*t) = InsereEntre(palavra, t, i, aux->NO.NExterno.palavra[i]);
        else
            (*t) = InsereEntre(palavra, t, i, palavra[i]);
        }*/
        while (palavra[i] == (aux->NO.NExterno.palavra[i])){
            i++;
		}
		if(palavra[i] > (aux->NO.NExterno.palavra[i]))
            return InsereEntre(palavra, t, i, aux->NO.NExterno.palavra[i]);
		else
             return InsereEntre(palavra, t, i, palavra[i]);
    }
}

void ImprimeArvore(TipoArvore t){//Imprime todos os nós externos
    if(t == NULL){
        printf("Nao ha registros!!!\n");
        return;
    }
    //Quando No é externo, imprime a palavra.
    if(EExterno(t)){
        printf("%s -> ", t->NO.NExterno.palavra);
        //LImprime(&(t->NO.Chave.ListaArq)); //Imprimir a lista de pares(ocorrencia,IDTexto)
        return;
    }
    //Quando não é No externo, percorre a arvore ate encontrar.
    else{
        ImprimeArvore(t->NO.NInterno.esq);
        ImprimeArvore(t->NO.NInterno.dir);
    }
}

void CorrigePalavra(char *palavra){
    strlwr(palavra);
}


/*void Pesquisa(char *k, TipoArvore t){
    if(EExterno(t)){
        if(strcmp(k, t->NO.Chave) == 0)
            printf("Elemento encontrado\n");
        else
            printf("Elemento nao encontrado\n");
        return;
    }
    if(ComparaIndice(t->NO.NInterno.Index, k))

}




void Ordem(TipoArvore ap)
{
    if(ap == NULL)
        return;
    if(!EExterno(ap))
        Ordem(ap->NO.NInterno.Esq);
    printNo(ap);
    if(!EExterno(ap))
        Ordem(ap->NO.NInterno.Dir);
}
*/
