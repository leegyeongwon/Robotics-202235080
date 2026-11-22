import rclpy
from math import cos, sin, radians
from rclpy.node import Node
from custom_interfaces.srv import MoveRobot


class MoveRobotNode(Node):
    def __init__(self):
        super().__init__('srv_server')

        self.srv = self.create_service(MoveRobot, '/move_robot', self.srv_callback)
        self.get_logger().info('Srv Server Ready.')

    def srv_callback(self, request, response):

        # Final result may have some error because of caculation of computer(Limit of computation of computer)
        angle = radians(request.current_pose.theta)
        
        response.result_pose.x = request.current_pose.x + (request.distance * cos(angle))
        response.result_pose.y = request.current_pose.y + (request.distance * sin(angle))
        response.result_pose.theta = angle
        response.success = True
        
        
        self.get_logger().info(f'Incoming request\nx: {request.current_pose.x}, y: {request.current_pose.y}, theta: {request.current_pose.theta}, distance: {request.distance}')
        self.get_logger().info(f'Sending back response: x,y,theta,success[{response.result_pose.x}, {response.result_pose.y}, {response.result_pose.theta}, {response.success}]')
        
        return response



def main():
    rclpy.init()
    node = MoveRobotNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
