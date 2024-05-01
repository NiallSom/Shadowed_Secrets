#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

Game *game;
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit->setStyleSheet("background-color: #ffffff; border-radius:5px;");
    QPixmap logo(":/images/MiniZorkLogo.png");
    ui->Title_img->setPixmap(logo);

    QPixmap North(":/images/N.png");
    QPixmap East(":/images/E.png");
    QPixmap South(":/images/S.png");
    QPixmap West(":/images/W.png");

    QPixmap Investigate(":/images/investigate.png");
    QPixmap Pickup(":/images/pickup.png");
    QPixmap Interrogate(":/images/interrogate.png");
    QPixmap Hide(":/images/hide.png");
    QPixmap Open(":/images/open.png");
    QPixmap Hit(":/images/hit.png");
    QPixmap Start(":/images/play-button.png");

    buttonSetup(ui->Start,Start);
    buttonSetup(ui->North,North);
    buttonSetup(ui->East,East);
    buttonSetup(ui->South,South);
    buttonSetup(ui->West,West);

    buttonSetup(ui->Investigate,Investigate);
    buttonSetup(ui->Pickup,Pickup);
    buttonSetup(ui->Interrogate,Interrogate);
    buttonSetup(ui->Hide,Hide);
    buttonSetup(ui->Open,Open);
    buttonSetup(ui->Hit,Hit);
    game = new Game("C:/Users/Niall/Desktop/C++/ShadowedSecretsFinal/zorkin-it.json",ui);

}
void MainWindow::buttonSetup(QPushButton *button, QPixmap map) {
    button->setIcon(QIcon(map));
    button->setIconSize(map.size()/4);
    button->setText("");
    button->setStyleSheet("border:0; outline:none;");
    connect(button, &QPushButton::pressed, this, &MainWindow::handleButton);
}
void MainWindow::handleButton() {
    QString senderButton = qobject_cast<QPushButton*>(sender())->objectName();
    game->buttonPress(senderButton);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}
