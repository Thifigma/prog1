#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"

void menu ()
{
    printf ("-------------------------\n");
    printf ("1. Inserir\n");
    printf ("2. Remover\n");
    printf ("3. Destruir\n");
    printf ("-------------------------\n");
}


int main() {
    lista_t *l;
    elemento_t *elemento;
    int op;

    menu ();
    scanf ("%d", &op);

    switch (op){
        case 1:

        break;

        case 2:

        break;

        case 3:

        break;
    }
    return 0;
}