
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {

  ofstream fsalida("/Users/inigo/Documentos/Programación/Hashcode18/hola.txt");  // crea "hola.txt" si es que no existe
  ifstream fentrada("/Users/inigo/Documentos/Programación/Hashcode18/example.in");

  string data;
  getline (fentrada, data);
  cout << data << endl;
  fentrada>>data;
  cout<<data<<endl;

  fentrada.close();
  fsalida.close();

  return 0;
}
