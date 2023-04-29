#include "libConfeitaria.h"

int main ()
{
	struct frigobar fb;

	fb = criaFrigobar ();

	pedido (&fb);

	return 0;
}


