#include <math.h>

int count;

// sensors
const int sensorLeftPin = 10;
const int sensorRightPin = 11;

int sensorLeftState;
int sensorRightState;

// motors
const int motorLeftPin1 = 7;
const int motorLeftPin2 = 6;
const int motorRightPin1 = 9;
const int motorRightPin2 = 8;

const int motorMaxSpeed = 130;
const int motorMinSpeed = 80;
const int motorLinearRate = 1;
const int motorTurnRate = 1;

int motorLeftSpeed = 100;
int motorRightSpeed = 100;

// robot global
int robotActive = 0;


void setup() {
    Serial.begin (9600);

    // set pins sensors
    pinMode (sensorLeftPin, INPUT); //Sensor output
    pinMode (sensorRightPin, INPUT); //Sensor output

    // set pins motors
    pinMode(motorLeftPin1, OUTPUT);
    pinMode(motorLeftPin2, OUTPUT);
    pinMode(motorRightPin1, OUTPUT);
    pinMode(motorRightPin2, OUTPUT);

    // set initial speeds to zero
    analogWrite(motorLeftPin1, 0);
    analogWrite(motorLeftPin2, 0);
    analogWrite(motorRightPin1, 0);
    analogWrite(motorRightPin2, 0);
}

void loop() {
  
    //Read and print sensor states
    sensorLeftState = digitalRead(sensorLeftPin);
    sensorRightState = digitalRead(sensorRightPin);

    if(sensorLeftState == 1 && sensorRightState == 1){
      robotSwitchState(0);
    }
    else if(sensorLeftState == 0 && sensorRightState == 0){
      robotSwitchState(1);
      robotAccelerate();
    } 
    else if(sensorLeftState == 1){
      robotSwitchState(1);
      robotTurnLeft();
    } 
    else if(sensorRightState == 1){
      robotSwitchState(1);
      robotTurnRight();
    } 

    Serial.print ("sensor left: ");
    Serial.print(sensorLeftState);
    Serial.print ("  sensor right: ");
    Serial.print(sensorRightState);
    Serial.print ("  motor speed left: ");
    Serial.print(motorLeftSpeed);
    Serial.print ("  motor speed right: ");
    Serial.println(motorRightSpeed);

    delay (1000); //wait half a second
}

// function to turn robot to the left
void robotTurnLeft(){
  motorLeftSpeed = max(motorLeftSpeed - motorTurnRate, motorMinSpeed);
  motorRightSpeed = min(motorRightSpeed + motorTurnRate,motorMaxSpeed);

  robotSetSpeeds(motorLeftSpeed, motorRightSpeed);
}

// function to turn robot to the left
void robotTurnRight(){
  motorLeftSpeed = min(motorLeftSpeed + motorTurnRate,motorMaxSpeed);
  motorRightSpeed = max(motorRightSpeed - motorTurnRate, motorMinSpeed);

  robotSetSpeeds(motorLeftSpeed, motorRightSpeed);
}

// function to accelerate robot
void robotAccelerate(){
  motorLeftSpeed = min(motorLeftSpeed + motorLinearRate,motorMaxSpeed);
  motorRightSpeed = min(motorRightSpeed + motorLinearRate,motorMaxSpeed);

  robotSetSpeeds(motorLeftSpeed, motorRightSpeed);
}

// function to switch robots active state
void robotSwitchState(int state){
  if(state == 1){
    robotActive = 1;
  } else {
    robotActive = 0;

    motorLeftSpeed = 100;
    motorRightSpeed = 100;
    robotSetSpeeds(motorLeftSpeed, motorRightSpeed);
  }
}

// function to Decelerate robot
void robotDecelerate(){
  motorLeftSpeed = max(motorLeftSpeed - motorLinearRate, motorMinSpeed);
  motorRightSpeed = max(motorRightSpeed - motorLinearRate, motorMinSpeed);

  robotSetSpeeds(motorLeftSpeed, motorRightSpeed);
}

// set motor speed
void robotSetSpeeds(int leftSpeed, int rightSpeed){
  analogWrite(motorLeftPin1, leftSpeed);
  analogWrite(motorRightPin1, 1.03*rightSpeed);
}
