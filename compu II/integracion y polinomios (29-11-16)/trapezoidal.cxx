/* COMPU 29-11-16*/
/* Integracion de una funcion analitica f(x) por el Metodo Trapezoidal*/

void trapezoidal(double(*f)(double), double a, double b, int n,  double &integral){

  /* Variables:
     a: limite inferior
     b: limite superior
     n: numero de pasos
     tau: paso
     integral: valor final de la integral
  */

  double tau = (b-a)/double(n); // paso, tamaño del intervalo
  integral = 0.0;
  double x = a; // valor de x estudiado

  // se implementa la funcion: integral = tau*(1/2(f(a)+f(b))+f(a+tau)+...+f(b-tau))
  for(int i = 1; i<n; i++){ // no se suma ni f(a) ni f(b), que se suman despues
    integral = integral + f(x+tau);
    x = a + double(i)*tau;
    // x = x+tau; // acumula el error de redondeo a cada iteracion. IMPRECISO, CUIDADO
  }
  integral = tau*(integral+0.5*(f(a)+f(b)));
}
