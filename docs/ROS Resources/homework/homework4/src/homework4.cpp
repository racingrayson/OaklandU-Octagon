#include <ros/ros.h>
#include <tf/tf.h>
#include <visualization_msgs/Marker.h>

#include <visualization_msgs/MarkerArray.h>

#include <tf/transform_broadcaster.h>

#include <dynamic_reconfigure/server.h>
#include <homework4/MarkerConfig.h>
//#include <tf_example/TfExampleConfig.h>

tf::StampedTransform transform;


ros::Publisher pub_marker;
ros::Publisher pub_marker_array;
visualization_msgs::MarkerArray marker_array_msg;
visualization_msgs::Marker cube_marker_msg_1;
visualization_msgs::Marker cube_marker_msg_2;
visualization_msgs::Marker cube_marker_msg_3;
visualization_msgs::Marker cube_marker_msg_4;


 void reconfig(homework4::MarkerConfig& config, uint32_t level)
 {
  transform.setOrigin(tf::Vector3(config.x, config.y, config.z));
 transform.setRotation(tf::createQuaternionFromRPY(config.roll, config.pitch, config.yaw));
 }



void timerCallback(const ros::TimerEvent& event)
{
 // cube_marker_msg.header.stamp = event.current_real;
 // pub_marker.publish(cube_marker_msg);
  
cube_marker_msg_1.header.stamp = event.current_real;
cube_marker_msg_2.header.stamp = event.current_real;
cube_marker_msg_3.header.stamp = event.current_real;
  
static tf::TransformBroadcaster broadcaster;
transform.stamp_ = event.current_real;
broadcaster.sendTransform(transform);



marker_array_msg.markers.push_back(cube_marker_msg_1);
marker_array_msg.markers.push_back(cube_marker_msg_2);
marker_array_msg.markers.push_back(cube_marker_msg_3);

pub_marker_array.publish(marker_array_msg);
  
  
}

int main(int argc, char**argv)
{
  ros::init(argc, argv, "homework4");
  ros::NodeHandle node;
  
  pub_marker_array = node.advertise<visualization_msgs::MarkerArray>("marker_array", 1);

  ros::Timer marker_pub_timer = node.createTimer(ros::Duration(0.05), timerCallback);
  
   dynamic_reconfigure::Server<homework4::MarkerConfig> srv;
   srv.setCallback(boost::bind(reconfig, _1, _2));
//   
   transform.frame_id_ = "map";
   transform.child_frame_id_ = "marker";
   
   
   
  marker_array_msg.markers.resize(3);

  
 // marker_msg.markers[0] = cube_marker_msg_1;
 // marker_msg.markers[1] = cube_marker_msg_2;
 // marker_msg.markers[2] = cube_marker_msg_3;
 // visualization_msgs::Marker Marker;
  
  
  //first cube
  
  cube_marker_msg_1.header.frame_id = "marker";
  cube_marker_msg_1.id = 0;
  cube_marker_msg_1.action = visualization_msgs::Marker::ADD;
  cube_marker_msg_1.type = visualization_msgs::Marker::CUBE;
  
  cube_marker_msg_1.pose.position.x = 0.0;
  cube_marker_msg_1.pose.position.y = 0.0;
  cube_marker_msg_1.pose.position.z = 0.0;
  cube_marker_msg_1.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);
 
  cube_marker_msg_1.scale.x = 1.0;
  cube_marker_msg_1.scale.y = 1.0;
  cube_marker_msg_1.scale.z = 1.0;
  
  cube_marker_msg_1.color.a = 1.0;
  cube_marker_msg_1.color.r = 1.0;
  cube_marker_msg_1.color.g = 1.0;
  cube_marker_msg_1.color.b = 0.0;  
  
  
  //second cube
  cube_marker_msg_2.header.frame_id = "marker";
  cube_marker_msg_2.id = 1;
  cube_marker_msg_2.action = visualization_msgs::Marker::ADD;
  cube_marker_msg_2.type = visualization_msgs::Marker::CUBE;
  
  cube_marker_msg_2.pose.position.x = 1.0;
  cube_marker_msg_2.pose.position.y = 1.0;
  cube_marker_msg_2.pose.position.z = 1.0;
  cube_marker_msg_2.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);
 
  cube_marker_msg_2.scale.x = 1.0;
  cube_marker_msg_2.scale.y = 1.0;
  cube_marker_msg_2.scale.z = 1.0;
  
  cube_marker_msg_2.color.a = 1.0;
  cube_marker_msg_2.color.r = 0.0;
  cube_marker_msg_2.color.g = 1.0;
  cube_marker_msg_2.color.b = 1.0;  
  
  //third cube 
  cube_marker_msg_3.header.frame_id = "marker";
  cube_marker_msg_3.id = 2;
  cube_marker_msg_3.action = visualization_msgs::Marker::ADD;
  cube_marker_msg_3.type = visualization_msgs::Marker::CUBE;
  
  cube_marker_msg_3.pose.position.x = 2.0;
  cube_marker_msg_3.pose.position.y = 2.0;
  cube_marker_msg_3.pose.position.z = 2.0;  
  cube_marker_msg_3.pose.orientation = tf::createQuaternionMsgFromYaw(0.0);
 
  cube_marker_msg_3.scale.x = 1.0;
  cube_marker_msg_3.scale.y = 1.0;
  cube_marker_msg_3.scale.z = 1.0;
  
  cube_marker_msg_3.color.a = 1.0;
  cube_marker_msg_3.color.r = 1.0;
  cube_marker_msg_3.color.g = 0.0;
  cube_marker_msg_3.color.b = 1.0;  
  

  
  
  ros::spin();
  
}


