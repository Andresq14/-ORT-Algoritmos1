#include "EjerciciosSem5.h"

#ifndef EJERCICIOSSEM5_CPP
#define EJERCICIOSSEM5_CPP

#pragma region Aux

/*
	PRE: -
	POS: Inserta un nuevo nodo a la lista en forma ordenada ascendentemente.
*/
void insertionSort(NodoLista*& list, int dato)
{
	NodoLista* nodo = new NodoLista(dato);

	if (!list)
	{
		list = nodo;
	}
	else
	{
		if (dato <= list->dato)
		{
			nodo->sig = list;
			list = nodo;
		}
		else
		{
			insertionSort(list->sig, dato);
		}
	}
}

void insertarPpio(NodoLista*& nodo, int dato)
{
	NodoLista* aux = new NodoLista;
	aux->dato = dato;
	aux->sig = nodo;
	nodo = aux;
}

void intercambiarValores(NodoLista*& nodo, NodoLista*& list)
{
	int aux = list->dato;
	list->dato = nodo->dato;
	nodo->dato = aux;
}

NodoLista* menorLista(NodoLista *& list)
{
	NodoLista* men = list;
	NodoLista* aux = list;
	
	while (aux != NULL)
	{
		if (aux->dato < men->dato)
			men = aux;
	
		aux = aux->sig;
	}
	return men;
}

void insertarFinal(NodoLista*& prim, NodoLista*& ult, int dato)
{
	if (!prim)
	{
		prim = new NodoLista;
		prim->dato = dato;
		prim->sig = NULL;
		ult = prim;
	}
	else
	{
		NodoLista* nodo = new NodoLista;
		nodo->dato = dato;
		nodo->sig = NULL;
		ult->sig = nodo;
		ult = nodo;
	}
}

#pragma endregion


void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	if (!lista) return;
	
	eliminarNesimoDesdeElFinal(lista->sig, n);
	n--;

	if (n == 0)
	{
		NodoLista* borrar = lista;
		lista = borrar->sig;
		delete borrar;
	}
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	if (!l) return NULL;

	NodoLista* ret = NULL;

	while (l != NULL)
	{
		insertionSort(ret, l->dato);
		l = l->sig;
	}

	return ret;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	if (!l) return;

	NodoLista* menor = menorLista(l);
	intercambiarValores(menor, l);
	listaOrdenadaSelectionSort(l->sig);
}

NodoLista* invertirParcial(NodoLista* l) 
{
	NodoLista* ret = NULL;

	while (l->sig != NULL)
	{
		NodoLista* nodo = new NodoLista;
		nodo->dato = l->dato;
		nodo->sig = ret;
		ret = nodo;

		l = l->sig;
	}

	return ret;
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	NodoLista* prim = NULL;
	NodoLista* ult = NULL;
	
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->dato <= l2->dato)
		{
			insertarFinal(prim, ult, l1->dato);
			l1 = l1->sig;
		}
		else
		{
			insertarFinal(prim, ult, l2->dato);
			l2 = l2->sig;
		}
	}

	while (l1 != NULL) 
	{
		insertarFinal(prim, ult, l1->dato); 
		l1 = l1->sig;
	}
	while (l2 != NULL)
	{
		insertarFinal(prim, ult, l2->dato);
		l2 = l2->sig;
	}

	return prim;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	if (l1 == NULL && l2 == NULL) return NULL;

	NodoLista* nodo = new NodoLista;

	if (l1 != NULL && (l2 == NULL || l1->dato <= l2->dato))
	{
		nodo->dato = l1->dato;
		nodo->sig = intercalarRec(l1->sig, l2);
	}
	else
	{
		nodo->dato = l2->dato;
		nodo->sig = intercalarRec(l1, l2->sig);
	}

	return nodo;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	NodoLista* ret = NULL;

	insertarPpio(ret, x);

	while (l != NULL)
	{
		insertarPpio(ret, l->dato);
		l = l->sig;
	}

	insertarPpio(ret, x);

	return ret;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}


#endif