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
	void PruebasERROR();

	//void pruebaOK();
	//void pruebaOK1();

	void pruebasERROR1();
	void pruebasERROR2();
	void pruebasERROR3();
	void pruebasERROR4();
	void pruebasERROR5();
	void pruebasERROR6();

	void cargarBaseDeDatos(InterfazDelSistema *interfaz);
	void cargarTablas(InterfazDelSistema *interfaz);
};

#endif