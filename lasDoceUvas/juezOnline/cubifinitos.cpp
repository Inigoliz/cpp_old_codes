// Números cubifinitos (extraer dígitos de un número)

#include <iostream>
#include <math.h>

using namespace std;

int iteracion(int n){
  int digitos = 1;
  int ntemp = n;

  while(ntemp/10 > 0){ // halla el numero de digitos
    digitos += 1;
    ntemp = ntemp/10;
  }

  int d[digitos]; // separa los digitos

  for(int i=0; i<digitos; i++){
    int aux = pow(10,(digitos-1-i));
    d[i] = n/aux;
    n = n % aux;
  }

  for(int i=0; i<digitos; i++){ // evalua la siguiente iteracion
    n = n+pow(d[i],3);
   }

  return n;
}



bool casoDePrueba(){

  int num;
  cin>>num;

  if(num==0){
    return false;
  }
  else{    ////////////// RUTINA://///////////////

    int anteriores[15];
    for(int i=0; i<15; i++){anteriores[i] = 0;}
    int pos = 0;

    cout<<num;

    while(num!=1){

      anteriores[pos] = num;
      num = iteracion(num);

      cout<<" - "<<num;

      for(int i=0; i<15; i++){ // evalua si esta repetido

	if(num == anteriores[i]){

	  cout<<" -> no cubifinito. \n";
	  goto mylabel;
	}

	else{
	}
      }

      pos +=1;

    }

    cout<<" -> cubifinito. \n";

    // RUTINA:

  }
  mylabel:
  return true;
}



int main(){
  cout<<"\n ";
  while(casoDePrueba()){ // sale de él tras el indicador de final de problema
  }

  return 0;

}
