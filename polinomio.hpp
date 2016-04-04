/*  \par Fichero: polinomio.hpp
  Representa la clase Polinomio
*/

#ifndef POLINOMIO__HPP_
#define POLINOMIO__HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include "polinomioInterfaz.hpp"


//! \attention Se incluye la clase Polinomio dentro del espacio de nombre ed
namespace ed{
//! Definición de la clase Polinomio
class Polinomio:public PolinomioInterfaz{
  //! \name Atributos privados de la clase Polinomio
  private:
    int _grado; //!< grado del polinomio
    int _terminos; //!< numeros de terminos del polinomio
    vector <Monomio> _polinomio; //!< monomios del polinomio

  //! \name Atributos publicos de la clase Polinomio
  public:

    /*!
			\brief Contructor que crea un polinomio a partir de otro polinomio pasado por referencia
			\attention Función sobrecargada
			\param p Polinomio, Polinomio pasado por referencia
			\pre Ninguna
			\post Ninguna
			\sa setGrado(), setTerminos(), setPolinomio(), getGrado(), getTerminos(), getPolinomio()
		*/
    inline Polinomio (Polinomio const &p){
      setGrado(p.getGrado());
      setTerminos(p.getTerminos());
      setPolinomio(p.getPolinomio());
    }

    /*!
      \brief Contructor que crea un polinomio a partir del grado, los terminos y el numero de terminos
      \attention Función sobrecargada
      \note Los parámetros tienen valores por defecto
      \param grado int, valor por defecto 0.0
      \param terminos int, valor por defecto 0
      \param n int, valor por defecto 0
      \pre Ninguna
      \post Ninguna
      \sa setGrado(), setTerminos()
    */
    inline Polinomio (int grado = 0, int terminos = 0, int n=0)
    {
      setGrado(grado);
      setTerminos(terminos);
      _polinomio.resize(n);
    }

    /*!
      \brief Devuelve el grado del polinomio
      \return Grado de un polinomio
      \pre El polinomio debe existir anteriormente
      \post Ninguna
      \sa getTerminos(), getMonomio(), getPolinomio()
    */
    inline int getGrado() const{
      return _grado;
    }

    /*!
      \brief Devuelve el numero de terminos de un polinomio
      \return Terminos de un polinomio
      \pre El polinomio debe existir anteriormente
      \post Ninguna
      \sa getGrado(), getMonomio(), getPolinomio()
    */
    inline int getTerminos() const{
      return _terminos;
    }

    /*!
      \brief Devuelve el monomio del polinomio
      \return Monomio de un polinomio
      \param i int, posicion del monomio a devolver
      \pre El polinomio debe existir anteriormente
      \post Ninguna
      \sa getTerminos(), getGrado(), getPolinomio()
    */
    inline Monomio getMonomio(const int i) const{
      return _polinomio[i];
    }

    /*!
      \brief Devuelve el polinomio
      \return  polinomio de monomios
      \pre El monomio debe existir anteriormente
      \post Ninguna
      \sa getTerminos(), getMonomio(), getGrado()
    */

    inline vector <Monomio> getPolinomio() const{
      return _polinomio;
    }


    /*!
      \brief Asigna un valor "terminos" al numero de terminos de un polinomio
      \param terminos int pasado por referencia constante
      \pre El polinomio debe existir
      \post Ninguna
      \sa setGrado(), setPolinomio()
    */
		inline void setTerminos(const int &terminos){
      _terminos = terminos;
    }

    /*!
      \brief Asigna un valor "grado" al grado de un polinomio
      \param grado int pasado por referencia constante
      \pre El polinomio debe existir
      \post Ninguna
      \sa setTerminos(), setPolinomio()
    */

		inline void setGrado(const int &grado){
      _grado = grado;
    }

    /*!
      \brief Asigna un polinomio
      \param p vector Monomio pasado por referencia constante
      \pre El polinomio debe existir
      \post Ninguna
      \sa setGrado(), setTerminos(1)
    */
    inline void setPolinomio(const vector <Monomio> &p){
      Monomio aux;
      int tam = p.size();
      for (int i=0; i<tam; i++){
        aux = p[i];
        _polinomio.push_back(aux);
      }
    }

    /*!
      \brief Comprueba si un polinomio esta vacio
      \pre El polinomio debe existir
      \post Ninguna
    */
    inline bool testPolinomio(){
      if (getTerminos() == 0)
        return true;
      else
        return false;
    }

