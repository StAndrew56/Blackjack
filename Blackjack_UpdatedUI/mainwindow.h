#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"
#include "Dealer.h"
#include "Deck.h"
#include <QList>
#include <QLabel>



QT_BEGIN_NAMESPACE
namespace Ui {
class mainWindow;
}
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    Ui::mainWindow *ui;
    User *user;
    Dealer *dealer;  // Add this line to declare dealer as a pointer
    Deck deck;       // Deck object
    QList<QLabel*> cardLabels;
    QList<QLabel*> dealerCardLabels;
    void setBackgroundImage();
    void setButtons();
    void setGraphic();
    QTimer *standTimer;
    int lastDisplayedUserCardIndex = 0;
    int lastDisplayedDealerCardIndex = 0;






private slots:
    void showErrorMessage(const QString &message);
    void updateBetDisplay(int bet);
    void onOneDollarBet();
    void onFiveDollarBet();
    void onTenDollarBet();
    void onTwentyDollarBet();
    void onHundredDollarBet();
    void updateBalanceDisplay();
    void onSubmitBet();
    void displayPlayerHand();
    void onHitButtonClicked();
    void animateCardToWidget(QWidget* targetWidget, const QString &cardPath, int width, int height);
    void animateDealerCardToWidget(QWidget* targetWidget, const QString &cardPath, int width = 100, int height = 150, bool faceDown = false);  // New function for dealer
    void displayDealerHand();
    void onDoubleDownButton();
    void onStandButton();
    void dealerStandStep();
    void onEndGame();
    void clearCardsDisplayed();

};
#endif // MAINWINDOW_H
