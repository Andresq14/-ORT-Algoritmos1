#include "ColaImp.h"

#ifndef COLAIMP_CPP
#define COLAIMP_CPP

template <class T>
ostream &operator<<(ostream& out, const ColaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
ColaImp<T>::ColaImp(){
	this->cola = new ListaPosImp<T>();
}

template <class T>
ColaImp<T>::ColaImp(const Cola<T> &c){
	this->cola = cola = new ListaPosImp<T>();

	*this = c;
}

template <class T>
ColaImp<T>::ColaImp(const ColaImp<T> &c){
	this->cola = cola = new ListaPosImp<T>();

	*this = c;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const Cola<T> &c){
	if (this != &c) {
		*this = c;
	}
	return *this;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const ColaImp<T> &c){
	if (this != &c) {
		*(cola) = *(c.cola);
	}
	return *this;
}

template <class T>
bool ColaImp<T>::operator==(const Cola<T>& c) const{
	return true;
}

template <class T>
ColaImp<T>::~ColaImp(){
	delete cola;
}

template<class T>
Cola<T>* ColaImp<T>::CrearVacia() const {
	return new ColaImp<T>();
}

template <class T>
void ColaImp<T>::Encolar(const T &e){
	if (this->cola->Existe(e))
	{
		this->cola->Borrar(e);
		this->cola->AgregarPpio(e);
	}
	else if (this->EsLlena())
	{
		this->cola->BorrarFin();
		this->cola->AgregarPpio(e);
	}
	else
	{
		this->cola->AgregarPpio(e);
	}
}

template <class T>
T& ColaImp<T>::Principio()const{
	assert(!EsVacia());

	return this->cola->ElementoPpio();
}

template <class T>
T ColaImp<T>::Desencolar(){
	T elem = Principio();
	this->cola->BorrarPpio();
	return elem;
}

template <class T>
void ColaImp<T>::Vaciar(){
	this->cola->Vaciar();
}

template <class T>
unsigned int ColaImp<T>::CantidadElementos()const{
	return this->cola->CantidadElementos();
}

template <class T>
bool ColaImp<T>::EsVacia() const{
	return this->cola->EsVacia();
}

template <class T>
bool ColaImp<T>::EsLlena() const{
	return false;
}

template <class T>
Cola<T>* ColaImp<T>::Clon()const{
	Cola<T>* clon = new ColaImp<T>();

	for (Iterador<T> i = this->cola->GetIterador(); !i.EsFin();)
		clon->Encolar(i++);

	return clon;
}

template <class T>
void ColaImp<T>::Imprimir(ostream& o)const{
	this->cola->Imprimir(o);
}

#endif