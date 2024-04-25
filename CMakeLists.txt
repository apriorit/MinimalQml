cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)

# 3rd party tools
find_package(Qt6 COMPONENTS Widgets Qml Quick REQUIRED)

# Directory with the source code
add_subdirectory(src)


