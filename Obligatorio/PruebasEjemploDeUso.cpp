#include "PruebasEjemploDeUso.h"

PruebasEjemploDeUso::PruebasEjemploDeUso(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasEjemploDeUso::~PruebasEjemploDeUso()
{
	
}

const char* PruebasEjemploDeUso::getNombre()const
{
	return "PruebasEjemploDeUso";
}

void PruebasEjemploDeUso::correrPruebaConcreta()
{
	//cout<<"\n\n";
	//cout<<"**************************************\n\n";
	//cout<<"***** PRUEBAS EJEMPLO DE USO *********\n";
	//cout<<"**************************************\n\n";

	//cout<<"\n\n";
	//cout<<"***** PRUEBAS EJEMPLO DE USO OK ******\n";
	//cout<<"**************************************\n\n";

	PruebasOK();
	
	//cout<<"\n\n";
	//cout<<"***** PRUEBAS EJEMPLO DE USO ERROR ***\n";
	//cout<<"**************************************\n\n";

	PruebasError();

	//cout<<"--------------------------------------------------------"<<endl;
	//cout<<"----- FIN PRUEBAS EJEMPLO DE USO ERROR."<<endl;
	//cout<<"--------------------------------------------------------"<<endl;


	//cout<<"--------------------------------------------------------"<<endl;
	//cout<<"----- FIN PRUEBAS EJEMPLO DE USO."<<endl;
	//cout<<"--------------------------------------------------------"<<endl;
}


void PruebasEjemploDeUso::PruebasError()
{
	
	pruebasERROR1();
	pruebasERROR2();
	pruebasERROR3();
	pruebasERROR4();
	pruebasERROR5();
	pruebasERROR6();
	pruebasERROR7();
	pruebasERROR8();
	
}

void PruebasEjemploDeUso::PruebasOK()
{	
	
	pruebaOK1();
	pruebaOK2();
	pruebaOK3();
	pruebaOK4();
	pruebaOK5();
	pruebaOK6();
	pruebaOK7();
	pruebaOK8();
	pruebaOK9();
	

	//cout<<"--------------------------------------------------------"<<endl;
	//cout<<"----- FIN PRUEBAS EJEMPLO DE USO OK."<<endl;
	//cout<<"--------------------------------------------------------"<<endl;
};

void PruebasEjemploDeUso::pruebaOK1()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK1 ****************\n";
	//cout<<"Prueba crear tablas y las lista\n";
	//cout<<"*********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok1");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(10);

	ver2(interfaz->createTable("Materias"),OK,"Se crea la tabla Materias");
	ver2(interfaz->createTable("Docentes"),OK,"Se crea la tabla Docentes");
	ver2(interfaz->createTable("Carreras"),OK,"Se crea la tabla Carreras");
	ver2(interfaz->createTable("Alumnos"), OK, "Se crea la tabla Alumnos");
	ver2(interfaz->printTables(), OK, "Se imprimen las tablas en orden alfabetico");
	
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok1");
}

void PruebasEjemploDeUso::pruebaOK2()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK2 ***********************\n";
	//cout<<"Prueba crear una tabla y borrarla y luego imprime\n";
	//cout<<"***************************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok2");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);
	
	ver2(interfaz->createTable("TablaABorrar"), OK, "Se crea la tabla a borrar");
	ver2(interfaz->dropTable("TablaABorrar"), OK, "Se borra la tabla a borrar");
	ver2(interfaz->printTables(), OK, "Se imprimen las tablas");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok2");
}

