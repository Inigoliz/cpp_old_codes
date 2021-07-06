/* Compu 29-11-16*/
/* Integracion de f(x), funcion analitica, por el metodo de Simpson */

void simpson(double(*f)(double), double a, double b, int n, double &integral){

  /* Variables
     a: limite inferior
     b: limite superior
     n: numero de pasos
     tau: paso
     integral: valor final de la integral
  */
	   
  double tau = (b-a)/double(n); // paso, tamaño del intervalo
  integral = 0.0;
  double i1 = 0.0;
  double i2 = 0.0;
  double x0 = a; // primer valor

  for(int i = 2; i <= n-2; i=i+2){
    i1 = i1 + f(x0+double(i)*tau);
  } 
 
  i1 = 2*i1;

  for(int i = 1; i <= n-1; i=i+2){
    i2 = i2 + f(x0+double(i)*tau);
  } 
 
  i2 = 4*i2;
  
  integral = tau/3*(f(a)+f(b)+i1+i2); // suma final

}
