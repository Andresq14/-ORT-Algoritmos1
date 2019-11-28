#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include "BaseDeDatos.h"
#include "Cadena.h"
#include "Tabla.h"
#include "ListaOrd.h"
#include "ListaOrdImp.h"
#include "ListaOrdImp2.h"
#include "Cola.h"
#include "ColaImp.h"

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
	
	//Constructores
	BaseDeDatos(unsigned int MAX_MODIFICADAS);
	BaseDeDatos(const BaseDeDatos &bd);
	
	//Destructor
	virtual ~BaseDeDatos();
	
	//PRE:
	//POS: Iguala la BD (this) con la BD pasada por parametro
	BaseDeDatos &operator=(const BaseDeDatos &bd);

	//PRE:
	//POS: Crea una tabla con el nombre pasada por parametro, si ya existe devuelve ERROR.
	TipoRetorno createTable(Cadena nombreTabla);

	//PRE:
	//POS: Borra el nombre de la tabla pasado por parametro en caso de existir, en caso contrario retorna ERROR
	TipoRetorno dropTable(Cadena nombreTabla);

	//PRE:
	//POS:	Crea la columna de nombre nombreCol y calificador caificadoColumna en la tabla pasada por paramtro, en caso de error retorna el mismo
	TipoRetorno addCol(Cadena nombreTabla, Cadena nombreCol, CalifCol calificadorColumna);

	//PRE:
	//POS: Elimina la columna indicada, de la tabla indicada en caso de existir. De lo contrario devuelve ERROR.
	TipoRetorno dropCol(Cadena nombreTabla, Cadena nombreCol);

	//PRE:
	//POS: Inserta en la tabla indicada, los valores pasados por parametro. En caso de error, retorna el mismo.
	TipoRetorno insertInto(Cadena nombreTabla, Cadena valoresTupla);

	//PRE:
	//POS: De la tabla indicada, elimia todas las tuplas que cumplan la condicion indicada. En caso de error, retorna el mismo.
	TipoRetorno deleteFrom(Cadena nombreTabla, Cadena condicionEliminar);

	//PRE:
	//POS: Imprime el nombre de todas las tablas ordenadas ascendentemente, en caso contrario, se indica que la lista es vacia.
	TipoRetorno printTables() const;

	//PRE:
	//POS: Imprime el nombre de todas las columnas ordenadas por orden de ingreso, en caso contrario, se indica que la lista es vacia.
	TipoRetorno printMetadata(Cadena nombreTabla) const;

	//PRE:
	//POS: Imprime el nombre de las columnas y los datos de las tuplas ordenadas por PK en caso de existir. Si es vacia, se indica lo mismo.
	TipoRetorno printDataTable(Cadena nombreTabla) const;

	//PRE:
	//POS: Crea una nueva tabla (nombreTabla3) con el resultado de la union de ambas tablas, en caso de que las primeras dos existan.
	TipoRetorno join(Cadena nombreTabla1, Cadena nombreTabla2, Cadena nombreTabla3);

	//PRE:
	//POS: Imprime el nombre de las ultimas "max" tablas modificadas, sin repetir. 
	TipoRetorno recent();
	
private:
	//Constructor por defecto.
	BaseDeDatos();

	//Atributos
	ListaOrd<Tabla>* tables;
	Cola<Tabla>* historic;
	unsigned int max;
};

#endif