#include "TADPatricia.h"



void Inicializa(TipoArvore *t){
    *t = NULL;
}


int EExterno(TipoArvore aux){
    if(aux->tipoNo == Externo)
        return 1;
    else
        return 0;
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
    printf("dale\n");
    return aux;
}


int ComparaLetra(TipoArvore *t, char *palavra){
    TipoArvore aux;
    if(palavra[aux->NO.NInterno.index] > aux->NO.NInterno.letra)
        return 1;                                   //1 anda pra direita
    else
        return 0;                                   //0 anda pra esquerda
}


char ComparaIndice(int i, char *palavra){
    return palavra[i];
}


TipoArvore Insere(char *palavra, TipoArvore *t, int indice){
    TipoArvore aux;
    int i;
    TipoCelula *celula;
    TipoItem item;
    if(*t == NULL)
        return (CriaNoExt(palavra));
                //Se é nó externo; Compare: é igual? Se sim, incremente na lista encadeada; Se não, criar um nó entre;
    else{
        aux = *t;
        while(!EExterno(aux)){

            if(ComparaLetra(aux->NO.NInterno.index, palavra) == 1)
                aux = aux->NO.NInterno.dir;
            else
                aux = aux->NO.NInterno.esq;
        }
    //Se não, verifique se esta palavra já existe na árvore. Caso sim, chame funcao da lista encadeada para incrementar o diretório. E retorne.

        i = 0;
        if(strlen(palavra)>= strlen(aux->NO.NExterno.palavra)){
            while ((i <= strlen(palavra)) && (ComparaIndice(i, palavra) == ComparaIndice(i, aux->NO.NExterno.palavra)))
                i++;
            if (i >= strlen(palavra)){
                celula = aux->NO.NExterno.lista.Primeiro;
                if(celula->Item.indice == indice){
                    celula->Item.ocorrencias++;
                    //printf("%d", celula->Item.ocorrencias);
                    }
                else{
                    while(celula->Prox != NULL && celula->Item.indice != indice)
                        celula = celula->Prox;
                    if(celula->Item.indice == indice)
                        celula->Item.ocorrencias++;
                    else if(celula->Item.indice != indice && celula->Prox == NULL){
                    item.indice = indice;
                    item.ocorrencias = 1;
                    //item.relevancia = 0;
                    InsereLista(&(aux->NO.NExterno.lista),&item);
                    aux->NO.NExterno.tamanho++;
                    }
                }
                return (*t);
            }
            else
                return (InsereEntre(palavra, t, i, indice));
        }
        else{
            while ((i <= strlen(palavra)) && (ComparaIndice(i, palavra) == ComparaIndice(i, aux->NO.NExterno.palavra)))
                i++;
            if (i >= strlen(palavra)){
                celula = aux->NO.NExterno.lista.Primeiro;
                if(celula->Item.indice == indice)
                    celula->Item.ocorrencias++;
                else{
                    while(celula->Prox != NULL && celula->Item.indice != indice)
                        celula = celula->Prox;
                    if(celula->Item.indice == indice)
                        celula->Item.ocorrencias++;
                    else if(celula->Item.indice != indice && celula->Prox == NULL){
                    item.indice = indice;
                    item.ocorrencias = 1;
                    //item.relevancia = 0;
                    InsereLista(&(aux->NO.NExterno.lista),&item);
                    aux->NO.NExterno.tamanho++;
                    }
                }
                return (*t);
            }
            else
                return (InsereEntre(palavra, t, i, indice));
        }
    }
}
TipoArvore InsereEntre(char *palavra, TipoArvore *t, int i, int indice){
    TipoArvore aux;
    char letra;

    if (EExterno(*t) || i < (*t)->NO.NInterno.index){
        aux = CriaNoExt(palavra);
        if (ComparaIndice(i, palavra)>= ComparaIndice(i, (*t)->NO.NExterno.palavra)){
            return (CriaNoInt(i, t, &aux, (*t)->NO.NExterno.palavra[i]));
        }
        else
            return (CriaNoInt(i, &aux, t, (*t)->NO.NExterno.palavra[i]));
    }
    else{
        if (ComparaIndice(i, palavra)>= (*t)->NO.NInterno.letra)
            (*t)->NO.NInterno.dir = InsereEntre(palavra,&(*t)->NO.NInterno.dir,i,indice);
        else
            (*t)->NO.NInterno.esq = InsereEntre(palavra,&(*t)->NO.NInterno.esq,i,indice);
        return (*t);
    }
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
