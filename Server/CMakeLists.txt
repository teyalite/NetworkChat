cmake_minimum_required(VERSION 3.20)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Network
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Server sources/main.cpp sources/server_window.cpp headers/server_window.h)
target_link_libraries(Server
        Qt::Core
        Qt::Gui
        Qt::Network
        Qt::Widgets
        )