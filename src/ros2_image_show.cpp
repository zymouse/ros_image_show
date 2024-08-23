#include "ros2_image_show/ros2_image_show.hpp"

namespace image_subscriber
{
ImageSubscriber::ImageSubscriber(const rclcpp::NodeOptions & node_options)
: Node("image_subscriber", node_options)
{
  subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
    "image_topic", 10, std::bind(&ImageSubscriber::topic_callback, this, std::placeholders::_1));
}

void ImageSubscriber::topic_callback(const sensor_msgs::msg::Image::SharedPtr msg)
{
  (void)msg;
  RCLCPP_INFO_THROTTLE(
    this->get_logger(), 
    *this->get_clock(), 
    std::chrono::milliseconds(5000).count(),
    "encoding: %s", 
    msg->encoding.c_str()
  );
}

}  // namespace image_subscriber

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(image_subscriber::ImageSubscriber)
