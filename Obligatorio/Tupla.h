#ifndef TUPLA_H
#define TUPLA_H

#include "Cadena.h"
#include "ListaPos.h"
#include "ListaPosImp.h"

class Tupla;
ostream& operator<<(ostream& out, const Tupla& t);

class Tupla
{

public:
	
	Tupla(ListaPos<Cadena>* dato);

	Tupla(const Tupla& tupla);

	virtual ~Tupla();
	
	// Operador de asignacion
	Tupla& operator=(const Tupla& t);

	// Operadores de comparacion (comparan el nombre de la tabla)
	bool operator==(const Tupla& t) const;
	bool operator!=(const Tupla& t) const;
	bool operator<(const Tupla& t) const;
	bool operator>(const Tupla& t) const;
	bool operator<=(const Tupla& t) const;
	bool operator>=(const Tupla& t) const;

	const ListaPos<Cadena>* GetTuplas() const;
	ListaPos<Cadena>* GetTuplasInseguro() const;

private:

protected:
	
	Tupla();

	ListaPos<Cadena>* tuplas;

};

#endif // ! TUPLA_H
