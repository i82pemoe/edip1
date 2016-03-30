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
	if ((getGrado() == 1) && (getCoeficiente() == 1)) {
		std::cout << "x" << std::endl;
	}
	else if ((getGrado() == 1) && (getCoeficiente()== -1)){
		std::cout << "-x" << std::endl;
	}
	else if(getCoeficiente() == 0){
		std::cout << "0" << std::endl;
	}
	else if (getGrado() == 0) {
		std::cout << getCoeficiente() << std::endl;
	}
	else if (getGrado() == 1){
		std::cout << getCoeficiente() << "x"<< std::endl;
	}
	else if(getCoeficiente() == 1){
		std::cout << "x^" << getGrado() << std::endl;
	}
	else if(getCoeficiente() == -1){
		std::cout << "-x^" << getGrado() << std::endl;
	}

	else{
		cout << getCoeficiente() << "x^"  << getGrado() << endl;
	}

}

double Monomio::valorMonomio (double x){
	double resultado;

	resultado = pow(x, getGrado()) *getCoeficiente();
	return resultado;
}

namespace ed{
ostream &operator << (ostream &stream, Monomio const &p)
{
	if ((p.getGrado() == 1) && (p.getCoeficiente() == 1)) {
		stream << "x";

	}
	else if ((p.getGrado() == 1) && (p.getCoeficiente()== -1)){
		stream << "-x";

	}
	else if(p.getCoeficiente() == 0){
		stream << "0";

	}
	else if (p.getGrado() == 0) {
		stream << p.getCoeficiente();
	}
	else if (p.getGrado() == 1){
		stream << p.getCoeficiente();
		stream << "x";


	}
	else if(p.getCoeficiente() == 1){
		stream << "x^";
		stream << p.getGrado();

	}
	else if(p.getCoeficiente() == -1){
		stream << "-x";
		stream << p.getGrado();


	}
	else{
		stream << p.getCoeficiente();
		stream << "x^";
		stream << p.getGrado();

	}

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
