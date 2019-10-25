#include "Tabla.h"

#ifndef TABLA_CPP
#define TABLA_CPP

ostream &operator<<(ostream& out, const Tabla &t) {
	out << t.GetNombre();
	return out;
}

Tabla::Tabla() {
	// NO IMPLEMENTADA
}

Tabla::Tabla(Cadena &nombreTabla) {
	// NO IMPLEMENTADA
}

Tabla::Tabla(const Tabla &t) {
	// NO IMPLEMENTADA
}

Tabla::~Tabla() {
	// NO IMPLEMENTADA
}

Tabla &Tabla::operator=(const Tabla &t) {
	if (this != &t) {
		// NO IMPLEMENTADA
	}
	return *this;
}

bool Tabla::operator==(const Tabla &t) const {
	// NO IMPLEMENTADA
	return false;
}

bool Tabla::operator!=(const Tabla &t) const {
	// NO IMPLEMENTADA
	return false;
}

bool Tabla::operator<(const Tabla &t) const {
	// NO IMPLEMENTADA
	return false;
}

bool Tabla::operator>(const Tabla &t) const {
	// NO IMPLEMENTADA
	return false;
}

bool Tabla::operator<=(const Tabla &t) const {
	// NO IMPLEMENTADA
	return false;
}

bool Tabla::operator>=(const Tabla &t) const {
	// NO IMPLEMENTADA
	return false;
}

bool Tabla::sonIguales(const Tabla &t) const
{
	// NO IMPLEMENTADA
	return false;
}

const Cadena &Tabla::GetNombre() const {
	// NO IMPLEMENTADA
	return *(new Cadena()); // Esta linea no es correcta, no debería hacer new. Esta asi para que no de warning al no estar implementada.
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
	// NO IMPLEMENTADA
}

TipoRetorno Tabla::join(Tabla &t1, Tabla &t2) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

#endif
