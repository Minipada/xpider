cmake_minimum_required(VERSION 2.8.3)
project(xpider_driver)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  tf
)

catkin_package()
add_definitions("-std=gnu++11")

include_directories(
  ${catkin_INCLUDE_DIRS}
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

add_library(xpider_driver_lib
 src/XpiderDriver.cpp
)

target_link_libraries(xpider_driver_lib
 ${catkin_LIBRARIES}
)

add_executable(xpider_driver
 src/xpider_driver.cpp)

target_link_libraries(xpider_driver
 xpider_driver_lib
)

install(TARGETS xpider_driver_lib
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(TARGETS xpider_driver
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
