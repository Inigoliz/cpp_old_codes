/* Problema del Hashcode 2018. Paula Melero, Miguel martínez, Jose María Hernández e Iñigo Lara */

/* Se utiliza la distancia Manhattan como métrica */

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

class Rutas{  // Guarda información de cada una de las rutas que están en la lista de espera
  public:
    int d, a, b, x, y, s, f;  // d: distancia Manhattan de la ruta + los demás parámetros según indica el problema de Google
    bool done;  // ruta ya completada

  void set (int ia, int ib, int ix, int iy, int is, int iif){
    a = ia;
    b = ib;
    x = ix;
    y = iy;
    s = is;
    f = iif;
    done = false;
    d = abs(x-a) + abs(y-b);
  }
};

class Nodos{
  public:
    int x, y;  // posición [row, column] = [x, y] del nodo en cuestión
    int n;  // número de rutas que parten del nodo
    int *rutas;  // puntero que guarda el identificador de cada ruta que parte del nodo

    // Identificador: número de la ruta según aparece en la lista de Google: 1, ..., N

  void addRuta(int i){  // guarda el identificador de una nueva ruta que parte del nodo
    rutas[n] = i;
    n++;
  }

    void set(int ix, int iy, int iN){
      x = ix;
      y = iy;
      rutas = new (nothrow) int[10];  // número de rutas que guarda cada nodo (a modificar)
      n = 0;
    }
};

int avanzar(int *icpos, int capas, int *rutPes, Nodos **nodo, Rutas *ruta, int (*funcPeso)(int*)){
// El objetivo de esta función es obtener la mejor ruta de todas aquellas en los nodos a una distancia de Capa
  rutPes[0] = 0;
  rutPes[1] = 0;

  // cout<<funcPeso(icpos, )<<endl;
  // for(int i = 0; i<capa; i++){  // cada nueva capa añade 4 nodos respecto a la anterior
  //   for(int j = 0; j<capa*4; j++){
  //     if()
  //
  //   }
  //
  // }
  //
  //
  return 1;


}

int funcPeso(int *icpos, Nodos &nodo, Rutas &ruta){  // Función para calcular como de bueno es un camino. Tiene en cuenta su longitud, el tiempo de espera,...
  return 6;
}

int main(){
  int R, C, F, N, B;
  long int T;
  int a, b, x, y, s, f;
  int t = 0;  // flujo del tiempo
  int *cpos = new int[2];  // [r, c] que guarda la posición actual del coche
  int capa = 0;  // Capa a inestigar. capa = 1; serían los nodos a distancia 1 del actual

  int peso = 0;  // distancia del camino (su peso)
  int *rutPes = new int[2];  // ruta y su peso. Para múltiples cálculos

  ifstream entrada("/Users/inigo/Documentos/Programación/Hashcode18/drivers_psi/a_example.in");
  ofstream salida("/Users/inigo/Documentos/Programación/Hashcode18/drivers_psi/sol.txt");

  entrada>>R>>C>>F>>N>>B>>T;

  Nodos **nodo = new Nodos*[R];  // Puntero 2D para guardar cada uno de los Nodos en un array
  for(int i = 0; i<C; i++){
    nodo[i] = new Nodos[C];
  }

  for(int i = 0; i<R; i++){
    for (int j = 0; j<C; j++) {
      nodo[i][j].set(i, j, N);
    }
  }

  Rutas *ruta = new Rutas[N+1];  // Puntero de objetos Rutas. Cada elemento guarda info. de su longitud, horarios, ...

  /* Para evitar confusiones con la nomenclatura de Google, en que las rutas se identifican con números de 1 a N, se crea un puntero *ruta que no utiliza el [0], y que tiene N huecos efectivos (hasta N+1) */

  for(int i = 1; i<N+1; i++){  // Las rutas empiezan a contar en 1
    entrada>>a>>b>>x>>y>>s>>f;
    ruta[i].set(a, b, x, y, s, f);
    nodo[a][b].addRuta(i);  // Se añade la ruta al nodo de que parte
  }

  for(int i=R-1; i>-1; i--){
    for(int j = 0; j<C; j++){
      salida<<nodo[i][j].n<<"||";
    }
    salida<<"\n";
  }

  //  cout<<ruta[nodo[473][815].rutas[0]].d<<endl; // Saca la información de la ruta guardada en la posición 0 (rutas[0]) del nodo [473][815]

  // peso = avanzar(cpos, capa, rutPes, nodo, ruta, funcPeso);
  // for(int i = 0; i<F; i++){
  //   t = 0;
  //   cy= 0;  // todos los coches parten de la posición [0, 0]
  //   cx = 0;
  //   ite = 0;
  //
  //   pr = avanzar(cy, cx, ite, pr, nodo, ruta);
  //   fsalida<<pr[1]<<" ";
  //
  // }

  entrada.close();
  salida.close();

  return 0;
}
