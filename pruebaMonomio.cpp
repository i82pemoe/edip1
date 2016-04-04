#include <iostream>
#include <cstdio>
#include <string>

#include "monomio.hpp"
#include "macros.hpp"

using namespace ed;
using namespace std;


int main (void)
{
  // Monomio con constructor por defecto
  BORRAR;
  Monomio m1;



  Monomio m2;
  cout << "Se va a comprobar el uso de los constructores" << endl;
  m2.leerMonomio();

  Monomio m3(m2);

  cout << "Se escriben los monomios creados" << endl;
  cout << "Monomio constructor por defecto" << endl;
  m1.escribirMonomio();

  cout << "Monomio leido desde el teclado" << endl;
  m2.escribirMonomio();

  cout << "Monomio constructor de copia" << endl;
  m3.escribirMonomio();

  getchar();
  printf("Pulse ");
  SUBRAYADO;
  printf("ENTER");
  APAGA;
  printf(" para ");
  INVERSO;
  printf("Continuar");
  APAGA;
  getchar();
  BORRAR;

  int opcion = 0;
  do{
    cout << endl;
    cout << endl;
    cout << "1. Valor de un monomio para un valor concreto" << endl;
    cout << "2. Multiplicación monomios" << endl;
    cout << "0. Salir" << endl;

    cin >> opcion;

    switch(opcion){
      case 1:
        double x;
        cout << "Se usara el monomio leido anteriormente por teclado" << endl;
        m2.escribirMonomio();
        cout << "Introduzca valor de x" << endl;
        cin >> x;
        cout << "El monomio vale: " << m2.valorMonomio(x) << endl;
        getchar();
        printf("Pulse ");
        SUBRAYADO;
        printf("ENTER");
        APAGA;
        printf(" para ");
        INVERSO;
        printf("Continuar");
        APAGA;
        getchar();
        BORRAR;
        break;

      case 2:
        Monomio p1, p2, p3;
        cout << "Valores primer monomio" << endl;
        p1.leerMonomio();

        cout << "Valores segundo monomio" << endl;
        p2.leerMonomio();

        p3 = p1*p2;
        cout << "p3 = " << p1 << " * " << p2<< endl;
        cout << "Producto = " << p3 << endl;
        getchar();
        printf("Pulse ");
        SUBRAYADO;
        printf("ENTER");
        APAGA;
        printf(" para ");
        INVERSO;
        printf("Continuar");
        APAGA;
        getchar();
        BORRAR;
        break;
    }
  }while(opcion !=0);

}
