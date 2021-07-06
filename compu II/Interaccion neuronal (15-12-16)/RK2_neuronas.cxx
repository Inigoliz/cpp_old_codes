/* Funcion RK2 (pendiente media) para resolver ODEs*/

/* PARA RESOLVEREL PROBLEMA DE LA INTERACCION NEURONAL */

void RK2_neuronas(mivector<double> (*f)(double,mivector<double>),double t0, mivector<double> y0, double tau, int n, int ndim, mivector<double> *y){
  
  // x0 contiene las condiciones iniciales, donde x0[0] son las condiciones inciiales de la primera variable

  // IMP sintaxis; y[instante de tiempo][n]
  for(int i = 0; i<ndim; i++){
    y[0][i] = y0[i]; 
  }

  // IMP x[t] coge la fila para un instante de tiempo

  mivector<double> ys(ndim); // vector auxiliar para el RK2 (mirar teoria)
  double t;
  t = t0; // como se declaran las condiciones iniciales, se inicializa en el primer instante de tiempo

  for(int i = 0; i<n; i++){ // i=0 son las condiciones iniciales
    t = t0 + double(i)*tau;
    ys = y[i] + tau*f(t, y[i]);
    y[i+1] = y[i] +0.5*tau*(f(t, y[i]) + f(t+tau, ys));
    // cout<<"RK2 "<<y[i][1]<<endl;
  }
}
