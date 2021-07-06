/*Metodo LU para resolucion de Sistemas Lineales*/

/*HACE USO DE LA CLASE MATRIX.H PARA EL TRATAMIENTO DE LOS DATOS*/
/*(necesita por tanto tener una cabecera adecuada para usarla)*/


void lu_mat(matrix<double> A, matrix<double> B, matrix<double> &X, int n){ // a y B son las matrices de datos, y X otra matriz (&para que sea accesible desde el programa principal), y n su dimension, nxn
  
  matrix<double> L(n,n);
  matrix<double> U(n,n);
  matrix<double> Z(n,1);
  L.Null(); // se inicializan a 0
  U.Null();
  Z.Null();

  double aux = 0; // variable auxiliar para los sumatorios internos

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i<j){
	L(i,j) = 0;
	aux = 0;
	for(int k=0; k<=i-1; k++){ // CUIDADO: i-1 esta incluido en la suma!!
	  aux = aux + L(i,k)*U(k,j);
	} // for
	U(i,j) = A(i,j)-aux;
      } // if
      if(i==j){
	aux = 0;
	L(i,j) = 1;
	for(int k=0; k<=i-1; k++){
	  aux = aux + L(i,k)*U(k,j);
	} // for
	U(i,j) = A(i,j)-aux;
      } // if
      if(i>j){
	aux = 0;
	U(i,j) = 0;
	for(int k=0; k<=j-1; k++){
	  aux = aux + L(i,k)*U(k,j);
	} // for
	L(i,j) = 1/(U(j,j))*(A(i,j)-aux);
      } // if
    } // for
  } // for
  
  Z(0,0) = B(0,0);

  for(int i=1; i<n; i++){ // Z(0,0) ya se ha calculado antes
    aux = 0;
    for(int j = 0; j<=i-1; j++){
      aux = aux + L(i,j)*Z(j,0);
    }
    Z(i,0) = B(i,0)-aux;
  }

  X(n-1,0) = 1/(U(n-1,n-1))*Z(n-1,0); // el ultimo valor se establece antes

  for(int i=n-2; i>=0; i--){
    aux = 0;
    for(int j = i+1; j<n; j++){
      aux = aux+U(i,j)*X(j,0);
    }
    X(i,0) = 1/(U(i,i))*(Z(i,0)-aux);
  }

} // cierre lu
