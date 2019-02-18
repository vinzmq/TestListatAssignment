//
// Created by vmartynu on 15.02.19.
//

#include "../inc/FileManager.h"
#include "../inc/ErrorException.h"

    FileManager::FileManager() {}
    FileManager::~FileManager() {}


    std::string FileManager::readFrom(std::string path) {
        std::string line;
        std::string prog;
        std::ifstream myfile(path);

        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                prog += (line + "\n");
            }
            myfile.close();
            return prog;
        } else {
            throw (ErrorException("Can't open file"));
           }

    }

        void FileManager::writeTo(std::string data, std::string path) {
            std::ofstream myfile (path);
            std::cout<<path<<" created"<<std::endl;
            if (myfile.is_open())
            {
                myfile << data;
                myfile.close();
            }
            else
                throw (ErrorException("Can't open file"));
        }

void FileManager::addTo(std::string data, std::string path) {
    std::ofstream myfile;
    myfile.open(path,  std::ofstream::out | std::ofstream::app);
    if (myfile.fail())
        throw (ErrorException("Can't open file"));
    myfile << data;
    myfile.close();

}

        bool FileManager::searchingTags(std::string data)
        {
            std::string dataNext;
            std::string openTag;
            std::string closeTag;
            std::string::iterator it=data.begin();
            std::size_t foundIn = 0;


            while (it<=data.end()) {
                 foundIn= data.find("<",foundIn,1 );
                if (foundIn == std::string::npos)
                    return true;
                it += foundIn;
                std::size_t foundOut = data.find(">", foundIn + 1, 1);
                if (foundOut == std::string::npos)
                    return false;
                openTag = data.substr(foundIn, foundOut + 1 - foundIn);
                closeTag = openTag;
                closeTag.insert(1, "/");

                foundIn = foundOut + 1;
                foundOut = data.find(closeTag, foundIn);
                if (foundOut == std::string::npos)
                    return false;
                dataNext = data.substr(foundIn, foundOut - foundIn);
                foundIn = foundOut + closeTag.length() + 1;
                if (!this->searchingTags(dataNext))
                    return false;
                it += (foundOut + 1 + closeTag.length() - (it - data.begin()));
            }

            return true;
        }

        bool FileManager::isXML(std::string data){

            std::size_t foundIn = data.find("<");
            if (foundIn == std::string::npos)
                return false;

            if (this->searchingTags(data))
                return true;
            else
                return false;
}
