// PALOMAR:
#include <iostream>

using namespace std;

int caso = 0;

void casoDePrueba(){
  //if(caso==0){cout<<"\n";}
  
  int palomas, huecos;

  cin>>palomas>>huecos;

  if(palomas>huecos){    
    cout<<"PRINCIPIO\n";
  }

  else{
    cout<<"ROMANCE\n";
  }
  //cout<<"\n";
  caso+=1;
}

int main(){
  
  int numCasos = 0;
  cin>>numCasos;

  for(int i=0; i<numCasos; i++){
    casoDePrueba();
  }
  //cout<<"\n";

  return 0;

}
