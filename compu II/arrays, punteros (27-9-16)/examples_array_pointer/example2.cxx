/* 
   Declaration of pointers
*/

#include <iostream>

using namespace std;

int main(){

  double mypi = 3.14;

  double *addr_mypi; // declaration of pointer: variable that stores an address

  //double addr_mypi; // compared to previous statement, this one produces an error

  /* *** to access to address of mypi ***
   * ************************************  */
  
  addr_mypi = &mypi;
  
  // ESTAS DOS LINEAS HACEN LO MISMO
  cout << "\n" << "address of variable mypi using pointer addr_mypi: " << addr_mypi << "\n\n"; // saca la direccion hexadecimal

  // check:
  cout << "check: address of variable mypi: " << &mypi << "\n\n"; // hexadecimal

  //

  /* *** to access to value of mypi ***
   * **********************************  */

  cout << "\n" << "value of mypi using pointer addr_mypi: " << *addr_mypi << "\n\n"; // saca el valor guardado en la celda a que dirige" addr_mypi"
  cout << "value of mypi using pointer addr_mypi: " << addr_mypi[0] << "\n\n"; // same as previous statement
  
  //check: 
  cout << "check: value of variable mypi:   " <<  mypi << "\n\n";


}
