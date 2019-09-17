#include "EjerciciosSem3.h"

#ifndef EJERCICIOSSEM3_CPP
#define EJERCICIOSSEM3_CPP

#pragma region Auxiliares

/*
	PRE: Recive una matriz de char, cantidad de columnas y cantidad de filas
	POS: Imprime la matriz pasada por parametro
*/
void imprimirMatriz(char** map, int col, int fil)
{
	for (int row = 0; row < fil; row++)
	{
		for (int column = 0; column < col; column++)
		{
			cout << map[row][column];
		}
	}
}

/*
	PRE: Recive un string
	POS: Retorna la cantidad de caracteres en dicho string sin contar el '\0'
*/
unsigned int stringLength(char* string)
{
	unsigned int index = 0;

	while (string[index] != '\0')
		index++;

	return index;
}

/*
	PRE: Recive dos strings y el largo del mismo
	POS: Copia el primer string en el segundo
*/
void stringCopy_s(char* dest, int length, char* orig)
{
	assert( (stringLength(dest)+1) >= length );

	for (int i = 0; i < length; i++)
		dest[i] = orig[i];
}

/*
	PRE: Recive dos string
	POS: Retorna true si el primer string contiene al segundo
*/
bool stringContains(char* word, char* string)
{
	int wordLen = stringLength(word);
 	int strLen = stringLength(string);
	int indexW = 0;
	int indexS = 0;
	int last = 0;

	while (indexW < wordLen && indexS != strLen) 
	{
		if (word[indexW] == string[indexS]) 
		{
			indexW++;
			indexS++;
		}
		else
		{
			last++;
			indexW = last;
			indexS = 0;
		}
	}

	return strLen == indexS;
}


/*
	PRE: Recive un numero, una lista y su largo
	POS: Retorna true si el numero se encuentra en la lista
*/
bool intContains(int numb, int* list, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (list[i] == numb)
			return true;
	}
	return false;
}

/*
	PRE: Recive dos strings
	POS: Retorna true si el primero es mayor al segundo
*/
bool stringCompare(char* first, char* second)
{
	int lenF = stringLength(first);
	int lenS = stringLength(second);

	int len = lenF > lenS ? lenS : lenF;
	
	for (int i = 0; i < len; i++)
	{
		if (first[i] < second[i])
			return false;
		if (first[i] > second[i])
			return true;
	}
	return lenF > lenS;
}

/*
	PRE: 
	POS: Retorna una matriz con las islas macadas con O
*/
void ocultarIsla(char** mapa, int c, int r, int col, int fil)
{
	if (r < 0)
		return;
	if (r >= col)
		return;
	if (c < 0)
		return;
	if (c >= fil)
		return;
	if (mapa[r][c] != 'T')
		return;


	mapa[r][c] = 'O';
	ocultarIsla(mapa, (c - 1), r, col, fil); //arriba
	ocultarIsla(mapa, (c + 1), r, col, fil); //abajo
	ocultarIsla(mapa, c, (r - 1), col, fil); //izquirda
	ocultarIsla(mapa, c, (r + 1), col, fil); //derecha
	ocultarIsla(mapa, (c - 1), (r + 1), col, fil); //arriba derecha
	ocultarIsla(mapa, (c - 1), (r - 1), col, fil); //arriba izquierda
	ocultarIsla(mapa, (c + 1), (r + 1), col, fil); //abajo derecha
	ocultarIsla(mapa, (c + 1), (r - 1), col, fil); //abajo izquierda
}

/*
	PRE: Recive una lista de strings y su largo
	POS: Retorna una copia de la primera, incluyendo sus elementos
*/
char** copyCharVec(char** vec, int length)
{
	char** newVec = new char* [length];
	
	for (int i = 0; i < length; i++)
	{
		int len = stringLength(vec[i]) + 1;
		char* str = new char[len];
		stringCopy_s(str, len, vec[i]);
		newVec[i] = str;
	}

	return newVec;
}

/*
	PRE: Recive dos listas ordenadas de ints y sus correspondientes largos
	POS: Retorna una lista ordenada con el merge de las anteriores
*/
int* mergeSortInts(int* v1, int* v2, int l1, int l2)
{
	int* vec = new int[l1 + l2];

	//Regla de la Suma: O(1)
	int index1 = 0; //O(1)
	int index2 = 0; //O(1)
	int len1 = l1; //O(1)
	int len2 = l2; //O(1)

	//Sumatoria de todas las iteraciones
	for (int i = 0; i < (l1 + l2); i++) //O(l1+l2)
	{
		//Regla del producto: O(1)
		if (len1 == 0) //O(1)
		{
			vec[i] = v2[index2]; //O(1)
			len2--; //O(1)
			index2++; //O(1)
		}
		else if (len2 == 0) //O(1)
		{
			vec[i] = v1[index1]; //O(1)
			len1--; //O(1)
			index1++; //O(1) 
		}
		else if (v1[index1] <= v2[index2]) //O(1)
		{
			vec[i] = v1[index1]; //O(1)
			len1--; //O(1)
			index1++; //O(1)
		}
		else
		{
			vec[i] = v2[index2]; //O(1)
			len2--; //O(1)
			index2++; //O(1) 
		}
	}

	return vec;
}

