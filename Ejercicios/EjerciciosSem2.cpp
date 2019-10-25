#include "EjerciciosSem2.h"

#ifndef EJERCICIOSSEM2_CPP
#define EJERCICIOSSEM2_CPP

#pragma region Auxiliar

/*
PRE: Recibe dos enteros
POST: Retorna el maximo comun divisor de estos
*/
int maximoComunDivisor(int numerador, int denominador) 
{
	if (numerador < denominador && numerador > 0)
	{
		int aux = numerador;
		numerador = denominador;
		denominador = aux;
	}

	while (denominador != 0)
	{
		int res = denominador;
		denominador = numerador % denominador;
		numerador = res;
	}

	return numerador;
}

#pragma endregion


void simplificar(int n, int d) 
{
	int mcd = maximoComunDivisor(n, d);
	
	cout << (n / mcd) << "/" << (d / mcd);
}

int ocurrencias123Repetidos(int* vector, int largo) 
{
	int inicio = 0;
	int cant = 0;

	for (int i = 0; i < largo; i++)
	{
		if (vector[i] == inicio || vector[i] == (inicio + 1))
		{
			inicio = vector[i];

			if (inicio == 3)
			{
				cant++;
				inicio = 0;
			}
		}
		else
		{
			inicio = 0;
		}
	}

	return cant;
}

int maximoNumero(unsigned int n) 
{
	int max = INT_MIN;

	for (int i = 0; i < n; i++) 
	{
		int numb;
		cin >> numb;

		if (numb > max)
			max = numb;
	}

    return max;
}

void ordenarVecInt(int *vec, int largoVec) 
{
	bool ordenado;

	do
	{
		ordenado = true;
		for (int i = 0; i < largoVec; i++)
		{
			if ( (i+1) >= largoVec)
				continue;

			if (vec[i] > vec[i + 1])
			{
				int aux = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = aux;
				ordenado = false;
			}

		}
	} while (!ordenado);

}

#endif