#include <QCoreApplication>
#include <QTest>
#include "userLogicTest.h"
#include "dealerLogicTest.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    int status = 0;

    // Run each test class and accumulate results
    {
        TestDealerLogic dealerLogicTests;
        status |= QTest::qExec(&dealerLogicTests, argc, argv);
    }

    {
        TestUserLogic userLogicTests;
        status |= QTest::qExec(&userLogicTests, argc, argv);
    }

    return status;  // Non-zero status means a test failed
}
