#include <stddef.h>
#include <stdlib.h>
#include "libConfeitaria.h"

struct frigobar  criaFrigobar ()
{
	struct frigobar fb;

	for (int i = 0; i < 20; i++)
		fb.Pcima[i] = NULL;

	for (int i = 0; i < 10; i++)
		fb.Pbaixo[i] = NULL;

	return fb;
}
