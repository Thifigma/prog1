#include <stdio.h>

int soma (int *a, int *b)
{
	return (*a + *b);
}


int main ()
{
	int a = 10;
	int b = 10;

	printf ("Soma:  %d\n", soma (&a, &b) );

	return 0;
}

