/* Funcion RK2 (pendiente media) para resolver ODEs*/

void RK2(mivector<double> (*f)(double,mivector<double>),double t0, mivector<double> y0, double tau, int n, int ndim, mivector<double> *y){
  
  /* y0 contiene las condiciones iniciales,
     donde y0[0]=vz; y0[1]=vx; y0[2] = z; y0[3] = x; y0[4] = t0*/

  // IMP sintaxis; y[tiempo][]: y[][0] = vz; y[][1] = vx; y[][2] = z; y[][3] = x
  y[0][0] = y0[0]; 
  y[0][1] = y0[1];
  y[0][2] = y0[2];
  y[0][3] = y0[3];
  // IMP y[t] coge la filas para un instante de tiempo

  mivector<double> ys(ndim); // vector auxiliar para el RK2 (mirar teoria)
  double t;
  t = t0; // como se declaran las condiciones iniciales, se inicializa en el primer instante de tiempo

  for(int i = 0; i<n; i++){ // i=0 son las condiciones iniciales
    t = t0 + i*tau;
    ys = y[i] + tau*f(t, y[i]);
    y[i+1] = y[i] +0.5*tau*(f(t, y[i]) + f(t+tau, ys));
    // cout<<"RK2, vz "<<y[i][0]<<endl;
  }
}
