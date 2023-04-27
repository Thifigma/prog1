#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libConfeitaria.h"

/*Retorna um frigobar com as prateleiras de cima e de baixo
 * Iniciado com NULL em todas as posicoes*/
struct frigobar  criaFrigobar ()
{
	struct frigobar fb;

	for (int i = 0; i < 20; i++)
		fb.Pcima[i] = NULL;

	for (int i = 0; i < 10; i++)
		fb.Pbaixo[i] = NULL;

	return fb;
}


void pedido (struct frigobar *fb)
{
	int nBolo;
	int nTorta;

	/*Define a quantidade de bolo*/
	scanf ("%d", &nBolo);
	while (nBolo > 20){
		printf("Leia n Bolo menor que 20 \n");
		scanf ("%d", &nBolo);
	}

	fb->Pcima = malloc ( nBolo*sizeof(struct bolo) );
	if (!fb->Pcima){
		printf ("Erro de alocacao! \n");
		exit (1);
	}

		
