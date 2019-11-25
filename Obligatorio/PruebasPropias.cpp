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
}


void PruebasPropias::PruebasOK() {


	pruebaOK();
	pruebaOK1();

}




void PruebasPropias::pruebaOK()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK *******************\n";
	//cout<<"Prueba agregar tuplas a las tablas y listarlas\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(10);
	cargarBaseDeDatos(interfaz);
	
	ver2(interfaz->insertInto("Alumnos", "1:Martin:21:martin@gmail.com:1"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->insertInto("Alumnos", "2:Victoria:24::1"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->insertInto("Alumnos", "3:Emilio:25:emilio@gmail.com:2"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->insertInto("Alumnos", "4:Andrea:26:andrea@hotmail.com:1"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->insertInto("Alumnos", "5:Pedro:27::2"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->printDataTable("Alumnos"), OK, "Se imprimen los datos de Alumnos");


	ver2(interfaz->insertInto("Carreras", "1:Ingenieria En Sistemas"), OK, "Se ingresa una tupla a la tabla Carreras");
	ver2(interfaz->insertInto("Carreras", "2:Licenciatura en Sistemas"), OK, "Se ingresa una tupla a la tabla Carreras");
	ver2(interfaz->insertInto("Carreras", "3:Analista Programador"), OK, "Se ingresa una tupla a la tabla Carreras");
	ver2(interfaz->printDataTable("Carreras"), OK, "Se imprimen los datos de Carreras");

	ver2(interfaz->insertInto("Materias", "Algoritmos 1:1111:1"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Algoritmos 2:2222:1"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Calculo 1:3333:1"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Logica:4444:2"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Programacion 1:5555:1"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Programacion 2:6666:2"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Matematica:7777:2"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Ingenieria De Software:8888:1"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Algoritmos 1:9999:2"), OK, "Se ingresa una tupla en la tabla Materias");
	ver2(interfaz->insertInto("Materias", "Sistemas Operativos:1212:3"), OK, "Se ingresa una tupla en la tabala Materias");
	ver2(interfaz->printDataTable("Materias"), OK, "Se imprimen los datos de Materias");

	ver2(interfaz->insertInto("Docentes", "1:Pedro:1111"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "2:Juan:8888"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "3:Jorge:3333"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "4:Alejandro:1111"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "5:Victoria:9999"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "6:Carlos:4444"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "7:Angel:1212"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "8:Pedro:2222"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "9:Helena:2222"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "10:Ines:5555"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->insertInto("Docentes", "11:Marcelo:6666"), OK, "Se ingresa una tupla en la tabla Docentes");
	ver2(interfaz->printDataTable("Docentes"), OK, "Se imprimen los datos de Materias");

	// Prueba repetidos
	ver2(interfaz->createTable("Nombres"), OK, "Se crea la tabla Nombres");
	ver2(interfaz->addCol("Nombres", "id", NOTEMPTY), OK, "Se agrega la columna Id a la tabla Nombres");
	ver2(interfaz->addCol("Nombres", "Nombre", NOTEMPTY), OK, "Se agrega la columna Nombre a la tabla Nombres");
	ver2(interfaz->insertInto("Nombres", "1:Pedro"), OK, "Se ingresa una tupla en la tabla Nombres");
	ver2(interfaz->insertInto("Nombres", "2:Juan"), OK, "Se ingresa una tupla en la tabla Nombres");
	ver2(interfaz->insertInto("Nombres", "3:Pedro"), OK, "Se ingresa una tupla en la tabla Nombres");
	ver2(interfaz->insertInto("Nombres", "4:Juan"), OK, "Se ingresa una tupla en la tabla Nombres");
	ver2(interfaz->dropCol("Nombres", "id"), OK, "Se da de baja la columna id en la tabla Nombres");
	ver2(interfaz->printDataTable("Nombres"), OK, "Se imprimen los datos de Nombres sin repetidos");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok");
}


void PruebasPropias::pruebaOK1() {

	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK1 *******************\n";
	//cout<<"Prueba agregar tuplas a las tablas y listarlas\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok1");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(10);
	cargarBaseDeDatos(interfaz);
	cargarTablas(interfaz);


	ver2(interfaz->deleteFrom("Alumnos", "eMail=@EMPTY@"), OK, "Se eliminan las tuplas de la tabla alumno sin email");
	ver2(interfaz->printDataTable("Alumnos"), OK, "Se imprimen los datos de la tabla Alumnos");
	ver2(interfaz->deleteFrom("Docentes", "idMateria=2222"), OK, "Se eliminan las tuplas de la tabla Docentes que atienden la especialidad con codigo 2222");
	ver2(interfaz->printDataTable("Docentes"), OK, "Se imprimen los datos de la tabla Docentes");
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok1 deleteFrom");


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


