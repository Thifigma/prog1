#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "libAgenda.h"

#define HORAS_DO_DIA 24
#define DIAS_DO_ANO 365

/* esta função transforma uma data lida pelo usuário para uma struct data
 * em uma data do tipo struct tm definida pela biblioteca time.h. 
 * Esta data é então transformada em segundos com a função mktime, para que
 * os outros membros da struct sejam preenchidos automaticamente, e então
 * reconvertida para uma data do tipo struct tm, reescrevendo a variável 
 * original. Com isso, pode-se obter o membro tm_yday, que representa o
 * dia do ano representado pela data: um inteiro entre 0 e 364 */
int obtemDiaDoAno(struct data d) {
	struct tm tipodata;
	time_t segundos;
	int dia_do_ano;

	tipodata.tm_mday = d.dia;
    tipodata.tm_mon = d.mes-1;
    tipodata.tm_year = d.ano-1900;
    tipodata.tm_isdst = -1;
	tipodata.tm_hour = 0;

	/* converte data para época, isto é, segundos desde 1970 */
	segundos = mktime(&tipodata);
	/* converte época em data, obtendo assim automaticamente
	 * o campo 'dia do ano' (tm_yday) que será o índice do
	 * vetor necessário para marcar um compromisso */
	tipodata = *localtime(&segundos);
	/* da reconversão da data, obtém o dia do ano, um número
	 * entre 0 e 364 */
    dia_do_ano = tipodata.tm_yday;
	
	return dia_do_ano;
}

/* DAQUI PARA BAIXO É COM VOCÊS! SIGAM O ENUNCIADO E O HEADER DISPONÍVEL */

//os Obtem usa para validar a data
int obtemHora(struct compromisso comp)
{
	return comp.hora_compr;
}

int obtemAno(struct agenda ag)
{
	return ag.ano;
}

//Toda a agenda vai ser preenchida com  ( 0 ).
struct agenda criaAgenda (int ano)
{
	struct agenda folha;
	folha.ano = ano;
	
	//Inicializa a agenda do ano fornecido.
	for (int i = 0; i < DIAS_DO_ANO; i++)
		for (int j = 0; j < HORAS_DO_DIA; j++)
			folha.agenda_do_ano[i].horas[j] = 0;

	return folha;
}

struct compromisso leCompromisso()
{
	struct compromisso evento;
	
	printf ("Ano do evento: ");
	scanf ("%d", &evento.data_compr.ano); 

	printf ("Mes do evento: ");
	scanf ("%d", &evento.data_compr.mes);

	printf ("Dia do evento: ");
	scanf ("%d", &evento.data_compr.dia);

	printf ("Hora do evento: ");
	scanf ("%d", &evento.hora_compr);


	return evento;
}

/*So eh valida se esta no mesmo ano. 
 *So é valida se o dia estiver no intervalo de tempo do mes em questao 28, 30 ou 31*/
int validaData(struct data d, struct agenda ag) //Como montar o vetor de agenda do ano?
{
	//D é  as datas do meu compromisso. 
	//ag é a agenda iniciada. 

	if (d.ano == ag.ano) {

		//Verifica os dias de cada mes. 
		switch (d.mes){
		case (1):
				if ((d.dia >= 1) && (d.dia <= 31))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente!\n");
					return 0;
				}
		break;

		case (2):
				if ((d.dia >= 1) && (d.dia <= 28))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente!\n");
					return 0;
				}
		break;

		case (3):
				if ((d.dia >= 1) && (d.dia <= 31))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente!\n");
					return 0;
				}
		break;

		case (4):
				if ((d.dia >= 1) && (d.dia <= 30))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;
		
		case (5):
				if ((d.dia >= 1) && (d.dia <= 31))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;

		case (6):
				if ((d.dia >= 1) && (d.dia <= 30))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;

		case (7):
				if ((d.dia >= 1) && (d.dia <= 31))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;

		case (8):
				if ((d.dia >= 1) && (d.dia <= 31))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;

		case (9):
				if ((d.dia >= 1) && (d.dia <= 30))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;
		
		case (10):
				if ((d.dia >= 1) && (d.dia <= 31))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;

		case (11):
				if ((d.dia >= 1) && (d.dia <= 30))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;

		case (12):
				if ((d.dia >= 1) && (d.dia <= 31))
					return 1;
				else {
					printf ("Dia incorreto. Tente novamente! \n");
					return 0;
				}
		break;

		default:
			printf ("Mes invalido. Tente novamente! \n");
			return 0;
			break;
		}
	} else {
		printf ("Ano invalido. Tente novamente! \n");
		return 0;
	}
}

//Tem como usar o obtem? 
int verificaDisponibilidade(struct compromisso compr, struct agenda ag)
{
	if (ag.agenda_do_ano[compr.data_compr.dia].horas[compr.hora_compr] == 0)
		return 1; // 0 na agenda quer dizer livre, logo retorna 1 para dizer que esta livre
	else
		return 0;
}

//Posso usar obtemHora e obtemDia?
struct agenda marcaCompromisso(struct agenda ag, struct compromisso compr)
{
	if ( validaData (compr.data_compr, ag) == 1){
		if ( verificaDisponibilidade (compr, ag) == 1 ){
			ag.agenda_do_ano[compr.data_compr.dia].horas[compr.hora_compr] = 1;
			printf ("Compromisso agendado com sucesso! \n");
			return ag;
		} else{
			printf ("Data não disponivel! \n");
			return ag;
		}
	} else{
		printf ("Data invalida! \n");		
		return ag;
	}
}

//Datas? Dia mes e ano?
void listaCompromissos(struct agenda ag)
{
	for (int i = 0; i < DIAS_DO_ANO; i++)
		for (int j = 0; j < HORAS_DO_DIA; j++)
			if (ag.agenda_do_ano[DIAS_DO_ANO].horas[HORAS_DO_DIA] == 1) {
				printf ("Dia: %d \n", i);
				printf ("Horas: %d Hrs. \n", j);
			}
}