/* Compu 29-11-16 */
/* Programa para probar los metodos de integracion, sketch que integra una funcion */

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

// funciones
#include "trapezoidal.cxx"
#include "simpson.cxx"
#include "cuadratura_gauss.cxx"


//////////////////// Funcion /////////////////////////

double f(double x){
  return x*x*exp(-x);
}
/////////////////////////////////////////////////////


int main(){
  cout<<setprecision(15);
  double a = 0; // limite inferior de integracion
  double b = 1; // limite superior de integracion
  int n = 100; // numero de subdivisiones
  double integralT = 0; // valor de la integra Trapezoidal
  double integralS = 0; // valor de la integral Simpson
  double integralG = 0; // valor de la integral Gauss

  trapezoidal(f, a, b, n, integralT);
  cout<<"Valor para el metodo trapezoidal "<<integralT<<endl;

  simpson(f, a, b, n, integralS);
  cout<<"Valor para el metodo de Simpson "<<integralS<<endl;

  cuadratura_gaussiana(f, a, b, integralG);
  cout<<"Valor para el metodo de Gauss "<<integralG<<endl;
  cout<<"Error para el metodo de Gauss "<<integralG-integralS<<endl;



  /////////////////////////////////// 2º Parte ///////////////////////////

  ofstream errorS("errorSimpson.dat");
  ofstream errorT("errorTrapezoidal.dat");

  // Ahora se buscara el valor de divisiones, n, necesarias para que el metodo de Simpson respecto al metodo de Gauss de un error de "err"

  double err0 = 5.75e-13; // error buscado
  double err = 10; // punto de partida alto

  n = 100; // punto de partida, obtenido a ojo

  while(err>err0){
    integralS = 0.0;
    simpson(f, a, b, n, integralS);
    //trapezoidal(f, a, b, n, integralS);
    err = abs(2-5*exp(-1)-integralS);
    // cout<<n<<" "<<err<<endl;

    errorS<<n<<" "<<err<<endl; // saca los resultados

    n=n+2; // suma de 2 en 2, pues deben ser pares para Simpson
  }
  cout<<"numero de divisiones "<<n-2<<endl;

  /////////////////////////////////////////////////////////////////////
  // Lo mismo, pero con el metodo trapezoidal

  err0 = 5.75e-13; // error buscado
  err = 10; // punto de partida alto

  n = 100000; // punto de partida, obtenido a ojo

  while(err>err0){
    integralT = 0.0;
    trapezoidal(f, a, b, n, integralT);
    err = abs(2-5*exp(-1)-integralT);
    //cout<<n<<" "<<err<<endl;

    errorT<<n<<" "<<err<<endl; // saca los resultados

    n=n+100;
  }
  cout<<"numero de divisiones "<<n<<endl;

}
