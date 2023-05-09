#include <stddef.h>
#include <stdlib.h>
#include "libpilha.h"

pilha_t *pilha_cria ()
{
    pilha_t *p;

    p = malloc (sizeof(pilha_t));
    if (!p){
        return NULL;
    }
    
    p->topo = NULL;
    p->tamanho = 0;

    return p;
}

void pilha_destroi (pilha_t **pilha)
{
   
}

int push (pilha_t *pilha, int dado)
{
    struct nodo *aux;

    aux->dado = dado;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    if (!pilha->topo)
        return 1;
    else
        return 0;
    
}

int pop (pilha_t *pilha, int *dado)
{

}