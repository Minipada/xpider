#include "../include/xpider_driver/XpiderDriver.h"
#include <string>

#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "xpider_driver");

  XpiderDriver xpider_driver;

  xpider_driver.randomMovement();

  return 0;
}
