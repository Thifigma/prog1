#include "libAgenda.h"
#include <stdio.h>


int main ()
{
	/*Variavel para saida do laco*/
	char saida = ('c');

	/*Ano fornecido pelo usuario*/
	int ano = 0;

	struct agenda ag;
	struct compromisso compr;

	scanf ("%d", &ano);
	ag = criaAgenda (ano);

	while (saida != 's'){	
		
		if ( leCompromisso (&ag, &compr) )
			marcaCompromisso (&ag, &compr);
		else
			printf ("Data e/ou hora invalidos, compromisso nao inserido\n");

		scanf (" %c", &saida);	
	}

	listaCompromissos (&ag);

	return 0;
}
