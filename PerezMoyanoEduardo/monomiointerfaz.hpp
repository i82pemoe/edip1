/*  \par Fichero: monomiointerfaz.hpp
  Representa la clase abstracta MonomioInterfaz
*/

#ifndef MONOMIOINTERFAZ__HPP_
#define MONOMIOINTERFAZ__HPP_

#include <iostream>
using namespace std;

namespace ed{

class MonomioInterfaz{
	public:
		virtual double getCoeficiente()const=0;
		virtual int getGrado()const=0;
		virtual void setCoeficiente(const double & coeficiente)=0;
		virtual void setGrado(const int & grado)=0;
};
}

#endif
