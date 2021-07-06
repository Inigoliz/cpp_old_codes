double integra(double (*f)(double), double a, double b){
  int N=10000; double delta=(b-a)/N;
  double sum=0.0, x=a;
  for(int i=1; i<=N; i++){
    sum=sum+(*f)(x);
    x=x+delta;
  }
  return sum*delta;
}
