#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "User.h"
#include <QMessageBox>

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
    , user(new User)
{
    ui->setupUi(this);
    //setBackgroundImage();
    //setButtons();

    connect(ui->pushButton, &QPushButton::clicked, this, &mainWindow::onOneDollarBet);
    connect(user, &User::betPlaced, this, &mainWindow::updateBetDisplay);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &mainWindow::onFiveDollarBet);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &mainWindow::onTenDollarBet);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &mainWindow::onTwentyDollarBet);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &mainWindow::onHundredDollarBet);
    connect(ui->pushButton_10, &QPushButton::clicked, user, &User::clearBet);
    connect(user, &User::balanceUpdated, this, &mainWindow::updateBalanceDisplay);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &mainWindow::onSubmitBet);
    connect(user, &User::actionError, this, &mainWindow::showErrorMessage);

    updateBalanceDisplay();
}

void setGraphic(){

}
void mainWindow::showErrorMessage(const QString &message) {
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Error");
    msgBox.setText(message);

    msgBox.setStyleSheet("QMessageBox { font-family: Segoe; font-size: 20px; border: 3px solid red; border-image: none; }"
                         "QMessageBox QLabel { font-family: Segoe; font-size: 20px; color: black; border-image: none; }"
                         "QMessageBox QPushButton { font-family: Segoe; font-size: 20px; border-image: none; }");
    msgBox.addButton(QMessageBox::Ok);

    msgBox.exec();
    //QMessageBox::warning(this, "Error", message); // Use a message box to show the error
}
void mainWindow::onOneDollarBet() {
    user->increaseBet(1); // Call the placeBet method from User class

    qDebug() << "Current Balance: $" << user->balance; // Accessing balance directly
    qDebug() << "Current Bet: $" << user->betVal; // Accessing betVal directly
}
void mainWindow::onFiveDollarBet() {
    user->increaseBet(5);

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onTenDollarBet() {
    user->increaseBet(10);

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onTwentyDollarBet() {
    user->increaseBet(20);

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onHundredDollarBet() {
    user->increaseBet(100);

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}
void mainWindow::updateBetDisplay(int bet) {
    // Update the display label to show the current bet amount
    ui->label_691->setText(QString("Current Bet: $%1").arg(bet));
}
void mainWindow::updateBalanceDisplay() {
    ui->label->setText(QString("Current Balance: $%1").arg(user->balance)); // Update balance label
}
void mainWindow::onSubmitBet() {//_)_)_)_)_)_)_)_)_)_)_)_)_)-0-0-0-0-0-0-0_)_)_)_0-0-0-0-0 fix this once we have dealer class
    // Ensure a bet is placed
    if (user->betVal <= 0) {
        // Emit an error message if no bet is placed
        //emit showErrorMessage("Please place a bet before submitting.");
        return;
    }

    // Proceed to deal cards
    //dealCards(); game loop starts here!!@!@!@!@!@!@!@@!@!@!@@!@!@!@@!@!@!@@!@!@!@!@@!@!@!@!@@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@!@
}

void mainWindow::resizeEvent(QResizeEvent *event)//called when resized
{
    QMainWindow::resizeEvent(event);

}

void mainWindow::setBackgroundImage()//handles the board, also known as the background image
{

}
void mainWindow::setButtons(){

}
mainWindow::~mainWindow()
{
    delete ui;
}

