#include <stdio.h>
#include <stdlib.h>
#include "TADPatricia.h"
#include "TADLista.h"


TipoArvore arquivo(TipoArvore *buscador, int idDoc){
    FILE *arq;
    char nomeArquivo[30], palavra[30];
    int i;
    printf("Insira o nome do arquivo com a extensao:\n");
    fflush(stdin);
    gets(nomeArquivo);
    fflush(stdin);
    printf("%s",nomeArquivo);
    arq = fopen(nomeArquivo,"r");
    if(arq == NULL){
        printf("Erro ao inserir o arquivo. \n");
    }
    while(fscanf(arq, "%s", palavra) == 1){
        for(i=0; i<strlen(palavra)+1; i++){
            if(palavra[i] >= 65 && palavra[i] <= 90){
                strlwr(palavra);
            }
            if(palavra[i] >= 31 && palavra[i] <65){
                remove_char(palavra,palavra[i]);
                printf("%s\n",palavra);
            }
        }
        buscador = Insere(palavra,&buscador,idDoc);
    }
    fclose(arq);
    return buscador;
}

int main(){
    int i = 0, opcao, idDoc = 0;
    TipoArvore buscador;
    Inicializa(&buscador);
    do{
        printf("\nDigite a opcao desejada:\n");
        printf(" 1) Construir o indice invertido, a partir dos textos de entrada, usando o TAD arvore PATRICIA\n");
        printf(" 2) Imprimir o indice invertido, contendo as palavras em ordem alfabetica, uma por linha, com suas respectivas listas de ocorrencias e\n");
        printf(" 3) Buscar palavra (s) no (s) texto (s), a partir do indice construido.\n");
        printf(" 4) Sair\n");
        scanf(" %d",&opcao);
        printf("Opcao escolhida: %d\n",opcao);
        switch (opcao){
            case 1:
                idDoc++;
                buscador = arquivo(buscador,idDoc);
                break;
            case 2:
                ImprimeArvore(buscador);
                ImprimeIndice(buscador);
                break;
            case 3:
                break;
            case 4:
                i=1;
                break;
        }
    }while(i == 0);
    return 0;
}
