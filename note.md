## 1. embedded based low-level control 
ROBOT system
high level: SBC/ROS2  ->  many calculation
low level: MCU/RTOS  ->  manipulate like motors and joints

Each function has different control cycle
So, In robot system, typically we split roles in high/low level

**High level**: SLAM(perception of env), camera, LIDAR, Path Planning, Navigation, ROS2, many memory needed. 

**Low level**: motor PWM, Encoder data processsing, PID, CPIO, UART, etc hardware control, **Short and periodic control execution**

MCU has many units include CPU, Memory, Peripheral. SOC maybe? 

V=IR 

floating: button push -> jittering voltage
pull down register: standard -> low, pushed -> high
pull up register: standard -> high, pushed -> low

serial: 직렬 통신
baud rate: bit/s
ex) Serial.begin(115200)

voltage bouncing
PWM: Pulse Width Modulator. Use duty cycle
IMU(Inertial Measurement Unit): gyro, accelameter

2 way for embedded communication protocol. IMU --[inertia]--> MCU
1. synchronous: There is a clock in MCU. make frequency. If you want to communicate with IMU, both of them will synchronize the frequency. ex) baud rate 115200 bit/s.
2. asynchronous: Just give data to MCU and MCU store it in buffer. MCU can use data when it need data. buffer management is needed.

UART(Universal Asynchronous Receiver/Transmitter): use async. simple method which is used to test.
TX (transmitter) <--> RX (receiver) Our LIADR use this way.

Send LSB(Least Significant Bit) first
              (databyte)
(start bit) + 101010101 + (stop bit)


I2C(Inter-Intergrated Circuit): Use two signal lines - SDA(Serial Data), SCL(Serial Clock). Synchronous. No need more SCA/SCL than one for MCU.
master: MCU, slave: sensors
Each slave has a unique addresss. Using that, slave and master can communicate with each other.

Start Condition: Start communication when SDA voltage is reduced. Clock(SDL) High and data(SDA) Low. 
ACK or NACK for slaves publish when master(MCU) call particular sensors(slaves). Similar with internet protocol.

SCldl dhffkrks ehddks epdlxjfmf dlfrrh shvdms wjsdkqdl dbwlehlsms ehddksdp rPthr dlfrsms tkdxofmf dbwlgksek(ko)


## 2. ROS2 basic my_domain: "14"
Robot OS. Not a OS for real. It is framework but similar with OS. 
each process is processed in seperated memory .
Support to interact between processes.

Standard Communication Protocol. Unites communication protocol strictly.
Almost functions needed in robots are existing in packages.
RViz, Gazebo etc...


There is "node" in ros2. Think it is one process = one terminal = one robot. Caution, not a perfect description.
A part publish a Topic and other parts subscribe that topic. Then, subscriber can get messages from publisher. 
A topic need to be named.
We can group topics with '/'
Message has a type. message_type. ex) int, float, pose, etc...
pose message_type includes many message_type like pose.position.x

service
action

vizualization command: rqt_graph

DDS
QoS(Quality of Service) - !IMPORTANT!
- Reliability
  - Best effort
  - Reliable
- Durability
  - Volatile
  - Transient Local
  
  
colcon Workspace:
ros2's folder for develop and management

src/ : ros2 packages's source code(developer wrote)
build/ : zjavkdlf alc qlfem rhkwjddptj todtjdehlsms wndrksvkdlf
install/: qlfem alc tjfclehls tlfgod vkdlf, fkdlqmfjfl, tjfwjd vkdlf emd
log/: qlfem alc xptmxm?

colcon: build tool
- CLI
- Workspace auto search
- analyze dependencies
- build pakages that developer want.

## 3. SLAM, Simulation 

## 4. RTOS based high-low level peristalsis
