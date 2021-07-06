/* funcion para calcular la posicion del elemento maximo (en valor absoluto)
   de una matriz simetrica (no considera los elementos de la diagonal principal)*/

void maxMat(matrix<double> A, int &i, int &j, int n){
  double max = 0;
  for(int a = 0; a<n; a++){ // este for barre los elemetnos estrictamente por encima de la diagonal principal
    for(int b = a+1; b<n; b++){
      if(abs(A(a,b))>max){
	max = abs(A(a,b));
	i = a;
	j = b;
      }
    }
  }
}
