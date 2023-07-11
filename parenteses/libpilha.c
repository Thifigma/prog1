#include <stdio.h>
#include <stdlib.h>
#include "libpilha.h"

pilha_t *pilha_cria (){

	pilha_t *pilha;

	if(!(pilha = malloc(sizeof(pilha_t))))
		return 0;

	pilha->tamanho = 0;
	pilha->topo = NULL;

	return pilha;
}

int push (pilha_t *pilha, int dado){

	/*variavel auxiliar para salvar o endereço do topo anterior*/
	nodo_t *aux = NULL;
	
	if (pilha->topo)
		aux = pilha->topo;

	if (!(pilha->topo = malloc(sizeof(nodo_t))))
		return 0;		
	
	pilha->tamanho++;
	pilha->topo->prox = aux;
	pilha->topo->dado = dado;
		
	return 1;
}

int pop (pilha_t *pilha, int *dado){

	/*variavel auxiliar para guardar o endereco salvo no prox, que
	 sera liberado junto ao topo, e depois apontar o topo para esse
	 endereço*/
	nodo_t *aux = NULL;

	if (!pilha->topo)
		return 0;
	
	aux = pilha->topo->prox;
	*dado = pilha->topo->dado;

	free(pilha->topo);
	pilha->tamanho--;
	
	pilha->topo = aux;

	return 1;
}

int pilha_topo (pilha_t *pilha, int *dado){

	if (!pilha->topo)
		return 0;

	*dado = pilha->topo->dado;

	return 1;	
}

int pilha_tamanho (pilha_t *pilha){

	return pilha->tamanho;
}

int pilha_vazia (pilha_t *pilha){

	if(!pilha->topo && pilha->tamanho == 0 )
		return 1;
	return 0;
}

void pilha_destroi (pilha_t **pilha){
	
	int cond = 1;
	int dado = 0;

	/*laço que da pop(free) em toda os membros da pilha antes de liberar a pilha*/
	while(cond){
		if(!pop(*pilha, &dado))
			cond = 0;
	}

	free(*pilha);
	*pilha = NULL;
}
