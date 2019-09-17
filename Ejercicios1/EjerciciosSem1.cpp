#include "EjerciciosSem1.h"

#ifndef EJERCICIOSSEM1_CPP
#define EJERCICIOSSEM1_CPP

int suma(int a, int b) 
{
    return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) 
{
	for (unsigned int i = desde; i<=hasta; i++) 
	{
		cout << i << '*' << tablaDel << '=' << i * tablaDel;
		if (i != hasta)
			cout << ';';
	}
}

#endif