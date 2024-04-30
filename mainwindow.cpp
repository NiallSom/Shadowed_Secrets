#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

    buttonSetup(ui->Start,Start,)
}
void MainWindow::buttonSetup(QPushButton *button, QPixmap map, Ui::MainWindow &func) {
    button->setIcon(QIcon(map));
    button->setIconSize(map.size()/4);
    button->setText("");
    button->setStyleSheet("border:0; outline:none;");
    connect(button, &QPushButton::pressed, this, func);
}
void MainWindow::handleButton() {
    QString senderButton = qobject_cast<QPushButton*>(sender())->objectName();
}
MainWindow::~MainWindow()
{
    delete ui;
}
