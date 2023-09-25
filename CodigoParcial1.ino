int pinData = 2;
int pinLatch = 3;
int pinClock = 4;
int luces[8];
int inicio,inicio2=1;
long f1;
int opcion;
int Tiempo;
int Cantidad;
int apagado;
int guardar[8];
int inicio3;
#define TIEMPO 100
void LedWrite(int Led1, int Led2,int Led3, int Led4,int Led5, int Led6,int Led7, int Led8)
 {
  shiftOut(pinData, pinClock, LSBFIRST,Led8);
  shiftOut(pinData, pinClock, LSBFIRST,Led7);
  shiftOut(pinData, pinClock, LSBFIRST,Led6);
  shiftOut(pinData, pinClock, LSBFIRST,Led5);
  shiftOut(pinData, pinClock, LSBFIRST,Led4);
  shiftOut(pinData, pinClock, LSBFIRST,Led3);
  shiftOut(pinData, pinClock, LSBFIRST,Led2);
  shiftOut(pinData, pinClock, LSBFIRST,Led1);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(pinLatch, LOW);
 } 
void setup(){
  Serial.begin(9600);
  pinMode(pinData, OUTPUT);
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);  
  
}
void verificar(int Cantidad, int Tiempo){
  while(inicio2<=Cantidad){
  for(inicio=0;inicio <8;inicio++){
	luces[inicio]=B11111111;
  }
  LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(Tiempo);
	for(inicio=0;inicio <8;inicio++){
	luces[inicio]=B00000000;
  }
  LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(Tiempo);
    inicio2++;
  }  
}
void patrones(int Tiempo){
  
    for(inicio=0;inicio <8;inicio++){
      if(inicio==0 || inicio ==7){
      	luces[inicio]=B00011000;
      }
      else if(inicio==1||inicio==6){
      	luces[inicio]=B00111100;
      }
      else if(inicio==2||inicio==5){
      	luces[inicio]=B01111110;
      }
      else if(inicio==3||inicio==4){
      	luces[inicio]=B11111111;
      }
    }      
  LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(Tiempo);
	for(inicio=0;inicio <8;inicio++){
      if(inicio==0 || inicio ==7){
      	luces[inicio]=B10000001;
      }
      else if(inicio==1||inicio==6){
      	luces[inicio]=B01000010;
      }
      else if(inicio==2||inicio==5){
      	luces[inicio]=B00100100;
      }
      else if(inicio==3||inicio==4){
      	luces[inicio]=B00011000;
      }
    }
    LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(Tiempo);
  	for(inicio=0;inicio <8;inicio++){
      if(inicio==0 || inicio ==1||inicio==4||inicio==5){
      	luces[inicio]=B11011011;
      }
      else if(inicio==2||inicio==3||inicio==6||inicio==7){
      	luces[inicio]=B01101101;
      }
    }
    LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(Tiempo);
  	for(inicio=0;inicio <8;inicio++){
      if(inicio==0 || inicio ==7){
      	luces[inicio]=B11110000;
      }
      else if(inicio==1||inicio==6){
      	luces[inicio]=B01111000;
      }
      else if(inicio==2||inicio==5){
      	luces[inicio]=B00111100;
      }
      else if(inicio==3||inicio==4){
      	luces[inicio]=B00011110;
      }
    }      
    LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(Tiempo);
  }
  
void imagen(int Cantidad, int Tiempo){
  inicio=0;
    while(inicio<8){
      if(Serial.available()){
      f1=Serial.parseInt();
    luces[inicio]=f1;
	inicio++;
    }
      LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(TIEMPO);
    }
  inicio2=1;
  apagado=B00000000;
  while(inicio2<=Cantidad){
    LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(Tiempo);
    for(inicio3=0; inicio3 <8;inicio3++){
      guardar[inicio3]=luces[inicio3];
    	luces[inicio3]=apagado;
    }
	LedWrite(luces[0],luces[1],luces[2],luces[3],luces[4],luces[5],luces[6], luces[7]);delay(Tiempo);
	for(inicio3=0; inicio3 <8;inicio3++){
      luces[inicio3]=guardar[inicio3];
    }
    inicio2++;
  }
}
void publik()
{
  while(Serial.available()){
  Serial.println("Que desea hacer? ");
  Serial.println("Verificar: (1)");
  Serial.println("Imagen de prueba: (2)");
  Serial.println("Mostrar patrones: (3)");
  opcion=Serial.parseInt();
    if(opcion==1){
      Serial.println("Escriba la cantidad de secuencias deseadas: ");
     while(Serial.available()==0){
      }
      Cantidad=Serial.parseInt();
      Serial.println("Escriba el tiempo");
    while(Serial.available()==0){}
	Tiempo=Serial.parseInt();
    verificar(Cantidad, Tiempo);
    }
    else if(opcion==2){
      Serial.println("Escriba la cantidad de secuencias deseadas: ");
     while(Serial.available()==0){}
      Cantidad=Serial.parseInt();
      Serial.println("Escriba el tiempo");
    while(Serial.available()==0){}
	Tiempo=Serial.parseInt();
    imagen(Cantidad, Tiempo);
    }
    else if(opcion==3){
      Serial.println("Escriba el tiempo");
    while(Serial.available()==0){}
	Tiempo=Serial.parseInt();
    patrones(Tiempo);
    } 	
	}
}
  void loop(){
    publik();
  }