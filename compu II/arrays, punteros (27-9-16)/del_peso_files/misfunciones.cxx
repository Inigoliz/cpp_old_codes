void Rpol2a(double *p, double *R, int &Nr){

}
void Rpol2(double a, double b, double c,
	   double *R, int &Nr){
  double delta=b*b-4*a*c;
  if(delta>0){
    Nr = 2;
    R[0]=(-b+sqrt(delta))/(2*a);
    R[1]=(-b-sqrt(delta))/(2*a);
  } else if(delta<0){
    Nr = 0;
  } else{
    Nr = 1;
    R[0]=-b/(2*a);
  }
  
}

double maxelemento(double *v, int n){
  double elmax; elmax = v[0];
  for(int i=1;i<n;i=i+1){
    if(v[i]>elmax) {elmax=v[i];}
  }
  return elmax;
  
}

double derivada(double (*f)(double), double x){
  double epsilon=0.000001; double aux;
  aux = (  f(x+epsilon)  -  f(x)  )/epsilon;
  return aux;
					     }
