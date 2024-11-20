#include "mainwindowTest.h"

void TestMainWindow::testWindowTitle() {
    mainWindow mainWindow;
    QVERIFY(mainWindow.windowTitle() == "Expected Title");
}

void TestMainWindow::testDefaultSize() {
    mainWindow mainWindow;
    QCOMPARE(mainWindow.size(), QSize(800, 600));
}
