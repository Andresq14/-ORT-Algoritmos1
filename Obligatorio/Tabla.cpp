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

	columns->Borrar(nombreCol);
	return OK;
}

TipoRetorno Tabla::insertInto(Cadena &valoresTupla) 
{
	unsigned int len = 0;
	char** split = valoresTupla.split(':', len);
	TipoRetorno ret = OK;
	ListaPos<Cadena>* datos = new ListaPosImp<Cadena>();

	if (columns->EsVacia())
	{
		cout << "ERROR: No se puede agregar la tupla, nombreTabla no tiene columnas." << endl;
		return ERROR;
	}
	if (len > (columns->CantidadElementos()) )
	{
		cout << "ERROR: No se puede agregar la tupla, la cantidad de campos en valoresTupla no coincide con la cantidad de columnas en la tabla." << endl;
		return ERROR;
	}

	for (unsigned int i = 0; i < len && ret == OK; i++)
	{
		Cadena tup = split[i];
		datos->AgregarFin(tup);
	}

	if (ret == OK)
	{
		Tupla tupl(datos);
		tuplas->AgregarFin(tupl);
	}

	for (unsigned int i = 0; i < len; i++)
		delete[] split[i];

	delete split;
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
		for (Iterador<Columna> i = columns->GetIterador(); !i.EsFin(); i++)
			cout << i.Elemento();
}

void Tabla::printDataTable() {
	cout << name << endl;
}

TipoRetorno Tabla::join(Tabla &t1, Tabla &t2) {
	// NO IMPLEMENTADA
	return NO_IMPLEMENTADA;
}

#endif
