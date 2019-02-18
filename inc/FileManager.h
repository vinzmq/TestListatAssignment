//
// Created by vmartynu on 15.02.19.
//

#ifndef LISTSATTEST_FILEMANAGER_H
#define LISTSATTEST_FILEMANAGER_H
#include "prime.h"


class FileManager {

public:
    FileManager();
    ~FileManager();

    std::string readFrom(std::string path);///getting string from file
    void writeTo(std::string data, std::string path);///writing string to file
    void addTo(std::string data, std::string path);///adding string to existing file
    bool isXML(std::string data); ///checking if XML has closed tags
private:
    bool searchingTags(std::string data); ///searching closed tags recursively, if it is ok return true

};


#endif //LISTSATTEST_FILEMANAGER_H
