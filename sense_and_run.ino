  /*

Satelite Orbitz
Sensor: fairchild qrb1134, NPN phtotransistor
  led metrics: 1.2v FV and 20ma. 150ohm resistor 

*/


#include "Timer.h"  //used 4/18/2014 on home computer: https://github.com/JChristensen/Timer


Timer t;

const int leds = 3;
const int motor = 10;
const int sensor = 6;

int counter = 0;
int sensorState = 1;
long startSensing = 0;
long triggerTime = 0;
int sensorMinThreshold = 3;
long sensorMaxThreshold = 30;

int onTime = 180; // 180 seconds is 3  minutes




////------------------------------------------------SETUP
void setup() {
  //start serial
  Serial.begin(9600);

  pinMode(leds, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(sensor, INPUT);
  digitalWrite(motor, LOW); //initialize off
  digitalWrite(leds, LOW); //initialize off
  digitalWrite(sensor, HIGH);  //turn on internal pullup resistor NPN 

  t.every(1000, moveCounter);  //this moves the countdown timer forward

}
//------------------------------------------------end setup





////------------------------------------------------------------------------------------------start main loop
void loop() {

  long now = millis();

  sensorState = digitalRead(sensor);

  if(sensorState == LOW && startSensing == 0){
    //Serial.println("low");
    startSensing = now;
  }

  if(sensorState == HIGH && startSensing > 0){
    triggerTime = now - startSensing;
    if(triggerTime > sensorMinThreshold && triggerTime < sensorMaxThreshold){
      counter = onTime;
      digitalWrite(motor, HIGH);
      digitalWrite(leds, HIGH);
    }
    startSensing = 0;
  }
  
  t.update();
  


}
//------------------------------------------------end main loop






void moveCounter()  //this is the coundown timer function
{
 
  if(counter > 0){
    
    Serial.println("game on, counting down");
    Serial.print("counter: ");
    Serial.println(counter);
    
    
    counter--;
  
    if(counter == 0){  //games over... game lost due to expire of points 
      //counter = 1;   //keeps from looping more than once
      digitalWrite(motor, LOW);
      digitalWrite(leds, LOW);
      }
  }
}



