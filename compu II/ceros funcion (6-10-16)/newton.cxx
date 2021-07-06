/* Metodo de newton para encontrar los ceros de una funcion*/

double newton(double(*f)(double), double(*fder)(double), double x0, double eps, int &i2){

  double x1;
  double sol = 0.0;
  i2 = 0; // iteraciones

  x1 = x0-(f(x0)/fder(x0));
  
  while(abs(x0-x1) > eps){
    i2++; // numero de iteraciones
    x0 = x1;
    x1 = x0-(f(x0)/fder(x0));
  }

  sol = (x0+x1)/2;
  return sol;

}
