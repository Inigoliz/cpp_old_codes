// STRING TO INT:

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main(){

  string myString = "37";

  istringstream buffer(myString);
  int value;
  buffer >> value;

  cout<<value+3<<endl; // value = 45. Output = 48

}
