
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

  ifstream elmio("misdatosin.dat");
  ifstream eltuyo("tusdatosin.dat");
  ofstream resultados("resultados.out");

  double misnum,tusnum,sum;

  resultados<<setprecision(10);
  sum=0.0;
  elmio>>misnum; eltuyo>>tusnum;

  while(!elmio.eof() && !eltuyo.eof()){ //.eof devuelve false si todavia esta en el cuerpo del archivo

    sum=misnum+tusnum;
    resultados<<sum<<endl;
    elmio>>misnum; eltuyo>>tusnum;

  }

  elmio.close();
  eltuyo.close(); 

}




