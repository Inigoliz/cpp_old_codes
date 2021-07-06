
#include <iostream>
#include <new>

using namespace std;

int main() {

  int * foo;

  cout<<"asignando... \n";

  foo = new (nothrow) int [10];
  if (foo == nullptr) {
    // error assigning memory. Take measures.
    cout<<"mal \n";
  }

  cin.get();

  return 0;
}
