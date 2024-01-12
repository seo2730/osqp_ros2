# Optimiaztion with ros2

# Ceres Solver


----
# OSQP-Eigen


----
# OR-Tool

## CMake 업그레이드 필수 
- version : 최소 3.18

        cd ~/[다운 받은 경로]/cmake-3.xxxx/   # or wherever you downloaded cmake
        sh bootstrap --prefix=$HOME/cmake-install
        make 
        make install

- bashrc에 추가

        export PATH=$HOME/cmake-install/bin:$PATH
        export CMAKE_PREFIX_PATH=$HOME/cmake-install:$CMAKE_PREFIX_PATH

- [설치 방법](https://developers.google.com/optimization/install/cpp/source_linux)

- error log
    1. 용량 부족

            c++: fatal error: Killed signal terminated program cc1plus

        - 해결책
                
                cmake --build build --config Release --target all -j 4 -v