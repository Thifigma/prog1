#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libConfeitaria.h"

/*Retorna um frigobar com as prateleiras de cima e de baixo
 * Iniciado com NULL em todas as posicoes*/
struct frigobar criaFrigobar ()
{
	struct frigobar fb; 

	*fb.Pcima = malloc (20*sizeof(struct torta));
	if (!fb.Pcima){
		printf ("Erro de alocação! \n");
		exit (1);
	}

	*fb.Pbaixo = malloc (10*sizeof(struct bolo));
	if (!fb.Pbaixo){
		printf ("Erro de alocação! \n");
		exit (1);
	}

    /*Todo espaco recebido pelo malloc é NULLADO*/
	for (int i = 0; i < 20; i++)
		fb.Pcima[i] = NULL;

	for (int i = 0; i < 10; i++)
		fb.Pbaixo[i] = NULL;

	return fb;
}

void pedido (struct frigobar *fb)
{
	static int nBolo = 0;
	static int nTorta = 0;

/*Leitura da quantidade de bolo*/

	scanf ("%d", &nBolo);
	while (nBolo > 20){
		printf ("Erro! nBolo > 20, tente novamente! \n");
		scanf ("%d", &nBolo);
	}
	*fb->Pcima = malloc (nBolo*sizeof(struct bolo));
	if (!fb->Pcima){
		printf ("Erro de alocacao! \n");
		exit (1);
	}

	/*Leitura da quantidade de torta*/

	scanf ("%d", &nTorta);
		while (nTorta > 10){
		printf ("Erro! nTorta > 10, tente novamente! \n");
		scanf ("%d", &nTorta);
	}

	*fb->Pbaixo = malloc (nTorta*sizeof(struct torta));
	if (!fb->Pbaixo){
		printf ("Erro de alocacao! \n");
		exit (1);
	}
}