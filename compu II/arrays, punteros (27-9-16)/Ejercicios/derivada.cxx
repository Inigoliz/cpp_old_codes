/* Funcion para derivar numericamente una funcion*/

double derivada(double(*f)(double), double x, double h){ // toma "a" y"b", valores entre los cuales se quiere derivar, y "func", la funcion a derivar

  double df;

  //df = (f(x+h)-f(x))/h; // la derivada es (f(x+h)-f(x))/h
  df = (f(x+h)-f(x-h))/(2*h); // DERIVADA SIMETRICA

  return df;

}
