/* COMPU 1-12-16*/
/* Evaluacion de dos definiciones de derivada para comprobar los
   ordenes de precision (h2 en la primera, h4 la segunda)*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

//funciones
#include "derivada_h2.cxx"
#include "derivada_h4.cxx"

//////////////////// Funciones /////////////////////////

double f(double x){
  return x*x*exp(-x);
}

double fder(double x){ // derivada analitica de f(x)
  return 2*x*exp(-x)-x*x*exp(-x);
}
/////////////////////////////////////////////////////


int main(){

  double a = 0; // limite inferior de integracion
  double b = 4; // limite superior de integracion
  double h = 0.04; // precision de la derivada
  int n = 100; // numero de divisiones del intervalo [a,b]
  double y1 = 0.0; // variable temporal para guardar el valor de la derivada con h4
  double y2 = 0.0; // variable temporal para guardar el valor de la derivada con h4
  double y = 0.0; // guarda el valor analitico de la derivada
  double tau = (b-a)/(double(n));
  double x = 0.0; // recorre el intervalo de derivacion

  ofstream derivada("derivadas_h2_h4.dat");
  ofstream derivadaerr("error_h2_h4.dat");
  
  derivada<<setprecision(15);
  derivadaerr<<setprecision(15);
 
  derivada<<"# Comparacion derivada por los métodos h2 y h4"<<endl<<endl;
  derivada<<"# x"<<"\t"<<"f(x)"<<"\t"<<"h2"<<"\t"<<"h4"<<endl;
  derivadaerr<<"# Error entre el valor analítico y el calculado para los métodos h2 y h4"<<endl<<endl;
  derivadaerr<<"# x"<<"\t"<<"error h2"<<"\t"<<"error h42"<<endl;
  
    // Se calculara la derivada en x=a, x=a+tau, x=a+2*ta, ..., x = b => habra "n+1" puntos
  
  for(int i = 0; i<=n; i++){
    x = a + double(i)*tau; // da mas precision que x = x+tau, pues no acumula error
    y1 = derivadah2(f, x, h);
    y2 = derivadah4(f, x, h);
    y = fder(x);

    derivada<<x<<"\t"<<f(x)<<"\t"<<y1<<"\t"<<y2<<endl;
    derivadaerr<<x<<"\t"<<abs(y1-y)<<"\t"<<abs(y2-y)<<endl;
  }


  ///////////////////////// Comprobacion del orden de h ////////////////////

  x = 0.5; // valor en el que se evalua la derivada
  
  ofstream variarh("variar_h.dat");

  variarh<<setprecision(15);

  variarh<<"# Valores del error obtenidos para distintos valores de h en el punto x = "<<x<<endl<<endl;
  variarh<<"# h"<<"\t"<<"error h2"<<"\t"<<"error h4"<<endl;

  x = 0.5; // valor en el que se evalua la derivada
  
  for(int i = 0; i<=10; i++){
    h = 0.04+0.008*double(i);
    y1 = derivadah2(f, x, h);
    y2 = derivadah4(f, x, h);
    y = fder(x);
    variarh<<h<<"\t"<<abs(y-y1)<<"\t"<<abs(y-y2)<<endl;
  }

}
