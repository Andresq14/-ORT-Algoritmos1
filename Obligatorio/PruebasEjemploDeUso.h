#ifndef EJEMPLODEUSO_H
#define EJEMPLODEUSO_H


#include "Prueba.h"
#include "ConductorPrueba.h"
#include "InterfazDelSistemaImp.h"

class PruebasEjemploDeUso : public Prueba  
{

public:
	PruebasEjemploDeUso(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUso();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;

	void PruebasOK();
	void PruebasError();

	void pruebaOK1();
	void pruebaOK2();
	void pruebaOK3();
	void pruebaOK4();
	void pruebaOK5();
	void pruebaOK6();
	void pruebaOK7();
	void pruebaOK8();
	void pruebaOK9();

	void pruebasERROR1();
	void pruebasERROR2();
	void pruebasERROR3();
	void pruebasERROR4();
	void pruebasERROR5();
	void pruebasERROR6();
	void pruebasERROR7();
	void pruebasERROR8();


	void cargarBaseDeDatos(InterfazDelSistema *interfaz);
	void cargarTablas(InterfazDelSistema *interfaz);
};

#endif