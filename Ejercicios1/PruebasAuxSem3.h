#ifndef PRUEBASAUXSEM3_H
#define PRUEBASAUXSEM3_H

#include "FuncAux.h"
#include "EjerciciosSem3.h"


bool PruebaInvertirCase(const char *substr, const char* output, int &nroPrueba);
bool PruebaIslas(const char* datosMapa, int col, int fil, int output, int &nroPrueba);
bool PruebaOcurrenciasSubstring(const char *stringVecStr, const char *substr, int output, int &nroPrueba);
bool PruebaOrdenarVecStr(const char* vecStr, const char* output, int &nroPrueba);
bool PruebaIntercalarVector(const char* vector1, const char* vector2, const char* vectorOutput, int &nroPrueba);
bool PruebaSubconjuntoVector(const char* vector1, const char* vector2, bool output, int &nroPrueba);
bool PruebaSplitStr(const char* entrada, char separador, const char* output, int &nroPrueba);
bool PruebaOrdenarVecIntMergeSort(const char* inputVector, const char* output, int&nroPrueba);

#endif