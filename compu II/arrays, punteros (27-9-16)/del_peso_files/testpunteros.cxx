#include <iostream>
using namespace std;
int main(){
  double a=5.1;
  cout<<a<<"  "<<&a<<"  "<<*(&a)<<endl;
  double *p; p=&a; p=p+1;
  cout<<p<<"   "<<&p<<endl;
  cout<<sizeof(a)<<"   "<<sizeof(p)<<endl;

  //Arrays
  double v[3]; v[0]=2.1; v[1]=3.4; v[2]=5.6;
  p=v;
  cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
  cout<<v[1]<<" "<<v<<"  "<<&v[1]<<endl;
  double *q; q = new double[3];
  q[0]=2.1; q[1]=3.4; q[2]=5.6;
  cout<<" Con 3 elementos q = "<<q<<endl;
  q = new double[5];
  cout<<" Con 5 elementos q = "<<q<<endl;
  //int n; cin>>n; q = new double[n];
  q[3]=1.1; q[4]=1.2;
  for(int i=0; i<=4; i=i+1){
    cout<<q[i]<<endl;
  }
  for(int i=0; i<=4; i=i+1){
    cout<<*q<<endl;
    q=q+1;
  }
  q=q-2;
  cout<<*q<<"  "<<q<<endl;


  double w[3]={1.2,1.3,1.4};
  q=w;
  int h[3]={1,2,3};
  int *t; t=h;

}
