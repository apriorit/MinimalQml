## Introduction

This guide aims to create a simple Qt application with Qt Quick graphical user 
interface. The tutorial uses CMake as the project format and C++ as the language 
of source code. The application created is simple in design and consists of sole 
window.

QtQuick is a user interface library that provides ways to create declarative 
user interface separated from the programming logic. It's framework is 
implemented as a part of the Qt library set. QML is a user interface 
specification and programming language.

CMake is the project generator for many platforms and build systems. CMake uses 
the unified file format and is able to generate makefiles, Visual Studio 
solutions and projects for many other build systems from the same project file.

## Prerequisites

Compiling and running the sample project requires GCC, CMake, GNU Make and Qt 
development libraries with Qt Quick enabled. This tutorial specifies the way to 
install pre-compiled packages from the standard repositories.

## Environment Setup

### Debian-based Systems

The following instructions are applied to these operating systems:

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

### RedHat-based Systems

The following instructions are applied to these operating systems:

* Fedora >=22

```
sudo dnf groupinstall -y \
    "Development Tools" \
    "Development Libraries"
sudo dnf install -y \
    cmake \
    gcc-c++ \
    qt5-qtbase-devel \
    qt5-qtdeclarative-devel \
    qt5-qtquickcontrols \
    qt5-qtquickcontrols2-devel
```

* CentOS 7

```
sudo yum groupinstall -y \
    "Development Tools" \
    "Development Libraries"
sudo yum install -y \
    cmake \
    qt5-qtbase-devel \
    qt5-qtdeclarative-devel \
    qt5-qtquickcontrols \
    qt5-qtquickcontrols2-devel
```

## Directory Structure

The directory of the project is laid out as follows.

```
$ tree
.
├── CMakeLists.txt
└── src
    ├── CMakeLists.txt
    ├── main.cpp
    ├── main.qml
    └── qml.qrc
 
1 directory, 5 files
```

All source files for the project will go in src and main project specifications 
in CMake format are in the `CMakeLists.txt` file. Larger projects tend to be 
organised in sub-directories for modules, executables and libraries, each with 
its individual sub-directory and `CMakeLists.txt` file within.

## Main Window GUI File

Start with declarative file for user interface that is specified in the file 
`src/main.qml`. The code creates a small window without any controls.

