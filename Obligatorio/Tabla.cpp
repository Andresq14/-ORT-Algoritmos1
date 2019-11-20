#include "Tabla.h"

#ifndef TABLA_CPP
#define TABLA_CPP

ostream &operator<<(ostream& out, const Tabla &t) {
	out << t.GetNombre();
	return out;
}

Tabla::Tabla() 
{
	assert(false);
}

Tabla::Tabla(Cadena &nombreTabla) 
{
	name = nombreTabla;
	columns = new ListaPosImp<Columna>;
	tuplas = new ListaPosImp<Tupla>;
}

Tabla::Tabla(const Tabla &t) {
	//Copy Paste de Tabla()
	columns = new ListaPosImp<Columna>;
	tuplas = new ListaPosImp<Tupla>;

	*this = t;
}

Tabla::~Tabla() 
{
	delete columns;
	delete tuplas;
}

Tabla &Tabla::operator=(const Tabla &t) {
	if (this != &t) {
		name = t.name;
		*(columns) = *(t.columns);
		*(tuplas) = *(t.tuplas);
	}
	return *this;
}

bool Tabla::operator==(const Tabla &t) const {
	return name == t.name;
}

bool Tabla::operator!=(const Tabla &t) const {
	return name != t.name;
}

bool Tabla::operator<(const Tabla &t) const {
	return name < t.name;
}

bool Tabla::operator>(const Tabla &t) const {
	return name > t.name;
}

bool Tabla::operator<=(const Tabla &t) const {
	return name <= t.name;
}

bool Tabla::operator>=(const Tabla &t) const {
	return name >= t.name;
}

bool Tabla::sonIguales(const Tabla &t) const
{
	// NO IMPLEMENTADA
	return false;
}

const Cadena &Tabla::GetNombre() const {
	return name;
}

const ListaPos<Columna>& Tabla::GetColumnas() const {
	return *columns;
}

TipoRetorno Tabla::addCol(Cadena &nombreCol, CalifCol calificadorColumna) 
{
	if (columns->Existe(nombreCol))
	{
		cout << "ERROR: No se puede agregar la columna, nombreCol ya existe." << endl;
		return ERROR;
	}
	if (!tuplas->EsVacia() && calificadorColumna == NOTEMPTY)
	{
		cout << "ERROR: No se puede agregar la columna, la tabla ya tiene al menos una tupla y el calificador no es EMPTY." << endl;
		return ERROR;
	}
	
	Columna c(nombreCol, calificadorColumna);
	
	if (columns->Existe(c))
	{
		cout << "ERROR: No se puede agregar la columna, la tabla ya tiene una columna PK." << endl;
		return ERROR;
	}
	
	columns->AgregarFin(c);
	return OK;
}

TipoRetorno Tabla::delCol(Cadena &nombreCol) 
{
	if (!columns->Existe(nombreCol))
	{
		cout << "ERROR: No se puede eliminar la columna, nombreCol no existe." << endl;
		return ERROR;
	}
	
	int pos = columns->Posicion(nombreCol);

	columns->Borrar(nombreCol);
	
	if (!tuplas->EsVacia())
		for (Iterador<Tupla> i = tuplas->GetIterador(); !i.EsFin(); i++)
			i.ElementoInseguro().GetDatosInseguro()->BorrarPos(pos);

	return OK;
}

TipoRetorno Tabla::insertInto(Cadena &valoresTupla) 
{
	TipoRetorno ret = OK;
	ListaPos<Cadena>* datos = new ListaPosImp<Cadena>();

	if (columns->EsVacia())
	{
		cout << "ERROR: No se puede agregar la tupla, nombreTabla no tiene columnas." << endl;
		return ERROR;
	}

	unsigned int ini = 0;
	unsigned int fin = 0;
	
	while (ini < valoresTupla.Length())
	{
		while (fin < valoresTupla.Length() && valoresTupla[fin] != ':') 
			fin++;

		Cadena c = valoresTupla.subString(ini, fin);
		datos->AgregarFin(c);
		ini++;
		fin++;
	}

	if (datos->CantidadElementos() < columns->CantidadElementos() || datos->CantidadElementos() > columns->CantidadElementos())
	{
		cout << "ERROR: No se puede agregar la tupla, la cantidad de campos en valoresTupla no coincide con la cantidad de columnas en la tabla." << endl;
		return ERROR;
	}

	for (Iterador<Tupla> i = tuplas->GetIterador(); !i.EsFin(); i++)
	{
		if (*i.Elemento().GetDatosInseguro() == *datos )
		{
			cout << "ERROR: No se puede agregar la tupla, ya existe una tupla igual." << endl;
			return ERROR;
		}
	}

	for (unsigned int i = 0; i < columns->CantidadElementos(); i++)
	{
		if (columns->ElementoPos(i).GetCalificador() != EMPTY && datos->ElementoPos(i).Length() == 0)
		{
			cout << "ERROR: No se puede agregar la tupla, no se puede agregar un dato vacio a una columna que no es EMPTY." << endl;
			return ERROR;
		}
		if (datos->ElementoPos(i) == "@EMPTY@")
		{
			cout << "ERROR: No se puede agregar la tupla, no se puede insertar el dato @EMPTY@." << endl;
			return ERROR;
		}
	}

	if (ret == OK)
	{
		Tupla tupl(datos);
		Columna colPk(PK);
		int posPK = columns->Posicion(colPk) > columns->CantidadElementos() ? -1 : columns->Posicion(colPk);
		int pos = 0;

		if (posPK > -1)
		{
			for (Iterador<Tupla> i = tuplas->GetIterador(); !i.EsFin(); i++)
			{
				if (i.ElementoInseguro().GetDatos()->ElementoPos(posPK) == tupl.GetDatos()->ElementoPos(posPK))
				{
					cout << "ERROR: No se puede agregar la tupla, la PK ya existe en la tabla." << endl;
					return ERROR;
				}
				if (i.ElementoInseguro().GetDatos()->ElementoPos(posPK) < tupl.GetDatos()->ElementoPos(posPK))
					pos++;
			}
			tuplas->AgregarPos(tupl, pos);
		}
		else
			tuplas->AgregarFin(tupl);

	}

	delete datos;

	return ret;
}

TipoRetorno Tabla::deleteFrom(Cadena &condicionEliminar) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

void Tabla::printMetadata() 
{
	if (columns->EsVacia())
		cout << "La tabla no tiene columnas." << endl;
	else
		for (Iterador<Columna> i = columns->GetIterador(); !i.EsFin();)
			cout << i++ << endl;
}

void Tabla::printDataTable() 
{
	cout << "Listado de datos de la tabla " << name << ":" << endl << endl;

	//Nombre de las Columnas
	for (Iterador<Columna> i = columns->GetIterador(); !i.EsFin();)
	{
		cout << i++;
		if (!i.EsFin())
			cout << ":";
		else
			cout << endl;
	}

	ListaPos<Tupla>* sinRepetir = new ListaPosImp<Tupla>();
	if (tuplas->EsVacia())
		cout << "La tabla no tiene tuplas." << endl;
	else
	{
		for (unsigned int i = 0; i < tuplas->CantidadElementos(); i++)
			if (!sinRepetir->Existe(tuplas->ElementoPos(i)))
				sinRepetir->AgregarFin(tuplas->ElementoPos(i));

		for (Iterador<Tupla> i = sinRepetir->GetIterador(); !i.EsFin(); )
			cout << i++;
	}

	delete sinRepetir;
}

TipoRetorno Tabla::join(Tabla &t1, Tabla &t2) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

#endif
