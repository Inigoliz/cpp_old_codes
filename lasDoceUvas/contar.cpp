// CONTAR:

#include <sstream>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool casoDePrueba(){

  string num;
  int pos = 0;
  int inum = 0;

  getline(cin,num);
  cout<<num;

  if(!cin){
    return false;
  }
  else{
    if(num.legth()<4 && num != '999'){
      istringstream buffer(num);
      buffer >> inum;
      cout<<inum+1<<"\n";
    }
    if(num == '999'){
      cout<<"1.000\n";
    }
    else{
      pos = num.length();
      while(num[pos-1]=='9'){
	int aux = 0;
	istringstream buffer(num[pos-1]);
        buffer >> aux;
	aux +=1;
	stringstream buffer2(aux);;
	string str;
        str <<buffer2;
	num[pos-2] = str;
	num[pos-1] = '0';
	pos -=1;
      }


    }


  }

  return true;

}


int main(){

  while(casoDePrueba()){
  }


  return 0;

}
