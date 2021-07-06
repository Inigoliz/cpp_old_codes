/* Resolucion del primer problema del examen por Jacobi*/


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
#include "jacobi1.cxx" // metodo jacobi
#include "gauss1.cxx" // metopdo gauss-seidel

int main(){

  ofstream resultados("solucion.dat"); // documento en que se imprimiran los resultados
  cout<<setprecision(10); // imprime 10 decimales por pantalla

 const int n = 5; // dimension de las matrices
 double eps = 1e-10; // precision buscada (variara a lo largo del programa)
 int ite = 0; // numero de iteraciones (se inicializara a 0 antes de cada nueva ejecucion)

 // MATRICES DE ENTRADA, que pasan como vectores de C++, no como matrices de matrix.h (me parece mas flexible asi, pues

 //////////////////// JACOBI ////////////////

  double A[n*n] = {9,3,-2,2,0.5,1.6,11,4,-1.2,2,2,3,12,2.3,-3,-1,3,-2,16,6,2,2,3,-4,15};
  double B[n] = {1.7,3.3,2.3,6.6,5.1};
  double X[n] = {}; // vector de soluciones de Jacobi

  ite = 0; // se asegura de que este a 0 al comenzar

 for(eps; eps<=1e-2; eps = eps*10){
    ite = 0;

    jacobi(A, B, X, n, eps, ite);

    resultados<<"Numero de iteraciones: "<<ite<<"; eps: "<<eps<<endl<<endl;
    resultados<<"XJacobi:"<<endl;
    for(int i=0; i<n; i++){ // saca los resultados en texto
      resultados<<" "<<X[i]<<" ";
     }
    resultados<<endl;
    ite = 0;

    gauss(A, B, X, n, eps, ite);

    resultados<<"XGauss:"<<endl;
    for(int i=0; i<n; i++){ // saca los resultados en texto
      resultados<<" "<<X[i]<<" ";
     }
    resultados<<endl<<endl;
   }

}
