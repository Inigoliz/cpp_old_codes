/* 25-10-16. COMPU 2:*/
/*METODO DE JACOBI para resolucion de sistemas de ecuaciones*/

/*NECESITA QUE ESTE DECLARADO EN EL PRINCIPAL "matrix.h" y todas sus librerias asociadas;
ejemplo de cabecera:

#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "matrix.h"
using namespace math;

#include "jacobi.cxx" // metodo jacobi
*/


// Mis scripts
#include "normaMat.cxx" // funcion que calcula la norma de una matriz de tipo matrix.h 

void jacobi(double *a, double *b, double *x, int n, double eps, int &ite){ // a, b y x son punteros que dirigen a las posiciones en el programa principal donde se han  guardado los elementos del sistema a resolver

  /*El programa toma vectores habituales de C++ y crea matrices de la clase matrix a partir de ellos.
    podria editarlo para que tomara directamente matrices, pero creo que es mas util de esta forma*/

  matrix<double> A(n,n);
  matrix<double> C(n,n);
  matrix<double> B(n,1);
  matrix<double> X0(n,1);
  matrix<double> X(n,1);
  matrix<double> Cinv(n,n); // inversa de C (que como es diagonal, es facil de calcular)
  matrix<double> Ide(n,n); // Identidad nxn
  matrix<double> Ide1(n,1); // Identidad nx1
  matrix<double> auxNorm(n,n); // matriz que guarda (1-Cinv*A), y despues llamando a normmat, nos devolvera su norma

  A.Null();
  B.Null();
  C.Null();
  Cinv.Null();
  X0.Null();
  X.Null();
  Ide.Null();
  Ide1.Null();
  auxNorm.Null();

  double norma = 0;

  // Rellena A, B y C, Cinv, Ide, Ide1
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      A(i,j) = a[i*n+j];
      }
    C(i,i) = a[i*n+i]; // en la diagonal los valores de A, en los demas 0
    Cinv(i,i) = 1/(a[i*n+i]);
    B(i,0) = b[i]; // los indices empiezan en 0!!
     Ide(i,i) = 1; // =1
     Ide1(i,0) = 1; // =1
    }

  auxNorm = (Ide - Cinv*A);
  norma = normaMat(auxNorm, n); // normaMat es una funcion que toma una matriz (matrix.h) y devuelve su norma


  /* Para testear*/
  // cout<<A(0,0)<<" "<<A(0,1)<<" "<<A(0,2)<<endl;
  // cout<<A(1,0)<<" "<<A(1,1)<<" "<<A(1,2)<<endl;
  // cout<<A(2,0)<<" "<<A(2,1)<<" "<<A(2,2)<<endl;
  // cout<<endl;
  // cout<<C(0,0)<<" "<<C(0,1)<<" "<<C(0,2)<<endl;
  // cout<<C(1,0)<<" "<<C(1,1)<<" "<<C(1,2)<<endl;
  // cout<<C(2,0)<<" "<<C(2,1)<<" "<<C(2,2)<<endl;
  // cout<<endl;
  // cout<<Cinv(0,0)<<" "<<Cinv(0,1)<<" "<<Cinv(0,2)<<endl;
  // cout<<Cinv(1,0)<<" "<<Cinv(1,1)<<" "<<Cinv(1,2)<<endl;
  // cout<<Cinv(2,0)<<" "<<Cinv(2,1)<<" "<<Cinv(2,2)<<endl;
  // cout<<endl;
  // cout<<Ide1(0,0)<<endl;
  // cout<<Ide1(1,0)<<endl;
  // cout<<Ide1(2,0)<<endl;
  // cout<<endl;
  // cout<<norma<<endl;

   if(norma<1){ // recurrencia
     do{
       ite++;
       X0 = X;
       X = Cinv*(B+(C-A)*X0);
     }while((X-X0).Norm()>eps);
   }
  else{
    cout<< "EL METODO NO CONVERGE"<<endl;
  }

   for(int i = 0; i<n; i++){
     x[i] = X(i,0); // guarda los valores calculado en el vector principal, para devolverlos al programa principal
   }

}
