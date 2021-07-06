/*
  use of pointers
*/

#include <iostream>

using namespace std;

int main () {

  int firstvalue, secondvalue;

  int * mypointer;     // declaration of pointer: variable that stores an address

  //int *mypointer;    // same as before
  //int *(mypointer);
  //int (*mypointer);
  
  mypointer = &firstvalue;

  *mypointer = 10; // asigna un valor a la celda de memoria de firstvalue
  //firstvalue = 10;
  //mypointer[0] = 10;
  
  mypointer = &secondvalue; // the same pointer can be used for
			    // different addresses

  *mypointer = 20;
  //secondvalue = 20;

  cout << "firstvalue is  " << firstvalue << '\n';
  cout << "secondvalue is " << secondvalue << '\n';

  return 0;

}
