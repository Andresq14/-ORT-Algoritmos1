#ifndef TABLA_H
#define TABLA_H

#include "Constantes.h"
#include "Cadena.h"
#include "CalifCol.h"

class Tabla;
// Operador de salida de flujo
ostream &operator<<(ostream& out, const Tabla &t);

class Tabla
{
public:
	
	// Constructor que recibe el nombre de la tabla
	Tabla(Cadena &nombreTabla);

	// Constructor copia
	Tabla(const Tabla &t);

	// Destructor
	virtual ~Tabla();

	// Operador de asignacion
	Tabla &operator=(const Tabla &t);

	// Operadores de comparacion (comparan el nombre de la tabla)
	bool operator==(const Tabla &t) const;
	bool operator!=(const Tabla &t) const;
	bool operator<(const Tabla &t) const;
	bool operator>(const Tabla &t) const;
	bool operator<=(const Tabla &t) const;
	bool operator>=(const Tabla &t) const;

	// Retorna true si las 2 tablas tienen las mismas columnas (mismo nombre y orden)
	// y tienen los mismos datos en sus tuplas
	bool sonIguales(const Tabla &t) const;
	
	// Retorna el nombre de la tabla
	const Cadena &GetNombre() const;

	// Agrega la columna a la tabla y retorna OK. 
	// Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno addCol(Cadena &nombreCol, CalifCol calificadorColumna);

	// Elimina la columna a la tabla y retorna OK. 
	// Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno delCol(Cadena &nombreCol);

	// Inserta los datos separados por : en la tabla y retorna OK. 
	// Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno insertInto(Cadena &valoresTupla);

	// Elimina los datos que cumplan con la condicion y retorna OK. 
	// Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno deleteFrom(Cadena &condicionEliminar);

	// Imprime la metadata de la tabla
	void printMetadata();

	// Imprime los datos de la tabla 
	void printDataTable();

	// Realiza el join entre t1 y t2 guardando el resultado en this y retorna OK. 
	// Si no se puede realizar despliega un mensaje de error y retorna ERROR.
	TipoRetorno join(Tabla &t1, Tabla &t2);


private:

protected:
	// Constructor por defecto
	Tabla();
	
	Cadena name;

};

#endif