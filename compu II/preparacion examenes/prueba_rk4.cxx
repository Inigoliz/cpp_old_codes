/* Script para probar el método Runge-Kutta 4, con el script "rk4.cxx"*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

#include "rk4.cxx"

//////////////////////// Aceleracion: acel = [x'', y''] /////////////////////

void acel(double *r, double *v, double *a){
  
  double gamm = 10000; //
  double R = sqrt(r[0]*r[0]+r[1]*r[1]);
  //cout<<R<<" "<<r[0]<<endl;
  a[0] = -1*gamm/(R*R*R)*r[0];
  // cout<<a[0]<<endl;
  a[1] = -1*gamm/(R*R*R)*r[1];
  

  //a[0] = 1;
  //a[1] = 1;

}

/////////////////////////////////////////////////////////////////////////////

int main(){

  cout<<setprecision(50);
  const int n = 2;

  double r[n]; // posicion, [x,y]
  double v[n]; // velocidad, [vx, vy]
  double a[n]; // aceleracion, [ax, ay]

  int ti = 0; // instante inicial
  int tf = 10; // instante final

  //double dt = 0.0001; // paso de tiempo MIRAR QUE OCURRE!!
  double dt = 1.0/1000.0; // paso de tiempo MIRAR QUE OCURRE!!
  cout<<(tf - ti)/dt<< " "<<dt<<endl;
  double pasos = (tf - ti)/dt; // cuantos pasos tiene que dar
  // double numno = 20; // cada cuantos pasos guarda datos (para no sobrecargar)

  /////////////////////// CONDICIONES INICIALES///////////////////////
  
  r[0] = 10; // x0
  r[1] = 10; // y0
  v[0] = 1; // vx0
  v[1] = 0; // vy0
  a[0] = 0;
  a[1] = 0;

  ////////////////////////////////////////////////////////////////////

  // cout<<pasos<<endl;
  rk4(acel, r, v, a, ti, tf, dt, n, pasos);

}
