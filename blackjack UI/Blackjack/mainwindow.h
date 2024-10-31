#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"
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
};
#endif // MAINWINDOW_H
