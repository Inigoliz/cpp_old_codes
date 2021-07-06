//Esta clase permite sumar dos fracciones

class fraccion{

private:

  //En private van los obejtos que van dentro de la clase y solo pueden ser manipulados dentro de la clase, solo viven ahi
  int numerador, denominador;

public:

  // En public van cosas que pueden ser accesibles desde fuera de la clase, por ejemplo, desde el main program
  fraccion(){numerador=0;denominador=1;};

  //El numerador = 0 y denominador =1 da los valores por defecto si uno solo nombre fracciones() sin dar valores
  fraccion(int n, int d); //Nombras la funcion que vas a definir mas abajo
 
  fraccion operator+(fraccion f); //Defines lo que va a hacer el simbolo +
 
  friend ostream & operator<<(ostream & s, fraccion h); //Para escribir fraccion en pantalla o fichero

  //friend te premite que el operador flujo (<<) pueda actuar dentro de la clase
};

fraccion::fraccion(int n, int d){ //El :: es un constructor, asocias la funcion fraccion a la clase fraccion (a la izq)
  numerador = n; denominador = d;
}
fraccion fraccion::operator+(fraccion h){
  fraccion aux; //Ya existe un tipo fraccion

  aux.numerador = numerador * h.denominador +
    denominador * h.numerador; //Para acceder al numerador ponemos aux.numerador
  aux.denominador = denominador * h.denominador;

  // el h corresponde a la fraccion que esta a la derecha del mas, el que esta a la izquierda es simplemente numerador y denominador

  //El resultado es aux.numerador y aux.denominador
  return aux;
}

ostream & operator<<(ostream & s, fraccion h){
  s<<h.numerador<<"/"<<h.denominador;
  return s;
}
