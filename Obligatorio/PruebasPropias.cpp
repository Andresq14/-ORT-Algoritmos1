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
	//cout<<"\n\n";
	//cout<<"**************************************\n\n";
	//cout<<"***** PRUEBAS PROPIAS *********\n";
	//cout<<"**************************************\n\n";

	//cout<<"\n\n";
	//cout<<"***** PRUEBAS PROPIAS OK ******\n";
	//cout<<"**************************************\n\n";

	PruebasOK();

	PruebasERROR();

}


void PruebasPropias::PruebasOK() {


	//pruebaOK();
	//pruebaOK1();

}

void PruebasPropias::PruebasERROR() {


	pruebasERROR1();
	pruebasERROR2();
	pruebasERROR3();
	pruebasERROR4();
	pruebasERROR5();
	pruebasERROR6();

}



void PruebasPropias::pruebasERROR1()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR1 ****************\n";
	//cout<<"Pruebas de error de la operacion createTable\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error createTable");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->createTable("Alumnos"), OK, "Se crea la tabla alumnos");
	ver2(interfaz->createTable("AlumnoS"), ERROR, "La tabla Alumnos ya existe");
	ver2(interfaz->dropTable("AlumnoS"), OK, "La tabla alumnos se elimino.");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error createTable");
}

void PruebasPropias::pruebasERROR2()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR1 ****************\n";
	//cout<<"Pruebas de error de la operacion createTable\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error createTable");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->createTable("Docentes"), OK, "Se crea la tabla docentes");
	ver2(interfaz->printDataTable("Docentes"), OK, "Esta tabla no tiene datos");
	ver2(interfaz->printMetadata("Docentes"), OK, "Esta tabla no tiene columnas");
	ver2(interfaz->addCol("DoCEnteS", "ID", PK), OK, "Se ingreso la columna");
	ver2(interfaz->addCol("DoCEnteS", "id", EMPTY), ERROR, "Esta columna ya existe");
	ver2(interfaz->addCol("DoCEnteS", "Nombre", PK), ERROR, "Esta tabla ya tiene una columna con el calificador PK");


	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error createTable");
}

void PruebasPropias::pruebasERROR3()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR1 ****************\n";
	//cout<<"Pruebas de error de la operacion createTable\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error createTable");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->createTable(""), ERROR, "No se puede crear una tabla sin nombre");
	ver2(interfaz->addCol("", "", PK), ERROR, "Nos e puede ingresar una columna sin nombre");
	ver2(interfaz->createTable("Presidentes"), OK, "Se creo la tabla");
	ver2(interfaz->addCol("Presidentes", "", PK), ERROR, "Nos e puede ingresar una columna sin nombre");



	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error createTable");
}

void PruebasPropias::pruebasERROR4()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR1 ****************\n";
	//cout<<"Pruebas de error de la operacion createTable\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error createTable");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	
	ver2(interfaz->createTable("Presidentes"), OK, "Se creo la tabla");
	ver2(interfaz->addCol("Presidentes", "ID", PK), OK, "Se creo la columna");
	ver2(interfaz->dropCol("Presidentes", ""), ERROR, "No se encontro la columna");
	ver2(interfaz->printMetadata("Presidentes"),OK);
	ver2(interfaz->dropCol("Presidentes", "id"), OK, "Se elimino la columna");
	ver2(interfaz->printMetadata("Presidentes"), OK);


	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error createTable");
}


void PruebasPropias::pruebasERROR5()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR5 ****************\n";
	//cout<<"Pruebas de error de la operacion createTable\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error createTable");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);


	ver2(interfaz->createTable("Alumnos"), OK, "Se creo la tabla");
	ver2(interfaz->addCol("Alumnos", "ID", PK), OK, "Se creo la columna");
	ver2(interfaz->addCol("Alumnos", "Nombre",EMPTY), OK, "Se creo la columna");


	ver2(interfaz->insertInto("Alumnos", ""), ERROR, "Nose puede ingresar una tupla vacia");
	ver2(interfaz->insertInto("Alumnos", "1:Martin::::::::::"), ERROR, "Los datos a ingresar no coinciden con la cantidad de columnas");
	ver2(interfaz->insertInto("Alumnos", "1:Martin:23:martin@gmail.com:1:56"), ERROR, "Los datos a ingresar no coinciden con la cantidad de columnas");
	ver2(interfaz->insertInto("Alumnos", ":Pepe"), ERROR, "Nose puede ingresar una tupla vacia");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error createTable");
}


void PruebasPropias::pruebasERROR6()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR5 ****************\n";
	//cout<<"Pruebas de error de la operacion createTable\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error createTable");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->createTable("Alumnos"), OK, "Se creo la tabla");
	ver2(interfaz->addCol("Alumnos", "ID", PK), OK, "Se creo la columna");
	ver2(interfaz->addCol("Alumnos", "Nombre", EMPTY), OK, "Se creo la columna");

	ver2(interfaz->createTable("Docente"), OK, "Se creo la tabla");
	ver2(interfaz->addCol("Docente", "ID", PK), OK, "Se creo la columna");
	ver2(interfaz->addCol("Docente", "Nombre", EMPTY), OK, "Se creo la columna");

	ver2(interfaz->join("Docente", "Alumnos", "Resultado"), ERROR, "No se puede hacer join");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error createTable");
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
	cargarBaseDeDatos(interfaz);
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


