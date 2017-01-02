#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

class XpiderDriver {
public:
  XpiderDriver():
    loop_rate_(10),
    joints_name_(
    {"base_link", "base_joint", "base_link_to_step_up_1",
      "base_link_to_step_up_2", "base_link_to_step_up_3", "step_connect_1_to_step_b_1",
      "step_connect_2_to_step_b_2", "step_connect_3_to_step_b_3",
      "base_link_to_step_c_1", "base_link_to_step_c_2", "base_link_to_step_c_3"})
  {
    joint_states_publisher_ = n_.advertise<sensor_msgs::JointState>("joint_states",1000);
  }

  ~XpiderDriver(){}
  void randomMovement();



private:
  ros::NodeHandle n_;
  ros::Rate loop_rate_;
  ros::Publisher joint_states_publisher_;
  sensor_msgs::JointState joint_states_;
  std::vector<std::string> joints_name_;

};
