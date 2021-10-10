#include <ThingSpeak.h>


#include <Servo.h>
Servo servos; 


//const int led1 = 4;
//const int led2 = 0;
//const int led3 = 2;

const int sensor = 14;
int nilai;

void setup() {
  Serial.begin(115200);
  servos.attach(13);
  pinMode(sensor, INPUT);
}

void loop() {
  nilai = digitalRead(sensor);
  Serial.println(nilai);
  if (nilai == 1){
    servos.write(90);
   } else {
     servos.write(0);
   }
}
