//
// Created by xobtah on 06/02/17.
//

#ifndef POOLIUM_MUTEX_HPP
#define POOLIUM_MUTEX_HPP

#include <mutex>

#include "IMutex.hpp"

namespace Poolium
{
    class Mutex : public IMutex
    {
    public:
        Mutex();
        ~Mutex();

        IMutex  &Lock();
        bool    TryLock();
        IMutex  &Unlock();

    private:
        std::mutex  _mutex;
    };
}

#endif //POOLIUM_MUTEX_HPP