void PruebasEjemploDeUso::pruebaOK3()
{

	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK3 ***********************\n";
	//cout<<"Prueba crear tablas, agregar columnas y listarlas\n";
	//cout<<"*****************************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok3");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->createTable("Materias"),OK,"Se crea la tabla Materias");
	ver2(interfaz->createTable("Docentes"),OK,"Se crea la tabla Docentes");
	ver2(interfaz->createTable("Carreras"),OK,"Se crea la tabla Carreras");
	ver2(interfaz->createTable("Alumnos"), OK, "Se crea la tabla Alumnos");

	ver2(interfaz->addCol("Alumnos", "idAlumno", PK), OK, "Se agrega la columa idAlumno a la tabla Alumno como PK");
	ver2(interfaz->addCol("Alumnos", "Nombre", NOTEMPTY), OK, "Se agrega la columna nombre a la tabla alumno");
	ver2(interfaz->addCol("Alumnos", "Edad", NOTEMPTY), OK, "Se agrega la columna Edad en la tabla alumno");
	ver2(interfaz->addCol("Alumnos", "eMail", EMPTY), OK, "Se agrega la columna email a la tabla alumno");
	ver2(interfaz->addCol("Alumnos", "idCarrera", NOTEMPTY), OK, "Se agrega la columa idCarrera a la tabla Alumnos");
	ver2(interfaz->printMetadata("Alumnos"), OK, "Se imprimen los metadatos de alumnos");
	ver2(interfaz->printDataTable("Alumnos"), OK, "Se imprimen los datos de alumnos");

	ver2(interfaz->addCol("Materias", "Nombre", NOTEMPTY), OK, "Se agrega la columna Nombre a la tabla Materia");
	ver2(interfaz->addCol("Materias", "idMateria", PK), OK, "Se agrega la columna idMateria a la tabla Materia como PK");
	ver2(interfaz->addCol("Materias", "idCarrera", NOTEMPTY),OK, "Se agrega la columna idCarrera a la tabla Materia");
	ver2(interfaz->printMetadata("Materias"), OK, "Se imprimen los metadatos de Materias");
	ver2(interfaz->printDataTable("Materias"), OK, "Se imprimen los datos de Materias");

	ver2(interfaz->addCol("Carreras", "Nombre", NOTEMPTY), OK, "Se agrega la columna nombre a la tabla Carrera");
	ver2(interfaz->addCol("Carreras", "idCarrera", PK), OK, "Se agrega la columna idCarrera a la tabla Carrera");
	ver2(interfaz->printMetadata("Carreras"), OK, "Se imprimen los metadatos de Carreras");
	ver2(interfaz->printDataTable("Carreras"), OK, "Se imprimen los datos de Carreras");

	ver2(interfaz->addCol("Docentes", "idDocente", PK), OK, "Se agrega la columa idDocente como PK a la tabla Docentes");
	ver2(interfaz->addCol("Docentes", "Nombre", NOTEMPTY), OK, "Se agrega la columna Nombre a la tabla Docentes");
	ver2(interfaz->addCol("Docentes", "idMateria", NOTEMPTY), OK, "Se agrega la columna idMateria a la tabla Docentes");
	ver2(interfaz->printMetadata("Docentes"), OK, "Se imprimen los metadatos de Docentes");
	ver2(interfaz->printDataTable("Docentes"), OK, "Se imprimen los datos de Docentes");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok3");
}

void PruebasEjemploDeUso::pruebaOK4()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK4 ****************\n";
	//cout<<"Prueba borrar una tabla\n";
	//cout<<"*********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok4 dropTable");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(10);
	cargarBaseDeDatos(interfaz);
	ver2(interfaz->dropTable("Alumnos"), OK, "Se da de baja la tabla Alumnos");
	ver2(interfaz->printTables(), OK, "Se imprimen las tablas");
	delete interfaz;
	
	this->mImpresion.cerrarSeccion("PRUEBAS ok4 dropTable");
}

void PruebasEjemploDeUso::pruebaOK5()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK5 ****************\n";
	//cout<<"Prueba borrar columnas de una tabla\n";
	//cout<<"*********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok5 dropCol");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(10);
	cargarBaseDeDatos(interfaz);
	ver2(interfaz->dropCol("Alumnos", "idAlumno"), OK, "Se da de baja la columna idAlumno en la tabla Alumnos");
	ver2(interfaz->dropCol("Alumnos", "eMail"), OK, "Se da de baja la columna eMail en la tabla Alumnos");
	ver2(interfaz->printMetadata("Alumnos"), OK, "Se imprimen los metadatos de alumnos");
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok5 dropCol");
}

