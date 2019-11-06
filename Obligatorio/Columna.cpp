#include "Columna.h"

#ifndef COLUMNA_CPP
#define COLUMNA_CPP

ostream& operator<<(ostream& out, const Columna& c)
{
	out << (c.GetCalificador() == PK ? "*" : "") << c.GetNombre() << endl;
	return out;
}

Columna::Columna()
{
	assert(false);
}

Columna::Columna(Cadena& nombre, CalifCol& calificador)
{
	name = nombre;
	qualifier = calificador;
}

Columna::Columna(Cadena& nombre)
{
	name = nombre;
	qualifier = EMPTY;
}

Columna::Columna(const Columna& c)
{
	//Copy Paste constructor sin parametros

	*this = c;
}

Columna::~Columna()
{
}

Columna& Columna::operator=(const Columna& c) {
	if (this != &c) {
		name = c.name;
		qualifier = c.qualifier;
	}
	return *this;
}

bool Columna::operator==(const Columna& c) const {
	if (c.qualifier == PK)
		return name == c.name || qualifier == PK;
	else
		return name == c.name;
}

bool Columna::operator!=(const Columna& c) const {
	return name != c.name;
}

bool Columna::operator<(const Columna& c) const {
	return name < c.name;
}

bool Columna::operator>(const Columna& c) const {
	return name > c.name;
}

bool Columna::operator<=(const Columna& c) const {
	return name <= c.name;
}

bool Columna::operator>=(const Columna& c) const {
	return name >= c.name;
}

const Cadena& Columna::GetNombre() const
{
	return name;
}

const CalifCol& Columna::GetCalificador() const
{
	return qualifier;
}

#endif // !COLUMNA_CPP
