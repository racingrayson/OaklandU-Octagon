#include <ros/ros.h>
#include <unistd.h>
#include <std_msgs/String.h>
#include <sstream>
#include "roboteq_msgs/Feedback.h"
#include "roboteq_msgs/Command.h"



float init_time = 0;
float total_time = 0;
int MODE_POSITION = 1;
int MODE_VELOCITY = 0;
int MODE_STOPPED = -1;
int accel_gain = 1;
int decel_gain = 1;
int MAX_VELOCITY = 400;
int VELO_CMD = 0;
int TURNING_SPEED = 200;
float turning_ratio = 1.4583;
float turning_cmd = 180.678;
roboteq_msgs::Command command1;
roboteq_msgs::Command command2;



class controller{
  public:

    controller(){
      sub1 = n_.subscribe("channel1/feedback", 1000, &controller::callback, this);
      sub2 = n_.subscribe("channel2/feedback", 1000, &controller::callback, this);
      pub1 = n_.advertise<roboteq_msgs::Command>("channel1/cmd",1000);
      pub2 = n_.advertise<roboteq_msgs::Command>("channel2/cmd",1000);
    }
    
    void callback(const roboteq_msgs::Feedback::ConstPtr& msg){

      std_msgs::String pub_str;
      std::stringstream ss;
      int turn_loop = static_cast<int>(abs(turning_ratio*turning_cmd));
      if (init_time<=turn_loop){
	        ++init_time;
		turn();
	}else {
		stop();
	}
   
      
      ss << "Loop: " << init_time;
      pub_str.data = ss.str();
      
      std::cout << pub_str.data.c_str() <<std::endl;
      
      
      ros::spinOnce();
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
	}
	void go(){
		if (VELO_CMD<MAX_VELOCITY){
			VELO_CMD = VELO_CMD + accel_gain;
		}
		command1.mode = MODE_VELOCITY;
		command1.setpoint = VELO_CMD;
		command2.mode = MODE_VELOCITY;
		TURNING_SPEED = VELO_CMD/25;
		command2.setpoint = TURNING_SPEED;
		pub1.publish(command1);
		pub2.publish(command2);
	}
	void turn(){
		if (turning_cmd<0){
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
		
    ros::Subscriber sub1;
    ros::Subscriber sub2;
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
