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
    joint_state.name.resize(14);
    joint_state.position.resize(14);

    joint_state.name[0] = "base_link";
    joint_state.position[0] = 0;

    joint_state.name[1] = "shield_top";
    joint_state.position[1] = 0;

    joint_state.name[2] = "shield_bottom";
    joint_state.position[2] = 0;

    joint_state.name[3] = "step";
    joint_state.position[3] = 0;

    joint_state.name[4] = "step_base";
    joint_state.position[4] = 0;

    joint_state.name[5] = "leg_1";
    joint_state.position[5] = 0;

    joint_state.name[6] = "leg_2";
    joint_state.position[6] = 0;

    joint_state.name[7] = "leg_3";
    joint_state.position[7] = 0;

    joint_state.name[8] = "step_up_1";
    joint_state.position[8] = 0;

    joint_state.name[9] = "step_up_2";
    joint_state.position[9] = 0;

    joint_state.name[10] = "step_up_3";
    joint_state.position[10] = 0;

    joint_state.name[11] = "leg_4";
    joint_state.position[11] = 0;

    joint_state.name[12] = "leg_5";
    joint_state.position[12] = 0;

    joint_state.name[13] = "leg_6";
    joint_state.position[13] = 0;

    joint_state_publisher.publish(joint_state);
    loop_rate.sleep();
    ros::spinOnce();
  }

  return 0;
}
