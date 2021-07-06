#include <iostream>

using namespace std;

int main(){
  
  int *s; // crea un puntero s;
  int n = 10;
  s = &n; // asigna a s la direccion de memoria de n

  cout<<"s = "<<s<<endl; // imprime el valor de direccion de s, Hexadecimal
  cout<<"*s = "<<*s<<endl; // saca el valor guardado en la dir. memoria a qu apunta s, imrpime 10;
  *s = 3; // cambia el valor de la celda de memoria a que apunta s por 3
  cout<<"*s = "<<*s<<endl; // imprime 3
  
  double a = 5;
  cout<<sizeof(a)<<endl; // numero de bytes destinados a a; 8 en este caso (double)

  double *p;
  p = new double[10]; // se reservan 10 celdas de memoria, y p apunta al comienzo de ellas

  p[0] = 1;
  p[9] = 72;
  p[14] = 37; // aunque al principio se habian dedicado 10 espacios seguidos, se pueden utilizar los siguientes. SON ARRAYS VARIABLES EN TAMAÑO (cuidado: su hubiera algo en la casilla 14, se sobreescribiria)

  cout<<"p[0] = "<<p[0]<<"; p[9] = "<<p[9]<<endl;
  cout<<"p = "<<p<<endl; // imprime la direccion Hex a que apunta p
  cout<<"p[14] = "<<p[14]<<endl;

  char *pal;
  pal  = new char[10]; //reserva 10 huecos de memria a variables tipo char
  pal[0] = 'y'; // guarda el caracter x en la posicion 0 del bloque a que apunta el puntero pal
  cout<<"pal[0] = "<<pal[0]<<endl; //

  if(pal[0] == 120){ // el codigo ascii de la x es 120; aunque al poner "cout pal[0]" imprime "x", al poner un if, lo tarta segun su cdigo ascii
    cout<<"entro"<<endl;
   

}
