//
// Created by xobtah on 06/02/17.
//

#ifndef POOLIUM_ITHREAD_HPP
#define POOLIUM_ITHREAD_HPP

#include "IThreadRunner.hpp"

namespace Poolium
{
    class   IThread
    {
    public:
        virtual ~IThread() {}

        virtual IThread &Free() = 0;
        virtual IThread &Run(IThreadRunner&) = 0;
        virtual IThread &Run(void (*)()) = 0;
        virtual IThread &Join() = 0;
    };
}

#endif //POOLIUM_ITHREAD_HPP
