/* Funcion RK4  para resolver ODEs*/
/* necesita "mivector.h" y "maxvec.cxx" */

void RK4(mivector<double> (*f)(double,mivector<double>),double t0, mivector<double> y0, double tau, int n, int ndim, mivector<double> *y){

  // auxiliares para RK4
  mivector<double> k1(ndim);
  mivector<double> k2(ndim);
  mivector<double> k3(ndim);
  mivector<double> k4(ndim);

  double t;
  t = t0;

  // Condiciones iniciales
  y[0][0] = y0[0];
  y[0][1] = y0[1];

  for(int i = 0; i<n; i++){
    t = t0 + i*tau;

    k1 = tau*f(t, y[i]);
    k2 = tau*f(t+0.5*tau, y[i]+0.5*k1);
    k3 = tau*f(t+0.5*tau, y[i]+0.5*k2);
    k4 = tau*f(t+tau, y[i]+k3);

    y[i+1] = y[i] + (1/6.0)*(k1+k2+k2+k3+k3+k4);
    cout<<"RK4 "<<y[i][1]<<endl;
  }
}


