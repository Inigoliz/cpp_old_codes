/*resolucion de Sistemas No Lineales por Newton Raphson*/

#include "lu_mat.cxx" // para hallar la inversa del jacobiano no con !J, que es mas lento

void newtonraphson(matrix<double>(*f)(matrix<double>, int), matrix<double>(*jacobiano)(matrix<double>, int), matrix<double> X0, matrix<double> &X, double eps, int dim, int &ite){
  
  /* f = (f1(x),...,fn(x))
     jacobiano = (j11(x),...,j1n(x);...;jn1(x),...,jnn(x))
     X0: punto de partida
     X: vector del programa principal donde se guarda la solucion
     eps: precision
     dim: dimension de las matrices (numero incognitas)
     ite: iteraciones
  */

  matrix<double> F(dim,1); // vector que guarda los valores de (f1(X0),...,fn(X0)
  matrix<double> J(dim,dim); // matriz que guarda los valores del jacobiano evaluado en X0
  double det = 0;

  X = X0;

  J = jacobiano(X0,dim);
  det = J.Det();

  if(abs(det)<1e-10){
    cout<<"JACOBIANO = 0; ELEGIR OTRO PUNTO DE PARTIDA"<<endl;
  }
  else{
    do{
      if(abs(det)<1e-10){
	X0 = X;
	F = f(X0,dim);
	J = jacobiano(X0,dim);
	//X = X0-(!J)*F; // Con inversion por parte de matrix.h. LENTO; APARATOSO
	lu_mat(J, J*X0-F, X, dim);
	ite++;
	J = jacobiano(X,dim);
	det = J.Det();
      }
      else{
	cout<<"JACOBIANO = 0; Calculo abortado"<<endl;
      }
    }
    while((X-X0).Norm()>eps); // cuando sea muuuy pequeño. por calculo numerico, puede que no sea 0, aunque debiera serlo
  }

}
