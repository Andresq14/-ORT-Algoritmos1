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
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
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
	if (!tables->Existe(nombreTabla1) || !tables->Existe(nombreTabla2))
	{
		cout << "ERROR: No se puede hacer join, nombreTabla1 o nombreTabla2 no existe." << endl;
		return ERROR;
	}
	if (tables->Existe(nombreTabla3))
	{
		cout << "ERROR: No se puede hacer join, nombreTabla3 ya existe." << endl;
		return ERROR;
	}

	Tabla tab1(tables->Recuperar(nombreTabla1));
	Tabla tab2(tables->Recuperar(nombreTabla2));

	if (tab1.GetColumnas().CantidadElementos() == 0 || tab2.GetColumnas().CantidadElementos() == 0)
	{
		cout << "ERROR: No se puede hacer join, nombreTabla1 y nombreTabla2 deben tener al menos una columna." << endl;
		return ERROR;
	}

	Columna colPk(PK);

	int posPkTab1 = tab1.GetColumnas().Posicion(colPk);
	int posPkTab2 = tab2.GetColumnas().Posicion(colPk);

	Columna col1(tab1.GetColumnas().ElementoPos(posPkTab1));
	Columna col2(tab2.GetColumnas().ElementoPos(posPkTab2));

	if (col1.GetNombre() != col2.GetNombre())
	{
		cout << "ERROR: No se puede hacer join, nombreTabla1 y nombreTabla2 no tienen el mismo nombre de columna PK." << endl;
		return ERROR;
	}

	Tabla tab3(nombreTabla3);
	TipoRetorno ret = tab3.join(tab1, tab2);

	if (ret == OK)
		tables->AgregarOrd(tab3);

	return OK;
}

TipoRetorno BaseDeDatos::recent()
{
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}


#endif
