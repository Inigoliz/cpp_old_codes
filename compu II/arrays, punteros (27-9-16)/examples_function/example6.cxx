/*
  prototyping
*/

#include <iostream>

using namespace std;

int main () {

  int x=5, y=3, z;

  int subtraction (int, int); // prototype of function. "Tienes que ir a buscar una funcion en otro sitio"
  
  z = subtraction(7,2); // call of function 

  cout << "The result is  " << z << '\n';

}


// declaration of function 

int subtraction (int a, int b) {

  int r;

  r = a - b;

  return r;

}

