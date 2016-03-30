#include <iostream>
#include <vector>

#include "polinomio.hpp"
#include "monomio.cpp"
using namespace std;
using namespace ed;

void Polinomio::leerPolinomio(){
  vector <Monomio> vector;
  Monomio monomio;
  cout << "Para terminar introducir los valores como 0" << endl;
  do{
    monomio.leerMonomio();
    if (monomio.getCoeficiente() != 0){
      vector.push_back(monomio);
    }
  }while(monomio.getCoeficiente() !=0 );

  setPolinomio(vector);
  setTerminos(vector.size());
  calcularGrado();


}

void Polinomio::escribirPolinomio(){
  Monomio aux;
  cout << "Grado: " << getGrado() <<endl;;
  cout << "Terminos: " << getTerminos() << endl;
  cout << "Vector: " ;
  for(int i=0; i < getTerminos(); i++){
    aux = getMonomio(i);
    cout << aux;
    if (i < getTerminos()-1){
        cout << "+";
    }
  }
  cout << endl;
}

double Polinomio::valorPolinomio(double x){
  double suma=0;
  Monomio monomio;
  for (int i=0; i< getTerminos(); i++){
    monomio = getMonomio(i);
    suma = suma + monomio.valorMonomio(x);
  }

  return suma;
}

void Polinomio::calcularGrado(){
  Monomio aux;
  int grado = 0;
  for (int i=0; i<getTerminos();i++){
    aux = getMonomio(i);
    if (aux.getGrado() > grado){
      grado = aux.getGrado();
    }
  }
  setGrado(grado);

}

vector <Monomio> Polinomio::sumaVector(vector <Monomio> &p){
  vector <Monomio> suma;
  Monomio msuma;
  double aux;
  int i = 0, tam = p.size();
  do{
    aux = p[i].getCoeficiente();
    for (int j = i+1; j < tam; j++){
      if (p[i].getGrado() == p[j].getGrado()){
        aux = aux + p[j].getCoeficiente();
        p[j].setGrado(0);
        p[j].setCoeficiente(0);
      }
    }

    msuma.setGrado(p[i].getGrado());
    msuma.setCoeficiente(aux);
    suma.push_back(msuma);

    i++;
  }while (i < tam);
  int tams = suma.size();
  for (i = 0; i < tams; i++){
    if (suma[i].getCoeficiente()==0){
      suma.erase(suma.begin()+i);
      i--;
    }
  }
  return suma;
}
namespace ed{
ostream &operator << (ostream &stream, Polinomio const &p)
{
  stream << "Grado: ";
  stream << p._grado;
  stream << endl;
  stream << "Terminos: ";
  stream << p._terminos;
  stream << endl;
  stream << "Polinomio: ";

  for (int i=0; i < p.getTerminos(); i++){
     stream << p.getMonomio(i);
     stream << "+";
  }
  stream << endl;
  return stream;
}

istream &operator >> (istream &stream, Polinomio &p);

}
