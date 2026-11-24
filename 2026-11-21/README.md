# 2026-11-15

## Folder Contents
- `imu_test.ino`
- `lidar_test.ino`
- `motor_test.ino`
- `1_pubsub/`

```text
1_pubsub
├── 1_pubsub
│   ├── listener.py
│   └── talker.py
└── setup.py
```

## Description

### imu_test.ino
Example code to test the MPU6050 accelerometer and gyroscope via I2C.
* **SDA:** Pin 21
* **SCL:** Pin 22
* **I2C Address:** `0x68`

---

### lidar_test.ino
Example code to test the 360° LIDAR sensor.
* **LIDAR Pin:** Pin 16 (RX / Signal)

---

### motor_test.ino
Example code to test the motors in the sequence: FR, FL, RR, RL.
* **Front Right Wheel:** `[26, 25]` -> `[forward, backward]`
* **Front Left Wheel:** `[19, 27]` -> `[forward, backward]`
* **Rear Right Wheel:** `[23, 12]` -> `[forward, backward]`
* **Rear Left Wheel:** `[0, 15]` -> `[forward, backward]`

---

### 1_pubsub
Folder containing ROS 2 example code.
* **talker.py:** Publishes a topic containing the elapsed time since the node started.
* **listener.py:** Subscribes to and displays the timestamp information published by `talker.py`.
* **setup.py:** Package configuration file for building with `colcon`.

---

## How to Execute

### 1. `imu_test.ino`
**Hardware Requirements:**
* ESP32 Development Board
* MPU6050

**Steps (Arduino IDE):**
1. **Wiring:** Connect the MPU6050 to the ESP32 (Pin 21 for SDA, Pin 22 for SCL).
2. **Upload:** Paste the code into the **Arduino IDE**, compile, and upload (`→`) it to the board.

---

### 2. `lidar_test.ino`
**Hardware Requirements:**
* ESP32 Development Board
* LIDAR Sensor

**Steps (Arduino IDE):**
1. **Wiring:** Connect the LIDAR to the ESP32 (Pin 16).
2. **Upload:** Paste the code into the **Arduino IDE**, compile, and upload (`→`) it to the board.

---

### 3. `motor_test.ino`
**Hardware Requirements:**
* ESP32 Development Board
* 4 DC Motors (with motor driver)

**Steps (Arduino IDE):**
1. **Wiring:** Connect the 4 motors to the ESP32 according to the pinout in the Description.
2. **Upload:** Paste the code into the **Arduino IDE**, compile, and upload (`→`) it to the board.

---

### 4. `1_pubsub` (ROS 2)
Build the package in your ROS 2 workspace:
```bash
colcon build
source install/setup.bash
```

Run the publisher and subscriber in **two separate terminals**:
```bash
# Terminal 1
ros2 run 1_pubsub talker

# Terminal 2
ros2 run 1_pubsub listener
```
