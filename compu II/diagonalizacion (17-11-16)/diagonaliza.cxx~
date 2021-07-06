/* 17-11-16*/
/*DIAGONALIZACION DE MATRICES CON EL METODO DE JACOBI (iterativo):

Diagonaliza matrices simetricas (A=At)

*/
 
void diagonaliza(matrix<double> A, matrix<double> &B, int n, double eps){

  double the = 0;
  matrix<double> R(n,n);
  matrix<double> Rt(n,n); // Rt = Rinv, pero cuesta mucho computar la inversa, y la traspuesta es cambiar el signo del seno solo
  R.Null();
  Rt.Null();
  int i = 0; // posicion i del elemento maximo (en la diagonal superior)
  int j = 0; // posicion j del elemento maximo (en la diagonal superior)

  B = A;

  maxMat(B, i, j, n); // devuelve en i y j la posicion del maximo de la matriz (como es simetrica, se calcula el maximo para los elementos de la parte superior de la diagonal principal)

  if(B(i,i)==B(j,j){
      the = acos(-1.0)/4; // pi/4
    }
    else{
      the = 1/2*atan(2*B(i,j)/(B(i,i)-B(j,j)));
    }

  for(int k =0; k<n; k++){ // se rellenan R y Rt
    R(k,k) = 1;
    Rt(k,k) = 1;
  }

    R(i,j) = -sin(the);
    Rt(i,j) = sin(the);
    R(i,i) = cos(the);
    Rt(i,i) = cos(the);
    R(j,j) = cos(the);
    Rt(j,j) = cos(the);
    R(j,i) = sin(the);
    Rt(j,i) = -sin(the);

    B = Rt*B*R;

    cout<<B<<endl;


}
