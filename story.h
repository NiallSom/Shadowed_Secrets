#ifndef STORY_H
#define STORY_H

#include "rapidjson/document.h"
#include <vector>
#include "dataStructs.h"
class Story
{
private:
    rapidjson::Document document;
public:
    Story(const char* filename);
    std::vector<values> getValues(int id);
    std::string getText(int id);
};

#endif // STORY_H
