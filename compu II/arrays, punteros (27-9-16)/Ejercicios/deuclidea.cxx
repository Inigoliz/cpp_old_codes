
/* Funcion para calcular la distancia euclidea entre dos vectores:
   Suma los cuadrados de la diferencia entre las coordenadas*/


double  d2v(double *a, double *b, int dim){ // a y b son los vectores de entrada; dim, su dimension

  double sum = 0.0;

  for(int i = 0; i < dim; i++){

    sum = sum + (a[i]-b[i])*(a[i]-b[i]);

  }

  return sqrt(sum);

}

