#include "../include/xpider_driver/XpiderDriver.h"
#include <string>

#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "xpider_driver");

  ros::NodeHandle n;

  ros::Rate loop_rate(10);
  ros::Publisher joint_states_publisher = n.advertise<sensor_msgs::JointState>("joint_states",1000);

  sensor_msgs::JointState joint_states;


  while (ros::ok())
  {
    joint_states.header.frame_id = "";
    joint_states.header.stamp = ros::Time::now();
    std::vector<std::string> joints_name = {"base_joint", "base_link_to_step_up_1",
        "base_link_to_step_up_2", "base_link_to_step_up_3", "step_connect_1_to_step_b_1",
        "step_connect_2_to_step_b_2", "step_connect_3_to_step_b_3",
        "base_link_to_step_c_1", "base_link_to_step_c_2", "base_link_to_step_c_3"};

    double i = rand() % 2;
    if (i == 0){
      i = -0.1;
    } else if (i == 1){
      i = 0.1;}
    joint_states.position = {i, i, i, i, i, i, i, i, i, i};
    joint_states.name = joints_name;

    joint_states_publisher.publish(joint_states);

    loop_rate.sleep();
    ros::spinOnce();
  }

  return 0;
}
