
#include "PruebasTAD.h"

PruebasTAD::PruebasTAD(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasTAD::~PruebasTAD()
{
	
}

const char* PruebasTAD::getNombre() const
{
	return "PruebasTAD";
}

void PruebasTAD::correrPruebaConcreta()
{
	pruebaListaPos();

	ListaOrd<int>* l;

	//l = new ListaOrdImp<int>();
	//pruebaListaOrd(l);
	//delete l;

	l = new ListaOrdImp2<int>();
	pruebaListaOrd(l);
	delete l;
}


void PruebasTAD::pruebaListaPos()
{
	this->mImpresion.iniciarSeccion("PRUEBAS LISTA POS");

	
	ListaPos<int>* l = new ListaPosImp<int>();


	//cout << "------------------- Prueba agregar principio ----------------------" << endl << endl << endl;
	
	l->AgregarPpio(4);
	l->AgregarPpio(5);

	cout << *l << endl;
	ver3("Imprimo la lista luego de agregar 2 datos al principio");

	
	//cout << "------------------- Prueba agregar fin ----------------------" << endl << endl << endl;
	
	l->AgregarFin(2);
	l->AgregarFin(1);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de agregar 2 datos al final");

	//cout << "------------------- Prueba agregar posición ----------------------" << endl << endl << endl;
	
	l->AgregarPos(3,2);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de agregar el dato 3 en la posición 2");

	
	//cout<<"--------------------Prueba largo de la lista-------------------"<<endl<<endl<<endl;
	
	cout << l->CantidadElementos()<<endl;
	ver3("Imprimo el largo de la lista");

	
	//cout<<"--------------------Prueba clon de la lista-------------------"<<endl<<endl<<endl;
	
	
	ListaPos<int>* clonL = l->Clon();
	cout << "Resultado Original: " << endl << *l<< endl << endl;
	cout << "Resultado Clon: " << endl << *clonL << endl;
	ver3("Imprimo el la lista original y su clon");
	
	ListaPos<int> *l2 = l->CrearVacia();
	cout<<"["<<*l2<<"]"<<endl;
	ver3("Imprimo luego de crearvacia");

	*l2 = *l;
	cout<<"["<<*l2<<"]"<<endl;
	ver3("Imprimo luego de =");
	
	//cout<<"--------------------Prueba == de la lista (iguales)-------------------"<<endl<<endl<<endl;

	if(*l==*clonL)
	{
		cout<<"La lista original es igual a la lista clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista original no es igual a la lista clon"<<endl<<endl<<endl;
	}
	ver3("Imprimo prueba de == sobre listas iguales");

	//cout<<"--------------------Prueba == de la lista (diferentes)-------------------"<<endl<<endl<<endl;
	clonL->BorrarPpio();

	if(*l==*clonL)
	{
		cout<<"La lista original es igual a la lista clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista original no es igual a la lista clon"<<endl<<endl<<endl;
	}
	cout << "Resultado Original: " << endl << *l<< endl << endl;

	cout << "Resultado Clon: " << endl << *clonL << endl;

	ver3("Imprimo prueba de == sobre listas distintas");

	*clonL = *l;
	cout << "Resultado Clon: " << endl << *clonL << endl;

	ver3("Imprimo clon luego de asignarle l");

	//cout<<"--------------------Prueba elemento principio-------------------"<<endl<<endl<<endl;
	

	cout << l->ElementoPpio()<<endl;
	ver3("Imprimo el principio de la lista");

	
	//cout<<"--------------------Prueba elemento fin-------------------"<<endl<<endl<<endl;
	

	cout << l->ElementoFin() <<endl;
	ver3("Imprimo el fin de la lista");

	
	//cout<<"--------------------Prueba elemento posición-------------------"<<endl<<endl<<endl;
	

	cout << l->ElementoPos(3) <<endl;
	ver3("Imprimo el elemento de la cuarta posición");
	
	
	//cout<<"--------------------Prueba eliminar elemento principio-------------------"<<endl<<endl<<endl;
	
	l->BorrarPpio();

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el principio");

	//cout<<"--------------------Prueba eliminar elemento fin-------------------"<<endl<<endl<<endl;
	
	l->BorrarFin();

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el fin");

	//cout<<"--------------------Prueba eliminar elemento posición-------------------"<<endl<<endl<<endl;
	
	l->BorrarPos(2);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el tercer elemento");

	
	//cout<<"--------------------Prueba eliminar elemento-------------------"<<endl<<endl<<endl;
	
	l->Borrar(3);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el elemento 3");

	
	//cout<<"--------------------Prueba posicion elemento-------------------"<<endl<<endl<<endl;
	
	cout << l->Posicion(4)<<endl;
	ver3("Imprimo la posicion del elemento 4");

	//cout<<"---------------------Prueba elemento pertenece ---------------------"<<endl<<endl<<endl;
	if(l->Existe(4))
	{
		cout<<"Elemento 4 pertenece  a la lista"<<endl<<endl<<endl;
	}else
	{
		cout<<"Elemento 4 no pertenece a la lista"<<endl<<endl<<endl;
	}

	ver3("Imprimo si el elemento 4 existe en la lista");

	//cout<<"---------------------Prueba elemento no pertenece ---------------------"<<endl<<endl<<endl;
	if(l->Existe(6))
	{
		cout<<"Elemento 6 pertenece  a la lista"<<endl<<endl<<endl;
	}else
	{
		cout<<"Elemento 6 no pertenece a la lista"<<endl<<endl<<endl;
	}

	ver3("Imprimo si el elemento 6 existe en la lista");
	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;
	
	if(l->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista se encuentra vacia");

	//cout<<"-------------------Prueba lista es vaciar ----------------------"<<endl<<endl<<endl;
	
	l->Vaciar();
	
	cout<<"["<<*l<<"]"<<endl<<endl<<endl;

	ver3("Imprimo la lista luego de vaciarla");

	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;
	
	if(l->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	
	ver3("Imprimo si la lista se encuentra vacia ");

	delete l;
	delete clonL;

	this->mImpresion.cerrarSeccion("PRUEBAS LISTA POS");
}

void PruebasTAD::pruebaListaOrd(ListaOrd<int>* l)
{
	this->mImpresion.iniciarSeccion("PRUEBAS LISTA ORD");

	//cout << "------------------- Prueba agregar elemento ----------------------" << endl << endl << endl;

	l->AgregarOrd(5);
	l->AgregarOrd(3);
	l->AgregarOrd(3);
	l->AgregarOrd(6);
	l->AgregarOrd(6);
	l->AgregarOrd(1);
	l->AgregarOrd(4);
	l->AgregarOrd(2);
	l->AgregarOrd(1);

	cout << *l << endl;
	ver3("Imprimo la lista luego de agregar 9 datos");


	//cout<<"--------------------Prueba largo de la lista-------------------"<<endl<<endl<<endl;

	cout << l->CantidadElementos() << endl;
	ver3("Imprimo el largo de la lista");


	//cout<<"--------------------Prueba clon de la lista-------------------"<<endl<<endl<<endl;


	ListaOrd<int>* clonL = l->Clon();

	cout << "Resultado Original: " << endl << *l << endl << endl;

	cout << "Resultado Clon: " << endl << *clonL << endl;

	ver3("Imprimo la lista original y su clon");
	////////////////////////////////////////////////////////////////////////////////////////
	ListaOrd<int>* listaIgual = l->CrearVacia();
	*listaIgual = *l;

	cout << "Resultado Original: " << endl << *l << endl << endl;

	cout << "Resultado lista obtenida operador =: " << endl << *listaIgual << endl;

	ver3("Imprimo la lista original y la obtenida");
	//cout<<"--------------------Prueba == de la lista (iguales)-------------------"<<endl<<endl<<endl;

	if (*l == *clonL)
	{
		cout << "La lista original es igual a la lista clon" << endl << endl << endl;
	}
	else
	{
		cout << "La lista original no es igual a la lista clon" << endl << endl << endl;
	}
	ver3("Imprimo prueba de == sobre listas iguales");

	//cout<<"--------------------Prueba == de la lista (diferentes)-------------------"<<endl<<endl<<endl;
	clonL->BorrarMinimo();

	if (*l == *clonL)
	{
		cout << "La lista original es igual a la lista clon" << endl << endl << endl;
	}
	else
	{
		cout << "La lista original no es igual a la lista clon" << endl << endl << endl;
	}

	ver3("Imprimo prueba de == sobre listas distintas");

	//cout<<"--------------------Prueba elemento principio-------------------"<<endl<<endl<<endl;


	cout << l->Minimo() << endl;
	ver3("Imprimo el principio de la lista");


	//cout<<"--------------------Prueba elemento fin-------------------"<<endl<<endl<<endl;


	cout << l->Maximo() << endl;
	ver3("Imprimo el fin de la lista");


	//cout<<"--------------------Prueba eliminar elemento principio-------------------"<<endl<<endl<<endl;

	l->BorrarMinimo();

	cout << *l << endl;
	ver3("Imprimo la lista luego de eliminar el principio");

	//cout<<"--------------------Prueba eliminar elemento fin-------------------"<<endl<<endl<<endl;

	l->BorrarMaximo();

	cout << *l << endl;
	ver3("Imprimo la lista luego de eliminar el fin");

	//cout<<"--------------------Prueba eliminar elemento-------------------"<<endl<<endl<<endl;

	l->Borrar(3);

	cout << *l << endl;
	ver3("Imprimo la lista luego de eliminar el elemento 3");


	//cout<<"--------------------Prueba recuperar elemento-------------------"<<endl<<endl<<endl;

	cout << l->Recuperar(2) << endl;

	ver3("Imprimo la recuperación del elemento 2");

	//cout<<"---------------------Prueba elemento pertenece ---------------------"<<endl<<endl<<endl;
	if (l->Existe(2))
	{
		cout << "Elemento 2 pertenece  a la lista" << endl << endl << endl;
	}
	else
	{
		cout << "Elemento 2 no pertenece a la lista" << endl << endl << endl;
	}
	ver3("Imprimo si el elemento 2 existe en la lista");
	//cout<<"---------------------Prueba elemento no pertenece ---------------------"<<endl<<endl<<endl;
	if (l->Existe(6))
	{
		cout << "Elemento 6 pertenece  a la lista" << endl << endl << endl;
	}
	else
	{
		cout << "Elemento 6 no pertenece a la lista" << endl << endl << endl;
	}

	ver3("Imprimo si el elemento 6 existe en la lista");
	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;

	if (l->EsVacia())
	{
		cout << "La lista se encuentra vacia" << endl << endl << endl;
	}
	else
	{
		cout << "La lista no se encuentra vacia" << endl << endl << endl;
	}

	ver3("Imprimo si la lista es vacia");
	/////////////////////////////////////////////////////////////////////////
	ListaOrd<int>* lVacia = l->CrearVacia();
	if (lVacia->EsVacia())
	{
		cout << "La lista se encuentra vacia" << endl << endl << endl;
	}
	else
	{
		cout << "La lista no se encuentra vacia" << endl << endl << endl;
	}

	ver3("Imprimo si la lista creada es vacia ");
	delete lVacia;
	/////////////////////////////////////////////////////////////////////////
	if (l->EsLlena())
	{
		cout << "La lista se encuentra llena" << endl << endl << endl;
	}
	else
	{
		cout << "La lista no se encuentra llena" << endl << endl << endl;
	}

	ver3("Imprimo si la lista esta llena");

	//cout<<"-------------------Prueba lista es vaciar ----------------------"<<endl<<endl<<endl;

	l->Vaciar();

	cout << "[" << *l << "]" << endl << endl << endl;

	ver3("Imprimo la lista luego de vaciarla");

	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;

	if (l->EsVacia())
	{
		cout << "La lista se encuentra vacia" << endl << endl << endl;
	}
	else
	{
		cout << "La lista no se encuentra vacia" << endl << endl << endl;
	}

	ver3("Imprimo si la lista es vacia");
	delete clonL;

	this->mImpresion.cerrarSeccion("PRUEBAS LISTA ORD");
}
