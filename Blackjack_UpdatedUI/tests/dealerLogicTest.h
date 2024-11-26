#ifndef DEALERLOGICTEST_H
#define DEALERLOGICTEST_H

#include <QObject>
#include <QtTest/QtTest>
//#include <QString>
using namespace std;

class TestDealerLogic : public QObject {
    Q_OBJECT

private slots:
    // Define your test cases
    void testDealer();
    void testDealerCardCompare();
};

#endif // DEALERLOGICTEST_H
