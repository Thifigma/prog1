#include <stdio.h>
#include <stdlib.h>

void leVetor (int *v, int n)
{
	for (int i = 0; i < n; i++)
		scanf ("%d", &v[i]);
}

void mostraVetor (int *v, int n)
{
	for (int i = 0; i < n; i++)
		printf ("%d ", v[i]);
}

int main ()
{
	int n = 0;	
	int *v = malloc (n*sizeof(int));

	if (!v){
		printf ("Erro de alocacao! \n");
		exit(1);
	}

	scanf ("%d", &n);

	leVetor (v, n);
	mostraVetor (v, n);

	return 0;
}
		

