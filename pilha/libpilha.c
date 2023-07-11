#include <stdlib.h>
#include "libpilha.h"

pilha_t *pilha_cria ()
{
    pilha_t *p;

    if (!(p = malloc (sizeof(pilha_t))))
        return NULL;
    
    p->topo = NULL;
    p->tamanho = 0;

    return p;
}

void pilha_destroi (pilha_t **pilha)
{
    nodo_t *aux;

    /* laco inicia com o topo atualizado*/
    while ((*pilha)->topo ){
        aux = (*pilha)->topo; /*Guarda o topo atual*/
        (*pilha)->topo = (*pilha)->topo->prox; /*atualiza o topo*/
        free (aux);
        (*pilha)->tamanho--;
    }

    free ((*pilha));
    (*pilha) = NULL;
}

int push (pilha_t *pilha, int dado)
{
    nodo_t *aux;
    if (!(aux = malloc(sizeof(nodo_t))))
        return 0;
    
    /*Cria um novo item*/
    aux->dado = dado;
    aux->prox = pilha->topo;

    /*Primeiro apontamento de item*/
    if (pilha_vazia(pilha)){
        pilha->topo = aux;
    }

    /*Empilhamento*/
    pilha->topo = aux;
    pilha->tamanho++;

    return 1;
}

int pop (pilha_t *pilha, int *dado)
{
    nodo_t *aux;

    if (pilha_vazia(pilha))
        return 0;

    *dado = pilha->topo->dado;
    
    /*Salva o topo anterior e 
    *aloca o novo topo*/
    aux = pilha->topo->prox;
    free(pilha->topo);
    pilha->topo = aux;
    pilha->tamanho--;

    return 1;
}

int pilha_topo (pilha_t *pilha, int *dado)
{
    if (pilha_vazia(pilha))
        return 0;
    
    *dado = pilha->topo->dado;

    return 1;
}

int pilha_vazia (pilha_t *pilha)
{
    if (!(pilha->topo))
        return 1;

    return 0;
}

int pilha_tamanho (pilha_t *pilha)
{
    return pilha->tamanho;
}