cmake_minimum_required(VERSION 3.5)
project(optimization_solver)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

## Eigen
find_package(Eigen3 3.3 REQUIRED)

## Ceres
find_package(Ceres REQUIRED)

## OSQP-Eigen
find_package(OsqpEigen REQUIRED)

## OSQP-CPP
add_subdirectory(abseil-cpp)
find_library(
  OsqpCpp 
  NAMES libosqp-cpp.a
  HINTS ~/github/osqp-cpp/build
  REQUIRED
  )

include_directories(include
~/github/osqp-cpp/include/
)

set(src_files
  src/optimization.cpp
  src/op_node.cpp
)

add_executable(op_node ${src_files})
ament_target_dependencies(op_node rclcpp std_msgs)
target_link_libraries(op_node Eigen3::Eigen OsqpEigen::OsqpEigen absl::strings ${OsqpCpp})

# Install
install(TARGETS
op_node
DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
