//#ifndef TEST_MAINWINDOW_H
//#define TEST_MAINWINDOW_H

#ifndef MAINWINDOWTEST_H
#define MAINWINDOWTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "mainwindow.h"

class TestMainWindow : public QObject {
    Q_OBJECT

private slots:
    // Define your test cases
    void testWindowTitle();
    void testDefaultSize();
};

#endif // TEST_MAINWINDOW_H
