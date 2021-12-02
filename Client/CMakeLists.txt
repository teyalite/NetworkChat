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

add_executable(Client main.cpp ClientWindow.cpp ClientWindow.h TopWidget.cpp TopWidget.h BottomWidget.cpp BottomWidget.h LogoWidget.cpp LogoWidget.h ListWidget.cpp ListWidget.h)
target_link_libraries(Client
        Qt::Core
        Qt::Gui
        Qt::Network
        Qt::Widgets
        )

