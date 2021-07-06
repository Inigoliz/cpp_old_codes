/* Sistema de EDOs que simula la interaccion de redes nueronales */

#include <string.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib> // para numeros aleatorios
using namespace std;

#include "mivector.h"
#include "RK2_neuronas.cxx"

const int N = 10;

/////////////////////////////// f(t,x)////////////////////////////////
mivector<double> f(double t, mivector<double> x){
  double J[N][N];
  mivector<double> aux(N);
  double sum;


  double sigma=100,mu=0,rx,ru; double rt,rs,rho,theta,pi=acos(-1.0);
      //Seed for random number generator.
        srand(5);

  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){


      //Generation of random number.
          ru = double(rand())/RAND_MAX;
          rt = - log(1.0 - ru);
          ru = double(rand())/RAND_MAX;
          rs = ru;
          rho = sigma * sqrt(2 * rt);
          theta = 2 * pi * rs;
          rx = rho * cos(theta) + mu;
          J[i][j]=rx;
    }
  }

  for (int i=0;i<N;i++){
    sum=0.0;
    for (int j=0;j<N;j++){
      sum=sum+J[i][j]*tanh(x[j]);
    }
    aux[i]=-x[i]+sum;
  }
  return aux;
}
/////////////////////////////////////////////////////////////////////



int main(){
  cout<<setprecision(15);
  const int ndim = N; // numero de variables a evaluar
  const int n = 300; // numero de pasos dados
  double tau = 0.1;
  const double t0 = 0;


  mivector<double> x0(ndim); // condiciones iniciales
  x0[0] = 1;
  for(int i = 1; i<ndim; i++){
    x0[i] = 0;
    }

  mivector<double> *xrk2;
  xrk2 = new mivectores<double,ndim>[n]; // objeto de ndim filas que guarda 300 instantes de tiempo

  RK2_neuronas(f, t0, x0, tau, n, ndim, xrk2);


  FILE *datos;
  datos=fopen("Neuronas.dat","w");
  fprintf(datos, "tiempo (s) \t\t NEURONA 1 \t\t NEURONA 2 \t\t NEURONA 3 \n");

  for(int i = 0; i<n; i++){
    //fprintf(datos, "%f \t %.15e \t %.15e \t %.15e \n", t0+double(i)*tau, xrk2[i][0], xrk2[i][1], xrk2[i][3]);
    fprintf(datos, "%f \t %.15e \t %.15e \t %.15e \n", t0+double(i)*tau, abs(xrk2[i][0]), abs(xrk2[i][1]), abs(xrk2[i][3]));
  }
 cout<<"Hecho"<<endl;
}
