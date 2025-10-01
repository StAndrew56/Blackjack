cmake_minimum_required(VERSION 3.16)

project(Blackjack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia Test)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(WIN32)
    set(RC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Blackjack
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        BJpngs.qrc
        test.cpp test.h
        Cards.cpp Cards.h
        Dealer.cpp Dealer.h Deck.cpp Deck.h
        Suit.cpp Suit.h
        User.cpp User.h
        resources.qrc
        ${RC_FILE}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Blackjack APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Blackjack SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Blackjack
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Blackjack PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia Qt${QT_VERSION_MAJOR}::Test)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Blackjack)
endif()
set_target_properties(Blackjack PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Blackjack
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Blackjack)
endif()

# Unit Testing - this connects Unit Test build to Project build
include(CTest) # Makes BUILD_TESTING CMake option available in Project Build settings
option(BUILD_TESTS "Build the unit tests" ON)

if (BUILD_TESTS) # If BUILD_TESTS option is on in Project Build settings
    add_subdirectory(tests) # Enable access to tests directory
endif()
#add_subdirectory(tests) # Adds tests directory to project


