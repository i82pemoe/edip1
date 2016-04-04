/*  \par Fichero: polinomioInterfaz.hpp
  Representa la clase abstracta PolinomioInterfaz
*/

#ifndef POLINOMIOINTERFAZ__HPP_
#define POLINOMIOINTERFAZ__HPP_

#include <iostream>
#include <vector>

#include "monomio.hpp"




namespace ed{
  //! Definición de la clase PolinomioInterfaz

  class PolinomioInterfaz{
    //! \name Atributos publicos de la clase Polinomio
    public:
      /*!
        \brief Devuelve el numero de terminos de un polinomio
        \return Terminos de un polinomio
        \pre El polinomio debe existir anteriormente
        \post Ninguna
        \sa getGrado(), getMonomio(), getPolinomio()
      */
      virtual int getTerminos()const=0;
      /*!
        \brief Devuelve el grado del polinomio
        \return Grado de un polinomio
        \pre El polinomio debe existir anteriormente
        \post Ninguna
        \sa getTerminos(), getMonomio(), getPolinomio()
      */
  		virtual int getGrado()const=0;
      /*!
        \brief Devuelve el monomio del polinomio
        \return Monomio de un polinomio
        \param i int, posicion del monomio a devolver
        \pre El polinomio debe existir anteriormente
        \post Ninguna
        \sa getTerminos(), getGrado(), getPolinomio()
      */
      virtual Monomio getMonomio(const int i) const = 0;
      /*!
        \brief Devuelve el polinomio
        \return  polinomio de monomios
        \pre El monomio debe existir anteriormente
        \post Ninguna
        \sa getTerminos(), getMonomio(), getGrado()
      */
      virtual vector <Monomio> getPolinomio() const = 0;
      /*!
        \brief Asigna un valor "terminos" al numero de terminos de un polinomio
        \param terminos int pasado por referencia constante
        \pre El polinomio debe existir
        \post Ninguna
        \sa setGrado(), setPolinomio()
      */
  		virtual void setTerminos(const int &terminos)=0;
      /*!
        \brief Asigna un valor "grado" al grado de un polinomio
        \param grado int pasado por referencia constante
        \pre El polinomio debe existir
        \post Ninguna
        \sa setTerminos(), setPolinomio()
      */
  		virtual void setGrado(const int & grado)=0;
      /*!
        \brief Asigna un polinomio
        \param p vector Monomio pasado por referencia constante
        \pre El polinomio debe existir
        \post Ninguna
        \sa setGrado(), setTerminos(1)
      */
      virtual void setPolinomio(const vector <Monomio> &p) = 0;
      /*!
        \brief Comprueba si un polinomio esta vacio
        \pre El polinomio debe existir
        \post Ninguna
      */
      virtual bool testPolinomio()=0;
  };
}

#endif
