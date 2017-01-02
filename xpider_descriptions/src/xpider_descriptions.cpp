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
    joint_state.name.resize(20);
    joint_state.position.resize(20);

    joint_state.name[0] = "base_link";
    joint_state.position[0] = 0;

    joint_state.name[1] = "base_step";
    joint_state.position[1] = 0;

    joint_state.name[2] = "base_link_to_step_connect_1";
    joint_state.position[2] = 0;

    joint_state.name[3] = "base_link_to_step_connect_2";
    joint_state.position[3] = 0;

    joint_state.name[4] = "base_link_to_step_connect_3";
    joint_state.position[4] = 0;

    joint_state.name[5] = "step_connect_1_to_step_b_1";
    joint_state.position[5] = 0;

    joint_state.name[6] = "step_connect_2_to_step_b_2";
    joint_state.position[6] = 0;

    joint_state.name[7] = "step_connect_3_to_step_b_3";
    joint_state.position[7] = 0;

    joint_state.name[8] = "base_link_to_shield_top";
    joint_state.position[8] = 0;

    joint_state_publisher.publish(joint_state);
    loop_rate.sleep();
    ros::spinOnce();
  }

  return 0;
}
