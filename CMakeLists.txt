cmake_minimum_required(VERSION 3.15...4.0)
project(Vidito VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

set(PROJECT_SOURCES
    src/main.cpp
    src/editorstate.cpp
    src/editorstate.h
    src/components/timedisplay.cpp
    src/components/timedisplay.h
)

qt_add_executable(Vidito
    ${PROJECT_SOURCES}
)

target_include_directories(Vidito
    PRIVATE
    src
)

qt_add_qml_module(Vidito
    URI ui
    VERSION 1.0
    QML_FILES qml/main.qml
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml_out
)

target_link_libraries(Vidito
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)
