#include <stdio.h>
#include <stdlib.h>


struct aluno {
	char nome[80];
	int idade;
	float ira;
};


int main ()
{
	/*Ponteiro para estrutura  alunos*/
	struct aluno *lista;

	/*Define o tamanho de bytes a ser buscado na heap.*/
	int tam = 0;

	/*Conta os reallocs*/
	int cont = 0;
	
	/*Determina o tamanho do vetor*/
	scanf ("%d", &tam);
	
	lista = malloc (tam*sizeof(struct aluno));
	if (!lista){
		printf ("Erro de alocacao! \n");
		exit (1);
	}
	
	printf ("Endereco antes: %p \n", lista);

	/*Novo tamanho: */
	scanf ("%d", &tam);

	lista = realloc (lista, tam*sizeof(struct aluno));
	while (!lista){
		cont++;

		scanf ("%d", &tam);
		lista = realloc (lista, tam*sizeof(struct aluno) );	
	}


	printf ("Valor de chamados de realloc: %d \n", cont);
	printf ("Endereco depois: %p \n", lista);

	free (lista); 

	return 0;
}


