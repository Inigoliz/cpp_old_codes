// overloading class constructors
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle ();
    Rectangle (int,int);
    int area (void) {return (width*height);}
};

Rectangle::Rectangle () {  // Esta es la función ejecutada cuando se llama rect()
  width = 5;
  height = 5;
}

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4);
  Rectangle rectb;
  Rectangle *p;
  p = &rectb;
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;ç
  //cout << "hey */" <<p->width<< '\n';  // no va a poder, pues width es privado
  cout << "hey */" <<p->area()<< '\n';
  return 0;
}
