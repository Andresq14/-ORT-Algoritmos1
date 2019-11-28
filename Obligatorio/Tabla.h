#ifndef TABLA_H
#define TABLA_H

#include "Constantes.h"
#include "Cadena.h"
#include "CalifCol.h"
#include "Columna.h"
#include "Tupla.h"
#include "ListaPos.h"
#include "ListaPosImp.h"

class Tabla;
// Operador de salida de flujo
ostream &operator<<(ostream& out, const Tabla &t);

class Tabla
{
public:
	
	// Constructores
	Tabla(Cadena &nombreTabla);
	Tabla(const Tabla &t);
	
	// Destructor
	virtual ~Tabla();

	//PRE:
	//POS: Iguala la Tabla (this) con la Tabla pasada por parametro
	Tabla &operator=(const Tabla &t);

	// Operadores de comparacion
	bool operator==(const Tabla &t) const;
	bool operator!=(const Tabla &t) const;
	bool operator<(const Tabla &t) const;
	bool operator>(const Tabla &t) const;
	bool operator<=(const Tabla &t) const;
	bool operator>=(const Tabla &t) const;

	//PRE:
	//POS: Retorna true si las 2 tablas tienen las mismas columnas (mismo nombre y orden) y tienen los mismos datos en sus tuplas
	bool sonIguales(const Tabla &t) const;
	
	//PRE:
	//POS: Retorna el nombre de this
	const Cadena &GetNombre() const;

	//PRE:
	//POS: Retorna el nombre de this, no permite modificar
	const ListaPos<Columna>& GetColumnas() const;

	//PRE:
	//POS: Agrega la columna a la tabla y retorna OK. Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno addCol(Cadena &nombreCol, CalifCol calificadorColumna);

	//PRE:
	//POS: Elimina la columna a la tabla y retorna OK. Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno delCol(Cadena &nombreCol);

	//PRE:
	//POS: Inserta los datos separados por : en la tabla y retorna OK. Si no se puede realizar despliega un mensaje de error y retorna ERROR. 
	TipoRetorno insertInto(Cadena &valoresTupla);

	//PRE:
	//POS: Elimina los datos que cumplan con la condicion y retorna OK. Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno deleteFrom(Cadena &condicionEliminar);

	//PRE:
	//POS: Imprime la metadata de la tabla
	void printMetadata();

	//PRE:
	//POS: Imprime los datos de la tabla 
	void printDataTable();

	//PRE:
	//POS: Realiza el join entre t1 y t2 guardando el resultado en this y retorna OK. Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno join(Tabla &t1, Tabla &t2);

private:

protected:
	// Constructor por defecto
	Tabla();
	
	//Atributos
	Cadena name;
	ListaPos<Columna>* columns;
	ListaPos<Tupla>* tuplas;
};

#endif