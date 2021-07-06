/*

JUEGO: AHORCADO

*/



#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;


int main(){

  cout << "\n\n\n" << setw(50) << "----- EL AHORCADO ----" << endl << endl << endl; 
  // Introduccion de la palabra

  char *palabra= new char[50];
    
  cout << "Introducir palabra (max. 50 caracteres):\n";

  cin.getline(palabra,50,'\n');
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  
  // Determinacion del numero de letras de la palabra
  
  int letras=0;

  int esp=0;

  int longitud=strlen(palabra); // el comando strlen nos da el número de caracteres

  for (int i=0; i<longitud; i++){

    if (palabra[i] == 32){ // 32 = espacio en codigo ASCII
      esp++;
    }

  }

  letras=longitud-esp; // el comando strlen nos da el número de letras

  cout << "\nLa palabra tiene " << letras << " letras \n";

  
  // Representacion grafica

  char *graf=new char[longitud];

  for(int i=0; i<longitud; i++){

    if (palabra[i] == 32){
      graf[i]=' ';
    }

    else {
      graf[i]='_';
    }

  }

  cout << setw(10) << graf << endl;


  // Comparacion de letras

  int lim_int=6;
  int intentos=0;
  int aciertos=0;

  while (intentos<=6){

    cout << "\nIntroducir letra: ";
    char letra;
    cin >> letra;

    int cont1=0;
    int cont2=0;
    
    for (int i=0; i<longitud; i++){

      if (letra==palabra[i]){
	graf[i]=letra;
	cont2++;
      }

      else {
	cont1++;
      }

    }

    if ((cont1-esp)==letras){
      intentos++;

      if (intentos==lim_int){
	cout << "\n\n" << setw(20) << "FIN DEL JUEGO :( \n" << "La palabra era " << palabra << endl << endl << endl;
	break;
      }

      else {
	cout << setw(10) << graf << endl;
	cout << "Intentos restantes: " << (lim_int-intentos) << endl;
      }
    }

    else {
      aciertos=aciertos+cont2;

      if (aciertos == letras){
	cout << setw(10) << graf << endl;
	cout << "\n\n" << setw (20) << "HAS GANADO! :) \n\n\n";
	break;
      }

      else {
	cout << setw(10) << graf << endl;
      }
    }
     
  }

  
  
}
