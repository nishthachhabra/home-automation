//temperature and humidity sensor
#include "DHT.h"
#define dht_apin A0 // Analog Pin sensor is connected to
dht DHT;

void setup() {
  // put your setup code here, to run once:
  
  //ultrasonic sensor 
  pinMode(0, INPUT);

  //flame sensor
  pinMode(4, INPUT);

  //gas sensor
  pinMode(5, INPUT);
  
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //ultrasonic sensor
  Serial.println(digitalRead(0));
  if(digitalRead(0)==1){
    //call intermediate code
    }

  //flame sensor
  Serial.println(digitalRead(4));
  if(digitalRead(4)==1){
    //call intermediate code
    }

  //gas sensor
  Serial.println(digitalRead(5));
  if(digitalRead(5)==1){
    //call intermediate code
    }

  //temperature and humidity sensor
  DHT.read11(dht_apin);
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature); 
  Serial.println("C  ");

  delay(100);

}
