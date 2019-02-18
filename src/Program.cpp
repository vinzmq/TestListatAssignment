//
// Created by vmartynu on 15.02.19.
//

#include "../inc/Program.h"
#include "../inc/ErrorException.h"

Program::Program() {}
Program::Program(std::string inF) : inFile(inF), outFile("PrimesResult") {}
Program::Program(std::string inF, std::string outF) : inFile(inF), outFile(outF) {}
Program::Program(const Program &obj) {}
Program& Program::operator=(const Program &obj) {
    *this= obj;
    return *this;
}
Program::~Program() {}

void Program::run() {
    std::string read = manager.readFrom(inFile);
    if (manager.isXML(read)) {
        this->getIntervallsXml(read);
        this->runThreads();
        std::string result = setPrimesToXml();
        if (!this->inFile.compare(this->outFile)) {
            manager.addTo(result, inFile);
        }
        else
            manager.writeTo(result, outFile);

    }
    else
        throw (ErrorException("It is not XML"));

}

std::string Program::setPrimesToXml() {
    std::string ret = "<root>\n<primes></primes>\n</root>\n";
    std::string insertPrime = this->cntr.toString();
    ret.insert(15,insertPrime);
    return  ret;

}

void Program::getIntervallsXml(std::string xml) {

    std::size_t interval = 0;

    while ((interval = xml.find("<interval>", interval)) != std::string::npos) {
        std::size_t foundLower = xml.find("<low>", interval);
        std::size_t foundHigher = xml.find("<high>", interval);
        double first= std::stod(&xml.at(foundLower + 5));
        double second =  std::stod(&xml.at(foundHigher + 6));
        this->mmap.insert(std::make_pair<double, double>( ceil(first), floor(second) ) );
        interval += 10;
    }

}

bool Program::isPrime(double number)
{
    double j;
    if (number >= 1) {
        double i = number - 1;
        while (i > 1) {

            if (modf(number / i, &j) == 0)
                return false;
                i--;
        }
        return true;
    }
    else
        return false;
}

void Program::getPrimesInInterval(PrimeContainer<double> &c, std::pair<double, double> interval) {
    double i = interval.first;
    while (i <= interval.second)
    {
        if (isPrime(i))
            c.add(i);
        i++;
    }
}

void Program::runThreads(){
    int i = 0;
    for (auto &it : this->mmap)
    {
        if(it.second > it.first)
            this->threads.push_back(std::thread(&Program::getPrimesInInterval, this, std::ref(this->cntr), it));
        else
            throw (ErrorException("Wrong interval"));
        i++;
    }
    for (auto &it : threads) {
        if (it.joinable())
            it.join();
    }
}