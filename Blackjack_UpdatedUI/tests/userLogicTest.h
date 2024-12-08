#ifndef USERLOGICTEST_H
#define USERLOGICTEST_H

#include <QObject>
#include <QtTest/QtTest>
//#include <QString>
using namespace std;

class TestUserLogic : public QObject {
    Q_OBJECT

private slots:
    // Define your test cases
    void testUserPlaceBet();
    void testUserHit();
    //void testUserCardVal();
};

#endif // USERLOGICTEST_H
