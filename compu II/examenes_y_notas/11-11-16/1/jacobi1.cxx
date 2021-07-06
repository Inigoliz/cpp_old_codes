/*METODO DE JACOBI para resolucion de sistemas de ecuaciones*/

/*NECESITA QUE ESTE DECLARADO EN EL PRINCIPAL "matrix.h" y todas sus librerias asociadas;*/

void jacobi(double *a, double *b, double *x, int n, double eps, int &ite){ // a, b y x son punteros que dirigen a las posiciones en el programa principal donde se han  guardado los elementos del sistema a resolver

  /*El programa toma vectores habituales de C++ y crea matrices de la clase matrix a partir de ellos.
    podria editarlo para que tomara directamente matrices de clase matrix, pero creo que es mas util de esta forma*/

  matrix<double> A(n,n);
  matrix<double> C(n,n);
  matrix<double> B(n,1);
  matrix<double> X0(n,1);
  matrix<double> X(n,1);
  matrix<double> Cinv(n,n); // inversa de C (que como es diagonal, es facil de calcular)
  matrix<double> Ide(n,n); // Identidad nxn
  matrix<double> Ide1(n,1); // Identidad nx1
  matrix<double> auxNorm(n,n); // matriz que guarda (1-Cinv*A), y despues llamando a normmat, nos devolvera su norma

  A.Null();
  B.Null();
  C.Null();
  Cinv.Null();
  X0.Null();
  X.Null();
  Ide.Null();
  Ide1.Null();

  double norma = 0;

  // Rellena A, B y C, Cinv, Ide, Ide1
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      A(i,j) = a[i*n+j];
      }
    C(i,i) = a[i*n+i]; // en la diagonal los valores de A, en los demas 0
    Cinv(i,i) = 1/(a[i*n+i]);
    B(i,0) = b[i]; // los indices empiezan en 0!!
     Ide(i,i) = 1; // =1
     Ide1(i,0) = 1; // =1
    }

  auxNorm = (Ide - Cinv*A);
  norma = normaMat(auxNorm, n); // normaMat es una funcion que toma una matriz (matrix.h) y devuelve su norma

   if(norma<1){ // recurrencia solo si el metodo converge, lo que se comprueba con la norma de la matriz
     do{
       ite++;
       X0 = X;
       X = Cinv*(B+(C-A)*X0);
     }while((X-X0).Norm()>eps);
   }
  else{
    cout<< "EL METODO NO CONVERGE"<<endl;
  }

   for(int i = 0; i<n; i++){
     x[i] = X(i,0); // guarda los valores calculado en el vector principal, para devolverlos al programa principal
   }

}
