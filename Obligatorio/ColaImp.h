#ifndef COLAIMP_H
#define COLAIMP_H

#include "Cola.h"
#include "ListaPos.h"
#include "ListaPosImp.h"

template <class T>
class ColaImp : public Cola<T>{

public:
	//Constructor por defecto
	ColaImp();
	//Constructor copia
	ColaImp(const Cola<T> &c);
	ColaImp(const ColaImp<T> &c);
	
	//PRE:
	//POS: Iguala la Cola (this) con la Cola pasada por parametro
	Cola<T> &operator=(const Cola<T> &c);
	Cola<T> &operator=(const ColaImp<T> &c);

	//Destructor
	virtual ~ColaImp();

	//Operador de comparacion
	bool operator==(const Cola<T>& c) const;

	//PRE:
	//POS: Crea una nueva cola vacia y retorna su puntero
	Cola<T> *CrearVacia() const;

	//PRE:
	//POS: Retorna el puntero a una copia de this
	Cola<T> *Clon()const;
	
	//PRE:
	//POS: Inserta el elemento 'e' en la primera posicion de la cola, si ya existia, lo elimina y lo coloca en el primer lugar.
	void Encolar(const T &e);
	
	//PRE:
	//POS: Retorna el elemento que se encuentra al principio.
	T& Principio() const;
	
	//PRE:
	//POS: Retorna el primer elemento y lo elimina de la cola.
	T Desencolar();

	//PRE:
	//POS: Elimina todos los elementos.
	void Vaciar();
	
	//PRE:
	//POS: Retorna la cantidad de elementos en la cola.
	unsigned int CantidadElementos() const;
	
	//PRE:
	//POS: Retorna true si y solo si la cantidad de elementos es 0
	bool EsVacia() const;
	
	//PRE:
	//POS: Retorna false, la cola no es acotada
	bool EsLlena() const;

	//PRE:
	//POS: Imprime los elementos de la cola
	void Imprimir(ostream& o) const;

private:
	//Atributos
	ListaPos<T>* cola;
};

#include "ColaImp.cpp"

#endif