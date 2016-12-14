cmake_minimum_required(VERSION 2.8.3)
project(xpider_descriptions)

find_package(catkin REQUIRED COMPONENTS
  urdf
  roslint
)

catkin_package(
)

set(ROSLINT_CPP_OPTS "--filter=-legal/copyright")
roslint_cpp()

add_definitions("-std=gnu++11")
add_definitions("-Wall")

# Turn some warnings into errors.
add_definitions("-Werror=format-security")
add_definitions("-Werror=missing-braces")
add_definitions("-Werror=reorder")
add_definitions("-Werror=return-type")
add_definitions("-Werror=uninitialized")

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

add_library(xpider_descriptions_lib
 src/XpiderKinematics.cpp
)

target_link_libraries(xpider_descriptions_lib
 ${catkin_LIBRARIES}
)

add_executable(xpider_descriptions
 src/xpider_descriptions.cpp)

target_link_libraries(xpider_descriptions
 xpider_descriptions_lib
)

install(TARGETS xpider_descriptions_lib
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(TARGETS xpider_descriptions
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
