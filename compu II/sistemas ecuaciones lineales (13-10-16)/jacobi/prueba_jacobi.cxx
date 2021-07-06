/* Script para probar JACOBI*/

// Estos codigos son para que funcione matrix.h
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "matrix.h"
using namespace math;

#include "jacobi.cxx" // metodo jacobi

int main(){

 const int n = 5; // dimension de las matrices
 const double eps = 1e-4; // precision buscada
 int ite = 0; // numero de iteraciones

 // MATRICES DE ENTRADA, que pasan como vectores de C++, no como matrices de matrix.h

  double A[n*n] = {12,3,-2,2,0.5,1.6,14,4,-1.2,2,2,3,17,2.3,-3,-1,3,-2,16,6,2,2,3,-4,20};
  double B[n] = {1.7,3.3,2.3,6.6,5.1};
 double X[n] = {}; // X, vale 0 inicialmente

 jacobi(A, B, X, n, eps, ite);

  for(int i=0; i<n; i++){
    cout<<X[i]<<endl;
  }
  cout<<endl<<ite<<endl; // numero de iteraciones

}
