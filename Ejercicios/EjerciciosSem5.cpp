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

/*
	PRE: Recibe un dato diferente a NULL
	POS: Inserta un nuevo nodo al principio de la lista pasada por parametro.
*/
void insertarPpio(NodoLista*& nodo, int dato)
{
	NodoLista* aux = new NodoLista;
	aux->dato = dato;
	aux->sig = nodo;
	nodo = aux;
}

/*
	PRE: Recibe un dato diferente a NULL
	POS: Inserta un nuevo nodo al final de la lista pasada por parametro.
*/
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

/*
	PRE: Recibe un dato y posicion diferente a NULL y la posicion debe ser mayor a 0
	POS: Inserta un nuevo nodo en la posicion de la lista pasada por parametro
*/
void insertarPos(NodoLista*& list, int dato, int pos)
{
	if (list == NULL) return;
	if (pos > 1) insertarPos(list->sig, dato, (pos - 1));
	else
	{
		NodoLista* nodo = new NodoLista;
		nodo->dato = dato;
		nodo->sig = list;
		list = nodo;
	}
}

/*
	PRE: Recibe dos nodos diferentes a null
	POS: Intercambia el dato de estos nodos
*/
void intercambiarValores(NodoLista*& nodo, NodoLista*& list)
{
	int aux = list->dato;
	list->dato = nodo->dato;
	nodo->dato = aux;
}

/*
	PRE: Recibe una lista
	POS: Retorna el nodo que posee el menor valor de la lista
*/
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

/*
	PRE: Recibe una lista
	POS: Retorna el largo de la misma
*/
int listaLength(NodoLista* list)
{
	if (list == NULL) return 0;
	else return 1 + listaLength(list->sig);
}

/*
	PRE: Recibe una lista y una secuencia no NULL
	POS: Retorna si la secuencia se encuentra en las primeras posiciones de la lista
*/
bool verificarSecuencia(NodoLista* list, NodoLista* seq)
{
	if (seq == NULL) return true;
	if (list == NULL) return false;
	if (list->dato != seq->dato) return false;
	else return verificarSecuencia(list->sig, seq->sig);
}

/*
	PRE: Recibe una lista y una posicion
	POS: Retorna si el valor que poseia dicho nodo y lo elimina
*/
int buscarBorrarNodo(NodoLista*& list, unsigned int pos)
{
	if (list == NULL) return NULL;
	if (pos == 1)
	{
		int dato = list->dato;
		NodoLista* borrar = list;
		list = list->sig;
		delete borrar;
		return dato;
	}
	else return buscarBorrarNodo(list->sig, (pos - 1));
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
	NodoLista* ini = NULL;
	NodoLista* ult = NULL;
	int min = INT_MAX;

	while (l1 != NULL && l2 != NULL)
	{
		if(l1->dato < l2->dato )
		{
			if (l1->dato != min)
			{
				min = l1->dato;
				insertarFinal(ini, ult, min);
			}
			l1 = l1->sig;
		}
		else if (l2->dato < l1->dato)
		{
			if (l2->dato != min)
			{
				min = l2->dato;
				insertarFinal(ini, ult, min);
			}
			l2 = l2->sig;
		}
		else
		{
			min = l1->dato;
			l1 = l1->sig;
			l2 = l2->sig;
		}
	}

	while (l1 != NULL)
	{
		if (l1->dato != min)
		{
			min = l1->dato;
			insertarFinal(ini, ult, min);
		}
		l1 = l1->sig;
	}
	while (l2 != NULL)
	{
		if (l2->dato != min)
		{
			min = l2->dato;
			insertarFinal(ini, ult, min);
		}
		l2 = l2->sig;
	}

	return ini;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	if (l == NULL || l->sig == NULL) return;

	if (l->dato == l->sig->dato)
	{
		int dato = l->dato;

		while (l != NULL && l->dato == dato) l = l->sig;

		eliminarDuplicadosListaOrdenadaDos(l);
	}
	else
		eliminarDuplicadosListaOrdenadaDos(l->sig);
}

bool palindromo(NodoLista* l)
{
	if (l == NULL) return true;

	NodoLista* aux = l;
	NodoLista* listaInversa;

	while (l != NULL)
	{
		insertarPpio(listaInversa, l->dato);
		l = l->sig;
	}

	bool palindroma = verificarSecuencia(listaInversa, aux);

	return palindroma;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	if (l == NULL) return;
	if (secuencia == NULL) return;

	if (l->dato == secuencia->dato)
	{
		if (verificarSecuencia(l, secuencia))
		{
			while (secuencia != NULL)
			{
				l = l->sig;
				secuencia = secuencia->sig;
			}
		}
		else
			eliminarSecuencia(l->sig, secuencia);
	}
	else
		eliminarSecuencia(l->sig, secuencia);
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	if (inicial == final) return;
	if (inicial < 1 || final < 1) return;

	int len = listaLength(lista);

	if (len < final || inicial > len) return;
	
	int dato = buscarBorrarNodo(lista, inicial);
	insertarPos(lista, dato, final);
}

#endif