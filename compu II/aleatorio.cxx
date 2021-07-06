/*
Es algo muy frecuente, cuando ya dominas todo eso de pedir y almacenar datos, ahora tu profesor te pedirá que tus programas generen números aleatorios para automatizar el proceso de llenar arreglos y todo eso.

Así que lo primero que tenemos que hacer es incluir la librería:
#include<stdlib.h>

Necesitamos esta libreria para usar la función time()
#include<time.h>

Luego inicializar los números aleatorios incluyendo esto:
srand(time(NULL));

Luego guardar el número aleatorio en alguna parte:
num = rand();

Para ajustar el rango de número aleatorios podemos hacer varias cosas.

- Número aleatorios entre 0 y 50:
  num=rand()%51;

- Número aleatorios entre 1 y 100:
  num=1+rand()%(101-1);

- Número aleatorios entre 250 y 420:
  num=250+rand()%(421-250);

De forma general es:
variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
*/

#include <stdlib.h>  // librería estándar
#include <time.h> // libreria para manejar tiempo
#include <iostream>

using namespace std;

int main()
{
    int num, c;
    srand(time(NULL)); // genera una semilla para los numeros aleatorios

    for(c = 1; c <= 30; c++)
    {
        num = 1 + rand() % (11 - 1);
        cout << num<< " ";
    }

    cin.get();

    return 0;
}
