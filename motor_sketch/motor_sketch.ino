

//Motor 1
const int motorPin1 = 9;
const int motorPin2 = 8;
//Motor 2
const int motorPin3 = 7;
const int motorPin4 = 6;

int count = 0;

int speed = 200;
void setup(){
    Serial.begin (9600);
  
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

    //Motor Control A in both directions
    // forward
    //Serial.println("Left forwards");
    //analogWrite(motorPin1, speed);
    //delay(2000);
    //analogWrite(motorPin1, 0);
    //delay(200);
    // backwards
    //Serial.println("Left backwards");
    //analogWrite(motorPin2, speed);
    //delay(2000);
    //analogWrite(motorPin2, 0);
    
    //Motor Control B in both directions
    // forwards
    //Serial.println("Right forwards");
    //analogWrite(motorPin3, speed);
    //delay(2000);
    //analogWrite(motorPin3, 0);
    //delay(200);

    // backwards
    //Serial.println("Right backwards");
    //analogWrite(motorPin4, speed);
    //delay(2000);
    //analogWrite(motorPin4, 0);


}

void loop(){
    Serial.println("Hello Arduino");
    delay(50);
    if(count <= 2){
     // left forward
    analogWrite(motorPin1, speed);
    // right forward
    analogWrite(motorPin4, speed);
    } else {
           // left forward
    analogWrite(motorPin1, 0);
    // right forward
    analogWrite(motorPin4, 0);
    }

    count++;
    if (count == 5){
      count = 0;
    }

}
