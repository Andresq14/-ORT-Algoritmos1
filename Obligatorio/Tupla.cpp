#include "Tupla.h"

#ifndef TUPLA_CPP
#define TUPLA_CPP

ostream& operator<<(ostream& out, const Tupla& t)
{
	for (Iterador<Cadena> i = t.GetTuplas()->GetIterador(); !i.EsFin();)
	{
		out << i++;
		
		if (!i.EsFin())
			out << ":";
		else
			out << endl;

		if (i.ElementoInseguro().Length() == 0)
			out << "@EMPTY@";

	}
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

const ListaPos<Cadena>* Tupla::GetTuplas() const
{
	return this->tuplas;
}

ListaPos<Cadena>* Tupla::GetTuplasInseguro() const
{
	return this->tuplas;
}

#endif // !TUPLA_CPP
