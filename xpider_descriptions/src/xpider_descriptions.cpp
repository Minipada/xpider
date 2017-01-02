#include "../include/XpiderKinematics.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "xpider_descriptions");

  XpiderKinematics xpider;

  ros::Rate loop_rate(30);

  while (ros::ok())
  {
    xpider.setJoints();
    loop_rate.sleep();
    ros::spinOnce();
  }

  return 0;
}
