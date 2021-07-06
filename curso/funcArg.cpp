// Functions as arguments

#include <iostream>

using namespace std;

int add(int a, int b){
  return a+b;
}

void print(int (*add)(int, int), int a, int b){
  cout<<add(a, b)<<endl;
}

int main(){

  print(add, 4, 3);

  return 0;
}
