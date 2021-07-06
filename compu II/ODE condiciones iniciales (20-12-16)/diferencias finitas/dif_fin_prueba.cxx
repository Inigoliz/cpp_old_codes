/* Metodo de las diferencias finitas para resolver una ODE con condiciones de contorno.
Se resuelve con el metodo LU tridiagonal */

#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

#include "lu_trid.cxx"


//////////////////////////////// Funciones p, q y r ////////////////////////////////////
/* u''=pu'+qu+r */

double p(double x){
  //return x*x;
  //return 1-x*x; // Ec. Legendre
  //return 1; // Ec. Hermite
  return 1-x*x; // Ec. Chebyshev
}

double q(double x){
  //return (4-x*x/2);
  //return -2*x; // Ec. Legendre
  //return -2*x; // Ec. Hermite
  return -x; // Ec. Chebyshev
}

double r(double x){
  //return exp(-x*x);
  //return 2*(2+1); // Ec. Legendre
  //return 2*3*3; // Ec. Hermite
  return 3*3; // Ec. Chebyshev
}


int main(){
  const int n = 5000; // divisiones del intervalo

  // double a0 = 2; // punto de partida
  // double b0 = 3; // punto de llegada
  double a0 = 0; // punto de partida
  double b0 = 10; // punto de llegada
  double ua = 1; // u(a), condiciones de contorno
  double ub = 4; // u(b), condiciones de contorno
  double h = (b0-a0)/n; // tamaño del paso


  double d[n-1];
  double ds[n-1]; // diagonal superior. ULTIMO ELEMENTO A 0, IMP
  double df[n-1]; // diagonal inferior. PRIMER ELEMENTO A 0, IMP
  double b[n-1];
  double u[n-1]; // solucion buscada
  double x[n+1];

  for(int i=0; i<=n; i++){ // se divide [a,b] en n subdivisiones, cuyos valores se guardan en x (x0=a...xn=b)
    x[i] = a0 + double(i)*h;
  }
 
  for(int i=1; i<n; i++){
    d[i-1] = 2+h*h*q(x[i]);
    ds[i-1] = h/2*p(x[i])-1;
    df[i-1] = -(h/2*p(x[i])+1);
    b[i-1] = -h*h*r(x[i]);
  }
  ds[n-2] = 0; // ultimo elemento a 0
  df[0] = 0; // primer elemento a 0
  b[0] = -h*h*r(x[1])+(h/2*p(x[1])+1)*ua;
  b[n-2] = -h*h*r(x[n-1])-(h/2*p(x[n-1])-1)*ub; 
		      
  lu_trid(d, ds, df, b, u, n-1);

  // Exportar datos

  FILE *doc;
  doc=fopen("chebyshev.dat","w");
  fprintf(doc, " \t\t # x \t\t u(x) \n");

  fprintf(doc, " \t %.15e \t %.15e \n", x[0], ua);

  for(int i=0; i<n-1; i++){
    fprintf(doc, " \t %.15e \t %.15e \n", x[i+1], u[i]);
  }

  fprintf(doc, " \t %.15e \t %.15e \n", x[n], ub);

}
