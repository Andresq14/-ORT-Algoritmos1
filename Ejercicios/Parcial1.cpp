#include "Parcial1.h"

#ifndef PARCIAL1_CPP
#define PARCIAL1_CPP

#pragma region Aux

void eliminarPosAux(NodoLista*& L, int desde, int hasta, int pos)
{
	if (L == NULL || pos > hasta) return;
	if (pos < desde) eliminarPosAux(L->sig, desde, hasta, pos + 1);
	else
	{
		NodoLista* borrar = L;
		L = L->sig;
		delete borrar;
		eliminarPosAux(L, desde, hasta, pos + 1);
	}
}

int maximo(int a, int b)
{
	return a > b ? a : b;
}

int nivel(NodoAG* a, int x, int n)
{
	if (a == NULL) return 0;
	if (a->dato == x) return n + maximo(nivel(a->ph, x, n + 1), nivel(a->sh, x, n)); //Error: return 1 + ... Correccion: return n + ...
	else
	{
		int aux = maximo(nivel(a->ph, x, n + 1), nivel(a->sh, x, n));
		if (aux == 0) return 0;
		else return aux; //Error: return n. Correccion: return aux
	}
}

#pragma endregion

NodoLista* posicion(NodoLista* L, int x)
{
	NodoLista* element = NULL;
	bool found = false;

	while (L != NULL && !found)
	{
		if (L->dato != x) L = L->sig;
		else 
		{
			element = L;
			found = true;
		}
	}

	return element;
}

void eliminarPosiciones(NodoLista*& L, int desde, int hasta)
{
	eliminarPosAux(L, desde, hasta, 1);
}

int nivelDeElemento(NodoAG* A, int x)
{
	return nivel(A, x, 1);
}

int piso(NodoAB* a, int x)
{
	if (a == NULL) return INT_MIN;
	if (a->dato == x) return x;
	if (x > a->dato)
	{
		if (a->der == NULL || a->der->dato > x) return a->dato; //Error: return a->der->dato. Correcto: a->dato;
		else return piso(a->der, x);
	}
	else
	{
		if (a->izq != NULL && a->izq->dato < x) return a->izq->dato;
		else return piso(a->izq, x);
	}
}

#endif