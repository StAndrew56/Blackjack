#include <QTest>
#include "dealerLogicTest.h"  // Include the test header for Dealer
#include "userLogicTest.h"    // Include the test header for User
// Add more test headers as needed

int main(int argc, char** argv) {
    int status = 0;

    {
        TestDealerLogic dealerTest;
        status |= QTest::qExec(&dealerTest, argc, argv);
    }

    {
        TestUserLogic userTest;
        status |= QTest::qExec(&userTest, argc, argv);
    }

    return status;
}
