#include <stdio.h>
#include <stdlib.h>
#include "libagenda.h"

/*Aqui vai ser implementado o teste - 'firma' */

#define REUNIOES 100


typedef struct funcionario {
    int lideranca;
    int exp;
    agenda_t *ag;
}funcionario_t;

typedef struct tarefa {
    int tempo_conclusao;
    int dificuldade;
} tarefa_t;

int aleat(int min, int max)
{
    return (rand() %max);
}

int aleat_mult_15(int min, int max)
{
    int num = rand() %max;

    while (num % 15 != 0)
        num = rand() %max;
    
    return num;
}

void inicia_colaborador(funcionario_t *colaborador)
{
    for(int i = 0; i < 30; i++){
        colaborador[i].lideranca = aleat(0, 100);
        colaborador[i].exp = aleat (0, 100);
        colaborador[i].ag = cria_agenda();
    }
}

void inicia_tarefas (tarefa_t *tarefas)
{
    for (int i = 0; i < 100; i++){
        tarefas[i].tempo_conclusao = aleat (0, 100);
        tarefas[i].dificuldade = aleat (30, 80); 
    }
}

/*Verificar a questao dos ponteiros*/
void inicia_compromisso (compromisso_t **reuniao, int *dia)
{
    horario_compromisso_t hc = inicia_hc (&hc);
    *dia = aleat(1, 31);
    int id = (0, REUNIOES - 1); /*Ajustar segundo parametro*/
    char descricao; /*Ajustar descrcao conforme FIRMA e ajustar problemas de seguranca*/

    (*reuniao) = cria_compromisso (hc, id, descricao);
}

compromisso_t *compromisso_atual (agenda_t *agenda_funcionario)
{  
    return agenda_funcionario->ptr_mes_atual->dias->comprs; 
}

horario_compromisso_t inicia_hc(horario_compromisso_t *hc)
{
    hc->ini_h = aleat(8, 12);
    hc->ini_m = aleat_mult_15 (0, 45);
    hc->fim_h = hc->ini_h + aleat(1, 4);
    hc->fim_m = hc->ini_m;

    return *hc;
}



int escolhe_lider (funcionario_t *colaborador)
{
    int lider;

    lider = aleat(0, 29);
    while (colaborador[lider].lideranca < 30 || colaborador[lider].lideranca > 70)
        lider = aleat(0, 29);
    
    return lider;
}

int escolhe_membro (funcionario_t *colaborador)
{
    int membro = aleat(0, 29);
    
    return membro;
}

int main () 
{
    funcionario_t colaborador[30];
    tarefa_t tarefas[100];
    compromisso_t *reuniao;

    /*Indice do vetor colaborador*/
    int lider;
    int dia;
    int mes;
    int membro;


    inicia_colaborador(&colaborador);
    inicia_tarefas (&tarefas);

    for (mes = 1; mes <= 12; mes++)
        for (int i = 0; i < REUNIOES; i++){

            lider = escolhe_lider(&colaborador);
            
            inicia_compromisso (&reuniao, &dia);
            
            if (marca_compromisso_agenda(colaborador[lider].ag, dia, reuniao) > 0){
                  int max_membros = aleat (2, 6);

                  for (int j = 0; j < max_membros; j++){
                    membro = escolhe_membro(&colaborador);

                    if (colaborador[lider].lideranca > colaborador[membro].lideranca + aleat(-20, 10))
                        if (marca_compromisso_agenda(colaborador[membro].ag, dia, reuniao) < 0)
                            desmarca_compromisso_agenda(colaborador[lider].ag, dia, reuniao);
                    else
                         desmarca_compromisso_agenda(colaborador[lider].ag, dia, reuniao);
                }
            }
        }

    for (mes = 1; mes < 12; mes ++){
        for (dia = 1; dia < 31; dia ++){
            for (int i = 0; i < REUNIOES; i++){
                for (int id = 0; id < 30; id++){
                    compromisso_t *compromisso = compromisso_atual(colaborador[id].ag);

                    while (compromisso){
                        int tarefa_id = compromisso->id;

                        if(tarefas[tarefa_id].tempo_conclusao > 0){
                            
                        }
                    }
                }
            }
        }
    }
    return 0;
}