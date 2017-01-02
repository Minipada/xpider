#include <ros/ros.h>
#include <string>
#include <sensor_msgs/JointState.h>

class XpiderKinematics{
public:
  XpiderKinematics(){}
//  loop_rate(30) {}
  ~XpiderKinematics() {}

//  ros::Publisher joint_state_publisher = n_.advertise<sensor_msgs::JointState>("joint_states",1000);
//  ros::Rate loop_rate;
//  sensor_msgs::JointState joint_state;

  void initJoints();

private:

//  ros::NodeHandle n_;
};
