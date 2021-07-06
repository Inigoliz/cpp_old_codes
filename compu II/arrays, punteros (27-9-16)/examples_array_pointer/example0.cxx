
#include <iostream>

using namespace std;

int main(){

  const int ndim=3; // si no se declara como const, la linea (1) no da error, lo que puede traer problemas
  //int ndim=3; // can lead to problems: see below

  // double a[ndim] = {1.2,6.7,2.5}; // declaration of an array

  double a[ndim] = {1.2,6.7}; // si solo se ponen dos elementos, el ultimo vale 0
  //double a[ndim] = {}; // se pone todo a 0
  //double a[ndim]; // not initialised. En el array se queda lo que estaba antes en la memoria. NO HACER, INICIALIZAR SIEMPRE A 0
  //double a [] = {1.2,6.7,2.5}; // use with care (EVITAR)

  //a[0]=1.2; a[1]=6.7; a[2]=2.5;  // access element of array
                                   // indices start at 0 up to (ndim-1)
  
  //(1)//a[3]=4.5; // produces error with "const int ndim=3", pues el array solo va de 0 a 2
  //cout << a[3] << endl;

  // a[(1+1)]=2.2; // se pueden usar operaciones algebraicas

  for(int i=0;i<ndim;i++) {

    cout <<"i, a: " << i << " " << a[i] << endl;

  }

}
