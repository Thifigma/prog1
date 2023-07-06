/*Notas sobre a firma  ________________

* Tomei varias decisões erradas em relação a que tipo de estutura usar. 
* Inicialmente fiz funcionarios, tarefas e meses como listas ligadas até a implementação da firma.c estáva tudo bem
* Porém quando fui manipular as estuturas na agenda  houve varias complicações, 
*percebendo meu equivoco fiz o presente trabalho
* em pouco menos de 10 horas. Por isso não deu tempo de corrigir as memorias vazadas 
*entre outros erros que possivelmente vai encontrar
* OBS: em firma.c é possivel ver comentado o código que fiz com a abordagem de listas ligadas para as estruturas. 
* Lembrando que as complicações surgiram na agenda e não na firma. 
*/

/*
 *Estrutura para representar o Funcionario
 *Vai ser identificado pela matricula de 1 a 30.
 */
typedef struct funcionario {
    int lideranca;
    int matricula;
    int exp;
    agenda_t *ag;
} funcionario_t;

/*
 *Estutura para representar as tarefas, 
 *Toda tarefa eh identificada pelo seu id
*/
typedef struct tarefa {
    int tempo_conclusao;
    int dificuldade;
} tarefa_t;

/*
 *Retorna um inteiro aleatorio entre min e max
*/
int aleat (int min, int max);

/*
*Retorna um inteiro aleatorio entre min e max multiplo de 15
*/
int aleat_mult15 (int min, int max);
/*
 *Atribui lideranca, exp, cria uma agenda e identifica o funcionario pela matricula.
*/
void inicia_funcionario (funcionario_t *funcionario);

/*
 *Atribui tempo e dificuldade a cada uma das 100 tarefas. 
*/
void inicia_tarefa (tarefa_t *tarefa);

/*
 *Responsavel por gerar hc, dia, id e descricao
*/
compromisso_t *cria_nova_reuniao (horario_compromisso_t *hc, int *dia, int * id, char **desc);
/*
 *Veririca se lideranca está entre 30 e 70.
*/
int verifica_lideranca (funcionario_t *candidato);

/*
 *Escolhe um Lider aleatorio entre os 30 funcionarios 
*/
funcionario_t *escolhe_lider (funcionario_t *funcionario);

/*
 *Escolhe um membro aleatorio entre os 30 funcionarios
*/
funcionario_t *escolhe_membro (funcionario_t *funcionario);

/*
 *Retorna 1 se valido e 0 caso contrario.
 *Avalia se a lideranca do Lider eh maior que a do membro
*/
int valida_lideranca (funcionario_t *lider, funcionario_t *membro);