[src/main.qml](https://github.com/apriorit/MinimalQml/blob/master/src/main.qml)

Necessary modules are imported. The exact version of the `QtQuick` library is not 
the same as the version of the Qt framework used. `QtQuick.Controls` library 
contains some basic controls for the user interface.

```
import QtQuick 2.0
import QtQuick.Controls 1.0
```

Main application window is represented with the `ApplicationWindow` control in the 
Qt Quick library. 

```
ApplicationWindow
{
...
}
```

There are four attributes of the main window that specify the size and title of 
the window. The `visible` attribute is required to specify that the window should 
be shown in the screen right after launch.

```
visible: true
width: 640
height: 480
title: qsTr("Minimal Qml")
```

## QML Resource File

This is the QML resource file for the application that consists of sole QML file 
named `main.qml`. The file is XML with `RCC` element as root and `qresource` as 
element for group of resources. This project contains only one group that is the 
root (i.e. `/`). Larger projects may contain additional qresource elements for 
each resource subgroup (e.g. `customControls`, `customWindows`, etc.).

[src/qml.qrc](https://github.com/apriorit/MinimalQml/blob/master/src/qml.qrc)

## Application Code

The main entry point of the application provides the C++ code for displaying Qt 
Quick user interface.

[src/main.qml](https://github.com/apriorit/MinimalQml/blob/master/src/main.cpp)

Standard object for Qt application is constructed.

```
QApplication app(argc, argv);
```

Here the QML parsing object is initiated for the application. This object 
receives the string with address of the main QML resource as the construction 
parameter. In this case `qrc:/main.qml` is the address specified in the `qml.qrc` 
file. `qrc:` is the default prefix for the QML resource, `/main.qml` stands for 
resource named `main.qml` in the root resource directory (`/`).

```
QQmlApplicationEngine engine;
engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
```

The `exec` method starts Qt application.

```
return app.exec();
```

## Project Files

This section shows deployment of Qt Quick application using CMake project 
format.

This is the main project file. The first line sets the minimum version of CMake 
for the project. It includes Qt5 framework into the application and concludes 
with the further inclusion of the src subdirectory so that CMake would search 
for the project file (`CMakeLists.txt`) there.

[CMakeLists.tst](CMakeLists.txt)

This is the project file for the executable.

[src/CMakeLists.tst](src/CMakeLists.txt)

The header files of the Qt project should be included into the project so that 
makefiles generated will have them specified in the corresponding compilation 
commands. There Qt5Widgets stands the header files for the Qt Framework and 
QtQml invokes special files for QML functions.

```
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
```

The definitions as well as Qt include files should be specified in the makefile 
compilation commands.

```
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS}
                ${${Qt5Quick_DEFINITIONS}})
```

The Qt framework requires the code to be created from the Qt resource files. 
This is achieved using the special `qt5_add_resources` command. The QML resource 
file path relative to this file is passed as an argument here.

```
qt5_add_resources(QT_RESOURCES qml.qrc)
```

For Qt projects with graphical user interface the compiler should receive 
special parameters for compilcation

```
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
```

Qt programs require several additional compilation steps for [moc](https://doc.qt.io/qt-5/moc.html),
[rcc](https://doc.qt.io/qt-5/rcc.html) and [uic](https://doc.qt.io/qt-5/uic.html). 

```
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
```

The name of the project that will be used as a name of the compiled executable 
is specified using the set command that receives the name of a variable (i.e. 
`PROJECT`) and it's value.

```
set(PROJECT "MinimalQml")
```

The project command sets the current project within the CMake file. It receives 
the value of the variable defined above.

```
project(${PROJECT})
```

The compiler flags for compiling C++ sources are set below. These flags stands 
for very strict compilation rules and help to detect and locate a lot of 
potential issues during compilation.

```
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11 
    -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations 
    -Wno-unused-variable")
```

There are conditional commands in the CMake project language. The code below 
detects if there are `HEADERS` in the project. If the header files were not set 
before the `file(GLOB ... .h)` command creates a list of all header files in the 
current directory and passes them as header files of the current project. The 
same applies to the `.cpp` sources that will be stored in the `SOURCES` variable if 
it was not defined.

```
if(NOT DEFINED HEADERS)
    file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
endif()
 
if(NOT DEFINED SOURCES)
    file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
endif()
```

The `source_group` definition creates a group of files that will be placed in some 
build systems (e.g. there will be project sub-directories in Visual Studio 
solution).

```
source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
```

This command states an executable file is the result of the project. The first 
parameter receives the name of an executable file that is the same as the name 
of the project in this case. The rest of the arguments are project sources, 
headers and compiled Qt resources.

```
add_executable(${PROJECT} ${HEADERS} ${SOURCES} ${QT_RESOURCES})
```

The set of libraries that will be linked with the executable above is set with 
the `target_link_libraries` command. Like the command above it receives the name 
of project's executable and the list of libraries. In this case the project uses 
Qt framework libraries only.

```
target_link_libraries(${PROJECT}
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    )
```

## Building Project

The program is built with the commands below. CMake requires the directory 
with the main project's `CMakeLists.txt` file as an argument. Then the CMake 
creates the build files for the GNU make which build an executable.

```
cd <PathToProject>
mkdir build && cd build
cmake ..
make
```

After the successful build the binary `MinimalQml` will end up in `build/src/`.

```
./src/MinimalQml
```

## Working with Project with Qt Creator

Go to the *Welcome* tab *(1)* in the main window and select *Open Project* *(2)*.

![Qt Creator Welcome Page](img/qt101.png)

In the opened dialog locate the `CMakeLists.txt` file in the root directory of the 
project.

![Opening Project File](img/qt102.png)

After that select the version of the *Qt framework* that will be used for 
compiling the project. In case there are multiple frameworks installed in the 
system it is possible to select several of them.

![Selecting Qt Frameworks](img/qt103.png)

After opening the project its directory structure will be visible in the *Projects* 
panel in Qt Creator.

![Opened Qt Project](img/qt104.png)

The C++ source files are treated as usual by the editor.

![Editing C++ File](img/qt105.png)

QRC resource files are opened as a resource tree.

![Opened QRC Resource File](img/qt106.png)

From the resource tree it is possible to open QML files of the project.

![Editing QML File](img/qt107.png)

## Links

* Qt Documentation 
  * [Qt QML](https://doc.qt.io/qt-5/qtqml-index.html)
  * [Qt Quick](https://doc.qt.io/qt-5/qtquick-index.html)
  * [QML Applications](https://doc.qt.io/qt-5/qmlapplications.html)
* CMake
  * [CMake Documentation](https://cmake.org/documentation/)
  * [CMake Tutorial](https://cmake.org/cmake-tutorial/)

