
/*Funcion  que, dados los coeficientes de un POLINOMIO de grado 2, calcula sus raices*/

void rpol2(double *coef, double *R){

  double a = coef[0];
  double b = coef[1];
  double c = coef[2];

  double r1, r2; // se crean las variables para las dos raices

  double disc = b*b-4*a*c; // valor del discriminante

  if(disc > 0){
    r1 = (-b+sqrt(disc))/(2*a);
    r2 = (-b-sqrt(disc))/(2*a); 
    cout << "Las raices son: r1 = " << r1 << " y r2 = " << r2 << endl;
    R[0] = r1;
    R[1] = r2;
   }
  else if(disc == 0){
    r1 = -b/(2*a);
    r2 = 0;
    cout << "Solo hay una raiz, que es r1 = " << r1 << endl;
    R[0] = r1;
    R[1] = r2;
  }
  else{
    r1 = 0;
    r2 = 0;
    cout << "No tiene raices reales" << endl;
    R[0] = r1;
    R[1] = r2;
  }

}
