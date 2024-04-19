#ifndef __OCTAGON_NAV_GOALS_H__
#define __OCTAGON_NAV_GOALS_H__

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <visualization_msgs/MarkerArray.h>
#include <ros/ros.h>
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/shared_ptr.hpp>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>


namespace octagon
{

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class OcatagonNavGoals
{
	boost::mutex mtx_;

	//store nav goals from rviz/config
	std::list<geometry_msgs::PoseStampedConstPtr> goals_;

	ros::Publisher movebase_simple_navgoal_, wp_markers_pub_;
	ros::Subscriber get_navgoals_, final_goal_sub_, waypoints_sub_;

	double close_enough_;
	bool loop_;

	std::vector<geometry_msgs::PointStamped> waypoints_;
	std::vector<geometry_msgs::PointStamped>::iterator waypoints_it_;
	tf::TransformListener tf_listener_;

    visualization_msgs::MarkerArray markers_array_;

	boost::shared_ptr<MoveBaseClient> mbc_;

	geometry_msgs::PoseStamped::ConstPtr goal_;

	ros::NodeHandle nh_;

	move_base_msgs::MoveBaseGoal mb_goal_;

	std::string robot_frame_;
	std::string world_frame_;

public:
	OcatagonNavGoals();
	~OcatagonNavGoals();

	void captureMoveBaseGoals(const geometry_msgs::PoseStampedConstPtr& goals);
	geometry_msgs::PoseStampedConstPtr getMoveBaseGoals();
	void processGoals();
	void processGoals1();
	void spinOnce();

private:
	void waitForActionServer();
	bool isGoalAvailable();
	void finalGoalCB(const geometry_msgs::PoseStamped::ConstPtr& goal);
	void waypointCB(const geometry_msgs::PointStamped::ConstPtr& point);

	void publishMarkerArray();
	void addMarker(const geometry_msgs::PointStamped::ConstPtr& point, int index);
	void addGoal(const geometry_msgs::PoseStamped::ConstPtr& point, int index);
	void clearAllMarkers();
	void initMarker();


    void getGPSWayPointsFromParam();
	void getOdomWayPointsFromParam();

	void pose2tf(const geometry_msgs::PoseStamped& pose, tf::StampedTransform& tf);
	void pose2tf(const geometry_msgs::Pose& pose, tf::Transform& tf);

	double distance2D(double x, double y)
	{
	  return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
	}

	double distance2D(const tf::Point& p)
	{
	  return std::sqrt(std::pow(p.x(), 2) + std::pow(p.y(), 2));
	}

	double distance2D(double ax, double ay, double bx, double by)
	{
	  return std::sqrt(std::pow(ax - bx, 2) + std::pow(ay - by, 2));
	}

	double distance2D(const tf::Point& p1, const tf::Point& p2)
	{
	  return std::sqrt(std::pow(p2.x() - p1.x(), 2) + std::pow(p2.y() - p1.y(), 2));
	}

	double distance2D(geometry_msgs::Point a, geometry_msgs::Point b)
	{
	  return distance2D(tf::Vector3(a.x, a.y, a.z), tf::Vector3(b.x, b.y, b.z));
	}

	double distance2D(geometry_msgs::Pose a, geometry_msgs::Pose b)
	{
	  return distance2D(a.position, b.position);
	}

	double distance2D(const tf::Transform& a, const tf::Transform& b)
	{
	  return distance2D(a.getOrigin(), b.getOrigin());
	}
};

}

#endif
