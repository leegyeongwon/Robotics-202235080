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
GNSS: Similar with GPS. but cannot use indoor
Wheel Encoder: Get data about how much that wheel has spun around. Its important but error is occur when wheel is sliped.
LIDAR: Detect distances based with laser. 360 degrees

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
QoS(Quality of Service) - !IMPORTANT!  communication protocol (node <---> node)
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

Launch File: Make ros2 run ... -> execute by one click or command.
my_location.launch.py, setup.py  Its almost python code/file.

Service: Request and Response.
It is Composed 'Client-Server' structure. For One-time request and short management
use .srv file
ex) what is A-module's sensor value

Action: Client-server structure and Goat-Feedback-Result
ex) Go to that location(Give sensors value or Feedback, etc to server continuously).

Custom Interface: Define Data Structure in person. 


HIGH level: cognition, planning, control (PPA)
get data + analysis, target/path planning, pose conrtol

Cognition: Get data from sensors + "position of the robot inself" and environments around
Planning: Edit planning on time
Action: Do action

AMR: Autonomous Mobile Robot is what we will do. 


Reference commands: 
```bash
ros2 launch turtlebot3_gazebo turtlebot3_dqn_stage1.launch.py
ros2 topic pub /cmd_vel geometry_msgs/msg/TwistStamped "{twist: {angular: {z: 1.0}}}"
ros2 run turtlebot3_teleop teleop_keyboard
rviz2
```


/odom: topic contain how much I have gone far or spun

Quatanion -> w^2 + x^2 + y^2 + z^2 = 1

TF(transform) important
Parent Frame(rlwns whkvyrP) <---> Child Frame(qnah rlwns dnlcl/ghlwjs)

Static TF: fixed TF. low network usage
Dynamic TF: tlftlrks dnlcl cnwjr. tlrksdp Ekfk qusgksms dnlcl rhksrP. wlthrwjrdls epdlxj tmxmflald. rhwnvktnfh wlthrwjrdls epdlxjfmf qkfgodgkrh djqepdlxm

Broadcaster: whkvyrP wjdqh qkfgod. rkr fldzm rksdml tkdeowjr dnlclfmf tlftlrksdmfh qkdthd
ehdwjr/wjdwjr qusghks rhksfl: wjdwjr qusghks, ehdwjr qusghksdmf sksndj wjsthd

Listner: whkvyrP wjdqh tnwlq, whkvy qusghks rPtks

## 3. SLAM, Simulation 

## 4. RTOS based high-low level peristalsis
