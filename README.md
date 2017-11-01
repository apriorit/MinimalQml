## Introduction

This is minimal program that uses QtQuick library for creating user interface
and using CMake as build system. The application created is simple in design and
consists of sole window.

## Built With

Compiling and running the project requires GCC, CMake, GNU Make
and Qt development libraries with Qt Quick enabled.

* [CMake](http://cmake.org/) - Build system (>=2.8 is required).
* [Qt](http://www.qt.io/) - Cross-platform library (>=5.7 is required).

## Dependencies

Install the following packages to prepare the build.

### Ubuntu & Debian

The following instructions are appliable to:
* Ubuntu 16.04
* Debian 9

```
sudo apt-get install -y \
    build-essential \
    cmake qtbase5-dev \
    qtdeclarative5-dev \
    qml-module-qtquick2 \
    qtquickcontrols2-5-dev \
    qml-module-qtquick-controls
```

### CentOS 7

```
sudo yum groupinstall -y "Development Tools"
sudo yum install -y \
    cmake \
    qt5-qtbase-devel \
    qt5-qtdeclarative-devel \
    qt5-qtquickcontrols \
    qt5-qtquickcontrols2-devel
```

### Fedora >=22

```
sudo dnf groupinstall -y "Development Tools"
sudo dnf install -y \
    cmake \
    qt5-qtbase-devel \
    qt5-qtdeclarative-devel \
    qt5-qtquickcontrols \
    qt5-qtquickcontrols2-devel
```

## Build Project

Call the build of the solution and launch the application:

```
cd <PathToProject>
mkdir build && cd build
cmake ..
make
```

After building the binary `MinimalQml` will end up in `build/src/`

```
cd build/src
./MinimalQml
```

