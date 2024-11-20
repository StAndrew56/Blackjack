enable_testing()

# Add test executable
add_executable(BlackjackTests
    testMain.cpp testMain.h
    mainwindowTest.cpp mainwindowTest.h
    BJLogicTest.cpp BJLogicTest.h
)
#Include project directory for finding project's files
target_include_directories(BlackjackTests PRIVATE ${CMAKE_SOURCE_DIR})

# Link test executable with Qt Test and the main application library (if needed)
find_package(Qt6 REQUIRED COMPONENTS Test)
find_package(Qt6 REQUIRED COMPONENTS Test Widgets)
target_link_libraries(BlackjackTests PRIVATE Qt6::Test Qt6::Widgets)
target_link_libraries(BlackjackTests PRIVATE Qt6::Test)

# Register the test with CTest
add_test(NAME BlackjackTests COMMAND testBlackjack)
