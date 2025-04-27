cmake_minimum_required(VERSION 3.15...4.0)
project(Vidito)

set(CMAKE_CXX_STANDARD 17)

set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_add_executable(Vidito
    main.cpp
)

qt_add_qml_module(Vidito
    URI hello
    VERSION 1.0
    QML_FILES main.qml
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml
)

target_link_libraries(Vidito
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)
