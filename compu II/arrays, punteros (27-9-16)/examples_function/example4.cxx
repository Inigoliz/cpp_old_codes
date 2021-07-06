/*
  pointer as argument of a function
*/

#include <iostream>

using namespace std;

// function with arguments declared as references

int subtraction4(int *a) {

  int r;

  r = a[0] - a[1];

  return r;

}


int main () {

  const int n=2;

  int x[n];
  int z;
  
  x[0] = 10;
  x[1] =  2;

  z = subtraction4(x);
    
  cout << '\n' << "x[0], x[1]: " << x[0] << ",  " << x[1] << ",   return of function: " << z << '\n';

}
