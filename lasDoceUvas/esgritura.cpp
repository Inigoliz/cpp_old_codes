// ESGRITURA:

#include <iostream>
#include <string>

using namespace std;

bool casoDePrueba(){

  string frase;

  int signos,letras;
  signos = 0;
  letras = 0;

  int ascii;

  getline(cin,frase);

  if(!cin){
    return false;
  }
  else{

    for(int i = 0; i<frase.length(); i++){
      ascii = frase[i];

      if(frase[i]=='!'){
	signos+=1;
      }
      if((ascii>96 && ascii<123)||(ascii>64 && ascii<91)){
	letras+=1;
      }
    }

}

  if(signos>letras){
    cout<<"ESGRITO\n";
  }
  else{
    cout<<"escrito\n";
  }

  return true;

}


int main(){

  while(casoDePrueba()){
  }


  return 0;

}
