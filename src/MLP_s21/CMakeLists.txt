cmake_minimum_required(VERSION 3.5)

project(MLP_s21 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/Users/otttisss/Qt/6.4.2/macos/lib/cmake")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Charts Core)

include_directories(
        ${CMAKE_SOURCE_DIR}/logic
        ${CMAKE_SOURCE_DIR}/graphics
        ${CMAKE_SOURCE_DIR}/controller
        ${CMAKE_SOURCE_DIR}/forms
        ${CMAKE_SOURCE_DIR}/qrc
)

set(CMAKE_AUTOUIC_SEARCH_PATHS forms qrc)

set(SOURCES
        logic/Emnist_sample.cpp
        logic/GraphNet.cpp
        logic/LaunchMode.cpp
        logic/Matrix.cpp
        logic/MatrixNet.cpp
        logic/Net.cpp
        graphics/learningmainwindow.cpp
        graphics/learningstartwindow.cpp
        graphics/main.cpp
        graphics/mainwindow.cpp
        graphics/paintscene.cpp
        graphics/secondwindow.cpp
        graphics/settingswindow.cpp
        controller/controller.cpp
)

set(HEADERS
        logic/headers/Emnist_sample.hpp
        logic/headers/GraphNet.hpp
        logic/headers/Matrix.hpp
        logic/headers/MatrixNet.hpp
        logic/headers/Net.hpp
        graphics/headers/learningmainwindow.hpp
        graphics/headers/learningstartwindow.hpp
        graphics/headers/mainwindow.h
        graphics/headers/paintscene.hpp
        graphics/headers/secondwindow.hpp
        graphics/headers/settingswindow.h
        controller/controller.hpp
)

set(FORMS
        forms/learningmainwindow.ui
        forms/learningstartwindow.ui
        forms/mainwindow.ui
        forms/secondwindow.ui
        forms/settingswindow.ui
)

set(QRC
    qrc/sources.qrc)

set(PROJECT_SOURCES
    ${SOURCES}
        ${HEADERS}
        ${FORMS}
        ${QRC}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MLP_s21
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MLP_s21 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MLP_S21 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MLP_s21
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MLP_s21 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts Qt${QT_VERSION_MAJOR}::Core)

set_target_properties(MLP_s21 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MLP_s21)
endif()
