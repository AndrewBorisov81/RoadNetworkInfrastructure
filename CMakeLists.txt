cmake_minimum_required(VERSION 3.0.0)
project(RoadNetworkInfrastructure VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

add_subdirectory(src)

add_executable(RoadNetworkInfrastructure main.cpp RdnwinfInstance.cpp)

target_link_libraries(RoadNetworkInfrastructure PRIVATE my_src)