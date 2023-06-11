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

int lista_insere_ordenado (lista_t *l, elemento_t *elemento)
{
    nodo_t *novo = malloc (sizeof(nodo_t));
    nodo_t *aux;

    if (!(novo ))
        return 0;

    /*Iniica o novo nodo*/
    novo->elemento = elemento;
    novo->prox = NULL;


    /*Insere o primeiro elemento no inicio da lista*/
    if (lista_vazia(&l)){
        l->ini = novo;
        return 1;
    }

    /*Verificar em qual posição da lista 
    a chave deve ser inserida */
    aux = l->ini;
    while (aux->prox && aux->elemento->chave < elemento->chave)
        aux = aux->prox;
    
    novo->prox = aux->prox;
    aux->prox = novo;

    free (novo);

    return 1;
}

int lista_remove_ordenado (lista_t *l, elemento_t *elemento)
{
    nodo_t *aux;
    nodo_t *remover;

    if (lista_vazia(&l)){
        printf ("Lista vazia! \n");
        return 0;
    }

    aux = l->ini;
    while (aux->prox && aux->elemento->chave != elemento->chave)
        aux = aux->prox;
    
    if (!(aux->prox)){
        printf ("Elemento nao esta na lista. \n");
        return 0;
    }
    
    remover = aux;
    aux->prox = aux->prox->prox;

    free(remover->elemento);
    free (remover); 

    return 1;
}