#include "ListaOrdImp2.h"

#ifndef LISTAORDIMP2_CPP
#define LISTAORDIMP2_CPP

template <class T>
inline ostream &operator<<(ostream& out, const ListaOrdImp2<T> &l) 
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaOrd<T>* ListaOrdImp2<T>::CrearVacia() const 
{
	return new ListaOrdImp2<T>();
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2()
{
	this->nodo = NULL;
	this->lenght = 0;
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrd<T> &l) 
{
	this->nodo = NULL;
	this->lenght = 0;
	*this = l;
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrdImp2<T> &l) 
{
	this->nodo = NULL;
	this->lenght = 0;
	*this = l;
}

template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrd<T> &l) 
{ 
	if (this != &l) {
		this->Vaciar();
		ListaOrd<T>* clon = l.Clon();
		while (!clon->EsVacia())
		{
			const T& elem = clon->Minimo();
			this->AgregarOrd(elem);
			clon->BorrarMinimo();
		}
	}
	return *this;
}

template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrdImp2<T> &l) 
{ 
	if (this != &l) {
		this->Vaciar();
		ListaOrd<T>* clon = l.Clon();
		while (!clon->EsVacia())
		{
			const T& elem = clon->Minimo();
			this->AgregarOrd(elem);
			clon->BorrarMinimo();
		}
	}
	return *this;
}

template <class T>
ListaOrdImp2<T>::~ListaOrdImp2()
{
	this->Vaciar();
}

template <class T>
void ListaOrdImp2<T>::AgregarOrd(const T &e) 
{
	AgregarOrdAux(this->nodo, e);
}

template <class T>
void ListaOrdImp2<T>::AgregarOrdAux(NodoABB<T>*& n, const T& e)
{
	if (n == NULL)
	{
		NodoABB<T>* nuevo = new NodoABB<T>(e);
		nuevo->auxiliar = 1;
		n = nuevo;
		lenght++;
	}
	else if (e == n->dato)
	{
		n->auxiliar++;
		lenght++;
	}
	else if (e > n->dato)
		AgregarOrdAux(n->der, e);
	else
		AgregarOrdAux(n->izq, e);
}

template <class T>
void ListaOrdImp2<T>::BorrarMinimo()
{
	if (nodo == NULL) return;

	BorrarNodoRaiz( MinimoEnABB(this->nodo) );
}

template <class T>
void ListaOrdImp2<T>::BorrarMaximo() 
{
	if (nodo == NULL) return;

	BorrarNodoRaiz( MaximoEnABB(this->nodo) );
}

template <class T>
void ListaOrdImp2<T>::Borrar(const T &e)
{
	BorrarAux(this->nodo, e);
}

template <class T>
void ListaOrdImp2<T>::BorrarAux(NodoABB<T>*& n, const T& e)
{
	if (EsVacia())
		return;

	if (e == n->dato)
		BorrarNodoRaiz(n);
	else if (e > n->dato)
		BorrarAux(n->der, e);
	else
		BorrarAux(n->izq, e);
}

template <class T>
void ListaOrdImp2<T>::BorrarNodoRaiz(NodoABB<T>*& n)
{
	if (n == NULL) 
		return;

	if (n->auxiliar > 1)
		n->auxiliar--;
	else
	{
		NodoABB<T>* borrar = n;

		if (n->izq == NULL)
			n = n->der;
		else if (n->der == NULL)
			n = n->izq;
		else
		{
			NodoABB<T>* aux = MinimoEnABB(n->der);
			aux->izq = n->izq;
			n = n->der;
		}

		delete borrar;
	}

	this->lenght--;
}

template <class T>
const T& ListaOrdImp2<T>::Minimo() const 
{
	assert(nodo != NULL);

	return MinimoAux(this->nodo);
}

template <class T>
const T& ListaOrdImp2<T>::MinimoAux(NodoABB<T>* n) const
{
	if (n->izq == NULL)
		return n->dato;
	else
		return MinimoAux(n->izq);
}

template <class T>
NodoABB<T>*& ListaOrdImp2<T>::MinimoEnABB(NodoABB<T>*& n)
{
	assert(nodo != NULL);

	if (n->izq == NULL)
		return n;
	else
		return MinimoEnABB(n->izq);
}

