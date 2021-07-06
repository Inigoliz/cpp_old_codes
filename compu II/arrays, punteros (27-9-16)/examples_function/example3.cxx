/*
  arguments of a function passed by reference
*/

#include <iostream>

using namespace std;

// function with arguments declared as references

int subtraction3(int &a, int &b) { // ahora los parametros de entrada deben ser direcciones de variables.
  // " a" s es lo que hay en la direccion de "x" y "b" lo que hay en la direccion de " y"

  int r;

  r = a - b;

  a = a + 2; // a is modified. Como "a" es lo que hay en la direccion de "x", al cambiar "a" cambia lo que hay en la direccion de "x"

  b = b + a; // b is modified

  return r;

}


int main () {

  int x=5, y=3, z;

  cout << '\n' << "before: x, y: " << x << ",  " << y << '\n';

  z = subtraction3(x,y);
  
  cout << "after:  x, y: " << x << ",  " << y << ",   return of function: "  << z << '\n';

  // note: subtraction3(2,3) will not work

}
