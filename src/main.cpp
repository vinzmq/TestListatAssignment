#include <iostream>
#include "../inc/Program.h"
#include "../inc/ErrorException.h"
int main(int argc, char** argv) {
    try {
        if (argc == 3) {
            Program pro(argv[1], argv[2]);
            pro.run();
        } else if (argc == 2) {
            Program pro(argv[1]);
            pro.run();

        } else
            std::cout << "Usage: ./prime [inputFile] [outputFile](optional)" << std::endl;
    }
    catch (ErrorException &e)
    {
        std::cout <<"Error: "<< e.getError()<<std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout <<"Error: "<< e.what()<<std::endl;
    }
    catch (...){
        std::cout <<"Not Handled Exception "<< std::endl;
    }
    return 0;
}