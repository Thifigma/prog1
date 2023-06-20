#include <stdio.h>
#include <stdlib.h>
#include "libagenda.h"

/*Aqui vai ser implementado o teste - 'firma' */

typedef struct funcionario {
    int lideranca;
    int exp;
    agenda_t *ag;
}funcionario_t;

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

int main () 
{
    funcionario_t colaborador[30];

    inicia_colaborador(colaborador);


    return 0;
}