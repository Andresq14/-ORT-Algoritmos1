#include "BaseDeDatos.h"

#ifndef BASEDEDATOS_CPP
#define BASEDEDATOS_CPP


BaseDeDatos::BaseDeDatos() {
	// NO IMPLEMENTADA
}

BaseDeDatos::BaseDeDatos(unsigned int MAX_MODIFICADAS) {
	// NO IMPLEMENTADA
}

BaseDeDatos::BaseDeDatos(const BaseDeDatos &bd) {
	// NO IMPLEMENTADA
}

BaseDeDatos::~BaseDeDatos() {
	// NO IMPLEMENTADA
}

BaseDeDatos &BaseDeDatos::operator=(const BaseDeDatos &bd) {
	if (this != &bd) {
		// NO IMPLEMENTADA
	}
	return *this;
}

TipoRetorno BaseDeDatos::createTable(Cadena nombreTabla)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::dropTable(Cadena nombreTabla)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::addCol(Cadena nombreTabla, Cadena nombreCol, CalifCol calificadorColumna)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::dropCol(Cadena nombreTabla, Cadena nombreCol)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::insertInto(Cadena nombreTabla, Cadena valoresTupla)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::deleteFrom(Cadena nombreTabla, Cadena condicionEliminar)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::printTables()
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::printMetadata(Cadena nombreTabla)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::printDataTable(Cadena nombreTabla)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::join(Cadena nombreTabla1, Cadena nombreTabla2, Cadena nombreTabla3)
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

TipoRetorno BaseDeDatos::recent()
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}


#endif
