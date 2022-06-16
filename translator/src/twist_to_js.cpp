#include "../include/translator/twist_to_js.h"

void TwistToJs::twistCallback(const geometry_msgs::TwistConstPtr& msg)
{
    float xVel = msg->linear.x;
    float yVel = msg->linear.y;

    int jsFB = 100;
    int jsLR = 100;

    std::cout << "MSG recieved ... " << msg->linear.x << std::endl;
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
    jsMsg.forwardBack = jsFB;
    jsMsg.leftRight = jsLR;
    this->publisher.publish(jsMsg);
}

void TwistToJs::run() { ros::spin(); }

int main(int argc, char** argv)
{

    ros::init(argc, argv, "js_interface_node");

    TwistToJs twistConverter;
    twistConverter.run();

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