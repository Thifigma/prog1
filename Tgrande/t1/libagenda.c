#include <stdlib.h>
#include "libagenda.h"

agenda_t* cria_agenda()
{
    agenda_t *ag;

    if (!(ag = malloc (sizeof(agenda_t)))){
        printf ("Erro de alocacao! \n");
        return NULL;
    }

    ag->mes_atual = 1;
    ag->ptr_mes_atual = NULL;

    return ag;
}

compromisso_t* cria_compromisso (horario_compromisso_t hc, int id,  char* descricao)
{
    compromisso_t *compr;

    if (!(compr = malloc (sizeof(compromisso_t)))){
        printf ("Erro de alocacao! \n");
        return NULL;
    }

    compr->descricao = descricao;
    compr->id = id;
    compr->inicio = (hc.ini_h*60 + hc.ini_m);
    compr->fim = (hc.fim_h*60 + hc.fim_m);
    compr->prox = NULL;

    return compr;
}


int mes_atual_agenda(agenda_t *agenda)
{
    return agenda->mes_atual;
}

void prim_mes_agenda(agenda_t* agenda)
{
    agenda->mes_atual = 1;
    agenda->ptr_mes_atual = agenda->mes_atual;
}

int prox_mes_agenda(agenda_t* agenda)
{
    if ( !(agenda->mes_atual = agenda->ptr_mes_atual->prox->mes)){   
        prim_mes_agenda(agenda);
        agenda->ptr_mes_atual->prox->mes++;
        return agenda->mes_atual;
    }   
    
    return 0;
}

int ant_mes_agenda(agenda_t* agenda)
{
    if ( !(agenda->mes_atual = agenda->ptr_mes_atual->ant->mes)){
        prim_mes_agenda(agenda);
        agenda->ptr_mes_atual->ant->mes--;
        return agenda->mes_atual;
    }

    return 0;
}

horario_compromisso_t hc_compr(compromisso_t* compr) {
    horario_compromisso_t hc;

    hc.ini_h = compr->inicio / 60;
    hc.ini_m = compr->inicio % 60;
    hc.fim_h = compr->fim / 60;
    hc.fim_m = compr->fim % 60;

    return hc;
}

char* descricao_compr(compromisso_t* compr)
{
    return compr->descricao;
}

int id_compr(compromisso_t* compr)
{
    return compr->id;
}