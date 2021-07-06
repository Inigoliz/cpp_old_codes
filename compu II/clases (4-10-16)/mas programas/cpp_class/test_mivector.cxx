#include <iostream>
using namespace std;
#include "mivector.h"
int main(){
  const int n=5;
  mivector v(n),u(n),w(n);


  for (int i=0;i<n;i++){
    v[i]=i;
    u[i]=2*i;
  }

  w=v+u;

  for(int i=0;i<n;i++){
    cout<<w[i]<<endl;
  }

  double norma=w||0;
  cout<<"norma sup = "<<norma<<endl;
  norma=w||2;
  cout<<"norma cuadratica = "<<norma<<endl;

  w=v-u;
  for(int i=0;i<n;i++){
    cout<<w[i]<<endl;
  }

  double a=2.0;
  w=v*a;
  for(int i=0;i<n;i++){
    cout<<w[i]<<endl;
  }
  


  double b=v*u;
  cout<<b<<endl;


  // declaracion de vectores con varias componentes

  mivector *y, *x,*z; const int ndim=3,numv=3;
  y = new mivectores<ndim>[numv];
  x = new mivectores<ndim>[numv];
  z = new mivectores<ndim>[numv]; 

  y[0][0]=1.0; y[0][1]=1.0; y[0][2]=1.0; 
  y[1][0]=1.0; y[1][1]=-1.0; y[1][2]=1.0; 
  y[2][0]=1.0; y[2][1]=0.0; y[2][2]=1.0; 



  x[0]=y[0]; norma=x[0]||(2); z[0]=(1.0/norma)*x[0];
  x[1]=y[1]-(y[1]*z[0])*z[0]; norma=x[1]||(2); z[1]=(1.0/norma)*x[1];
  x[2]=y[2]-(y[2]*z[0])*z[0]-(y[2]*z[1])*z[1];
  norma=x[2]||(2); z[2]=(1.0/norma)*x[2];
  cout<<"************"<<endl;
  for(int i=0;i<numv;i++){
    for(int j=0;j<ndim;j++){
      cout<<z[i][j]<<endl;
    }
  }
}

