#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double suma;
  const int n=10;
  suma=0.0;
  for(int i=1;i<=n;i=i+1){
    double minum=double(i); // crea minum, double, y guarda en el i, que debe ser convertido a double antes
    suma=suma+sqrt(minum);
  }
  cout<<"Mi suma es "<<suma<<endl;
}
