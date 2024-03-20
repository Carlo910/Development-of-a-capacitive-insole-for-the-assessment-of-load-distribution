#include <CapacitiveSensor.h>
#include <SoftwareSerial.h>
SoftwareSerial SerialM(0, 1); // RX | TX

#define R 13
#define Y 12

CapacitiveSensor cs1 = CapacitiveSensor(11,4); //1=avampiede
CapacitiveSensor cs2 = CapacitiveSensor(11,8); //2=retropiede

void setup() {
  Serial.begin(9600);
  SerialM.begin(9600);
}

void loop() {
  //legge e stampa valore sensore
  long out1 = cs1.capacitiveSensor(30);
  //Serial.print("A= ");
  //Serial.println(out1);
  long out2 = cs2.capacitiveSensor(30);
  //Serial.print("R= ");
  //Serial.println(out2);
   int lout1 = map(out1, 0, 600,0, 255);
   int lout2 = map(out2, 0, 600,0, 255);
   String data =  String(out1) + "," + String(out2) + ",\n";
   //Serial.print(data);
  SerialM.write(lout1);
  SerialM.write(lout2);
  
  
  delay(99);
}
