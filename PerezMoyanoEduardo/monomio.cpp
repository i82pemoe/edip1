#include <iostream>
#include "monomio.hpp"

using namespace std;
using namespace ed;

void Monomio::leerMonomio(){
	double coef;
	int grado;

	cout << "Introduzca coeficiente:" << endl;
	cin >> coef;

	setCoeficiente(coef);

	cout << "Introduzca grado:" << endl;
	cin >> grado;

	setGrado(grado);
}

void Monomio::escribirMonomio(){
	cout << getCoeficiente() << "x" << getGrado() << endl;
}

double Monomio::valorMonomio (double x){

	double resultado;

	resultado = pow(x, getGrado()) *getCoeficiente();
	return resultado;
}

namespace ed{
ostream &operator << (ostream &stream, Monomio const &p)
{
	stream << p._coeficiente;
	stream << "x";
	stream << p._grado;
	return stream;
}


istream &operator >> (istream &stream, Monomio &p)
{
	cout << "Introduce coeficiente: ";
	stream >> p._coeficiente;
	cout << "Introduce grado: ";
	stream >> p._grado;

	return stream;
}
}
