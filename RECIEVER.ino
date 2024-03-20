#include <SoftwareSerial.h>
#include <CapacitiveSensor.h>
SoftwareSerial SerialM(2, 3); // RX | TX


float val;
float val2;
int R=0;
void setup() {
  
  Serial.begin(9600);
  SerialM.begin(9600);
  
}
 
void loop() {

  if (SerialM.available()>0)

{
  if(R==0)
  {
val = SerialM.read();
val = map(val, 0, 255, 0, 1000);
val = val/5;
val = val/16; //tau in microseconds
val = val*1000;

R=1;
  }
  else{
    val2 = SerialM.read();
    val2 = map(val2, 0, 255, 0, 1000);
    val2 = val2/5;
    val2 = val2/16; //tau in microseconds
    val2 = val2*1000; 
   
   R=0;
  }

  String data=String(val)+","+String(val2)+",\n";
  Serial.print(data);

}
}
