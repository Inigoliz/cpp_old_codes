#include <iostream>
#include <string>

using namespace std;

void pei(int &ia);  // "Lo que te voy a pasar es un int, del que deberás coger su celda de memoria"
void pea(int *p);  // "Lo que te voy a pasar es un puntero"


int main() {
  int a, b;
  int *p, *q;
  cout<<"Inserte dos números: \n";
  cin>>a>>b;
  cin.ignore();

  p = &a;

  pei(a);  // se le pasa el argumento y él crea el alias a la celda de memoria
  pea(&b);  // se le pasa la celda de memoria

  cin.get();

  return 0;
}

void pei(int &ia){
  cout<<ia<<endl;
}

void pea(int *p){
  cout<<*p<<endl;
}
