#include <cstdio>
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/string.hpp"

using rclcpp::Node;
using namespace std::chrono_literals;
using namespace std;

class Pub : public Node {
public:
    Pub() : Node("nodeName") {
        RCLCPP_INFO(get_logger(),"Init");
        auto publisher = create_publisher<std_msgs::msg::String>("topic1", 256);
        create_wall_timer(1s, [publisher]() {
            auto msg = std_msgs::msg::String();
            msg.data = "233";
            publisher->publish(msg);
        });
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    auto pub = make_shared<Pub>();
    rclcpp::spin(pub);
    printf("hello world pub package\n");
    rclcpp::shutdown();
    return 0;
}
