#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"


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
    if(!(*l)->ini)
        return 1;
    return 0;
}

int lista_insere_ordenado (lista_t *l, elemento_t *elemento)
{
    nodo_t *novo;
    nodo_t *aux;

    if (!(novo = malloc(sizeof(nodo_t))))
        return 0;

    if (!(aux = malloc(sizeof(nodo_t))))
        return 0;

    /*Carrega o elemento a ser inserido no novo nodo. */
    novo->elemento = elemento;
    novo->prox = NULL;


    /*Verifica se vai ser o primeiro elemento a ser inserido. */
    if (lista_vazia(l))
    {
        l->ini->elemento = novo->elemento;
        l->ini->prox = novo->prox;
    }

    /*Caminhar na lista*/
    aux = l->ini;
    while (aux->prox && novo->elemento->chave > aux->elemento->chave)
        aux = aux->prox;
    
    /*Insere ordenado. */
    aux->elemento = novo->elemento;
    aux->prox = novo->prox;
    return 1;
}

int lista_remove_ordenado (lista_t *l, elemento_t *elemento)
{
    nodo_t *atual;
    nodo_t *aux;



    if (lista_vazia(l))
        return 0;

    if (l->ini->elemento->chave == elemento->chave){
        
        /*Se tiver apenas um elemento na lista, 
        *remove e aponta o inicio da lista para NULL*/
        if (!(l->ini->prox)){
            free(l->ini);
            l->ini = NULL;
            return 1;
        }

        aux = l->ini;
        l->ini = l->ini->prox;
        free(aux);
        return 1;
    }

    atual = l->ini;
    while (atual->prox && elemento->chave != atual->elemento->chave)
        atual = atual->prox;

       


}