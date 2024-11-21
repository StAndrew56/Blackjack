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
//--------------------------------------***********--------------------------------------

//--------------------------------------BET AMOUNTS--------------------------------------
void mainWindow::onOneDollarBet() {
    if(user->balance == 0){
        showErrorMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
    user->increaseBet(1); // Call the placeBet method from User class
    }
    else{
        showErrorMessage("You can't change your bet aftering start!");
    }
    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;

}
void mainWindow::onFiveDollarBet() {
    if(user->balance == 0){
        showErrorMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
        user->increaseBet(5); // Call the placeBet method from User class
    }
    else{
        showErrorMessage("You can't change your bet aftering start!");
    }
    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onTenDollarBet() {
    if(user->balance == 0){
        showErrorMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
        user->increaseBet(10); // Call the placeBet method from User class
    }
    else{
        showErrorMessage("You can't change your bet aftering start!");
    }

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onTwentyDollarBet() {
    if(user->balance == 0){
        showErrorMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
        user->increaseBet(20); // Call the placeBet method from User class
    }
    else{
        showErrorMessage("You can't change your bet aftering start!");
    }

    qDebug() << "Current Balance: $" << user->balance;
    qDebug() << "Current Bet: $" << user->betVal;
}

void mainWindow::onHundredDollarBet() {
    if(user->balance == 0){
        showErrorMessage("Out of money!");
        return;
    }
    if(user->userHand.size() == 0){
        user->increaseBet(100); // Call the placeBet method from User class
    }
    else{
        showErrorMessage("You can't change your bet aftering start!");
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

    user->trueRank();
    qDebug() << "Current handVal: " << user->handVal;
    qDebug() << "tbvwayyyyyyyvabvaw";
    displayDealerHand();
    displayPlayerHand();

    //sound during original deal
    M_Player2->setSource(QUrl("qrc:/sounds/shuffleSound"));
    M_Player2->play();
    controlSFX->setVolume(100);

    //pays player for getting "BlackJack" 21 off original deal.
    if (user->getUserHandTotal() == 21 && dealer->getHandValue() != 21) {
        showErrorMessage("Blackjack! You win!");
        user->pay();
        user->betVal = 0;
        user->clearUserHand();
        onEndGame();
        return;
    }

    if(dealer->getHandValue() == 21 && user->getUserHandTotal() != 21){
        showErrorMessage("Dealer has blackjack... You Lose.");
        user->betVal = 0;
        user->clearUserHand();
        onEndGame();
        return;
    }

    updateBetDisplay(user->betVal);
    updateBalanceDisplay();
    qDebug() << "New round started, cards dealt, and UI updated.";
    }
    else{
        showErrorMessage("Finish the current hand first!");
    }
}



//--------------------------------------BET AMOUNTS--------------------------------------

//--------------------------------------***********--------------------------------------
//--------------------------------------***********--------------------------------------


//--------------------------------------BUTTONCLICK--------------------------------------
void mainWindow::onHitButtonClicked() {
    if(user->userHand.size() > 0){
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

        //sound during hit
        M_Player2->setSource(QUrl("qrc:/sounds/singleFlipSound"));
        M_Player2->play();
        controlSFX->setVolume(100);

    }
    qDebug() << "Current handVal: " << user->handVal;

    // Check if the user has busted after hitting
    if (user->handVal > 21) {
        qDebug() << "Player busted!";
        showErrorMessage("You busted!");
        user->clearUserHand();//clear the hand from the vector
        onEndGame();
    }
    }
    else{
        showErrorMessage("Must place a bet first! Please click submit after choosing the amount.");
    }
}





void mainWindow::onDoubleDownButton(){
    // Checks if user has 2 cards and enough money
    if(user->betVal == 0){
        showErrorMessage("Double down is available only on the initial deal with enough balance.");
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

        //sound during player DD
        M_Player2->setSource(QUrl("qrc:/sounds/singleFlipSound"));
        M_Player2->play();
        controlSFX->setVolume(100);

        // Check if the player has busted after doubling down
        if (user->getUserHandTotal() > 21) {
            qDebug() << "Player busted after double down!";
            showErrorMessage("You busted!");
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
        showErrorMessage("Double down is available only on the initial deal with enough balance.");
    }
}





void mainWindow::onStandButton() {
    if(user->userHand.size() > 0){
    // Make sure theres a bet before stand is clicked
    if (user->betVal > 0)
    {
        dealer->stand(); // Trigger stand though its empty

        // Add a delay animation in between cards to prevent all of them showing up at same time
        standTimer = new QTimer(this);
        connect(standTimer, &QTimer::timeout, this, &mainWindow::dealerStandStep);
        standTimer->start(750); // 750 ms delay between each dealer hit animation
    }
    else
    {
        showErrorMessage("Please place a bet before standing.");
    }
    }
    else{
        showErrorMessage("First place a bet!");

    }
}



void mainWindow::dealerStandStep() {
    // Getter to get dealer hand value
    if (dealer->getDealerHandVal() >= 17 || dealer->getDealerHandVal() > 21 || deck.deckOfCards.empty())
    {
        // Stop timer if conditions met
        standTimer->stop();
        delete standTimer;
        standTimer = nullptr;

        displayDealerHand();  // Final display of dealers hand

        // Check who winner is and  end game (need copy paste end game)
        dealer->compareCards(deck.deckOfCards, *user);
        // End the game
        onEndGame();
        //clear user hand to allow further betting(condition to placing bet is userHand.size() == 0)
        user->clearUserHand();

    }
    else
    {
        // Dealer takes anotha card
        dealer->hit(deck.deckOfCards);
        //dealer->trueRank();  // Recalc hand value for dealer
        displayDealerHand(); // Update the UI to show the new card

        //sound during dealer hit
        M_Player2->setSource(QUrl("qrc:/sounds/singleFlipSound"));
        M_Player2->play();
        controlSFX->setVolume(100);
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

void mainWindow::displayDealerHand() {
    QList<QWidget*> dealerWidgets = {ui->dealerWidget1, ui->dealerWidget2, ui->dealerWidget3, ui->dealerWidget4,
                                      ui->dealerWidget5, ui->dealerWidget6, ui->dealerWidget7, ui->dealerWidget8,
                                      ui->dealerWidget9, ui->dealerWidget10, ui->dealerWidget11};

    for (int i = lastDisplayedDealerCardIndex; i < dealer->getDealerHand().size() && i < dealerWidgets.size(); ++i) {
        QString cardPath = dealer->getDealerHand()[i].getCardImagePath();
        qDebug() << "Animating Dealer Card " << i + 1 << ": " << cardPath;

        animateDealerCardToWidget(dealerWidgets[i], cardPath, 100, 150);  // Animate only new cards
    }
    // Update the index to the last displayed card
    lastDisplayedDealerCardIndex = dealer->getDealerHand().size();
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



void mainWindow::animateDealerCardToWidget(QWidget* targetWidget, const QString &cardPath, int width, int height, bool faceDown) {
    QPixmap cardPixmap(faceDown ? ":/cards/back_dark.png" : cardPath); // Use a face-down image if necessary

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
    targetY += 80; // Adjust this value until the placement looks correct

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
    ui->label->setText(QString("Current Balance: $%1").arg(user->balance)); // Update balance label
}

void mainWindow::clearCardsDisplayed(){
    // Clear UI card displays for User
    for(auto label : cardLabels){
        if(label){
            label->deleteLater();
        }
    }
    cardLabels.clear();  // Clear the User list to reset for a new game

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

}


void mainWindow::onEndGame() {


    // Reset the deck if needed
    deck.killDeck();
    deck.createDeck();
    deck.shuffle();

    // Update balance and bet displays
    updateBalanceDisplay();  // Update balance display label
    updateBetDisplay(0);     // Reset bet display to 0
    user->betVal = 0;

    // Reset the displayed card indices to 0 for the next game
    lastDisplayedUserCardIndex = 0;
    lastDisplayedDealerCardIndex = 0;

    qDebug() << "End game: All displays reset, hands cleared, and deck reshuffled.";
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
