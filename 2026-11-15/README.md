# 2026-11-15
## This folder Include
- button_arduino.cpp
- button_arduino.png
<br>  

- button_LED_arduino.cpp
- button_LED_arduino.png
<br>

- potentiometer_LED.cpp
- potentiometer_LED.cpp
<br>

- buzzer.cpp
- mapping_pat.cpp
- servo.cpp

## Description
### button_arduino  
Example code that prints "Pressed" to the terminal window when a button is pressed, and "Not pressed" when it is released.  
Use pin 2 for a button.  
115200 Baud rate.  

### button_LED_arduino
Example code where the LED turns on when the button is pressed and turns off when the button is released.  
Use pin 2 for a button and pin 7 for LED.  

### potentiometer_LED
Example code for controlling an LED using a variable resistor.  
As the resistance of the variable resistor increases, the LED brightness increases; as the resistance decreases, the brightness decreases.  
Use pin A2 for potentiometer and pin 9 for a LED.  

### buzzer.cpp
Example code that makes the buzzer sound 3 times.  
Use pin 5 for buzzer.  
Buzzer frequency 2000 and resolution 8.  

### mapping_pat.cpp
Example code for measuring the resistance of a Potentiometer.  
Use pin A2 for potentiometer and pin 9 for a LED.  

### servo.cpp  
Example Code to make a servo motor rotate smoothly.  
Use ESP32Servo board and <ESP32Serbo.h> library.  

## How to execute
## For button_arduino.cpp, button_LED_arduino.cpp, potentiometer_LED.cpp
1. Go to Tinkeracd: https://www.tinkercad.com/dashboard
2. Make a curcuit like each png file.
3. Copy and paste c++ code which has same name for each png file.
4. Execute simulation

## How to Execute(For buzzer.cpp)

### 1. Hardware Requirements & Wiring
* **Board:** ESP32 Development Board
* **Component:** Buzzer

### 2. Upload & Run (Arduino IDE)
1. **Wiring:** Connect the buzzer to the board (`+` to **pin 5**, `-` to **GND**).
2. **Upload:** Assemble the circuit, paste the code into the **Arduino IDE**, compile it, and upload (`→`) it to the board.

## How to Execute (For potentiometer.cpp)

### 1. Hardware Requirements & Wiring
* **Board:** ESP32 Development Board
* **Components:** Potentiometer, LED

### 2. Upload & Run (Arduino IDE)
1. **Wiring:** 
   * Connect the **Potentiometer** to the board (Outer pins to **3.3V** and **GND**).
   * Connect the **LED** to the board (`+` to **Pin 9**, `-` to **GND**).
2. **Upload:** Assemble the circuit, paste the code into the **Arduino IDE**, compile it, and upload (`→`) it to the board.

## How to Execute (For servo.cpp)

### 1. Hardware Requirements & Wiring
* **Board:** ESP32 Development Board
* **Component:** Servo Motor
* **Library:** `ESP32Servo` (Install via Arduino IDE Library Manager)

### 2. Upload & Run (Arduino IDE)
1. **Wiring:** Connect the **Servo Motor** to the board (Signal to **SERVO_PIN**, VCC to **5V** or **3.3V**, GND to **GND**).
2. **Upload:** Assemble the circuit, paste the code into the **Arduino IDE**, compile it, and upload (`→`) it to the board.

