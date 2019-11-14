#include "Tupla.h"

#ifndef TUPLA_CPP
#define TUPLA_CPP

ostream& operator<<(ostream& out, const Tupla& t)
{
	return out;
}

Tupla::Tupla()
{
	tuplas = new ListaPosImp<Cadena>();
}

Tupla::Tupla(ListaPos<Cadena>* dato)
{
	tuplas = new ListaPosImp<Cadena>();
	*(tuplas) = *(dato);
}

Tupla::Tupla(const Tupla& t)
{
	tuplas = new ListaPosImp<Cadena>();
	
	*this = t;
}

Tupla::~Tupla()
{
	delete tuplas;
}

Tupla& Tupla::operator=(const Tupla& t) {
	if (this != &t){
		*(tuplas) = *(t.tuplas);
	}
	return *this;
}

bool Tupla::operator==(const Tupla& t) const 
{
	return tuplas == t.tuplas;
}

bool Tupla::operator!=(const Tupla& t) const {
	return tuplas != t.tuplas;
}

bool Tupla::operator<(const Tupla& t) const {
	return tuplas < t.tuplas;
}

bool Tupla::operator>(const Tupla& t) const {
	return tuplas > t.tuplas;
}

bool Tupla::operator<=(const Tupla& t) const {
	return tuplas <= t.tuplas;
}

bool Tupla::operator>=(const Tupla& t) const {
	return tuplas >= t.tuplas;
}


#endif // !TUPLA_CPP
