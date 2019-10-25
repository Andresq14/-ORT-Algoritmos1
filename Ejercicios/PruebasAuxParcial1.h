#ifndef PRUEBASAUXPARCIAL1_H
#define PRUEBASAUXPARCIAL1_H

#include <sstream>
#include <string>
#include <iostream>
using namespace std;
#include "FuncAux.h"
#include "Parcial1.h"
#include "Definiciones.h"

bool PruebaPosicion(const char* inputLista, int x, const char* output, int& nroPrueba);

bool PruebaEliminarPosiciones(const char* inputLista, int desde, int hasta, const char* output, int& nroPrueba);

bool PruebaNivelDeElemento(const char* inputTree, int x, const int output, int& nroPrueba);

bool PruebaPiso(const char* inputTree, int x, const int output, int& nroPrueba);

#endif