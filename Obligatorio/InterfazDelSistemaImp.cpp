#include "InterfazDelSistemaImp.h"

#ifndef INTERFAZ_DEL_SISTEMA_IMP_CPP
#define INTERFAZ_DEL_SISTEMA_IMP_CPP

// Inicialización de los atributos
InterfazDelSistemaImp::InterfazDelSistemaImp(unsigned int MAX_MODIFICADAS)
{
	baseDeDatos = new BaseDeDatos(MAX_MODIFICADAS);
}

// Eliminación de los objetos creados con "new"
InterfazDelSistemaImp::~InterfazDelSistemaImp()
{
	delete baseDeDatos;
}

TipoRetorno InterfazDelSistemaImp::createTable(const char *nombreTabla)
{
	return baseDeDatos->createTable(nombreTabla);
}

TipoRetorno InterfazDelSistemaImp::dropTable(const char *nombreTabla)
{
	return baseDeDatos->dropTable(nombreTabla);
}

TipoRetorno InterfazDelSistemaImp::addCol(const char *nombreTabla, const char *nombreCol, CalifCol calificadorColumna)
{
	return baseDeDatos->addCol(nombreTabla, nombreCol, calificadorColumna);
}

TipoRetorno InterfazDelSistemaImp::dropCol(const char *nombreTabla, const char *nombreCol)
{
	return baseDeDatos->dropCol(nombreTabla, nombreCol);
}

TipoRetorno InterfazDelSistemaImp::insertInto(const char *nombreTabla, const char *valoresTupla)
{
	return baseDeDatos->insertInto(nombreTabla, valoresTupla);
}

TipoRetorno InterfazDelSistemaImp::deleteFrom(const char *nombreTabla, const char *condicionEliminar)
{
	return baseDeDatos->deleteFrom(nombreTabla, condicionEliminar);
}

TipoRetorno InterfazDelSistemaImp::printTables()
{
	return baseDeDatos->printTables();
}

TipoRetorno InterfazDelSistemaImp::printMetadata(const char *nombreTabla)
{
	return baseDeDatos->printMetadata(nombreTabla);
}

TipoRetorno InterfazDelSistemaImp::printDataTable(const char *nombreTabla)
{
	return baseDeDatos->printDataTable(nombreTabla);
}

TipoRetorno InterfazDelSistemaImp::join(const char *nombreTabla1, const char *nombreTabla2, const char *nombreTabla3)
{
	return baseDeDatos->join(nombreTabla1, nombreTabla2, nombreTabla3);
}

TipoRetorno InterfazDelSistemaImp::recent()
{
	return baseDeDatos->recent();
}


#endif