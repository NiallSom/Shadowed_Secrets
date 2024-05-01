#include "game.h"

Game::Game(const char* file,Ui::MainWindow *x): story(file), ui(x){}

void Game::buttonPress(QString buttonName){
    //ui->plainTextEdit->setPlainText(buttonName);
    optionHandling(buttonName);
    std::vector<values> storyChoices = story.getValues(this->currentID);
    ui ->plainTextEdit->setPlainText(QString::fromStdString(story.getText(this->currentID)));
    for (int i=0;i<storyChoices.size();i++) {
        ui ->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText()+"\n >> " + QString::fromStdString(storyChoices[i].text));
    }
}

void Game::optionHandling(QString buttonName){
    std::vector<values> storyChoices = story.getValues(this->currentID);
    for (int i=0;i<storyChoices.size();i++) {
        if (QString::fromStdString(storyChoices[i].button) == buttonName) {
            qDebug() << i;
            this->currentID = storyChoices[i].leadsToID;
            qDebug() << "HELL YEAH BROTHA";
        }
    }
}
