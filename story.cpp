#include "story.h"
#include "rapidjson/filereadstream.h"
#include <vector>
#include <dataStructs.h>
#include <QMainWindow>
Story::Story(const char *filename){
    FILE* fp = fopen(filename, "r");
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer,
                                 sizeof(readBuffer));
    document.ParseStream(is);
    fclose(fp);
}

std::vector<values> Story::getValues(int id){
    std::vector<values> choicesVector = {}; // used vectors incase we want to change how many choices a user is granted
    rapidjson::Value& array = document["main_story"][id]["choices"].GetArray();
    qDebug() << "SAY WHATTT";
    for (rapidjson::SizeType i = 0; i < array.Size(); ++i) {
        rapidjson::Value& button = array[i]["button"];
        rapidjson::Value& textElement = array[i]["text"];
        const rapidjson::Value& leadsToElement = array[i]["leads_to"];
        choicesVector.push_back(values{button.GetString(),textElement.GetString(), leadsToElement.GetInt()});
    }
    return choicesVector;
}
std::string Story::getText(int id){
    return document["main_story"][id]["text"].GetString();
}
