cmake_minimum_required(VERSION 3.20)
project(Client)

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

add_executable(Client sources/main.cpp sources/client_window.cpp headers/client_window.h sources/top_widget.cpp headers/top_widget.h sources/bottom_widget.cpp headers/bottom_widget.h sources/logo_widget.cpp headers/logo_widget.h sources/list_widget.cpp headers/list_widget.h)
target_link_libraries(Client
        Qt::Core
        Qt::Gui
        Qt::Network
        Qt::Widgets
        )

