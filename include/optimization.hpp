#ifndef OPTIMIZATION_HPP
#define OPTIMIZATION_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// #include "OsqpEigen/OsqpEigen.h" //osqp : 6.3.0 version

// #include <Eigen/Dense>

// #include <iostream>


class optimization{
    public:
        optimization(){
            std::cout<< "생성자 호출" << std::endl;
        };

        ~optimization(){
            std::cout<< "소멸자 호출" << std::endl;
        };

        void test();

    private:
};

#endif // OPTIMIZATION_HPP