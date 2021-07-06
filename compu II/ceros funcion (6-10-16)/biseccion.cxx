/* Metodo de biseccion para encontrar los ceros de una funcion*/

double biseccion(double(*f)(double), double a, double b, double eps, int &i1){

  double signo = 0.0;
  double x0;
  double sol;
  i1 = 0;

  signo = f(a)*f(b);

  if(signo > 0){ // para comprobar si entre los valores introducidos esta la solucion o no. Si no, se pide que se introduzcan unos nuevos.
    cout<<"el intervalo indicado no es concluyente; acotar mas."<<endl;
  }
  else{
      x0 = (a+b)/2;
    while(abs(x0-a) > eps){
      i1++; // se suma una iteracion
      signo = f(a)*f(x0);

      if(signo < 0){
	b = x0;
      }
      else{
	a = x0;
      }
      x0 = (a+b)/2;
    }
    sol = (a+b)/2; // se toma la mitad del intervalo final
  }

  return sol;

}
