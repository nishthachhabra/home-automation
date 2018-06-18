//ultrasonic sensor
const int trigPin=2;
const int echoPin=4;
long duration;
int distance;

//flame sensor
const int flamePin=12;

//gas sensor
const int smokeA0=A0;
int sensorThresh=250;

void setup() {
  // put your setup code here, to run once:
  //ultrasonic sensor
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(7,OUTPUT);//0/1

  //flame sensor
  pinMode(flamePin,INPUT);
  pinMode(8,OUTPUT);//0/1

  //gas sensor
  pinMode(smokeA0,INPUT);
  pinMode(13,OUTPUT);//0/1
  
  Serial.begin(115200); // Starts the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  //ultrasonic sensor
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration/58.2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<20)
  {
    digitalWrite(7,HIGH);//1
    Serial.println("Security Breach!!");
    }
  else
  {
    digitalWrite(7,LOW);//0
    }  

  //flame sensor  
  Serial.println(digitalRead(flamePin));
  if (digitalRead(flamePin)==1)
  {
    Serial.println("Fire Detected");
    digitalWrite(8,HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
    Serial.println("No Fire!!");
  }

  //gas sensor
  int analogSensor=analogRead(smokeA0);
  if(analogSensor>sensorThresh&&analogSensor<400){
    digitalWrite(13,HIGH);
    Serial.println(analogSensor);
    Serial.println("Gas leakage detected");
    }
  else{
    digitalWrite(13,LOW);
    Serial.println(analogSensor);
    Serial.println("Clean!!");
    }
  
  delay(100);
}
