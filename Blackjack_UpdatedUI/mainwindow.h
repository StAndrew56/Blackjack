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
    void setBackgroundImage();
    void setButtons();
    void setGraphic();




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
    void displayCardProperly(const QString &cardPath, QWidget *parentWidget, int width, int height);  // Declare the display function
    void displayPlayerHand();
    void onHitButtonClicked();
    void animateCardToWidget(QWidget* targetWidget, const QString &cardPath, int width, int height);
};
#endif // MAINWINDOW_H
