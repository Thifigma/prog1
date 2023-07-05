#include <stdlib.h>
#include <stdio.h>
#include "libagenda.h"
#include "firma.h"

int aleat (int min, int max)
{
    int num = rand() %max;
    if (num < min)
        num = min;
    return  num;
}

/*Diminuir o custo com um desvio no laço. colocar MAX_ALEAT*/
int aleat_mult15 (int min, int max)
{
    int num = rand() %max;

    while (num % 15 != 0)
        num = rand() %max;
    return num;
}

funcionario_t *inicia_funcionarios()
{
    funcionario_t *funcionario = NULL;
    funcionario_t *aux = NULL;
    funcionario_t *funcionario_inicial = NULL;

    for (int i = 0; i < 30; i++){
        funcionario_t *novo_funcionario;

        if (!(novo_funcionario = malloc (sizeof(funcionario_t))))
            return NULL;

        novo_funcionario->matricula = i + 1;
        novo_funcionario->exp = aleat(20, 100);
        novo_funcionario->lideranca = aleat (0, 100);
        novo_funcionario->ag = cria_agenda();
        novo_funcionario->prox = NULL;

        if (!(funcionario)){
            funcionario = novo_funcionario;
            aux = novo_funcionario;
            funcionario_inicial = funcionario;
        }

        aux->prox = novo_funcionario;
        aux = novo_funcionario;
    }

    return funcionario_inicial;
}

tarefa_t *inicia_tarefas()
{
    tarefa_t *tarefa = NULL;
    tarefa_t *aux = NULL;
    tarefa_t *tarefa_inicial = NULL;

    for (int i = 0; i < 100; i++){
           tarefa_t *nova_tarefa;

           if (!(nova_tarefa = malloc(sizeof(tarefa_t))))
                return NULL;

            nova_tarefa->id = i + 1;
            nova_tarefa->dificuldade = aleat(30, 80);
            nova_tarefa->tempo_conclusao = aleat(600, 800);
            nova_tarefa->prox = NULL;

            if (!(tarefa)){
                tarefa = nova_tarefa;
                aux = nova_tarefa;
                tarefa_inicial = tarefa;
            }

            aux->prox = nova_tarefa;
            aux = nova_tarefa;
    }

    return tarefa_inicial;
}

meses_t *inicia_mes() {
    meses_t *mes = NULL;
    meses_t *aux = NULL;
    meses_t *mes_inicial = NULL;

    for (int i = 0; i < 12; i++) {
        meses_t *novo_mes;

        if (!(novo_mes = malloc(sizeof(meses_t))))
            return NULL;

        novo_mes->num_mes = i + 1;
        novo_mes->prox = NULL;

        if (!(mes)) {
            mes = novo_mes;
            aux = novo_mes;
            mes_inicial = mes;
        } 
        
        aux->prox = novo_mes;
        aux = novo_mes;
    }

    return mes_inicial;
}
int verifica_membro (funcionario_t candidato){
    if (candidato.lideranca > 0)
        return 1;
    return 0;
}
int verifica_lideranca(funcionario_t candidato)
{
    if (candidato.lideranca >= 30 && candidato.lideranca <= 70)
        return 1;
    return 0;
}

funcionario_t *escolhe_lider(funcionario_t *funcionario)
{
    static funcionario_t *ultimo_lider = NULL;

    if (!funcionario) {
        printf("Erro! Lista de funcionários vazia.\n");
        return NULL;
    }

    funcionario_t *lider = (ultimo_lider && ultimo_lider->prox) ? ultimo_lider->prox : funcionario;

    while (!verifica_lideranca(*lider)) {
        lider = lider->prox;
        if (!lider) {
            // Caso não haja mais funcionários na lista, reinicia a busca a partir do início
            lider = funcionario;
        }

        // Se voltar ao início sem encontrar um líder válido, nenhum líder é encontrado
        if (lider == ultimo_lider) {
            printf("Nenhum líder válido encontrado.\n");
            return NULL;
        }
    }

    ultimo_lider = lider;
    return lider;
}

funcionario_t *escolhe_membro(funcionario_t *funcionario)
{
    static funcionario_t *ultimo_membro = NULL;

    if (!funcionario) {
        printf("Erro! Lista de funcionários vazia.\n");
        return NULL;
    }

    funcionario_t *membro = (ultimo_membro && ultimo_membro->prox) ? ultimo_membro->prox : funcionario;

    while (!verifica_membro(*membro)) {
        membro = membro->prox;
        if (!membro) {
            // Caso não haja mais funcionários na lista, reinicia a busca a partir do início
            membro = funcionario;
        }

        // Se voltar ao início sem encontrar um líder válido, nenhum líder é encontrado
        if (membro == ultimo_membro) {
            printf("Nenhum líder válido encontrado.\n");
            return NULL;
        }
    }

    ultimo_membro = membro;
    return membro;
}


void inicia_hc(horario_compromisso_t *hc)
{
    hc->ini_h = aleat(8, 12);
    hc->ini_m = aleat_mult15 (0, 45);
    hc->fim_h = hc->ini_h + aleat(1, 4);
    hc->fim_m = hc->ini_m;
}

int inicia_dia()
{
    int max = 31;
    return rand() %max;
}

/*Ver essa questao da tarefa - 1*/
int inicia_id()
{
    int max = 99;
    return rand() %max;
}

/*Verificar descricao depois, arrumar ou fazer melhor*/
/*
void inicia_descricao(funcionario_t *lider, int dia, meses_t *mes_atual, horario_compromisso_t hc, tarefa_t *tarefa, char **descricao)
{
    sprintf((*descricao), "M %d\nREUNIR L %.2d %.2d/%.2d %.2d:%.2d %.2d:%.2d T %.2d",
            mes_atual->num_mes, lider->matricula, dia, mes_atual->num_mes, hc.ini_h, hc.ini_m, hc.fim_h, hc.fim_m, tarefa->id);
} */


void cria_reuniao (compromisso_t **reuniao, horario_compromisso_t hc, int id, char *descricao)
{
    (*reuniao) = cria_compromisso (hc, id, descricao);
}

int compara_lider_membro (funcionario_t *lider, funcionario_t *membro)
{
    if (lider->lideranca > membro->lideranca + aleat(-20, 10))
        return 1;
    return 0;
}

void destroi_funcionarios(funcionario_t *funcionario)
{
    funcionario_t *atual = funcionario;
    funcionario_t *prox;

    while (atual) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

void destroi_tarefas(tarefa_t *tarefa)
{
    tarefa_t *atual = tarefa;
    tarefa_t *prox;

    while (atual) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

void destroi_mes(meses_t *mes)
{
    meses_t *atual = mes;
    while (atual){
        meses_t *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}