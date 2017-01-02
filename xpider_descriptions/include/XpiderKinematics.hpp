#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

#include <string>
#include <vector>

class XpiderKinematics{
public:
  XpiderKinematics():
    number_of_joints_(1)
  {
    joint_state_publisher_ = n_.advertise<sensor_msgs::JointState>("/xpider/joint_states",1000);
    joints_names_ = { "base_link_to_step", "base_link_to_shield_top",
                      "base_link_to_step_connect_1", "base_link_to_step_connect_2",
                      "base_link_to_step_connect_3", "step_connect_1_to_step_b_1",
                      "step_connect_2_to_step_b_2", "step_connect_3_to_step_b_3"};

    number_of_joints_ = joints_names_.size() + 1;

    setJoints();
  }
  ~XpiderKinematics() {}


  void setJoints();

private:
  std::vector<std::string> joints_names_;
  unsigned int number_of_joints_;
  sensor_msgs::JointState joint_state_;
  ros::Publisher joint_state_publisher_;
  ros::NodeHandle n_;
};
