
#include <cmath>
#include "maxvec.cxx"

//La clase mivector incluye las operaciones usuales
//con vectores numericos de dimension n 


template <class T>
class mivector{
  protected:
    T *v;int n;
  public:
    mivector();
    mivector(int);  //Declaracion con dimension del vector
    mivector(T *,int);
    T& operator[](int); //Asignacion de valor a un elemento
                        //Devuelve el valor de un elemento
    mivector<T> operator*(T); //Multiplicacion de un vector por un numero
    mivector<T> operator+(mivector<T>); //Suma de dos vectores
    mivector<T> operator-(mivector<T>); //Resta de dos vectores
    T operator*(mivector<T>); //Producto escalar de dos vectores
    T operator||(int ); //Norma de un vector
    T norma(int);       //Norma de un vector
    int dimension(){return n;}; //Devuelve la dimension o numero de elementos
                                //de los vectores
};



template <class T>
mivector<T>::mivector(){}

template <class T>
mivector<T>::mivector(int m){
  v=new T[m];
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
