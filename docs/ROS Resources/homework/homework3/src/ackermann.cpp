#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>


ros::Publisher Pub_speeds; 
ros::Publisher pub_steering;


void recvcallback(const geometry_msgs::TwistConstPtr& msg)
{
  geometry_msgs::Twist speed;
  std_msgs::Float64 steering;
  
 speed.linear.x = msg ->linear.x;
 steering.data = 17.3*atan((3*(msg ->angular.z))/(msg ->linear.x));

  Pub_speeds.publish(speed);
  pub_steering.publish(steering);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ackermann_node");
  ros::NodeHandle node;
  
  ros::Subscriber sub_Twist = node.subscribe<geometry_msgs::Twist>("/twist_cmd", 1, recvcallback);
  
  Pub_speeds = node.advertise<geometry_msgs::Twist>("/audibot/cmd_vel", 1);
  
  pub_steering = node.advertise<std_msgs::Float64>("/audibot/steering_cmd", 1);
  
  ros::spin();
}

