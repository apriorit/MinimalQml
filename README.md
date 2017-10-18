# Minimal Qt QML Project

This is minimal program that uses Qt Qml for creating user interface library
and using CMake as build system.

## Built With

* [CMake](http://cmake.org/) - Build system (>=5.7 is required).
* [Qt](http://www.qt.io/) - Cross-platform library (>=2.8 is required).

## Getting Started

Install the following packages to prepare the build.

### Ubuntu & Debian

* Ubuntu 16.04
* Debian 9

```
sudo apt-get install -y build-essential cmake qtbase5-dev qtdeclarative5-dev qml-module-qtquick2 qtquickcontrols2-5-dev qml-module-qtquick-controls
```

### Fedora & CentOS

* CentOS 7
* Fedora >=20

```
sudo yum groupinstall -y "Development Tools"
sudo yum install -y cmake qt5-qtbase-devel qt5-qtdeclarative-devel qt5-qtquickcontrols qt5-qtquickcontrols2-devel
```

### Build Solution

Call the build of the solution and launch the application:

```
cd <PathToProject>
mkdir build
cd build
cmake ..
make
./src/MinimalQml &
```

