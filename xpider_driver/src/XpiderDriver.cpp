#include "../include/xpider_driver/XpiderDriver.h"

void XpiderDriver::randomMovement()
{
  while (ros::ok())
  {
    double i = rand() % 2;
    if (i == 0){
      i = -0.1;
    } else if (i == 1){
      i = 0.1;
    }
    joint_states_.position = {0, i, i, i, i, i, i, i, i, i, i};
    joint_states_.name = joints_name_;
    joint_states_.header.frame_id = "";
    joint_states_.header.stamp = ros::Time::now();

    this->joint_states_publisher_.publish(this->joint_states_);
    this->loop_rate_.sleep();
    ros::spinOnce();
  }
}
