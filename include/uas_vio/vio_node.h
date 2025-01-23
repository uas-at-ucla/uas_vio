#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "sensor_msgs/msg/image.hpp"

class VIONode : public rclcpp::Node
{
  public:
    VIONode();

  private:
    void callbackImu(const sensor_msgs::msg::Imu msg);
    void callbackImage(const sensor_msgs::msg::Image msg);

    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub;
};