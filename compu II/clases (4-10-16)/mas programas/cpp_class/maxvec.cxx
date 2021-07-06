double maxvec(double *v,int n){
  double elmax;
  elmax=v[0];
  for(int i=1;i<n;i++){
    if(v[i]>elmax) elmax=v[i];
  }
  return elmax;
}
