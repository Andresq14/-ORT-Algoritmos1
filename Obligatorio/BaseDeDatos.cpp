#include "BaseDeDatos.h"

#ifndef BASEDEDATOS_CPP
#define BASEDEDATOS_CPP


BaseDeDatos::BaseDeDatos() {
	assert(false);
}

BaseDeDatos::BaseDeDatos(unsigned int MAX_MODIFICADAS) {
	tables = new ListaOrdImp<Tabla>;
}

BaseDeDatos::BaseDeDatos(const BaseDeDatos &bd) {
	assert(false);
	/*
		Quiero que el programa se caiga, 
		dado que el metodo no deberia de utilizarse
	*/
}

BaseDeDatos::~BaseDeDatos() {
	delete tables;
}

BaseDeDatos &BaseDeDatos::operator=(const BaseDeDatos &bd) {
	if (this != &bd) {
		assert(false);
	}
	return *this;
}

TipoRetorno BaseDeDatos::createTable(Cadena nombreTabla)
{
	if (tables->Existe(nombreTabla))
	{
		cout << "ERROR:	No se puede crear la tabla, el nombre ya existe." << endl;
		return ERROR;
	}

	Tabla table(nombreTabla);
	tables->AgregarOrd(table);

	return OK;
}

TipoRetorno BaseDeDatos::dropTable(Cadena nombreTabla)
{
	if (tables->EsVacia()) return OK;

	//TODO
	/*
		Cambiar metodo "Recuperar" para que retorne NULL en caso de que no exista
		y en caso positivo, retorne el nodo, asi no recorrer la lista dos veces.
	*/

	if (!tables->Existe(nombreTabla))
	{
		cout << "No se puede eliminar la tabla, el nombre no existe." << endl;
		return ERROR;
	}

	Tabla table = tables->RecuperarInseguro(nombreTabla);
	tables->Borrar(table);
	
	return OK;
}

TipoRetorno BaseDeDatos::addCol(Cadena nombreTabla, Cadena nombreCol, CalifCol calificadorColumna)
{
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se puede agregar la columna, nombreTabla no existe." << endl;
		return ERROR;
	}

	Tabla table = tables->RecuperarInseguro(nombreTabla);

	return table.addCol(nombreCol, calificadorColumna);;
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
	cout << "Listado de tablas:" << endl << endl;

	if (tables->EsVacia())
	{
		cout << "No hay tablas creadas" << endl;
	}
	else
	{
		for ( Iterador<Tabla> i = tables->GetIterador(); !i.EsFin() ; i++)
			cout << i.Elemento() << endl;
	}

	return OK;
}

TipoRetorno BaseDeDatos::printMetadata(Cadena nombreTabla)
{
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se puede imprimir el esquema, nombreTabla no existe." << endl;
		return ERROR;
	}

	cout << "Listado de esquema de la tabla " << nombreTabla << ":" << endl << endl;

	Tabla table = tables->Recuperar(nombreTabla);

	table.printMetadata();

	return OK;
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
