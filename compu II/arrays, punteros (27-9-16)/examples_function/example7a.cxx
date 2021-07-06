/*
  #include of separate function
*/

#include <iostream> // busca el codigo en la libreria estandard de C++

using namespace std;

#include "example7b.cxx" // busca el codigo e inserta example7 en el directorio donde se trabaja

// es conveniente poner este include después de los includes standard de C++, pues asi example7 puede usar las librerias que se han incluido antes.
// Si se pone "#include <iostream>" en example7a, NO ponerlo en example7b


int main () {

  int x=5, y=3, z;

  z = subtraction(7,2); // call of function, que esta en example7b

  cout << "The result is  " << z << '\n';

}