void PruebasEjemploDeUso::pruebaOK6()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK6 *******************\n";
	//cout<<"Prueba agregar tuplas a las tablas y listarlas\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok6");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(10);
	cargarBaseDeDatos(interfaz);
	ver2(interfaz->insertInto("Alumnos","1:Martin:21:martin@gmail.com:1"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->insertInto("Alumnos","2:Victoria:24::1"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->insertInto("Alumnos", "3:Emilio:25:emilio@gmail.com:2"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->insertInto("Alumnos", "4:Andrea:26:andrea@hotmail.com:1"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->insertInto("Alumnos", "5:Pedro:27::2"), OK, "Se ingresa una tupla a la tabla Alumnos");
	ver2(interfaz->printDataTable("Alumnos"), OK,  "Se imprimen los datos de Alumnos");
	

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
	ver2(interfaz->createTable("Nombres"),OK,"Se crea la tabla Nombres");
	ver2(interfaz->addCol("Nombres", "id", NOTEMPTY), OK, "Se agrega la columna Id a la tabla Nombres");
	ver2(interfaz->addCol("Nombres", "Nombre", NOTEMPTY), OK, "Se agrega la columna Nombre a la tabla Nombres");
	ver2(interfaz->insertInto("Nombres", "1:Pedro"), OK, "Se ingresa una tupla en la tabla Nombres");
	ver2(interfaz->insertInto("Nombres", "2:Juan"), OK, "Se ingresa una tupla en la tabla Nombres");
	ver2(interfaz->insertInto("Nombres", "3:Pedro"), OK, "Se ingresa una tupla en la tabla Nombres");
	ver2(interfaz->insertInto("Nombres", "4:Juan"), OK, "Se ingresa una tupla en la tabla Nombres");
	ver2(interfaz->dropCol("Nombres", "id"), OK, "Se da de baja la columna id en la tabla Nombres");
	ver2(interfaz->printDataTable("Nombres"), OK, "Se imprimen los datos de Nombres sin repetidos");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok6");
}

void PruebasEjemploDeUso::pruebaOK7()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK7 ****************\n";
	//cout<<"Pruebas de la operacion deleteFrom\n";
	//cout<<"*********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok7 deleteFrom");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(10);
	cargarTablas(interfaz);

	ver2(interfaz->deleteFrom("Alumnos", "eMail=@EMPTY@"), OK, "Se eliminan las tuplas de la tabla alumno sin email");
	ver2(interfaz->printDataTable("Alumnos"), OK, "Se imprimen los datos de la tabla Alumnos");
	ver2(interfaz->deleteFrom("Docentes", "idMateria=2222"), OK, "Se eliminan las tuplas de la tabla Docentes que atienden la especialidad con codigo 2222");
	ver2(interfaz->printDataTable("Docentes"), OK, "Se imprimen los datos de la tabla Docentes");
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok7 deleteFrom");
}

void PruebasEjemploDeUso::pruebaOK8()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK8 ****************\n";
	//cout<<"Pruebas de la operacion recent\n";
	//cout<<"*********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok8 recent");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(10);
	cargarTablas(interfaz);
	ver2(interfaz->recent(), OK, "Se muestran las ultimas tablas modificadas.");
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS ok8 recent");
}

void PruebasEjemploDeUso::pruebaOK9()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA OK9 ****************\n";
	//cout<<"Pruebas de la operacion join\n";
	//cout<<"*********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS ok9 join");

	InterfazDelSistema* interfaz = new InterfazDelSistemaImp(10);
	cargarTablas(interfaz);
	ver2(interfaz->createTable("Docentes2"), OK, "Se crea la tabla docentees2");
	ver2(interfaz->addCol("Docentes2", "idDocente", PK), OK, "Se agrega la columa idDocente como PK a la tabla Docentes");
	ver2(interfaz->addCol("Docentes2", "Nombre2", NOTEMPTY), OK, "Se agrega la columna Nombre a la tabla Docentes");
	ver2(interfaz->addCol("Docentes2", "idMateria2", NOTEMPTY), OK, "Se agrega la columna idMateria a la tabla Docentes");
	ver2(interfaz->insertInto("Docentes2", "1:Pedro:1111"), OK, "Se inserta una tupla en Docentes2");
	ver2(interfaz->insertInto("Docentes2", "4:Alejandro:1111"), OK, "Se inserta una tupla en Docentes2");
	
	ver2(interfaz->join("Docentes", "Docentes2", "DocentesDeA1"), OK, "Se intersectan Docentes y Docentes2");
	ver2(interfaz->printDataTable("DocentesDeA1"), OK, "Se imprimen los datos de la tabla DocentesDeA1");

	delete interfaz;
	
	this->mImpresion.cerrarSeccion("PRUEBAS ok9 join");
}

