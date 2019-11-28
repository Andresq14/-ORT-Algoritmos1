#ifndef LISTAPOSIMP_H
#define LISTAPOSIMP_H

#include <assert.h>
#include "ListaPos.h"
#include "IteradorListaPosImp.h"
#include "NodoLista.h"

template <class T>
class IteradorListaPosImp;

template <class T>
class ListaPosImp : public ListaPos<T> {
	friend class IteradorListaPosImp<T>;
	friend ostream &operator<<(ostream& o, const ListaPosImp<T> & l);

public:
	// Constructor por defecto
	ListaPosImp();
	// Constructor copia
	ListaPosImp(const ListaPos<T> &l);
	ListaPosImp(const ListaPosImp<T> &l);

	//PRE:
	//POS: Iguala la Lista (this) con la Lista pasada por parametro
	ListaPos<T> &operator=(const ListaPos<T> &l);
	ListaPos<T> &operator=(const ListaPosImp<T> &l);

	// Para ver la documentacion del resto de las funciones ver la especificacion
	ListaPos<T> *CrearVacia() const;

	//Destructor
	virtual ~ListaPosImp();

	//PRE:
	//POS: Agrega el nodo 'e' al principio de la lista this
	void AgregarPpio(const T &e);
	
	//PRE:
	//POS: Agrega el nodo 'e' al final de la lista this
	void AgregarFin(const T &e);
	
	//PRE:
	//POS: Agrega el nodo 'e' en la posicion indicada y reacomoda los demas elementos
	void AgregarPos(const T &e, unsigned int pos);
	
	//PRE:
	//POS: Elimina el nodo que se encuentra al principio de la lista
	void BorrarPpio();
	
	//PRE:
	//POS: Elimina el nodo que se encuentra al final de la lista
	void BorrarFin();
	
	//PRE:
	//POS: Elimina el nodo de la posicion pos, si pos <= 0 elimina el primer nodo, si pos >= CantidadElementos, elimina el ultimo
	void BorrarPos(unsigned int pos);
	
	//PRE:
	//POS: Elimina el nodo 'e'
	void Borrar(const T &e);

	//PRE:
	//POS: Retorna el nodo al principio de la lista
	T& ElementoPpio() const;
	
	//PRE:
	//POS: Retorna el nodo al final de la lista
	T& ElementoFin() const;
	
	//PRE:
	//POS: Retorna el dato en la posicion indicada
	T& ElementoPos(unsigned int pos) const;
	
	//PRE:
	//POS: Retorna la posicion 
	unsigned int Posicion(const T &e) const;
	
	//PRE:
	//POS: Retorna true si y solo si, el elemento 'e' se encuentra en la lista this
	bool Existe(const T &e) const;

	//PRE:
	//POS: Elimina todos los elementos de this
	void Vaciar();

	//PRE:
	//POS: Retorna la cantidad de elementos insertados en la lista this
	unsigned int CantidadElementos() const;

	//PRE:
	//POS: Retorna true si y solo si la cantidad de elementos es 0
	bool EsVacia() const;
	
	//PRE:
	//POS: Retorna false, dado que la lista no es acotada
	bool EsLlena() const;
	
	//PRE:
	//POS: Retorna un puntero a una lista identica a this (no comparten memoria)
	ListaPos<T>* Clon() const;

	//PRE:
	//POS: Retorna el iterador de ListaPos
	Iterador<T> GetIterador() const;
	
	//PRE:
	//POS: Imprime los datos de los elementos en this
	void Imprimir(ostream& o) const;

private:

protected:

	//PRE:
	//POS: Agrega el elemento 'e' en la posicion indicada de la lista this
	void AgregarPosAux(NodoLista<T>* list, const T& e, unsigned int pos);
	
	//PRE:
	//POS: retorna el nodo del elemento que se encuentre en la posicion dada 
	NodoLista<T>* ElementoPosAux(NodoLista<T>* list, unsigned int pos) const;
	
	//PRE:
	//POS: Retorna la posicion del elemento 'e' en caso de que se encuentre en la lista, en caso contrario, retorna el length + 1
	unsigned int PosElemento(const T& elem, NodoLista<T>* list, unsigned int pos) const;

	// Atributos de la clase
	// Primer elemento tiene posicion 0
	NodoLista<T>* first;
	NodoLista<T>* last;
	unsigned int length;

};

#include "ListaPosImp.cpp"

#endif