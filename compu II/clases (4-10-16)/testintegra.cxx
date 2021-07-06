#include <iostream>
#include <cmath>
using namespace std;
#include "integra.cxx"
int main(){
  double integra(double (*f)(double),double,double);
  double f(double);
  double pi=acos(-1.0);
  cout<<integra(f,0.0,pi/2)<<endl;
}

double f(double x){
  return 3*sin(x);
}
