enable_testing()

# Link test executable with Qt Test and the main application library (if needed)
find_package(Qt6 REQUIRED COMPONENTS Test)
find_package(Qt6 REQUIRED COMPONENTS Test Widgets)

# Add test executable
add_executable(BlackjackTests
    #testMain.cpp testMain.h
    #mainwindowTest.cpp mainwindowTest.h
    dealerLogicTest.cpp dealerLogicTest.h
)

target_link_libraries(BlackjackTests PRIVATE Qt6::Test Qt6::Widgets)
#target_link_libraries(BlackjackTests PRIVATE Qt6::Test)

#Include project directory for finding project's files
#target_include_directories(BlackjackTests PRIVATE ${CMAKE_SOURCE_DIR})

target_sources(BlackjackTests PRIVATE
    ${CMAKE_SOURCE_DIR}/Suit.h
    ${CMAKE_SOURCE_DIR}/Suit.cpp

    ${CMAKE_SOURCE_DIR}/Cards.h
    ${CMAKE_SOURCE_DIR}/Cards.cpp

    ${CMAKE_SOURCE_DIR}/Dealer.h
    ${CMAKE_SOURCE_DIR}/Dealer.cpp

    ${CMAKE_SOURCE_DIR}/User.h
    ${CMAKE_SOURCE_DIR}/User.cpp

    ${CMAKE_SOURCE_DIR}/Deck.h
    ${CMAKE_SOURCE_DIR}/Deck.cpp
)

# Register the test with CTest
add_test(NAME BlackjackTests COMMAND testBlackjack)
