/* Funcion que calcula el menor elemento de un Array*/

#include <iostream>

using namespace std;


int minArray(int *a, int dim){

  int r;
  int i = 1;
  r = a[0]; // coge el primer elemento

  for(int i = 0; i<dim; i++){

    if(a[i] < r){ // compara el primer elemento con el segundo
	r = a[i];
    }
  }

  return r; 
}

int main(){
  const int n = 10;
  int minimo;

  int array[n] = {5,7,3,8,5,6,7,8,9,10};

  minimo = minArray(array,n);

  cout<<"el valor minimo del array es "<<minimo<<endl;
}
