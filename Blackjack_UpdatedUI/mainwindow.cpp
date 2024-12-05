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
#include <QTimer>
#include <QMediaPlayer>
#include <QtMultimedia>
#include <QFileDialog>
#include <QStyle>
#include <QString>
#include <QSoundEffect>

//user's turn tracker
bool userTurn = true;

//muteButton toggle tracker
bool muted = false;

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
    , dealer(new Dealer())
    , user(new User)


{
    ui->setupUi(this);

    //music object pointers
    M_Player = new QMediaPlayer();
    volumeControl = new QAudioOutput();
    M_Player->setAudioOutput(volumeControl);

    //SFX objext pointers
    M_Player2 = new QMediaPlayer();
    controlSFX = new QAudioOutput();
    M_Player2->setAudioOutput(controlSFX);


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
    connect(ui->pushButton_9, &QPushButton::clicked, this, &mainWindow::onDoubleDownButton);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &mainWindow::onStandButton);
    connect(user, &User::updateUserHandVal, this, &mainWindow::updateUserHandValDisplay);
    connect(dealer, &Dealer::updateDealerHandVal, this, &mainWindow::updateDealerHandValDisplay);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &mainWindow::onSplitButton);



    updateBalanceDisplay();

    deck.createDeck();
    deck.shuffle();

    //music (free from https://pixabay.com/music/search/lofi%20chill/)
    //other sounds (free from https://pixabay.com/sound-effects/search/card-flip/)
    M_Player->setSource(QUrl("qrc:/sounds/musicFile"));
    volumeControl->setVolume(0.1);
    M_Player->play();
    M_Player->setLoops(QMediaPlayer::Infinite);




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
//mute button
void mainWindow::on_muteButton_clicked(bool checked) {
    if (checked) {
        volumeControl->setMuted(true);
    } else {
        volumeControl->setMuted(false);
    }
}

//--------------------------------------***********--------------------------------------

