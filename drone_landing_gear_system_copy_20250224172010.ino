#include <Servo.h>

Servo landingServos[4];
const int trigPin = 9;
const int echoPin = 10;
const int servoPins[4] = {3, 5, 6, 7}; // Pins for four servo motors

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    for (int i = 0; i < 4; i++) {
        landingServos[i].attach(servoPins[i]);
    }
    Serial.begin(9600);
}

void loop() {
    long duration;
    int distance;
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 50) {
        for (int i = 0; i < 4; i++) {
            landingServos[i].write(90);  // Deploy landing gear
        }
    } else {
        for (int i = 0; i < 4; i++) {
            landingServos[i].write(0);   // Retract landing gear
        }
    }
    delay(500);
}
