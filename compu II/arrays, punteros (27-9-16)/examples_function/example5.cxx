/*
  pointer as argument of a function
*/

#include <iostream>

using namespace std;

// function with arguments declared as references

int subtraction4(int *a) { // como *a es un puntero, al cambiar los elementos de a cambian los elementos del array que entro

  int r;

  r = a[0] - a[1];

  a[0] = 2*a[0]; // the argument is modified
  a[1] = 2*a[1];
    
  return r;

}


int main () {

  const int n=2;

  int x[n];
  int z;
  
  x[0] = 10;
  x[1] =  2;

  cout << '\n' << "before: x[0], x[1]: " << x[0] << ",  " << x[1] << '\n';

  z = subtraction4(x);
    
  cout << '\n' << "after:  x[0], x[1]: " << x[0] << ",  " << x[1] << ",   return of function: " << z << '\n';

}
