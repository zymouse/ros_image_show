#include "ros2_image_show/ros2_image_show.hpp"

namespace image_subscriber
{
ImageSubscriber::ImageSubscriber(const rclcpp::NodeOptions & options)
: Node("image_subscriber", options)
{
  subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
    "image_topic", 10, std::bind(&ImageSubscriber::topic_callback, this, std::placeholders::_1));
}

void ImageSubscriber::topic_callback(const sensor_msgs::msg::Image::SharedPtr msg) const
{
  cv_bridge::CvImagePtr cv_ptr;
  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception & e)
  {
    RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
    return;
  }

  cv::imshow("Image Window", cv_ptr->image);
  cv::waitKey(1);
}

}  // namespace image_subscriber

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(image_subscriber::ImageSubscriber)
