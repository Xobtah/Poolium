//
// Created by xobtah on 06/02/17.
//

#ifndef POOLIUM_THREAD_HPP
#define POOLIUM_THREAD_HPP

#include <thread>

#include "IThread.hpp"

namespace Poolium
{
    class Thread : public IThread
    {
    public:
        Thread();
        Thread(IThreadRunner&);
        Thread(void (*)());
        ~Thread();

        IThread &Free();
        IThread &Run(IThreadRunner&);
        IThread &Run(void (*)());
        IThread &Join();

    private:
        std::thread *_thread;
    };
}

#endif //POOLIUM_THREAD_HPP
