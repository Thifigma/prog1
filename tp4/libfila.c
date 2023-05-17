#include <stddef.h>
#include <stdlib.h>
#include "libfila.h"

fila_t *fila_cria ()
{
    fila_t *fila;

    fila = malloc (sizeof(fila_t));
    if (!fila)
        return NULL;

    fila->cabeca = NULL;
    fila->cauda = NULL;
    fila->tamanho = 0;

    return fila;
}

void fila_destroi (fila_t **fila)
{
    nodo_t *aux;

    while ((*fila)->cabeca != NULL){
        aux = (*fila)->cabeca; /*Salva a cabeca*/
        (*fila)->cabeca = (*fila)->cabeca->prox; /*vai em direcao a cauda*/
        free (aux);
    }

    free ((*fila));
    *fila = NULL;
}

int enqueue (fila_t *fila, int dado)
{
    nodo_t *aux;
    aux = malloc (sizeof(nodo_t));
    if (!aux)
        return 0;
    
    aux->dado = dado;
    aux->prox = fila->cauda;
    fila->cauda = aux;
    fila->tamanho++;

    return 1;
}

int dequeue (fila_t *fila, int *dado)
{
    nodo_t *aux;
    
    if ( !fila_vazia(fila) ){
        *dado = fila->cabeca->dado;

        aux = fila->cabeca->prox;
        free (fila->cabeca);
        fila->cabeca = aux;
        fila->tamanho--;

        return 1;
    }

    return 0;
}

int fila_tamanho (fila_t *fila)
{
    return fila->tamanho;
}

int fila_vazia (fila_t *fila)
{
    if ( (!fila->cabeca) && (!fila->cauda) )
        return 1;
    return 0;
}