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
	
	//Constructores
	Tupla(ListaPos<Cadena>* dato);
	Tupla(const Tupla& tupla);

	//Destructor
	virtual ~Tupla();
	
	//PRE:
	//POS: Iguala la Tupla (this) con la Tupla pasada por parametro
	Tupla& operator=(const Tupla& t);

	// Operadores de comparacion 
	bool operator==(const Tupla& t) const;

	//PRE:
	//POS: Retorna los datos de this, no se pueden modificar
	const ListaPos<Cadena>* GetDatos() const;
	
	//PRE:
	//POS: Retorna los datos de this, se pueden modificar
	ListaPos<Cadena>* GetDatosInseguro() const;

private:

protected:
	
	//Constructor
	Tupla();

	//Atributos

	ListaPos<Cadena>* datos;

};

#endif // ! TUPLA_H
