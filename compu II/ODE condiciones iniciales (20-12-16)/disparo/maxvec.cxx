double maxvec(double * V, int n){
  double elmayor;
  elmayor=V[0];
  for (int i=1;i<n;i++){
    if(V[i]>elmayor){
      elmayor=V[i];
    }
  }
  return elmayor;
}
