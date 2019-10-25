#include "ConductorPrueba.h"

ConductorPrueba::ConductorPrueba()
{
	nroPrueba = 0;
	firstTime = true;
}

ConductorPrueba::~ConductorPrueba()
{
}

void ConductorPrueba::correrPrueba(bool paraParseo)
{
	ManejadorSalidaPrueba msp = getManejadorSalida();
	msp.crearDirectorio(getNombre());

	correrPruebaConcreta();
	
	//msp.setSalidaArchivo("Resultados Totales.txt");
	//ManejadorImpresionPrueba mip = getManejadorImpresion();
	//mip.imprimirTotalResultados(getEstadisticaGlobal(), paraParseo);
	msp.setSalidaPantalla();
}

void ConductorPrueba::correrPrueba(const char *nombrePrueba, bool paraParseo)
{
	ManejadorSalidaPrueba msp = getManejadorSalida();
	if (firstTime)
	{
		msp.crearDirectorio(getNombre());
		firstTime = false;
	}
	correrPruebaConcreta(nombrePrueba);

	//msp.setSalidaArchivo("Resultados Totales.txt");
	//ManejadorImpresionPrueba mip = getManejadorImpresion();
	//mip.imprimirTotalResultados(getEstadisticaGlobal(), paraParseo);
	msp.setSalidaPantalla();
}

void ConductorPrueba::ver(TipoRetorno retorno, TipoRetorno retornoEsperado, const char* comentario)
{
	getManejadorImpresion().imprimirResultado(retorno,retornoEsperado,comentario, false);

	getEstadisticaGlobal().actualizarEstadisticas(retorno,retornoEsperado);
}

void ConductorPrueba::ver2(TipoRetorno retorno, TipoRetorno retornoEsperado, const char* comentario)
{
	cout << endl << "-!-" << this->nroPrueba++ << "::" << 0 << "-";
	getManejadorImpresion().imprimirResultado(retorno, retornoEsperado, comentario, true);

	getEstadisticaGlobal().actualizarEstadisticas(retorno,retornoEsperado);
}

void ConductorPrueba::ver3(const char* comentario)
{
	cout << endl << "-!-" << this->nroPrueba++ << "::" << 0 << "-";
	getManejadorImpresion().imprimirResultado(comentario, true);
}

void ConductorPrueba::ver3(const char* comentario, double puntaje)
{
	cout << endl << "-!-" << this->nroPrueba++ << "::" << puntaje << "-";
	getManejadorImpresion().imprimirResultado(comentario, true);
}

void ConductorPrueba::comenzarNuevaPrueba()
{
	nroPrueba = 0;
}

EstadisticaPrueba& ConductorPrueba::getEstadisticaGlobal()
{
	return estadisticaGlobal;
}

ManejadorImpresionPrueba ConductorPrueba::getManejadorImpresion()
{
	return ManejadorImpresionPrueba::getInstancia();
}

ManejadorSalidaPrueba ConductorPrueba::getManejadorSalida()
{
	return ManejadorSalidaPrueba::getInstancia();
}