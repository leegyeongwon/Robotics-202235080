import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Publisher(Node):
    def __init__(self):
        super().__init__('publisher')
        self.publisher_ = self.create_publisher(String, '/publisher_topic', 10)
        self.timer = self.create_timer(0.3, self.publish_message)

    def publish_message(self):
        msg = String()
        keyboard_input = str(input("Enter: "))
        msg.data = keyboard_input
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: "{msg.data}"')

def main():
    rclpy.init()
    node = Publisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
