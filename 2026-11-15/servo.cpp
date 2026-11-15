#include <ESP32Servo.h>
Servo myServo;


void setup() {
    myServo.attach(SERVO_PIN);
    myServo.write(0);
}

void loop() {
  for(int angle=0; angle <= 180; angle = angle + 5) {
    myServo.write(angle);
    delay(100);
  }
}