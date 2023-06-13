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
    ag->ptr_mes_atual = 6;

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
    compr->inicio = (hc.ini_h + hc.ini_m);
    compr->fim = (hc.fim_h + hc.fim_m);

    return compr;
}