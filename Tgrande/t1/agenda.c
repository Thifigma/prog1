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
    return tempo_trabalado * 60;
}


int main () 
{
    funcionario_t funcionario[30];
    tarefa_t tarefa[100];


    int mes;
    int dia;
    int id; /*Indice da tarefa a ser discutida*/
    char *descricao;
    horario_compromisso_t hc;

    int qt_reunioes_realizadas = 0;
    int qt_tarefas_realizadas = 0;


    funcionario_t *lider;
    funcionario_t *membro;
    compromisso_t *reuniao;

    for (int i =0; i < 30; i++){   
        inicia_funcionario(&funcionario[i]);
    }

    for (int i = 0; i < 100; i++){
        inicia_tarefa(&tarefa[i]);
    }



    for(mes = 1; mes <= 12; mes++){
        printf ("M %d\n", mes);
        for(int i = 0; i < 100; i++){
            lider = escolhe_lider (&funcionario[0]);
            reuniao = cria_nova_reuniao(&hc, &dia, &id, &descricao);

                sprintf(descricao, "REUNIR L %.2d %.2d/%.2d %.2d:%.2d %.2d:%.2d T %.2d",
                        lider->matricula, dia, mes, hc.ini_h, hc.ini_m, hc.fim_h, hc.fim_m, id);
                printf("%s    ", descricao);

            if (marca_compromisso_agenda(lider->ag, dia, reuniao) > 0){
                int MAX_MEMBRO = aleat(2,6);
                int IND_MEMBRO = 0;
                
                for (int i = 0; i < MAX_MEMBRO; i++){
                    membro = escolhe_membro(&funcionario[0]);

                    if (valida_lideranca(lider, membro)){
                       if (marca_compromisso_agenda(membro->ag, dia, reuniao) > 0){
                            printf ("\tMEMBRO%.2d: OK ", membro->matricula);
                       } else {
                            printf ("\tMEMBRO%.2d: IN ", membro->matricula);
                            IND_MEMBRO++;
                       }
                    }

                    if (MAX_MEMBRO == IND_MEMBRO){
                        desmarca_compromisso_agenda(lider->ag, dia, reuniao);
                        printf ("VAZIA\n");
                    }

                }
            } else printf ("\tLIDER INDISPONIVEL \n");
            printf("\n");
        }
    }


    /*Realizar reunioes*/
    for (mes = 1; mes <= 12; mes++){
        for(dia = 1; dia <= 31; dia ++){
            for(int x = 1; x <= 29; x++){
                
                if ((reuniao = compr_agenda(funcionario[x].ag, dia))){
                    while (reuniao){
                    
                        if (tarefa[id_compr(reuniao)].tempo_conclusao > 0)
                            tarefa[id_compr(reuniao)].tempo_conclusao -=  min_trab(reuniao) * 
                                (funcionario[x].exp / 100.0) * ((100 - tarefa[id_compr(reuniao)].dificuldade) / 100);

                        if (tarefa[id_compr(reuniao)].tempo_conclusao <= 0 ){
                            tarefa[id_compr(reuniao)].tempo_conclusao = 0;
                            qt_tarefas_realizadas++;
                        }

                        printf ("\tT %.2d D %.2d TCR %.2d\n", id_compr(reuniao), tarefa[id_compr(reuniao)].dificuldade, 
                                        tarefa[id_compr(reuniao)].tempo_conclusao);
                                                        
                        printf ("%.2d/%.2d F %.2d: %s \n",dia, mes, x, descricao_compr(reuniao));

                        
                        reuniao = prox_compr(reuniao);
                    }

                }
            }
        }
    }

    printf("REUNIOES REALIZADAS %d\n", qt_reunioes_realizadas);
    printf("TAREFAS CONCLUIDAS %d\n", qt_tarefas_realizadas);

    return 0;
}