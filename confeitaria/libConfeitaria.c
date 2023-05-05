#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libConfeitaria.h"

/*Retorna um frigobar com as prateleiras de cima e de baixo
 * Iniciado com NULL em todas as posicoes*/
struct frigobar *criaFrigobar ()
{
	int aleatoria = 0;
	struct frigobar *fb; 
	scanf("%d", &aleatoria);

	fb = malloc (sizeof(struct frigobar));
	
	for (int i = 0; i < 20; i++)
		fb->Pcima[i] = NULL;
	
	for (int i = 0; i < 10; i++)
		fb->Pbaixo[i] = NULL;

	return fb;
}

/*O que tem de errado aqui? */
void pedido (struct frigobar *fb)
{
	static int nBolo;
	static int nTorta;

	printf ("Quantidade Bolo: ");
	scanf ("%d", &nBolo);
	printf ("Quantidade Torta: ");
	scanf ("%d", &nTorta);

	for (int i= 0; i < nBolo; i++)
		fb->Pcima[i]  = malloc(sizeof(struct bolo) );

	for (int i = 0; i < nBolo; i++){
		printf ("Sabor: \n");
		scanf (" %c", &fb->Pcima[i]->sabor[2]);
		printf ("Dia: ");
		scanf ("%d", &fb->Pcima[i]->validade.dia);
	}

	for (int i= 0; i < nTorta; i++)	
		fb->Pbaixo[i] = malloc( nTorta*sizeof(struct torta) );

}
