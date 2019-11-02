#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include "BaseDeDatos.h"
#include "Cadena.h"
#include "Tabla.h"
#include "ListaOrd.h"
#include "ListaOrdImp.h"


/*
	Todos los métodos retornan un enumerado correspondiente a si la operación
	se pudo realizar correctamente, hubo un error o no fue implementada.


	NOTA:
			Ver la especificación completa de los diferentes comandos en
			la letra del obligatorio.

*/

class BaseDeDatos
{
public:
	
	BaseDeDatos(unsigned int MAX_MODIFICADAS);
	BaseDeDatos(const BaseDeDatos &bd);
	
	virtual ~BaseDeDatos();
	
	BaseDeDatos &operator=(const BaseDeDatos &bd);

	TipoRetorno createTable(Cadena nombreTabla);
	TipoRetorno dropTable(Cadena nombreTabla);
	TipoRetorno addCol(Cadena nombreTabla, Cadena nombreCol, CalifCol calificadorColumna);
	TipoRetorno dropCol(Cadena nombreTabla, Cadena nombreCol);
	TipoRetorno insertInto(Cadena nombreTabla, Cadena valoresTupla);
	TipoRetorno deleteFrom(Cadena nombreTabla, Cadena condicionEliminar);
	TipoRetorno printTables();
	TipoRetorno printMetadata(Cadena nombreTabla);
	TipoRetorno printDataTable(Cadena nombreTabla);
	TipoRetorno join(Cadena nombreTabla1, Cadena nombreTabla2, Cadena nombreTabla3);
	TipoRetorno recent();

private:
	BaseDeDatos();

	ListaOrd<Tabla>* tables;

};

#endif