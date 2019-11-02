#include "Tabla.h"

#ifndef TABLA_CPP
#define TABLA_CPP

ostream &operator<<(ostream& out, const Tabla &t) {
	out << t.GetNombre();
	return out;
}

Tabla::Tabla() {
	//Done
}

Tabla::Tabla(Cadena &nombreTabla) {
	name = nombreTabla;
}

Tabla::Tabla(const Tabla &t) {
	//Copy Paste de Tabla()
	*this = t;
}

Tabla::~Tabla() {
}

Tabla &Tabla::operator=(const Tabla &t) {
	if (this != &t) {
		name = t.name;
	}
	return *this;
}

bool Tabla::operator==(const Tabla &t) const {
	return name == t.name;
}

bool Tabla::operator!=(const Tabla &t) const {
	return name != t.name;
}

bool Tabla::operator<(const Tabla &t) const {
	return name < t.name;
}

bool Tabla::operator>(const Tabla &t) const {
	return name > t.name;
}

bool Tabla::operator<=(const Tabla &t) const {
	return name <= t.name;
}

bool Tabla::operator>=(const Tabla &t) const {
	return name >= t.name;
}

bool Tabla::sonIguales(const Tabla &t) const
{
	// NO IMPLEMENTADA
	return false;
}

const Cadena &Tabla::GetNombre() const {
	return name;
}

TipoRetorno Tabla::addCol(Cadena &nombreCol, CalifCol calificadorColumna) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno Tabla::delCol(Cadena &nombreCol) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno Tabla::insertInto(Cadena &valoresTupla) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno Tabla::deleteFrom(Cadena &condicionEliminar) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

void Tabla::printMetadata() {
	// NO IMPLEMENTADA
}

void Tabla::printDataTable() {
	cout << name;
}

TipoRetorno Tabla::join(Tabla &t1, Tabla &t2) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

#endif
