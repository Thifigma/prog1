#include <stdio.h>


int main ()
{
	int a = 10;
	int b = 10;
	int soma = 0;
	
	int *ptr_a = &a;
	int *ptr_b = &b;

	soma = *ptr_a + *ptr_b;

	printf ("Soma : %d\n", soma);
		
	return 0;
}
