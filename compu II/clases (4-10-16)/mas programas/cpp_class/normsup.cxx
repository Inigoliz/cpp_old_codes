#include <cmath>
#include "maxvec.cxx"
double normsup(double *v,int n){
  double w[n];
  for (int i=0;i<n;i++){
    w[i]=abs(v[i]);
  }
  return maxvec(w,n);
}
