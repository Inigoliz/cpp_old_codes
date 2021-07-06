/* Metodo de derivacion con precision h2 (h cuadrado)*/
/* Definicion: f'=(f(x+h)-f(x-h))/2h */

double derivadah2(double(*f)(double), double x,  double h){
  /* Entrada:
     f: f(x)
     h: precision de la derivada
  */

  return (f(x+h)-f(x-h))/(2*h);
 
  }
