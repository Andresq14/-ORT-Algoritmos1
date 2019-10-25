#ifndef INTERFAZ_DEL_SISTEMA_H
#define INTERFAZ_DEL_SISTEMA_H

#include "Constantes.h"
#include "CalifCol.h"

/*	
	Todos los métodos retornan un enumerado correspondiente a si la operación 
	se pudo realizar correctamente, hubo un error o no fue implementada.
   

	NOTA:
			Ver la especificación completa de los diferentes comandos en 
			la letra del obligatorio.

*/

class InterfazDelSistema abstract
{
	public:

		virtual ~InterfazDelSistema() {};

		virtual TipoRetorno createTable(const char *nombreTabla) = 0;
		virtual TipoRetorno dropTable(const char *nombreTabla) = 0;
		virtual TipoRetorno addCol(const char *nombreTabla, const char *nombreCol, CalifCol calificadorColumna) = 0;
		virtual TipoRetorno dropCol(const char *nombreTabla, const char *nombreCol) = 0;
		virtual TipoRetorno insertInto(const char *nombreTabla, const char *valoresTupla) = 0;
		virtual TipoRetorno deleteFrom(const char *nombreTabla, const char *condicionEliminar) = 0;
		virtual TipoRetorno join(const char *nombreTabla1, const char *nombreTabla2, const char *nombreTabla3) = 0;
		virtual TipoRetorno printTables() = 0;
		virtual TipoRetorno printMetadata(const char *nombreTabla) = 0;
		virtual TipoRetorno printDataTable(const char *nombreTabla) = 0;
		virtual TipoRetorno recent() = 0;
};

#endif 