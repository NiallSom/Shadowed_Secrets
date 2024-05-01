#ifndef GAME_H
#define GAME_H

#include "ui_mainwindow.h"
#include "story.h"
#include <vector>

class Game
{
private:
    int currentID;
    Story story;
    Ui::MainWindow *ui;
public:
    Game(const char *file,Ui::MainWindow *ui);
    void buttonPress(QString senderButton);
    void optionHandling(QString senderButton);
};

#endif // GAME_H
