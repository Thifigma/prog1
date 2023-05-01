#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct caixa {
	int n1;
};

/*Cada posicao do vetor aponta para uma struct caixa*/
struct prateleira {
	struct caixa *v[10];
};

/*Inicia todas as posicoes de V com NULL*/
struct prateleira iniciaPrateleira ()
{
	struct prateleira p;

	for (int i = 0; i < 10; i++)
		p.v[i] = NULL;
	return p;
}


/*Aloca uma um numero N no vetor V*/
void preenchePrateleira (struct prateleira *p)
{
	static int numCaixa;

	printf ("Leia num caixa: ");
	scanf ("%d", &numCaixa);
	while (numCaixa > 10){
		printf ("Excede a capacidade maxima de V \n");
		scanf ("%d", &numCaixa);
	}

	*p->v = malloc ( numCaixa*sizeof(struct caixa) );
	if (!*p->v){
		printf ("Erro de alocacao! \n");
		exit (1);
	}
}

void leCaixa (struct prateleira *p)
{
	for (int i = 0; *p->v != NULL; i++){
		printf ("Leia n1: ");
		scanf ("%d", &p->v[i]->n1);
	}
}

/*Por qual motivo esse programa da falha de segmentação? */
int main ()
{
	struct prateleira p;

	p = iniciaPrateleira ();
	
	preenchePrateleira (&p);
	leCaixa (&p);

	free (p.v);

	return 0;
}
