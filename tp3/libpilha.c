#include <stddef.h>
#include <stdlib.h>
#include "libpilha.h"

pilha_t *pilha_cria ()
{
    pilha_t *p;

    p = malloc (sizeof(pilha_t));
    if (!p)
        return NULL;
    
    p->topo = NULL;
    p->tamanho = 0;

    return p;
}

void pilha_destroi (pilha_t **pilha)
{
    nodo_t *aux;

    while ( (*pilha)->topo != NULL) {
        aux = (*pilha)->topo;
        (*pilha)->topo = (*pilha)->topo->prox;
        free (aux);
    }

    free (*pilha);
    *pilha = NULL;
}

int push (pilha_t *pilha, int dado)
{
    nodo_t *aux;
    aux = malloc (sizeof(nodo_t));
    if (!aux)
        return 0;

    aux->dado = dado;
    aux->prox = pilha->topo;
    pilha->tamanho++;
    pilha->topo = aux;
    if (!pilha->topo)
        return 1;
    else
        return 0;   
}

int pop (pilha_t *pilha, int *dado)
{
    nodo_t *aux;

    if (!pilha_vazia(pilha)){
        aux = pilha->topo->prox;
        *dado = pilha->topo->dado;
        free (pilha->topo);
        pilha->tamanho--;
        pilha->topo = aux;
        return 1;
    }

    return 0;
}

int pilha_topo (pilha_t *pilha, int *dado)
{
    if (!pilha->topo){
        return 0;
    }

    *dado = pilha->topo->dado;
    
    return 1;
}

int pilha_vazia (pilha_t *pilha)
{
    if (!pilha->topo)
        return 1;
    return 0;
}

int pilha_tamanho (pilha_t *pilha)
{
    return pilha->tamanho;
}