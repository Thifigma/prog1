#include <stdlib.h>
#include "liblista.h"

lista_t *lista_cria()
{
    lista_t *l;

    if (! (l = malloc (sizeof(lista_t))))
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

int lista_insere_ordenado (lista_t *l, elemento_t *elemento)
{
    nodo_t *novo;

    if (!(novo = malloc(sizeof(nodo_t))))
        return 0;
    
    /*Inicia o novo elemento*/
    novo->elemento = elemento;
    novo->prox = NULL;

    if (lista_vazia(l)){
        l->ini->prox = novo->prox;
        l->ini->elemento = novo->elemento;
    }

}