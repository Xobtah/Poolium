//
// Created by xobtah on 06/02/17.
//

#ifndef POOLIUM_THREADPOOL_HPP
#define POOLIUM_THREADPOOL_HPP

#include <exception>

#include "IThreadPool.hpp"
#include "Thread.hpp"
#include "../Basium/DataBase.hpp"

namespace Poolium
{
    class ThreadPoolException : public std::exception
    {
    public:
        ThreadPoolException(std::string what) throw() : _what(what) {}
        ~ThreadPoolException() {}

        virtual const char  *what() const throw() { return _what.c_str(); }

    private:
        std::string _what;
    };

    class   ThreadPool : public IThreadPool
    {
    public:
        ThreadPool();
        ~ThreadPool();

        unsigned int    Add(IThreadRunner&);
        unsigned int    Add(void (*)());
        Thread          &Get(unsigned int);
        IThreadPool     &Remove(unsigned int);

        unsigned int    GetSize() const;

    private:
        Basium::DataBase<Poolium::Thread*>  _db;
    };
}

#endif //POOLIUM_THREADPOOL_HPP
