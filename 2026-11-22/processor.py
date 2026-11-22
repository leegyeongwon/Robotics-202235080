import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Processor(Node):
    def __init__(self):
        super().__init__('processor')
        self.subscription_ = self.create_subscription(String, '/publisher_topic', self.callback, 10)
        self.subscription_

        self.current_state = [0,0]
        self.publisher_ = self.create_publisher(String, '/processor_topic', 10)
        self.timer = self.create_timer(0.3, self.processor_publish)

    def callback(self, msg):
        self.get_logger().info(f'Received: "{msg.data}"')

        if msg.data == "w" or msg.data == "W":
            self.current_state[1] += 1
        elif msg.data == "s" or msg.data == "S":
            self.current_state[1] -= 1
        elif msg.data == "d" or msg.data == "D":
            self.current_state[0] += 1
        elif msg.data == "a" or msg.data == "A":
            self.current_state[0] -= 1


    def processor_publish(self):
        cur_state = String()
        cur_state.data = f"[{str(self.current_state[0])}, {str(self.current_state[1])}]"
        self.publisher_.publish(cur_state)
        self.get_logger().info(f'Publishing: "{cur_state.data}"')



def main():
    rclpy.init()
    node = Processor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()