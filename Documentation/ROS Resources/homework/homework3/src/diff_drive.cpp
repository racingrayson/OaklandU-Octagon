#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>


ros::Publisher pub_left1;
ros::Publisher pub_right;


void recvcallback(const geometry_msgs::TwistConstPtr& msg)
{
  
  
  std_msgs::Float64 left;
  std_msgs::Float64 right;

   left.data =  (1/0.2)*((msg ->linear.x) - (0.5*(msg -> angular.z)));
  right.data =  (1/0.2)*((msg ->linear.x) + (0.5*(msg -> angular.z)));
  
  pub_left1.publish(left);
  pub_right.publish(right);

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "diff_drive_node");
  ros::NodeHandle node;
  
  ros::Subscriber sub_Twist = node.subscribe<geometry_msgs::Twist>("/twist_cmd", 1, recvcallback);
  
  pub_left1 = node.advertise<std_msgs::Float64>("/roundbot/left_speed_cmd", 1);
  
  pub_right = node.advertise<std_msgs::Float64>("/roundbot/right_speed_cmd", 1);
  
  ros::spin();
}

