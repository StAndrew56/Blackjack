#ifndef BJLOGICTEST_H
#define BJLOGICTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "Dealer.h"

class TestMainWindow : public QObject {
    Q_OBJECT

private slots:
    // Define your test cases
    void testDealer();
    void testDealerCardCompare();
};

#endif // TEST_MAINWINDOW_H
