template <class T>
/* donde ponga double, se pone T. En el main, mivector<double>. De esta forma, se puede cambiar toda la declaracion de variables */

class mivector{
  
protected: // guardado de datos
  double *v; int n; // n=dim, *v=direccion de los elementos
  
public: // funciones asociadas a tipo de dato mivector
  mivector(int);
  int dim();
  double & operator[](int); // & referencia de direccion de memoria
  mivector operator+(mivector);
}

mivector::mivector(int L){ // crea vector, creacion de tipo mivector
  v = new double[L];
  n = L;
}

int mivector::dim(){ // devuelve la dim del vector
  return n;
}

double & mivector::operator[](int L){
  // operator[]: declaracion de funcion para objeto tipo mivector
  return v[L]; // v puntero de array, [] de array
}

mivector mivector::operator+(mivector z){
  mivector aux(n);
  for (int i=0; i<n; i++){
    aux.v[i] = v[i] + z.v[i]; // => aux[i] = v[i] + z[i]
  }
  return aux;
}

/* funcion que no es de la clase. No declaracion en public
   No se pueden usar las variables protegidas, pero si las funciones de la clase*/
mivector operator*(double a, mivector z){
  int n=z.dim(); 
  mivector aux(n);
  for (int i=0; i<n; i++){
    aux[i]=a*z[i];
  }
  return aux;
}
