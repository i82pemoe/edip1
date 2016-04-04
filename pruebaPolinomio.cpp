#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

#include "polinomio.hpp"
#include "macros.hpp"

using namespace std;
using namespace ed;

int main(void){
  BORRAR;
  Polinomio p(0,0,0), producto, suma, operador;

  cout << "Polinomio por defecto"  << endl;
  p.escribirPolinomio();

  cout << "Se va a leer el polinomio" << endl;
  p.leerPolinomio();
  Polinomio p2(p);

  cout <<endl<< "Polinomio por copia" << endl;
  p2.escribirPolinomio();

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
    cout << endl << endl;
    cout << "1.Valor polinomio dato concreto" << endl;
    cout << "2.Suma de polinomios" << endl;
    cout << "3.Multiplicacion de polinomios" << endl;
    cout << "4.Sobrecarga de operadores" << endl;
    cout << "0.Salir" << endl;

    cin >> opcion;

    switch(opcion){
     case 1:
      double x;
      cout << "Introduzca valor de x" << endl;
      cin >> x;
      BORRAR;
      std::cout << "Polinomio:\n" << p2 << std::endl;
      cout << "Valor del polinomio: " << p2.valorPolinomio(x) << endl;
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
      BORRAR;
      cout << "Suma" << endl;
      cout << "----" << endl;
      cout << "Primer operando" << endl;
      p.escribirPolinomio();
      cout << "\nSegundo operando" << endl;
      p2.escribirPolinomio();
      suma = p+p2;
      cout << "\nResultado" << endl;
      suma.escribirPolinomio();

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

      case 3:
      BORRAR;
      cout << "Multiplicacion" << endl;
      cout << "----" << endl;
      cout << "Primer operando" << endl;
      p.escribirPolinomio();
      cout << "\nSegundo operando" << endl;
      p2.escribirPolinomio();
      producto = p*p2;
      cout << "\nResultado" << endl;
      producto.escribirPolinomio();
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

      case 4:
      BORRAR;
      cin >> operador;
      cout << operador;
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

 }while(opcion != 0);

}
