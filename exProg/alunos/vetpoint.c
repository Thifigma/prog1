#define <stdio.h>
#define <stdlib.h>


struct aluno {
	int ano;
	int nota;
};

struct aluno *aloca_vetor (int n)
{
	return malloc (n*sizeof(struct aluno) );
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
	v = aloca_vetor (n);
	
	/*Como inicializar o vetor com null? */
	
	/*Como atribuir os valores (ponteiros P/ estrutura, NULLs) ) 
	 * dentro do vetor? */

	/*Como operar esses ponteiros com essas estruturas?*/
	
	free (v);

	return 0; 
}
