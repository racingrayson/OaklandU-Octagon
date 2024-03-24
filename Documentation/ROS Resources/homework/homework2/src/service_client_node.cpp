#include <ros/ros.h>
#include <homework2/StringCat.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_client_node");
  ros::NodeHandle node;
  
  ros::ServiceClient srv=node.serviceClient<homework2::StringCat>("concatenate_string");
  
  homework2::StringCatRequest request;
  homework2::StringCatResponse response;
  
  bool success = srv.call(request, response);
  if (success)
  {
    ROS_INFO("Service succeeded Resule = %s", response.string_out);
    
  }
  else
  {
    ROS_WARN("Service call failed");
    
  }
  

  /* Code goes here! */

  return 0; // Stop immediately instead of spinning
}
