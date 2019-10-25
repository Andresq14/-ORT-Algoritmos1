#include "PruebasPropias.h"

PruebasPropias::PruebasPropias(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebasPropias::~PruebasPropias()
{
}

const char* PruebasPropias::getNombre() const
{
	return "PruebasPropias";
}

void PruebasPropias::correrPruebaConcreta()
{
	this->mImpresion.iniciarSeccion("PRUEBAS Propias");

	// Este archivo lo puedo modificar para hacer mis propias pruebas
	// Ejemplo:

	InterfazDelSistema *interfaz = new InterfazDelSistemaImp(2);

	cargarBaseDeDatos(interfaz);
	cargarTablas(interfaz);

	ver2(interfaz->printTables(), OK, "Se imprimen las tablas");
	ver2(interfaz->printDataTable("Materias"), OK, "Se imprimen los datos de Materias");
	ver2(interfaz->printDataTable("Alumnos"), OK, "Se imprimen los datos de Alumnos");



	delete interfaz;
	this->mImpresion.cerrarSeccion("PRUEBAS Propias");
}


void PruebasPropias::cargarBaseDeDatos(InterfazDelSistema *interfaz)
{
	interfaz->createTable("Materias");
	interfaz->createTable("Docentes");
	interfaz->createTable("Carreras");
	interfaz->createTable("Alumnos");

	interfaz->addCol("Alumnos", "idAlumno", PK);
	interfaz->addCol("Alumnos", "Nombre", NOTEMPTY);
	interfaz->addCol("Alumnos", "Edad", NOTEMPTY);
	interfaz->addCol("Alumnos", "eMail", EMPTY);
	interfaz->addCol("Alumnos", "idCarrera", NOTEMPTY);
	interfaz->addCol("Materias", "Nombre", NOTEMPTY);
	interfaz->addCol("Materias", "idMateria", PK);
	interfaz->addCol("Materias", "idCarrera", NOTEMPTY);


	interfaz->addCol("Carreras", "Nombre", NOTEMPTY);
	interfaz->addCol("Carreras", "idCarrera", PK);
	interfaz->addCol("Docentes", "idDocente", PK);

	interfaz->addCol("Docentes", "Nombre", NOTEMPTY);
	interfaz->addCol("Docentes", "idMateria", NOTEMPTY);
	
	
}



void PruebasPropias::cargarTablas(InterfazDelSistema *interfaz)
{
	interfaz->insertInto("Alumnos","1:Martin:23:martin@gmail.com:1");
	interfaz->insertInto("Alumnos","2:Valeria:24::1");
	interfaz->insertInto("Alumnos", "3:Emilio:25:emilio@gmail.com:2");
	interfaz->insertInto("Alumnos", "4:Andrea:26:andrea@hotmail.com:1");
	interfaz->insertInto("Alumnos", "5:Pedro:27::2");
	
	interfaz->insertInto("Carreras", "1:Ingenieria En Sistemas");
	interfaz->insertInto("Carreras", "2:Licenciatura en Sistemas");
	interfaz->insertInto("Carreras", "3:Analista Programador");
	interfaz->insertInto("Materias", "Algoritmos 1:1111:1");
	interfaz->insertInto("Materias", "Algoritmos 2:2222:1");
	interfaz->insertInto("Materias", "Calculo 1:3333:1");
	interfaz->insertInto("Materias", "Logica:4444:2");
	interfaz->insertInto("Materias", "Algoritmos 1:9999:2");
	interfaz->insertInto("Materias", "Sistemas Operativos:1212:3");

	interfaz->insertInto("Docentes", "1:Pedro:1111");
	interfaz->insertInto("Docentes", "2:Juan:8888");
	interfaz->insertInto("Docentes", "3:Jorge:3333");
	interfaz->insertInto("Docentes", "4:Alejandro:1111");
	interfaz->insertInto("Docentes", "5:Victoria:9999");
	interfaz->insertInto("Docentes", "6:Carlos:4444");
	interfaz->insertInto("Docentes", "7:Angel:1212");
	interfaz->insertInto("Docentes", "8:Pedro:2222");
	interfaz->insertInto("Docentes", "9:Helena:2222");
	interfaz->insertInto("Docentes", "10:Ines:5555");
	interfaz->insertInto("Docentes", "11:Marcelo:6666");

}


