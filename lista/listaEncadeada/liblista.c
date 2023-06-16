#include <stdlib.h>
#include <stdio.h>
#include  "liblista.h"


lista_t *lista_cria ()
{
    lista_t *l = malloc(sizeof(lista_t));

    if (!(l)){
        printf ("Erro de alocacao! \n");
        return NULL;
    }

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
    nodo_t *aux;

    /*Falha de alocacao. */   
    if (!(novo = malloc(sizeof(nodo_t)))){
        printf ("Erro de alocacao! \n");
        return 0;
    }

    /*Falha de alocacao. */
    if (!(aux = malloc(sizeof(nodo_t)))){
        printf ("Erro de alocacao! \n");
        return 0;
    }

    /*Inicia novo elemento. */
    novo->elemento = elemento;
    novo->prox = NULL;

    /*Se lista vazia meu primeiro nodo
    *sera o novo nodo. Ou seja, coloca o primeiro e sai fora. */
    if (lista_vazia(&l)){
        printf ("Primeiro elemento inserido na lista. \n");
        l->ini = novo;
        printf ("Depois - Chave[%d]\n", l->ini->elemento->chave);
        return 1;
    }

    aux = l->ini;
    while (aux->prox != NULL && aux->elemento->chave < elemento->chave){
        printf ("E.Aux (%d) < E.e (%d)",aux->elemento->chave, elemento->chave);
        aux = aux->prox;
    }

    printf ("Deve ter alguns prints acima. \n");
    return 0;
}