cmake_minimum_required(VERSION 2.8)

# Common project properties
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILT_TYPE Debug CACHE STRING "Choose the type of build, options are: Debug Release" FORCE)
endif()

# 3rd party tools
find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)

# Directory with the source code
add_subdirectory(src)


