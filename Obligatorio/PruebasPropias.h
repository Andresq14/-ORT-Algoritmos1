#ifndef PRUEBASPROPIAS_H
#define PRUEBASPROPIAS_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"

class PruebasPropias : public Prueba  
{

public:
	PruebasPropias(ConductorPrueba* conductor);
	virtual ~PruebasPropias();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre() const;

private:
	ManejadorImpresionPrueba mImpresion;


	void PruebasOK();

	void pruebaOK();
	void pruebaOK1();

	void cargarBaseDeDatos(InterfazDelSistema *interfaz);
	void cargarTablas(InterfazDelSistema *interfaz);
};

#endif