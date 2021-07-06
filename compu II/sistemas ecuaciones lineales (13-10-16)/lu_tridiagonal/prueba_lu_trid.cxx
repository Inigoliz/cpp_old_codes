/* Sketch para probra lu_trid.cxx */

/* MetodoLU para matrices tridiagonales (numeros en la diagonal principal, una por encima y otra por debajo*/


#include <iostream>

using namespace std;

#include "lu_trid.cxx"
#include "ax.cxx"

int main(){
  const int n = 5; // dimension
  double d[n] = {11,10,13,15,9};
  double ds[n] = {1,3,1,4,0}; // diagonal superior. ULTIMO ELEMENTO A 0, IMP
  double df[n] = {0,2,2,3,1}; // diagonal inferior. PRIMER ELEMENTO A 0, IMP
  double b[n] = {1,3,5,2,4};
  double x[n];
  double a[n*n] = {11,1,0,0,0,2,10,3,0,0,0,2,13,1,0,0,0,3,15,4,0,0,0,1,9};
  double xsol[n]; // si todo va bien, deberia devolver B

  lu_trid(d, ds, df, b, x, n);

  cout<<"Solucion"<<endl;
  for(int i = 0; i<n; i++){
    cout<<x[i]<<endl;
  }

  // Testeo con "ax.cxx"

  ax(a, x, xsol, n);

  cout<<"B"<<endl;
  for(int i = 0; i<n; i++){
    cout<<xsol[i]<<endl;
  }

}
