cmake_minimum_required(VERSION 3.0.0)
project(RoadNetworkInfrastructure VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE DEBUG)

# variables to store additional compiler flags
set(CXX_FLAGS)
set(CXX_FLAGS_DEBUG)
set(CXX_FLAGS_RELEASE)

# append global compiler flags to list
list(APPEND CXX_FLAGS "-Wall")

add_subdirectory(src)

# set compile options for my_src library
target_compile_options(my_src PRIVATE ${CXX_FLAGS})

find_package(Boost COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND) 
    include_directories(${Boost_INCLUDE_DIR})
    add_executable(RoadNetworkInfrastructure main.cpp RdnwinfInstance.cpp)
    link_directories(${Boost_LIBRARY_DIR})
endif()

target_link_libraries(RoadNetworkInfrastructure my_src ${Boost_LIBRARIES})