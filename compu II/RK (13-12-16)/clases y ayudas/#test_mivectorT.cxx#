/*
"The career of a young theoretical physicist consists of treating the
harmonic oscillator in ever-increasing levels of abstraction."
Sidney Coleman
*/

#include <iostream>
using namespace std;
#include "mivector.h"

int main(){

  const int n=5;
  mivector<double> v(n),u(n),w(n);

  for (int i=0;i<n;i++){
    v[i]=i;
    u[i]=2*i;
  }

  w=v+u;

  for(int i=0;i<n;i++){
    cout<<w[i]<<endl;
  }

  double a=3;

  w = a * w;

  cout << endl;

  for(int i=0;i<n;i++){
    cout<<w[i]<<endl;
  }

  // para crear vectores multidimensionales:

  mivector<double> *y;

  const int m=3;

  y = new mivectores<double,m>[n];

  cout << endl << "mivectores:" << endl;

  mivector<double> r(n);

  for(int j=0;j<m;j++){

    r[j] = j;
  }


  for(int i=0;i<n;i++){

    y[i] = r;

  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

    cout<<"i,j: " << i << " " << j << "  y[i,j]: " << y[i][j]<<endl;

    }

  }

  // mivector<double> f(double t, mivector<double> y){ ...


}
