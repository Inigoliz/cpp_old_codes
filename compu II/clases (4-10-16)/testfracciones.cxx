#include <iostream>
using namespace std;

#include "fracciones.cxx"

int main(){
  fraccion x, y(1,2), z(3,4); //A y y z le das la funcion los valores, y a x le da los valores por defecto
  x = y + z;  // x = y.operator+(z)
  cout<<x<<endl;
}
