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

add_executable(Client main.cpp client_window.cpp client_window.h top_widget.cpp top_widget.h bottom_widget.cpp bottom_widget.h logo_widget.cpp logo_widget.h list_widget.cpp list_widget.h ./tests/test.cpp)
target_link_libraries(Client
        Qt::Core
        Qt::Gui
        Qt::Network
        Qt::Widgets
        )

