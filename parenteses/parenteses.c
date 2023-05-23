#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libpilha.h"

 /*Como o dado da pilha eh int, fiz seus correspondentes em int.
* [ = 1, ] = 2
* ( = 3, ) = 4 
* { = 5, } = 6 
* O correspondente eh o seu valor - 1
* Seria mais facil se o dado da pilha fosse do tipo char. 
* Tal mudança afetaria a .h e por isso o pedaço de código estranho.
 */
int validaCaracter (int tam, const char *string, pilha_t *p)
{
    int dado = 0;
	int i = 0;
	
	/*Meu compilador esta acusando erro na expressao
	*for (int i = 0 .....)*/
    for (i = 0; i < tam; i++){
        switch (string[i]){
            case ( '[' ):
                push((p), 1);
            break;
            
            case ('('):
                push((p), 3);
            break;

            case ('{'):
                push((p), 5);
            break;

            case (']'):
                if (pilha_vazia((p)))
                    return 0;
                else {
                    dado = 2;
                    if (p->topo->dado == dado -1)
                        pop(p, &dado);
                    else
                        return 0;
                }                                    
            break;

            case (')'):
                if (pilha_vazia((p)))
                    return 0;
                else {
                    dado = 4;
                    if (p->topo->dado == dado -1)
                        pop(p, &dado);
                    else
                        return 0;
                }                
            break;

            case ('}'):
                if (pilha_vazia((p)))
                    return 0;
                else {
                    dado = 6;
                    if (p->topo->dado == dado -1)
                        pop(p, &dado);
                    else
                        return 0;
                }
            break;
        }
    }

    if (pilha_vazia(p))
        return 1;
    else    
        return 0;
}

/*Retorna 1 se CORRETA e 0 se INCORRETA*/
int verifica (const char *string)
{
    int tam = strlen (string);
    pilha_t *p = pilha_cria ();

    if ( validaCaracter (tam, string, p) ){
        pilha_destroi (&p);
		return 1;
	} else {
        pilha_destroi (&p);
		return 0;
	}
}

int main ()
{
    char *string = (char*)malloc(sizeof(char));
    if (!string){
        printf ("Erro de alocacao! \n");
        return 0;
    }

    printf ("Leia a expressao aritmetica: ");
    scanf ("%s", string);

    if (verifica(string))
        printf ("CORRETA\n");
    else
		printf ("INCORRETA\n");
    
	free (string);
    return 0;
}