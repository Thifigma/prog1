

/*Lista ligada de meses, que vai de 1 a 12.*/
typedef struct meses {
    int num_mes;
    struct meses *prox;
} meses_t;

/*Lista ligada de funcionarios
  *Sao identificados pela sua matricula de 1 a 30
 */
typedef struct funcionario {
    int lideranca;
    int exp;
    int matricula;
    agenda_t *ag;
    struct funcionario *prox;
} funcionario_t;

/*Lista ligada de tarefas que vai de 0 a 99, 
 * Toda tarefa eh identificada pelo seu id
*/
typedef struct tarefa {
    int tempo_conclusao;
    int dificuldade;
    int id;
    struct tarefa *prox;
} tarefa_t;


/*Retorna um inteiro aleatorio entre min e max*/
int aleat (int min, int max);

/*Retorna um inteiro aleatorio entre min e max multiplo de 15*/
int aleat_mult15 (int min, int max);

void destroi_funcionarios(funcionario_t *funcionario);

void destroi_tarefas(tarefa_t *tarefa);

void destroi_mes(meses_t *mes);

/*Retorna um ponteiro com todos os 30 funcionarios 
  * iniciados, inclusive a agenda.
 */
funcionario_t *inicia_funcionarios();

/*Retorna um ponteiro  com as tarefas devidamente iniciadas
  *  tempo_conclusao = ALEAT(600,800)
  *  dificuldade = ALEAT(30,80)
  * id de 0 a 100
*/
tarefa_t *inicia_tarefas();

/*Retorna um ponteiro de uma estrutura mes iniciada*/
meses_t *inicia_mes();

/*Retorna 1 se lideranca entre 30 e 70 e 0 caso contrario. */
int verifica_lideranca (funcionario_t lider);

/*Vai selecionar um lider aleatorio (que corresponda com os criterios de liderança) 
* entre os funcionarios*/
funcionario_t *escolhe_lider(funcionario_t *funcionario);

/*Seleciona um membro aleatorio entre os funcionarios para participar da reuniao.  */
funcionario_t *escolhe_membro(funcionario_t *funcionario);

/*Inicia hc com 
 *ini_h aleat(8,12)
 *ini_m aleat(0, 45) * 15
 *fim_h ini_h + aleat(1, 4);
 *fim_m = ini_m;
*/
void inicia_hc(horario_compromisso_t *hc);

/*Retorna um inteiro aleatorio entre 1 e 31*/
int inicia_dia();

/*Retorna um numero aleatorio entre 0 e TAREFAS - 1. */
int inicia_id();

/*Inicia a descricao com os dados fornecidos serve para saida do programa
 * exemplo: REUNIR L 29 11/01 08:00 09:00 T 42	MEMBROS: 23:OK 18:OK 24:OK 29:IN 13:OK
 * REUNIR L %.2d %.2d/%.2d %.2d:%.2d %.2d:%.2d T %.2d
*/
void inicia_descricao(funcionario_t *lider, int dia, meses_t *mes_atual, horario_compromisso_t hc, tarefa_t *tarefa, char **descricao);

/*Cria um compromisso Reuniao
* Se utiliza de funcoes auxiliares para iniciar ( id, hc e descricao)
* retorna um ponteiro de compromisso na reuniao
*/
void cria_reuniao (compromisso_t **reuniao, horario_compromisso_t hc, int id, char *descricao);

/*Se lider for maior retorna 1 e 0 caso contrario. */
int compara_lider_membro (funcionario_t *lider, funcionario_t *membro);