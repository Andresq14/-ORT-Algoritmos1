#ifndef INTERFAZ_DEL_SISTEMA_IMP_H
#define INTERFAZ_DEL_SISTEMA_IMP_H

#include "Constantes.h"
#include "InterfazDelSistema.h"
#include <assert.h>
#include "BaseDeDatos.h"


class InterfazDelSistemaImp  : public InterfazDelSistema
{
public:
	
	InterfazDelSistemaImp(unsigned int MAX_MODIFICADAS);
	~InterfazDelSistemaImp();

	TipoRetorno createTable(const char *nombreTabla);
	TipoRetorno dropTable(const char *nombreTabla);
	TipoRetorno addCol(const char *nombreTabla, const char *nombreCol, CalifCol calificadorColumna);
	TipoRetorno dropCol(const char *nombreTabla, const char *nombreCol);
	TipoRetorno insertInto(const char *nombreTabla, const char *valoresTupla);
	TipoRetorno deleteFrom(const char *nombreTabla, const char *condicionEliminar);
	TipoRetorno join(const char *nombreTabla1, const char *nombreTabla2, const char *nombreTabla3);
	TipoRetorno printTables();
	TipoRetorno printMetadata(const char *nombreTabla);
	TipoRetorno printDataTable(const char *nombreTabla);
	TipoRetorno recent();

private:
	InterfazDelSistemaImp() { assert(false); }
	InterfazDelSistemaImp(const InterfazDelSistemaImp &i) { assert(false); }
	InterfazDelSistemaImp &operator=(const InterfazDelSistemaImp &i) { assert(false); return *new InterfazDelSistemaImp(); }

	BaseDeDatos * baseDeDatos;
	
	
};

#endif
