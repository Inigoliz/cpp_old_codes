// VOID Pointers

#include <iostream>

using namespace std;

void increase (void* data, int psize)  // toma un puntero void
{
  if (psize == sizeof(char)){
    char* pchar;
    pchar=(char*)data; // hace falta decir de qué tipo es data
    ++(*pchar); // incremeneta 1 al código ASCII, una vez desreferenciado pchar
  }
  else if (psize == sizeof(int)){
    int* pint;
    pint=(int*)data;
    ++(*pint);
  }
}

int main (){
  char a = 'x';
  int b = 1602;
  increase (&a,sizeof(a));
  increase (&b,sizeof(b));
  cout << a << ", " << b << '\n';
  //cout<<sizeof(float)<<endl;
  return 0;
}
