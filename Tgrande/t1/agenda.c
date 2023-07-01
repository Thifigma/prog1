#include <stdio.h>
#include <stdlib.h>
#include "libagenda.h"

/*Aqui vai ser implementado o teste - 'firma' */

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

void inicia_colaborador(funcionario_t *colaborador)
{
    for(int i = 0; i < 30; i++){
        colaborador[i].lideranca = aleat(0, 100);
        colaborador[i].exp = aleat (0, 100);
        colaborador[i].ag = cria_agenda();
    }
}

void inicia_terafas (tarefa_t *tarefas)
{
    for (int i = 0; i < 100; i++){
        tarefas[i].tempo_conclusao = aleat (0, 100);
        tarefas[i].dificuldade = aleat (30, 80); 
    }
}

int escolhe_lider (funcionario_t *colaborador)
{
    int lider;

    lider = aleat(0, 29);
    while (colaborador[lider].lideranca < 30 || colaborador[lider].lideranca > 70)
        lider = aleat(0, 29);
    
    return lider;
}

int main () 
{
    funcionario_t colaborador[30];
    tarefa_t tarefas[100];
    mes_t meses;
    int lider;

    inicia_colaborador(colaborador);
    inicia_tarefas (tarefas);

    for (meses.mes = 1; meses.mes <= 12; meses.mes++){
        for (int i = 0; i < 100; i++){
            lider = escolhe_lider(colaborador);

        }
    }
    return 0;
}