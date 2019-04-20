#include <stdio.h>
#include <stdlib.h>
#include "TADPatricia.h"

int main()
{
    char palavra[20];
    ApontadorNoTST raiz = NULL;
    TipoArvore *t = NULL;
    //Inicializa(&t);

    for(int i=0; i<3; i++){
        scanf("%s", palavra);
        t = Insere(palavra, &t);
        insereNoTST(&raiz, palavra);
        printf("INSERIDO NA ARVORE!!!\n");

    }

    ImprimeArvore(t);

return 0;
}
