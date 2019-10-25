#ifndef PARCIAL1_H
#define PARCIAL1_H

#include <iostream>
using namespace std;
#include "Definiciones.h"

/*
Ejercicio 1 (12pts)

Considerando la definicion NodoLista.

a) Implementar la funcion iterativa "posicion" que dada una lista 'L' de tipo NodoLista* y un entero 'x', retorne un puntero
   al nodo de 'L' que contiene al elemento 'x'. Si 'x' no pertenece a la lista, en particular si la lista es vacia, el resultado debe ser NULL.
   Si el elemento 'x' esta repetido en , se debe retornar el puntero al primer nodo (de izquierda a derecha) de 'L' que contenga a 'x'.

b) Implemente una funcion "eliminarPosiciones" que dada una lista 'L' de tipo NodoLista* y dos enteros 'desde' y 'hasta', elimine de 'L'
   los nodos que estan entre las posiciones 'desde' y 'hasta' inclusive. Se asume que 1 <= 'desde' <= 'hasta'. 
   Si 'L' es vacia, la funcion no tendra efecto.

c) Calcule el orden del tiempo de ejecicion de las funciones anteriores.

*/

NodoLista* posicion(NodoLista* L, int x);

void eliminarPosiciones(NodoLista*& L, int desde, int hasta);

/*
Ejercicio 2 (6 pts)

Considerando la definicion de NodoAG.

Defina una funcion recursiva "nivelDeElemento" que, dados un arbol 'A' de tipo NodoAG y un entero 'x', retorne el nivel en el que se
encuentra 'x' en A. Si 'x' no esta el arbol (en particular si A es vacio) la funcion debe retornar 0. Si hay mas de una ocurrencia de 'x'
en A, se debe retornar el nivel de la ocurrencia mas profunda. Recuerde ue en un arbol no vacio la raiz esta en el nivel 1. 
No se permite recorrer el arbol mas de una vez.

*/

int nivelDeElemento(NodoAG* A, int x);


/*
Ejercicio 3 (7pts)

Considere la definicion de NodoAB

a) Defina una funcion "piso" que dado un NodoAB* 'a' y un entero 'x', retorne el mayor valor perteneciente al arbol que sea menor que 'x',
   en otras palabras, el valor inferior mas cercano a 'x'. Si el elemento 'x' pertenece al arbol, entonces retornar 'x'. Si el arbol es vacio
   o no existen valores menores en el arbol, retornar INT_MIN

b) Cual es el orden de tiempo de ejecicion en el peor caso y en el caso promedio de piso? Justifique brevemente en ambos casos.

*/

int piso(NodoAB* a, int x);


/*
Resultado: 18/25
*/

#endif