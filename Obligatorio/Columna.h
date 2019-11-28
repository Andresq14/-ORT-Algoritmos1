#ifndef COLUMNA_H
#define COLUMNA_H

#include "Cadena.h"
#include "CalifCol.h"

class Columna;
ostream& operator<<(ostream& out, const Columna& c);

class Columna
{
public:

	//Constructores
	Columna(Cadena& nombreCol, CalifCol& calificador);
	Columna(Cadena& nombreCol);
	Columna(CalifCol calificador);
	Columna(const Columna& c);

	//Destructor
	virtual ~Columna();

	//PRE:
	//POST: Iguala la Columna (this) con la Columna pasada por parametro
	Columna& operator=(const Columna& c);

	// Operadores de comparacion
	bool operator==(const Columna& c) const;
	bool operator!=(const Columna& c) const;
	bool operator<(const Columna& c) const;
	bool operator>(const Columna& c) const;
	bool operator<=(const Columna& c) const;
	bool operator>=(const Columna& c) const;

	//PRE:
	//POS: Retorna el nombre de this
	const Cadena& GetNombre() const;

	//PRE:
	//POS: Retorna el calificador de this
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
