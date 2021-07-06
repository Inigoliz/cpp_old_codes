//Define vectores al igual que las operaciones algebraicas usuales
//Los elementos de los vectores se suponen reales de doble precision (double).
//Autor:  Jose del Peso
//Fecha:  24 de Septiembre del 2010



#include "normsup.cxx"
#include <cmath>

//La clase mivector incluye las operaciones usuales
//con vectores reales (double) de dimension n 

class mivector{
  protected:
    double *v; int n;
  public:
    mivector(int);                //Declaracion con dimension del vector
    double& operator[](int);      //Asignacion de valor a un elemento
                                  //Devuelve el valor de un elemento
    mivector operator+(mivector); //Suma de dos vectores
    mivector operator-(mivector); //Resta de dos vectores
    mivector operator*(double);   //Multiplicacion de un vector por un numero
                                  //Se ha definido tambien una funcion, que
                                  //no es de la clase, pera hacer la
                                  //multiplicacion de un numero por un vector
    double operator*(mivector);   //Producto escalar de dos vectores
    double operator||(int);       //Norma de un vector. El argumento indica
                                  //que tipo de norma:
                                  // supremo (0), cuadratica (2)
    int dimension(){return n;}    //Devuelve la dimension o numero de elementos
                                  //de los vectores
};

mivector::mivector(int ndim){
  //Constructor
  v=new double[ndim];
  n=ndim;
}

double&  mivector::operator[](int j){
  //O bien:
  //   utilizado para asignacion de un valor al elemento j de un vector
  //o bien:
  //   devuelve el valor del elemento j de un vector
  return v[j];
}

mivector mivector::operator+(mivector vecin){
  //Suma dos vectores ( vecout = *this + vecin )
  mivector vecout(n);
  for(int i=0;i<n;i++){
    vecout.v[i]=v[i]+vecin.v[i];
  }
  return vecout;
}

mivector mivector::operator-(mivector vecin){
  //Suma dos vectores ( vecout = *this - vecin )
  mivector vecout(n);
  for(int i=0;i<n;i++){
    vecout.v[i]=v[i]-vecin.v[i];
  }
  return vecout;
}


mivector mivector::operator*(double num){
  //Multiplica un vector por un numero ( vecout = *this * num )
  mivector vecout(n);
  for(int i=0;i<n;i++){
    vecout.v[i]=num*v[i];
  }
  return vecout;
}

double mivector::operator*(mivector vecin){
  //Producto escalar de dos vectores ( sum = *this * vecin )
  double sum;
  sum=0;
  for(int i=0;i<n;i++){
    sum=sum+ v[i]*vecin.v[i];
  }
  return sum;
}


double mivector::operator||(int opt){
  //Norma de un vector. El argumento opt se refiere
  //al tipo de norma: supremo (0), cuadratica (2). ( numout = (*this)||(2) )
  if (opt==0) {return normsup(v,n);}
  if (opt==2) {return sqrt((*this)*(*this));}
}

mivector operator*(double num, mivector& vecin){
  //Multiplicacion de un numero por un vector ( vecout = num * vecin )
  //No es una funcion de la clase
  const int n=vecin.dimension();
  mivector vecout(n);
  for(int i=0;i<n;i++){
    vecout[i]=num*vecin[i];
  }
  return vecout;
}

template <int sz>
class mivectores : public mivector{
  public:
    mivectores(): mivector(sz){};
};
