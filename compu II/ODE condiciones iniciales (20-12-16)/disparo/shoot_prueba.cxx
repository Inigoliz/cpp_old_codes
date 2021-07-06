/* Metodo de disparo para resolver una ODE con condiciones de contorno */

#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// Se insertan las funciones

#include "secante.cxx"
#include "mivector.h"
#include "RK2.cxx"

// VARIABLES GLOBALES (pues se utilizan en multiples funciones):

// Condiciones de contorno
const double ua = 0.5; // u(t=t0)
const double ub = 4.5; // u(t=tf)
const double t0 = 2; // instante inicial
const double tf = 3; // instante final

//para llamar a rk2
  const int ndim = 2; // hay dos variables en RK
  double tau = 0.01; //  paso de tiempo
  const int n = int((tf-t0)/tau+1); // Numero de divisiones. Se suma 1 para alcanzar tf

// IMP: cada vez que se va a llamar a rk2 hay que inicializar el puntero para guardar los datos. Se hace con:

/* mivector<double> *yrk2; // yrk2 = [v;u]
   yrk2 = new mivectores<double,ndim>[n]; // objeto de 2 filas que guarda 300 instantes de tiempo */


/////////////////////////////// f(t,y)////////////////////////////////
mivector<double> f(double t, mivector<double> y){
  // se descompone u'=v; u''=v'; y = [v; u];
  mivector<double> yout(2); // salida
  yout[0]= -y[0]*y[0]-exp(-y[1])+t; // [v']=f(u,v,t)
  yout[1] = y[0]; // [u']=v
  return yout;
}
//////////////////////////////////////////////////////////////////////


//////////////////////////// Funcion para derivar///////////////////
double func(double lambda){
  // Entrada:
  //lambda = u'(t=t0)

  //ua = u(t=t0)
  //ub = u(t=tf)

  mivector<double> *yrk2; // yrk2 = [v;u]
  yrk2 = new mivectores<double,ndim>[n]; // objeto de 2 filas que guarda 300 instantes de tiempo

  mivector<double> y0(ndim); // condiciones iniciales
  y0[0] = lambda; // v(=u') inicial
  y0[1] = ua; // u inicial

  RK2(f, t0, y0, tau, n, ndim, yrk2);
  cout<<yrk2[n-1][1]<<endl;
  return yrk2[n-1][1]-ub; // se devuelve el valor obtenido para tf (es decir, n)  
}

///////////////////////////////////////////////////////////////////

int main(){

  double eps = 0.00001; // precision buscada
  int i = 0; // iteraciones para secante
  double sol = 0.0; // solucion para metodo secante

 ////////////// SECANTE ////////////////
 // x0 y x1 son dos puntos entre los que se busca el 0, no tienen por que ser iguales a a y b, puede incluso que entre x0 y x1 no este la solucion
  
  double x0 = (ub-ua)/(tf-t0); // la pendiente de partida es la que hay entre los puntos de salida y llegada
//para cada llamada a rk2

  mivector<double> *yrk2; // yrk2 = [v;u]
  yrk2 = new mivectores<double,ndim>[n]; // objeto de 2 filas que guarda 300 instantes de tiempo
  double x1 = 0.0;
  if(yrk2[n-1][1]<ub){ // si ha quedado por debajo, el otro se establece por encima
    x1 = x0*1.2; // 1.2 y 0.8 son arbitrarios
  }
  else{ // si ha quedado por encima, el segundo se pone por debajo
    x1 = x0*0.8;
  }

  sol = secante(func, x0, x1, eps, i); // se obtiene el valor de "lambda" (sol) que hace que u(x) llegue a ub

 ////////////// SALIDAS ////////////////
  cout<<"la solucion por secante es: "<<sol<<" con "<<i<<" iteraciones"<<endl;

  mivector<double> y0(ndim); // condiciones iniciales
  y0[0] = sol; // v(=u') inicial
  y0[1] = ua; // u inicial

  RK2(f, t0, y0, tau, n, ndim, yrk2); // se re-integra la funcion con el valor de lambda(sol) adecuado

  // SACAR LA FUNCION SOLUCION OBTENIDA
  FILE *doc;
  doc=fopen("ua0_5-ub4_5.dat","w");
  fprintf(doc, " \t\t t \t\t u(t) \n");
  for(int i=0; i<n; i++){
    fprintf(doc, " \t %.15e \t %.15e \n", t0+i*tau, yrk2[i][1]);
  }
}
