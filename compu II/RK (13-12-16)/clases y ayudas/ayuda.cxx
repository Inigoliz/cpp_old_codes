

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "mivector.h"


...

const int n=300,ndim=2;
mivector<double> *yrk2;
yrk2 = new mivectores<double,ndim>[n];

...


mivector<double> f(double t, mivector<double> y){

  ...  

}






void runge(mivector<double> (*f)(double,mivector<double>),double t0,mivector<double> y0,
            double tau,int n,mivector<double> *y){

  ....

}
