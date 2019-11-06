#include "ListaPosImp.h"

#ifndef LISTAPOSIMP_CPP
#define LISTAPOSIMP_CPP

template <class T>
inline ostream & operator<<(ostream &out, const ListaPosImp<T> &l)
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::CrearVacia() const
{
	return new ListaPosImp<T>();
}

template <class T>
ListaPosImp<T>::ListaPosImp()
{
	this->first = NULL;
	this->last = NULL;
	this->length = 0;
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPos<T> &l)
{
	this->first = NULL;
	this->last = NULL;
	this->length = 0;

	*this = l;
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPosImp<T> &l)
{
	this->first = NULL;
	this->last = NULL;
	this->length = 0;

	*this = l;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPos<T> &l)
{
	if (this != &l) {
		this->Vaciar();

		unsigned int index = 0;

		for (Iterador<T> i = l.GetIterador(); !i.EsFin(); i++)
		{
			AgregarPos(i.Elemento(), index);
			index++;
		}
	}
	return *this;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPosImp<T> &l)
{
	if (this != &l) {
		this->Vaciar();

		unsigned int index = 0;

		for (Iterador<T> i = l.GetIterador(); !i.EsFin(); i++)
		{
			AgregarPos(i.Elemento(), index);
			index++;
		}
	}
	return *this;
}

template <class T>
ListaPosImp<T>::~ListaPosImp()
{
	this->Vaciar();
}

template <class T>
void ListaPosImp<T>::AgregarPpio(const T &e) 
{
	NodoLista<T>* nodo = new NodoLista<T>(e, NULL, first); //Nodo, Anterior, Siguiente
	if (last == NULL)
		last = nodo;
	else
		first->ant = nodo;

	first = nodo;
	length++;
}

template <class T>
void ListaPosImp<T>::AgregarFin(const T &e) 
{
	NodoLista<T>* nodo = new NodoLista<T>(e, last, NULL);
	if (first == NULL)
		first = nodo;
	else
		last->sig = nodo;

	last = nodo;
	length++;
}

template <class T>
void ListaPosImp<T>::AgregarPos(const T &e, unsigned int pos)
{
	AgregarPosAux(first, e, pos);
}

template <class T>
void ListaPosImp<T>::AgregarPosAux(NodoLista<T>* list, const T& e, unsigned int pos)
{
	if (pos <= 0 || first == NULL)
		AgregarPpio(e);
	else if (pos >= length)
		AgregarFin(e);
	else 
	{
		NodoLista<T>* aux = ElementoPosAux(first, pos-1);
		NodoLista<T>* nodo = new NodoLista<T>(e, aux, aux->sig);
		aux->sig = nodo;
		length++;
	}
}

template <class T>
void ListaPosImp<T>::BorrarPpio()
{
	if (first == NULL) return;

	NodoLista<T>* borrar = first;
	first = first->sig;
	delete borrar;
	length--;

	if (first != NULL)
		first->ant = NULL;
	else
		last = NULL;
}

template <class T>
void ListaPosImp<T>::BorrarFin()
{
	if (last == NULL) return;

	NodoLista<T>* borrar = last;
	last = last->ant;
	delete borrar;
	length--;

	if (last != NULL)
		last->sig = NULL;
	else
		first = NULL;
}

template <class T>
void ListaPosImp<T>::BorrarPos(unsigned int pos)
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaPosImp<T>::Borrar(const T& e)
{
	if (EsVacia())
		return;
	if (e == first->dato)
		BorrarPpio();
	else if (e == last->dato)
		BorrarFin();
	//TODO Buscar elemento y borrarlo

}

template <class T>
T& ListaPosImp<T>::ElementoPpio() const
{
	return this->first->dato;
}

template <class T>
T& ListaPosImp<T>::ElementoFin() const
{
	return this->last->dato;
}

template <class T>
T& ListaPosImp<T>::ElementoPos(unsigned int pos) const
{
	if (pos <= 0)
		return first->dato;
	if (pos >= length)
		return last->dato;

	NodoLista<T>* nodo = ElementoPosAux(first, pos);
	return nodo->dato;
}

template <class T>
NodoLista<T>* ListaPosImp<T>::ElementoPosAux(NodoLista<T>* list, unsigned int pos) const
{
	if (pos == 0)
		return list;
	else
		return ElementoPosAux(list->sig, (pos - 1));
}

template <class T>
unsigned int ListaPosImp<T>::Posicion(const T &e) const
{
	// NO IMPLEMENTADA
	return 0;
}

template <class T>
bool ListaPosImp<T>::Existe(const T &e) const
{
	if (first == NULL)
		return false;

	NodoLista<T>* aux = first;
	while (aux != NULL && !(aux->dato == e)) {
		aux = aux->sig;
	}

	if (aux == NULL)
		return false;

	return true;
}

template <class T>
void ListaPosImp<T>::Vaciar()
{
	NodoLista<T>* aux = first;
	while (aux != NULL) {
		NodoLista<T>* borrar = aux;
		aux = aux->sig;
		delete borrar;
	}

	this->last = NULL;
	this->first = NULL;
	this->length = 0;
}

template <class T>
unsigned int ListaPosImp<T>::CantidadElementos() const
{ 
	return length;
}

template <class T>
bool ListaPosImp<T>::EsVacia() const
{
	return length == 0;
}

template <class T>
bool ListaPosImp<T>::EsLlena() const
{
	return false;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::Clon() const
{
	ListaPos<T>* clon = new ListaPosImp<T>();

	unsigned int index = 0;

	for (Iterador<T> i = this->GetIterador(); !i.EsFin(); i++)
	{
		clon->AgregarPos(i.Elemento(), index);
		index++;
	}

	return clon;
}

template <class T>
Iterador<T> ListaPosImp<T>::GetIterador() const
{
	return IteradorListaPosImp<T>(*this);
}

template <class T>
void ListaPosImp<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> i = GetIterador(); !i.EsFin();) {
		o << i++;
		if (!i.EsFin()) o << " ";
	}
}

#endif