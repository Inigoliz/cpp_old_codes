// RACIMOS:


#include <iostream>

using namespace std;

bool casoDePrueba(){

  int num;
  cin>>num;

  if(num==0){
    return false;
  }
  else{
    int nivel = 1;
    int resto = 0;
    int caso = 1;
    resto = num;
    
    while(resto>0){
      resto = resto - nivel;
      nivel +=1;
    }

    cout<<nivel-1<<"\n";

    
    // RUTINA:
    
  }
  return true;
}


int main(){
  while(casoDePrueba()){ // sale de él tras el indicador de final de problema
  }
  
  return 0;

}