template <class T>
const T& ListaOrdImp2<T>::Maximo() const
{
	assert(nodo != NULL);

	return MaximoAux(this->nodo);
}

template <class T>
const T& ListaOrdImp2<T>::MaximoAux(NodoABB<T>* n) const
{
	assert(nodo != NULL);

	if (n->der == NULL)
		return n->dato;
	else
		return MinimoAux(n->der);
}

template <class T>
NodoABB<T>*& ListaOrdImp2<T>::MaximoEnABB(NodoABB<T>*& n)
{
	assert(nodo != NULL);

	if (n->der == NULL)
		return n;
	else
		return MinimoEnABB(n->der);
}

template <class T>
const T& ListaOrdImp2<T>::Recuperar(const T &e) const 
{
	assert(this->nodo != NULL);
	
	return RecuperarAux(this->nodo, e);
}

template <class T>
const T& ListaOrdImp2<T>::RecuperarAux(NodoABB<T>* n, const T& e) const
{
	if (n->dato == e)
		return n->dato;
	else if (n->dato > e)
		return RecuperarAux(n->izq, e);
	else
		return RecuperarAux(n->der, e);
}

template <class T>
T& ListaOrdImp2<T>::RecuperarInseguro(const T& e) const
{
	assert(nodo != NULL);

	return RecuperarInseguroAux(this->nodo, e);
}

template <class T>
T& ListaOrdImp2<T>::RecuperarInseguroAux(NodoABB<T>* n, const T& e) const
{
	assert(nodo != NULL);

	if (n->dato == e)
		return n->dato;
	else if (n->dato > e)
		return RecuperarInseguroAux(n->izq, e);
	else
		return RecuperarInseguroAux(n->der, e);
}

template <class T>
bool ListaOrdImp2<T>::Existe(const T &e) const 
{
	return ExisteAux(this->nodo, e);
}

template <class T>
bool ListaOrdImp2<T>::ExisteAux(NodoABB<T>* n, const T& e) const
{
	if (n == NULL)
		return false;
	if (n->dato == e)
		return true;
	else if (n->dato > e)
		return ExisteAux(n->izq, e);
	else
		return ExisteAux(n->der, e);
}

template <class T>
void ListaOrdImp2<T>::Vaciar() 
{
	VaciarAux(this->nodo);
}

template <class T>
void ListaOrdImp2<T>::VaciarAux(NodoABB<T>*& n)
{
	if (n == NULL) return;

	VaciarAux(n->izq);
	VaciarAux(n->der);
	BorrarNodoRaiz(n);
}

template <class T>
unsigned int ListaOrdImp2<T>::CantidadElementos()const 
{ 
	return lenght;
}

template <class T>
bool ListaOrdImp2<T>::EsVacia()const 
{
	return lenght == 0;
}

template <class T>
bool ListaOrdImp2<T>::EsLlena()const 
{ 
	return false;
}

template<class T>
ListaOrd<T>* ListaOrdImp2<T>::Clon() const
{
	ListaOrd<T>* clon = new ListaOrdImp2<T>();

	for (Iterador<T> i = this->GetIterador(); !i.EsFin();)
		clon->AgregarOrd(i++);

	return clon;
}

template <class T>
void ListaOrdImp2<T>::ABBToListPos(NodoABB<T>* abb, ListaPos<T>& list) const
{
	if (abb == NULL) return;
	
	ABBToListPos(abb->izq, list);
	
	for(unsigned int i = 0; i < abb->auxiliar; i++)
		list.AgregarFin((abb->dato));

	ABBToListPos(abb->der, list);
}

template <class T>
Iterador<T> ListaOrdImp2<T>::GetIterador() const 
{
	ListaPosImp<T> l;
	ABBToListPos(nodo, l);
	return IteradorListaOrdImp2<T>(l);
}

template <class T>
void ListaOrdImp2<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> i = GetIterador(); !i.EsFin();) {
		o << i++;
		if (!i.EsFin()) o << " ";
	}
}


#endif