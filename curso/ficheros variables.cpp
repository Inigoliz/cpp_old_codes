// Variables dinámicas para ficheros con la clase String

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

  string core = "/Users/inigo/Documentos/Programación/fichero";
  string fin = ".txt";
  string var;
  string path;
  fstream salida;

  for(int i=0; i<3; i++){
    var = to_string(i);
    path = core + var + fin;
    ofstream salida(path);
  }
}
