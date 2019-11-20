#include "Tupla.h"

#ifndef TUPLA_CPP
#define TUPLA_CPP

ostream& operator<<(ostream& out, const Tupla& t)
{
	for (Iterador<Cadena> i = t.GetDatos()->GetIterador(); !i.EsFin();)
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
	datos = new ListaPosImp<Cadena>();
}

Tupla::Tupla(ListaPos<Cadena>* dato)
{
	datos = new ListaPosImp<Cadena>();
	*(datos) = *(dato);
}

Tupla::Tupla(const Tupla& t)
{
	datos = new ListaPosImp<Cadena>();
	
	*this = t;
}

Tupla::~Tupla()
{
	delete datos;
}

Tupla& Tupla::operator=(const Tupla& t) {
	if (this != &t){
		*(datos) = *(t.datos);
	}
	return *this;
}

bool Tupla::operator==(const Tupla& t) const 
{
	return *(datos) == *(t.datos);
}

const ListaPos<Cadena>* Tupla::GetDatos() const
{
	return this->datos;
}

ListaPos<Cadena>* Tupla::GetDatosInseguro() const
{
	return this->datos;
}

#endif // !TUPLA_CPP
