#include "BaseDeDatos.h"

#ifndef BASEDEDATOS_CPP
#define BASEDEDATOS_CPP

BaseDeDatos::BaseDeDatos() {
	assert(false);
}

BaseDeDatos::BaseDeDatos(unsigned int MAX_MODIFICADAS) {
	tables = new ListaOrdImp2<Tabla>;
}

BaseDeDatos::BaseDeDatos(const BaseDeDatos &bd) 
{
	assert(false);
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
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se puede eliminar la tabla, el nombre no existe." << endl;
		return ERROR;
	}

	tables->Borrar(nombreTabla);
	
	return OK;
}

TipoRetorno BaseDeDatos::addCol(Cadena nombreTabla, Cadena nombreCol, CalifCol calificadorColumna)
{
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se puede agregar la columna, nombreTabla no existe." << endl;
		return ERROR;
	}

	return (tables->RecuperarInseguro(nombreTabla)).addCol(nombreCol, calificadorColumna);;
}

TipoRetorno BaseDeDatos::dropCol(Cadena nombreTabla, Cadena nombreCol)
{
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se puede eliminar la columna, nombreTabla no existe." << endl;
		return ERROR;
	}
	
	return (tables->RecuperarInseguro(nombreTabla).delCol(nombreCol));
}

TipoRetorno BaseDeDatos::insertInto(Cadena nombreTabla, Cadena valoresTupla)
{
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se puede agregar la tupla, nombreTabla no existe." << endl;
		return ERROR;
	}
	if (valoresTupla.Length() == 0)
	{
		cout << "ERROR: No se puede agregar la tupla, valoresTupla es vacio. " << endl;
		return ERROR;
	}


	return tables->RecuperarInseguro(nombreTabla).insertInto(valoresTupla);
}

TipoRetorno BaseDeDatos::deleteFrom(Cadena nombreTabla, Cadena condicionEliminar)
{
	if (!tables->Existe(nombreTabla)) {
		cout << "ERROR: No se puede eliminar la tupla, nombreTabla no existe." << endl;
		return ERROR;
	}	
	return tables->RecuperarInseguro(nombreTabla).deleteFrom(condicionEliminar);
}

TipoRetorno BaseDeDatos::printTables() const
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

TipoRetorno BaseDeDatos::printMetadata(Cadena nombreTabla) const
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

TipoRetorno BaseDeDatos::printDataTable(Cadena nombreTabla) const
{
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se pueden imprimir los datos, nombreTabla no existe." << endl;
		return ERROR;
	}

	Tabla table(tables->Recuperar(nombreTabla));
	table.printDataTable();

	return OK;
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
