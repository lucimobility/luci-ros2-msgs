#include "../include/translator/twist_to_js.h"

void TwistToJs::twistCallback(const geometry_msgs::msg::TwistConstPtr msg)
{
    float xVel = msg.linear.x;
    float yVel = msg.linear.y;

    int jsFB = 100;
    int jsLR = 100;

    std::cout << "MSG recieved ... " << msg.linear.x << std::endl;
    if (xVel > 0)
    {
        jsFB = 130;
    }
    else if (xVel < 0)
    {
        jsFB = 70;
    }
    if (yVel > 0)
    {
        jsLR = 130;
    }
    else if (yVel > 0)
    {
        jsLR = 70;
    }

    // Publish info
    translator::luci_joystick jsMsg;
    jsMsg.forward_back = jsFB;
    jsMsg.left_right = jsLR;
    this->publisher.publish(jsMsg);
}

// void TwistToJs::run() { rclcpp::spin(); }

int main(int argc, char** argv)
{

    rclcpp::init(argc, argv);
    auto node = std::make_shared<TwistToJs>();
    // ros::init(argc, argv, "js_interface_node");

    TwistToJs twistConverter;
    rclcpp::spin(node);
    // twistConverter.run();

    // ros::NodeHandle node_handle;
    // ros::Publisher publisher = node_handle.advertise<std_msgs::String>("joystick_topic", 1);
    // ros::Subscriber subscriber = node_handle.subscribe("turtle1/cmd_vel", 1, &twistCallback);
    // ros::Rate rate(10);

    // while (ros::ok())
    // {
    //     std_msgs::String msg;
    //     msg.data = "Hello";
    //     publisher.publish(msg);
    //     ros::spinOnce();
    //     rate.sleep();
    // }

    // ros::spin();

    return 0;
}