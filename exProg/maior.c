#include <stdio.h>


int maior (int *a, int *b)
{
	if ( *a > *b)
	       return *a;
	return *b;
}

int main ()
{
	int a = 0;
	int b = 0;

	scanf ("%d", &a);
	scanf ("%d", &b);

	printf ("Maior: %d\n", maior (&a, &b) );

	return 0;	
}
