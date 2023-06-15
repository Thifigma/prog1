#include <stdio.h>
#include "liblista.h"

lista_t *lista_cria ()
{
    lista_t *l;

    if (!(l = malloc(sizeof(lista_t)))){
        printf ("Erro de alocacao! \n");
        return NULL;
    }

    l->ini = NULL;

    return l;
}

int lista_vazia (lista_t *l)
{
    if(!(l))
        return 1;
    return 0;
}

int lista_insere_ordenado (lista_t *l, elemento_t *elemento)
{
    nodo_t *novo;
    nodo_t *aux = l->ini;

    if (!(novo = malloc(sizeof(nodo_t)))){
        printf ("Erro de alocacao! \n");
        return 0;
    }

    /*Inicia novo elemento*/
    novo->elemento = elemento;
    novo->prox = NULL;
    novo->prev = NULL;

    /*Primeiro item a ser inserido na lista. */
    if (lista_vazia(l)){
        l = novo;
        return 1;
    }

    while (aux->prox && aux->elemento->chave < elemento->chave)
        aux = aux->prox;
    
    
}