/* Simulación de un control PDI*/

#include <string.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(){
  cout<<setprecision(15);
  FILE *doc;
  doc = fopen("PID.dat", "w");
  fprintf(doc, "tiempo (s) \t\t u \n");
  
  const int dim = 3;
  const double dt = 0.001; // paso de tiempo
  const double u0 = 0; // posición objetivo
  double t = 0;
  double tmax = 9;
  
  double u[dim] = {0, 0, 0}; // {pos(t-1), pos(t), pos(t+1)}

  // Constantes PID
  const double kp = 0.01;
  const double ki = 0;
  const double kd = 0;


  // Bucle:

  u[0] =1;
  u[1] =1;

  fprintf(doc, "%f \t %.15e \n",t, u[1]);
   
  for(t; t<tmax; t=t+dt){
    
    u[2] = u[1] + kp*(u0-u[1]);

    u[0] = u[1];
    u[1] = u[2];

    fprintf(doc, "%f \t %.15e \n",t, u[2]);
  }
  
}
