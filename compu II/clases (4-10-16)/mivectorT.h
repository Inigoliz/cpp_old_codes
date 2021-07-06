//Los archivos .h son como los .cxx, pero nos recuerda que este archivo se va a encontrar en las cabeceras de otros
#include <cmath>
double maxvec(double * V, int n){
  double elmayor;
  elmayor=V[0];
  for (int i=1;i<n;i++){
    if(V[i]>elmayor){
      elmayor=V[i];
    }
  }
  return elmayor;
}


//La clase mivector incluye las operaciones usuales
//con vectores numericos de dimension n 


template <class T> //Template permite que definamos T de como queramos (double,int,char...)
class mivector{
  protected:
    T *v;int n;
  public:
    mivector(); //Declaracion de la funcion sin concretar nada
    mivector(int);  //Declaracion con dimension del vector
    mivector(T *,int);
    //Tenemos una sobrecarga de el nombre de la funcion mivector. Dependiendo de los argumentos que le pongas te cogera una de las funciones mi vector
    T& operator[](int); //Defines que pasa cuando le pones corchetes a un numero de clase mi vector
                        //Devuelve el valor de un elemento
    mivector<T> operator*(T); //Multiplicacion de un vector por un numero
    //En T podemos asignar el tipo a nuestro vector
    mivector<T> operator+(mivector<T>); //Suma de dos vectores
    mivector<T> operator-(mivector<T>); //Resta de dos vectores
    T operator*(mivector<T>); //Producto escalar de dos vectores
    //Lo que esta a la izq de operator es lo que te va a devolver, el simbolo es como lo vas a invocar, y lo de la derech es es el tipo del que vaa ser el segundo argumento, el primero es por definicion del tipo mi vector
    T operator||(int ); //Norma de un vector
    T norma(int);       //Norma de un vector
    int dimension(){return n;}; //Devuelve la dimension o numero de elementos
                                //de los vectores
};



template <class T>
mivector<T>::mivector(){}

template <class T>
mivector<T>::mivector(int m){
  v=new T[m]; //New para poner la dimension
  n=m;
}

template <class T>
mivector<T>::mivector(T *u,int m){
  v=new T[m];
  n=m;
  for(int i=0;i<m;i++){
    v[i]=u[i];
  }
}


template <class T>
T mivector<T>::norma(int tipo){
  T sum;
  if(tipo==2){
    sum=0;
    for(int i=0;i<n;i++){
      sum=sum+v[i]*v[i];
    }
    return sqrt(sum);
  } else if(tipo==0){
    T u[n];
    for(int i=0;i<n;i++){
      u[i]=fabs(v[i]);
    }
    T amax=maxvec(u,n);
    return amax;
  }
}


template <class T>
T mivector<T>::operator||(int tipo){
  T sum;
  if(tipo==2){
    sum=0;
    for(int i=0;i<n;i++){
      sum=sum+v[i]*v[i];
    }
    return sqrt(sum);
  } else if(tipo==0){
    T u[n];
    for(int i=0;i<n;i++){
      u[i]=fabs(v[i]);
    }
    T amax=maxvec(u,n);
    return amax;
  }
}

template <class T>
T mivector<T>::operator*(mivector<T> u){
  T sum;
  sum=0;
  for(int i=0;i<n;i++){
    sum=sum+v[i]*u[i];
  }
  return sum;
}


template <class T>
T& mivector<T>::operator[](int j){
  return v[j];
}


template <class T>
mivector<T>  mivector<T>::operator+(mivector<T> w){
  //Suma de dos vectores
  mivector<T> aux(n);
  for(int i=0;i<n;i++){
    aux.v[i]=v[i]+w.v[i];
  }
  return aux;
}

template <class T>
mivector<T>  mivector<T>::operator-(mivector<T> w){
  //Suma de dos vectores
  mivector<T> aux(n);
  for(int i=0;i<n;i++){
    aux.v[i]=v[i]-w.v[i];
  }
  return aux;
}

template <class T>
mivector<T>  mivector<T>::operator*(T a){
  //Multiplicacion de un vector por un numero
  mivector<T> aux(n);
  for(int i=0;i<n;i++){
    aux.v[i]=v[i]*a;
  }
  return aux;
}

template <class T,int sz>
class mivectores : public mivector<T>{
  public:
    mivectores() : mivector<T>(sz){};
};

template <class T>
mivector<T> operator*(T a, mivector<T> u){
  return u*a;
}