void PruebasEjemploDeUso::pruebasERROR1()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR1 ****************\n";
	//cout<<"Pruebas de error de la operacion createTable\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error createTable");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);
	
	ver2(interfaz->createTable("Alumnos"), OK, "Se crea la tabla alumnos");
	ver2(interfaz->createTable("Alumnos"), ERROR, "La tabla Alumnos ya existe");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error createTable");
}

void PruebasEjemploDeUso::pruebasERROR2()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR2 ****************\n";
	//cout<<"Pruebas de error de la operacion dropTable\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error dropTable");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);
	ver2(interfaz->dropTable("Alumnos"), ERROR, "La tabla alumnos no existe");
	delete interfaz;
	
	this->mImpresion.cerrarSeccion("PRUEBAS error dropTable");
}

void PruebasEjemploDeUso::pruebasERROR3()
{

	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR3 ****************\n";
	//cout<<"Pruebas de error de la operacion addCol\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error addCol");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->addCol("Alumnos", "idAlumno", PK), ERROR, "La tabla alumnos no existe");
	ver2(interfaz->createTable("Alumnos"), OK, "Se crea la tabla alumnos");
	ver2(interfaz->addCol("Alumnos", "idAlumno", PK), OK, "Se agrega la columna idAlumno a Alumnos");
	ver2(interfaz->addCol("Alumnos", "idAlumno", NOTEMPTY), ERROR, "Ya existe una columna con el nombre idAlumno");
	ver2(interfaz->addCol("Alumnos", "cedula", PK), ERROR, "Ya existe una columna que es PK");

	delete interfaz;
	
	this->mImpresion.cerrarSeccion("PRUEBAS error addCol");
}

void PruebasEjemploDeUso::pruebasERROR4()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR4 ****************\n";
	//cout<<"Pruebas de error de la operacion dropCol\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error dropCol");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->dropCol("Alumnos", "idAlumno"), ERROR, "La tabla alumnos no existe");
	ver2(interfaz->createTable("Alumnos"), OK, "Se crea la tabla alumnos");
	ver2(interfaz->dropCol("Alumnos", "idAlumno"), ERROR, "La columna idAlumno No existe");
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error dropCol");
}

