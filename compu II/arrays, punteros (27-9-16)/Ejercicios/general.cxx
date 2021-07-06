/* CLASE 29-9-16

   PROGRAMA PARA PROBAR LAS DISTINTAS FUNCIONES*/


#include <iostream>
#include <cmath>
#include <fstream> // para escribir los datos en un archivo, en derivada

using namespace std;

// se inserta las funciones

#include "deuclidea.cxx"
#include "rpol2.cxx"
#include "derivada.cxx"


//////////////////////////// Funcion para derivar///////////////////
double func(double x){
  return x*sin(x);
}
///////////////////////////////////////////////////////////////////

int main () {

  // PRUEBA FUNCION DISTANCIA EUCLIDEA ENTRE 2 VECTORES:
  /*
  const int dim=3; // dimension de los vectores

  double v1[dim] = {1, 2, 3};
  double v2[dim] = {1, 2, 4};

  double dist = d2v(v1, v2, dim);
    
  cout << "distancia entre v1={" <<  v1[0] << "," << v1[1]<< ","  << v1[2] << "} y v2={" << v2[0] << "," << v2[1] << "," << v2[2] << "} es " << dist << endl;
  */
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // PRUEBA DE CALCULO DE RAICES DE POLINOMIO DE  GRADO 2
  /*
  double a, b, c; // coeficientes
  double *raices; // puntero donde se guardaran las raices; asi las podra modificar la  funcion
  raices = new double [2]; 

  cout << " Inserte los coeficientes:" << endl;
  cin >> a >> b >> c;

  double coef[3] = {a,b,c};

  rpol2(coef, raices);
  */

  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Calculo de Derivada
// PI=acos(-1.0);
  
  double a = -50; // limites de derivacion
  double b = 50;
  double h = 0.0001; // para la precision de la derivacion

  const int num = 40000; // numero de puntos que va a haber en la grafica
  
  double x = 0.0;
  double y = 0.0;
  double df = 0.0;

  double paso = (b-a)/num; // distancia en x entre dos puntos

  ofstream fpuntos("derivada.out");

  for(int i = 0; i < num+1; i++){ // IMP: num+1
    x = a+i*paso;
    y = func(x);
    df = derivada(func,x,h);
    fpuntos << x << "  " << y << "  " << df << endl; // imprime en derivada.out el valor de "x", de "y" y de "df"
  }

  fpuntos.close();

  

} // cierre main

