#include "EjerciciosSem7.h"

#ifndef EJERCICIOSSEM7_CPP
#define EJERCICIOSSEM7_CPP

#pragma region Aux

/*
PRE: Recibe dos enteros
POST: Retorna el mayor de estos
*/
int max(int a, int b)
{
	return a > b ? a : b;
}

/*
PRE: Recibe un árbol (a) y dos enteros (desde y hasta) mayores a 0 y el nivel en el cual se encuentra actualmente.
POST: Retorna la cantidad de nodos ubicados entre los niveles desde y hasta del árbol a.
*/
int cantNodosEntreNiveles(NodoAB* a, int nivel, int desde, int hasta)
{
	if (a == NULL) return 0;
	if (desde > hasta || nivel > hasta) return 0;
	if (desde == hasta) return 1;

	if (nivel < desde)
		return cantNodosEntreNiveles(a->izq, nivel + 1, desde, hasta) + cantNodosEntreNiveles(a->der, nivel + 1, desde, hasta);
	else
		return 1 + cantNodosEntreNiveles(a->izq, nivel + 1, desde, hasta) + cantNodosEntreNiveles(a->der, nivel + 1, desde, hasta);
}

/*
PRE:
POST:
*/
bool existsInABB(NodoAB* a, int dato)
{
	if (a == NULL) return false;
	if (a->dato == dato) return true;
	if (dato > a->dato)
		return existsInABB(a->der, dato);
	else
		return existsInABB(a->izq, dato);
}

/*
PRE:
POST:
*/
bool sumaABBAux(NodoAB* a, int n, NodoAB* root)
{
	if (a == NULL) return NULL;
	if ((a->dato * 2) != n)
	{
		bool existe = existsInABB(root, n - a->dato);
		if (existe) return true;
	}
	return sumaABBAux(a->izq, n, root) || sumaABBAux(a->der, n, root);
}

/*
PRE:
POST:
*/
NodoAB*& minInABB(NodoAB*& a) 
{
	if (a->izq == NULL) 
		return a;
	else 
		return minInABB(a->izq);
}

/*
PRE:
POST:
*/
int sucesorAux(NodoAB* a, int n, int min)
{
	if (a == NULL) return (min == INT_MAX) ? -1 : min;

	if(a->dato > n && a->dato < min)
		min = a->dato;

	if (n >= a->dato)
		return sucesorAux(a->der, n, min);
	else
		return sucesorAux(a->izq, n, min);

	return min;
}

/*
PRE:
POST:
*/
int sumaPorNivelesAux(NodoAG* a, int n)
{
	int sum = 0;
	if (a == NULL) return sum;
	if (n % 2 == 0) sum += a->dato;
	else sum-= a->dato;
	
	return sum += sumaPorNivelesAux(a->ph, n + 1) + sumaPorNivelesAux(a->sh, n);
}

/*
PRE:
POST:
*/

void enNivelAux(NodoAB* a, int k, NodoLista*& l)
{
	if (k <= 0) return;
	if (a == NULL) return;

	enNivelAux(a->der, k - 1, l);

	if (k == 1)
	{
		NodoLista* nodo = new NodoLista;
		nodo->dato = a->dato;
		nodo->sig = l;
		l = nodo;
	}

	enNivelAux(a->izq, k - 1, l);
}

#pragma endregion


int altura(NodoAB* raiz)
{
	if (raiz == NULL) return 0;
	return 1 + max(altura(raiz->izq), altura(raiz->der));
}

bool sonIguales(NodoAB* p, NodoAB* q) 
{
	if (p == NULL && q == NULL) return true;
	if (p == NULL) return false;
	if (q == NULL) return false;

	return (p->dato == q->dato) && sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	if (raiz == NULL) return sum == 0;
	else if (raiz->der == NULL && raiz->izq == NULL) return raiz->dato == sum;
	else if (raiz->izq == NULL) return existeCaminoConSuma(raiz->der, sum - raiz->dato);
	else if (raiz->der == NULL) return existeCaminoConSuma(raiz->izq, sum - raiz->dato);
	else return existeCaminoConSuma(raiz->der, sum - raiz->dato) || existeCaminoConSuma(raiz->izq, sum - raiz->dato);
}

