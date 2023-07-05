#include <stdio.h>
#include <stdlib.h>
#include "libagenda.h"
#include "firma.h"

/*Aqui vai ser implementado o teste - 'firma' */




int min_trab (compromisso_t *reuniao)
{
    int tempo_trabalado = (reuniao->fim - reuniao->inicio);
    if (tempo_trabalado < 0)
        tempo_trabalado = 0;
    return tempo_trabalado;
}

int main () 
{
    meses_t *mes = inicia_mes();
    funcionario_t *funcionarios = inicia_funcionarios();
    tarefa_t *tarefas = inicia_tarefas();
    tarefa_t *tarefa_inical = tarefas;
    meses_t *mes_inicial = mes;
    funcionario_t *funcionario_inicial = funcionarios;

    /*Verifica se alguma alocacao deu falha*/
    if (!(tarefas || funcionarios || mes)){
        printf ("Erro de alocacao! \n");
        return 1;
    }

    compromisso_t *reuniao;
    funcionario_t *lider;
    funcionario_t *membro;

    int dia;
    horario_compromisso_t hc;
    char *descricao = "Descricao\0";
    int id;


    /*Percore os 12 meses da lista ligada de meses*/
    while (mes) {
       
       printf ("M: %d\n", mes->num_mes);
       while(tarefas){

            inicia_hc(&hc);
            dia = inicia_dia();
            id = inicia_id();
            lider = escolhe_lider(funcionarios);

            cria_reuniao(&reuniao, hc, id, descricao);
            
            if (marca_compromisso_agenda(lider->ag, dia, reuniao) > 0){
                
                printf ("REUNIR L %.2d %.2d/%.2d %.2d:%.2d %.2d:%.2d T %.2d ", 
                lider->matricula, dia, mes->num_mes, hc.ini_h, hc.ini_m, hc.fim_h, hc.fim_m, tarefas->id);

                int MEMBRO_MAX = aleat(2, 6);
                int MEMBRO_IN = 0;
  
                for (int i = 0; i < MEMBRO_MAX; i++){
                    membro = escolhe_membro(funcionarios);
                    
                    if (compara_lider_membro(lider, membro)){
                        if (marca_compromisso_agenda(membro->ag, dia, reuniao)> 0 )
                            printf ("\tMEMBROS %.2d: OK\n", membro->matricula);
                        else{
                            MEMBRO_IN++;
                            printf ("\tMEMBROS %.2d: IN\n", membro->matricula);
                        }
                    }

                    if (MEMBRO_IN == MEMBRO_MAX){
                        desmarca_compromisso_agenda(lider->ag, dia, reuniao);
                        printf("VAZIA\n");
                    }
                }
            
            } else {
                printf ("REUNIR L %.2d %.2d/%.2d %.2d:%.2d %.2d:%.2d T %.2d \n", 
                lider->matricula, dia, mes->num_mes, hc.ini_h, hc.ini_m, hc.fim_h, hc.fim_m, tarefas->id);
                printf ("\tLIDER INDISPONIVEL \n");
            }

            tarefas = tarefas->prox;
            }

            tarefas = tarefa_inical;
            mes = mes->prox;
    }


    mes = mes_inicial;
    while (mes){
        for (dia = 1; dia < 31; dia++){
            funcionarios = funcionario_inicial;
            while (funcionarios){
                tarefas = tarefa_inical;
                while (tarefas){

                    while ((tarefas->tempo_conclusao) > 0){
                        tarefas->tempo_conclusao = (min_trab (reuniao)*funcionarios->exp / 100)*
                        ((100 - tarefas->dificuldade) / 100.0);
                    
                        if (tarefas->tempo_conclusao <= 0)
                            tarefas->tempo_conclusao = 0;
                    
                    }

                    funcionarios->exp = aleat(0, 100);
                tarefas = tarefas->prox;
                }

            funcionarios = funcionarios->prox;
            }
        }          
    mes = mes->prox;
    }


    return 0;
}