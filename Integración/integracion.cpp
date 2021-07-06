// Sketch para evaluar integrales

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

// funciones

#include "trapezoidal.cxx"
#include "simpson.cxx" // el mejor
#include "cuadratura_gauss.cxx"


/////////////////////////// Función a integrar //////////////////////
double f(double x){
  return 1/sqrt(2*3.141592)*exp(-x*x/2);
}
/////////////////////////////////////////////////////////////////////

int main(){
  cout<<setprecision(15);
  double a = 5; // limite inferior de integracion
  double b = 30; // limite superior de integracion
  int n = 100000; // numero de subdivisiones
  //double integralT = 0; // valor de la integra Trapezoidal
  double integralS = 0; // valor de la integral Simpson
  //double integralG = 0; // valor de la integral Gauss

  //trapezoidal(f, a, b, n, integralT);
  //cout<<"Valor para el metodo trapezoidal "<<integralT<<endl;

  simpson(f, a, b, n, integralS);
  cout<<"Valor para el metodo de Simpson "<<integralS<<endl;

  //cuadratura_gaussiana(f, a, b, integralG);
  //cout<<"Valor para el metodo de Gauss "<<integralG<<endl;
  //cout<<"Error para el metodo de Gauss "<<integralG-integralS<<endl;
}
