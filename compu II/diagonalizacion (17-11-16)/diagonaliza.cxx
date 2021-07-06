/* 17-11-16*/
/*DIAGONALIZACION DE MATRICES CON EL METODO DE JACOBI (iterativo):

Diagonaliza matrices simetricas (A=At)

*/
 
void diagonaliza(matrix<double> A, matrix<double> &lambda, matrix<double> &vect, int n, double eps, int &ite){

  double the = 0.0;
  matrix<double> R(n,n);
  matrix<double> Rt(n,n); // Rt = Rinv, pero cuesta mucho computar la inversa, y la traspuesta es cambiar el signo del seno solo
  R.Unit();
  Rt.Unit();
  vect.Unit();
  int i = 0; // posicion i del elemento maximo (en la diagonal superior)
  int j = 0; // posicion j del elemento maximo (en la diagonal superior)

  double pi = acos(-1.0);

  maxMat(A, i, j, n); // devuelve en i y j la posicion del maximo de la matriz (como es simetrica, se calcula el maximo para los elementos de la parte superior de la diagonal principal)

   while(abs(A(i,j)) > eps){
    if(A(i,i)!=A(j,j)){
      the = 0.5*atan(2*A(i,j)/(A(i,i)-A(j,j)));
    }
    else{
      the = pi/4; // pi/4
    }

    R.Unit();
    Rt.Unit();

    // Declaracion de R y Rt
    R(i,j) = -sin(the);
    R(i,i) = cos(the);
    R(j,j) = R(i,i);
    R(j,i) = -R(i,j);

    Rt(i,j) = R(j,i);
    Rt(i,i) = R(i,i);
    Rt(j,j) = R(i,i);
    Rt(j,i) = R(i,j);

    A = Rt*A*R;  // poco a poco se va diagonalizando
    vect=vect*R; // va rellenando los autovectores
    ite++;
    maxMat(A, i, j, n);

   }

   for(int l = 0; l<n; l++){
       lambda(l,0) = A(l,l); 
   }
}