    //! /name Operadores

		/*!
			\brief Operador de copia de un polinomio en otro
			\attention Se sobrecarga el operador de asignacion
			\param p Polinomio pasado por referencia constante
			\pre El polinomio debe existir
			\post Ninguna
			\sa setGrado(), setTerminos(), setPolinomio(), getGrado(), getTerminos(), getPolinomio()
		*/
    inline Polinomio &operator = (Polinomio const &p){
      setGrado(p.getGrado());
      setTerminos(p.getTerminos());
      setPolinomio(p.getPolinomio());

      return *this;
    }

    /*!
			\brief Operador de suma de dos polinomios
			\attention Se sobrecarga el operador de suma
			\param p Polinomio pasado por referencia constante
      \return Suma de dos polinomios
			\pre El polinomio debe existir
			\post Ninguna
			\sa setGrado(), setTerminos(), setPolinomio(), getGrado(), getTerminos(), getPolinomio()
		*/
    inline Polinomio operator + (Polinomio const &p){
      Polinomio psuma(0,0,0);
      vector <Monomio> vsuma, aux, m, m2;
      m = getPolinomio();
      m2 = p.getPolinomio();
      aux.insert( aux.end(), m.begin(), m.end() );
      aux.insert( aux.end(), m2.begin(), m2.end() );

      vsuma = aux;
      vsuma = sumaVector(aux);
      psuma.setPolinomio(vsuma);
      psuma.setTerminos(vsuma.size());
      psuma.calcularGrado();
      return psuma;
    }

    /*!
			\brief Operador de producto de dos polinomios
			\attention Se sobrecarga el operador de suma
			\param p Polinomio pasado por referencia constante
      \return Producto de dos polinomios
			\pre El polinomio debe existir
			\post Ninguna
			\sa setGrado(), setTerminos(), setPolinomio(), getGrado(), getTerminos(), getPolinomio()
		*/
    inline Polinomio operator * (Polinomio const &p){
      Polinomio producto;
      Monomio aux, p1, p2;
      vector <Monomio> v, res;
      for (int i = 0; i < getTerminos(); i++){
        for (int j=0; j< p.getTerminos(); j++){
          aux = getMonomio(i) * p.getMonomio(j);
          v.push_back(aux);
        }
      }
      res = sumaVector(v);
      producto.setPolinomio(res);
      producto.setTerminos(res.size());
      producto.calcularGrado();
      return producto;
    }

    /*!
			\brief Calcula el grado de un Polinomio y se lo asigna
			\pre El polinomio debe existir
			\post El grado del polinomio queda modificado
		*/
    void calcularGrado();

    /*!
			\brief Lee los valores de un polinomio por pantalla y se los asigna al Polinomio
			\pre El polinomio debe existir
			\post El polinomio es modificado
		*/
    void leerPolinomio();

    /*!
			\brief Escribe los valores de un polinomio por pantalla
			\pre El polinomio debe existir
			\post Ninguna
		*/
    void escribirPolinomio();

    /*!
			\brief Calcula el valor de un polinomio dado un valor
      \param x double, valor para calcular el polinomio
      \return Valor del polinomio
			\pre El polinomio debe existir
			\post Ninguna
		*/
    double valorPolinomio(double x);

    /*!
			\brief Suma los monomios de un vector dado
      \param p vector Monomio, vector que se debe sumar
      \return Polinomio sumado
			\pre El vector debe existir
			\post Ninguna
		*/
    vector <Monomio> sumaVector(vector <Monomio> &p);

    //! \name Funciones amigas para poder acceder a la parte privada de Monomio

    /*!
      \brief Sobrecarga del operador de salida "<<"
      \attention Funcion amiga de la clase Polinomio
      \param stream ostream, flujo de salida
      \param p Polinomio, pasado por referencia constante
      \pre El Polinomio debe existir
      \post Se escribe por pantalla el Polinomio
      \sa operator >>
    */
    friend ostream &operator << (ostream &stream, Polinomio const &p);

    /*!
			\brief Sobrecarga del operador de entrada ">>"
			\attention Funcion amiga de la clase Polinomio
			\param stream istream, flujo de entrada
			\param p Polinomio, pasado por referencia
			\pre El Polinomio debe existir
			\post Se le asignan los valores al polinomio
			\sa operator <<
		*/
    friend istream &operator >> (istream &stream, Polinomio &p);

};

}


#endif
