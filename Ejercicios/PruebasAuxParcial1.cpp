#include "PruebasAuxParcial1.h"

#ifndef PRUEBASAUXPARCIAL1_CPP
#define PRUEBASAUXPARCIAL1_CPP

bool PruebaPosicion(const char* inputLista, int x, const char* output, int& nroPrueba) {
	// PRUEBA POSICION
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Posicion " << nroPrueba++;
	
	int largo;

	std::ostringstream s;
	s << inputLista << ", " << x;
	char* inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	NodoLista* lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	lista = posicion(lista, x);
	largo = 0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(lista, solucion);
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		char* resultado = FrameworkA1::serializar(lista);
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
		delete[] resultado;
	}
	else {
		cout << " -> OK" << endl;
	}

	delete[] inputParametersFormated;
	FrameworkA1::destruir(lista);
	FrameworkA1::destruir(solucion);
	return resultadoOK;
}

bool PruebaEliminarPosiciones(const char* inputLista, int desde, int hasta, const char* output, int& nroPrueba) {
	// PRUEBA ELIMINAR POSICIONES
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Eliminar Posiciones " << nroPrueba++;

	int largo;

	std::ostringstream s;
	s << inputLista << ", " << desde << " - " << hasta;
	char* inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	NodoLista* lista = (NodoLista*)FrameworkA1::parsearColeccion(inputLista, largo);
	eliminarPosiciones(lista, desde, hasta);
	largo = 0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(lista, solucion);
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		char* resultado = FrameworkA1::serializar(lista);
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
		delete[] resultado;
	}
	else {
		cout << " -> OK" << endl;
	}

	delete[] inputParametersFormated;
	FrameworkA1::destruir(lista);
	FrameworkA1::destruir(solucion);
	return resultadoOK;
}

bool PruebaNivelDeElemento(const char* inputTree, int x, const int output, int& nroPrueba) 
{
	// PRUEBA NIVEL DE ELEMENTO
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Nivel de Elemento " << nroPrueba++;
	std::ostringstream s;
	s << inputTree << ", " << x;
	char* inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoAG* arbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	NodoAG* copiaArbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	int resultado = nivelDeElemento(arbol, x);

	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(arbol, copiaArbol);
	bool resultadoOK = output == resultado;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta " << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}
	else if (parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
	}
	else {
		cout << " -> OK" << endl;
	}

	delete[] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(copiaArbol);
	return resultadoOK;
}


bool PruebaPiso(const char* inputTree, int x, const int output, int& nroPrueba)
{
	// PRUEBA PISO
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Piso " << nroPrueba++;
	int largo;

	std::ostringstream s;
	s << inputTree << ", " << x;
	char* inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputTree, largo);
	int resultado = piso(arbol , x);
	largo = 0;
	
	bool resultadoOK = output == resultado;
	
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		char* resultado = FrameworkA1::serializar(arbol);
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
		delete[] resultado;
	}
	else {
		cout << " -> OK" << endl;
	}

	delete[] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	return resultadoOK;
}

#endif