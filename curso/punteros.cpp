
#include <iostream>

using namespace std;

int main () {

  ///////// PUNTERO CHAR ///////////////

  const char * let = "hola"; // Apunta al primer elemento de hola

  cout<<let<<"\n";
  cout<<*(let+1)<<"\n"; // o

  cin.get();

  return 0;
}
