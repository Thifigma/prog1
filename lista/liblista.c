#include <stdlib.h>
#include <stdio.h>
#include  "liblista.h"


lista_t *lista_cria ()
{
    lista_t *l;

    if (!(l = malloc(sizeof(lista_t))))
        return NULL;

    l->ini = NULL;

    return l;
}

int lista_vazia (lista_t **l)
{
    if (!(*l)->ini)
        return 1;
    return 0;
}

int lista_destroi (lista_t **l)
{
    nodo_t *aux = (*l)->ini;
    nodo_t *prox;

    /*Se estiver vazia nao há o que destruir*/
    if (lista_vazia(&(*l))){
        return 0;
    }
    
    while (aux){
        prox = aux->prox;
        free (aux->elemento);
        free(aux);
        aux = prox;
    }   

    free ((*l));
    (*l) = NULL;

    return 1;
}