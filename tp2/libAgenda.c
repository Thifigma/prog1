/* 
 * Feito por Marcos Castilho em 06/04/2023
 * para a disciplina CI1001 - Programacao 1
 * obs.: a funcao obtemDiaDoAno foi feita
 * pelo prof. Andre Gregio.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libAgenda.h"

#define LIVRE 0
#define OCUPADA 1
#define MESES 12

int obtemDiaDoAno(struct data d)
{
    struct tm tipodata={0};
    time_t segundos;
    int dia_do_ano;

    tipodata.tm_mday = d.dia;
    tipodata.tm_mon = d.mes - 1;
    tipodata.tm_year = d.ano - 1900;
    tipodata.tm_isdst = -1;
    tipodata.tm_hour = 0;

    /* converte data para epoca, isto eh, segundos desde 1970 */
    segundos = mktime(&tipodata);

    /* converte epoca em data, obtendo assim automaticamente
     * o campo 'dia do ano' (tm_yday) que sera o indice do
     * vetor necessario para marcar um compromisso */
    tipodata = *localtime(&segundos);

    /* da reconversao da data, obtem o dia do ano, um numero
     * entre 0 e 364 */
    dia_do_ano = tipodata.tm_yday;

    return dia_do_ano;
}

/* Daqui para frente eh com voces! */

int obtemHora (struct compromisso *compr)
{
	return compr->hora_compr;
}

int obtemAno (struct agenda *ag)
{
	return ag->ano;
}

/*Inicializa a agenda*/
struct agenda criaAgenda (int ano)
{
	struct agenda AgLivre;
	AgLivre.ano = ano;
	
	for (int i = 0; i < DIAS_DO_ANO; i++)
		for (int j = 0; j <HORAS_DO_DIA; j++)
			AgLivre.agenda_do_ano[i].horas[j] = 0;
	return AgLivre;
}

/*Define o maximo de dias de cada mes
 * Os meses sao representados pelos indices de 0 a 11*/
int validaData (struct agenda *ag, struct data *d)
{
	int v[MESES] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	if (obtemAno(ag) == d->ano) {
		if ( d->mes > 0 && d->mes <= 12){
			 if( d->dia > 0 && d->dia <= v[d->mes - 1] )
				return 1;
			else 
				return 0;	
		} else 
			return 0;
	} else 
		return 0;
}

int validaHora (struct compromisso *compr)
{
	if (compr->hora_compr > 0 && compr->hora_compr <= 23)
		return 1;
	return 0;
}

int verificaDisponibilidade (struct agenda *ag, struct compromisso *compr)
{
	if ( ag->agenda_do_ano[obtemDiaDoAno (compr->data_compr)].horas[obtemHora (compr)] == 0)
		return LIVRE;
	return OCUPADA;
}

/*So deixa inserir o compromisso na agenda
 * se for uma data valida*/
int leCompromisso (struct agenda *ag, struct compromisso *compr)
{
	scanf ("%d",&compr->data_compr.dia);
	scanf ("%d",&compr->data_compr.mes);
	scanf ("%d",&compr->data_compr.ano);
	scanf ("%d",&compr->hora_compr);

	if ( validaData (ag, &compr->data_compr) ){
		if (validaHora (compr) )
			return 1;
		else
			return 0;	
	} else	
		return 0;
}

/*Marca o compromisso se a agenda estiver livre
 *A data ja vem validada*/
void marcaCompromisso(struct agenda *ag, struct compromisso *compr)
{
	if ( !verificaDisponibilidade(ag, compr) ) {
		ag->agenda_do_ano[obtemDiaDoAno (compr->data_compr)].
		horas[obtemHora(compr)] = 1;
		printf ("Compromisso inserido com sucesso! \n");
	} else
		printf ("Data/Hora ocupada, compromisso nao inserido \n");
}

void listaCompromissos(struct agenda *ag)
{
	for (int i = 0; i < DIAS_DO_ANO; i++)
		for (int j = 0; j < HORAS_DO_DIA; j++) {
			if (ag->agenda_do_ano[i].horas[j] == 1)
				printf ("Dia: %d, ano: %d, hora: %d, compromisso!\n",
				i, 
				ag->ano, 
				j);
		}
}
