#define <stdio.h>
#define <stdlib.h>


struct aluno {
	int ano;
	int nota;
}

void aloca_vetor (struct aluno *v, int n)
{

}

int main ()
{
	/*Vetor que aponta para a estrutura*/
	struct aluno *v;
	int n = 0;

	/*Tamanho a ser alocado. */
	scanf ("%d", &n);

	/*Retorna um endereco de memoria na heap com 
	 *o espaco solicitado*/ 
	aloca_vetor (v, n);
	
	/*Como inicializar o vetor com null? */
	/*Como atribuir os valores dentro do vetor? */
	/*Como colocar os ponteiros dentro do vetor? */


	return 0; 
}

