#include <QtTest/QtTest>

// Include all test classes
#include "mainwindowTest.h"

int main(int argc, char** argv) {
    int status = 0;

    // Run each test class
    {
        TestMainWindow test;
        status |= QTest::qExec(&test, argc, argv);
    }

    return status;
}
