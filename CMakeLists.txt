cmake_minimum_required(VERSION 3.5)

project(ControlTheory VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ControlTheory
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(ControlTheory SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ControlTheory
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# ✅ Add subdirectory for math library inside libs/
add_subdirectory(libs/MathsAlgebreLineaire)

# ✅ Link the MathMethods library
target_link_libraries(ControlTheory PRIVATE MathMethods)

# ✅ Link Qt Widgets
target_link_libraries(ControlTheory PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# macOS Bundle ID for Qt < 6.1
if(Qt${QT_VERSION_MAJOR}_VERSION VERSION_LESS 6.1.0)
    set_target_properties(ControlTheory PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ControlTheory
    )
endif()

# App metadata
set_target_properties(ControlTheory PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
)

if(WIN32)
    set_target_properties(ControlTheory PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# Installation
include(GNUInstallDirs)
install(TARGETS ControlTheory
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize for Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ControlTheory)
endif()
