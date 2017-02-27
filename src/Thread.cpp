//
// Created by xobtah on 06/02/17.
//

#include "Thread.hpp"

namespace Poolium
{
    /*
     *   Ctor & Dtor
     */
    Thread::Thread() : _thread(NULL) {}

    Thread::~Thread() { this->Free(); }

    /*
     *  Public member functions
     */

    Thread  &Thread::Free()
    {
        if (_thread)
        {
            if (_thread->joinable())
                _thread->detach();
            delete _thread;
            _thread = NULL;
        }
        return (*this);
    }

    Thread  &Thread::Join()
    {
        if (_thread && _thread->joinable())
            _thread->join();
        return (*this);
    }
}