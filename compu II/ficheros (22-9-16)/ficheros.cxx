/* TRATAMIENTO DE FICHEROS*/
/* Deben existir misdatosin.dat y */


#include <iostream>
#include <cmath>
#include <fstream> // para escribir o leer un archivo
#include <iomanip>
using namespace std;

int main(){
  ifstream elmio("misdatosin.dat"); // abre archivo a lectura
  ifstream eltuyo("tusdatosin.dat");
  ofstream resultados("resultados.dat"); // para escribir en archivo
  double misnum,tusnum,sum; 
  sum=0.0;

  for(int i=1;i<=4;i=i+1){
    elmio>>misnum; eltuyo>>tusnum; // >> traslada 64 en cada traspaso de "elmio" a" misnum"
    sum=misnum+tusnum;
    resultados<<sum<<" "<<sum<<endl; // manda resultado de sum a "resultados"
  }

  elmio.close();
  eltuyo.close(); 
  resultados.close();
}



