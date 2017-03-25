#include "math.h"

int rd = 0;

const int ledPin = 3;
const int speakPin = 2;
const int trigPin = 13;
const int echoPin = 12;
const int lightPin = A0;


void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(lightPin, INPUT);

    Serial.begin(9600);
    Serial.println("Echo v2");
}


void loop() {
        long duration, distance, light, length;

        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);
        distance = (duration/2) / 29.1;

        light = analogRead(lightPin);

        Serial.print("Light: ");
        Serial.println(light);

        length = map(light, 950, 1050, 0, 100);

        if (distance >= 200 || distance <= 10){
            Serial.println("Out of range");
            digitalWrite(speakPin, LOW);
        }
        else {
            tone(speakPin, map(distance, 10, 200, 50, 4000), length);
            Serial.print(distance);
            Serial.println(" cm");
        }
        delay(map(light, 950, 1000, 0, length));
    }