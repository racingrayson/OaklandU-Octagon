/*
 * Translates sensor_msgs/NavSat{Fix,Status} into nav_msgs/Odometry using UTM
 */

#include <ros/ros.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <sensor_msgs/NavSatStatus.h>
#include <sensor_msgs/NavSatFix.h>
#include <gps_common/conversions.h>
#include <nav_msgs/Odometry.h>
//#include <gps_common/getRelativePose.h>
#include <boost/thread/shared_mutex.hpp>
//#include <tf/transform_broadcaster.h>
#include <geometry_msgs/PoseStamped.h>

using namespace gps_common;

static ros::Publisher odom_pub;
std::string frame_id, child_frame_id;
nav_msgs::Odometry *initial_odom_utm_ = NULL;
double rot_cov;
boost::mutex mtx_;
//tf::TransformBroadcaster* tf_br_;

void callback(const sensor_msgs::NavSatFixConstPtr &fix) {


    if (fix->status.status == sensor_msgs::NavSatStatus::STATUS_NO_FIX) {
        ROS_INFO("No fix.");
        return;
    }

    if (fix->header.stamp == ros::Time(0)) {
        return;
    }

    double northing, easting;
    std::string zone;

    LLtoUTM(fix->latitude, fix->longitude, northing, easting, zone);

    if (odom_pub) {
        nav_msgs::Odometry odom;
        odom.header.stamp = fix->header.stamp;

        if (frame_id.empty())
            odom.header.frame_id = fix->header.frame_id;
        else
            odom.header.frame_id = frame_id;

        odom.child_frame_id = child_frame_id;

        odom.pose.pose.position.x = northing;
        odom.pose.pose.position.y = easting;
        odom.pose.pose.position.z = fix->altitude;

        odom.pose.pose.orientation.x = 0;
        odom.pose.pose.orientation.y = 0;
        odom.pose.pose.orientation.z = 0;
        odom.pose.pose.orientation.w = 1;

        // Use ENU covariance to build XYZRPY covariance
        boost::array<double, 36> covariance = {{
                                                       fix->position_covariance[0],
                                                       fix->position_covariance[1],
                                                       fix->position_covariance[2],
                                                       0, 0, 0,
                                                       fix->position_covariance[3],
                                                       fix->position_covariance[4],
                                                       fix->position_covariance[5],
                                                       0, 0, 0,
                                                       fix->position_covariance[6],
                                                       fix->position_covariance[7],
                                                       fix->position_covariance[8],
                                                       0, 0, 0,
                                                       0, 0, 0, rot_cov, 0, 0,
                                                       0, 0, 0, 0, rot_cov, 0,
                                                       0, 0, 0, 0, 0, rot_cov
                                               }};

        odom.pose.covariance = covariance;

        ROS_INFO_STREAM_ONCE("Initial Pose from GPS" << odom);
        if (initial_odom_utm_ == NULL) {
            boost::lock_guard<boost::mutex> guard(mtx_);
            initial_odom_utm_ = new nav_msgs::Odometry();
            (*initial_odom_utm_) = odom;
        }

        odom_pub.publish(odom);

        /*tf::Transform transform;
        transform.setOrigin(tf::Vector3(odom_relative_utm.pose.pose.position.x, odom_relative_utm.pose.pose.position.y, 0.0));
        tf::Quaternion q;
        q.setRPY(0.0, 0.0, 0.0);
        transform.setRotation(q);
        tf_br_->sendTransform(tf::StampedTransform(transform, ros::Time::now(), frame_id, "base_footprint"));*/
    }
}



int main(int argc, char **argv) {
    ros::init(argc, argv, "utm_odometry_node");
    ros::NodeHandle node;
    ros::NodeHandle priv_node("~");

    //tf_br_ = new tf::TransformBroadcaster();
    priv_node.param<std::string>("frame_id", frame_id, "");
    priv_node.param<std::string>("child_frame_id", child_frame_id, "");
    priv_node.param<double>("rot_covariance", rot_cov, 99999.0);

    odom_pub = node.advertise<nav_msgs::Odometry>("odom_utm", 10);

    ros::Subscriber fix_sub = node.subscribe("ublox/fix", 10, callback);

    ros::spin();
}

