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
    void testDealCards();
    void testDealerCardCompareWin();
    void testDealerCardCompareTie();
    void testDealerCardCompareLose();
    //void testDealerHit();
};

#endif // DEALERLOGICTEST_H
