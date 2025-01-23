#include "uas_vio/vio_node.h"

VIONode::VIONode() : Node("VIONode") {
  RCLCPP_INFO(this->get_logger(), "Starting VIO Node...");

  this->imu_sub = this->create_subscription<sensor_msgs::msg::Imu>("imu", 10, std::bind(&VIONode::callbackImu, this, std::placeholders::_1));
  this->image_sub = this->create_subscription<sensor_msgs::msg::Image>("image", 10, std::bind(&VIONode::callbackImage, this, std::placeholders::_1));
}

void VIONode::callbackImu(const sensor_msgs::msg::Imu msg) {
  RCLCPP_INFO(this->get_logger(), "Imu data received.");
}

void VIONode::callbackImage(const sensor_msgs::msg::Image msg) {
  RCLCPP_INFO(this->get_logger(), "Image data received.");
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VIONode>());
  rclcpp::shutdown();
  return 0;
}