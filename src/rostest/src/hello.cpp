#include <cstdio>
#include <rclcpp/rclcpp.hpp>

using rclcpp::init;
using rclcpp::Node;
using rclcpp::shutdown;

int main(int argc, char **argv) {
    init(argc, argv);
    const std::shared_ptr<Node> &node = Node::make_shared("node");
    RCLCPP_FATAL(node->get_logger(),"hello");
    printf("hello world rostest package\n");
    shutdown();
    return 0;
}
