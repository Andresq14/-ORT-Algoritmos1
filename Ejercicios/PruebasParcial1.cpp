#include "PruebasParcial1.h"

#ifndef PRUEBASPARCIAL1_CPP
#define PRUEBASPARCIAL1_CPP

void PruebasParcial1()
{
	int nroPrueba = 1;
	int correctos = 0, error = 0;
	int correctosTotal = 0, errorTotal = 0, ejCorrectosTotal = 0, ejErrorTotal = 0;

	FrameworkA1::ver(PruebaPosicion("()", 0, "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPosicion("(1)", 2, "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPosicion("(1,2,3,4,5)", 3, "(3,4,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPosicion("(1,2,3,1)", 1, "(1,2,3,1)", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaPosicion", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaEliminarPosiciones("()", 0, 0, "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarPosiciones("(1,2,3,4)", 6, 7, "(1,2,3,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarPosiciones("(1,2,3,4,5)", 2, 3, "(1,4,5)", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaEliminarPosiciones", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaNivelDeElemento("{{1,2,5,#,#,3,#,#,6,7,#,8}}", 1, 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelDeElemento("{{1,2,5,#,#,3,#,#,6,7,#,8}}", 8, 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelDeElemento("{{1,2,5,#,#,3,#,#,6,7,#,8}}", 5, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelDeElemento("{{1,2,1,#,#,3,#,#,6,7,#,8}}", 1, 3, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaNivelDeElemento", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaPiso("{10, 5, 16, 3, 8, 12, 23}", 7, 5, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPiso("{10, 5, 16, 3, 8, 12, 23}", 16, 16, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPiso("{10, 5, 16, 3, 8, 12, 23}", 50, 23, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPiso("{10, 5, 16, 3, 8, 12, 23}", -5, INT_MIN, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaPiso", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);
}


#endif