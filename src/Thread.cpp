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

    Thread::Thread(IThreadRunner &tr) { this->Run(tr); }

    Thread::Thread(void (*funcPtr)()) { this->Run(funcPtr); }

    Thread::~Thread() { this->Free(); }

    /*
     *  Public member functions
     */

    IThread &Thread::Free()
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

    IThread &Thread::Run(IThreadRunner &tr)
    {
        _thread = new std::thread(&IThreadRunner::ThreadRunner, &tr);
        return (*this);
    }

    IThread &Thread::Run(void (*funcPtr)())
    {
        _thread = new std::thread(funcPtr);
        return (*this);
    }

    IThread &Thread::Join()
    {
        if (_thread && _thread->joinable())
            _thread->join();
        return (*this);
    }
}