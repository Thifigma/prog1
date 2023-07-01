#include <stdio.h>
#include <stdlib.h>
#include "libagenda.h"

agenda_t* cria_agenda()
{
    agenda_t *ag;

    if (!(ag = malloc (sizeof(agenda_t))))
        return NULL;

    if (!(ag->ptr_mes_atual = malloc(sizeof(mes_t)))){
        free(ag);
        return NULL;
    }
    ag->mes_atual = 1;

    return ag;
}

/*Funcao axiliar que retorna 0 se agenda estiver vazia*/
int agenda_vazia (agenda_t *agenda)
{
    if (!(agenda->ptr_mes_atual))
        return 0;
    return 1;
}

void destroi_compromisso(compromisso_t* compr)
{

    if (!(compr))
        return;
    
    free(compr->descricao);
    free(compr);
}

compromisso_t* prox_compr(compromisso_t* compr)
{
    if (!(compr->prox))
        return NULL;
    return compr->prox;
}

compromisso_t* compr_agenda(agenda_t* agenda, int dia)
{
    compromisso_t *ptr_compr;
    dia_t *dia_atual;

    if (agenda_vazia(agenda))
        return NULL;
    
    dia_atual = agenda->ptr_mes_atual->dias;
    while (dia_atual && dia_atual->dia != dia)
        dia_atual = dia_atual->prox;

    if (dia_atual){
        ptr_compr = dia_atual->comprs;
        return ptr_compr;
    }

    return NULL;
}

/*Retorna 1 caso tenha interseccao entre os compromissos*/
int intersecta (compromisso_t *compr_atual, compromisso_t *compr_anterior, compromisso_t *compr)
{
    if ((compr_anterior && compr_anterior->fim >= compr->inicio) ||
        (compr_atual && compr->fim >= compr_atual->inicio))
        return 1;
    return 0;
}

/*vou forcar o usuario a passar a descricao com \0 no final*/
compromisso_t* cria_compromisso (horario_compromisso_t hc, int id,  char* descricao)
{
    compromisso_t *compr;

    if (!(compr = malloc (sizeof(compromisso_t))))
        return NULL;

    /*Resolver o problema de seguranca depois*/
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
    agenda->ptr_mes_atual = NULL;
}

int prox_mes_agenda(agenda_t* agenda)
{
    
    if (!(agenda->ptr_mes_atual->prox)){
        mes_t *novo_mes;

        if (!(novo_mes = malloc(sizeof(mes_t))))
            return 0;

        agenda->ptr_mes_atual->prox = novo_mes;
        agenda->mes_atual++;

        return agenda->mes_atual;
    }

    agenda->ptr_mes_atual = agenda->ptr_mes_atual->prox;
    agenda->mes_atual++;

    return agenda->mes_atual;
}

int ant_mes_agenda(agenda_t* agenda)
{
    if (!(agenda->ptr_mes_atual->ant)){
        mes_t *novo_mes;

        if (!(novo_mes = malloc (sizeof(mes_t))))
            return 0;
        
        agenda->ptr_mes_atual->ant = novo_mes;
        agenda->mes_atual--;

        return agenda->mes_atual;
    }

    agenda->ptr_mes_atual = agenda->ptr_mes_atual->ant;
    agenda->mes_atual--;

    return agenda->mes_atual;
}

horario_compromisso_t hc_compr(compromisso_t* compr) 
{
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

int marca_compromisso_agenda(agenda_t* agenda, int dia, compromisso_t* compr)
{
    dia_t *novo_dia;
    dia_t *dia_anterior;
    dia_t *dia_atual;

    /*Procurando o dia correto*/
    dia_atual = agenda->ptr_mes_atual->dias;
    dia_anterior = NULL;
    while (dia_atual && dia_atual->dia < dia) {
        dia_anterior = dia_atual;
        dia_atual = dia_atual->prox;
    }

    if (dia_atual && dia_atual->dia == dia){

        compromisso_t *compr_atual = dia_atual->comprs;
        compromisso_t *compr_anterior = NULL;
        while (compr_atual && compr_atual->inicio < compr->inicio){ 
            compr_anterior = compr_atual;
            compr_atual = compr_atual->prox;
        }

        /*Verifica a interseccao dos compromissos*/
        if ( intersecta (compr_atual, compr_anterior, compr) ) 
            return -1;

        /*Insere o compromisso entre o anterior e o proximo*/
        if (compr_anterior)
            compr_anterior->prox = compr;
        
        /*Insere o compromisso no inicio*/
        dia_atual->comprs = compr;
        compr->prox = compr_atual;

        return 1;
    }

    /*Caso  o dia não exista*/
    if (!(novo_dia = malloc(sizeof(dia_t))))
        return 0;
    
    novo_dia->dia = dia;
    novo_dia->comprs = compr;
    novo_dia->prox = dia_atual;

    if (dia_anterior)
        dia_anterior->prox = novo_dia;
    
    agenda->ptr_mes_atual->dias = novo_dia;
    
    return 1;
}

int desmarca_compromisso_agenda(agenda_t* agenda, int dia, compromisso_t* compr)
{
    dia_t *dia_atual = agenda->ptr_mes_atual->dias;

    while (dia_atual && dia_atual->dia < dia)
        dia_atual = dia_atual->prox;

    if (dia_atual && dia_atual->dia == dia){    
        
        compromisso_t *compr_atual = dia_atual->comprs;
        compromisso_t *compr_anterior = NULL;
        while (compr_atual && compr_atual->inicio < compr->inicio){
            compr_anterior = compr_atual;
            compr_atual = prox_compr(compr_atual);
        }

        if (compr_atual == compr){

            if (compr_anterior)
                compr_anterior->prox = prox_compr(compr_atual);
            
            dia_atual->comprs = compr->prox;
            free(compr_atual);

            return 1;
        }
    }

    return 0;
}

void destroi_agenda(agenda_t* agenda)
{
    mes_t *mes_atual;
    dia_t *dia_atual;
    compromisso_t *compr_atual;
    
    
    if (agenda_vazia(agenda)){
        return;
    }

    mes_atual = agenda->ptr_mes_atual;
    while (mes_atual){
    
        dia_atual = mes_atual->dias;
        while (dia_atual){

            compromisso_t *prox_compr;

            compr_atual = dia_atual->comprs;
            while (compr_atual){

                prox_compr = compr_atual->prox;
                destroi_compromisso(compr_atual);
                compr_atual = prox_compr;
            }

            dia_t *prox_dia = dia_atual->prox;
            free (dia_atual);
            dia_atual = prox_dia;

        }

        mes_t *prox_mes = mes_atual->prox;
        free (mes_atual);
        mes_atual = prox_mes;
    }

    free (agenda);
    agenda = NULL;
}