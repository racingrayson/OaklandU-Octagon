#include <ros/ros.h>
//#include <std_msgs/String.h>
#include <std_msgs/Float64.h>

ros::Publisher pub;

void Callback(const std_msgs::Float64ConstPtr& msg)
{
  std_msgs::Float64 new_message;
  new_message.data = msg -> data+5;
  pub.publish(new_message);
  
}
// Callback function and global variables go here!
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "pubsub_node");
  ros::NodeHandle node;
  
  ros::Subscriber sub = node.subscribe("topic_in",1, Callback);
  
  pub = node.advertise<std_msgs::Float64>("topic_out",1);
  
  
  ros::spin();
}




