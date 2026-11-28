// Front Right
#define FR_IN1 26
#define FR_IN2 25

// Front Left
#define FL_IN1 19
#define FL_IN2 27

// Rear Right
#define RR_IN1 23
#define RR_IN2 12

// Rear Left
#define RL_IN1 0
#define RL_IN2 15

// front, back repeat
int motorPins[8] = {
    FR_IN1, FR_IN2,
    FL_IN1, FL_IN2,
    RR_IN1, RR_IN2,
    RL_IN1, RL_IN2
};

void goRight() {
    digitalWrite(motorPins[0], LOW);
    digitalWrite(motorPins[1], LOW);

    digitalWrite(motorPins[2], HIGH);
    digitalWrite(motorPins[3], LOW);

    digitalWrite(motorPins[4], LOW);
    digitalWrite(motorPins[5], LOW);

    digitalWrite(motorPins[6], HIGH);
    digitalWrite(motorPins[7], LOW);
}

void setup() {
    Serial.begin(115200);

    for (int i = 0; i < 8; i++) {
        pinMode(motorPins[i], OUTPUT);
        digitalWrite(motorPins[i], LOW);
    }
}

void loop() {
  goRight();
}