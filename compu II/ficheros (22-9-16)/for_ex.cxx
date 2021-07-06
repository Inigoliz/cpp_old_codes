
/* PROGRAMA de introduccion, bucles FOR

Sumatorio de 2(-i) desde i=0 hasta 100

*/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

  cout<<setprecision(50); // imprime 50 decimales por pantalla. Es necesiario" #include <iomanip>"

  double suma;
  const int n=19;
  suma=0.0;

  for(int i=0;i<=n;i=i+1){
    double minum=double(i);
    suma=suma+pow(10,-minum);
    cout<<"valor de 10 elevado a -"<<i<<" es "<<pow(10,-minum)<<endl;
  }

  cout<<"Mi suma es "<<suma<<endl;

}
