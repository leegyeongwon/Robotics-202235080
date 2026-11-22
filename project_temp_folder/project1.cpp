/*
 * Back  :    0°
 * Left  :   90°
 * Front :  180°
 * Right :  270°
*/

/*
 * Byte 0       : Header (0x54)
 * Byte 1       : VerLen (0x2C)
 * Byte 2~3     : 회전 속도
 * Byte 4~5     : 시작 각도
 * Byte 6~41    : 거리 측정값 12개
 *                각 측정점 = 3 byte
 *                distance 2 byte + confidence 1 byte
 * Byte 42~43   : 끝 각도
 * Byte 44~45   : timestamp
 * Byte 46      : CRC
*/

// LIDAR RX
#define LIDAR_RX 16

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

void goFront() {
    digitalWrite(motorPins[0], HIGH);
    digitalWrite(motorPins[1], LOW);

    digitalWrite(motorPins[2], HIGH);
    digitalWrite(motorPins[3], LOW);

    digitalWrite(motorPins[4], HIGH);
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
  goFront();
}