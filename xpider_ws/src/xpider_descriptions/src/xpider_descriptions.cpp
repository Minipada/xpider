#include "../include/XpiderKinematics.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "xpider_descriptions");

  XpiderKinematics xpider;
//  xpider.initJoints();
  ros::NodeHandle n;

  ros::Publisher joint_state_publisher = n.advertise<sensor_msgs::JointState>("joint_states",1000);
  ros::Rate loop_rate(30);
  sensor_msgs::JointState joint_state;

  while (ros::ok())
  {
    joint_state.header.stamp = ros::Time::now();
    joint_state.name.resize(3);
    joint_state.position.resize(3);

    joint_state.name[0] = "base_link";
    joint_state.position[0] = 0;

    joint_state.name[1] = "shield_top";
    joint_state.position[1] = 0;

    joint_state.name[1] = "shield_bottom";
    joint_state.position[1] = 0;

    joint_state_publisher.publish(joint_state);
    loop_rate.sleep();
    ros::spinOnce();
  }

  return 0;
}
