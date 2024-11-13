#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include "User.h"
#include "User.h"
#include "Dealer.h"
#include <QMessageBox>

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
    , dealer(new Dealer())
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
    connect(ui->pushButton_6, &QPushButton::clicked, this, &mainWindow::onHitButtonClicked);
    updateBalanceDisplay();

    deck.createDeck();
    deck.shuffle();
    dealer->dealCards(user->userHand, deck.deckOfCards, user);

}

void setGraphic(){

}
void mainWindow::showErrorMessage(const QString &message) {
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Error");
    msgBox.setText(message);

    msgBox.setStyleSheet("QMessageBox { font-family: S  egoe; font-size: 20px; border: 3px solid red; border-image: none; }"
                         "QMessageBox QLabel { font-family: Segoe; font-size: 20px; color: black; border-image: none; }"
                         "QMessageBox QPushButton { font-family: Segoe; font-size: 20px; border-image: none; }");
    msgBox.addButton(QMessageBox::Ok);

    msgBox.exec();
}
void mainWindow::onOneDollarBet() {
    user->increaseBet(1); // Call the placeBet method from User class

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
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
void mainWindow::onSubmitBet() {
    // Ensure a bet is placed
    if (user->betVal <= 0) {
        return;
    }
    user->userHand.clear();

    dealer->dealCards(user->userHand, deck.deckOfCards, user);
    user->trueRank();
    qDebug() << "Current handVal: " << user->handVal;
    displayPlayerHand();

    //pays player for getting "BlackJack" 21 off original deal.
    if(user->handVal == 21){
        showErrorMessage("BlackJack! Congratulations!");
        user->pay();
        user->betVal = 0;
        //clear each widget after a bust
        for (int i = 0; i < cardLabels.size(); ++i) {
            delete cardLabels[i];  // Delete each QLabel
        }
        cardLabels.clear();//clear the label of the card png

        //if you get 21 re-create the deck
        deck.killDeck();
        deck.createDeck();
        deck.shuffle();
        //call dealer to show cards after this comment

        //code here.
    }
}

void mainWindow::onHitButtonClicked() {
    qDebug() << "Hit has been SMACKED!!!";
    //checks if bet is placed, if not bet is placed will send error
    if(user->betVal == 0){
        showErrorMessage("You need to place a bet first!");
        return;
    }
    //prevents users from hitting on 21.
    if(user->handVal == 21){
        showErrorMessage("You already have 21! Press stand to continue.");
        return;
    }

    // Add a card to the user's hand
    user->hit(deck);  // Player hits and gets another card

    // Get the index of the newly added card
    int newCardIndex = user->userHand.size() - 1;  // The last card in the hand is the new one
    QString cardPath = user->userHand[newCardIndex].getCardImagePath();


    QList<QWidget*> userWidgets =   {ui->widget1, ui->widget2, ui->widget3, ui->widget4, ui->widget5, ui->widget6,
                                    ui->widget7, ui->widget8, ui->widget9, ui->widget10, ui->widget11};

    // Check if there is a corresponding widget to display the new card
    if (newCardIndex < userWidgets.size()) {
        // Only animate the newly added card to the corresponding widget
        animateCardToWidget(userWidgets[newCardIndex], cardPath, 100, 150);
    }
    qDebug() << "Current handVal: " << user->handVal;

    // Check if the user has busted after hitting
    if (user->handVal > 21) {
        qDebug() << "Player busted!";
        showErrorMessage("You busted!");
        user->clearUserHand();//clear the hand from the vector
        user->bust();//deal with loss of currency

        //clear each widget after a bust
        for (int i = 0; i < cardLabels.size(); ++i) {
            delete cardLabels[i];  // Delete each QLabel
        }
        cardLabels.clear();//clear the label of the card png

        //if you bust re-create the deck
        deck.killDeck();
        deck.createDeck();
        deck.shuffle();
    }

}


void mainWindow::displayCardProperly(const QString &cardPath, QWidget *parentWidget, int width = 100, int height = 150) {
    QPixmap cardPixmap(cardPath);  // Load the card image

    if (cardPixmap.isNull()) {
        qDebug() << "Failed to load image for card: " << cardPath;
    } else {
        QLabel* cardLabel = new QLabel(parentWidget);  // Create a QLabel to display the card

        // Scale the card image and set it to the QLabel
        QPixmap scaledPixmap = cardPixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        cardLabel->setPixmap(scaledPixmap);

        // Set a fixed size for the QLabel to prevent clipping
        cardLabel->setFixedSize(width, height);
        cardLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cardLabel->setAlignment(Qt::AlignCenter);

        // Add the QLabel to the layout of the parent widget
        if (!parentWidget->layout()) {
            QVBoxLayout* layout = new QVBoxLayout(parentWidget);
            parentWidget->setLayout(layout);  // Apply a layout if it doesn't already exist
        }

        parentWidget->layout()->addWidget(cardLabel);  // Add QLabel to the parent layout
        cardLabel->show();  // Make sure the card is visible
        qDebug() << "Card displayed successfully for: " << cardPath;
    }
}



void mainWindow::displayPlayerHand() {
    qDebug() << "User hand size:" << user->userHand.size();  // Output the number of cards in thui->widget4ui->widget4ui->widget4ui->widget4ui->widget4e user's hand

    // Assuming you have user widgets named widget1, widget2, widget3, etc.
    QList<QWidget*> userWidgets =  {ui->widget1, ui->widget2, ui->widget3, ui->widget4, ui->widget5, ui->widget6,
                                    ui->widget7, ui->widget8, ui->widget9, ui->widget10, ui->widget11};

    for (int i = 0; i < user->userHand.size(); ++i) {
        QString cardPath = user->userHand[i].getCardImagePath();  // Get the image path for the current card

        qDebug() << "Card " << i + 1 << ": " << cardPath;

        if (i < userWidgets.size()) {  // Make sure there is a corresponding widget
            animateCardToWidget(userWidgets[i], cardPath, 100, 150);
        }
    }
}


void mainWindow::animateCardToWidget(QWidget* targetWidget, const QString &cardPath, int width, int height) {
    // Load the card image
    QPixmap cardPixmap(cardPath);

    if (cardPixmap.isNull()) {
        qDebug() << "Failed to load image for card: " << cardPath;
        return;
    }

    // Create a QLabel to display the card
    QLabel* cardLabel = new QLabel(this);

    // Scale the card image and maintain aspect ratio
    QPixmap scaledPixmap = cardPixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    cardLabel->setPixmap(scaledPixmap);

    // Set the QLabel size to match the scaled image size
    int adjustedWidth = scaledPixmap.width();
    int adjustedHeight = scaledPixmap.height();

    cardLabel->setFixedSize(adjustedWidth, adjustedHeight);
    cardLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    cardLabel->setAlignment(Qt::AlignCenter);

    // Calculate the geometry for the starting point off-screen or custom
    QRect startGeometry(-100, -100, adjustedWidth, adjustedHeight);
    cardLabel->setGeometry(startGeometry);
    cardLabel->show();

    // Create QPropertyAnimation to move the card to the target widget
    QPropertyAnimation* animation = new QPropertyAnimation(cardLabel, "geometry");
    animation->setDuration(750);

    // Calculate the geometry for the target widget, centering the card inside the target
    QRect targetGeometry = targetWidget->geometry();
    int targetX = targetGeometry.x() + (targetGeometry.width() - adjustedWidth) / 2;  // Center horizontally
    int targetY = targetGeometry.y() + (targetGeometry.height() - adjustedHeight) / 2;  // Center vertically

    animation->setStartValue(startGeometry);
    animation->setEndValue(QRect(targetX, targetY, adjustedWidth, adjustedHeight));  // Move to centered target

    // Start the animation
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    //store the cardLabel
    cardLabels.append(cardLabel);

    qDebug() << "Card animation started for: " << cardPath;
}






/*
void mainWindow::displayPlayerHand() {
    // Load the card image directly by specifying the file path
    QString cardPath = ":/cards/diamonds_A.png";  // Use the correct image path
    QPixmap cardPixmap(cardPath);  // Load the card image

    if (cardPixmap.isNull()) {
        qDebug() << "Failed to load image for card: " << cardPath;
    } else {
        // Create a QLabel to display the card
        QLabel* cardLabel = new QLabel(this);

        // Set a fixed size for the QLabel that matches the card size
        cardLabel->setFixedSize(100, 150);  // Set QLabel to be the exact size of the card

        // Scale the card image if needed, maintaining aspect ratio
        QPixmap scaledPixmap = cardPixmap.scaled(100, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        cardLabel->setPixmap(scaledPixmap);

        // Set size policy and alignment
        cardLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);  // Make sure the label doesn’t shrink
        cardLabel->setAlignment(Qt::AlignCenter);

        // Check if a layout exists for stackedWidget_3, if not, create one
        if (!ui->stackedWidget_3->layout()) {
            QVBoxLayout* stackedLayout = new QVBoxLayout(ui->stackedWidget_3);
            ui->stackedWidget_3->setLayout(stackedLayout);  // Apply the layout
        }

        // Add the QLabel (with the card) to the stacked widget's layout
        ui->stackedWidget_3->layout()->addWidget(cardLabel);

        // Make sure the QLabel is visible
        cardLabel->show();

        qDebug() << "Card displayed successfully.";
        qDebug() << cardPath;
    }
}
*/












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