bool esArbolBalanceado(NodoAB *raiz) {
	if (raiz == NULL) return true;

	int altIzq = altura(raiz->izq);
	int altDer = altura(raiz->der);

	return (altIzq == altDer || altIzq + 1 == altDer || altIzq == altDer + 1)
		&& esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
}

NodoLista* enNivel(NodoAB *a, int k) 
{
	NodoLista* ret = NULL;
	enNivelAux(a, k, ret);
	return ret;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) 
{
	return cantNodosEntreNiveles(a, 1, desde, hasta);
}

NodoLista* camino(NodoAB *arbol, int x) 
{
	if (arbol == NULL) return NULL;

	NodoLista* ret = new NodoLista;

	if (arbol->dato == x)
	{
		ret->dato = arbol->dato;
		ret->sig = NULL;
	}
	else
	{
		if (x > arbol->dato)
		{
			ret->dato = arbol->dato;
			ret->sig = camino(arbol->der, x);
		}
		else
		{
			ret->dato = arbol->dato;
			ret->sig = camino(arbol->izq, x);
		}
	}

	return ret;

}

NodoAB* invertirHastak(NodoAB* a, int k){
	if (a == NULL) return NULL;
	if (k == 0) return NULL;

	NodoAB* nodo = new NodoAB;
	nodo->dato = a->dato;
	nodo->der = invertirHastak(a->izq, k - 1);
	nodo->izq = invertirHastak(a->der, k - 1);
	return nodo;
}

void borrarNodoRaiz(NodoAB * & A) 
{
	if (A == NULL) return;
	
	NodoAB* borrar = A;

	if (A->izq == NULL)
	{
		A = A->der;
	}
	else if (A->der == NULL)
	{
		A = A->izq;
	}
	else
	{
		NodoAB* aux = minInABB(A->der);
		aux->izq = A->izq;
		A = A->der;
	}

	delete borrar;
}

bool sumaABB(NodoAB* a, int n)
{
	return sumaABBAux(a, n, a);
}

int sucesor(NodoAB* a, int n)
{
	return sucesorAux(a, n, INT_MAX);
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) 
{
	return 0;
}

void borrarPares(NodoAB* & a)
{
	if (a == NULL) return;
	if (a->dato % 2 == 0)
	{
		borrarNodoRaiz(a);
		borrarPares(a);
	}
	else
	{
		borrarPares(a->izq);
		borrarPares(a->der);
	}
}

int alturaAG(NodoAG* raiz)
{
	if (raiz == NULL) return 0;
	else return max(alturaAG(raiz->ph) + 1, alturaAG(raiz->sh));
}

int sumaPorNiveles(NodoAG* raiz)
{
	return sumaPorNivelesAux(raiz, 1);
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	if (l == NULL) return true;
	if (a == NULL) return false;

	if (a->dato == l->dato)
		return esPrefijo(a->ph, l->sig);
	else
		return esPrefijo(a->sh, l);
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) 
{
	if (arbolGeneral == NULL) return NULL;
	NodoLista* nodo = NULL;
	if (arbolGeneral->dato == dato)
	{
		nodo = new NodoLista;
		nodo->dato = dato;
		nodo->sig = caminoAG(arbolGeneral->ph, dato);
		return nodo;
	}
	else
	{
		nodo = caminoAG(arbolGeneral->ph, dato);
		if (nodo == NULL) return caminoAG(arbolGeneral->sh, dato);
		else
		{
			NodoLista* aux = new NodoLista;
			aux->dato = arbolGeneral->dato;
			aux->sig = nodo;
			nodo = aux;
			return nodo;
		}
	}

}

int nivelConMasNodosAG(NodoAG * arbolGeneral) 
{
	// IMPLEMENTAR SOLUCION
	return 0;
}


#endif