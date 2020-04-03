/*
* Code based on the Ultrasonic Sensor HC-SR04 and Arduino Tutorial by Dejan Nedelkovski www.HowToMechatronics.com
*/
// Defines ultrasonic sensor pins numbers
const int trigPin = 9;
const int echoPin = 10;
// Defines leds pins numbers
const int redPin = 7;
const int orangePin =  12;
const int greenPin = 13;
// Define levels for the ultrasonic sensor
int levels [3] = {25,60,100};
// Defines variables for calculate the distance
long duration;
int distance;

void setup() { 
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
// Adding the pins for the leds (red, orange and green)
pinMode(redPin, OUTPUT);
pinMode(orangePin, OUTPUT);
pinMode(greenPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor and active a led
if(distance<levels[0]){
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
// Active red led
  digitalWrite(redPin, HIGH);
  digitalWrite(orangePin, LOW);
  digitalWrite(greenPin, LOW);
} else if(distance<levels[1]){
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
// Active orange led
  digitalWrite(redPin, LOW);    
  digitalWrite(orangePin, HIGH);
  digitalWrite(greenPin, LOW);
  }else if(distance>=levels[1]&distance<levels[2]){
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
// Active green led    
    digitalWrite(redPin, LOW);
    digitalWrite(orangePin, LOW);
    digitalWrite(greenPin, HIGH);
    } else{
        digitalWrite(redPin, LOW);
       digitalWrite(orangePin, LOW);
       digitalWrite(greenPin, LOW);
      }
}
