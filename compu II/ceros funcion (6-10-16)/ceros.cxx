/* Programa para testear los metodos de busqueda de ceros de una funcion;
   en func se declara la funcion, y las diferentes soluciones correponden a todos los metodos de solucion: biseccion, Newton y secante*/


#include <iostream>
#include <cmath>

using namespace std;

// Se insertan las funciones

#include "biseccion.cxx"
#include "newton.cxx"
#include "secante.cxx"


//////////////////////////// Funcion para derivar///////////////////
double func(double x){
  return x*x-1-cos(acos(-1.0)*x);
}

double funcder(double x){ // derivada de la funcion diferencia
  return 2*x+acos(-1.0)*sin(acos(-1.0)*x);
}
///////////////////////////////////////////////////////////////////

int main(){

  double eps = 0.00001; // precision buscada
  int i1; // iteraciones para biseccion
  int i2; // iteraciones para newton
  int i3; // iteraciones para secante
  double sol1 = 0.0; // solucion para metodo biseccion
  double sol2 = 0.0; // solucion para metodo Newton
  double sol3 = 0.0; // solucion para metodo secante

  ////////////// BISECCION ////////////////
  // a y b son los puntos entre los que se cree que esta la solucion
  double a = 0.0;
  double b = 1;
  sol1 = biseccion(func, a, b, eps, i1);

 ////////////// NEWTON ////////////////
  a = 0.2; // pues en 0.0 hay un maximo y no converge
  sol2 = newton(func, funcder, a, eps, i2);

 ////////////// SECANTE ////////////////
 // x0 y x1 son dos puntos entre los que se busca el 0, no tienen por que ser iguales a a y b, puede incluso que entre x0 y x1 no este la solucion
  double x0 = 0.0;
  double x1 = 1;

  sol3 = secante(func, x0, x1, eps, i3);

 ////////////// SALIDAS ////////////////
  cout<<"la solucion por biseccion es: "<<sol1<<" con "<<i1<<" iteraciones"<<endl;
  cout<<"la solucion por newton es: "<<sol2<<" con "<<i2<<" iteraciones"<<endl;
  cout<<"la solucion por secante es: "<<sol3<<" con "<<i3<<" iteraciones"<<endl;

}
