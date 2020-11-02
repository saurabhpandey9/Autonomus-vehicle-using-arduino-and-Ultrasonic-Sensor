//Author: SAURABH PANDEY


#include<AFMotor.h>
AF_DCMotor motor2(2); //for HW-130 motor driver
AF_DCMotor motor3(3);

#define echoPin 11 //ultrasonic sensror echo pin (11)
#define trigPin 10 //ultrasonic sensror trig pin (10)

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  motor2.setSpeed(255);
  motor3.setSpeed(238);
  Serial.begin(9600); 
}

void right(){
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(1000);
    motor2.run(FORWARD);
    delay(700);
    motor2.run(RELEASE);
    motor2.run(RELEASE);
    delay(1000);
  
}

void back(){
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(1000);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    delay(500);
    motor2.run(RELEASE);
    motor2.run(RELEASE);
    delay(400);
    right();
  
}




void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.println(distance);

  if (distance < 25){
   right();
  }
  else if(distance > 1500){
    back();
  }
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  delay(1000);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(100);
 
}
