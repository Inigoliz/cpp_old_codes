

#include <iostream>
#include <fstream>
using namespace std;
int main(){
//Escribe numeros consecutivos en un fichero
  int n;
  cout<<"Escribir numero entero > "; cin>>n;
  cout<<endl;
      //fstream fsalida;
      //fsalida.open("numeros.txt",fstream::out);
  ofstream fsalida("numeros.txt");
  int i=1, numax=50;
  while(i<=n && i<=numax){
    fsalida<<i<<endl;
    i=i+1;
  }
}
