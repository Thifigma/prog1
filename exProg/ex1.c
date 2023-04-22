#include <stdio.h>

int main ()
{
	int m = 10;
	int n = 0;
	int o = 0;
	int *z = NULL;

	printf ("Endereco de M: %p\n", &m);
	z = &m;
	printf ("O valor de Z: %d\n", *z);
       	printf ("Endereco de M: %p\n", &n);
	o = m;
	printf ("Endereco de z: %p\n", &z);

	
	*n = &o;


	return 0;
}
