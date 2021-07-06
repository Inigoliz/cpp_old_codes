/* SISTEMAS DE ECUACIONES NO LINEALES-(26-10-16)*/

// Estos codigos son para que funcione matrix.h
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
using namespace math;

#include "matrix.h"

#include "newtonraphson.cxx"

////////////////////////////////////////////////  Declaracion de f(v)=(f1(v),...fn(v))  //////////////////////////////////////////////
matrix<double> f(matrix<double> v, int dim){
  //x = a(0,0); y = a(1,0)
  matrix<double> fv(dim,1); // columna que guardara (f1(v),f2(v))
  fv(0,0) = pow(v(0,0),4)+pow(v(1,0),3)-pow(v(0,0),2)-4*pow(v(1,0),2)-6; // x4+y3-x2-4y2-6
  fv(1,0) = 4*pow(v(0,0),2)-2*pow(v(1,0),2)+3*v(0,0)+1; // 4x2-2y2+3x+1

  return fv;
}


/////////////////////////////////  Declaracion de jacobiano(v)=(j11(v),...j1n(v); ... ; jn1(v),...,jnn(v))  ///////////////////////////////////////
matrix<double> jacobiano(matrix<double> v, int dim){ // devuelve la matriz jacobiana evaluada en v a partir de j1,...jn, derivadas parciales del jacoibiano (que se obtienen analiticamente)
  matrix<double> j(dim,dim);
  j(0,0) = 4*pow(v(0,0),3)-2*v(0,0); // 4x3-2x
  j(0,1) = 3*pow(v(1,0),2)-8*v(1,0); // 3y2-8
  j(1,0) = 8*v(0,0)+3; // 8x+3
  j(1,1) = -4*v(1,0); //-4y

  return j;
}



int main(){
  // const int dim = 2;
  // int ite = 0;
  // const double eps = 1e-4;

  // matrix<double> X0(dim,1);
  // matrix<double> X(dim,1);
  // X0.Null();
  // X.Null();

  // // PUNTO DE PARTIDA:
  // X0(0,0) = -2;
  // X0(1,0) = 2;
  // ////////////////////
 
  // newtonraphson(f, jacobiano, X0, X, eps, dim, ite);

  // cout<<X<<endl;
  // cout<<ite<<endl;

  int dim = 2;
  matrix<double> A(dim,dim);
  matrix<double> B(dim,1);
  matrix<double> X(dim,1);

  A(0,0) = 2;
  A(0,1) = 1;
  A(1,0) = 1;
  A(1,1) = 3;
  B(0,0) = 7;
  B(1,0) = 11;

  lu_mat(A,B,X,dim);
  cout<<X<<endl;
}
