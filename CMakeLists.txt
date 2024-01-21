cmake_minimum_required(VERSION 3.5)

project(CarDashboard VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp



)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CarDashboard
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Widgets/turnleft.h Widgets/turnleft.cpp
        Widgets/turnright.h Widgets/turnright.cpp
        Widgets/bonnet.h Widgets/bonnet.cpp
        Widgets/boot.h Widgets/boot.cpp
        Widgets/dippedbeam.h Widgets/dippedbeam.cpp
        Widgets/highbeam.h Widgets/highbeam.cpp
        Widgets/foglight.h Widgets/foglight.cpp
        Widgets/battery.h Widgets/battery.cpp
        Widgets/door.h Widgets/door.cpp
        Widgets/engine.h Widgets/engine.cpp
        Widgets/oil.h Widgets/oil.cpp
        Widgets/traction.h Widgets/traction.cpp
        Widgets/temperaturegauge.h Widgets/temperaturegauge.cpp
        Widgets/fuelgauge.h Widgets/fuelgauge.cpp
        Widgets/speedometer.h Widgets/speedometer.cpp
        Widgets/revolutiongauge.h Widgets/revolutiongauge.cpp
        Controls/dashcontrol.h Controls/dashcontrol.cpp
        DashboardInterface/dashboardinterface.h DashboardInterface/dashboardinterface.cpp
        Controls/carsliders.h Controls/carsliders.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CarDashboard APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CarDashboard SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CarDashboard
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CarDashboard PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CarDashboard)
endif()
set_target_properties(CarDashboard PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CarDashboard
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CarDashboard)
endif()
