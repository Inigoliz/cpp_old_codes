
#include <iostream>
#include <new>  // Operador new

using namespace std;

void func(int **a){  // "Lo que te voy a pasar es un puntero doble"
  cout<<a[2][1]<<endl;
}

int main() {

  int a, b;
  a = 3;
  b = 3;

  int **array = new int*[a]; // allocate an array of axb int pointers — these are our rows

  for (int count = 0; count < a; count++){
      array[count] = new int[b]; // these are our columns
  }

  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      cout<<"Número de la posición ("<<i<<","<<j<<")\n";
      // cin>>array[i][j];
      // cin.ignore();
      array[i][j] = a*i+j;
    }
  }

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      cout<<array[i][j]<<" ";
    }
    cout<<"\n";
  }

  func(array);

  //
  // for (int count = 0; count < b; ++count){ // Primero se borran las columnas
  //   delete[] array[count];
  // }
  // delete[] array; // Por último, las filas

  return 0;
}
