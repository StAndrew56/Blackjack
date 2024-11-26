#ifndef TESTMAIN_H
#define TESTMAIN_H

#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include "Dealer.h"

class TestMainLogic{

public:
    // Define your test cases
    void testPTurnResult(); //Player Turn result
    void testDTurnResult(); //Dealer Turn result
    void testEndRoundResult(); //End result
};

#endif // TESTMAIN_H
