/*
  different ways of using a pointer
*/

#include <iostream>

using namespace std;

int main () {

  const int n=7;

  int numbers[n]; // declaration of an array
                  // size of the array is set by n
  
  int * p;        // declaration of a pointer

  // LA DECLARACION DE *p y de numbers DEBE SER DEL MISMO TIPO; si no al poner p = p+1, saltara 8 unidades, perdiendo valores de numbers (pues sus elementos solo


  // p is an address;   value of p at that address

  p = numbers;         *p = 10;  // the name of an array can be used as a pointer to its first element

  p = &numbers[1];     *p = 20;  // declaracion ususal del valor del puntero

  p = numbers + 2;     *p = 30;  // se declara el nombre (que es el valor de memoria del primer elemneto) + 2

  p = numbers;     *(p+3) = 40;  // se obtiene el punetero del primer elemento, primera celda de memoria, y se guarda en la 4º a partir de ella (3 mas a la derecha)

  p = p+4;             *p = 50;  // p sigue apuntando a la direccion del primer elemento (elemento 0) de numbers. Se le suman 4

  p++;               p[0] = 60; // p = p+1, se obtiene el siguiente p

  p = numbers;       p[6] = 70;

  
  for (int i=0; i<n; i++) {
   cout << "numbers["<< i << "]:  " << numbers[i] << "\n";
  }

  cout << endl;
  
  for (int i=0; i<n; i++)
    cout << "numbers["<< i << "]:  " << numbers[i] << "\n"; // for loop without braces: use with care

  
  return 0;

}

