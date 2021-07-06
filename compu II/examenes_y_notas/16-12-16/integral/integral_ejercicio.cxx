/* Examen computacion II, 16-12-16. Grupo: Gregorio Herdoiza*/
/* Ejercicio integral */
/* Iñigo Lara */

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

// funciones
#include "simpson.cxx"

 double pi = acos(-1.0);

//////////////////// Funcion /////////////////////////

double f(double x){
  return 2/sqrt(pi)*exp(-x*x);
}
/////////////////////////////////////////////////////


int main(){
  cout<<setprecision(15);
  double a = 0; // limite inferior de integracion
  double b = 0.5; // limite superior de integracion
  int n = 30; // numero de subdivisiones inicial, se explica en la discusion

  ////////////////////////////// Evaluacion del error ////////////////////////

  // Se evalua la integral aumentando el nuemro de subdivisiones hasta que el resultado converja con un precision eps
  double eps = 1e-11;
  double val0 = 0.0;
  double val1 = 0.0;

  // Exportacion de datos:
  FILE *doc;
  doc=fopen("Simpon13.dat","w");
  fprintf(doc, "# subdivisiones (n) \t\t integral \t\t\t error \n");

  do{
    simpson(f, a, b, n, val0);
    n = n + 2;
    simpson(f, a, b, n, val1);
    fprintf(doc, "%.15e \t %.15e \t %.15e \n", double(n), val0, abs(val0-val1));

  }while(abs(val1-val0)>eps);

  cout<<"Valor para el metodo de Simpson "<<val1<<endl;


}
