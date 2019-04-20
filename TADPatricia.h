#include "TADLista.h"
#include "TST.h"

#define tam 30
typedef unsigned int TipoIndex;

typedef enum {
  Interno, Externo
} TipoNo;

typedef struct TipoPatricia* TipoArvore;

typedef struct TipoPatricia{
    TipoNo tipoNo;
    union {
        struct {
            int index; //Indicie para identificar qual posição do caractere da chave que deve ser analisado
            char letra; //Caractere a ser comparado ao caractere da chave
            TipoArvore esq, dir;
        } NInterno;
        struct{
            char palavra[tam]; //Palavra armazenada na arvóre
            TipoLista lista;            //Lista encadeada;
            int tamanho;
        }NExterno;
    }NO;
} TipoPatricia;


void Inicializa(TipoArvore *t);
int EExterno(TipoArvore aux);
TipoArvore CriaNoExt(char *palavra);
int ComparaLetra(TipoArvore *t, char *palavra);
char ComparaIndice(int i, char *palavra);

TipoArvore Insere(char *palavra, TipoArvore *t);

TipoArvore InsereEntre(char *palavra, TipoArvore *t, int i, char letra);
TipoArvore CriaNoInt(int i, TipoArvore *esq, TipoArvore *dir, char letra);
void Pesquisa(char *palavra, TipoArvore t);
void ImprimeArvore(TipoArvore t);
void CorrigePalavra(char *palavra);
