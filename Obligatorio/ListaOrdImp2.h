#ifndef LISTAORDIMP2_H
#define LISTAORDIMP2_H

#include <assert.h>
#include "ListaOrd.h"
#include "ListaPosImp.h"
#include "IteradorListaOrdImp2.h"
#include "NodoABB.h"

template <class T>
class IteradorListaOrdImp2;

template <class T>
class ListaOrdImp2: public ListaOrd<T> {
	friend class IteradorListaOrdImp2<T>; 
	friend ostream &operator<<(ostream& o, const ListaOrdImp2<T> & l);

public:
	
	// Constructores
	ListaOrdImp2();
	// Constructor copia
	ListaOrdImp2(const ListaOrd<T> &l);
	ListaOrdImp2(const ListaOrdImp2<T> &l);
	
	//PRE:
	//POS: Iguala la Lista (this) con la Lista pasada por parametro
	ListaOrd<T> &operator=(const ListaOrd<T> &l);
	ListaOrd<T> &operator=(const ListaOrdImp2<T> &l);

	//PRE:
	//POS: Crea una nueva lista vacia y retorna su puntero
	ListaOrd<T>* CrearVacia() const;

	//Destructor
	virtual ~ListaOrdImp2();

	//PRE:
	//POS: Agrega el elemento 'e' a la lista 'this' en orden ascendente.
	void AgregarOrd(const T &e);

	//PRE:
	//POS: Elimina el nodo de menor valor. (Mas a la izquierda)
	void BorrarMinimo();

	//PRE:
	//POS: Elimina el nodo con mayor valor. (Mas a la derecha)
	void BorrarMaximo();

	//PRE:
	//POS: Busca y elimina el elemento 'e', en caso de existir.
	void Borrar(const T &e);

	//PRE:
	//POS: Retorna el valor minimo.
	const T& Minimo() const;

	//PRE:
	//POS: Retorna el valor maximo.
	const T& Maximo() const;

	//PRE:
	//POS: Retorna el valor T de la lista
	const T& Recuperar(const T&) const;

	//PRE:
	//POS: Retorna el valor T de la lista
	T& RecuperarInseguro(const T&) const;

	//PRE:
	//POS: Returna true si y solo si se encuentra el elemento 'e' en la lista.
	bool Existe(const T& e) const;

	//PRE:
	//POS: Elimina todos los elementos de this
	void Vaciar();

	//PRE:
	//POS: Retorna la cantidad de elementos que existen en this
	unsigned int CantidadElementos() const;

	//PRE:
	//POS: Retorna true si y solo si la cantidad de elementos en this es 0
	bool EsVacia() const;

	//PRE:
	//POS: Retorna false, dado que no es una lista acotada
	bool EsLlena() const;

	//PRE:
	//POS: Retorna el puntero a una copia de this
	ListaOrd<T>* Clon() const;

	//PRE:
	//POS: Retorna el iterador de la lista
	Iterador<T> GetIterador() const;

	//PRE:
	//POS: Imprime los elementos de la lista
	void Imprimir(ostream& o) const;

private:

protected:

	//Funcionex Auxiliares

	//PRE:
	//POS: Agrega de forma ordenada ascendentemente el elemento 'e' en el ABB this
	void AgregarOrdAux(NodoABB<T>*& nodo, const T& e);

	//PRE:
	//POS: Retorna un puntero al nodo con el valor minimo en la lista (ABB)
	NodoABB<T>*& MinimoEnABB(NodoABB<T>*& nodo);

	//PRE:
	//POS: Retorna un puntero al nodo con el valor maximo en la lista (ABB)
	NodoABB<T>*& MaximoEnABB(NodoABB<T>*& nodo);
	
	//PRE:
	//POS: Convierte el ABB this a una ListaPos
	void ABBToListPos(NodoABB<T>* abb, ListaPos<T>& list) const;

	//PRE:
	//POS: Retorna el valor minimo en el ABB
	const T& MinimoAux(NodoABB<T>* n) const;
	
	//PRE:
	//POS: Retorna el valor maximo en el ABB
	const T& MaximoAux(NodoABB<T>* n) const;

	//PRE:
	//POS: Elimina el nodo raiz del ABB y re acomoda nuevamente los nodos
	void BorrarNodoRaiz(NodoABB<T>*& n);
	
	//PRE:
	//POS: Elimina el elemento 'e' en el ABB this
	void BorrarAux(NodoABB<T>*& n, const T& e);

	//PRE:
	//POS: Elimina todos los nodos del ABB
	void VaciarAux(NodoABB<T>*& n);
	
	//PRE:
	//POS: Retorna el dato del nodo 'e'
	const T& RecuperarAux(NodoABB<T>* nodo, const T& e) const;

	//PRE:
	//POS: Retorna el valor dato del nodo 'e', permite modificarlo
	T& RecuperarInseguroAux(NodoABB<T>* nodo, const T& e) const;
	
	//PRE:
	//POS: Retorna true si y solo si existe el elemento 'e' en el ABB this
	bool ExisteAux(NodoABB<T>* n, const T& e) const;

	//Atributos
	NodoABB<T>* nodo;
	int lenght;
};

#include "ListaOrdImp2.cpp"

#endif