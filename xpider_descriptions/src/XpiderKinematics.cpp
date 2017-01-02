#include "../include/XpiderKinematics.hpp"

void XpiderKinematics::setJoints()
{
  joint_state_.header.stamp = ros::Time::now();
  joint_state_.name.resize(number_of_joints_);
  joint_state_.position.resize(number_of_joints_);

  joint_state_.name[0] = "base_link";
  joint_state_.position[0] = 0;

  int joint_number = 1; // 0 is for base_link
  for (auto joints_name_loop : joints_names_){
    std::string param_name = "/xpider/" + joints_name_loop + "_controller/position";

    joint_state_.name[joint_number] = joints_name_loop;
    if(!n_.getParam(param_name, joint_state_.position[joint_number])){
      ROS_WARN("Could not get param from %s", param_name.c_str());
    }
    joint_number++;
  }

  joint_state_publisher_.publish(joint_state_);
}
