/* \par Fichero: monomio.hpp
	Monomio representa la clase monomio
*/

#ifndef MONOMIO__HPP_
#define MONOMIO__HPP_

#include <iostream>
#include <cmath>
#include "monomiointerfaz.hpp"



//! \attention Se incluye la clase Monomio dentro del espacio de nombre ed
namespace ed{

//! Definición de la clase Monomio
class Monomio:public MonomioInterfaz {

	//! \name Atributos privados de la clase Monomio
	private:
		double _coeficiente; //!< coeficiente del monomio
		int _grado; //!< grado del monomio

	//! \name Métodos públicos de la clase Monomio
	public:

		//! \name Constructores de la clase Monomio

		/*!
			\brief Contructor que crea un monomio a partir del coeficiente y del grado
			\attention Función sobrecargada
			\note Los parámetros tienen valores por defecto
			\param coef double, valor por defecto 0.0
			\param grado int, valor por defecto 0
			\pre Ninguna
			\post Ninguna
			\sa setCoeficiente(), setGrado()
		*/
		inline Monomio (double coef=0.0, int grado=0)
		{
			setCoeficiente(coef);
			setGrado(grado);
		}
		/*!
			\brief Contructor que crea un monomio a partir de otro monomio pasado por referencia
			\attention Función sobrecargada
			\param p Monomio, Monomio pasado por referencia
			\pre Ninguna
			\post Ninguna
			\sa setCoeficiente(), setGrado(), getGrado(), getCoeficiente()
		*/
		inline Monomio (Monomio const &p)
		{
			setCoeficiente(p.getCoeficiente());
			setGrado(p.getGrado());
		}

		/*!
			\brief Devuelve el coeficiente de un monomio
			\return Coeficiente de un monomio
			\pre El monomio debe existir anteriormente
			\post Ninguna
			\sa getGrado()
		*/
		inline double getCoeficiente() const
		{
			return _coeficiente;
		}

		/*!
			\brief Devuelve el grado de un monomio
			\return Grado de un monomio
			\pre El monomio debe existir
			\post Ninguna
			\sa getCoeficiente()
		*/
		inline int getGrado() const
		{
			return _grado;
		}

		/*!
			\brief Asigna un valor "coeficiente" al coeficiente de un monomio
			\param coeficiente double pasado por referencia constante
			\pre El monomio debe existir
			\post Ninguna
			\sa setGrado()
		*/
		inline void setCoeficiente(const double & coeficiente)
		{
			_coeficiente = coeficiente;
		}

		/*!
			\brief Asigna un valor "grado" al grado de un monomio
			\param grado int pasado por referencia constante
			\pre El monomio debe existir
			\post Ninguna
			\sa setCoeficiente()
		*/
		inline void setGrado(const int & grado)
		{
			_grado = grado;
		}

		//! /name Operadores

		/*!
			\brief Operador de copia de monomio en otro
			\attention Se sobrecarga el operador de asignacion
			\param p Monomio pasado por referencia constante
			\pre El monomio debe existir
			\post Ninguna
			\sa getGrado(), getCoeficiente(), setGrado(), setCoeficiente()
		*/
		inline Monomio &operator = (Monomio const &p)
		{
			setCoeficiente(p.getCoeficiente());
			setGrado(p.getGrado());

			return *this;
		}

		/*!
			\brief Operador producto de dos monomios
			\attention Se sobrecarga el operador producto
			\param p Monomio pasado por referencia constante
			\pre El monomio debe existir
			\post Ninguna
			\sa getGrado(), getCoeficiente(), setGrado(), setCoeficiente()
		*/
		inline Monomio operator * (Monomio const &p)
		{
			Monomio aux;
			int grado = getGrado()+p.getGrado();
			double coeficiente = getCoeficiente()*p.getCoeficiente();
			aux.setGrado(grado);
			aux.setCoeficiente(coeficiente);
			return aux;
		}

		//! \name Funciones lectura y escritura de la clase Punto2D

		/*!
			\brief Asigna el grado y el coeficiente a un monomio
			\pre El monomio debe existir
			\post Ninguna
			\sa setGrado(), setCoeficiente()
		*/
		void leerMonomio();

		/*!
			\brief Escribe los valores de un monomio por pantalla
			\pre El monomio debe existir
			\post Ninguna
			\sa getGrado(), getCoeficiente()
		*/
		void escribirMonomio();

		/*!
			\brief Calcula el valor de un monomio dado un valor x
			\param x double
			\pre El monomio debe existir
			\post Ninguna
			\sa getGrado(), getCoeficiente()
		*/
		double valorMonomio (double x);

		//! \name Funciones amigas para poder acceder a la parte privada de Monomio

		/*!
			\brief Sobrecarga del operador de salida "<<"
			\attention Funcion amiga de la clase Monomio
			\param stream ostream, flujo de salida
			\param p Monomio, pasado por referencia constante
			\pre El monomio debe existir
			\post Se escribe por pantalla el coeficiente y el grado de un monomio
			\sa operator >>
		*/
		friend ostream &operator << (ostream &stream, Monomio const &p);

		/*!
			\brief Sobrecarga del operador de entrada ">>"
			\attention Funcion amiga de la clase Monomio
			\param stream istream, flujo de entrada
			\param p Monomio, pasado por referencia
			\pre El monomio debe existir
			\post Se le asignan los valores coeficiente y grado a un monomio
			\sa operator <<
		*/
		friend istream &operator >> (istream &stream, Monomio &p);
};

}
#endif
