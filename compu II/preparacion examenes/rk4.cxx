/* Método Runge-Kutta 4 para resolver ODE's lineales de 1º orden en t*/

/* Argumentos:
   x''(t,x',y',x,y)
   y''(t,x',y',x,y)
   x'(t=0)
   y'(t=0)
   x(t=0)
   y(t=0)

   ti: tiempo inicial
   tf: tiempo final
   dt: paso de tiempo
*/

void rk4(void(*f)(double(*), double(*), double(*)), double *r, double *v, double *a, double ti, double tf, double dt, int n, double pasos){

  // Variables auxiliares para el metodo RK4

  ofstream resultado("xy.txt"); // archivo de salidad de datos
  
  double k1x[n];
  double k1u[n];
  double k2x[n];
  double k2u[n];
  double k3x[n];
  double k3u[n];
  double k4x[n];
  double k4u[n];

  double rr[n];
  double vv[n];
  //double aa[n];

  //aa[0] = a[0]; // como a se va a pasar a otra funcion, debe ser declarada dentro de rk4, no se puede pasar como puntero, que es lo que come rk4, *a
  //aa[1] = a[1];
  
  double t = ti; //  instante inicial

  /// RK4

  resultado<<t<<" "<<r[0]<<" "<<r[1]<<endl; // guarda el estado inicial
  
  for(double i = 0; i < pasos; i++){ // para cada componente
      
    k1x[0] = v[0];
    k1x[1] = v[1];
    f(r, v, a);
    k1u[0] = a[0];
    k1u[1] = a[1];
    k2x[0] = v[0] + dt/2*k1u[0];
    k2x[1] = v[1] + dt/2*k1u[1]; 
    rr[0] = r[0] + dt/2*k1x[0];
    rr[1] = r[1] + dt/2*k1x[1];
    vv[0] = v[0] + dt/2*k1u[0];
    vv[1] = v[1] + dt/2*k1u[1];
    f(rr, vv, a);
    k2u[0] = a[0];
    k2u[1] = a[1]; 
    k3x[0] = v[0] + dt/2*k2u[0];
    k3x[1] = v[0] + dt/2*k2u[1];   
    rr[0] = r[0] + dt/2*k2x[0];
    rr[1] = r[1] + dt/2*k2x[1];
    vv[0] = v[0] + dt/2*k2u[0];
    vv[1] = v[1] + dt/2*k2u[1];
    f(rr, vv, a);
    k3u[0] = a[0];
    k3u[1] = a[1];
    k4x[0] = v[0] + dt*k3u[0];
    k4x[1] = v[1] + dt*k3u[1];
    rr[0] = r[0] + dt*k3x[0];
    rr[1] = r[1] + dt*k3x[1];
    vv[0] = v[0] + dt*k3u[0];
    vv[1] = v[1] + dt*k3u[1];
    f(rr, vv, a);
    k4u[0] = a[0];
    k4u[1] = a[1];

    r[0] = r[0] + dt/6*(k1x[0]+2*k2x[0]+2*k3x[0]+k4x[0]);
    r[1] = r[1] + dt/6*(k1x[1]+2*k2x[1]+2*k3x[1]+k4x[1]);
    v[0] = v[0] + dt/6*(k1u[0]+2*k2u[0]+2*k3u[0]+k4u[0]);
    v[1] = v[1] + dt/6*(k1u[1]+2*k2u[1]+2*k3u[1]+k4u[1]);

    resultado<<t<<" "<<r[0]<<" "<<r[1]<<endl; // guarda los datos
    t = t + dt;
  }

}


