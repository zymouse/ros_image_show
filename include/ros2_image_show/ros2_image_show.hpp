#ifndef IMAGE_SUBSCRIBER__IMAGE_SUBSCRIBER_COMPONENT_HPP_
#define IMAGE_SUBSCRIBER__IMAGE_SUBSCRIBER_COMPONENT_HPP_

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

namespace image_subscriber
{
class ImageSubscriber : public rclcpp::Node
{
public:
  ImageSubscriber(const rclcpp::NodeOptions & node_options);

private:
  void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg);

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};
}  // namespace image_subscriber

#endif  // IMAGE_SUBSCRIBER__IMAGE_SUBSCRIBER_COMPONENT_HPP_
