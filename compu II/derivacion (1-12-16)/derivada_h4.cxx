/* Metodo de derivacion con precision h4 (h cuarta)*/
/* Definicion: f'=(8f(x+h)-8f(x-h)+f(x-2h)-f(x+2h))/(12h) */

double derivadah4(double(*f)(double), double x, double h){
  /* Entrada:
     f: f(x)
     fder: f'(x) analitica (pues se puede hacer)
     h: precision de la derivada
  */

  return (8*f(x+h)-8*f(x-h)+f(x-2*h)-f(x+2*h))/(12*h);

  }