void PruebasEjemploDeUso::pruebasERROR5()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR5 ****************\n";
	//cout<<"Pruebas de error de la operacion insertInto\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error insertInto");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->insertInto("Alumnos", "11:Juan"), ERROR, "La tabla alumnos no existe");
	ver2(interfaz->createTable("TablaVacia"), OK, "Se crea una tabla sin columnas");
	ver2(interfaz->insertInto("TablaVacia", "no:hay:columnas"), ERROR, "la tabla no tiene columnas");
	cargarBaseDeDatos(interfaz);
	ver2(interfaz->insertInto("Alumnos", ""), ERROR, "Los datos a ingresar estan vacios");
	ver2(interfaz->insertInto("Alumnos", "1:Martin"), ERROR, "Los datos a ingresar no coinciden con la cantidad de columnas");
	ver2(interfaz->insertInto("Alumnos", "1:Martin:23:martin@gmail.com:1:56"), ERROR, "Los datos a ingresar no coinciden con la cantidad de columnas");
	ver2(interfaz->insertInto("Alumnos", "1:Martin:23:martin@gmail.com:1"), OK, "Se ingresa una tupla a la tabla");
	ver2(interfaz->insertInto("Alumnos", "1:Valeria:23:vale@gmail.com:1"), ERROR, "Ya existe una tupla con la PK 1");
	ver2(interfaz->insertInto("Alumnos", "2:Valeria:::1"), ERROR, "No se puede agregar un valor vacio a un campo NOTEMPTY");
	ver2(interfaz->insertInto("Alumnos", "2:Valeria:23:@EMPTY@:2"), ERROR, "No se puede agregar el valor @EMPTY@");
	ver2(interfaz->createTable("Universidades"), OK, "Se crea la tabla Universidades");
	ver2(interfaz->addCol("Universidades", "Nombre", NOTEMPTY), OK, "Se agrega la columna nombre a la tabla Universidades");
	ver2(interfaz->addCol("Universidades", "Direccion", EMPTY), OK, "Se agrega la columna direccion a la tabla Universidades");
	ver2(interfaz->insertInto("Universidades", "Universidad ORT:Cuareim"), OK, "Se agrega una tupla a la tabla Universidades");
	ver2(interfaz->insertInto("Universidades", "Universidad ORT:Cuareim"), ERROR, "No se puede agregar una tupla identica a una existente");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error insertInto");
}

void PruebasEjemploDeUso::pruebasERROR6()
{

	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR6 ****************\n";
	//cout<<"Pruebas de error de la operacion deleteFrom\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error deleteFrom");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);

	ver2(interfaz->deleteFrom("Alumnos", "nombre=Martin"), ERROR, "No existe la tabla Alumnos");
	cargarBaseDeDatos(interfaz);
	ver2(interfaz->deleteFrom("Alumnos", "idMateria=2"), ERROR, "El campo idMateria no existe en la tabla Alumnos");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error deleteFrom");
}

void PruebasEjemploDeUso::pruebasERROR7()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR9 ****************\n";
	//cout<<"Pruebas de error de la operacion join\n";
	//cout<<"***********************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error join");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);
	cargarBaseDeDatos(interfaz);
	ver2(interfaz->join("Universidades", "Alumnos", "UniAlumnos"), ERROR, "La tabla Universidades no existe");
	ver2(interfaz->join("Alumnos", "Universidades", "UniAlumnos"), ERROR, "La tabla Universidades no existe");
	ver2(interfaz->join("Alumnos", "Materias", "Carreras"), ERROR, "La tabla Carreras ya existe");
	ver2(interfaz->join("Alumnos", "Materias", "MateriasIntersectAlumnos"), ERROR, "Las tablas tienen distintos nombres y calificadores");
	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error join");
}

void PruebasEjemploDeUso::pruebasERROR8()
{
	//cout<<"\n\n";
	//cout<<"**************** PRUEBA ERROR10 ****************\n";
	//cout<<"Pruebas de error de los listados\n";
	//cout<<"************************************************\n\n";

	this->mImpresion.iniciarSeccion("PRUEBAS error listados");

	InterfazDelSistema* interfaz;
	interfaz = new InterfazDelSistemaImp(20);
	cargarBaseDeDatos(interfaz);
	ver2(interfaz->printDataTable("Universidades"), ERROR, "La tabla Universidades no existe");
	ver2(interfaz->printMetadata("Universidades"), ERROR, "La tabla Universidades no existe");

	delete interfaz;

	this->mImpresion.cerrarSeccion("PRUEBAS error listados");
}


void PruebasEjemploDeUso::cargarBaseDeDatos(InterfazDelSistema *interfaz)
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



void PruebasEjemploDeUso::cargarTablas(InterfazDelSistema *interfaz)
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
	interfaz->insertInto("Materias", "Programacion 1:5555:1");
	interfaz->insertInto("Materias", "Programacion 2:6666:2");
	interfaz->insertInto("Materias", "Matematica:7777:2");
	interfaz->insertInto("Materias", "Ingenieria De Software:8888:1");
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