//--------------------------------------BET AMOUNTS--------------------------------------
void mainWindow::onOneDollarBet() {
    if(user->balance == 0){
        showFloatingMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
    user->increaseBet(1); // Call the placeBet method from User class
    }
    else{
        showFloatingMessage("You can't change your bet aftering start!");
    }
    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;

}
void mainWindow::onFiveDollarBet() {
    if(user->balance == 0){
        showFloatingMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
        user->increaseBet(5); // Call the placeBet method from User class
    }
    else{
        showFloatingMessage("You can't change your bet aftering start!");
    }
    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onTenDollarBet() {
    if(user->balance == 0){
        showFloatingMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
        user->increaseBet(10); // Call the placeBet method from User class
    }
    else{
        showFloatingMessage("You can't change your bet aftering start!");
    }

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onTwentyDollarBet() {
    if(user->balance == 0){
        showFloatingMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
        user->increaseBet(20); // Call the placeBet method from User class
    }
    else{
        showFloatingMessage("You can't change your bet aftering start!");
    }

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onHundredDollarBet() {
    if(user->balance == 0){
        showFloatingMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
        user->increaseBet(100); // Call the placeBet method from User class
    }
    else{
        showFloatingMessage("You can't change your bet aftering start!");
    }

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}




void mainWindow::onSubmitBet() {
    if(user->balance == 0 && user->betVal == 0){
        showErrorMessage("Out of money! Restart the game to get more.");
        return;
    }
    // Ensure a bet is placed
    if(user->userHand.size() == 0){
    if (user->betVal <= 0) {
        return;
    }
    user->userHand.clear();
    dealer->removeCards();
    clearCardsDisplayed();

    dealer->dealCards(user->userHand, deck.deckOfCards, user);


    qDebug() << "Current handVal: " << user->handVal;
    qDebug() << "tbvwayyyyyyyvabvaw";
    displayDealerHand();
    displayPlayerHand();
    updateUserHandValDisplay();

    // Sound during card deal
    M_Player2->setSource(QUrl("qrc:/sounds/shuffleSound"));
    M_Player2->play();
    controlSFX->setVolume(100);

    // Display user hand value
    //user->displayUserHandVal();

    // Turn off dealer hand value on deal
    ui->label_56->setText(QString(""));

    // User is dealt blackjack
    if (user->getUserHandTotal() == 21 && dealer->getHandValue() != 21){
        showErrorMessage("Blackjack! You win!");
        user->blackJack();
        user->betVal = 0;
        user->clearUserHand();

        userTurn = false;
        // Update the UI to show the new card
        displayDealerHand();
        // Display dealer hand value
        dealer->displayDealerHandVal();

        onEndGame();
        return;
    }
    // Dealer is dealt blackjack
    if(dealer->getHandValue() == 21 && user->getUserHandTotal() != 21){
        showErrorMessage("Dealer has blackjack... You Lose.");
        user->betVal = 0;
        user->clearUserHand();

        userTurn = false;
        // Update the UI to show the new card
        displayDealerHand();
        // Display dealer hand value
        dealer->displayDealerHandVal();

        onEndGame();
        return;
    }

    updateBetDisplay(user->betVal);
    updateBalanceDisplay();

    qDebug() << "New round started, cards dealt, and UI updated.";
    }
    else{
        showFloatingMessage("Finish the current hand first!");
    }
}



//--------------------------------------BET AMOUNTS--------------------------------------

//--------------------------------------***********--------------------------------------
//--------------------------------------***********--------------------------------------


//--------------------------------------BUTTONCLICK--------------------------------------
void mainWindow::onHitButtonClicked() {
    // Ensure the user has placed a bet
    if (user->betVal == 0) {
        showErrorMessage("You need to place a bet first!");
        return;
    }

    // Check if playing the main hand
    if (!isPlayingSplitHand) {
        // Ensure there is no split hand before switching
        if (!user->splitHand.empty() && user->getUserHandTotal() > 21) {
            isPlayingSplitHand = true;
            showErrorMessage("You busted on your main hand. Now playing your split hand.");
            displaySplitHand();
            return;
        }

        // Prevent hitting on a perfect main hand
        if (user->getUserHandTotal() == 21) {
            showFloatingMessage("You already have 21 on your main hand! Press stand to continue.");
            return;
        }

        // Hit for the main hand
        user->hit(deck);
        updateUserHandValDisplay();

        //sound during player Hit
        M_Player2->setSource(QUrl("qrc:/sounds/singleFlipSound"));
        M_Player2->play();
        controlSFX->setVolume(100);

        // Animate and display the card
        int newCardIndex = user->userHand.size() - 1;
        QString cardPath = user->userHand[newCardIndex].getCardImagePath();
        QList<QWidget*> userWidgets = {ui->widget1, ui->widget2, ui->widget3, ui->widget4, ui->widget5, ui->widget6};
        if (newCardIndex < userWidgets.size()) {
            animateCardToWidget(userWidgets[newCardIndex], cardPath, 100, 150);
        }

        // Check for bust on the main hand
        if (user->getUserHandTotal() > 21) {
            showErrorMessage("You busted on your main hand!");
            if (!user->splitHand.empty()) {
                isPlayingSplitHand = true;  // Switch to the split hand if it exists
                displaySplitHand();
                showErrorMessage("Now playing your split hand.");
            } else {

                onEndGame();  // End the game if there's no split hand
            }
        }
    } else {
        // Ensure there is a valid split hand
        if (user->splitHand.empty()) {
            showErrorMessage("No split hand to play!");
            return;
        }

        // Prevent hitting on a perfect split hand
        if (user->getSplitHandTotal() == 21) {
            showFloatingMessage("You already have 21 on your split hand! Press stand to continue.");
            return;
        }

        // Hit for the split hand
        user->hitSplit(deck);
        updateSplitHandValDisplay();

        // Animate and display the card
        int newCardIndex = user->splitHand.size() - 1;
        QString cardPath = user->splitHand[newCardIndex].getCardImagePath();
        QList<QWidget*> splitWidgets = {ui->splitWidget1, ui->splitWidget2, ui->splitWidget3, ui->splitWidget4, ui->splitWidget5};
        if (newCardIndex < splitWidgets.size()) {
            animateSplitCardToWidget(splitWidgets[newCardIndex], cardPath, 100, 150);
        }

        // Check for bust on the split hand
        if (user->getSplitHandTotal() > 21) {
            showErrorMessage("You busted on your split hand!");
            isPlayingSplitHand = false;  // End split hand play
            onEndGame();
        }
    }
}

void mainWindow::onDoubleDownButton(){
    // Checks if user has 2 cards and enough money
    if(user->betVal == 0){
        showFloatingMessage("Double down is available only on the initial deal with enough balance.");
        return;
    }
    if (user->userHand.size() == 2 && user->balance >= user->betVal)
    {
        user->doubleDown();  // Double current bet amount
        updateBalanceDisplay();  // Show new current money on UI
        updateBetDisplay(user->betVal);  // Show new current bet amount on UI

        // Deal only one card to user
        user->hit(deck);
        displayPlayerHand();
        updateUserHandValDisplay();

        //user->displayUserHandVal();

        //sound during player DD
        M_Player2->setSource(QUrl("qrc:/sounds/singleFlipSound"));
        M_Player2->play();
        controlSFX->setVolume(100);

        // Check if the player has busted after doubling down
        if (user->getUserHandTotal() > 21) {
            userTurn = false;
            displayDealerHand();
            // Display dealer hand value
            dealer->displayDealerHandVal();

            qDebug() << "Player busted after double down!";
            showErrorMessage("You busted!");
            user->clearUserHand();//clear the hand from the vector
            onEndGame();
        }
        // Player finishes turn for rest of game and dealer takes over
        else
        {
            qDebug() << "Player doubled down and stands.";
            onStandButton();
        }
    }
    else
    {
        showFloatingMessage("Double down is available only on the initial deal with enough balance.");
    }
}





void mainWindow::onStandButton() {
    if (user->betVal > 0) {
        // If playing the starting hand, switch to the split hand after standing
        if (hasSplit && !isPlayingSplitHand) {
            qDebug() << "Finished playing the starting hand. Switching to split hand.";
            isPlayingSplitHand = true;
            showErrorMessage("Now playing the split hand.");
        } else {
            // If playing the split hand, proceed with the dealer's turn
            dealer->stand();  // Trigger dealer logic

            // Add a delay animation in between cards to prevent all of them showing up at the same time
            standTimer = new QTimer(this);
            connect(standTimer, &QTimer::timeout, this, &mainWindow::dealerStandStep);
            standTimer->start(750);  // 750 ms delay between each dealer hit animation
        }
    } else {
        showFloatingMessage("Please place a bet before standing.");
    }
}




void mainWindow::dealerStandStep() {
    userTurn = false;
    // Getter to get dealer hand value
    if (dealer->getDealerHandVal() >= 17 || dealer->getDealerHandVal() > 21)
    {
        // Stop timer if conditions met
        standTimer->stop();
        delete standTimer;
        standTimer = nullptr;

        displayDealerHand();
        // Display dealer hand value
        dealer->displayDealerHandVal();


        // Check who winner is and  end game (need copy paste end game)
        dealer->compareCards(deck.deckOfCards, *user);
        // End the game
        onEndGame();
        // clear user hand to allow further betting(condition to placing bet is userHand.size() == 0)
        user->clearUserHand();

    }
    else
    {
        // Dealer takes anotha card
        dealer->hit(deck.deckOfCards);
        // Update the UI to show the new card
        displayDealerHand();
        // Display dealer hand value
        dealer->displayDealerHandVal();

        // Sound during dealer hit
        M_Player2->setSource(QUrl("qrc:/sounds/singleFlipSound"));
        M_Player2->play();
        controlSFX->setVolume(100);
    }
}



void mainWindow::onSplitButton() {
    // NOT FINISHED
    // 1. IMPLEMENTATION NEEDED FOR NOT HAVING ENOUGH MONEY TO SPLIT!!!
    // 2. NEED TO CONSIDER DOUBLE DOWN
    // 3 .

    // Check if user can split
    if (user->userHand.size() >= 2 && user->userHand[0].cardRank == user->userHand[1].cardRank ) {
        user->split();  // User.cpp Split Function
        hasSplit = true;

        // Remove the split card from the starting deck's UI but we can't because error message
        QLabel* splitCardLabel = cardLabels.last();
        splitCardLabel->deleteLater();
        cardLabels.pop_back(); // Removed card from split cardlabel

        updateUserHandValDisplay();

        // Update UI hand
        displayPlayerHand();
        updateBetDisplay(user->betVal);
        updateBalanceDisplay();


        // Delaying Error Message to allow split hand to be removed first
        QTimer::singleShot(500, this, [this]() {
            showErrorMessage("Playing the starting hand. Split hand will follow.");
        });

        // Animate the card
        QString cardPath = user->splitHand[0].getCardImagePath(); // Get the image path for the split card
        animateSplitCardToWidget(ui->splitWidget1, cardPath, 100, 150); // Move the split card to the split UI
        qDebug() << "Split completed. Message delayed to ensure UI updates first.";
        updateSplitHandValDisplay();

    } else {
        showFloatingMessage("You cannot split these cards.");
    }

}






//--------------------------------------BUTTONCLICK--------------------------------------

//--------------------------------------***********--------------------------------------
//--------------------------------------***********--------------------------------------

//--------------------------------------CARDANIMATE--------------------------------------

void mainWindow::displayPlayerHand() {
    qDebug() << "User hand size:" << user->userHand.size();  // Output the number of cards in user's hand

    QList<QWidget*> userWidgets = {ui->widget1, ui->widget2, ui->widget3, ui->widget4, ui->widget5, ui->widget6,
                                    ui->widget7, ui->widget8, ui->widget9, ui->widget10, ui->widget11};

    // Start animating only from the last displayed card index
    for (int i = lastDisplayedUserCardIndex; i < user->userHand.size(); ++i) {
        QString cardPath = user->userHand[i].getCardImagePath();  // Get the image path for the current card
        qDebug() << "Animating User Card " << i + 1 << ": " << cardPath;

        if (i < userWidgets.size()) {
            animateCardToWidget(userWidgets[i], cardPath, 100, 150);
        }
    }
    // Update the index to the last displayed card
    lastDisplayedUserCardIndex = user->userHand.size();
}


void mainWindow::displaySplitHand() {
    QList<QWidget*> splitWidgets = {ui->splitWidget1, ui->splitWidget2, ui->splitWidget3, ui->splitWidget4, ui->splitWidget5};

    for (int i = lastDisplayedSplitCardIndex; i < user->splitHand.size(); ++i) {
        QString cardPath = user->splitHand[i].getCardImagePath();
        qDebug() << "Animating Split Hand Card " << i + 1 << ": " << cardPath;

        if (i < splitWidgets.size()) {
            animateSplitCardToWidget(splitWidgets[i], cardPath, 100, 150);
        }
    }

    // Update the index to the last displayed card
    lastDisplayedSplitCardIndex = user->splitHand.size();
}

void mainWindow::displayDealerHand() {
    QList<QWidget*> dealerWidgets = {ui->dealerWidget1, ui->dealerWidget2, ui->dealerWidget3, ui->dealerWidget4,
                                      ui->dealerWidget5, ui->dealerWidget6, ui->dealerWidget7, ui->dealerWidget8,
                                      ui->dealerWidget9, ui->dealerWidget10, ui->dealerWidget11};

    for (int i = lastDisplayedDealerCardIndex; i < dealer->getDealerHand().size() && i < dealerWidgets.size(); ++i) {
        QString cardPath = dealer->getDealerHand()[i].getCardImagePath();
        qDebug() << "Animating Dealer Card " << i + 1 << ": " << cardPath;

        if(i == 1 && userTurn == true){
            animateDealerCardToWidget(dealerWidgets[i], cardPath, 100, 150, true);
        }

        else{
            animateDealerCardToWidget(dealerWidgets[i], cardPath, 100, 150);  // Animate only new cards
        }
    }
    // Update the index to the last displayed card
    lastDisplayedDealerCardIndex = dealer->getDealerHand().size();

    if(!userTurn){
        QString cardPath2 = dealer->getDealerHand()[1].getCardImagePath();
        QPixmap cardPixmap(cardPath2);

        QLabel* dealerCardLabel = dealerCardLabels[1];
        dealerCardLabel->setPixmap(cardPixmap);
        dealerCardLabel->setScaledContents(true);
        userTurn = true;
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


void mainWindow::animateSplitCardToWidget(QWidget* targetWidget, const QString &cardPath, int width, int height) {
    QPixmap cardPixmap(cardPath);

    if (cardPixmap.isNull()) {
        qDebug() << "Failed to load image for split card: " << cardPath;
        return;
    }

    // Create QLabel for the card and set its parent to the main window
    QLabel* cardLabel = new QLabel(this); // Parent is the main window

    // Scale the card image and maintain aspect ratio
    QPixmap scaledPixmap = cardPixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    cardLabel->setPixmap(scaledPixmap);

    // Set QLabel properties
    cardLabel->setFixedSize(scaledPixmap.width(), scaledPixmap.height());
    cardLabel->setAlignment(Qt::AlignCenter);

    // Start the card off-screen
    QRect startGeometry(-scaledPixmap.width(), -scaledPixmap.height(), scaledPixmap.width(), scaledPixmap.height());
    cardLabel->setGeometry(startGeometry);
    cardLabel->show();
    cardLabel->raise(); // Ensure the card is drawn above other widgets

    // Calculate the absolute position of the target widget relative to the main window
    QPoint targetWidgetPosition = targetWidget->mapTo(this, QPoint(0, 0)); // Map target widget position to mainWindow coordinates
    QPoint targetCenter(targetWidgetPosition.x() + (targetWidget->width() - scaledPixmap.width()) / 2,
                        targetWidgetPosition.y() + (targetWidget->height() - scaledPixmap.height()) / 2);

    // Create QPropertyAnimation to move the card smoothly
    QPropertyAnimation* animation = new QPropertyAnimation(cardLabel, "pos");
    animation->setDuration(750);
    animation->setStartValue(QPoint(-100, -100)); // Start off-screen
    animation->setEndValue(targetCenter);         // End at the widget's center

    animation->start(QAbstractAnimation::DeleteWhenStopped);

    // Store the cardLabel for cleanup
    splitCardLabels.append(cardLabel);

    qDebug() << "Split card animation started for: " << cardPath;
}





void mainWindow::animateDealerCardToWidget(QWidget* targetWidget, const QString &cardPath, int width, int height, bool faceDown) {

    QPixmap cardPixmap(faceDown ? ":/cards/back_dark.png" : cardPath); //face-down image

    if (cardPixmap.isNull()) {
        qDebug() << "Failed to load image for dealer card: " << cardPath;
        return;
    }

    QLabel* cardLabel = new QLabel(this);

    QPixmap scaledPixmap = cardPixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    cardLabel->setPixmap(scaledPixmap);

    cardLabel->setFixedSize(scaledPixmap.width(), scaledPixmap.height());
    cardLabel->setAlignment(Qt::AlignCenter);

    QRect startGeometry(-100, -100, scaledPixmap.width(), scaledPixmap.height());
    cardLabel->setGeometry(startGeometry);
    cardLabel->show();

    QPropertyAnimation* animation = new QPropertyAnimation(cardLabel, "geometry");
    animation->setDuration(750);

    QRect targetGeometry = targetWidget->geometry();
    int targetX = targetGeometry.x() + (targetGeometry.width() - scaledPixmap.width()) / 2;
    int targetY = targetGeometry.y() + (targetGeometry.height() - scaledPixmap.height()) / 2;

    // Apply vertical offset to move the card down
    targetY += 0; // Adjust this value until the placement looks correct

    animation->setStartValue(startGeometry);
    animation->setEndValue(QRect(targetX, targetY, scaledPixmap.width(), scaledPixmap.height()));

    animation->start(QAbstractAnimation::DeleteWhenStopped);

    dealerCardLabels.append(cardLabel);

    qDebug() << "Dealer card animation started for: " << cardPath;
}



//--------------------------------------CARDANIMATE--------------------------------------

//--------------------------------------***********--------------------------------------
//--------------------------------------***********--------------------------------------


void mainWindow::updateBetDisplay(int bet) {
    // Update the display label to show the current bet amount
    ui->label_691->setText(QString("Current Bet: $%1").arg(bet));
}
void mainWindow::updateBalanceDisplay() {
    ui->label->setText(QString("Current Balance: $%1").arg(user->balance));
}
void mainWindow::updateUserHandValDisplay() {
    ui->label_54->setText(QString("Main Hand Value: %1").arg(user->handVal));
}
void mainWindow::updateDealerHandValDisplay() {
    ui->label_56->setText(QString("Dealer Hand Value: %1").arg(dealer->getDealerHandVal()));
}

void mainWindow::updateSplitHandValDisplay(){
    ui->label_55->setText(QString("Split Hand Value: %1").arg(user->getSplitHandTotal()));

}


void mainWindow::clearCardsDisplayed(){
    // Clear UI card displays for User
    for(auto label : cardLabels){
        if(label){
            label->deleteLater();
        }
    }
    cardLabels.clear();  // Clear the User list to reset for a new game

    for (auto label : splitCardLabels) {
        if (label) {
            label->deleteLater();
        }
    }
    splitCardLabels.clear();


    // Clear UI card displays for Dealer
    for(auto label : dealerCardLabels){
        if(label){
            label->deleteLater();
        }
    }
    dealerCardLabels.clear();  // Clear the Dealer list to reset for a new game

    // Clear user and dealer hands
    user->clearUserHand();  // Clear the user's hand
    dealer->removeCards();   // Clear the dealer's hand
    user->splitHand.clear(); // Clear the 2nd user's hand


    ui->label_54->setText(""); // Clear Main Hand Value
    ui->label_55->setText(""); // Clear Split Hand Value
    ui->label_56->setText(""); // Clear Dealer Hand Value
}


void mainWindow::onEndGame() {
    userTurn = false;
    // Update the UI to show the new card
    displayDealerHand();
    // Display dealer hand value
    dealer->displayDealerHandVal();


    // Reset the deck if needed
    deck.killDeck();
    deck.createDeck();
    deck.shuffle();


    // Update balance and bet displays
    updateBalanceDisplay();  // Update balance display label
    updateBetDisplay(0);     // Reset bet display to 0
    user->betVal = 0;
    user->splitBetVal = 0;
    // Reset the displayed card indices to 0 for the next game
    lastDisplayedUserCardIndex = 0;
    lastDisplayedDealerCardIndex = 0;

    //Reseting these for next game
    isPlayingSplitHand = false;
    hasSplit = false;

    showErrorMessage("Game over. Ready for a new game.");
    clearCardsDisplayed();
    qDebug() << "End game: All displays reset, hands cleared, and deck reshuffled.";



}



void mainWindow::showFloatingMessage(const QString &message) {
    QLabel *floatingMessage = new QLabel(this);
    floatingMessage->setText(message);
    floatingMessage->setStyleSheet("background-color: rgba(50, 50, 50, 200);"
                                   "color: white;"
                                   "font: bold 25px;"
                                   "padding: 15px;"
                                   "border-radius: 10px;"
                                   "box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.5);");
    floatingMessage->setAlignment(Qt::AlignCenter);

    QFont font("Arial", 25, QFont::Bold);
    floatingMessage->setFont(font);
    QFontMetrics metrics(font);
    QSize textSize = metrics.size(Qt::TextSingleLine, message);
    int labelWidth = textSize.width() + 30;  // Add padding to width
    int labelHeight = textSize.height() + 30; // Add padding to height

    floatingMessage->setGeometry(width() / 2 - labelWidth / 2, height(), labelWidth, labelHeight);
    floatingMessage->setAttribute(Qt::WA_TranslucentBackground, true); // Enable translucency
    floatingMessage->show();

    // Create the animation for the floating message
    QPropertyAnimation *animation = new QPropertyAnimation(floatingMessage, "geometry");
    animation->setDuration(2000); // Duration in milliseconds
    animation->setStartValue(floatingMessage->geometry());
    animation->setEndValue(QRect(width() / 2 - labelWidth / 2, height() / 2, labelWidth, labelHeight)); // Float to the center

    // Delete the message after animation
    connect(animation, &QPropertyAnimation::finished, floatingMessage, &QLabel::deleteLater);

    // Start the animation
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}





void mainWindow::on_horizontalSlider_valueChanged(int value)
{

    volumeControl->setVolume(static_cast<float>(value) / 100.0f);

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



