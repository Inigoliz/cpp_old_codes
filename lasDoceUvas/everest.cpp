// EVEREST:
#include <iostream>

using namespace std;

bool casoDePrueba(){

  int num;
  cin>>num;
  
  if(num==0){
    return false;
  }
  else{

    int escaladores = num;
    int vel[escaladores+1];

    int min = escaladores;
    int max = 1;
    int tam = 1; // tamaño del grupo

    int pri = 0; // velocidad del primero

    int grupos = 0;

    for(int i=0; i<escaladores; i++){     
      cin>>vel[i];
    }

    vel[escaladores]=0; // siempre se parte al final

    pri = vel[0];

    for(int i=1; i<escaladores+1; i++){
      
      if(vel[i]<pri){
	grupos +=1;
	pri = vel[i];
	if(tam<min){
	  min = tam;
	}
	if(tam>max){
	  max = tam;
	}
        tam = 1;
      }
      else{
        tam+=1;
      }
    }

    cout<<grupos<<" "<<min<<" "<<max<<"\n";
      
  }
  return true;
}


int main(){
  while(casoDePrueba()){ // sale de él tras el indicador de final de problema
  }
  
  return 0;

}
