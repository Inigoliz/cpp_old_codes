/* 17-11-16 */
/* Script para probar "diagonaliza.cxx", metodo de Jacobi para diagonalizar matrices simetricas (pues son siempre diagonalizables) */


// Estos codigos son para que funcione matrix.h
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "matrix.h"
using namespace math;

#include "maxMat.cxx"
#include "diagonaliza.cxx"


int main(){
  double eps = 1e-7; // precisión del metodo
  const int n = 5; //  dimension de la matriz
  // const int n = 3;
  int ite = 0;
   double entrada[n*n] = {8,-2,3,-1,1,-2,4,1,-1,-3,3,1,7,2,3,-1,-1,2,9,4,1,-3,3,4,12}; // matriz A de entrada, fila a fila
  // double entrada[n*n] = {-1, 0, 0, 3, 1, 0, 4, 2, -3};
  matrix<double> A(n,n); // se rellena despues
  matrix<double> lambda(n,1); // fila que guarda los autovalores
  matrix<double> vect(n,n); // cada columna es un autovector
  A.Null();
  lambda.Null();
  vect.Unit(); // IMP: se inicializa en la unidad para que converja

  for(int i = 0; i<n; i++){ // rellena A
    for(int j = 0; j<n; j++){
      A(i,j) = entrada[i*n+j];
    }
  }

  cout<<A<<endl;

  diagonaliza(A, lambda, vect, n, eps, ite);

  cout<<lambda<<endl;
  cout<<vect<<endl;

  /////////////////// COMPROBACION//////////////

  matrix<double> vtemp(n,1);

  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      vtemp(j,0) = vect(j,i); // coge las columnas 1 a 1 para comprobar
    }
    if((A*vtemp/lambda(i,0)-vtemp).Norm()<0.01){ // Av/lambda = v
      cout<<"Autovector "<<i<<" correcto"<<endl;
    }
  }

}
