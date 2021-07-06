/* Programa para probar la funcion "integral.cxx"*/

#include <string.h>
#include <iostream>
#include <fstream>
#include <cmath> // para acos(-1.0)

using namespace std;

#include "integral.cxx" // NO PONER ; TRAS #INCLUDE

/////////////////////////// Funcion a integrar /////////////////
double func(double x){
return 3.*sin(x);
}
////////////////////////////////////////////////////////////////


int main(){

  ////////////
  double f(double); // prototype de la funcion, si f se va a declarar despues del main()
  ////////////

  double a = 0;
  double b = acos(-1.0)/2; // PI/2
  double n = 5;

  double val = 0.0;

  val = integral(func, a, b, n);

  cout<<val<<endl;



}
