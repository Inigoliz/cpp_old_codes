
/* Funcion que calcula la norma de una matriz (la mayor de la suma de sus filas)  IMP: la matriz que toma es de la clase matrix.h*/

double normaMat(matrix<double> a, int dim){ // toma como argumentos la matriz a y la dimension (1xdim)

  matrix<double> b(dim,1); // columna que guarda la suma de cada fila

  double sum = 0;

  for(int i = 0; i<dim; i++){
    sum = 0;
    for(int j = 0; j<dim; j++){
      sum = sum + abs(a(i,j));
    }
    b(i,0) = sum;
  }

  double r;
  r = b(0,0); // coge el primer elemento

  for(int i = 1; i<dim; i++){
    if(b(i,0) > r){ // compara el primer elemento con el segundo
      r = b(i,0);
    }
  }
 return r; 
}
