#ifndef PRUEBASAUXSEM5_H
#define PRUEBASAUXSEM5_H

#include <sstream>
#include <string>
#include <iostream>
using namespace std;
#include "FuncAux.h"
#include "EjerciciosSem5.h"
#include "Definiciones.h"

bool PruebaEliminarNesimoDesdeElFinal(const char* inputLista, int n, const char* output, int &nroPrueba);
bool PruebaListaOrdenadaInsertionSort(const char* inputLista, const char* output, int &nroPrueba);
bool PruebaListaOrdenadaSelectionSort(const char* inputLista, const char* output, int &nroPrueba);
bool PruebaInvertirParcial(const char* inputLista, const char* output, int &nroPrueba);
bool PruebaIntercalarIter(const char* inputLista1, const char* inputLista2, const char* output, int &nroPrueba);
bool PruebaIntercalarRec(const char* inputLista1, const char* inputLista2, const char* output, int &nroPrueba);
bool PruebaInsComFin(const char* inputLista, int n, const char* output, int &nroPrueba);
bool PruebaEXOR(const char* inputLista1, const char* inputLista2, const char* output, int &nroPrueba);
bool PruebaEliminarDuplicadosListaOrdenadaDos(const char* inputLista, const char* output, int &nroPrueba);
bool PruebaPalindromo(const char* inputLista, bool output, int &nroPrueba);
bool PruebaEliminarSecuencia(const char* inputListaOriginal, const char* inputSecuenciaAEliminar, const char* output, int &nroPrueba);
bool PruebaMoverNodo(const char* inputListaOriginal, unsigned int inicial, unsigned int final, const char* output, int &nroPrueba);

#endif