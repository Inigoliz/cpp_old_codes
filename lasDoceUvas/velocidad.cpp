//VELOCIDAD:

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void casoDePrueba(){
  
  string pri, seg;
  cin>>pri>>seg;

  int t, d, v;
  t = 0;
  d = 0;
  v = 0;

  if(pri[0] == 'D'){
    if(seg[0] == 'T'){
      pri = pri.erase(0,2);
      seg = seg.erase(0,2);

      istringstream buffer1(pri);
      buffer1 >> d;
      istringstream buffer2(seg);
      buffer2 >> t;

      v=d/t;
      cout<<"V="<<v<<"\n";
    }
    
    if(seg[0] == 'V'){
      pri = pri.erase(0,2);
      seg = seg.erase(0,2);

      istringstream buffer1(pri);
      buffer1 >> d;
      istringstream buffer2(seg);
      buffer2 >> v;

      t=d/v;
      cout<<"T="<<t<<"\n";
    }
  }

  if(pri[0] == 'T'){
    if(seg[0] == 'D'){
      pri = pri.erase(0,2);
      seg = seg.erase(0,2);

      istringstream buffer1(pri);
      buffer1 >> t;
      istringstream buffer2(seg);
      buffer2 >> d;

      v=d/t;
      cout<<"V="<<v<<"\n";
    }
    
    if(seg[0] == 'V'){
      pri = pri.erase(0,2);
      seg = seg.erase(0,2);

      istringstream buffer1(pri);
      buffer1 >> t;
      istringstream buffer2(seg);
      buffer2 >> v;

      d=v*t;
      cout<<"D="<<d<<"\n";
    }
  }

  if(pri[0] == 'V'){
    if(seg[0] == 'D'){
      pri = pri.erase(0,2);
      seg = seg.erase(0,2);

      istringstream buffer1(pri);
      buffer1 >> v;
      istringstream buffer2(seg);
      buffer2 >> d;

      t=d/v;
      cout<<"T="<<t<<"\n";
    }
    
    if(seg[0] == 'T'){
      pri = pri.erase(0,2);
      seg = seg.erase(0,2);

      istringstream buffer1(pri);
      buffer1 >> v;
      istringstream buffer2(seg);
      buffer2 >> t;

      d=v*t;
      cout<<"D="<<d<<"\n";
    }
  }

}

int main(){
  
  int numCasos = 0;
  cin>>numCasos;

  for(int i=0; i<numCasos; i++){
    casoDePrueba();

  }

  return 0;

}
