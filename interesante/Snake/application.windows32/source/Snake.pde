int sheigth = 700; // screen heigth
int swidth = 700;

byte num = 50; // longitud máxima de píxeles de la serpiente
byte a = 1; // para indicrar en que dirección se inserta la nueva pieza
int pos = 1; // para el elmento de la serpiente en que se van guardando las nuevas posiciones
int usad = 0; // piezas de serpiente usadas
int temp = 150;//cada cuanto se mueven
int t = 0; // variable para manejo temporal

int tam = 35; // tamaño de los píxeles

float[] xs = new float[num]; // posición de la serpiente
float[] ys = new float[num];


float x = random(50, swidth-50);
float y = random(50, sheigth-50);


void setup(){
  size(700, 700);
  xs[0] = random(200, swidth-200);
  ys[0] = random(200, sheigth-200);
  for(byte i = 1; i<num; i++){ // rellena todos menos el primero para que no estén en pantalla
    xs[i] = -1000;
    ys[i] = -1000;
  }
}

void draw(){
  background(255, 175, 0);
  
  fill(255, 0, 0);
  rect(x, y, tam, tam);
  
   if (keyPressed) {
    if (key == 'w') {
     a = 4;
    }
    else if(key == 's'){
      a = 3;
    }
    else if(key == 'a'){
      a = 2;
    }
    else if(key == 'd'){
      a = 1;
    }
   }

  if(millis() >= temp+t){ // movimiento
   switch(a){ 
     case 1: // choque por la dcha
       if(usad > 0){
         for(int i = usad; i>0; i--){
            xs[i] = xs[i-1];
            ys[i] = ys[i-1];
         }
       }
       xs[0] = xs[0] + tam;
       break;
     case 2: //choque por izq
       if(usad > 0){
         for(int i = usad; i>0; i--){ 
            xs[i] = xs[i-1];
            ys[i] = ys[i-1];
         }
       }
       xs[0] = xs[0] - tam;
       break;
     case 3: //choque por arriba
       if(usad > 0){
         for(int i = usad; i>0; i--){
            xs[i] = xs[i-1];
            ys[i] = ys[i-1];
         }
       }
       ys[0] = ys[0] + tam;
       break;
     case 4: //choque por abajo
       if(usad > 0){
         for(int i = usad; i>0; i--){
            xs[i] = xs[i-1];
            ys[i] = ys[i-1];
         }
       }
       ys[0] = ys[0] - tam;
       break;
   }
   t = millis();
  }
 
 if((((xs[0]+tam+2) > x) && ((xs[0]+tam) <= (x+tam)) && (ys[0]>y-tam) && (ys[0]<y+tam)) || (((xs[0]) >= x) && ((xs[0]-2) <= (x+tam)) && (ys[0]>y-tam) && (ys[0]<y+tam)) || (((ys[0]+tam+2) >= y) && ((ys[0]) <= (y+tam)) && (xs[0]>x-tam) && (xs[0]<x+tam)) || (((ys[0]) >= y) && ((ys[0]-2) <= (y+tam)) && (xs[0]>x-tam) && (xs[0]<x+tam))){
   switch(a){ 
     case 1: // choque por la dcha
        xs[pos] = xs[pos-1] - tam;
        ys[pos] = ys[pos-1];
        break;
     case 2: //choque por izq
        xs[pos] = xs[pos-1] + tam;
        ys[pos] = ys[pos-1];
        break;
     case 3: //choque por arriba
        ys[pos] = ys[pos-1] - tam;
        xs[pos] = xs[pos-1];
       break;
     case 4: //choque por abajo
        ys[pos] = ys[pos-1] + tam;
        xs[pos] = xs[pos-1];
       break;
   }
   pos = pos+1;
   usad = usad+1;
   x = random(50, swidth-50); //swidth-50
   y = random(50, sheigth-50); //sheigth-50
 }
 
 if(xs[0]<-5){ // sumar o restar 5 es para dejar cierto margen, y que no haya bucles de rebote
   xs[0] = swidth;
 }
 if(xs[0]>swidth+5){
   xs[0] = 0;
 }
 if(ys[0]<-5){
   ys[0] = sheigth;
 }
 if(ys[0]>sheigth+5){
   ys[0] = 0;
 }

 
 for(int i = 0; i<num; i++){  // pintar la serpiente
   if(i == 0){
     fill(0, 0, 255);
   }
   else{
    fill(0, 255, 70);
   }
    rect(xs[i], ys[i], tam, tam);
  }
  
}
