/* Resolucion del primer problema del examen*/


// Estos codigos son para que funcione matrix.h
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "matrix.h"
using namespace math;


// CUIDADO CON EL ORDEN EN QUE SE DECLARAN ESTOS TRES. jacobi1 y gauss1 usan normaMat1
#include "normaMat1.cxx" // calculo norma de matriz
#include "gauss1.cxx" // metodo Gauss-Seidel

int main(){

  ofstream resultados("solucionGauss.dat"); // documento en que se imprimiran los resultados
  cout<<setprecision(10); // imprime 10 decimales por pantalla

  const int n = 5; // dimension de las matrices
  const double eps = 1e-10; // precision buscada (variara a lo largo del programa)
  int ite = 0; // numero de iteraciones (se inicializara a 0 antes de cada nueva ejecucion)

  // MATRICES DE ENTRADA, que pasan como vectores de C++, no como matrices de matrix.h (me parece mas flexible asi, pues


  //////////////////// GAUSS-SEIDEL/////////

  double AJ[n*n] = {9,3,-2,2,0.5,1.6,11,4,-1.2,2,2,3,12,2.3,-3,-1,3,-2,16,6,2,2,3,-4,15};
  double BJ[n] = {1.7,3.3,2.3,6.6,5.1};
  double XJ[n] = {}; // vector de soluciones de Jacobi

  ite = 0; // se asegura de que este a 0 al comenzar

  for(eps; eps<=1e-2; eps = eps*10){
    ite = 0;
    gauss(AJ, BJ, XJ, n, eps, ite);
    resultados<<"iteraciones"<<ite<<endl;
    for(int i=0; i<n; i++){
      cout<<XJ[i]<<endl;
      resultados<<"X:  "<<XJ[i]<<endl;
     }
   }

}


