// 현재까지 구현한 것: 앞으로 간다 -> 만약 5cm앞에 장애물 있으면 0.5초동안 멈춤 -> 뒤로 1초 -> 다시 앞으로

// Motors pin
#define FR_IN1 26
#define FR_IN2 25
#define FL_IN1 19
#define FL_IN2 27
#define RR_IN1 23
#define RR_IN2 12
#define RL_IN1 0
#define RL_IN2 15


// LIDAR RX
#define LIDAR_RX 16
// Obstacle is near -> return true or false
#define OBSTACLE_LIMIT_MM 50

uint8_t packet[47];
uint16_t distances[360] = {0};

float previousAngle = -1.0;

// LiDAR가 low byte, high byte 순서로 보낸 2바이트를 하나의 16비트 정수로 합친다
uint16_t readUInt16(uint8_t low, uint8_t high) {
    return low | (high << 8);
}

// 모터 초기화
int motorPins[8] = {
    FR_IN1, FR_IN2,
    FL_IN1, FL_IN2,
    RR_IN1, RR_IN2,
    RL_IN1, RL_IN2
};

// 주행 상태 관리
enum DriveState {
    STATE_GO_FRONT,
    STATE_GO_BACK,
    STATE_GO_RIGHT,
    STATE_GO_LEFT,
    STATE_STOP
};
DriveState currentState = STATE_GO_FRONT;

// LIDAR: 0~359도에 저장된 거리값을 모두 출력한다
void printAllDistances() {
    for (int degree = 0; degree < 360; degree++) {
        Serial.print(degree);
        Serial.print(" deg : ");
        Serial.print(distances[degree]);
        Serial.println(" mm");
    }

    Serial.println("----------------");
}

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

void goBack() {
    digitalWrite(motorPins[0], LOW);
    digitalWrite(motorPins[1], HIGH);

    digitalWrite(motorPins[2], LOW);
    digitalWrite(motorPins[3], HGIH);

    digitalWrite(motorPins[4], LOW);
    digitalWrite(motorPins[5], HGIH);

    digitalWrite(motorPins[6], LOW);
    digitalWrite(motorPins[7], HGIH);
}

void goRight() {
    // TODO
}

void goLeft() {
    // TODO
}

void stopMotor() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(motorPins[i], LOW);
    }
}

void checkLidar() {
    if (!Serial2.available()) {
        return;
    }

    // packet의 첫 byte는 항상 0x54
    if (Serial2.read() != 0x54) {
        return;
    }

    // 두 번째 byte가 들어올 때까지 기다린다
    while (!Serial2.available()) {
    }

    // 두 번째 byte가 0x2C인지 확인
    if (Serial2.read() != 0x2C) {
        return;
    }

    packet[0] = 0x54;
    packet[1] = 0x2C;

    // header 2바이트를 제외한 나머지 packet 데이터를 읽는다
    for (int i = 2; i < 47; i++) {
        while (!Serial2.available()) {
        }

        packet[i] = Serial2.read();
    }

    // 시작 각도와 끝 각도는 각각 2바이트
    uint16_t startRaw = readUInt16(packet[4], packet[5]);
    uint16_t endRaw = readUInt16(packet[42], packet[43]);

    // 각도값은 0.01도 단위로 들어오므로 100으로 나눈다
    float startAngle = startRaw / 100.0;
    float endAngle = endRaw / 100.0;

    if (endAngle < startAngle) {
        endAngle += 360.0;
    }

    // 한 packet에는 12개 측정점이 있으므로 시작점과 끝점 사이를 11구간으로 나눈다
    float angleStep = (endAngle - startAngle) / 11.0;

    for (int i = 0; i < 12; i++) {
        // 각 측정점은 distance 2바이트 + confidence 1바이트로 구성
        int index = 6 + i * 3;

        // 거리값 2바이트를 mm 단위 정수로 변환
        uint16_t distance = readUInt16(packet[index], packet[index + 1]);

        // 현재 측정점이 어느 각도에 해당하는지 계산
        float angle = startAngle + angleStep * i;

        if (angle >= 360.0) {
            angle -= 360.0;
        }

        // 360도에서 0도로 넘어오면 한 바퀴 완료로 보고 전체 거리값 출력
        if (previousAngle > 300.0 && angle < 60.0) {
            printAllDistances();
        }

        // float 각도를 가장 가까운 정수 각도로 반올림
        int degree = (int)(angle + 0.5);

        if (degree >= 360) {
            degree = 0;
        }

        // 0은 유효하지 않은 거리값으로 보고 저장하지 않는다
        if (distance > 0) {
            distances[degree] = distance;
        }

        previousAngle = angle;
    }
}


/*
 * Back  :    0°
 * Left  :   90°
 * Front :  180°
 * Right :  270°
*/

// 전방 60도를 검토
bool isObstacleDetected(int angleFrom, int angleTo) {
    for (int deg = angleFrom; deg <= angleTo; deg++) {
        if (distances[deg] > 0 && distances[deg] < OBSTACLE_LIMIT_MM) {
            return true;
        }
    }
    return false;
}






void setup() {
    Serial.begin(115200);  // 시리얼 모니터
    Serial2.begin(230400, SERIAL_8N1, LIDAR_RX, -1);  // LiDAR -> RX 시리얼 통신 (TX 사용안함)

    for (int i = 0; i < 8; i++) {
        pinMode(motorPins[i], OUTPUT);
        digitalWrite(motorPins[i], LOW);
    }

    // 거리 배열을 큰 값으로 초기화 (초기 오작동 방지)
    for (int i = 0; i < 360; i++) {
        distances[i] = 10000;
    }
}

void loop() {
    // 매 루프마다 라이다 데이터 최신화
    checkLidar();

    // 상태에 따른 주행 
    switch (currentState) {
        case STATE_GO_FRONT:
            goFront();
            if (isObstacleDetected(150, 210)) {
                Serial.println("장애물 감지: 정지");
                stopMotor();
                currentState = STATE_STOP;
            }
            break;

        case STATE_STOP:
            stopMotor();
            // 0.5초(500ms) 동안 완전히 멈춘 뒤 후진으로 전환
            delay(500);
            Serial.println("후진");
            currentState = STATE_BACK;
            stateStartTime = millis();
            break;

        case STATE_GO_BACK:
            goBack();
            // 1초(1000ms) 동안 후진한 뒤 다시 전진 상태로 복귀
            delay(1000);
            Serial.println("전진");
            // 거리 초기화
            for (int deg = 1; deg <= 360; deg++) {
                distances[deg] = 9999;
            }
            currentState = STATE_FRONT;
            break;
    }
}