#include <stdio.h>
#include <stdlib.h>


struct aluno {
	char nome[80];
	int idade;
	float ira
}


int main ()
{
	struct aluno *lista;
	int tam;

	/*Determina o tamanho do vetor*/
	scanf ("%d", &tam);
	
	lista = malloc (tam*sizeof(struct aluno));
	if (!lista){
		printf ("Erro de alocacao! \n");
		exit (1);
	}
	
	/*Novo tamanho: */
	scanf ("%d", &tam);

	lista = realloc (lista, tam*sizeof(struct aluno));

	//4?
	//5?

	return 0;
}


