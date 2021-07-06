// DOBLECES PAPEL:

#include <iostream>
#include <math.h>

using namespace std;

bool casoDePrueba(){

  double grosor, altura;
  cin>>grosor>>altura;

  int pliegues = 0;

  grosor = grosor/1000000;

  if(!cin){
    return false;
  }
  else{
     while(grosor<altura){

      grosor = grosor * 2.0;
      
      pliegues+=1;
      //cout<<grosor<<"\n";
      //cout<<pliegues<<"\n";
      
      }
       //cout<<grosor<<"\n";
       cout<<pliegues<<"\n";
    
  }
  
  return true;

}


int main(){

  while(casoDePrueba()){
  }

  
  return 0;

}
