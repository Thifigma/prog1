#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"

void menu ()
{
    printf ("1. Inserir\n");
    printf ("2. Remover\n");
    printf ("3. Destruir\n");
}

/*Retorna 1 se OK e 0 caso contrario. */
int testa_lista_cria (lista_t *l)
{
    if (! (l)){
        printf ("falha na alocacao da lista \n");
        return 0;
    }

    if (lista_vazia(&l))
        return 1;

    printf ("Erro! Lista nao vazia \n");
    return 0;
}

int main() {
    lista_t *l;
    elemento_t *elemento;
    int op;


    printf ("Teste 1. Criar lista e ver se esta vazia \n");
    printf ("Tem que dar lista criada com sucesso e vazia \n");
    l = lista_cria();
    if (testa_lista_cria(l))
        printf ("Lista criada com sucesso e vazia. Ok! \n");

    menu ();
    scanf ("%d", &op);

    swtich (op){
        case (1): 
                printf ("Teste 2. Inserir elemento ordenado \n");
                printf ("Tem que dar ok, inserido!\n");
                    if (!(elemento = malloc (sizeof(elemento_t))))
                        printf ("Erro ao alocar memoria para elemento! \n");
                
                printf ("Ler chave do elemento \n");
                scanf ("%d", &elemento->chave);
                
                if (lista_insere_ordenado(l, elemento))
                    printf ("Ok! Elemento inserido com sucesso! \n");
                else
                    printf ("Erro! Elemento nao inserido! \n");
        break;

        case (2):

        break;

        case (3):

        break;
    }

    return 0;
}