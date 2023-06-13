#include <stdio.h>
#include "libAgenda.h"

int main ()
{
	/*Variavel para operar no switch-case*/
	int escolha;
	char OP;  //Talvez escolha dpode ser um char? 

	//Representa o calendario do ano
	struct agenda calendario;

	struct compromisso evento;
	
	
	//Ano vai ser fornecido pelo usuario 
	int ano;
	printf ("Cria agenda para o ano: ");
	scanf ("%d", &ano);

	//Cria a agenda do ano fornedio.
	calendario = criaAgenda (ano);
//Antes de trabalhar o menu, faz cada case fazer sua função. 
	printf ("------menu------\n");
	printf ("1. Marca Compromisso.\n");
	printf ("2. Lista compromisso. \n.\n");
	printf ("s. Para sair. \n");
	printf ("Escolha :> ");
	
//Talvez um while com uma condicao de para de 's' para sair. um if para cada fim de operacao com uma variavel casting
//Como voltar para a escolha? switch dentro do case
//Valores que sao guardados em case 1 valem par autros cases?

	while (OP != "s") {		
		scanf ("%d", &escolha);
		switch (escolha) {
			case 1:  //Agenda compromisso 
				evento = leCompromisso ();

				/*Quando for 1 é uma data valida.*/
				while ( (validaData(evento.data_compr,calendario)) != 1 ){
					evento = leCompromisso ();
				}

				calendario = marcaCompromisso(calendario, evento);


				// Inicio Menu]
				escolha = (int)"s";
				// Fim menu


			break;

			case 2: //Lista compromisso 

			break;

			case 3: //Case teste saida 

			break;
		}
	}

	return 0;
}
