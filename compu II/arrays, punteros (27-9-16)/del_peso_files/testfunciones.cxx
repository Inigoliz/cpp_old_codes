#include <iostream>
#include <cmath>
using namespace std;
#include "misfunciones.cxx"

double g(double x){
  return x*exp(-x);
}

int main(){
  //a2*x^2 + a1*x + a0 = 0
  double a2=1.0,a1=4.0,a0=1.0;
  int num_raices; double *R; R=new double[2];
  double parametros[3]={1.0,4.0,1.0};
  Rpol2(1.0,a1,a0,R,num_raices);
  //Rpol2a(parametros,R,num_raices);
  for(int i=1; i<=num_raices; i=i+1){
    cout<<"Raiz "<<i<<" es "<<R[i-1]<<endl;
  }


  double w[3]={1.3,7.2,5.4};
  cout<<maxelemento(w,3)<<endl;


  cout<<derivada(g,0.5)<<endl;
}
