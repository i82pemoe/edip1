#include <iostream>
#include <vector>

#include "polinomio.hpp"
#include "monomio.cpp"
using namespace std;
using namespace ed;

void Polinomio::leerPolinomio(){
  vector <Monomio> vector;
  Monomio monomio;
  int terminos;
  
  std::cout << "Introduzca numero de terminos a introducir" << std::endl;
  std::cin >> terminos;
  for(int i=0; i < terminos; i++){
    monomio.leerMonomio();
    vector.push_back(monomio);
  }

  setPolinomio(vector);
  setTerminos(terminos);
  calcularGrado();


}

void Polinomio::escribirPolinomio(){
  cout << "Grado: " << getGrado() <<endl;;
  cout << "Terminos: " << getTerminos() << endl;
  cout << "Vector: " ;
  for(int i=0; i < getTerminos(); i++){
    cout << getMonomio(i);
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

  // for (int i = 0; i < suma.size(); i++){
  //   if (suma[i].getCoeficiente()==0){
  //     suma.erase(suma.begin()+i);
  //     i--;
  //   }
  // }
  i = 0;
  while(i < tams){
    if(suma[i].getCoeficiente()==0){
      suma.erase(suma.begin()+i);
      tams --;
      i--;
    }
    i++;
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
     if (i < p.getTerminos()-1){
         stream << "+";
     }
  }
  stream << endl;
  return stream;
}

istream &operator >> (istream &stream, Polinomio &p){
  int num; //Numero de monomios a introducir;
  vector <Monomio> vector;
  Monomio mon;

  std::cout << "Introduzca numero de monomios" << std::endl;
  stream >> num;
  for(int i = 0; i < num; i++){
    stream >> mon;
    vector.push_back(mon);
  }
  p._polinomio = vector;
  p._terminos = num;
  p.calcularGrado();
  return stream;
}

}
