#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    //setBackgroundImage();
    //setButtons();

}

void setGraphic(){

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

