#include "PruebasSem1.h"

#ifndef PRUEBASSEM1_CPP
#define PRUEBASSEM1_CPP

void PruebasSem1() {
	int nroPrueba = 1;
	int correctos = 0, error = 0;
	int correctosTotal = 0, errorTotal = 0, ejCorrectosTotal = 0, ejErrorTotal = 0;

	FrameworkA1::ver(PruebaSuma(2, 7, 9, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSuma(-8, 6, -2, nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaSuma", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	FrameworkA1::ver(PruebaImprimirTabla(7, 0, 6, "0*7=0;1*7=7;2*7=14;3*7=21;4*7=28;5*7=35;6*7=42", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(11, 1, 5, "1*11=11;2*11=22;3*11=33;4*11=44;5*11=55", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(0, 0, 0, "0*0=0", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(12, 10, 15, "10*12=120;11*12=132;12*12=144;13*12=156;14*12=168;15*12=180", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(5, 9, 9, "9*5=45", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(10, 0, 1, "0*10=0;1*10=10", nroPrueba), correctos, error);
	FrameworkA1::imprimirResultadoPrueba("PruebaImprimirTabla", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);

	cout << "----------------------------------------------"<<endl;
	cout << "----------------------------------------------"<<endl;
	cout << "PRUEBAS FUNCIONES " << endl;
	cout << "PRUEBAS FUNCIONES " << setw(48) << std::right << "RESULTADO SEM1 =>" << " CORRECTAS: " << setw(2) << std::right << ejCorrectosTotal << " INCORRECTAS: " << setw(2) << std::right << ejErrorTotal << endl;
	cout << "PRUEBAS FUNCIONES " << endl;
}

#endif
