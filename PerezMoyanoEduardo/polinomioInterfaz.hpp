/*  \par Fichero: polinomioInterfaz.hpp
  Representa la clase abstracta PolinomioInterfaz
*/

#ifndef POLINOMIOINTERFAZ__HPP_
#define POLINOMIOINTERFAZ__HPP_

#include <iostream>
#include <vector>

#include "monomio.hpp"

using namespace std;


namespace ed{
  class PolinomioInterfaz{
    virtual int getTerminos()const=0;
		virtual int getGrado()const=0;
    virtual Monomio getMonomio(const int i) const = 0;
    virtual vector <Monomio> getPolinomio() const = 0;
		virtual void setTerminos(const int &terminos)=0;
		virtual void setGrado(const int & grado)=0;
    virtual void setPolinomio(const vector <Monomio> &p) = 0;
    virtual bool testPolinomio()=0;
  };
}

#endif
