/* FUNCION QUE TOMA LOS LIMITES a y b, SUPERIOR E INFERIOR DE INTEGRACION, Y n, TAMAÑO DE LAS PARTICIONES*/

double integral(double(*f)(double), double a, double b, double n){ // "a": limite inferior, "b" limite superior, "n" divisiones de la particion

  double delta = (b-a)/n; // tamaño del diferencial de x, dx
  double sum = 0.0;

  for(int i = 0; i < n; i++){
    sum = sum + delta*f(a+delta/2+delta*i); // centra los valores a sumar
  }
  return sum;
}
