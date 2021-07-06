 /* Resolucion de sistemas de ecuaciones con metodo LU*/
 /* Sistema A*x=b**/

void lu(double *a, double *B, double *X, int n){ // a es el puntero que dirige a los elementos de la matriz, y n su dimension, nxn
  
  double L[n][n];
  double U[n][n];
  double Z[n];
  double A[n][n]; // matriz A con los coeficientes de entrada

  for(int i=0; i<n; i++){ // crea una matriz bidimensional, como se queria
    for(int j=0; j<n; j++){ // CUIDADO: en C++ se empieza a contar en 0!!
      A[i][j] = a[i*n+j];
    }
  }

  for(int i=0; i<n; i++){ // se inicializan a 0
    for(int j=0; j<n; j++){
      L[i][j] = 0;
      U[i][j] = 0;
    }
  }

  double aux = 0; // variable auxiliar para los sumatorios internos

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i<j){
	L[i][j] = 0;
	aux = 0;
	for(int k=0; k<=i-1; k++){ // CUIDADO: i-1 esta incluido en la suma!!
	  aux = aux + L[i][k]*U[k][j];
	} // for
	U[i][j] = A[i][j]-aux;
      } // if
      if(i==j){
	aux = 0;
	L[i][i] = 1;
	for(int k=0; k<=i-1; k++){
	  aux = aux + L[i][k]*U[k][j];
	} // for
	U[i][j] = A[i][j]-aux;
      } // if
      if(i>j){
	aux = 0;
	U[i][j] = 0;
	for(int k=0; k<=j-1; k++){
	  aux = aux + L[i][k]*U[k][j];
	} // for
	L[i][j] = 1/(U[j][j])*(A[i][j]-aux);
      } // if
    } // for
  } // for
  
  Z[0] = B[0];

  for(int i=1; i<n; i++){ // z[0] ya se ha calculado antes
    aux = 0;
    for(int j = 0; j<=i-1; j++){
      aux = aux + L[i][j]*Z[j];
    }
    Z[i] = B[i]-aux;
  }

  X[n-1] = 1/(U[n-1][n-1])*Z[n-1]; // el ultimo valor se establece antes

  for(int i=n-2; i>=0; i--){
    aux = 0;
    for(int j = i+1; j<n; j++){
      aux = aux+U[i][j]*X[j];
    }
    X[i] = 1/(U[i][i])*(Z[i]-aux);
  }

  /*PARA TESTEAR SI FUNCIONA*/

  // cout<<A[0][0]<<" "<<A[0][1]<<" "<<A[0][2]<<endl;
  // cout<<A[1][0]<<" "<<A[1][1]<<" "<<A[1][2]<<endl;
  // cout<<A[2][0]<<" "<<A[2][1]<<" "<<A[2][2]<<endl;
  // cout<<endl;
  // cout<<U[0][0]<<" "<<U[0][1]<<" "<<U[0][2]<<endl;
  // cout<<U[1][0]<<" "<<U[1][1]<<" "<<U[1][2]<<endl;
  // cout<<U[2][0]<<" "<<U[2][1]<<" "<<U[2][2]<<endl;
  // cout<<endl;
  // cout<<L[0][0]<<" "<<L[0][1]<<" "<<L[0][2]<<endl;
  // cout<<L[1][0]<<" "<<L[1][1]<<" "<<L[1][2]<<endl;
  // cout<<L[2][0]<<" "<<L[2][1]<<" "<<L[2][2]<<endl;
  // cout<<endl;
  // cout<<Z[0]<<" "<<Z[1]<<" "<<Z[2]<<endl;
  // cout<<endl;
  // cout<<X[0]<<" "<<X[1]<<" "<<X[2]<<endl;


} // cierre lu
