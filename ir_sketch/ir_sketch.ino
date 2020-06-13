int count;

const int sensor_analog_pin = A0;
const int sensor_digital_pin = 11;
int sensor_state;


void setup() {
    Serial.begin (9600);
    pinMode (sensor_digital_pin, INPUT); //Sensor output
}

void loop() {
    Serial.print ("Sensor: ");
    //Serial.println (digitalRead(9)); //print the sensor output
    //sensor_state = analogRead(sensor_pin);
    sensor_state = digitalRead(sensor_digital_pin);
    
    Serial.println(sensor_state);

    delay (500); //wait half a second
}
