/* Metodo LU para matrices tridiagonales:
 Ax = b;

 A es matriz tridiagonal: solo tiene numeros en la diagonal principal, una por arriba y otra por debajo. El resto son 0's
*/


void lu_trid(double *d, double *ds, double *df, double *b, double *x, int n){
  /* Entradas:
d: elementos de la diagonal principal. Array de n elementos
ds: elementos de la diagonal de arriba. Array de n-1 elementos
df: elementos de la diagonal de abajo. Array de n-1 elementos
b: elementos de B.
x: solucion
n: dimension
  */


  /* Para entender la nomenclartura, leer "L_trid.pdf"*/
  double delta[n]; // array de los elementos delta
  double deltaf[n]; // array de los elementos delta f
  double z[n];


  ///////////////////// Algoritmo /////////////////////////

  deltaf[0] = 0; // pues no se utilizan el primero de df

  delta[0] = d[0];

  for(int i = 1; i<n; i++){
    deltaf[i] = df[i]/delta[i-1];
    delta[i] = d[i]-deltaf[i]*ds[i-1];
  }

  z[0] = b[0];

  for(int i = 1; i<n; i++){ // calculo de las z
    z[i] = b[i]-deltaf[i]*z[i-1];
  }

 x[n-1] = z[n-1]/delta[n-1];

 for(int i = n-2; i>=0; i--){ // calculo de las x
   x[i] = (z[i]-ds[i]*x[i+1])/delta[i];
 }

}
