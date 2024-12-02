enable_testing()

# Link test executable with Qt Test and the main application library (if needed)
find_package(Qt6 REQUIRED COMPONENTS Test)
find_package(Qt6 REQUIRED COMPONENTS Test Widgets)

# Add test executable
#testMain.cpp testMain.h
#mainwindowTest.cpp mainwindowTest.h
add_executable(BlackjackTests
    dealerLogicTest.cpp dealerLogicTest.h
)

target_link_libraries(BlackjackTests PRIVATE Qt6::Core Qt6::Test Qt6::Widgets)
#target_link_libraries(BlackjackTests PRIVATE Qt6::Test)

#Include project directory for finding project's files
target_sources(BlackjackTests PRIVATE
    #${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/Suit.cpp
    ${CMAKE_SOURCE_DIR}/Cards.cpp
    ${CMAKE_SOURCE_DIR}/Dealer.cpp
    ${CMAKE_SOURCE_DIR}/User.cpp
    ${CMAKE_SOURCE_DIR}/Deck.cpp
    ${CMAKE_SOURCE_DIR}/mainwindow.cpp
)
# Root directory to access the headers
target_include_directories(BlackjackTests PRIVATE ${CMAKE_SOURCE_DIR})


# Register the test with CTest
add_test(NAME BlackjackTests COMMAND testBlackjack)
#qt_add_test(BlackjackTests)
