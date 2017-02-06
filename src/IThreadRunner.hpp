//
// Created by xobtah on 06/02/17.
//

#ifndef POOLIUM_ITHREADRUNNER_HPP
#define POOLIUM_ITHREADRUNNER_HPP

namespace Poolium
{
    class   IThreadRunner
    {
    public:
        ~IThreadRunner() {}

        virtual void    ThreadRunner() = 0;
    };
}

#endif //POOLIUM_ITHREADRUNNER_HPP
