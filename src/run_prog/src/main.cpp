#include <ros/ros.h>
#include <unistd.h>
#include <std_msgs/String.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <nav_msgs/Odometry.h>
#include <gps_common/conversions.h>
#include <cmath>
#include "roboteq_msgs/Feedback.h"
#include "roboteq_msgs/Command.h"

#define PI 3.14159265

//GPS variables
int WAYPOINT = 1;
float waypoint_lat;
float waypoint_long;
double waypoint_northing, waypoint_easting;
float waypoint_dist;
float current_northing,current_easting,last_northing, last_easting;
float heading, waypoint_heading, heading_error, next_waypoint_heading;
int loop = 0;

//Motor controller variables
int MODE_VELOCITY = 0;
int accel_gain = 40;
int decel_gain = 40;
int MAX_VELOCITY = 400;
int VELO_CMD = 0;
int TURNING_SPEED = 200;
float turning_ratio = 0.085;
int CMD_MODE = 1; //1 = go, 0 = stop, -1 = turn
float P = 6; //Heading correction gain
float I = -0.4; //Heading correction integrator
float error_sum = 0;
int heading_correction;
roboteq_msgs::Command command1;
roboteq_msgs::Command command2;
bool prog_end = false;



class controller{
  public:

    controller(){
      sub_gps = n_.subscribe("odom_utm", 1000, &controller::callback, this);
      pub_gps = n_.advertise<std_msgs::String>("gps_pose", 1000);
      pub1 = n_.advertise<roboteq_msgs::Command>("channel1/cmd",1000);
      pub2 = n_.advertise<roboteq_msgs::Command>("channel2/cmd",1000);
    }
    
    void callback(const nav_msgs::Odometry &odom){
      
      std_msgs::String pub_str;
      std::stringstream ss;
	if (CMD_MODE == 0){
		stop();
	} else if (CMD_MODE == -1){
	      int turn_loop = static_cast<int>(abs(turning_ratio*next_waypoint_heading));
	      if (loop<=turn_loop){
			++loop;
			turn();
		}else {
			stop();
			last_easting = current_easting;
			last_northing = current_northing;
		}
	} else {
		go();
      current_northing = odom.pose.pose.position.x;
      current_easting = odom.pose.pose.position.y;
      getWaypoint(WAYPOINT);
      getHeading();
      

      ss << "Waypoint:"<<WAYPOINT<<", Distance to waypoint: " << waypoint_dist << " m, Heading error:"<< heading_error <<" deg";
      pub_str.data = ss.str();
      
      std::cout << pub_str.data.c_str() <<std::endl;
      
      pub_gps.publish(pub_str);
      waypoint_dist = sqrt(pow((current_easting-waypoint_easting),2)+pow((current_northing-waypoint_northing),2));
      if (waypoint_dist < 3){
	CMD_MODE = 0;
	++WAYPOINT;
	getWaypoint(WAYPOINT);
	next_waypoint_heading = atan2((waypoint_easting-current_easting),(waypoint_northing-current_northing))*180/PI;
	}
      
      ++loop;
      if(loop >= 20){
		last_easting = current_easting;
		last_northing = current_northing;
		loop = 0;
      }
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
		if (waypoint>size){
			CMD_MODE = 0;
			prog_end = true;
		} else{
		
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
	}
	void getHeading(){
		heading = atan((current_easting-last_easting)/(current_northing-last_northing))*180/PI;
		waypoint_heading = atan((waypoint_easting-current_easting)/(waypoint_northing-current_northing))*180/PI;
		heading_error = (waypoint_heading - heading);
		if (abs(heading_error)<15){
			error_sum = error_sum + heading_error;
		}

		
	}
	void stop(){
		if (VELO_CMD>0){
			VELO_CMD = VELO_CMD - decel_gain;
		}
		command1.mode = MODE_VELOCITY;
		command1.setpoint = VELO_CMD;
		command2.mode = MODE_VELOCITY;
		command2.setpoint = 0;
		pub1.publish(command1);
		pub2.publish(command2);
		if (VELO_CMD == 0){
			if (CMD_MODE == -1){
				CMD_MODE = 1;
			} else if (prog_end) {
				CMD_MODE = 0;
			} else {
				CMD_MODE = -1;
			}
			usleep(1000000);
		}
		loop = 0;
	}
	void go(){
		if (VELO_CMD<MAX_VELOCITY){
			VELO_CMD = VELO_CMD + accel_gain;
			command2.setpoint = 8;
			error_sum = 0;
		}else{
			int heading_correction_p = static_cast<int>(P*heading_error);
			int heading_correction_i = static_cast<int>(I*error_sum);
			heading_correction = heading_correction_p + heading_correction_i;
			if ((abs(heading_error)>40)||(heading_error!=heading_error)){
				heading_correction = 0;
			}
			command2.setpoint = VELO_CMD/20 + heading_correction ;
		}
		command1.mode = MODE_VELOCITY;
		command1.setpoint = VELO_CMD;
		command2.mode = MODE_VELOCITY;
		
		pub1.publish(command1);
		pub2.publish(command2);
	}
	void turn(){
		if (next_waypoint_heading<0){
			command2.setpoint = -1*TURNING_SPEED;
		} else {
			command2.setpoint = TURNING_SPEED;
		} 
		command1.mode = MODE_VELOCITY;
		command1.setpoint = 0;
		command2.mode = MODE_VELOCITY;
		pub1.publish(command1);
		pub2.publish(command2);
	}

  private:
    ros::NodeHandle n_;
		
    ros::Subscriber sub_gps;
    ros::Publisher pub_gps;
    ros::Publisher pub1;
    ros::Publisher pub2;
};



int main(int argc, char **argv){
  
  usleep(2000000);
  ros::init(argc, argv, "controller");
  
  controller ctrl;

  ros::spin();
  
  return 0;
}
