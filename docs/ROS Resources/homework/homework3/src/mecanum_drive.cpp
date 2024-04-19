#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>

ros::Publisher Pub1;

void callback(const geometry_msgs::TwistConstPtr& msg)
{
  std_msgs::Float64MultiArray float_array;

  float_array.data.resize(4);
  float_array.data[0] = (1/0.15)*(msg ->linear.x) - (1/0.15)*(msg->linear.y) - (1/0.3)*(msg->angular.z); 
  float_array.data[1] = (1/0.15)*(msg ->linear.x) + (1/0.15)*(msg->linear.y) + (1/0.3)*(msg->angular.z); 
  float_array.data[2] = (1/0.15)*(msg ->linear.x) + (1/0.15)*(msg->linear.y) - (1/0.3)*(msg->angular.z);
  float_array.data[3] = (1/0.15)*(msg ->linear.x) - (1/0.15)*(msg->linear.y) + (1/0.3)*(msg->angular.z);
  
  Pub1.publish(float_array);

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "mecanum_drive_node");
  
  ros::NodeHandle node;

  ros::Subscriber sub_Twist = node.subscribe<geometry_msgs::Twist>("/twist_cmd", 1, callback);
  
  Pub1 = node.advertise<std_msgs::Float64MultiArray>("/omnibot/wheel_speed_cmd", 1);
  
  ros::spin();
}