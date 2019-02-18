//
// Created by vmartynu on 16.02.19.
//

#ifndef LISTSATTEST_PRIMECONTAINERT_H
#define LISTSATTEST_PRIMECONTAINERT_H

#include "prime.h"

template <typename T>
class PrimeContainer{
public:
    void add(int element)///adding element to container
    {
        std::lock_guard<std::recursive_mutex> locker(_lock);
        _elements.emplace(element);
    }
    std::string toString() ///getting string of values of container
    {
        std::string ret;
        _lock.lock();
        for(auto e: _elements) {
            ret += " ";
            std::string str = std::to_string(e);
            ret += str.erase ( str.find('.'), std::string::npos );
        }
        _lock.unlock();
        return ret;
    }
private:
    std::recursive_mutex _lock; ///mutex for threads locking
    std::set<T> _elements; // set of primes
};

#endif //LISTSATTEST_PRIMECONTAINERT_H
