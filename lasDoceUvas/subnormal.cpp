// SUBNORMAL:

#include <iostream>
#include <string>

using namespace std;

bool casoDePrueba(){

  string numero;

  getline(cin,numero);

  if(!cin){
    return false;
  }
  else{

    int reps[10]; // repeticiones de cada numero

    for(int i=0; i<10;i++){
      reps[i] = 0;
    }
  
  
    for(int i = 0; i<numero.length(); i++){
      switch(numero[i]){

      case '0':
	reps[0]+=1;
	break;
      case '1':
	reps[1]+=1;
	break;
      case '2':
	reps[2]+=1;
	break;
      case '3':
	reps[3]+=1;
	break;
      case '4':
	reps[4]+=1;
	break;
      case '5':
	reps[5]+=1;
	break;
      case '6':
	reps[6]+=1;
	break;
      case '7':
	reps[7]+=1;
	break;
      case '8':
	reps[8]+=1;
	break;
      case '9':
	reps[9]+=1;
	break;
      }
    }

    if((reps[0]==reps[1])&&(reps[1]==reps[2])&&(reps[2]==reps[3])&&(reps[3]==reps[4])&&(reps[4]==reps[5])&&(reps[5]==reps[6])&&(reps[6]==reps[7])&&(reps[7]==reps[8])&&(reps[8]==reps[9])){
      cout<<"subnormal\n";
    }
    else{
      cout<<"no subnormal\n";
    }
  }
  
  return true;

}


int main(){
  
  while(casoDePrueba()){
  }
  
  return 0;

}
