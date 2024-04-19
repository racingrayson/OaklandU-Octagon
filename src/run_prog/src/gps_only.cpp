#include <ros/ros.h>
#include <unistd.h>
#include <std_msgs/String.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <nav_msgs/Odometry.h>
#include <gps_common/conversions.h>
#include <cmath>

#define PI 3.14159265

float init_time = 0;
float total_time = 0;
int MODE_POSITION = 1;
int MODE_VELOCITY = 0;
int MODE_STOPPED = -1;
int MAX_VELOCITY = 200;
int TURNING_SPEED = 200;
int WAYPOINT = 1;
float waypoint_lat;
float waypoint_long;
double waypoint_northing, waypoint_easting;
float waypoint_dist;
float current_northing,current_easting,last_northing, last_easting;
float heading, waypoint_heading, heading_error, next_waypoint_heading;
int loop = 0;



class controller{
  public:

    controller(){
      sub_gps = n_.subscribe("odom_utm", 1000, &controller::callback, this);
      pub_gps = n_.advertise<std_msgs::String>("gps_pose", 1000);
    }
    
    void callback(const nav_msgs::Odometry &odom){
      
      std_msgs::String pub_str;
      std::stringstream ss;
      current_northing = odom.pose.pose.position.x;
      current_easting = odom.pose.pose.position.y;
      getWaypoint(WAYPOINT);
      getHeading();
      
      

      //ss << "X: " << odom.pose.pose.position.x << " m, Y:"<< odom.pose.pose.position.y << " m";

      ss << "Waypoint:"<<WAYPOINT<<", Distance to waypoint: " << waypoint_dist << " m, Heading:" << heading << " deg, Heading error:"<< heading_error <<" deg";
      pub_str.data = ss.str();
      
      std::cout << pub_str.data.c_str() <<std::endl;
      
      pub_gps.publish(pub_str);
      waypoint_dist = sqrt(pow((current_easting-waypoint_easting),2)+pow((current_northing-waypoint_northing),2));
      if (waypoint_dist < 1){
	++WAYPOINT;
	getWaypoint(WAYPOINT);
	next_waypoint_heading = atan2((waypoint_easting-current_easting),(waypoint_northing-current_northing))*180/PI;
	}
      
      ++loop;
      if(loop == 20){
		last_easting = current_easting;
		last_northing = current_northing;
		loop = 0;
      }
      ros::spinOnce();
    }
    void getWaypoint(int waypoint){
	std::vector<std::string> keys;
        n_.getParamNames(keys);

        std::vector<std::map<std::string, double> > coordinates;
	    if (n_.hasParam("/waypoints/points/size")) {
		int size;
		n_.getParam("/waypoints/points/size", size);

		std::map<std::string, double> coordinate;
		std::stringstream path;
		path << "/waypoints/points/p" << waypoint;
		std::string tmpPath = path.str();
		bool flag = n_.getParam(tmpPath, coordinate);
		coordinates.push_back(coordinate);

		waypoint_lat = coordinate["latitude"];
		waypoint_long = coordinate["longitude"];
    		std::string zone;

   		gps_common::LLtoUTM(waypoint_lat, waypoint_long, waypoint_northing, waypoint_easting, zone);
	     }
	}
	void getHeading(){
		heading = atan((current_easting-last_easting)/(current_northing-last_northing))*180/PI;
		waypoint_heading = atan((waypoint_easting-current_easting)/(waypoint_northing-current_northing))*180/PI;
		heading_error = (waypoint_heading - heading);
		
	}
	void stop(){
	}
	void go(){
	}
	void turn(){
	}

  private:
    ros::NodeHandle n_;
		
    ros::Subscriber sub_gps;
    ros::Publisher pub_gps;
};



int main(int argc, char **argv){
  
  //usleep(2000000);
  ros::init(argc, argv, "controller");
  
  controller ctrl;

  ros::spin();
  
  return 0;
}
