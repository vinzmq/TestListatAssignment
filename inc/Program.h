//
// Created by vmartynu on 15.02.19.
//

#ifndef LISTSATTEST_PROGRAM_H
#define LISTSATTEST_PROGRAM_H


#include "FileManager.h"
#include "prime.h"
#include "PrimeContainerT.h"
#include <math.h>

class Program {
public:
    Program();
    Program(const Program &obj);
    Program&  operator=(const Program &obj);
    ~Program();

    Program(std::string inFilePath);
    Program(std::string inFilePath, std::string outFilePath);

    void run(); /// start runing app
    bool isPrime( double number); /// is number prime

    void getIntervallsXml(std::string xml); //get multimap of intervals from XML-file

    std::string setPrimesToXml(); ///getting string content from set of primes

    void runThreads(); ///run thread function
private:
    ///methods
    void getPrimesInInterval(PrimeContainer<double> &c, std::pair<double,double> interval);
   ///variables
    std::string inFile; /// source filePath
    std::string outFile;/// result filePath
    FileManager manager; ///manager for operation with files
    std::multimap<double, double> mmap; ///contains low(key) and high(value) border of interval
    PrimeContainer<double> cntr;///wrap container for getting thread's results
    std:: vector<std::thread> threads;///vector of container threads.

};


#endif //LISTSATTEST_PROGRAM_H
