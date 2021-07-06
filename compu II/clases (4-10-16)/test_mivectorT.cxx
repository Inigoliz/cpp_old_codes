// USO DE LA CLASE MIVECTOR

#include <iostream>
using namespace std;
#include "mivectorT.h" // incluye la clase

int main(){
  const int n=5;
  mivector<double> v(n),u(n),w(n); // se definen objetos del tipo "mivector" (parentesis curvos)


  for (int i=0;i<n;i++){
    v[i]=i; // (parentesis cuadrados para las caracteristicas)
    u[i]=2*i;
  }

  w=v+u; // suma de vectores, a partir de la definicion de suma en la clase

  for(int i=0;i<n;i++){
    cout<<w[i]<<endl;
  }


}
