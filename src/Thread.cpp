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

    Thread::Thread(const Thread &t) : _thread(NULL), _func(t._func) {}

    Thread  &Thread::operator=(const Thread &t)
    {
        if (this == &t)
            return (*this);
        _thread = NULL;
        _func = t._func;
        return (*this);
    }

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