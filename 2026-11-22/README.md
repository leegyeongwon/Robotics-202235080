# 2026-11-15

## Folder Contents
- `publisher.py`
- `processor.py`
- `subscriber.py`

- `2_srvmsg`  
```text
2_srvmsg
├── 2_srvmsg
│   ├── add_ints_client.py
│   ├── add_ints_server.py
│   ├── move_robot_client.py
│   └── move_robot_server.py
├── setup.cfg
└── setup.py
```  


- `custom_interfaces`
```text
custom_interfaces
├── msg
│   ├── Num.msg
│   └── RobotPose.msg
└── srv
    ├── AddTwoInts.srv
    └── MoveRobot.srv
```

## Description
### publisher.py (Code included in ../2026-11-21/1_pubsub/1_pubsub)
A Script that receives keyboard input and publishes the entered characters as a ROS2 topic.

---

### processor.py (Code included in ../2026-11-21/1_pubsub/1_pubsub)
A Script that receives a topic from `publisher.py` and processes current location.  
Initial positon: [0, 0]  
***W*** or ***w*** -> [0, 1]  
***A*** or ***a*** -> [-1, 0]  
***S*** or ***s*** -> [0, -1]  
***D*** or ***d*** -> [1, 0]  
Others are ignored.  
Publishes current location as a topic.  

---

### subscriber.py (Code included in ../2026-11-21/1_pubsub/1_pubsub)
A Script that receives a topic from `processor.py` and print current location to terminal.

---

### 2_srvmsg
A new package, distinct from the `1_pubsub`.  
Folder containing ROS2 example code.
* **add_ints_client.py:** Client for request service `/add_two_ints` (Num a, Num b).
* **add_ints_server.py:** A Server for if `/add_two_ints` service requested, Num a and Num b are come, return a + b as a response.
* **move_robot_client.py:** Client for request service `/move_robot` (RobotPose current_pose, float64 distance).
* **move_robot_server.py:** A Server for if `/move_robot` service requested, Current position, angle and distance are come, return next position and whether or not it is successful as a response. 

---

### custom_interfaces
A new package, distinct from the `1_pubsub` and `2_srvmsg`.  
Folder containing ROS2 custom interfaces example file.
* **AddTwoInts.srv:** Custom service includes variable type `Num a, Num b` for request and `Num sum` for response.
* **Num.msg:** Custom message include `int64 my_num`.
* **MoveRobot.srv:** Custom service includes variable type `RobotPose current_pose, float64 distance` for request and `RobotPose result_pose, bool success` for response.
* **RobotPose.msg:** Custom message include `float64 x, float64 y, float64 theta`.

---

## How to Execute

### 1. `publisher.py`, `processor.py`, `subscriber.py`
Build the package in your ROS2 workspace:  
```bash
colcon build
source install/setup.bash
```

Run the publisher and subscriber in **three separate terminals**:
```bash
# Terminal 1
ros2 run 1_pubsub publisher

# Terminal 2
ros2 run 1_pubsub processor

# Termianl 3
ros2 run 1_pubsub subscriber
```

### 2. `2_srvmsg` + `custom_interfaces`
#### add_ints_client.py + add_ints_server.py
Build the package in your ROS2 workspace:  
```bash
colcon build
source install/setup.bash
```
Run the publisher and subscriber in **two separate terminals**:
```bash
# Terminal 1
ros2 run 2_srvmsg add_ints_server

# Terminal 2
ros2 run 2_srvmsg add_ints_client <a> <b>    # Each <a>, <b> is a int64 what you want
```


---
#### move_robot_client.py + move_robot_server.py
Build the package in your ROS2 workspace:  
```bash
colcon build
source install/setup.bash
```
Run the publisher and subscriber in **two separate terminals**:
```bash
# Terminal 1
ros2 run 2_srvmsg move_robot_server

# Terminal 2
ros2 run 2_srvmsg move_robot_client <x> <y> <theta> <distance>    # Each <x>, <y>, <theta>, <distance> is a float64 what you want
```
