#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"

void menu ()
{
    printf ("-------------------------\n");
    printf ("1. Inserir\n");
    printf ("2. Remover\n");
    printf ("3. Destruir\n");
    printf ("4. Mostrar\n");
    printf ("0. Sair\n");
    printf ("-------------------------\n");
}

/*Retorna 1 se lista estiver sido criada corretamente e estiver vazia
 *retorna 0 caso contrario. */
int testa_lista_cria (lista_t *l)
{
    if (!(l->ini)){
        if (lista_vazia(&l))
            return 1;
        else
            return 0;
    }

    return 0;
}

int main() {
    lista_t *l;
    elemento_t *elemento = malloc (sizeof(elemento_t));
    if (!(elemento)){
      printf ("Erro ao alocar memoria ao elemento. \n");
      return 0;
    }    
    
    int op;

    printf ("Testando lista_cria! \n");
    l = lista_cria();
    if (testa_lista_cria(l))
        printf ("Lista criada com sucesso! \n");
    else{
        printf ("Erro ao criar fila! \n");
        return 0;
    }


    menu ();
    scanf ("%d", &op);

    while (op){
        switch (op){
            case 1:
                
                printf ("Leia a chave do elemento: ");
                scanf ("%d", &elemento->chave);

                if (lista_insere_ordenado(l, elemento))
                    printf ("Elemento inserido com sucesso! \n");
                else
                    printf ("Erro ao Inserir elemento... \n");    
            
            
            break;

            case 2:

                printf ("Leia a chave do elemento a ser  removido: ");
                scanf ("%d", &elemento->chave);

                if (lista_remove_ordenado(l, elemento))
                    printf ("Elemento removido com sucesso! \n");
            break;

            case 3:
                if (lista_destroi (&l))
                    printf ("Lista destruida com sucesso! \n");
                else
                    printf ("Lista vazia, nao ha o que destruir... \n");
            break;
        
            case 4:
                //mostrar_lista (l);
            break;

            case 0:
                printf ("Saindo... \n");
            break;
        }
            menu ();
            scanf ("%d", &op);
    }
    return 0;
}