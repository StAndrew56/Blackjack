#ifndef USERLOGICTEST_H
#define USERLOGICTEST_H

#include <QObject>
#include <QtTest/QtTest>
using namespace std;

class TestUserLogic : public QObject {
    Q_OBJECT

    private slots:
    void testHit_AddCard();
    void testIncreaseBet_Valid();
    void testIncreaseBet_NotValid();
    void testBlackJack();
    void testDoubleDown();
};

#endif // USERLOGICTEST_H
