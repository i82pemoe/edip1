#include <iostream>
#include <vector>
#include <algorithm>

#include "polinomio.hpp"

using namespace std;
using namespace ed;

int main(void){
 Polinomio p(0,0,0), producto, suma;

 cout << "Polinomio por defecto"  << endl;
 p.escribirPolinomio();

 cout << "Se va a leer el polinomio" << endl;
 p.leerPolinomio();
 Polinomio p2(p);

 cout <<endl<< "Polinomio por copia" << endl;
 p2.escribirPolinomio();


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
      cout << "Valor del polinomio: " << p2.valorPolinomio(x) << endl;
      break;

      case 2:
      cout << "Suma" << endl;
      p.escribirPolinomio();
      p2.escribirPolinomio();
      suma = p+p2;
      suma.escribirPolinomio();
      break;

      case 3:
      cout << "Producto" << endl;
      producto = p*p2;
      producto.escribirPolinomio();
      break;

      case 4:
      cout << "Polinomio producto" << endl;
      cout << producto;
      break;
   }

 }while(opcion != 0);

}
