// CAMPANADAS:

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void casoDePrueba(){

  string datos, hora, min, seg;

  int ihora, imin, iseg;
  cin>>datos;

  hora = datos.substr (0,2);
  min = datos.substr (3,2);
  seg = datos.substr (6,2);

   istringstream buffer1(hora);
   buffer1 >> ihora;
   istringstream buffer2(min);
   buffer2 >> imin;
   istringstream buffer3(seg);
   buffer3 >> iseg;

  if(iseg!=0){
    imin+=1;
  }

  if(imin!=0){
    ihora+=1;
  }


  if(ihora == 0){
    cout<<"00";
  }
  else if(ihora < 14 && ihora != 0){
    cout<<24-ihora;
  }
  else{
    cout<<"0"<<24-ihora;
  }

  if(imin == 0){
    cout<<":00";
  }
  else if(imin < 50){
    cout<<":"<<60-imin;
  }
  else{
    cout<<":0"<<60-imin;
  }

  if(iseg == 0){
    cout<<":00\n";
  }
  else if(iseg < 50){
    cout<<":"<<60-iseg<<"\n";
  }
  else{
    cout<<":0"<<60-iseg<<"\n";
  }

}

int main(){

  int numCasos = 0;
  cin>>numCasos;

  for(int i=0; i<numCasos; i++){
    casoDePrueba();
  }

  return 0;

}
