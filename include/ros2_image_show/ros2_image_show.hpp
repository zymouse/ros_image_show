#ifndef IMAGE_SUBSCRIBER__IMAGE_SUBSCRIBER_COMPONENT_HPP_
#define IMAGE_SUBSCRIBER__IMAGE_SUBSCRIBER_COMPONENT_HPP_

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

namespace image_subscriber
{
class ImageSubscriber : public rclcpp::Node
{
public:
  explicit ImageSubscriber(const rclcpp::NodeOptions & options);

private:
  void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg) const;

  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};
}  // namespace image_subscriber

#endif  // IMAGE_SUBSCRIBER__IMAGE_SUBSCRIBER_COMPONENT_HPP_
