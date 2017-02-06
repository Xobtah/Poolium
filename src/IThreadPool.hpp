//
// Created by xobtah on 06/02/17.
//

#ifndef POOLIUM_ITHREADPOOL_HPP
#define POOLIUM_ITHREADPOOL_HPP

#include "IThreadRunner.hpp"
#include "Thread.hpp"

namespace Poolium
{
    class IThreadPool
    {
    public:
        virtual ~IThreadPool() {}

        virtual unsigned int    Add(IThreadRunner&) = 0;
        virtual unsigned int    Add(void (*)()) = 0;
        virtual Thread          &Get(unsigned int) = 0;
        virtual IThreadPool     &Remove(unsigned int) = 0;

        virtual unsigned int    GetSize() const = 0;
    };
}

#endif //POOLIUM_ITHREADPOOL_HPP
