#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"


int testa_lista_cria ()
{
    lista_t *l;

    l = lista_cria ();
    if (!l) {
        printf ("Erro de alocacao, fila não criada. \n");
        free (l);
        return 0;
    }


    if (lista_vazia(&l)){
        free(l);
        return 1;
    } else {
        free(l);
        return 0;
    }
}
int main ()
{
    if (testa_lista_cria())
        printf ("Ok, lista_cria funciona e esta vazia! \n");
    else
        printf ("Falha para criar a fila. \n");

    return 0;
}