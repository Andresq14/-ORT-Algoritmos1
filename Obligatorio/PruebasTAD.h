#ifndef PRUEBASTAD_H
#define PRUEBASTAD_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "Cadena.h"
#include "ListaPosImp.h"
#include "ListaOrdImp.h"
#include "ListaOrdImp2.h"

class PruebasTAD : public Prueba  
{

public:
	PruebasTAD(ConductorPrueba* conductor);
	virtual ~PruebasTAD();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre() const;

private:
	ManejadorImpresionPrueba mImpresion;

	void pruebaListaPos();
	void pruebaListaOrd(ListaOrd<int>* l);
};

#endif