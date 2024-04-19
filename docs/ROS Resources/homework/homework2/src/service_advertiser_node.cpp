#include <ros/ros.h>
#include <homework2/StringCat.h>
// Callback function goes here!

bool srvCallback(homework2::StringCatRequest& req, homework2::StringCatResponse& res)
{
  res.string_out = req.string_in + " with more text";
  return true;
  
}



int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_advertiser_node");
  ros::NodeHandle node;

  /* Code goes here! */
  ros::ServiceServer srv = node.advertiseService("concatenate_string", srvCallback);
  
  

  ros::spin();
}
