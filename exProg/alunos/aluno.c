#include <stdio.h>
#include <stdlib.h>


struct aluno {
	char nome[80];
	int idade;
	float ira;
};


int main ()
{
	struct aluno *lista;
	int tam = 0;
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

	return 0;
}


