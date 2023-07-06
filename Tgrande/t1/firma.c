#include <stdlib.h>
#include <stdio.h>
#include "libagenda.h"
#include "firma.h"

int aleat (int min, int max)
{
     return min + rand() % (max - min + 1);
}

/*Diminuir o custo com um desvio no laço. colocar MAX_ALEAT*/
int aleat_mult15 (int min, int max)
{
    int num = min + rand() % (max - min + 1);

    while (num % 15 != 0)
        num = min + rand() % (max - min + 1);;
    return num;
}

void inicia_funcionario (funcionario_t *funcionario)
{
    static int i = 1;
    funcionario->lideranca = aleat(1, 100);
    funcionario->matricula = i;
    funcionario->exp = aleat (20, 100);
    funcionario->ag = cria_agenda();
    i++;
}

void inicia_tarefa (tarefa_t *tarefa)
{
    tarefa->tempo_conclusao = aleat(600, 800);
    tarefa->dificuldade = aleat(30, 80);
}

compromisso_t *cria_nova_reuniao (horario_compromisso_t *hc, int *dia, int * id, char **desc)
{
    compromisso_t *compr;
    hc->ini_h = aleat(8, 12);
    hc->ini_m = aleat_mult15(0, 45);
    hc->fim_h = hc->ini_h + aleat(1, 4);
    hc->fim_m = hc->ini_m;

    *dia = aleat(1, 31);
    *id = aleat(0, 99);

    (*desc) = malloc(sizeof(char)*100);
    if (!(*desc)){
        printf("Erro de alocacao! \n");
        return NULL;
    }

    compr = cria_compromisso(*hc, *id, (*desc));
    return compr;
}

int verifica_lideranca (funcionario_t *candidato)
{
    if (candidato->lideranca >= 30 && candidato->lideranca <= 70)
        return 1;
    return 0;
}

funcionario_t *escolhe_lider (funcionario_t *funcionario)
{
    int indice = aleat (0, 29);
    
    while (!(verifica_lideranca(&funcionario[indice])))
        indice = aleat(0, 29);

    return &funcionario[indice];
}

funcionario_t *escolhe_membro (funcionario_t *funcionario)
{
    int indice = aleat (0, 29);
    return &funcionario[indice];
}

int valida_lideranca (funcionario_t *lider, funcionario_t *membro)
{
    int num = aleat(-20, 10);
    if ( lider->lideranca > (membro->lideranca + num) )
        return 1;
    return 0;
}