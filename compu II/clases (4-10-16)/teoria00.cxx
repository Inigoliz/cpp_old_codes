/*
EJEMPLO CLASE
*/

#include <iostream>
#include <cmath>

using namespace std;

#include "mivector.cxx"

int main(){

 int ndim;
 cin >> ndim;
 
 double C[ndim];
 
 mivector V(ndim), U(ndim), W(ndim);
 // creacion de los tres vectores (objeto mi vector, no arrays!!!)
 
 cout << W.dim() << endl; // w.dim() devuelve dim de W

 V[0]=1.2; // asigna valor al primer elemento
 C[0]=V[0];
 // valor del primer elemento del vector V, equivale a V.operator[](0)

 W = V + U; // equivale a W=V.operator+(U)

 W = 5.4 * U; // equivale a W=operator*(5.4,U), funcion no de la clase

 W = U * 5.4; // equivale a W=U.operator*(5.4), funcion de la clase
}
