/*  \par Fichero: monomiointerfaz.hpp
  Representa la clase abstracta MonomioInterfaz
*/

#ifndef MONOMIOINTERFAZ__HPP_
#define MONOMIOINTERFAZ__HPP_

#include <iostream>
using namespace std;

namespace ed{
//! Definición de la clase MonomioInterfaz
class MonomioInterfaz{
	//! \name Métodos públicos de la clase Monomio
	public:
		/*!
			\brief Devuelve el coeficiente de un monomio
			\return Coeficiente de un monomio
			\pre El monomio debe existir anteriormente
			\post Ninguna
			\sa getGrado()
		*/
		virtual double getCoeficiente()const=0;
		/*!
			\brief Devuelve el grado de un monomio
			\return Grado de un monomio
			\pre El monomio debe existir
			\post Ninguna
			\sa getCoeficiente()
		*/
		virtual int getGrado()const=0;
		/*!
			\brief Asigna un valor "coeficiente" al coeficiente de un monomio
			\param coeficiente double pasado por referencia constante
			\pre El monomio debe existir
			\post Ninguna
			\sa setGrado()
		*/
		virtual void setCoeficiente(const double & coeficiente)=0;
		/*!
			\brief Asigna un valor "grado" al grado de un monomio
			\param grado int pasado por referencia constante
			\pre El monomio debe existir
			\post Ninguna
			\sa setCoeficiente()
		*/
		virtual void setGrado(const int & grado)=0;
};
}

#endif
