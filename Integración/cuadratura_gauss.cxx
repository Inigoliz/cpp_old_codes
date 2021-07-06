/* Compu 29-11-16*/
/* Integracion de f(x), funcion analitica, por el metodo de la Cuadratura Gaussiana */

void cuadratura_gaussiana(double(*f)(double), double a, double b,  double &integral){

  /* Variables
     a: limite inferior
     b: limite superior
     integral: valor final de la integral
  */

  integral = 0.0;

  // Declaracion de las w's y x's para Cuadratura Gaussiana-6

  double w[6] = {
    0.1713244924,
    0.1713244924,
    0.360761573,
    0.360761573,
    0.4679139346,
    0.4679139346,
  };

  double x[6] = {
    0.9324695142,
    -0.9324695142,
    0.6612093865,
    -0.6612093865,
    0.2386191861,
    -0.2386191861,
  };

  double c = 0.5*(b-a); // constante para cambiar los limites de (a,b) a (-1,1)

  for(int i = 0; i<6; i++){
    double y = 0.5*((b+a)+x[i]*(b-a)); // cambio de variable para cambiar los limites
    integral = integral + w[i]*f(y);
  }
  integral = integral*c;

}
