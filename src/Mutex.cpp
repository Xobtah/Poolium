//
// Created by xobtah on 06/02/17.
//

#include "Mutex.hpp"

namespace Poolium
{
    /*
     *  Ctor & Dtor
     */

    Mutex::Mutex() : _mutex() {}
    Mutex::~Mutex() {}

    /*
     *  Public member functions
     */

    IMutex  &Mutex::Lock()
    {
        _mutex.lock();
        return (*this);
    }

    bool    Mutex::TryLock() { return (_mutex.try_lock()); }

    IMutex  &Mutex::Unlock()
    {
        _mutex.unlock();
        return (*this);
    }
}