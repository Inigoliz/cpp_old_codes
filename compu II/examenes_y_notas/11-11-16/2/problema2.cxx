/* Problema 2 del examen*/

/* Programa para testear los metodos de busqueda de ceros de una funcion;
   en func se declara la funcion, y las diferentes soluciones correponden a todos los metodos de solucion: biseccion, Newton y secante*/


#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

// Se insertan las funciones

#include "newton1.cxx"


//////////////////////////// Funcion para derivar///////////////////
double func(double x){
  return x*x+5*x+3-exp(x);
}

double funcder(double x){ // derivada de la funcion diferencia
  return 2*x+5-exp(x);
}
///////////////////////////////////////////////////////////////////

int main(){

  cout<<setprecision(6);

  // Como la ecuacion es de 2º grado, puede que tenga mas de una solucion
  // Se pinta la grafica con Gnuplot para tener una idea de que puntos de partida poner
  ofstream xy("fx.dat"); // tabla de datos x e y
  ofstream tabla("/Users/inigo/Documentos/Programación/compu II/examenes_y_notas/11-11-16/2/tabla.dat"); //  iteraciones en funcion del punto de partida
  tabla<<"1ºcol: punto de partida(p); 2º col: numero de iteraciones"<<"3º col: solucion hallada"<<"\n"<<endl; // se escribe una explicacion en la cabecera

  // Estas lineas son para pintar la funcion en un intervalo [a,b]
  double a = -3; // [-5,5] es un intervalo donde se encuentran 2 ceros
  double b = 2;
  double paso = 0.01;

  for(double i = a; i < b; i = i+paso){
    double x = i;
    double y = func(i);
    xy<<x<<" "<<y<<endl;
  }
  cout<<funcder(-2.4)<<" "<<funcder(2.3)<<endl;
  double eps = 1e-5; // precision buscada

  // Para hacer la tabla, se usan las siguintes
  double sol = 0.0; // solucion que se utiliza para hacer la tabla
  int ite = 0; // iteraciones que se usan para hacer la tabla. Cambiaran segun el punto de partida p
  double p = -5; // se empieza partiendo de -5
  double h = 0.1; // los distintos puntos de partidas distan entre si 0.1

 ////////////// NEWTON. TABLA ////////////////

  while(p<=5){
    ite = 0;
    sol = newton(func, funcder, p, eps, ite);
    tabla<<p<<"  ||  "<<ite<<"  ||  "<<sol<<endl;
    p = p+h;
  }

}
