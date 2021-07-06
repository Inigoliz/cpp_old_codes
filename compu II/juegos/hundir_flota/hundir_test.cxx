
/* JUEGO DE HUNDIR LA FLOTA - 12-10-16*/

/*EN PRUEBAS*/

#include <iostream>
#include <stdlib.h>
#include <time.h> // libreria para manejar tiempo

using namespace std;

void rellenar(int *a){ //funcion para rellenar aleatoriamente el tablero del PC con los barcos
  /* Habra 6 barcos:
     1 de 5 casillas:0
     1 de 4 casillas:1
     2 de 3 casillas:2,3
     2 de 2 casillas:4,5
  */
  int aux1; // variable en referencia a las filas
  int aux2; // variable en referencia a las columnas
  int ori; // direccion aleatoria en que se orienatara el barco:(1:dcha, 2:izq, 3:arr, 4:abaj)
  int pos; // crea una variable posicion, donde comenzara la asignacion del barco
  int barco; // indica el tipo de barco a colocar, guardando el numero de casillas que ocupa
  
  for(int i=0; i<6; i++){ //ejecuta el bucle for para cada barco
    if(i==0){barco=5;}
    if(i==1){barco=4;}
    if(i==2||i==3){barco=3;}
    if(i==4||i==5){barco=2;}
    // portaaviones, 5 casillas     
    srand(time(NULL)); // genera una semilla para los numeros aleatorios
    ori = 1 + rand() % (5 - 1); // numero aleatorio entre 0-4, direccion de orientacion     
    switch(ori){
    case 1: // si el portaaviones esta orientado hacia la derecha (morro apuntando hacia la izquierda)	
      do{
	do{
	  srand(time(NULL));
	  aux1 = 0 + rand() % (10 - 0); // puede ocupar cualquier fila, de la 0-9
	  aux2 = 0 + rand() % (10-barco+1 - 0); // si el barco esta orientado hacia la derecha, solo puede ocupar las columnas entre 0 y 5 (para que quepa)
	  pos = 10*aux1+aux2;
	}
	while(a[pos] == 1);// si esa posicion ya esta ocupada, coge otro numero	    
      }
      while((a[pos+1] || a[pos+2] || a[pos+3] || a[pos+4]) != 0);
      /* Se comprueba si estan libres horizontales derecha */
      for(int j=0; j<barco; j++){
	a[pos+j] = i+1;
      }
      break;
    case 2: // si el portaviones esta orientado hacia la izquierda (morro apuntando hacia la derecha)	
      do{
	do{
	  srand(time(NULL));
	  aux1 = 0 + rand() % (10 - 0); // puede ocupar cualquier fila, de la 0-9
	  aux2 = 4 + rand() % (10 - barco-1); // si el barco esta orientado hacia la izquierda, solo puede ocupar las columnas entre 4 y 9 (para que quepa)
	  pos = 10*aux1+aux2;
	}
	while(a[pos] == 1); // si esa posicion ya esta ocupada, coge otro numero
      }	
      while((a[pos-1] || a[pos-2] || a[pos-3] || a[pos-4]) != 0);
      /* Se comprueba si estan libres las horizontales  izquierda */
      for(int j=0; j<barco; j++){
	a[pos-j] = i+1;
      }
      break;
    case 3: // si el portaaviones esta orientado hacia abajo (morro apuntando hacia arriba)	
      do{
	do{
	  srand(time(NULL));
	  aux1 = 0 + rand() % (10-barco+1 - 0); // si el barco esta orientado hacia abajo, solo puede ocupar las filas entre 0 y 5 (para que quepa)
	  aux2 = 0 + rand() % (10 - 0); // puede ocupar cualquier columna, de la 0-9
	  pos = 10*aux1+aux2;
	}
	while(a[pos] == 1);// si esa posicion ya esta ocupada, coge otro numero	    
      }
      while((a[pos+10] || a[pos+20] || a[pos+30] || a[pos+40]) != 0);
      /* Se comprueba si estan libres las verticales descendente */
      for(int j=0; j<barco; j++){
	a[pos+10*j] = i+1;
      }
      break;
    case 4: // si el portaviones esta orientado hacia arriba (morro apuntando hacia abajo)	
      do{
	do{
	  srand(time(NULL));
	  aux1 = 0 + rand() % (10 - barco-1); // si el barco esta orientado hacia arriba, solo puede ocupar las filas entre 4 y 9 (para que quepa)
	  aux2 = 4 + rand() % (10 - 0); //  puede ocupar cualquier columna, de la 0-9
	  pos = 10*aux1+aux2;
	}
	while(a[pos] == 1); // si esa posicion ya esta ocupada, coge otro numero
      }	
      while((a[pos-10] || a[pos-20] || a[pos-30] || a[pos-40]) != 0);
      /* Se comprueba si estan libres las verticales ascendente */
      for(int j=0; j<barco; j++){
	a[pos-10*j] = i+1;
      }
      break;
    } // cierre switch(ori)   
  } // cierre for

  for(int j=0; j<100; j=j+10){
    cout<<a[j]<<" "<<a[j+1]<<" "<<a[j+2]<<" "<<a[j+3]<<" "<<a[j+4]<<" "<<a[j+5]
	<<" "<<a[j+6]<<" "	  <<a[j+7]<<" "<<a[j+8]<<" "<<a[j+9]<<" "<<endl;
  }

} // cierre funcion rellenar()




int main(){

  int pc[100]; // vector que guardara los estados de cada celdilla de barcos del PC

  for(int i=0; i<100; i++){ //inicializa pc a 0;
    pc[i] = 0;
  }

  rellenar(pc);


}
