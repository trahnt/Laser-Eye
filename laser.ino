#include<Servo.h>

Servo serX;
Servo serY;
//Servo trig;
int xServoPin = 10;
int yServoPin = 11;
//int triggerPin = 9;
int laserPin = 8;
bool laserState = false;
String serialData;

void setup() {
  // put your setup code here, to run once:
//  pinMode(laserPin, OUTPUT);
//  trig.attach(triggerPin);
  serX.attach(xServoPin);
  serY.attach(yServoPin);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop(){
  while (!Serial.available()){}
  serialData = Serial.readString();
  if (serialData[0] == 'X'){
    serX.write(180 - parseDataX(serialData));
    serY.write(parseDataY(serialData));
//    delay(500);
//    trig.write(50);
//    delay(1000);
//    trig.write(90);
    }
//  else{
//    
//    if (laserState){
//      digitalWrite(laserPin, LOW);
//      laserState = false;}
//    else{digitalWrite(laserPin, HIGH);
//      laserState = true;}
//}
}

int parseDataX(String data){
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);
  return data.toInt();
}

int parseDataY(String data){
  data.remove(0, data.indexOf("Y") + 1);
  return data.toInt();
}
