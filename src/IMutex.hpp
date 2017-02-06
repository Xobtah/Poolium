//
// Created by xobtah on 06/02/17.
//

#ifndef POOLIUM_IMUTEX_HPP
#define POOLIUM_IMUTEX_HPP

namespace Poolium
{
    class   IMutex
    {
    public:
        virtual ~IMutex() {}

        virtual IMutex  &Lock() = 0;
        virtual bool    TryLock() = 0;
        virtual IMutex  &Unlock() = 0;
    };
}

#endif //POOLIUM_IMUTEX_HPP
