#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"
#include "Dealer.h"
#include "Deck.h"
#include <QList>
#include <QLabel>
#include <QtMultimedia>
#include <QFileDialog>
#include <QStyle>


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
    QList<QLabel*> splitCardLabels;
    void setBackgroundImage();
    void setButtons();
    void setGraphic();
    QTimer *standTimer;
    int lastDisplayedUserCardIndex = 0;
    int lastDisplayedDealerCardIndex = 0;
    int lastDisplayedSplitCardIndex = 0;
    QMediaPlayer *M_Player;
    QMediaPlayer *M_Player2;
    QAudioOutput *volumeControl;
    QAudioOutput *controlSFX;
    bool isSplitHandDisplayed = false;
    bool isPlayingSplitHand = false;
    bool hasSplit = false;




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
    void on_horizontalSlider_valueChanged(int value);
    void on_muteButton_clicked(bool checked);
    void updateUserHandValDisplay();
    void updateDealerHandValDisplay();
    void updateSplitHandValDisplay();
    void onSplitButton();
    void displaySplitHand();
    void animateSplitCardToWidget(QWidget* targetWidget, const QString &cardPath, int width, int height);

    void showFloatingMessage(const QString &message);
};
#endif // MAINWINDOW_H


void on_horizontalSlider_valueChanged(int value);
void on_muteButton_clicked(bool checked);
