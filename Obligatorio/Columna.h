#ifndef COLUMNA_H
#define COLUMNA_H

#include "Cadena.h"
#include "CalifCol.h"

class Columna;
ostream& operator<<(ostream& out, const Columna& c);

class Columna
{
public:

	//Constructor con parametros
	Columna(Cadena& nombreCol, CalifCol& calificador);

	Columna(Cadena& nombreCol);

	Columna(CalifCol calificador);

	//Constructor copia
	Columna(const Columna& c);

	//Destructor
	virtual ~Columna();

	// Operador de asignacion
	Columna& operator=(const Columna& c);

	// Operadores de comparacion (comparan el nombre de la tabla)
	bool operator==(const Columna& c) const;
	bool operator!=(const Columna& c) const;
	bool operator<(const Columna& c) const;
	bool operator>(const Columna& c) const;
	bool operator<=(const Columna& c) const;
	bool operator>=(const Columna& c) const;

	// Retorna el nombre de la tabla
	const Cadena& GetNombre() const;
	const CalifCol& GetCalificador() const;
	
private:

protected:
	//Constructor sin parametros
	Columna();

	//Atributos 
	Cadena name;
	CalifCol qualifier;

};


#endif
