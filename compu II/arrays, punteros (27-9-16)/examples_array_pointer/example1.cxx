/*
  address of variable and array
*/

#include <iostream>

using namespace std;

int main(){

  double mypi = 3.14;

  cout << "value of variable mypi:   " <<  mypi << '\n';
  cout << "address of variable mypi: " << &mypi << "\n\n"; // hexadecimal. "  " == ' '. Poner 2 /n, produce dos saltos de linea

  const int ndim=3;

  //float  b[ndim] = {1.2,6.7,2.5};
  double b[ndim] = {1.2,6.7,2.5};

  for(int i=0;i<ndim;i++) {

    cout <<"i, value of b:   " << i << " " << b[i] <<endl;

    cout <<"i, address of b: " << i << " " << &b[i] <<endl;
    // cout <<"i, address of b: " << i << " " << &(b[i]) <<endl; // same as before

  }

}