/*
	PRE: Recive un vector de enteros, posicion de inicio, fin y la mitad de la lista.
	POS: Ordena de forma ascendiente los elementos de dicha lista.
*/
void merge(int* vec, int inicio, int medio, int fin)
{
	int* tmp = new int[fin - inicio + 1];
	int ini = inicio;
	int med = medio + 1;
	int count = 0;

	while (ini <= medio && med <= fin)
	{
		if (vec[ini] <= vec[med])
		{
			tmp[count] = vec[ini];
			ini++;
			count++;
		}
		else
		{
			tmp[count] = vec[med];
			med++;
			count++;
		}
	}

	while (ini <= medio)
	{
		tmp[count] = vec[ini];
		ini++;
		count++;
	}

	while (med <= fin)
	{
		tmp[count] = vec[med];
		med++;
		count++;
	}

	for (int i = inicio; i <= fin; i++)
	{
		vec[i] = tmp[i - inicio];
	}

	delete[] tmp;
}

/*
	PRE: Recive un vector de enteros, posicion de inicio y fin.
	POS: Ordena de forma ascendiente los elementos de dicha lista.
*/
void mergeSort(int* vec, int inicio, int fin)
{
	if (inicio < fin)
	{
		int medio = (inicio + fin) / 2;
		mergeSort(vec, inicio, medio);
		mergeSort(vec, medio + 1, fin);
		merge(vec, inicio, medio, fin);
	}
}

/*
	PRE: Recive un string, un separador y el largo de ese string
	POS: Retorna la cantidad de particiones del string con dicho separador.
*/
unsigned int countSubstrings(char* str, char separador, int length)
{
	char* aux = new char[length];
	stringCopy_s(aux, length, str);

	char* stringSplitted = strtok(aux, &separador);
	
	if (stringSplitted == NULL)
	{
		return 0;
	}

	unsigned int len; 
	for (len = 0; stringSplitted != NULL; len++)
	{
		stringSplitted = strtok(NULL, &separador);
	}

	return len;
}

#pragma endregion

char* invertirCase(char* palabra)
{
	unsigned int len = stringLength(palabra) + 1; //Largo de la palabra + 1 (\0)
	char* word = new char[len]; // Creo un vector para el nuevo String con el largo obtenido
	stringCopy_s(word, len, palabra);
	
	unsigned int index = 0;

	while (word[index] != '\0')
	{
		if (word[index] >= 'a' && word[index] <= 'z') // Es minuscula
			word[index] -= 32;
		else if (word[index] >= 'A' && word[index] <= 'Z') // es mayuscula
			word[index] += 32;
		
		index++;
	}
	
	return word;
}

int islas(char** mapa, int col, int fil)
{
	int cant = 0;
	
	for (int c = 0; c < fil; c++) //column
	{
		for (int r = 0; r < col; r++) //row
		{
			if (mapa[r][c] == 'T')
			{
				ocultarIsla(mapa, c, r, col, fil);
				cant++;
			}
		}
	}

	//Desocultar islas
	for (int c = 0; c < fil; c++)
	{
		for (int r = 0; r < col; r++)
		{
			if (mapa[r][c] == 'O')
				mapa[r][c] = 'T';
		}
	}

    return cant;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	unsigned int count = 0;

	for (int i = 0; i < largoVecStr; i++)
		if (stringContains(vecStr[i], substr))
			count++;

    return count;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	char** newVec = copyCharVec(vecStr, largoVecStr);

	bool ordenado;

	do
	{
		ordenado = true;
		for (int i = 0; i < largoVecStr; i++)
		{
			if ((i + 1) >= largoVecStr)
				continue;

			if (stringCompare(newVec[i], newVec[i + 1]))
			{
				char* aux = newVec[i];
				newVec[i] = newVec[i + 1];
				newVec[i + 1] = aux;
				ordenado = false;
			}
		}
	} while (!ordenado); 

	return newVec;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2)
{
	if ( (l1 + l2) == 0)
		return NULL;

	int* vec = mergeSortInts(v1, v2, l1, l2);

	return vec;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	if (v1 == NULL)
		return true;

	for (int i = 0; i < l1; i++)
	{
		if (!intContains(v1[i], v2, l2))
			return false;
	}

	return true;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	unsigned int vecLen = stringLength(str) + 1;
	unsigned int len = countSubstrings(str, separador, vecLen);

	if (len == 0)
	{
		largoRet = 0;
		return NULL;
	}

	char* aux = new char[vecLen];
	stringCopy_s(aux, vecLen, str);
	char* stringSplitted = strtok(aux, &separador);

	largoRet = len;

	char** mat = new char* [len];

	for (int i = 0; stringSplitted != NULL; i++)
	{
		unsigned int charLen = stringLength(stringSplitted) + 1;
		char* cpy = new char[charLen];
		stringCopy_s(cpy, charLen, stringSplitted);

		mat[i] = cpy;
		stringSplitted = strtok(NULL, &separador);
	}

	return mat;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	mergeSort(vector, 0, (largo - 1));
}

#endif