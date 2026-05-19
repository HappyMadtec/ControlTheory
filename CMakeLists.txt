cmake_minimum_required(VERSION 3.5)

project(ControlTheory VERSION 0.1 LANGUAGES CXX)

# === Qt Setup ===
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# === Sources ===
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# === Executable Definition ===
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ControlTheory
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        fileparser.h fileparser.cpp
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

# === Add Subdirectories ===
#add_subdirectory(libs/MathsAlgebreLineaire)
#add_subdirectory(libs/googletest)

# === Link Libraries to Main App ===
target_link_libraries(ControlTheory PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)

# === macOS & Windows Bundle Settings ===
if(Qt${QT_VERSION_MAJOR}_VERSION VERSION_LESS 6.1.0)
    set_target_properties(ControlTheory PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ControlTheory
    )
endif()

set_target_properties(ControlTheory PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
)

#if(WIN32)
#    set_target_properties(ControlTheory PROPERTIES WIN32_EXECUTABLE TRUE)
#endif()

# === Install ControlTheory App ===
include(GNUInstallDirs)
install(TARGETS ControlTheory
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# === Finalize Qt 6 Executable ===
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ControlTheory)
endif()

# qt_finalize_executable sets WIN32_EXECUTABLE back to TRUE on Windows,
# so we override it after finalization
if(WIN32)
    set_target_properties(ControlTheory PROPERTIES WIN32_EXECUTABLE FALSE)
endif()

# === Google Test (fetched automatically) ===
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# === Unit Tests ===
enable_testing()

add_executable(Tests
    Tests/Test_exmaple.cpp
)

target_link_libraries(Tests PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    gtest
    gtest_main
)

add_test(NAME RunUnitTests COMMAND Tests)
