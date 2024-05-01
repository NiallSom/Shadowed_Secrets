#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <string>

struct values{
    std::string button;
    std::string text;
    int leadsToID;
    values(std::string btn,std::string storyText,int id):button(btn),text(storyText),leadsToID(id){}
};

#endif // DATASTRUCTS_H
