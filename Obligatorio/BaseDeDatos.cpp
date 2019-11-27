#include "BaseDeDatos.h"

#ifndef BASEDEDATOS_CPP
#define BASEDEDATOS_CPP

BaseDeDatos::BaseDeDatos() {
	assert(false);
}

BaseDeDatos::BaseDeDatos(unsigned int MAX_MODIFICADAS) {
	tables = new ListaOrdImp2<Tabla>;
	historic = new ColaImp<Tabla>;	
	max = MAX_MODIFICADAS;
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

//PRE: Recibe el nombre de la tabla a crear.
//POST: Si la tabla no existe crea la misma, de lo contrario devuelve ERROR.


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

//PRE: Recibe el nombre de la tabla a borrar.
//POST: Si la tabla existe borra la misma, de lo contrario devuelve ERROR.

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

//PRE: Recibe el nombre de la tabla, el nombre de la columna y su calificador.
//POST: Sí existe la tabla, no hay una columna con el mismo nombre, si el calificador es PK y la tabla no tiene una columna PK se agrega la columna.
//      De lo contrario devuelve ERROR.

TipoRetorno BaseDeDatos::addCol(Cadena nombreTabla, Cadena nombreCol, CalifCol calificadorColumna)
{
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se puede agregar la columna, nombreTabla no existe." << endl;
		return ERROR;
	}

	historic->Encolar(nombreTabla);

	return (tables->RecuperarInseguro(nombreTabla)).addCol(nombreCol, calificadorColumna);
}

//PRE: Recibe el nombre de la tabla y el nombre de la columna.
//POST: Sí existe la tabla y la columna se elimina la columna. De lo contrario devuelve ERROR.

TipoRetorno BaseDeDatos::dropCol(Cadena nombreTabla, Cadena nombreCol)
{
	if (!tables->Existe(nombreTabla))
	{
		cout << "ERROR: No se puede eliminar la columna, nombreTabla no existe." << endl;
		return ERROR;
	}
	
	historic->Encolar(nombreTabla);

	return (tables->RecuperarInseguro(nombreTabla).delCol(nombreCol));
}

//PRE: Recibe el nombre de la tabla y los valores a insertar.
//POST: Si existe la tabla y los valores que vienen por parametro no estan vacios inserta la tupla.

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

	historic->Encolar(nombreTabla);

	return tables->RecuperarInseguro(nombreTabla).insertInto(valoresTupla);
}

//PRE: Recibe el nombre de la tabla y la condición a eliminar.
//POST: Si la tabla existe y se cumple la condicion para alguna de las tuplas, se elimina la misma.

TipoRetorno BaseDeDatos::deleteFrom(Cadena nombreTabla, Cadena condicionEliminar)
{
	if (!tables->Existe(nombreTabla)) {
		cout << "ERROR: No se puede eliminar la tupla, nombreTabla no existe." << endl;
		return ERROR;
	}	

	historic->Encolar(nombreTabla);

	return tables->RecuperarInseguro(nombreTabla).deleteFrom(condicionEliminar);
}

//PRE: --
//POST: Imprime los nombres de las tablas de la base de datos, ordenados alfabéticamente de menor a mayor.
//      Si no hay tablas devuelve “no hay tablas en la base de datos”.

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

//PRE: Recibe el nombre de la tabla
//POST: Si la tabla existe imprime el nombre de las columnas, si la tabla no existe devuelve ERROR.

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

//PRE: Recibe el nombre de la tabla
//POST: Si existe a tabla muestra los datos de la misma, si la tabla no existe devuelve ERROR.

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

//PRE: Recibe el nombre de las 2 tablas de las cales se hace el JOIN y el nombre de la tabla resultante.
//POST: En caso que existan las dos tablas y el nombre de la tabla resultante no esta utilizado en otra tabla, se crea la nueva tabla con el resultado de la operacion.
//      Si no se cumplen estas condiciones, devuelve ERROR.

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

	for (Iterador<Columna> i = tab1.GetColumnas().GetIterador(); !i.EsFin(); i++)
	{
		if(i.Elemento().GetCalificador() != PK)
			if (tab2.GetColumnas().Existe(i.Elemento()))
			{
				cout << "ERROR: No se puede hacer join, nombreTabla1 y nombreTabla2 comparten un nombre de columna distinto a la PK." << endl;
				return ERROR;
			}
	}
	

	Tabla tab3(nombreTabla3);
	TipoRetorno ret = tab3.join(tab1, tab2);

	if (ret == OK)
		tables->AgregarOrd(tab3);

	return OK;
}

TipoRetorno BaseDeDatos::recent()
{
	cout << "Listado de tablas recientes:" << endl;

	if (this->historic->EsVacia())
	{
		cout << "No hay tablas modificadas recientemente." << endl;
	}
	else
	{
		Cola<Tabla>* col = this->historic;
		ListaPos<Tabla>* lis = new ListaPosImp<Tabla>;

		int len = col->CantidadElementos() > max ? max : col->CantidadElementos();

		for (int i = 0; i < len; i++)
		{
			lis->AgregarFin(col->Desencolar());
		}
		for (unsigned int i = 0; i < lis->CantidadElementos(); i++)
		{
			cout << lis->ElementoPos(i) << endl;
		}

		delete col;
		delete lis;
	}

	return OK;
}


#endif
